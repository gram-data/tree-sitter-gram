# Publishing to crates.io

This project publishes three crates to crates.io (in dependency order):
- `tree-sitter-gram` — The main grammar crate
- `gram-lsp` — Language server library and binary
- `gram` — Unified CLI tool

## Prerequisites

### 1. Create a crates.io account

1. Go to [crates.io](https://crates.io)
2. Sign in with your GitHub account
3. Complete your profile

### 2. Generate an API token

1. Go to [Account Settings > API Tokens](https://crates.io/me)
2. Click "New Token"
3. Give it a name (e.g., "GitHub Actions Publishing")
4. Copy the token (you'll only see it once!)

### 3. Add the token to GitHub Secrets

1. Go to your repository on GitHub
2. Navigate to **Settings > Secrets and variables > Actions**
3. Click "New repository secret"
4. Name: `CARGO_REGISTRY_TOKEN`
5. Value: Paste your crates.io API token
6. Click "Add secret"

## Publishing Process

Publishing is automated via GitHub Actions when you push a git tag:

1. **Update versions** using `tree-sitter version <X.Y.Z>`, which updates all version fields consistently.

2. **Commit and tag**:
   ```bash
   git commit -am "Release 0.3.7"
   git tag -a v0.3.7 -m "Release 0.3.7"
   git push --follow-tags
   ```

3. **GitHub Actions will automatically**:
   - Publish `tree-sitter-gram`
   - Update and publish `gram-lsp` (path deps swapped for version deps)
   - Update and publish `gram` (path deps swapped for version deps)

## Manual Publishing (if needed)

```bash
VERSION="0.3.7"

# 1. Publish tree-sitter-gram first
cargo publish --package tree-sitter-gram

# 2. Swap path dep → version dep in gram-lsp, publish, restore
sed -i "s|tree-sitter-gram = { path = \"../..\" }|tree-sitter-gram = \"$VERSION\"|" tools/lsp/Cargo.toml
cargo publish --package gram-lsp --allow-dirty
sed -i "s|tree-sitter-gram = \"$VERSION\"|tree-sitter-gram = { path = \"../..\" }|" tools/lsp/Cargo.toml

# 3. Swap path deps → version deps in gram, publish, restore
sed -i "s|tree-sitter-gram = { path = \"../..\" }|tree-sitter-gram = \"$VERSION\"|" tools/gram/Cargo.toml
sed -i "s|gram-lsp = { path = \"../lsp\" }|gram-lsp = \"$VERSION\"|" tools/gram/Cargo.toml
cargo publish --package gram --allow-dirty
sed -i "s|tree-sitter-gram = \"$VERSION\"|tree-sitter-gram = { path = \"../..\" }|" tools/gram/Cargo.toml
sed -i "s|gram-lsp = \"$VERSION\"|gram-lsp = { path = \"../lsp\" }|" tools/gram/Cargo.toml
```

## Important Notes

- **Publish order matters**: `tree-sitter-gram` → `gram-lsp` → `gram` (each depends on the previous)
- **Path dependencies**: The workflow automatically swaps path deps for version deps before publishing and restores them after
- **Dry run**: Use `cargo publish --dry-run` to verify before publishing
- **Yanking**: `cargo yank --vers <version> <package-name>`
