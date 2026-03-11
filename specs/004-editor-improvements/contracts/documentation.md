# Documentation Contract

**Feature**: 004-editor-improvements  
**Spec reference**: FR-010

## Required content

### 1. Well-known tags

Documentation MUST include a convention table (or equivalent) for well-known tags and how they map to parsers. At least: md, ts, date, datetime, time, sql, json, html.

- **md** → markdown (injections.scm override)
- **ts** → typescript (injections.scm override)
- **date**, **datetime**, **time** → often no parser; content format described (e.g. ISO 8601)
- **sql**, **json**, **html** → tag used as language name; editors may map as needed

Editors and downstream MAY add more tag → parser mappings without changing the grammar or query set.

### 2. `::` schema convention

Documentation MUST state that `::` is used for type/schema slots and that values are often tagged strings (e.g. `ts`, `SQL`) describing the type. No new grammar rules; convention only.

## Location

Existing `docs/tagged-strings-and-injections.md` already covers tagged strings, well-known tags, and the `::` convention. This feature requires that content to be present and up to date; extend or cross-link from gram-reference / gram-ebnf as needed.

## Test requirements

- A maintainer or editor author can find the well-known tags table and the `::` convention in the docs without reading the grammar source.
