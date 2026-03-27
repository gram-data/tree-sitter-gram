# Quickstart: Tighten Quoted Names

**Feature**: `005-tighten-quoted-identifiers`  
**Date**: 2026-03-27

## Overview

This feature narrows which quoted forms are accepted as names while keeping both JSON-friendly keys and Cypher-friendly identifiers/labels:

- identifiers: bare name, backtick-quoted name, existing numeric identifier
- labels: bare name or backtick-quoted name
- record/map keys: bare name, backtick-quoted name, or double-quoted name
- values: unchanged

Semantically, annotation syntax remains sugar for the wrapper subject:

- `@key(value)` supplies a wrapper-subject property
- `@@identifier:Label` supplies the wrapper subject's identifier and labels
- the bracket-pattern form remains the full surface, and the sugar forms do not need identical syntax to be semantically equivalent

## Implementation Steps

### 1. Update `grammar.js`

- Keep `symbol` unchanged as the bare-name token.
- Introduce dedicated quoted-name rules rather than reusing the full `string_literal` rule in name positions.
- Update `_identifier` so it accepts:
  - `symbol`
  - backtick-quoted name
  - `integer`
- Update `_label` so it accepts:
  - `:symbol`
  - `::symbol`
  - `:` or `::` followed by a backtick-quoted name
- Update record and map key rules to use a key-specific rule that accepts:
  - `symbol`
  - backtick-quoted name
  - double-quoted name
- Leave `_value`, `_scalar_value`, `property_annotation.key`, and `tagged_string.tag` unchanged.

### 2. Regenerate parser artifacts

```bash
npx tree-sitter generate
```

### 3. Update corpus tests

Revise or add focused fixtures in `test/corpus/` for:

- accepted identifiers:
  - `(a)`
  - `(``route 66``)`
  - `(42)`
- rejected identifiers:
  - `("route 66")`
  - `('route 66')`
  - fenced strings in identifier position
- accepted labels:
  - `(a:Person)`
  - `(a:`Role Label`)`
- rejected labels:
  - `(a:"Role Label")`
  - `(a:'Role Label')`
- accepted keys:
  - `{ name: "Alice" }`
  - `{ "display name": "Alice" }`
  - `{ `display name`: "Alice" }`
- rejected keys:
  - `{ 'display name': "Alice" }`
  - fenced key names
  - numeric key names if previously covered

### 4. Update queries

- Extend `queries/highlights.scm` so quoted labels and quoted keys are captured with the same semantic intent as their bare-name counterparts.
- Extend `queries/locals.scm` if visible quoted-name nodes participate in definition/reference captures.
- Keep `queries/injections.scm` unchanged unless implementation accidentally broadens tagged-string tags.
- Sync query changes into `editors/zed/languages/gram/` via the existing repo workflow.

### 5. Update docs

Revise:

- `docs/gram-reference.md`
- `docs/gram-ebnf.md`
- `docs/gram.ebnf`

Document that:

- identifiers no longer accept arbitrary `string_literal`
- labels support backticks but not double quotes
- keys support double quotes and backticks
- values still support the full string family

### 6. Run validation

```bash
npx tree-sitter test
npm test
```

## Accepted Syntax Examples

```gram
(route66)
(`route 66`)
(42)
(a:`Route Label`)
({ "display name": "Route 66" })
({ `display name`: "Route 66" })
```

## Rejected Syntax Examples

```gram
("route 66")
(a:"Route Label")
({ 'display name': "Route 66" })
({ ```
bad key
```: "Route 66" })
```

## Validation Checklist

- Bare-name behavior is unchanged.
- Backtick identifiers parse where quoted names are intended.
- Backtick labels remain single labels even with whitespace.
- Double-quoted keys remain valid.
- Single-quoted and fenced forms are rejected in name positions.
- Property annotation keys remain bare symbols only.
- Tagged-string tags remain bare symbols only.
