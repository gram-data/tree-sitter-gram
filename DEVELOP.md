# Development

## Install `tree-sitter` CLI

Follow [tree-sitter installation](https://tree-sitter.github.io/tree-sitter/creating-parsers#installation) instructions

## Build testable grammar (when grammar has changed)

```
npx tree-sitter generate
```

## Build all the things

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

# Publish

## Local Python

```
python -m pip install .
```

## Release to npm, pypi

1. Bump all build files to matching version (global search & replace)
  - `tree-sitter version 1.2.3`
  - `npm run zed:publish`
2. Commit changes
  - `git commit -am "Release 1.2.3" `
3. Tag with new version using
  - `git tag -a <version> -m "<description>"`
4. Push the tags to trigger deployment
  - `git push --follow-tags`
