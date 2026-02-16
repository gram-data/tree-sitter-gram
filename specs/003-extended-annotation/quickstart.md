# Quickstart: Extended Annotation

**Feature**: 003-extended-annotation  
**Date**: 2025-02-16

## Overview

This quickstart covers implementing extended annotations (`@@` for identifier/labels, `@` for property-style) and documents the full grammar syntax and semantics for the Gram notation.

---

## Implementation Steps

### 1. Update the grammar (`grammar.js`)

- **Stacking rule**: Annotations stack on a single body. Allow **at most one** optional `identified_annotation` (`@@`) followed by **zero or more** `property_annotation` (`@`). The body is the single **elements** of `annotated_pattern` (appears once after the whole stack). So: `annotations: choice(seq($.identified_annotation, repeat($.property_annotation)), repeat1($.property_annotation))`.
- **Introducer**: `@@` = identified/labeled (at most one); `@` = property-style (zero or more). Match `@@` before `@` so the parser distinguishes them.
- **Property-style** (single `@`): Keep current shape: `@` + `field("key", $.symbol)` + `"("` + `field("value", $._value)` + `")"`. Rule name `property_annotation`.
- **Identified/labeled** (`@@`): Add a rule **identified_annotation** for `@@` with **identifier** and/or **labels** as direct fields (no separate header node; no parentheses; no body in this rule). Use a choice: identifier only, labels only, or identifier then labels (at least one required). Reuse `_identifier` and `labels`. The body is **not** part of `identified_annotation`; it is the `elements` field of the parent `annotated_pattern`.
- **annotated_pattern**: Unchanged: `seq(field("annotations", $.annotations), field("elements", choice($.subject_pattern, $._path_pattern)))`. So the body appears once after all annotations.

### 2. Regenerate parser

```bash
npx tree-sitter generate
```

### 3. Add corpus tests

Create or update `test/corpus/extended_annotations.txt` with "source ===> tree" cases:

- `@@p (a)` — identifier only
- `@@:L (a)` — labels only
- `@@p:L (a)` — identifier + labels
- `@desc (a)` and `@desc("text")` — property-style (unchanged)
- `@@route66:Highway @name("Route 66") @description("A famous roadway in the USA") (a)-->(b)-->(c)` — one `@@` then two `@` then body
- Negative: `@@ (a)` — invalid empty header

### 4. Run tests

```bash
npx tree-sitter test
npm test
```

### 5. Update examples and docs

If the AST for annotations gains new node types or fields, update `examples/` and any binding docs. Ensure quickstart and this grammar reference stay in sync.

---

## Grammar Syntax and Semantics Reference

This section documents the Gram notation: syntax and semantics for arity, annotations, nodes, relationships, paths, generic patterns, and value types. It serves as the single reference for the language.

### 1. Pattern notation and arity

Gram supports **pattern notation** (brackets) and **graph notation** (nodes, relationships, paths). The semantic role of a pattern is determined by its **arity** (number of elements).

| Arity | Notation example | Topology | Semantic role |
|-------|------------------|----------|----------------|
| **0** | `[a]` | Node | Entity: atomic unit. |
| **1** | `[b \| a]` | Wrapper | Annotation: `b` wraps `a`. |
| **2** | `[r \| a, b]` | Relationship | Connection: `r` connects `a` to `b`. |
| **N** | `[C \| a, b, c]` | Component | Composition: `C` contains multiple elements. |

- **Brackets** `[...]` define a pattern (anonymous or identified).
- **Subject** (optional) before `|`: identifier, labels, and/or record.
- **Elements** (optional) after `|`: comma-separated list of pattern elements (brackets, paths, or bare references).

### 2. Annotations

Annotations **stack** on a single body. Order: **at most one** `identified_annotation` (`@@`), then **zero or more** `property_annotation` (`@`), then the **body** (node, relationship, or path) once.

**Example**: `@@route66:Highway @name("Route 66") @description("A famous roadway in the USA") (a)-->(b)-->(c)` — one `@@`, two `@`, then the path as body.

#### 2.1 Property-style (`@`)

- **Syntax**: `@` *key* `(` *value* `)`  
- **Meaning**: Property *key* with *value*. The parenthesized part is the value expression.  
- **Example**: `@name("Route 66")` — key `name`, value string `"Route 66"`.  
- **Value types**: Any `_value`: symbol, string, number, boolean, range, array, map, tagged string. Zero or more may appear before the body.

#### 2.2 Identified/labeled (`@@`)

- **Syntax**: `@@` *header content* (identifier and/or labels; no parentheses in this token; the body follows the entire annotation stack.)  
- **Meaning**: A wrapper with optional identifier and/or labels; the **body** is the single element that follows all annotations (the node, relationship, or path). Maps to a 1-arity pattern. At most one `@@` per annotated element; it must appear first if present.  
- **Header**: Optional identifier, optional labels (at least one required). Same order and syntax as subject position (`:`, `::` + symbol). **Identifier semantics**: use **short names**, **GUIDs**, or **pseudo-sequences** (e.g. `p`, `r1`, `seg_ab`). Property-like terms (verified, name, description) belong in `@` form: `@verified(true)`, `@name("Route 66")`, not `@@verified`.  
- **Body**: The annotated element — defined once after the stack (e.g. `(a)`, `(a)-[r]->(b)`, or a path).  
- **Examples**:
  - `@@p (a)` — identifier `p` (short name); body is node `(a)`
  - `@@r1 (a)-[r]->(b)` — identifier `r1` (pseudo-id for the relationship wrapper); body path
  - `@@:L (a)` — labels only; body `(a)`
  - `@@p:L (a)` — identifier `p` and label `L`; body `(a)`
  - `@@route66:Highway @name("Route 66") @verified(true) (a)-->(b)-->(c)` — one `@@` (named/labeled wrapper), then properties `@name`, `@verified`; body path

**Disambiguation**: Single `@` = property-style; `@@` = identified/labeled. No overlap. **Stacking**: only one `@@` allowed; zero or more `@`; body once at the end.

### 3. Nodes (graph notation)

- **Syntax**: `(` *subject* `)`  
- **Subject**: Optional identifier, labels, and/or record (same as in bracket subject).  
- **Semantics**: Equivalent to 0-arity pattern `[subject]`.  
- **Example**: `(a)`, `(a:Person)`, `(a { name: "x" })`.

### 4. Relationships

- **Syntax**: *left* *kind* *right*  
  - *left* / *right*: node or path.  
  - *kind*: arrow with optional relationship subject in brackets.  
- **Arrow variants**:  
  - Undirected: `-[-]`, `= =`, `~ ~`  
  - Right: `-[-]->`, `=>`, `~>`  
  - Left: `<-[-]-`, `<=`, `<~`  
  - Bidirectional: `<-[-]->`, etc.  
- **Relationship subject**: Optional `[` *subject* `]` between the arrow symbols (e.g. `-[r]->`).  
- **Semantics**: Equivalent to 2-arity pattern `[r \| left, right]` with direction encoded in the arrow.

### 5. Paths

- **Syntax**: Chained relationships, e.g. `(a)-[r1]->(b)-[r2]->(c)`.  
- **Semantics**: Path is a component (N-arity pattern): an anonymous pattern containing a sequence of relationships. Order of relationships is significant.

### 6. Generic (bracket) patterns

- **Syntax**: `[` *subject*? `|` *elements*? `]`.  
- **Subject**: identifier, labels, record, or combinations (same rules as node subject).  
- **Elements**: Comma-separated; each element is a bracket pattern, path, or **pattern reference** (bare identifier).  
- **References**: A bare identifier in element position references an existing pattern; brackets define a pattern.

### 7. Value types

Values appear in property-style annotation values, records, maps, and similar contexts.

| Type | Syntax examples | Notes |
|------|------------------|--------|
| **Symbol** | `a`, `foo.bar` | `[a-zA-Z_][0-9a-zA-Z_.\-@]*` |
| **String** | `'x'`, `"x"`, `` `x` ``, ` ```fenced``` ` | Single/double/backtick/fenced. |
| **Integer** | `0`, `42`, `-1` | Decimal. |
| **Decimal** | `3.14`, `-0.5` | |
| **Hex** | `0xff` | |
| **Octal** | `0o77` | |
| **Measurement** | `42m`, `1.5kg` | Number + unit. |
| **Boolean** | `true`, `false` | |
| **Range** | `1..10`, `1...`, `...10` | Inclusive/exclusive bounds. |
| **Tagged string** | `` lang`code` ``, ` ```lang\ncode``` ` | Tag + content. |
| **Array** | `[v1, v2]` | Comma-separated scalar values. |
| **Map** | `{ k: v, ... }` | Key–value pairs; value is scalar. |
| **Record** | `{ k: v, ... }` (in subject) | Key–value with `:` or `::`; value can be any _value. |

*Scalar value* (in arrays and map values): symbol, string, number, boolean, range, tagged string — not array/map (no nesting of structural values in scalar contexts where the grammar restricts to _scalar_value).

### 8. Labels

- **Syntax**: `:symbol` or `::symbol` (single or multiple).  
- **Used in**: Subject position (brackets, nodes), relationship subject, and `@@` annotation headers.  
- **Consistent** across all these positions.

### 9. Comments

- **Syntax**: `//` to end of line.  
- **Handling**: In grammar extras; ignored for structure, may appear in AST for tooling.

---

## Summary

- **Annotations**: `@` = property (key + value); `@@` = identifier and/or labels wrapping a body.  
- **Arity**: 0 node, 1 wrapper/annotation, 2 relationship, N component.  
- **Graph**: Nodes `(...)`, relationships with arrows, paths as chains.  
- **Values**: Symbol, strings, numbers, boolean, range, tagged string, array, map; records in subject.  
- **Implementation**: Grammar change for `@@` (identified_annotation with identifier/labels fields), corpus tests, then regenerate and validate.
