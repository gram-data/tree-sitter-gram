#!/usr/bin/env bash
# Bump all package versions and prepare release artifacts.
#
# Usage:
#   ./scripts/prepare-release.sh --bump patch|minor|major
#   ./scripts/prepare-release.sh 0.4.0
#
# Covers:
#   tree-sitter version       →  package.json, Cargo.toml (workspace), pyproject.toml,
#                                tree-sitter.json, Makefile
#   npm --package-lock-only   →  package-lock.json (tree-sitter version does not touch it)
#   prepare-zed-extension.sh  →  editors/zed/extension.toml version and rev = "v<version>"
#   cargo check --workspace   →  validate all Rust crates compile at new version

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(dirname "$SCRIPT_DIR")"

# Use the repo-pinned tree-sitter CLI (a devDependency) when no global one is installed.
export PATH="$ROOT/node_modules/.bin:$PATH"

# ---------------------------------------------------------------------------
# Args
# ---------------------------------------------------------------------------
if [[ $# -eq 0 ]]; then
    echo "Usage: $0 --bump patch|minor|major"
    echo "       $0 <version>"
    exit 1
fi

# ---------------------------------------------------------------------------
# Prerequisites
# ---------------------------------------------------------------------------
for cmd in tree-sitter cargo node git; do
    if ! command -v "$cmd" &>/dev/null; then
        echo "error: '$cmd' not found on PATH"
        exit 1
    fi
done

if [[ ! -f "$ROOT/grammar.js" ]]; then
    echo "error: run from the tree-sitter-gram repository root"
    exit 1
fi

# ---------------------------------------------------------------------------
# 1. Bump tree-sitter-managed versions
#    Updates: package.json, package-lock.json, Cargo.toml ([workspace.package]),
#             pyproject.toml, tree-sitter.json
# ---------------------------------------------------------------------------
echo "→ Bumping versions..."
cd "$ROOT"
tree-sitter version "$@"

NEW_VERSION=$(node -p "require('./package.json').version")
echo "  version: $NEW_VERSION"

# tree-sitter version leaves package-lock.json at the old version.
npm install --package-lock-only --ignore-scripts --silent

# ---------------------------------------------------------------------------
# 2. Prepare Zed extension
#    Sets extension.toml version and rev = "v<version>" (the git tag that will
#    be created in the next step — no amend needed).
# ---------------------------------------------------------------------------
echo "→ Preparing Zed extension..."
"$SCRIPT_DIR/prepare-zed-extension.sh"

# ---------------------------------------------------------------------------
# 3. Validate the full workspace compiles
# ---------------------------------------------------------------------------
echo "→ Checking workspace..."
cargo check --workspace --quiet
echo "  ok"

# ---------------------------------------------------------------------------
# Summary
# ---------------------------------------------------------------------------
echo ""
echo "Version $NEW_VERSION ready. Changed files:"
git diff --name-only | sed 's/^/  /'
echo ""
echo "Next steps:"
echo ""
echo "  git commit -am \"Release $NEW_VERSION\""
echo "  git tag -a v$NEW_VERSION -m \"Release $NEW_VERSION\""
echo "  git push --follow-tags"
