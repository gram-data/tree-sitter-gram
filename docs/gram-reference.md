# Gram Notation Reference

**Status:** Working reference — consolidates `gram-notation.md`, `gram-pattern-relationship.md`,
`gram-semantics.md`, and `grammar.js` (tree-sitter).  
**Open issues are marked** ⚠️ where questions remain unresolved.  
**Formal grammar:** See `gram.ebnf` for the authoritative syntactic specification.

---

## 1. What is Gram Notation?

Gram notation is a text format for serializing and deserializing `Pattern<Subject>` structures.
It provides two complementary syntactic styles for the same underlying data model:

- **Pattern notation** — uses square brackets `[...]` for general-purpose tree construction.
- **Path notation** — uses parentheses `(...)` for nodes and brackets `[...]` for relationship
  labels, in the style of Cypher.

Both styles produce the same `Pattern<Subject>` data structure and are fully interchangeable.
Every valid gram document can be parsed to a `Pattern<Subject>` tree and serialized back to gram
without loss of structure (though whitespace and style may differ).

Comments (`// to end of line`) and whitespace (spaces, tabs, newlines) are freely interspersed
between any two tokens and carry no semantic meaning. The one exception is fenced strings, whose
content begins on the line after the opening ` ``` `.

---

## 2. The Data Model: `Pattern<Subject>`

Every gram construct maps to a `Pattern<Subject>`, which has two fields:

```rust
Pattern<Subject> {
    value:    Option<Subject>,  // optional identity, labels, and properties
    elements: Vec<Pattern>      // zero or more child patterns
}
```

A `Subject` holds:

```rust
Subject {
    identity:   Symbol,
    labels:     HashSet<String>,
    properties: HashMap<String, Value>
}
```

The number of `elements` determines the structural role of a pattern:

| Element count | Role |
|---|---|
| 0 | Node / atomic pattern |
| 1 | Annotation wrapper |
| 2 | Relationship |
| N ≥ 3 | General / list pattern |

---

## 3. Pattern Notation (Square Brackets)

Square brackets always **define** a new pattern. A bare identifier inside a bracket expression
without further brackets **references** an existing pattern by identity.

### 3.1 Empty Pattern

```gram
[]
```

```rust
Pattern { value: None, elements: vec![] }
```

### 3.2 Identified Pattern

```gram
[a]
```

```rust
Pattern {
    value: Some(Subject { identity: Symbol::from("a"), labels: {}, properties: {} }),
    elements: vec![]
}
```

### 3.3 Labeled Pattern

```gram
[a:Person]
[a:Person:Employee]
[a::Type]              // double-colon — stylistically suggests schema/ontology intent
```

Labels use colon-prefix syntax and are unordered (stored as a set). A label may be a bare
symbol or a backtick-quoted name. `:` and `::` are **semantically equivalent** — the choice
is purely stylistic (see §7).

```rust
Subject { identity: Symbol::from("a"), labels: {"Person"}, ... }
Subject { identity: Symbol::from("a"), labels: {"Person", "Employee"}, ... }
```

### 3.4 Pattern with Properties

```gram
[a {name: "Alice", age: 30}]
[a:Person {name: "Alice"}]
```

Properties use a `record` — a `{key: value}` container attached to the subject (see §6).

### 3.5 Anonymous Value Pattern

```gram
["hello"]
[42]
```

A bare string or number with no identifier is stored in the reserved `_` property:

```rust
Subject {
    identity:   Symbol::anonymous(),
    properties: {"_": Value::String("hello")}
}
```

The key `_` is conventionally reserved for this purpose and should not be used in
user-written records.

### 3.6 Pattern with Elements (the Pipe Separator)

The `|` operator separates the subject (value) from its elements:

```gram
[root | a, b, c]
```

```rust
Pattern {
    value: Some(Subject::from_id("root")),
    elements: vec![
        Pattern { value: Some(Subject::from_id("a")), elements: vec![] },
        Pattern { value: Some(Subject::from_id("b")), elements: vec![] },
        Pattern { value: Some(Subject::from_id("c")), elements: vec![] },
    ]
}
```

Here `a`, `b`, `c` are **references**. See §8 for reference and forward-reference rules.

### 3.7 Nested Patterns

Nesting `[...]` inside another `[...]` creates inline definitions:

```gram
[outer | [inner | a, b]]
```

```rust
Pattern {
    value: Some(Subject::from_id("outer")),
    elements: vec![
        Pattern {
            value: Some(Subject::from_id("inner")),
            elements: vec![
                Pattern { value: Some(Subject::from_id("a")), elements: vec![] },
                Pattern { value: Some(Subject::from_id("b")), elements: vec![] },
            ]
        }
    ]
}
```

---

## 4. Path Notation (Parentheses + Brackets)

Path notation uses parentheses for nodes and bracketed edge labels for relationships.
Nodes in path notation are always atomic — no elements are defined inline.

### 4.1 Node

```gram
(n)
(n:Person)
(alice:Person {name: "Alice", age: 30})
```

These map identically to their pattern-notation equivalents `[n]`, `[n:Person]`, etc.

### 4.2 Directed Relationship (left-to-right)

```gram
(a)-[r:KNOWS]->(b)
```

Equivalent to `[r:KNOWS | a, b]`. Element order encodes direction: `[source, target]`.

```rust
Pattern {
    value:    Some(Subject { identity: Symbol::from("r"), labels: {"KNOWS"}, properties: {} }),
    elements: vec![a_pattern, b_pattern]
}
```

### 4.3 Directed Relationship (right-to-left)

```gram
(a)<-[r:KNOWS]-(b)
```

Equivalent to `[r:KNOWS | b, a]`. The left arrow reverses element order.

```rust
elements: vec![b_pattern, a_pattern]
```

### 4.4 Undirected and Bidirectional Relationships

```gram
(a)-[r:CONNECTED]-(b)    // undirected
(a)<-[r:LINKED]->(b)     // bidirectional
```

Both fall through to the right-facing case in `Pattern<Subject>`:

```rust
elements: vec![a_pattern, b_pattern]
```

Arrow kind is **not preserved** once lowered to `Pattern<Subject>`. If a consumer needs to
distinguish undirected or bidirectional from directed, it must retain the AST node kind from
the parse phase. Semantic distinction is better expressed through relationship labels and
schema conventions.

### 4.5 Anonymous Relationship

```gram
(a)-[:KNOWS]->(b)
```

```rust
Pattern {
    value:    Some(Subject { identity: Symbol::anonymous(), labels: {"KNOWS"}, properties: {} }),
    elements: vec![a_pattern, b_pattern]
}
```

### 4.6 Multi-Hop Paths

```gram
(alice)-[:KNOWS]->(bob)-[:KNOWS]->(carol)
```

`relationship_pattern` is right-recursive in the grammar — the above parses as
`(alice)-[:KNOWS]->( (bob)-[:KNOWS]->(carol) )`. When lowering to `Pattern<Subject>`, each
relationship becomes an independent two-element pattern. The walk structure is not preserved
in the data model.

⚠️ **Open issue:** The canonical lowering form has not been declared. Two options exist:

**Option A — list of relationships:**
```rust
vec![
    Pattern { /* alice-KNOWS->bob */ elements: vec![alice, bob] },
    Pattern { /* bob-KNOWS->carol */ elements: vec![bob, carol] },
]
```

**Option B — walk pattern (alternating nodes and edges):**
```rust
Pattern {
    value:    None,
    elements: vec![alice, alice_knows_bob, bob, bob_knows_carol, carol]
}
```

---

## 5. Annotations

Annotations wrap a pattern with metadata. The result is a `Pattern<Subject>` with one element
(the wrapped pattern) and a subject carrying the annotation data.

### 5.1 Property Annotation

`@key(value)` attaches a single key/value metadata pair. The key remains a bare symbol.
Multiple property annotations may be chained; each becomes a property on the wrapper subject.

```gram
@timestamp(2024-01-15) (alice:Person)
@source("db") @confidence(0.9) (n:Entity)
```

```rust
Pattern {
    value: Some(Subject {
        identity:   Symbol::anonymous(),
        properties: {"timestamp": Value::String("2024-01-15")},
        labels:     {}
    }),
    elements: vec![ Pattern { /* alice:Person */ } ]
}
```

The annotation value may be any `value` expression (see §9).

### 5.2 Identified Annotation

`@@` gives the annotation wrapper its own identity and/or labels, as syntactic sugar for the
wrapper subject when the wrapped pattern itself must be typed or referenceable.

```gram
@@provenance:Source (alice:Person)
@@ref123:Citation (doc:Document)
```

An identified annotation may be combined with property annotations:

```gram
@@provenance:Source @confidence(0.9) (alice:Person)
```

The `@@` form is intended for schema and ontology definitions where annotation lineage matters.

---

## 6. Records, Maps, and the Property Depth Budget

The property system is intentionally deeper than Cypher but shallower than JSON. Nesting depth
is bounded by type, not convention:

| Depth | Construct | Value constraint |
|---|---|---|
| 0 | scalar | primitives only |
| 1 | `array`, `map` | scalar values only |
| 2 | `record` | any value, including `array` and `map` |
| structural | node, relationship, pattern | promote instead of nesting deeper |

**`record`** — appears in subject position, attached to a node, relationship, or pattern.
Property values may be any `value` including `map` and `array`. Record and map keys may be
bare symbols, backtick-quoted names, or double-quoted names. The key separator may be `:`
or `::`.

```gram
(a:Person {name: "Alice", scores: [10, 20, 30], address: {city: "Portland"}})
```

**`map`** — appears in value position (as a property value inside a record). Keys and values
must both be scalar. Only `:` is permitted as separator.

```gram
{ address: {city: "Portland", zip: "97201"} }
//         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ this is a map
```

**`array`** — an ordered sequence of scalars. Cannot contain `map` values.

```gram
{ tags: ["graph", "data"], counts: [1, 2, 3] }
```

Note: `[]` is not a valid array literal — it parses as an empty `subject_pattern`.
`{ tags: [] }` is therefore a parse error.

---

## 7. Stylistic Variants: Arrow Families and Label Separators

Gram supports three arrow families and two label separators. All variants within each group
are **semantically equivalent** — the choice is purely stylistic, with conventions emerging
through file-type and document-header hints rather than parser enforcement.

### Arrow Families

| Family | Undirected | Right | Left | Bidirectional |
|---|---|---|---|---|
| Dash (default) | `--` | `-->` | `<--` | `<-->` |
| Fat / double | `==` | `==>` | `<==` | `<==>` |
| Tilde | `~~` | `~~>` | `<~~` | `<~~>` |

By convention, `==` and `~~` arrows paired with `::` labels suggest schema or ontology definitions.

### Label Separators

| Separator | Example | Convention |
|---|---|---|
| `:` | `(n:Person)` | data graphs |
| `::` | `(n::Person)` | schema / type assertions |

### Document-Level Hints

The optional leading `record` in a gram document serves as a **document header** — metadata
about the file, not a graph element. The `kind` key is a natural convention:

```gram
{ kind: "schema" }

(Person::Entity)
(name::Property)
(Person)==[:HAS_PROPERTY::]==>(name)
```

File extensions provide an additional convention layer: `*.gram` for data,
`*.schema.gram` for schema definitions. These are orthogonal to the syntax and carry no
parser-enforced meaning.

---

## 8. Semantic Rules

### 8.1 Definitions vs. References

| Context | Behavior |
|---|---|
| `[id]`, `[id:Label]`, `[id \| ...]`, etc. | **Defines** pattern with that identity |
| Bare `id` inside `[v \| ...]` elements | **References** a pattern by identity |
| `(n)` in path notation — first occurrence | **Defines** pattern `n` |
| `(n)` in path notation — subsequent occurrence | **References** existing pattern `n` |

Each identified pattern may only be defined once within a file.

### 8.2 Immutability

Once defined, a pattern's structure, labels, and properties cannot be modified by subsequent
expressions.

### 8.3 Forward References

References to patterns defined later in the file are permitted. Parser implementations must
support deferred resolution.

⚠️ **Open issue:** The precise resolution mechanics (two-pass parsing vs. deferred/lazy binding)
have not been specified. Implementations may differ.

### 8.4 Document Header

A gram document may begin with a bare `record` before any patterns:

```gram
{ kind: "schema", version: "1.0" }

(Person::Entity)
```

This record is a **document header** — metadata about the file, not a graph element.

### 8.5 No Self-Reference

A pattern cannot contain itself as a direct element.

### 8.6 Document-Level Pattern Collection

⚠️ **Open issue:** The canonical `Pattern<Subject>` representation of the collection of
top-level patterns has not been declared. Two options exist:

- **Option A:** A bare `Vec<Pattern>`, with the header record discarded or returned separately.
- **Option B:** A root wrapper `Pattern<Subject>` with an implicit label such as `Gram.Root`,
  wrapping all top-level patterns as elements.

---

## 9. Identifiers and Value Types

### 9.1 Identifiers

An identifier may be a symbol, a backtick-quoted name, or an integer — allowing quoted or
numeric node identities:

```gram
[a]          // symbol identifier
[`node-1`]   // backtick-quoted identifier
[42]         // integer identifier
```

A `symbol` starts with a letter or underscore; subsequent characters may include digits,
`.`, `-`, and `@`: `/[a-zA-Z_][0-9a-zA-Z_.\-@]*/`.

### 9.2 Value Types

Values appear as record property values, map entry values, array elements, and annotation
arguments.

| Gram Syntax | Value Type | Notes |
|---|---|---|
| `42` | `Value::Integer` | |
| `-7` | `Value::Integer` | negative supported |
| `3.14` | `Value::Decimal` | |
| `0xFF` | `Value::Hexadecimal` | |
| `0o77` | `Value::Octal` | |
| `5m`, `10kg` | `Value::Measurement` | unit suffix, no space |
| `1..10` | `Value::Range` | bounded |
| `1...` | `Value::Range` | lower-bounded |
| `...10` | `Value::Range` | upper-bounded |
| `true` / `false` | `Value::Boolean` | |
| `"text"` | `Value::String` | double-quoted |
| `'text'` | `Value::String` | single-quoted |
| `` `text` `` | `Value::String` | backtick-quoted |
| ` ```\ntext\n``` ` | `Value::String` | fenced multiline |
| ``url`https://...` `` | `Value::TaggedString` | tag + backtick string |
| `` ```html\n...\n``` `` | `Value::TaggedString` | tag + fenced string |
| `[1, 2, 3]` | `Value::Array` | scalars only; non-empty |
| `{k: "v"}` | `Value::Map` | scalars only |
| `bareword` | `Value::Symbol` | unquoted symbol in value position |

See [Tagged strings and injections](tagged-strings-and-injections.md) for well-known tags, language injection, and the `::` schema convention.

String escape sequences (single, double, backtick forms): `\\`, `\'`, `\"`,
`` \` ``, `\b`, `\f`, `\n`, `\r`, `\t`.

---

## 10. Summary: Construct → Structure Mapping

| Gram Construct | Elements | Role |
|---|---|---|
| `(n)` or `[n]` | 0 | Atomic / node |
| `@k(v) (n)` | 1 | Annotation wrapper |
| `(a)-[r]->(b)` | 2 | Relationship |
| `[v \| a, b, c]` | N | General / list pattern |
| `[outer \| [inner \| a, b]]` | Recursive | Tree |

---

## 11. Parser Implementations

| Implementation | Parser Library | Notes |
|---|---|---|
| Haskell (`pattern-hs`) | Megaparsec | Reference implementation |
| Rust (`pattern-rs`) | Nom | ~95% test corpus compliance |
| Python / WASM | — | Use Rust parser via FFI |

Round-trip guarantee: `parse(serialize(pattern)) == pattern` (structure preserved;
whitespace and arrow/separator style may differ).

---

## 12. Open Issues

Items still requiring a decision before this document is complete:

1. **Multi-hop path lowering** (§4.6) — list of relationships vs. walk pattern: which is
   canonical when lowering to `Pattern<Subject>`?
2. **Document root representation** (§8.6) — bare `Vec<Pattern>` vs. implicit root wrapper.
3. **Forward reference mechanics** (§8.3) — two-pass, lazy binding, or other strategy?
4. **Empty array** (§6) — `[]` currently parses as an empty `subject_pattern`, making
   `{ tags: [] }` a parse error. Confirm whether this is intentional.
5. **`measurement` regex scope** — the current pattern accepts any alphabetic suffix; unit
   validation is left to consumers. Confirm whether this is intentional.
6. **Label case conventions** — uppercase (`KNOWS`) for relationship labels and titlecase
   (`Person`) for node labels is common but unenforced. Worth documenting as convention.
7. **Error handling** — behaviour on malformed input, duplicate definitions, and
   self-reference is unspecified.

---

## Related Documents

- `gram.ebnf` — authoritative formal grammar (W3C-style EBNF)
- `gram-notation.md` — original introductory reference (superseded by this document)
- `gram-pattern-relationship.md` — detailed mapping with Rust examples
- `gram-semantics.md` — semantic rules (terse)
- `gram-serialization.md` — implementation specification ⚠️ *not yet written*
- `pattern-data-structure.md` — deep dive into `Pattern<V>` ⚠️ *not yet written*
