# Contract: LSP capabilities and methods

**Feature**: 006-gram-lsp  
**Date**: 2026-04-26

## Server identity

- **Name**: `gram-lsp` (or package name; must be stable in `initializeResult.serverInfo.name`).
- **Document selector**: `language_id` `gram` and/or `*.gram` pattern as agreed with editor configs.

## MVP capabilities (must)

| Area | Behavior |
|------|----------|
| Text sync | Full or incremental (`textDocumentSync`) for `.gram` / `gram` language id |
| Diagnostics | `textDocument/publishDiagnostics` after open, change (debounced), save, close |
| Hover | `textDocument/hover` returns Markdown or plaintext contents |
| Definition | `textDocument/definition` from reference sites to definition sites |
| References | `textDocument/references` including declaration site in results per LSP convention |
| Completion | `textDocument/completion` with contextual items where grammar allows |
| Workspace | Honor `workspaceFolders` / root; `workspace/symbol` optional (defer if not needed for spec) |

## Deferred (may)

| Area | Notes |
|------|------|
| `textDocument/formatting` | Not in spec; defer |
| `textDocument/codeAction` | Defer |
| `textDocument/signatureHelp` | Defer unless trivial |
| `textDocument/semanticTokens` | Defer; syntax highlighting remains editor Tree-sitter |

## Failure behavior (FR-007)

- Invalid requests: respond with LSP error object; do not panic.
- Parse internal failure: publish single diagnostic or `showMessage` with severity `Error` once per session spike; CLI exits non-zero.
