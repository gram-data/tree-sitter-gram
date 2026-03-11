# Editor Support and Syntax Highlighting Improvements

**Status:** Proposal (summary of discussion)  
**Scope:** Tree-sitter-gram grammar, query files, editor integrations, and documentation.

---

## 1. Current state (review)

### Grammar

- **grammar.js** clearly separates pattern vs path notation: `subject_pattern` `[...]`, `node_pattern` `(...)`, `relationship_pattern`, `annotated_pattern`, `pattern_reference`.
- **Identifiers** (`_identifier` = symbol | string_literal | integer) appear as:
  - Subject/node/relationship identity, `@@` annotation identity and labels, `pattern_reference` (bare id in `[ ... | a, b ]`), and record/map keys.
- **Tagged strings:** `` tag`content` `` and ``` ```tag\ncontent\n``` ``` with `tag` (symbol) and `content` (string_content). No grammar-level restriction on tag names.

### Editor support

- **Queries:** Only `queries/highlights.scm` (and a copy under `editors/zed/languages/gram/`). No `locals.scm`, `indents.scm`, or `injections.scm` in the initial review.
- **Zed:** Extension points at the repo; `scripts/prepare-zed-extension.sh` syncs `queries/*.scm` into the extension. File type `.gram`, scope `source.gram`.
- **Other editors:** No in-repo VSCode/Neovim/Emacs config; they can use the npm package and point at `queries/` where supported.
- **Highlighting:** Strings, numbers, booleans, `symbol` → `@variable`, record/map keys → `@property`, annotation key/identifier/labels → `@attribute`, `subject_pattern` → `@type`, node labels → `@type`, `relationship_pattern` → `@keyword`, arrows → `@operator`, brackets/punctuation, `ERROR` → `@error`. All symbols are treated the same; no distinction between defining vs referencing identifiers.

---

## 2. Proposed improvements (general)

### Syntax highlighting (highlights.scm)

- **Differentiate identifier roles:** Capture definition-like identifiers (subject, node, relationship, annotation) separately from references (`pattern_reference`) so they can be styled differently (e.g. type-like vs variable/reference).
- **Tagged-string tag:** Explicitly capture the tag in `tagged_string` (e.g. `@type` or `@attribute`) so tags are highlighted distinctly.
- **Comments:** If the grammar exposes a named `comment` node, add `(comment) @comment`.
- **Single source of truth:** Keep one canonical `queries/highlights.scm` and have the Zed extension consume it via the existing sync script (no duplicate maintenance).

### Identifiers as unique symbols (semantics)

- **Add `queries/locals.scm`** using Tree-sitter’s local-variable captures:
  - **`@local.definition`:** Where an identifier is defined (subject in `subject_pattern`, identifier in `node_pattern`, subject in relationship arrows, identifier in `identified_annotation`).
  - **`@local.reference`:** Where an identifier is used as a reference (`pattern_reference` identifier).
  - **`@local.scope`** (optional): e.g. `gram_pattern` (file) and optionally `subject_pattern`, so references resolve to the right definition.
- Enables editors that support tree-sitter locals (Neovim, Helix, Emacs, etc.) to do “highlight references” and “go to definition” without an LSP.
- **Scope rules:** At least file scope; optionally refine so references inside a subject pattern resolve appropriately.

### Indentation and other queries

- **`queries/indents.scm`:** Define indentation for brackets and multi-line structures so tree-sitter–aware editors get consistent indent.
- **Optional:** `injections.scm` for embedding other languages (see below).

---

## 3. Tagged strings and language injection

### Question

Downstream uses well-known tags (`md`, `ts`, `date`, `datetime`, `time`, `sql`, etc.). Do we need to specify each of these in the grammar or query files?

### Proposal

- **No need to enumerate every tag in the grammar.** The grammar already allows any symbol as tag; tagged strings are a single generic construct.
- **Injection strategy:**
  - **Dynamic injection:** Use the tag symbol’s text as the injection language name. One rule in `injections.scm`: capture `tag` as `@injection.language`, content as `@injection.content`. Editors that support dynamic language from a capture (e.g. Neovim, Zed) then use the tag (e.g. `sql`, `json`, `html`) as the parser name.
  - **Overrides only where needed:** Add explicit rules only for tags that don’t match common parser names (e.g. `md` → `markdown`, `ts` → `typescript`) using `#eq?` and `#set! injection.language "markdown"` (or similar). Other tags (e.g. `date`, `datetime`, `time`) may have no parser or be mapped by the editor; the grammar stays agnostic.
- **Well-known tags** can be documented (e.g. in a doc like `docs/tagged-strings-and-injections.md`) as a convention table (md, ts, date, datetime, time, sql, json, html, etc.) so downstream and editors know what to expect and can add their own tag → parser mappings without changing the grammar.

---

## 4. Schema definitions: `::` and `=>` convention

### Observation

The `::` and `=>` / `==>` variations are used to imply schema definitions. For example, `{ name:: ts\`string\` }` is read as: property `name` has value-type described in TypeScript (e.g. “string”). Value types have used `ts`, `SQL`, and other languages, which avoids explicit grammar support for schema.

### Proposal

- **Grammar:** No change. `record_property` already allows both `:` and `::`; the value can be any `_value`, including tagged strings.
- **Convention:** Document that `::` is used for type/schema slots and that the value is often a tagged string (e.g. `ts`, `SQL`) describing the type. This keeps schema semantics out of the core grammar and lets each ecosystem choose its type languages.
- **Support in editors:** Language injection applies to tagged string content regardless of context. So `name:: ts\`string\`` gets TypeScript highlighting inside the backticks via the same `injections.scm` rules. No extra grammar or query logic is required for schema-specific languages.
- **Downstream:** Libraries can treat `key:: tagged_string` as “property `key` has type/schema given by tag and content” and dispatch to the right validator or code generator (e.g. `ts` → TypeScript, `SQL` → schema). Encouragement is mainly through documentation and examples (e.g. in `docs/` and `examples/`).

---

## 5. Summary table

| Area | Current | Proposed |
|------|--------|----------|
| **highlights.scm** | Single `@variable` for all symbols | Differentiate definition-like vs reference identifiers; capture tagged-string tag; add comment if exposed |
| **Identifiers as symbols** | Not modeled | Add **locals.scm** with `@local.definition`, `@local.reference`, optional `@local.scope` |
| **Injections** | None | **injections.scm**: dynamic injection from tag text; overrides for md→markdown, ts→typescript; document well-known tags |
| **Schema / `::`** | Grammar allows `::`; no documented convention | Document `::` for type/schema and tagged strings (ts, SQL, etc.); no new grammar rules |
| **Indentation** | None | Add **indents.scm** for brackets and multi-line structures |
| **Docs** | — | Document tagged strings, well-known tags, and `::` schema convention (e.g. dedicated doc + cross-links from gram-reference / gram-ebnf) |

---

## 6. References

- Grammar: `grammar.js`, `docs/gram-ebnf.md`
- Queries: `queries/highlights.scm`; proposed `queries/injections.scm`, `queries/locals.scm`, `queries/indents.scm`
- Zed: `editors/zed/`, `scripts/prepare-zed-extension.sh` (syncs `queries/*.scm`)
- Tree-sitter: injection captures `@injection.language`, `@injection.content`; locals `@local.definition`, `@local.reference`, `@local.scope`
