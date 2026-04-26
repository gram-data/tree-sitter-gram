# Implementation Plan: Gram language server (`tools/lsp`)

**Branch**: `006-gram-lsp` | **Date**: 2026-04-26 | **Spec**: [spec.md](./spec.md)  
**Input**: Feature specification from `/specs/006-gram-lsp/spec.md`; planning directive: add a `tools/lsp` subproject in Rust using `tower-lsp`.

## Summary

Deliver a Gram language server and aligned CLI diagnostics under `tools/lsp/`, implemented in Rust with **tower-lsp** (async LSP over JSON-RPC), **tree-sitter** + the in-repo **`tree-sitter-gram`** crate for parsing, and incremental document state per LSP. Editors get diagnostics, hover, definition/references, and completions scoped per [spec.md](./spec.md); maintainers get a `gram-lsp` (or shared) binary subcommand for machine-readable checks matching editor syntax rules. No `grammar.js` changes unless a gap is found during implementation; query semantics from `queries/locals.scm` inform cross-file name resolution where feasible.

## Technical Context

**Language/Version**: Rust (workspace `edition = "2021"`, align MSRV with existing `tools/gram-lint`, typically Rust 1.74+ unless CI pins higher)  
**Primary Dependencies**: `tower-lsp`, `tokio`, `tree-sitter` 0.25, `tree-sitter-gram` (path `../..` from `tools/lsp`), `clap` for CLI; optional `ropey` or line-index helpers for UTF-16/LSP positions (see research)  
**Storage**: In-memory workspace index (open buffers + scanned `.gram` files under workspace root); no database  
**Testing**: `cargo test` in `tools/lsp`; integration tests with synthetic `.gram` fixtures; repo-wide `npx tree-sitter test` / `npm test` unchanged unless grammar touched  
**Target Platform**: macOS/Linux/Windows (stdio LSP); CLI for CI on same targets  
**Project Type**: Workspace member binary crate under `tools/lsp` (mirrors `tools/gram-lint`)  
**Performance Goals**: Meet spec SC-005 (5k-line file first diagnostics within 10s on reference laptop); typical files sub-second publish for diagnostics after edit  
**Constraints**: LSP positions use UTF-16 code units per protocol; UTF-8-only sources per spec assumptions; single canonical parse/error logic shared between LSP and CLI (FR-006 / SC-004)  
**Scale/Scope**: Workspace = client-provided roots; minimum all `.gram` under one root for cross-file navigation; defer multi-root complexity to later if needed

## Constitution Check

*GATE: Must pass before Phase 0 research. Re-check after Phase 1 design.*

**Grammar Expressiveness and Clarity (Principle I)**:

- [x] No change to `grammar.js` in the default plan; LSP consumes the existing parser. If implementation discovers a grammar ambiguity, follow the normal grammar workflow in a follow-up.
- [x] N/A for new rule names — not a grammar feature branch.

**Comprehensive and Illustrative Testing (Principle II)**:

- [x] Corpus tests in `test/corpus/` unchanged unless grammar changes.
- [x] Add focused Rust tests and `.gram` fixtures under `tools/lsp` for diagnostics, navigation, and CLI parity (mirrors “binding tests beside implementation”).
- [ ] All suites green before merge: `cargo test -p gram-lsp` (package name TBD), `npx tree-sitter test`, `npm test` as applicable.

**Minimal Binding Examples (Principle III)**:

- [x] No AST change required for MVP; `examples/` unchanged unless hover text references public examples.

*Post Phase 1 design*: Research locked `tower-lsp`, shared parse/diagnostic core, UTF-16 positioning strategy, and workspace indexing. Principles I–III satisfied without Complexity Tracking entries.

## Project Structure

### Documentation (this feature)

```text
specs/006-gram-lsp/
├── plan.md              # This file
├── research.md          # Phase 0
├── data-model.md        # Phase 1
├── quickstart.md        # Phase 1
├── contracts/           # Phase 1
└── tasks.md             # Phase 2 (/speckit.tasks — not created here)
```

### Source Code (repository root)

```text
Cargo.toml                 # Add tools/lsp to [workspace.members]

tools/lsp/
├── Cargo.toml             # package e.g. gram-lsp; bin for LSP + CLI
├── src/
│   ├── main.rs            # clap: `stdio` / `check` (or separate bins if cleaner)
│   ├── lib.rs             # shared analysis (parse, diagnostics, symbols)
│   ├── lsp.rs             # tower-lsp Backend impl, caps registration
│   ├── workspace.rs       # root folders, indexed .gram paths, file sync
│   └── utf16.rs           # (optional module) byte offset ↔ LSP Position
└── tests/
    └── fixtures/          # minimal .gram files for diagnostics + cross-file refs

grammar.js, src/           # Unchanged unless bugfix follow-up
queries/locals.scm         # Reference for definition/reference captures (no change required for MVP if queries already match spec)
tools/gram-lint/           # Existing; may share helper patterns or later extract shared crate
```

**Structure Decision**: New workspace member **`tools/lsp`** only; keep parser dependency via `tree-sitter-gram` path crate consistent with `tools/gram-lint`. LSP and CLI entrypoints live in the same package to guarantee one implementation of diagnostics (SC-004).

## Complexity Tracking

> **Fill ONLY if Constitution Check has violations that must be justified**

| Violation | Why Needed | Simpler Alternative Rejected Because |
|-----------|------------|-------------------------------------|
| (none) | — | — |
