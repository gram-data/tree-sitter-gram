#!/bin/bash

# Local CI script: build and test locally before submitting a PR
# This script mirrors the GitHub CI workflow steps to validate changes locally

set -e

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Configuration
TREE_SITTER_ABI_VERSION=15
SKIP_RUST=false
VERBOSE=false

# Parse command line arguments
usage() {
  echo "Usage: $0 [OPTIONS]"
  echo ""
  echo "Options:"
  echo "  --skip-rust    Skip Rust build and tests"
  echo "  --verbose      Show detailed output"
  echo "  --help         Show this message"
  exit 1
}

while [[ $# -gt 0 ]]; do
  case $1 in
    --skip-rust)
      SKIP_RUST=true
      shift
      ;;
    --verbose)
      VERBOSE=true
      shift
      ;;
    --help)
      usage
      ;;
    *)
      echo "Unknown option: $1"
      usage
      ;;
  esac
done

log_step() {
  echo -e "${GREEN}→${NC} $1"
}

log_error() {
  echo -e "${RED}✗${NC} $1"
}

log_success() {
  echo -e "${GREEN}✓${NC} $1"
}

log_warn() {
  echo -e "${YELLOW}⚠${NC}  $1"
}

# Main CI steps
main() {
  log_step "Starting local CI..."
  echo ""

  # Step 1: Install dependencies
  # Use --ignore-scripts to skip native builds (tree-sitter v0.25.0 fails to
  # compile with Node 24 using its default C++17 flag; we rebuild it below with C++20).
  log_step "Installing dependencies..."
  if [[ "$VERBOSE" == true ]]; then
    npm ci --omit=peer --omit=optional --ignore-scripts
  else
    npm ci --omit=peer --omit=optional --ignore-scripts 2>&1 | grep -E "^(added|packages|found|up to date)" || true
  fi
  # Download the tree-sitter-cli prebuilt binary (skipped by --ignore-scripts).
  (cd node_modules/tree-sitter-cli && node install.js)
  # Rebuild tree-sitter native bindings with C++20 (required for Node 24+ V8 headers).
  if ! CXXFLAGS="-std=c++20" npm rebuild tree-sitter 2>&1; then
    log_error "Failed to build tree-sitter native bindings"
    return 1
  fi
  log_success "Dependencies installed"
  echo ""

  # Step 2: Regenerate parser
  log_step "Regenerating parser..."
  TREE_SITTER_ABI_VERSION=$TREE_SITTER_ABI_VERSION npx tree-sitter generate
  log_success "Parser generated"
  echo ""

  # Step 3: Build Wasm
  log_step "Building WebAssembly binaries..."
  npx tree-sitter build --wasm .
  log_success "WebAssembly built"
  echo ""

  # Step 4: Run corpus tests
  log_step "Running tree-sitter corpus tests..."
  if npx tree-sitter test; then
    log_success "Corpus tests passed"
  else
    log_error "Corpus tests failed"
    return 1
  fi
  echo ""

  # Step 5: Run Node binding tests
  log_step "Running Node binding tests..."
  if npm test; then
    log_success "Node binding tests passed"
  else
    log_error "Node binding tests failed"
    return 1
  fi
  echo ""

  # Step 6: Rust (optional)
  if [[ "$SKIP_RUST" == false ]]; then
    if command -v cargo &> /dev/null; then
      log_step "Building Rust release..."
      cargo build --release
      log_success "Rust release built"
      echo ""

      log_step "Running Rust tests..."
      if cargo test; then
        log_success "Rust tests passed"
      else
        log_error "Rust tests failed"
        return 1
      fi
      echo ""
    else
      log_warn "Cargo not found, skipping Rust build and tests"
      echo ""
    fi
  else
    log_warn "Skipping Rust build and tests (--skip-rust)"
    echo ""
  fi

  log_success "All tests passed! ✓"
  echo ""
  echo -e "${GREEN}Ready to submit PR${NC}"
}

# Run main function and handle errors
if main; then
  exit 0
else
  log_error "CI failed"
  exit 1
fi
