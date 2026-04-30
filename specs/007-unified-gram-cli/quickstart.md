# Quickstart: Unified `gram` CLI

**Feature**: 007-unified-gram-cli  
**Date**: 2026-04-30

---

## Prerequisites

- Rust 2021 edition (workspace edition)
- Cargo (build toolchain)
- `tree-sitter-gram` workspace checked out

---

## Build the `gram` binary

```bash
# From repo root
cargo build -p gram

# Run directly
./target/debug/gram --version
```

---

## gram check — validate gram files

```bash
# Check a single file
gram check data/example.gram

# Check all gram files in a directory
gram check data/

# Inline expression
gram check -e "(alice)-[:KNOWS]->(bob)"

# Read from stdin
echo "(a)-->(b)" | gram check

# Machine-readable JSON output
gram check --json data/*.gram

# Show parse tree
gram check --tree data/example.gram
```

---

## gram extension — manage extensions

```bash
# List available extensions (fetches registry)
gram extension list

# Install the LSP extension
gram extension install lsp

# Install a pinned version
gram extension install lsp@0.3.6

# List only installed extensions
gram extension list --installed

# Remove an extension
gram extension remove lsp
```

---

## Using an installed extension

After `gram extension install lsp`, the `gram-lsp` binary is placed in `~/.gram/bin/`.
Make sure `~/.gram/bin/` is on your `$PATH`, then:

```bash
# Use gram to dispatch to gram-lsp
gram lsp stdio

# Or invoke gram-lsp directly
gram-lsp stdio
```

---

## Third-party extensions (PATH dispatch)

If you have a binary named `gram-fmt` on your `$PATH`:

```bash
gram fmt data/example.gram
# equivalent to: gram-fmt data/example.gram
```

---

## Running tests

```bash
# Unit + integration tests for the gram crate
cargo test -p gram

# Full workspace test
cargo test
```

---

## CI/CD usage

```yaml
- name: Install gram
  run: curl -fsSL https://github.com/gram-data/tree-sitter-gram/releases/latest/download/gram-installer.sh | sh

- name: Lint gram files
  run: gram check **/*.gram

- name: Install lsp extension (pinned)
  run: gram extension install lsp@0.3.6
```
