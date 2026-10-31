#!/bin/bash

# Prepare Zed extension for publication
# This script ensures the Zed extension is ready for distribution

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"

# Use the repo-pinned tree-sitter CLI (a devDependency) when no global one is installed.
export PATH="$PROJECT_ROOT/node_modules/.bin:$PATH"
ZED_EXTENSION_DIR="$PROJECT_ROOT/editors/zed"

echo "🔧 Preparing Zed extension for publication..."

# Check if we're in the right directory
if [ ! -f "$PROJECT_ROOT/grammar.js" ]; then
    echo "❌ Error: Not in tree-sitter-gram root directory"
    exit 1
fi

# Ensure tree-sitter CLI is available
if ! command -v tree-sitter &> /dev/null; then
    echo "❌ Error: tree-sitter CLI not found. Install with: npm install -g tree-sitter-cli"
    exit 1
fi

# Configure repository mode (dev|pub) — used for sync and for extension.toml
ZED_REPO_MODE="${ZED_REPO_MODE:-dev}"

# Generate the latest parser
echo "📦 Regenerating parser..."
cd "$PROJECT_ROOT"
npx tree-sitter generate

# Run tests to ensure grammar is valid
echo "🧪 Running grammar tests..."
npx tree-sitter test

# Sync top-level queries into Zed extension
echo "📝 Syncing Tree-sitter queries into Zed extension..."
QUERIES_SRC="$PROJECT_ROOT/queries"
QUERIES_DST="$ZED_EXTENSION_DIR/languages/gram"

if [ ! -d "$QUERIES_SRC" ] || [ ! -f "$QUERIES_SRC/highlights.scm" ]; then
    echo "❌ Error: Missing canonical queries. Expected at: $QUERIES_SRC/highlights.scm"
    exit 1
fi

mkdir -p "$QUERIES_DST"
rm -f "$QUERIES_DST"/*.scm
cp "$QUERIES_SRC"/*.scm "$QUERIES_DST"/

# In dev mode, restore symlinks so the repo keeps a single source of truth (queries/)
if [ "$ZED_REPO_MODE" != "pub" ] && [ "$ZED_REPO_MODE" != "publish" ]; then
    echo "🔗 Restoring symlinks in languages/gram/ (dev mode)"
    rm -f "$QUERIES_DST"/*.scm
    for f in highlights indents locals injections; do
        ln -sf "../../../../queries/$f.scm" "$QUERIES_DST/$f.scm"
    done
fi



# Update version in extension.toml to match package.json
PACKAGE_VERSION=$(node -p "require('$PROJECT_ROOT/package.json').version")
echo "🔄 Updating extension version to $PACKAGE_VERSION..."

# extension.toml is committed, so it always points at the public repository, never a local path
# (the repository mode above only controls how queries are synced).
REPO_URL=$(node -p "require('$PROJECT_ROOT/package.json').repository.url")
REPO_URL=${REPO_URL#git+}
REPO_URL=${REPO_URL%.git}

# Zed fetches `rev` and then runs `git checkout <rev>`, which only works for a commit SHA:
# a tag name is fetched but never becomes a local ref ("pathspec 'v…' did not match").
# Use the current commit. It must be pushed for repository = https://… (pub mode).
REV=$(git -C "$PROJECT_ROOT" rev-parse HEAD)

echo "🔗 Repository: $REPO_URL"
echo "🔖 Rev: $REV"

# Update version, and the gram grammar's repository and rev. Only the [grammars.gram]
# section is touched: [grammars.gramdoc] pins a separate repository and commit.
EXT_TOML="$ZED_EXTENSION_DIR/extension.toml" PACKAGE_VERSION="$PACKAGE_VERSION" REPO_URL="$REPO_URL" REV="$REV" node -e '
const fs = require("fs");
const p = process.env.EXT_TOML;
let inGram = false;
let top = true;
const out = fs.readFileSync(p, "utf8").split("\n").map((line) => {
  const section = line.match(/^\[(.+)\]\s*$/);
  if (section) { top = false; inGram = section[1] === "grammars.gram"; }
  if (top && /^version = "/.test(line)) return `version = "${process.env.PACKAGE_VERSION}"`;
  if (inGram && /^repository = "/.test(line)) return `repository = "${process.env.REPO_URL}"`;
  if (inGram && /^rev = "/.test(line)) return `rev = "${process.env.REV}"`;
  return line;
});
fs.writeFileSync(p, out.join("\n"));
'

# Validate extension structure
echo "✅ Validating extension structure..."
required_files=(
    "$ZED_EXTENSION_DIR/extension.toml"
    "$ZED_EXTENSION_DIR/Cargo.toml"
    "$ZED_EXTENSION_DIR/src/lib.rs"
    "$ZED_EXTENSION_DIR/languages/gram/config.toml"
    "$ZED_EXTENSION_DIR/languages/gram/highlights.scm"
    "$ZED_EXTENSION_DIR/languages/gram/indents.scm"
    "$ZED_EXTENSION_DIR/languages/gram/locals.scm"
    "$ZED_EXTENSION_DIR/languages/gram/injections.scm"
    "$ZED_EXTENSION_DIR/languages/gramdoc/config.toml"
    "$ZED_EXTENSION_DIR/languages/gramdoc/highlights.scm"
)

for file in "${required_files[@]}"; do
    if [ ! -e "$file" ]; then
        echo "❌ Error: Missing required file: $file"
        exit 1
    fi
done

echo "✅ Extension validation passed!"

# Optional: ensure the Wasm extension crate compiles (Zed loads the cdylib target).
if command -v cargo &> /dev/null; then
    if rustup target list --installed 2>/dev/null | grep -q 'wasm32-wasip1'; then
        echo "🦀 Checking Zed extension Wasm build..."
        (cd "$ZED_EXTENSION_DIR" && cargo check --target wasm32-wasip1 --locked) || {
            echo "⚠️  Wasm check failed (install target: rustup target add wasm32-wasip1)"
        }
    else
        echo "ℹ️  Skipping Wasm check (wasm32-wasip1 not installed; rustup target add wasm32-wasip1)"
    fi
else
    echo "ℹ️  Skipping Wasm check (cargo not on PATH)"
fi

# Test the extension by creating a test file
echo "🧪 Testing syntax highlighting..."
TEST_FILE="$ZED_EXTENSION_DIR/test.gram"
cat > "$TEST_FILE" << 'EOF'
// Test Gram file for syntax highlighting
(:Person {
  name: "Test User",
  age: 30,
  active: true
})

(user:Person)-[:KNOWS]->(friend:Person {name: "Friend"})
EOF

echo "📁 Created test file: $TEST_FILE"

# Show extension info
echo ""
echo "🎉 Zed extension prepared successfully!"
echo ""
echo "Extension details:"
echo "  Location: $ZED_EXTENSION_DIR"
echo "  Version: $PACKAGE_VERSION"
echo "  Test file: $TEST_FILE"
echo ""
echo "Next steps:"
echo "  1. Test the extension manually:"
echo "     ln -s '$ZED_EXTENSION_DIR' ~/.config/zed/extensions/gram"
echo "     # Then restart Zed and open $TEST_FILE"
echo ""
echo "  2. For Zed extension registry submission:"
echo "     # Follow Zed's extension publishing guidelines"
echo "     # Repository: https://github.com/zed-industries/extensions"
echo ""
echo "  3. Clean up test file when done:"
echo "     rm '$TEST_FILE'"
