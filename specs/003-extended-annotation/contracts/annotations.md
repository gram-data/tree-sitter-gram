# Contract: Annotation AST Shape

**Feature**: 003-extended-annotation

## Introducer distinction

| Introducer | Rule name (recommended) | Meaning |
|------------|-------------------------|---------|
| `@`        | property_annotation     | Property key with value; body is the value expression. |
| `@@`       | identified_annotation   | Identifier and/or labels wrapping the following body; body is the annotated element. |

The parser MUST produce different node types (or a discriminable structure) for `@` vs `@@` so that consumers can tell property-style from identifier/labels without heuristics.

## Property-style annotation (`@`)

- **Structure**: `@` + key + `(` + value + `)`.
- **AST** (logical):
  - key: symbol (property name).
  - value: _value (symbol, string, number, boolean, range, array, map, tagged_string, etc.).
- **No change** to existing annotation shape for this form; backward compatible.

## Identified/labeled annotation (`@@`)

- **Structure**: `@@` + header content (no parentheses; the body is **not** part of this rule). Header content is identifier and/or labels (at least one required); order: identifier then labels (same as subject position).
- **Body**: The body is the single **elements** field of the parent **annotated_pattern** (the node, relationship, or path that follows the entire annotation stack). So for `@@route66:Highway @name("Route 66") (a)-->(b)`, the body `(a)-->(b)` appears once after all annotations.
- **AST** (logical): **identified_annotation** node with two direct fields (no separate header node):
  - identifier: optional (_identifier).
  - labels: optional (labels rule, same as elsewhere).
  - (Body is sibling: annotated_pattern.elements.)

## Stacking constraint

- **At most one** `identified_annotation` (`@@`) per annotated element; it MUST appear first if present.
- **Zero or more** `property_annotation` (`@`) follow (or appear alone).
- Grammar: `annotations: choice(seq(identified_annotation, repeat(property_annotation)), repeat1(property_annotation))`. So: `@@` only, `@@` + one or more `@`, or one or more `@` only. Invalid: two or more `@@` (e.g. `@@p @@q (a)`).

## Required behaviors

1. **Disambiguation**: A source span starting with `@@` MUST be parsed as identified_annotation; starting with `@` (and not `@@`) as property_annotation.
2. **Header recovery**: For `@@`, the structure (identifier only, labels only, or both) MUST be deterministically recoverable from the AST via identified_annotation’s identifier and labels fields.
3. **Invalid forms**: `@@` with no header, or `@` with no key, MUST be rejected (parse error or invalid node). Two or more `@@` before the body MUST be rejected.

4. **Identifier vs property**: Identifiers in `@@` headers are naming identifiers (short names, GUIDs, pseudo-sequences). Property-like terms (verified, name, description) MUST use property_annotation: `@verified(true)`, `@name("Route 66")` — not `@@verified` or `@@name`.

## Example (logical)

Source:

```gram
@@route66:Highway @name("Route 66") @description("A famous roadway in the USA") (a)-->(b)-->(c)
```

Expected logical structure:

- **annotated_pattern**: annotations (stack) + elements (body once).
- **annotations**: one identified_annotation then two property_annotations.
  - identified_annotation: identifier `route66`, labels `Highway` (direct fields; no body in node; body is shared).
  - property_annotation: key `name`, value `"Route 66"`.
  - property_annotation: key `description`, value `"A famous roadway in the USA"`.
- **elements** (body): path `(a)-->(b)-->(c)` — the single element that all annotations apply to.
