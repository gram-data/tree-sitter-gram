# Publishing to crates.io

This project publishes two crates to crates.io:
- `tree-sitter-gram` - The main grammar crate
- `gram-lint` - The linter CLI tool

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

1. **Update versions** in both `Cargo.toml` files:
   - `Cargo.toml` (tree-sitter-gram)
   - `tools/gram-lint/Cargo.toml` (gram-lint)

2. **Commit and tag**:
   ```bash
   git commit -am "Release 0.2.1"
   git tag -a v0.2.1 -m "Release 0.2.1"
   git push --follow-tags
   ```

3. **GitHub Actions will automatically**:
   - Publish `tree-sitter-gram` to crates.io
   - Update `gram-lint`'s dependency to the published version
   - Publish `gram-lint` to crates.io

## Manual Publishing (if needed)

If you need to publish manually:

```bash
# Publish tree-sitter-gram first
cargo publish --package tree-sitter-gram

# Then update gram-lint's dependency (remove path)
# Edit tools/gram-lint/Cargo.toml:
# Change: tree-sitter-gram = { version = "0.2.1", path = "../.." }
# To:     tree-sitter-gram = "0.2.1"

# Then publish gram-lint
cargo publish --package gram-lint
```

## Important Notes

- **Version synchronization**: The `gram-lint` crate's dependency on `tree-sitter-gram` must match the published version
- **Path dependencies**: The workflow automatically removes path dependencies before publishing
- **First-time publishing**: You may need to run `cargo publish --dry-run` first to verify everything is correct
- **Yanking**: If you need to remove a version, use `cargo yank --vers <version> <package-name>`

