# Injections Query Contract

**Feature**: 004-editor-improvements  
**File**: `queries/injections.scm`

## Required captures

| Capture | Node / pattern | Spec reference |
|--------|----------------|----------------|
| @injection.language | tagged_string tag (symbol): use tag’s text as language name | FR-008 |
| @injection.content | tagged_string content (string_content) | FR-008 |

## Dynamic injection

Language is NOT pre-defined. The tag symbol’s text is the injection language name. Both forms MUST be supported with the same semantics:

- Inline: `` tag`content` ``
- Fenced: ``` ```tag\ncontent\n``` ```

## Minimal override set (spec)

When the tag text does not match the editor’s parser name, overrides MUST be provided for:

- `md` → markdown  
- `ts` → typescript  

(FR-009). Other tags (e.g. `sql`, `json`, `html`) use the tag as the language name; no override required in the spec. Additional overrides (e.g. `zod`) may be added in docs or by editors.

## Rule order

Override rules (md, ts) MUST appear before the generic dynamic rule that sets `@injection.language` from the tag, so that `md` and `ts` are resolved to markdown and typescript.

## Single source of truth

injections.scm MUST exist under `queries/` and be synced to Zed via `scripts/prepare-zed-extension.sh`.

## Test requirements

- Tagged string with tag `sql` (or `json`, `html`) → content highlighted with that language (dynamic).
- Tagged string with tag `md` → content highlighted as markdown (override).
- Tagged string with tag `ts` → content highlighted as typescript (override).
- Unknown tag → content may be plain or editor-defined; no requirement to enumerate all tags.
