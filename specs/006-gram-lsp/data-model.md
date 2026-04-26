# Data Model: Gram LSP (`tools/lsp`)

**Feature**: 006-gram-lsp  
**Date**: 2026-04-26

In-memory and protocol-facing entities. No persistent database.

---

## 1. Workspace

| Field | Description |
|-------|-------------|
| `roots` | List of absolute folder URIs from LSP `workspaceFolders` (or single root) |
| `documents` | Map `Uri` → `DocumentState` for open buffers |
| `disk_index` | Optional map of path → last known revision / parse snapshot for files not open |
| `symbol_index` | Derived structure: definitions and references keyed by symbol name (see §4) |

**Validation**: Workspace scope for navigation = union of `roots` per FR-004 and spec assumptions.

**Transitions**: `initialize` / `initialized` populate roots; `didOpen`/`didChange`/`didClose` update `documents`; `didChangeWatchedFiles` or periodic refresh updates `disk_index`; index rebuild triggered after parse changes.

---

## 2. Document state

| Field | Description |
|-------|-------------|
| `uri` | LSP document URI |
| `version` | LSP version counter |
| `text` | Current UTF-8 source (String or rope) |
| `parser` | Optional dedicated `tree_sitter::Parser` instance for this document |
| `tree` | Latest `Tree` from parse |
| `language_id` | Must be `gram` (or client-specific; server only handles gram) |

**Validation**: FR-002 — updates apply on `didChange` without full process restart.

---

## 3. Diagnostic

| Field | Description |
|-------|-------------|
| `range` | LSP `Range` (UTF-16) |
| `severity` | Error for `ERROR`/missing; optional Warning for future lints |
| `message` | Human-readable plain text |
| `source` | Constant e.g. `gram-lsp` |
| `code` | Optional stable string/integer for CLI/tests |

**Derivation**: Parse walk for `ERROR` and missing nodes; ranges from node byte range → UTF-16 conversion.

---

## 4. Symbol and reference

| Field | Description |
|-------|-------------|
| `name` | Identifier text (normalized per language rules: exact string match for MVP) |
| `kind` | Simplified kind: `Subject`, `NodePattern`, `Relationship`, `Annotation`, `Reference`, etc. (implementation-defined enum aligned with AST) |
| `definition_sites` | List of `(uri, range)` where name is introduced |
| `reference_sites` | List of `(uri, range)` where name is used |

**Rules**: Definition/reference boundaries follow `queries/locals.scm` captures (see [contracts/navigation-semantics.md](./contracts/navigation-semantics.md)).

**Ambiguity**: If multiple definitions share a name in scope, document policy: return all matches on “find references”; “go to definition” returns `LocationLink[]` or first + log — locked in implementation and release notes (FR-008).

---

## 5. CLI report envelope

| Field | Description |
|-------|-------------|
| `schema_version` | Integer for JSON output evolution |
| `files` | Array of per-file results |
| `files[].path` | UTF-8 path string |
| `files[].diagnostics` | Array of objects compatible with LSP diagnostic shape (range + message + severity + code) |

**Validation**: SC-004 — same diagnostic count as LSP publish for identical inputs when using shared core.
