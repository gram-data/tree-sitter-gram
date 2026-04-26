# Contract: CLI diagnostic JSON

**Feature**: 006-gram-lsp  
**Date**: 2026-04-26

## Command

Documented entry point (exact argv finalized in implementation), e.g.:

`gram-lsp check [OPTIONS] <PATH>…`

- `PATH` may be files or directories; directories imply recursive `*.gram` (UTF-8 only).
- Exit code **0** if no diagnostics with severity `Error`.
- Exit code **non-zero** if one or more `Error` diagnostics (FR-006, Story 5).

## JSON shape (`schema_version` = 1)

Top-level object:

| Field | Type | Required |
|-------|------|----------|
| `schema_version` | number | yes, must be `1` for this contract |
| `files` | array | yes |

Each element of `files`:

| Field | Type | Required |
|-------|------|----------|
| `path` | string | yes, absolute or normalized relative path |
| `diagnostics` | array | yes (empty if clean) |

Each element of `diagnostics` (LSP-aligned subset):

| Field | Type | Required |
|-------|------|----------|
| `range` | object `{ start: { line, character }, end: { line, character } }` | yes, UTF-16 per LSP |
| `severity` | number or string | yes (`1`=Error, `2`=Warning, … LSP enum) |
| `message` | string | yes |
| `source` | string | recommended (`gram-lsp`) |
| `code` | string or number | optional, stable for tests |

## Parity with editor (SC-004)

For the same UTF-8 input text and version of the server, the multiset of `(path, range, message, severity)` for syntax-level diagnostics MUST match between:

1. What the server would publish via LSP for that buffer, and  
2. The `diagnostics` arrays in this JSON for the same paths.

Allowed differences: `path` normalization only; no semantic omission or extra errors.
