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

## gram-lint Tool

The `gram-lint` tool is a command-line linter for gram notation files, located in `tools/gram-lint/`.

### Build and Test

```bash
# Build the linter
cargo build --manifest-path tools/gram-lint/Cargo.toml

# Run the linter
cargo run --manifest-path tools/gram-lint/Cargo.toml -- [OPTIONS] [FILES]

# Run tests (if any)
cargo test --manifest-path tools/gram-lint/Cargo.toml
```

### Install Locally

Install to `~/.cargo/bin/` for system-wide use:

```bash
cargo install --path tools/gram-lint
```

### Usage Examples

```bash
# Check version
gram-lint --version

# Lint a file
gram-lint path/to/file.gram

# Lint multiple files
gram-lint file1.gram file2.gram

# Lint an expression directly
gram-lint -e "(person {name: 'Alice'})"

# Show parse tree
gram-lint -t file.gram

# Lint from stdin
cat file.gram | gram-lint
echo "(person {name: 'Bob'})" | gram-lint
```

### Development Notes

- The linter uses the same grammar version as the main tree-sitter-gram package (inherited via workspace)
- Error reporting includes line/column numbers and visual indicators
- Supports both ERROR nodes (unexpected tokens) and MISSING nodes (expected tokens)

# CI and release

## Workflows

- **CI** (`.github/workflows/ci.yml`) — Runs on every push to the default branch and on pull requests when grammar, bindings, or tests change. It runs the test suite and the full build (Wasm + Node prebuilds on all OSes). Use this to **validate that the build succeeds before you tag**; no publishing happens here.
- **Publish** (`.github/workflows/publish.yml`) — Runs only when you push a **tag**. It runs the same build, then publishes to npm, PyPI, and crates.io. All publish jobs depend on the build, so a failed build blocks publishing.
- **Release** (`.github/workflows/release.yml`) — Optional. Also runs on tag push; creates a GitHub Release with Wasm binaries, a source tarball, and attestations. Remove this file if you do not use GitHub Releases.

Build steps live in the reusable **Build** workflow (`.github/workflows/build.yml`), which is used by both CI and Publish.

## Releasing to npm, PyPI, and crates.io

1. Bump version everywhere (e.g. global search & replace for the new version):
   - `package.json` (`version`)
   - `tree-sitter.json` (`metadata.version`)
   - `Cargo.toml` (workspace and crates)
   - Any other version strings (e.g. `npm run zed:publish` if you use it)
2. Commit and push (or open a PR and merge).
3. Wait for **CI** to pass (test + build) on the branch you will tag.
4. Tag the release and push tags:
   ```bash
   git tag -a v1.2.3 -m "Release 1.2.3"
   git push --follow-tags
   ```
5. The **Publish** workflow runs on the tag: it builds again and publishes to npm, PyPI, and crates.io. Optionally, **Release** creates the GitHub Release.

## Local install (without publishing)

**Python:**

```bash
python -m pip install .
```

**Node:** from the repo root, `npm link` or install the package path in another project.
