#!/bin/bash

# Prepare Zed extension for publication
# This script ensures the Zed extension is ready for distribution

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"
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
QUERIES_DST="$ZED_EXTENSION_DIR/languages/gram/queries"

if [ ! -d "$QUERIES_SRC" ] || [ ! -f "$QUERIES_SRC/highlights.scm" ]; then
    echo "❌ Error: Missing canonical queries. Expected at: $QUERIES_SRC/highlights.scm"
    exit 1
fi

rm -rf "$QUERIES_DST"
mkdir -p "$QUERIES_DST"
cp "$QUERIES_SRC"/*.scm "$QUERIES_DST"/



# Update version in extension.toml to match package.json
PACKAGE_VERSION=$(node -p "require('$PROJECT_ROOT/package.json').version")
echo "🔄 Updating extension version to $PACKAGE_VERSION..."

# Configure repository mode (dev|pub)
ZED_REPO_MODE="${ZED_REPO_MODE:-dev}"
COMMIT_SHA=$(git -C "$PROJECT_ROOT" rev-parse HEAD)

if [ "$ZED_REPO_MODE" = "pub" ] || [ "$ZED_REPO_MODE" = "publish" ]; then
    # Use the public repository URL from package.json, normalized to https
    REPO_URL=$(node -p "require('$PROJECT_ROOT/package.json').repository.url")
    REPO_URL=${REPO_URL#git+}
    REPO_URL=${REPO_URL%.git}
else
    # Use local repository for development
    REPO_URL="file://$PROJECT_ROOT"
fi

echo "🔗 Repository: $REPO_URL"
echo "🔖 Rev: $COMMIT_SHA"

# Use sed in a cross-platform way
if [[ "$OSTYPE" == "darwin"* ]]; then
    # macOS
    sed -i '' "s/^version = \".*\"/version = \"$PACKAGE_VERSION\"/" "$ZED_EXTENSION_DIR/extension.toml"
    sed -i '' "s#^repository = \".*\"#repository = \"$REPO_URL\"#" "$ZED_EXTENSION_DIR/extension.toml"
    sed -i '' "s/^rev = \".*\"/rev = \"$COMMIT_SHA\"/" "$ZED_EXTENSION_DIR/extension.toml"
else
    # Linux and others
    sed -i "s/^version = \".*\"/version = \"$PACKAGE_VERSION\"/" "$ZED_EXTENSION_DIR/extension.toml"
    sed -i "s#^repository = \".*\"#repository = \"$REPO_URL\"#" "$ZED_EXTENSION_DIR/extension.toml"
    sed -i "s/^rev = \".*\"/rev = \"$COMMIT_SHA\"/" "$ZED_EXTENSION_DIR/extension.toml"
fi

# Validate extension structure
echo "✅ Validating extension structure..."
required_files=(
    "$ZED_EXTENSION_DIR/extension.toml"
    "$ZED_EXTENSION_DIR/languages/gram/config.toml"
    "$ZED_EXTENSION_DIR/languages/gram/queries/highlights.scm"
)

for file in "${required_files[@]}"; do
    if [ ! -f "$file" ]; then
        echo "❌ Error: Missing required file: $file"
        exit 1
    fi
done

# Explicit check for highlights.scm copied from queries/
HIGHLIGHTS_FILE="$ZED_EXTENSION_DIR/languages/gram/queries/highlights.scm"
if [ ! -f "$HIGHLIGHTS_FILE" ]; then
    echo "❌ Error: Missing required file: $HIGHLIGHTS_FILE"
    exit 1
fi

echo "✅ Extension validation passed!"

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
