# Research: Gram LSP (`tools/lsp`)

**Feature**: 006-gram-lsp  
**Date**: 2026-04-26

Consolidated decisions for Rust + tower-lsp implementation. All prior “NEEDS CLARIFICATION” items from planning are resolved here.

---

## 1. LSP framework: tower-lsp

**Decision**: Use **tower-lsp** (with `tokio` runtime) as the LSP server framework.

**Rationale**: Explicit user/planning directive; mature async model; integrates with Tower services for testing and layering; widely used in Rust LSP ecosystem.

**Alternatives considered**:

- **lsp-server**: Simpler synchronous style; rejected because the project standard is tower-lsp per directive.
- **Custom JSON-RPC**: Maximum control but high protocol surface area; rejected as unnecessary risk.

---

## 2. Parser integration

**Decision**: Use **`tree-sitter`** 0.25 and the workspace crate **`tree-sitter-gram`** (`path = "../.."`) identical to `tools/gram-lint` for language loading and incremental `Parser`.

**Rationale**: Single grammar source of truth; matches existing Rust tooling; enables incremental `didChange` without subprocess.

**Alternatives considered**:

- **FFI to Node/tree-sitter CLI**: Would complicate install and break incremental story; rejected.

---

## 3. UTF-8 source vs LSP UTF-16 positions

**Decision**: Treat on-disk and buffer content as **UTF-8** (per spec). Implement **explicit conversion** from byte offsets / tree-sitter `Point` to LSP `Position` (UTF-16 code unit indices) for `Range`, `Diagnostic`, `Location`, etc. Prefer a small tested helper module (or `ropey` if edit performance requires a rope later).

**Rationale**: LSP mandates UTF-16 column/offset semantics; tree-sitter uses byte offsets and UTF-8 line/column in `Point` for column as UTF-8 code points in some versions — team must map consistently; documenting + unit testing avoids subtle editor misalignment.

**Alternatives considered**:

- **Assume UTF-8-only ASCII subset for columns**: Fails on non-ASCII Gram identifiers/strings; rejected.

---

## 4. Diagnostics from parse tree

**Decision**: Walk the tree for **`ERROR` and missing nodes** (same family as `gram-lint`) for syntax diagnostics; map spans through UTF-16 conversion. Optionally unify message strings with `gram-lint` for human parity; CLI JSON uses stable codes + ranges.

**Rationale**: Meets FR-001/SC-001 without a second parser; proven pattern in-repo.

**Alternatives considered**:

- **Custom lexer errors only**: Too weak for user-visible “syntax” story; rejected.

---

## 5. Hover, definition, references, completions

**Decision**:

- **Hover**: Start from **smallest named node** at cursor; return structured plain text describing node kind and key child labels (iterate toward richer doc strings later).
- **Go to def / references**: Build a **workspace symbol index** from parsed trees: collect definition sites and reference sites using the **same semantic rules as `queries/locals.scm`** (either by loading the query with `tree_sitter::Query` + captures, or by AST walk that mirrors those captures). File scope first; cross-file = union of all indexed `.gram` under workspace roots.
- **Completions**: Contextual keyword/snippet set from parent node kind + in-scope names from the index when inside identifier positions.

**Rationale**: Aligns editor behavior with existing Tree-sitter locals contract ([../004-editor-improvements/contracts/locals.md](../004-editor-improvements/contracts/locals.md)); avoids inventing a second scoping model.

**Alternatives considered**:

- **TS query only in editors, not in LSP**: Would diverge from Zed/Neovim behavior; rejected for consistency (FR-004/FR-005).

---

## 6. CLI shape for CI (FR-006)

**Decision**: Same binary (e.g. `gram-lsp check <paths…>`) emits **one JSON object per run** (or JSONL per file — choose one in implementation; plan recommends **single JSON document** with `files: [{ path, diagnostics: [...] }]`) with stable schema documented in `contracts/cli-diagnostics.md`. Exit code non-zero if any error-severity diagnostic.

**Rationale**: Machine-friendly; easy diff in tests; matches SC-004 “same count” when both paths call shared core.

**Alternatives considered**:

- **Only reuse gram-lint output**: Would duplicate logic or couple binaries; shared library module preferred.

---

## 7. Workspace model

**Decision**: Honor LSP **`workspaceFolders`** (or single `rootUri`). Index `**/*.gram` under each folder on `initialize` / `didChangeWatchedFiles` where supported; fall back to open documents only on minimal clients.

**Rationale**: Meets minimum cross-file story in spec; incremental file discovery reduces stale references.

**Alternatives considered**:

- **Open files only**: Fails two-file cross-file acceptance scenario; rejected for default behavior.
