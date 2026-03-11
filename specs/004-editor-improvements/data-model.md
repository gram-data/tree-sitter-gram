# Data Model: Editor Support and Syntax Highlighting

**Feature**: 004-editor-improvements  
**Date**: 2025-03-11

This feature does not introduce a persistent data store or API entities. The “data model” here describes the **query capture model**: which grammar nodes map to which Tree-sitter capture names for highlights, locals, indents, and injections. Validation rules come from the spec (FR-001–FR-010).

---

## 1. Grammar nodes used by queries

Relevant rules from `grammar.js` (no changes in this feature):

| Node | Description |
|------|-------------|
| `gram_pattern` | Root; optional root record + repeated top-level patterns |
| `subject_pattern` | `[ subject \| elements ]`; subject is definition-like |
| `node_pattern` | `( subject )`; subject is definition-like |
| `relationship_pattern` | `left kind right`; left/right node subjects and kind (arrow) carry definitions |
| `pattern_reference` | Bare identifier; reference (use) of a pattern |
| `identified_annotation` | `@@ identifier` or `@@ labels`; identifier/labels are definition-like |
| `tagged_string` | `tag\`content\`` or ``` ```tag\ncontent\n``` ```; tag (symbol), content (string_content) |
| `comment` | `// ...` (in extras) |
| `record`, `labels`, `_subject`, `_identifier`, `symbol`, `string_content` | Used inside the above |

---

## 2. Highlight captures (highlights.scm)

| Capture | Grammar source | Purpose |
|--------|----------------|---------|
| Definition-like identifier | `subject_pattern` subject, `node_pattern` subject, `relationship_pattern` left/right subject, arrow kind subject, `identified_annotation` identifier/labels | Style as type/definition (e.g. `@type`) |
| Reference identifier | `pattern_reference` identifier | Style as variable/reference (`@variable`) |
| Tagged-string tag | `tagged_string` field `tag` (symbol) | Style distinctly (e.g. `@attribute`) |
| Tagged-string content | `tagged_string` field `content` (string_content) | Already string; injection handles language |
| Comment | `(comment)` | `@comment` |
| Existing | string_literal, number, boolean, property, bracket, operator, ERROR | Unchanged per current highlights.scm |

**Validation**: FR-001 (definition vs reference), FR-002 (tag distinct), FR-003 (comment), FR-004 (single canonical file).

---

## 3. Locals captures (locals.scm)

| Capture | Grammar source | Scope |
|--------|----------------|-------|
| `@local.definition` | Identifier in: subject of subject_pattern, subject of node_pattern, subject of relationship left/right, subject in relationship kind (arrow), identifier/labels in identified_annotation | File |
| `@local.reference` | Identifier in pattern_reference | File |
| `@local.scope` (optional) | `gram_pattern` (root) | Single file scope |

**Validation**: FR-005 (definition + reference), FR-006 (optional file scope). References resolve to any matching definition in the file.

---

## 4. Indent captures (indents.scm)

| Capture | Grammar source | Effect |
|--------|----------------|--------|
| `@indent` / indent begin | Opening of record `{`, subject_pattern `[`, node_pattern `(`, etc. | Increase indent by 2 spaces |
| `@indent.end` / dedent | Closing `}`, `]`, `)` | Align with opening; decrease indent |
| `@extend` (if needed) | Continuation of multi-line pattern | Extend scope so following lines get correct indent |

**Validation**: FR-007 (indentation for brackets and multi-line; 2 spaces per level).

---

## 5. Injection captures (injections.scm)

| Capture | Grammar source | Purpose |
|--------|----------------|---------|
| `@injection.language` | `tagged_string` field `tag` (symbol) | Dynamic: tag text as language name; overrides for md→markdown, ts→typescript |
| `@injection.content` | `tagged_string` field `content` (string_content) | Injected region |

**Validation**: FR-008 (dynamic; both inline and fenced forms), FR-009 (minimal overrides md, ts).

---

## 6. Documentation (non-capture)

| Artifact | Content |
|----------|---------|
| Well-known tags | Convention table: md, ts, date, datetime, time, sql, json, html (and mapping notes) |
| `::` schema convention | Document that `::` denotes type/schema slots; values often tagged strings |

**Validation**: FR-010. Existing `docs/tagged-strings-and-injections.md` covers this; extend or cross-link as needed.

---

## 7. State and lifecycle

No state machines or lifecycle. Query files are static; editors load them and apply captures to the AST. Scope is file-wide only; no cross-file resolution.
