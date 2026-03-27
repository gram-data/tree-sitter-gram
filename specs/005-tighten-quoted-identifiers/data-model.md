# Data Model: Tighten Quoted Names

**Feature**: `005-tighten-quoted-identifiers`  
**Date**: 2026-03-27

## Overview

This feature does not introduce runtime storage models. It refines the grammar and AST contract for how name-like text is expressed in three positions:

- identifiers
- labels
- record/map keys

The core model change is to separate **quoted names** from general **string values** so that the parser can distinguish naming syntax from arbitrary text.

Annotation sugar remains semantically tied to the same wrapper subject model used in bracket-pattern notation:

- `@key(value)` contributes a property on the wrapper subject
- `@@identifier:Label` contributes the wrapper subject's identifier and labels
- together they correspond to the subject portion of an implied wrapper pattern around the target

## Entities and AST Structure

### 1. Symbol

| Field | Type / Rule | Description |
|-------|-------------|-------------|
| text | token | Existing bare-name token matched by the `symbol` regex. |

**Behavior**:
- Remains the default unquoted name form.
- Continues to be valid in identifier, label, key, annotation-name, and tagged-string tag positions where it is already accepted.

### 2. Backtick Quoted Name

| Field | Type / Rule | Description |
|-------|-------------|-------------|
| content | string_content | Name text delimited by backticks, with existing backtick escape behavior. |

**Behavior**:
- Represents a name-like form, not a general string value.
- Valid in identifier positions.
- Valid as the textual part of a single label.
- Valid in record/map key positions.
- Not valid as a property annotation key or tagged-string tag.

### 3. Double-Quoted Key Name

| Field | Type / Rule | Description |
|-------|-------------|-------------|
| content | string_content | Key text delimited by double quotes, reusing the existing double-quote escape behavior. |

**Behavior**:
- Represents a key-specific quoted name.
- Valid only in record and map key positions.
- Not valid in identifier or label positions.

### 4. Identifier

| Field | Type / Rule | Description |
|-------|-------------|-------------|
| form | `symbol` \| backtick quoted name \| `integer` | The syntactic form used to name or reference a pattern element. |

**Used in**:
- Subject identifier fields
- Pattern references
- Identified annotation headers
- Relationship subject identifiers

**Validation rules**:
- Bare symbols remain valid.
- Existing numeric identifiers remain valid.
- Backtick-quoted names become the only quoted identifier form.
- Single-quoted, double-quoted, and fenced strings are invalid in identifier positions.

### 5. Label

| Field | Type / Rule | Description |
|-------|-------------|-------------|
| separator | `:` \| `::` | Existing stylistic separator. |
| form | `symbol` \| backtick quoted name | The textual label content. |

**Used in**:
- Subject labels
- Relationship subject labels
- Identified annotation labels

**Validation rules**:
- A single quoted label must remain one label even when the text contains whitespace.
- Double-quoted, single-quoted, fenced, and numeric forms are invalid as labels.

### 6. Key

| Field | Type / Rule | Description |
|-------|-------------|-------------|
| form | `symbol` \| backtick quoted name \| double-quoted key name | The name used for a record or map entry. |

**Used in**:
- `record_property`
- `map_entry`

**Validation rules**:
- Double-quoted keys remain valid for JSON-style authoring.
- Backtick-quoted keys support Cypher-like authoring and special characters.
- Single-quoted, fenced, and numeric key forms are invalid after this feature.

### 7. String Value

| Field | Type / Rule | Description |
|-------|-------------|-------------|
| form | existing `string_literal` variants | Arbitrary text value used in `_value` and `_scalar_value` contexts. |

**Behavior**:
- Unchanged by this feature.
- Continues to support single-quoted, double-quoted, backtick, and fenced strings where values are accepted.

## Relationships

- **Identifier** uses either **Symbol**, **Backtick Quoted Name**, or `integer`.
- **Label** uses a separator plus either **Symbol** or **Backtick Quoted Name**.
- **Key** uses either **Symbol**, **Backtick Quoted Name**, or **Double-Quoted Key Name**.
- **String Value** remains independent from identifier, label, and key syntax.
- **Property Annotation Key** and **Tagged String Tag** continue to depend only on **Symbol**.
- **Wrapper Subject** is assembled semantically from annotation sugar:
  - property annotation keys contribute wrapper-subject properties
  - identified annotation identifiers contribute wrapper-subject identity
  - identified annotation labels contribute wrapper-subject labels

## Validation Rules

1. A backtick-quoted name must preserve current backtick escaping rules.
2. A double-quoted key name must preserve current double-quote escaping rules.
3. Fenced strings are valid values but invalid identifiers, labels, and keys.
4. Single-quoted strings are valid values but invalid identifiers, labels, and keys.
5. Double-quoted strings are valid keys and values, but invalid identifiers and labels.
6. Integers remain valid identifiers only where they are already accepted today.
7. Property annotation keys and tagged-string tags remain bare-symbol only.

## State Transitions

N/A — this feature changes parse-time classification rules rather than introducing lifecycle state.

## Backward Compatibility

- Preserved:
  - Bare-name identifiers, labels, and keys
  - Double-quoted keys
  - Existing value strings in value positions
  - Numeric identifiers
- Intentionally narrowed:
  - Double-quoted identifiers
  - Single-quoted identifiers, labels, and keys
  - Fenced identifiers, labels, and keys
  - Numeric record/map keys
