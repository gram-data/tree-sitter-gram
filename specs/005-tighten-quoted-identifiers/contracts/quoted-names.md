# Contract: Quoted Identifier, Label, and Key Behavior

**Feature**: `005-tighten-quoted-identifiers`

## Scope

This contract governs the parser behavior for three name-like positions:

- identifiers
- labels
- record/map keys

It also defines which related positions remain `symbol`-only.

For semantic interpretation, annotation sugar maps onto the wrapper subject:

- `@key(value)` contributes a wrapper-subject property
- `@@identifier:Label` contributes the wrapper subject's identifier and labels
- these forms are alternate syntax for information that corresponds to the subject of an implied wrapper pattern

## Required Behaviors

### 1. Identifiers

Identifier positions MUST accept:

- `symbol`
- backtick-quoted name
- `integer` where numeric identifiers are already valid

Identifier positions MUST reject:

- single-quoted strings
- double-quoted strings
- fenced strings

**Examples**:

```gram
(route66)
(`route 66`)
(42)
```

Rejected:

```gram
("route 66")
('route 66')
```

### 2. Labels

Each label MUST consist of `:` or `::` followed by either:

- `symbol`
- backtick-quoted name

Labels MUST reject:

- double-quoted strings
- single-quoted strings
- fenced strings
- integers

**Examples**:

```gram
(a:Person)
(a:`Route Label`)
(a::`Schema Label`)
```

### 3. Record and Map Keys

Record and map keys MUST accept:

- `symbol`
- backtick-quoted name
- double-quoted name

Record and map keys MUST reject:

- single-quoted strings
- fenced strings
- integers

**Examples**:

```gram
({ name: "Alice" })
({ "display name": "Alice" })
({ `display name`: "Alice" })
```

### 4. Unchanged Value Behavior

String values in `_value` and `_scalar_value` contexts MUST continue to accept the existing string family:

- single-quoted
- double-quoted
- backtick-quoted
- fenced

This feature MUST NOT narrow or expand general value-string behavior.

### 5. Symbol-Only Contexts

The following contexts MUST remain `symbol`-only:

- property annotation keys
- tagged-string tags

Quoted-name support MUST NOT broaden those contexts.

## AST Expectations

1. The syntax tree MUST distinguish quoted names used as names from general string values well enough for query captures and downstream tooling to classify them correctly.
2. If visible node types are introduced for quoted names, they MUST be used consistently across identifier, label, and key positions.
3. Label captures in the syntax tree MUST continue to represent a single label even when the label text is backtick-quoted and contains whitespace.
4. Key captures in record and map nodes MUST preserve whether the key was bare, backtick-quoted, or double-quoted.

## Compatibility Expectations

Preserved:

- existing bare-name identifiers, labels, and keys
- existing double-quoted keys
- existing value strings in value positions
- existing symbol-only behavior for property annotation keys and tagged-string tags

Intentionally broken:

- double-quoted identifiers
- single-quoted identifiers, labels, and keys
- fenced identifiers, labels, and keys
- integer keys
