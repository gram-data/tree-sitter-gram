# Quickstart: Editor Support and Syntax Highlighting

**Feature**: 004-editor-improvements  
**Date**: 2025-03-11

## Prerequisites

- Node.js and npm
- Tree-sitter CLI: `npm install -g tree-sitter-cli` (or use `npx tree-sitter`)

## Build and test (repo root)

```bash
# Regenerate parser (no grammar change in this feature; run for hygiene)
npx tree-sitter generate

# Run grammar corpus tests
npx tree-sitter test

# Run Node binding tests (if applicable)
npm test
```

## Query files

Canonical query files live under `queries/`:

- `queries/highlights.scm` — syntax highlighting (extend for definition/reference, tag, comment)
- `queries/locals.scm` — go to definition / highlight references (add if missing)
- `queries/indents.scm` — indentation rules, 2 spaces (add if missing)
- `queries/injections.scm` — language injection for tagged strings (existing; ensure md/ts overrides)

Do not edit copies under `editors/zed/languages/gram/` directly; they are synced from `queries/`.

## Sync to Zed extension

After changing any `queries/*.scm`:

```bash
./scripts/prepare-zed-extension.sh
```

This copies `queries/*.scm` into `editors/zed/languages/gram/`, runs tests, and updates the extension metadata.

## Manual verification

1. **Highlights**: Open a .gram file with subject patterns, node patterns, pattern references, and tagged strings. Check that definitions and references use different styles and that the tag is distinct from the content; check that `//` comments are highlighted.
2. **Locals**: In an editor that supports tree-sitter locals (e.g. Neovim with nvim-treesitter, Helix), open a .gram file, put the cursor on a pattern reference, run “go to definition”; put the cursor on a definition, run “highlight references.”
3. **Indentation**: In a .gram file with nested brackets, use the editor’s indent/format and confirm 2-space step and bracket alignment.
4. **Injections**: Add `` sql`SELECT 1` ``, `` ts`string` ``, `` md`*bold*` `` and confirm SQL/TypeScript/Markdown highlighting inside the content.

## Docs

- Well-known tags and `::` convention: `docs/tagged-strings-and-injections.md`
- Spec and contracts: `specs/004-editor-improvements/spec.md`, `specs/004-editor-improvements/contracts/`

## Next

Run `/speckit.tasks` to generate `tasks.md` for implementation tasks (Phase 2).
