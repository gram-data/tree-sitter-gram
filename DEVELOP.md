# Development

## Install `tree-sitter` CLI

Follow [tree-sitter installation](https://tree-sitter.github.io/tree-sitter/creating-parsers#installation) instructions

## Build testable grammar (when grammar has changed)

```
npx tree-sitter generate
```

## Build all the things

- **Wasm:** `npx tree-sitter build --wasm .`
- **Node prebuilds:** `npx prebuildify -t 20.19.5` (see `package.json` scripts)

## Test

```
npx tree-sitter test
```

Run tests matching a specific filter:
```
npx tree-sitter test -f 'Node'
```

## gram CLI

The `gram` tool is the unified CLI for gram notation files, located in `tools/gram/`.

### Build and Test

```bash
cargo build -p gram
cargo test -p gram
```

### Install Locally

```bash
cargo install --path tools/gram
```

### Usage Examples

```bash
# Check a file
gram check path/to/file.gram

# Check multiple files or a directory
gram check file1.gram file2.gram
gram check data/

# Check an inline expression
gram check -e "(alice:Person)-[:KNOWS]->(bob:Person)"

# Read from stdin
cat file.gram | gram check

# Machine-readable JSON output
gram check --json file.gram

# Show parse tree
gram check --tree file.gram

# Manage extensions
gram extension list
gram extension install lsp
gram extension remove lsp
```

# CI and release

## Workflows

- **CI** (`.github/workflows/ci.yml`) — Runs on every push to the default branch and on pull requests when grammar, bindings, or tests change. It runs the test suite and the full build (Wasm + Node prebuilds on all OSes). Use this to **validate that the build succeeds before you tag**; no publishing happens here.
- **Publish** (`.github/workflows/publish.yml`) — Runs only when you push a **tag**. It runs the same build, then publishes to npm, PyPI, and crates.io (`tree-sitter-gram`, `gram-lsp`, and `gram`). All publish jobs depend on the build, so a failed build blocks publishing.
- **Release** (`.github/workflows/release.yml`) — Optional. Also runs on tag push; creates a GitHub Release with Wasm binaries, a source tarball, and attestations. Remove this file if you do not use GitHub Releases.

Build steps live in the reusable **Build** workflow (`.github/workflows/build.yml`), which is used by both CI and Publish.

## Releasing to npm, PyPI, and crates.io

Merging to the default branch **does not** publish anything. When you **push a `v*` version tag** to GitHub, **Publish** (`.github/workflows/publish.yml`) runs on that tag: npm (`@gram-data/tree-sitter-gram`), PyPI (`tree-sitter-gram`), and crates.io (`tree-sitter-gram`, `gram-lsp`, `gram`). The same tag also runs **Release** if you keep that workflow. You need the usual repo secrets (`NPM_TOKEN`, `PYPI_API_TOKEN`, `CARGO_REGISTRY_TOKEN`).

1. Bump version everywhere using `tree-sitter version 1.2.3`
   - `package.json` (`version`)
   - `tree-sitter.json` (`metadata.version`)
   - `Cargo.toml` (workspace and crates)
   - Bump zed editor: `npm run zed:publish`
2. Commit and push (or open a PR and merge) to check that build succeeds
3. Wait for **CI** to pass (test + build) on the branch you will tag.
4. Tag the release and push tags:
   ```bash
   git tag -a v1.2.3 -m "Release 1.2.3"
   git push --follow-tags
   ```
5. The **Publish** workflow runs on the tag: it builds again and publishes to npm, PyPI, and crates.io (Rust crates `tree-sitter-gram`, `gram-lsp`, `gram` in that order). Optionally, **Release** creates the GitHub Release.

## Local install (without publishing)

**Python:**

```bash
python -m pip install .
```

**Node:** from the repo root, `npm link` or install the package path in another project.
