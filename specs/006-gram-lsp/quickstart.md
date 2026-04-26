# Quickstart: Gram LSP (`tools/lsp`)

**Feature**: 006-gram-lsp  
**Date**: 2026-04-26

## Prerequisites

- Rust toolchain matching workspace MSRV (see root `Cargo.toml` / CI).
- This repository cloned with `grammar.js` and generated `src/` parser present (normal tree-sitter-gram dev setup).

## Build

From the repository root:

```bash
cargo build -p gram-lsp
```

*(Replace `gram-lsp` with the actual Cargo package name once `tools/lsp/Cargo.toml` is added.)*

## Run (stdio LSP)

Typical pattern for editors:

```bash
cargo run -p gram-lsp -- stdio
```

Wire the client to launch this command; set `language_id` / file association to `gram` and `*.gram` per [contracts/lsp-capabilities.md](./contracts/lsp-capabilities.md).

## Run (CLI check)

```bash
cargo run -p gram-lsp -- check --json path/to/models path/to/other.gram
```

Validate exit code and JSON against [contracts/cli-diagnostics.md](./contracts/cli-diagnostics.md).

## Tests

```bash
cargo test -p gram-lsp
```

## Editor snippet (VS Code–style)

```json
"gram.languageServer": {
  "command": "cargo",
  "args": ["run", "-p", "gram-lsp", "--", "stdio"],
  "options": { "cwd": "/absolute/path/to/tree-sitter-gram" }
}
```

Adjust `cwd` and binary name for installed artifacts in production.
