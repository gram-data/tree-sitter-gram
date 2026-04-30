# Implementation Plan: Unified `gram` CLI with Extensions

**Branch**: `007-unified-gram-cli` | **Date**: 2026-04-30 | **Spec**: [spec.md](./spec.md)  
**Input**: Feature specification from `specs/007-unified-gram-cli/spec.md`

## Summary

Create a unified `gram` CLI binary that consolidates `gram-lint` and `gram-lsp check` into a single `gram check` command while introducing a structured extension system (`gram extension install/list/remove`) and sub-command dispatch (exec `gram-<name>` for unknown commands). The tool ships as a new Rust crate (`tools/gram/`) within the existing workspace, reusing the `gram-lsp` shared library for semantic analysis and adding new dependencies for HTTP downloads and path management.

## Technical Context

**Language/Version**: Rust, edition 2021, workspace version 0.3.6  
**Primary Dependencies**: clap 4.5 (derive), tree-sitter 0.25, tree-sitter-gram (workspace local), serde + serde_json 1.x, reqwest 0.12 (extension downloads), directories 5.x (platform-aware `~/.gram/bin`), walkdir 2.x (directory traversal), toml 0.8 (extension registry parsing)  
**Storage**: `~/.gram/bin/` for installed extension binaries; extension registry is a static TOML file fetched from GitHub  
**Testing**: `cargo test` (unit + integration), no new corpus tests (no grammar changes)  
**Target Platform**: Linux (x86_64 + aarch64), macOS (x86_64 + aarch64), Windows (x86_64) — same matrix as existing tools  
**Project Type**: New crate `tools/gram/` added to the existing single Cargo workspace  
**Performance Goals**: `gram check` on a 1 000-file directory finishes in under 10 seconds; extension install completes in under 2 minutes on a typical connection  
**Constraints**: End-users must not need a Rust toolchain; installer + pre-built binaries published via GitHub Releases using cargo-dist

## Constitution Check

*GATE: Must pass before Phase 0 research. Re-check after Phase 1 design.*

**Grammar Expressiveness and Clarity (Principle I)**:
- [N/A] No grammar changes — this feature adds a new CLI binary only

**Comprehensive and Illustrative Testing (Principle II)**:
- [ ] Integration tests cover `gram check` with valid files, invalid files, stdin, `-e`, directories, `--json`, `--tree`
- [ ] Integration tests cover `gram extension list`, `install`, `remove`
- [ ] Integration tests cover sub-command dispatch (PATH lookup + missing-command error)
- [ ] Unit tests cover extension registry parsing, JSON output serialization, diagnostic formatting
- [ ] All tests pass (`cargo test -p gram`)

**Minimal Binding Examples (Principle III)**:
- [N/A] No AST structure changes; no binding example updates required

**Constitution Check Result**: No violations. No grammar changes; testing requirements map directly to feature scenarios.

## Project Structure

### Documentation (this feature)

```text
specs/007-unified-gram-cli/
├── plan.md              # This file
├── research.md          # Phase 0 output
├── data-model.md        # Phase 1 output
├── quickstart.md        # Phase 1 output
├── contracts/           # Phase 1 output
│   ├── README.md
│   ├── cli-commands.md
│   ├── json-diagnostics.md
│   └── extension-registry.md
└── tasks.md             # Phase 2 output (/speckit-tasks — NOT created here)
```

### Source Code (repository root)

```text
tools/gram/                    # New crate: unified `gram` binary
├── Cargo.toml
├── src/
│   ├── main.rs                # Entry point; clap dispatcher
│   ├── check.rs               # `gram check` — merged lint + LSP-check logic
│   ├── extension/
│   │   ├── mod.rs             # `gram extension` subcommand dispatcher
│   │   ├── install.rs         # Download + install extension binary
│   │   ├── list.rs            # List installed + registry extensions
│   │   ├── remove.rs          # Remove installed extension
│   │   └── registry.rs        # Fetch + parse extension registry manifest
│   └── dispatch.rs            # PATH search → exec gram-<name>
└── tests/
    ├── cli_check.rs           # Integration tests: gram check
    ├── cli_extension.rs       # Integration tests: gram extension
    └── cli_dispatch.rs        # Integration tests: sub-command dispatch

tools/gram-lint/               # Kept for backward compatibility; deprecated
tools/lsp/                     # gram-lsp; reused as library via workspace dep

Cargo.toml                     # Add "tools/gram" to workspace members
```

**Structure Decision**: New `tools/gram/` crate mirrors the pattern of `tools/gram-lint/` and `tools/lsp/`. The `gram-lsp` library (`tools/lsp/src/lib.rs`) is reused as a workspace dependency so `gram check` inherits all semantic diagnostics without code duplication.

## Complexity Tracking

No constitution violations requiring justification.
