# Tasks: Gram language server (`tools/lsp`)

**Input**: `/specs/006-gram-lsp/` (plan.md, spec.md, research.md, data-model.md, contracts/)  
**Prerequisites**: plan.md ✓

## Dependencies (story order)

P1 (diagnostics) → P2 (hover) / P5 (CLI) → P3 (navigation) → P4 (completions) → Polish.

## Phase 1: Setup

- [x] T001 Add Rust dependencies in `tools/lsp/Cargo.toml` (`tower-lsp`, `tokio`, `tree-sitter`, `tree-sitter-gram`, `serde`, `serde_json`)
- [x] T002 Create `tools/lsp/src/lib.rs` with shared analysis API used by LSP and CLI
- [x] T003 [P] Add `tools/lsp/src/utf16.rs` for UTF-8 byte offsets → LSP UTF-16 `Position`/`Range`

## Phase 2: Foundational

- [x] T004 Implement `tools/lsp/src/parse.rs` — load `tree_sitter_gram` language, parse UTF-8 source to `Tree`
- [x] T005 Implement syntax diagnostics (ERROR / missing nodes) in `tools/lsp/src/diagnostics.rs` reusing logic aligned with `tools/gram-lint`
- [x] T006 Implement named duplicate detection for `subject_pattern_elements` direct children in `tools/lsp/src/elements.rs` per `specs/006-gram-lsp/contracts/navigation-semantics.md`

## Phase 3: User Story 1 — Syntax diagnostics (P1)

- [x] T007 [US1] Wire `textDocument/didOpen` / `didChange` / `didClose` + `publishDiagnostics` in `tools/lsp/src/lsp.rs`
- [x] T008 [US1] `cargo test` tests in `tools/lsp/src/lib.rs` (`analyze_tests`) for parse errors / duplicates / anonymous

## Phase 4: User Story 5 — CLI check JSON (P5)

- [x] T009 [US5] Implement `gram-lsp check --json` in `tools/lsp/src/main.rs` using shared analysis; schema per `specs/006-gram-lsp/contracts/cli-diagnostics.md`
- [x] T010 [US5] Tests share `analyze_source` for CLI parity (same diagnostics as LSP publish path)

## Phase 5: User Story 2 — Hover (P2)

- [x] T011 [US2] Implement `textDocument/hover` with node kind + reference vs definition hint in `tools/lsp/src/lsp.rs`

## Phase 6: User Story 3 — Navigation (P3)

- [x] T012 [US3] ~~Load `queries/locals.scm`~~ **AST walk** in `tools/lsp/src/symbols.rs` (parser AST shape differs from current `locals.scm` `subject:` patterns; follow-up: align `queries/locals.scm` + walker)
- [x] T013 [US3] Implement `textDocument/definition` and `references` (workspace = indexed + open docs) in `tools/lsp/src/lsp.rs`

## Phase 7: User Story 4 — Completions (P4)

- [x] T014 [US4] Minimal `textDocument/completion` (definition names) in `tools/lsp/src/lsp.rs`

## Phase 8: Polish

- [x] T015 [P] Unit fixtures embedded in `tools/lsp/src/lib.rs` tests
- [x] T016 `cargo test -p gram-lsp` and `cargo clippy -p gram-lsp -- -D warnings` (fix clippy as needed)

## Implementation strategy

MVP delivered: stdio LSP + `check --json`, shared `analyze_source`, UTF-16 ranges, duplicate element detection, symbol walk for defs/refs/hover/navigation/completions.

**Follow-up**: Reconcile `queries/locals.scm` with parser field structure (`identifier` on `node_pattern`) so Zed/Neovim and `gram-lsp` share one query-backed model.
