# Data Model: Extended Annotation

**Feature**: 003-extended-annotation  
**Date**: 2025-02-16

## Overview

This feature extends the annotation syntax and corresponding AST. The grammar currently has a single `annotation` rule: `@` + key (symbol) + `(` + value + `)`. The extension introduces two annotation kinds distinguished by the introducer token: **property-style** (single `@`) and **identified/labeled** (double `@@`). The AST must represent both forms and, for `@@`, an optional identifier and optional labels in the header.

## Entities and AST Structure

### Annotation (top level)

Annotations **stack** on a single body but are constrained: **at most one** optional `identified_annotation` (`@@`), then **zero or more** `property_annotation` (`@`). The sequence precedes the annotated element (body).

- **annotations** (grammar): Either (1) one optional `identified_annotation` followed by zero or more `property_annotation`, or (2) one or more `property_annotation` only. At least one annotation is required. So: `choice(seq(optional($.identified_annotation), repeat($.property_annotation)), repeat1($.property_annotation))` — but the first alternative must allow “identified only” (zero property), so use: `choice(seq($.identified_annotation, repeat($.property_annotation)), repeat1($.property_annotation))` (when identified is present it comes first; when absent, one or more property).
- **property_annotation** — introducer `@`, then key (symbol) and value (value expression) in parentheses.
- **identified_annotation** — introducer `@@`, then header (identifier and/or labels). It does **not** include the body; the body is the single element after the whole annotation stack (see annotated_pattern).

### Property-style annotation (single `@`)

| Field    | Type / Rule   | Description |
|----------|---------------|-------------|
| introducer | literal `@` | Present for property form (or implied by rule choice). |
| key      | symbol        | Property key. |
| value    | _value        | Value inside parentheses (symbol, string, number, boolean, range, array, map, tagged string). |

*Current grammar:* `annotation: seq("@", field("key", $.symbol), "(", field("value", $._value), ")")`  
*No structural change to this form; only the rule name may be `property_annotation` when split.*

### Identified/labeled annotation (double `@@`)

| Field      | Type / Rule     | Description |
|------------|-----------------|-------------|
| introducer | literal `@@`    | Distinguishes from property-style. |
| header     | annotation_header | Optional identifier, optional labels (at least one required). |

The **body** is not part of this rule: it is the single `elements` field of the parent `annotated_pattern` (the node, relationship, or path that follows the whole annotation stack). At most one `identified_annotation` may appear in the stack; it must be the first annotation if present.

**annotation_header** (for `@@` only):

| Component   | Rule / Field   | Description |
|-------------|----------------|-------------|
| identifier  | optional(_identifier) | Wrapper name. |
| labels      | optional(labels)     | Same as subject position (`:L`, `::L`). |

Order: identifier (if present) then labels (if present). At least one must be present. No record in header.

### Existing rules reused

- **_identifier**: symbol | string_literal | integer (unchanged).
- **labels**: repeat1(_label); _label: (":" | "::") + symbol (unchanged).
- **_value**: existing value types (unchanged for property annotation).
- **subject_pattern**, **_path_pattern**, **node_pattern**, **relationship_pattern**: used as annotation body for `@@` (unchanged).

## Validation Rules

- `@@` must be followed by a valid header (identifier and/or labels) then `(` body `)`.
- `@` must be followed by key (symbol) then `(` value `)`.
- Empty header after `@@` (e.g. `@@ (a)`) is invalid.
- Label syntax in `@@` header MUST match the rest of the notation (`:`, `::`, symbol).

## State Transitions

N/A — annotations are syntactic; no state machine.

## Relationships

- **annotated_pattern** → annotations (stack: optional one identified_annotation, then zero or more property_annotation) + elements (subject_pattern or _path_pattern = the body).
- **annotations** → choice( seq(identified_annotation, repeat(property_annotation)), repeat1(property_annotation) ). So: at most one `@@`, then zero or more `@`; at least one annotation total.
- **identified_annotation** → header (annotation_header) only; body is annotated_pattern.elements.
- **property_annotation** → key + value (no body; body is annotated_pattern.elements).
- **annotation_header** → optional identifier, optional labels (same rules as _subject for those parts). Identifier in `@@` is a naming identifier (short name, GUID, pseudo-sequence); property-like terms (e.g. verified, name) use property_annotation: `@verified(true)`, not `@@verified`.

## Backward Compatibility

- Existing `@key(value)` continues to parse as property_annotation. No change to AST shape for this form beyond possible rule rename to `property_annotation`.
- New `@@` form adds new rule(s) and possibly new node types in `node-types.json`; bindings that only iterate annotations by kind can treat `property_annotation` as the legacy form.
