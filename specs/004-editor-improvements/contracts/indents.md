# Indents Query Contract

**Feature**: 004-editor-improvements  
**File**: `queries/indents.scm`

## Required behavior

- Indentation for brackets and multi-line structures so tree-sitter–aware editors apply consistent indent (FR-007).
- Indent width: 2 spaces per level (spec clarification).

## Capture pattern

Use standard Tree-sitter indent captures:

- **Indent increase**: Opening delimiters of record `{`, subject_pattern `[`, node_pattern `(`, and similar bracket/block nodes → capture that increases indent (e.g. `@indent` or language-specific indent begin).
- **Indent decrease / align**: Closing `}`, `]`, `)` → capture that aligns with opening and reduces indent (e.g. `@indent.end`).
- **Extend** (if needed): Nodes that span multiple lines so that continuation lines receive the correct indent (e.g. `@extend`).

Exact capture names depend on the editor (Neovim vs Helix vs Zed); the contract is “2 spaces per level” and “brackets and multi-line structures” aligned.

## Single source of truth

indents.scm MUST exist under `queries/` and be synced to Zed via `scripts/prepare-zed-extension.sh`.

## Test requirements

- Create or open a .gram file with nested brackets and multi-line patterns; use editor auto-indent; verify 2-space step and alignment of closing brackets with opening.
