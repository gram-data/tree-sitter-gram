# Tagged Strings and Language Injection

This document describes how tagged strings work in Gram notation, how syntax highlighting (language injection) is applied to their content, and how the `::` convention supports schema definitions without extending the grammar for each type system.

---

## 1. Tagged string syntax

A **tagged string** attaches a type or format tag to string content:

- **Backtick form:** `` tag`content` ``
- **Fenced form:** ` ```tag` followed by a newline, then content, then ` ``` `

The tag is a **symbol**; the content is arbitrary text (backtick form: single line with escapes; fenced form: multiline). The grammar does not restrict which tags may appear. Downstream libraries and editors interpret tags by convention.

---

## 2. Language injection (syntax highlighting)

Tree-sitter injection queries (`queries/injections.scm`) use the **tag’s text as the injection language**. You do **not** need to add every possible tag to the grammar or query file.

- **Dynamic injection:** For most tags, the content is highlighted with the language whose name matches the tag (e.g. `sql`, `json`, `html`).
- **Overrides:** A small set of tags are mapped to parser names that differ from the tag (e.g. `md` → `markdown`, `ts` → `typescript`) in `injections.scm`. Adding more overrides is optional; editors and downstream tools can also map tag names to parsers themselves.

### Well-known tags

| Tag       | Typical use              | Parser / notes                                      |
|----------|---------------------------|-----------------------------------------------------|
| `md`     | Markdown                  | Mapped to `markdown` in injections.scm              |
| `ts`     | TypeScript (types/code)   | Mapped to `typescript` in injections.scm           |
| `date`   | ISO 8601 date             | Often no parser; content is `YYYY-MM-DD`            |
| `datetime` | ISO 8601 date-time      | Often no parser; content is ISO 8601                |
| `time`   | ISO 8601 time             | Often no parser; content is time part              |
| `sql`    | SQL                       | Tag used as language name (parser often `sql`)      |
| `json`   | JSON                      | Tag used as language name                           |
| `html`   | HTML                      | Tag used as language name                           |

Editors and consumers can extend this list by mapping additional tag names to language parsers (e.g. `yaml`, `graphql`) without changing the Gram grammar or its queries.

---

## 3. Schema definitions and the `::` convention

In records, the grammar allows two separators between a property key and its value:

- **`:`** — normal property: value is data.
- **`::`** — often used for **type or schema** definitions: value describes the *kind* or *shape* of the property rather than a literal value.

Example:

```gram
{ name:: ts`string`, count:: ts`number`, bio:: md`# Markdown allowed` }
```

Here, `name`, `count`, and `bio` are property names whose **value types** are described by tagged strings: TypeScript type expressions (`string`, `number`) and Markdown. Downstream can interpret `::` as “schema slot” and use the tagged content for validation, codegen, or documentation without the grammar ever defining TypeScript, SQL, or other schema languages.

### Encouraging and supporting this

- **Grammar:** No change is required. `record_property` already allows both `:` and `::`; the value can be any `_value`, including tagged strings.
- **Convention:** Document and use `::` for “type/schema” and reserve tagged strings (e.g. `ts`, `SQL`) for the type description. That keeps schema concerns out of the core grammar and lets each ecosystem choose its type languages.
- **Editors:** Injection applies to tagged string content regardless of context. So `name:: ts\`string\`` gets TypeScript highlighting inside the backticks. Editors that support tree-sitter injections will get this from the existing `injections.scm`.
- **Downstream:** Libraries can treat `key:: tagged_string` as “property `key` has type/schema given by tag and content,” and dispatch to the right validator or generator (e.g. `ts` → TypeScript type checker, `SQL` → schema validator).

---

## 4. Summary

- **Tags:** Arbitrary; no need to enumerate every tag in the grammar. Injection uses the tag symbol; a few well-known tags are mapped in `injections.scm`; the rest use the tag text as the language name or are mapped by the editor.
- **Schema:** Use `::` for type/schema properties and tagged strings (`ts`, `SQL`, etc.) for the type description. The grammar stays generic; schema support is by convention and downstream tooling.

---

## See also

- [Gram Notation Reference](gram-reference.md) — value types and `Value::TaggedString` in the data model
- [Gram EBNF](gram-ebnf.md) — formal `tagged_string` syntax (§9.5)
