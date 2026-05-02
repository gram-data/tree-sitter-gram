---
name: gram
description: >
  Work with gram notation files (.gram). Use this skill when the user is
  creating, reading, editing, or validating gram notation — a text format
  for Pattern<Subject> structures. Gram encodes nodes, annotations,
  relationships, and general list/tree patterns in two interchangeable
  syntactic styles: square-bracket pattern notation and parenthesis path
  notation. Trigger on .gram files, graph data tasks, or any task
  involving Pattern<Subject> serialization.
license: MIT
compatibility: >
  Requires the gram CLI. Install with: cargo install gram-data
  Verify with: gram --version
metadata:
  author: gram-data
  homepage: https://github.com/gram-data/tree-sitter-gram
---

# Gram Notation

Gram is a text format for serializing and deserializing `Pattern<Subject>` structures. Files use the `.gram` extension.

## Core Data Model: `Pattern<Subject>`

Every gram construct lowers to a `Pattern<Subject>`:

```
Pattern<Subject> {
    value:    Option<Subject>,   // identity, labels, properties
    elements: Vec<Pattern>       // zero or more child patterns
}
```

The number of `elements` determines the structural role:

| Elements | Role |
|----------|------|
| 0 | Node / atomic pattern |
| 1 | Annotation wrapper |
| 2 | Relationship |
| N ≥ 3 | General / list pattern |

A graph (nodes + relationships) is one special case; gram can also represent annotations, trees, and arbitrary list structures.

## Syntactic Styles

Both styles produce identical `Pattern<Subject>` structures and are fully interchangeable.

### Pattern Notation (Square Brackets)

```gram
[]                          // empty pattern (node)
[a]                         // identified node
[a:Person]                  // labeled node
[a:Person {name: "Alice"}]  // node with properties
[r:KNOWS | a, b]            // relationship (2 elements)
[list | a, b, c]            // general pattern (3+ elements)
[outer | [inner | a, b]]    // nested / tree
```

The `|` separator divides the subject from its elements. Bare identifiers inside `[v | ...]` are **references** to previously (or forward-) defined patterns.

### Path Notation (Parentheses + Brackets)

Path notation uses `(...)` for nodes and `[...]` for relationship labels — familiar to Cypher users.

```gram
(n)                             // node
(alice:Person {name: "Alice"})  // labeled node with properties
(a)-[r:KNOWS]->(b)              // directed relationship → [r:KNOWS | a, b]
(a)<-[r:KNOWS]-(b)              // reversed  → [r:KNOWS | b, a]
(a)-[:KNOWS]->(b)               // anonymous relationship
(a)-[:KNOWS]->(b)-[:KNOWS]->(c) // multi-hop path
```

Arrow families are stylistic variants — all semantically equivalent:

| Family | Example |
|--------|---------|
| Dash (default) | `(a)-->(b)` |
| Fat | `(a)==>(b)` |
| Tilde | `(a)~~>(b)` |

## Annotations

An annotation wraps a pattern with metadata (1-element pattern):

```gram
@timestamp(2024-01-15) (alice:Person)
@source("db") @confidence(0.9) (n:Entity)
@@provenance:Source (alice:Person)   // identified annotation with label
```

## Properties

```gram
(a:Person {name: "Alice", age: 30})
(a {scores: [10, 20, 30], address: {city: "Portland"}})
```

Property values: strings (`"text"`, `'text'`, `` `text` ``), integers, decimals, booleans, arrays (scalars only), maps (scalars only), measurements (`5m`, `10kg`), ranges (`1..10`), tagged strings (`` url`https://...` ``).

## Schema / Ontology Style

Double-colon `::` labels and `==` / `~~` arrows conventionally signal schema definitions:

```gram
{ kind: "schema" }

(Person::Entity)
(name::Property)
(Person)==[:HAS_PROPERTY::]==>(name)
```

## Validation with `gram check`

```sh
gram check path/to/file.gram          # validate a file
gram check path/to/dir/               # validate all .gram files in a directory
gram check -e '(a)-[:KNOWS]->(b)'     # validate an inline expression
cat file.gram | gram check            # read from stdin
gram check --json file.gram           # machine-readable JSON output
gram check --strict file.gram         # warnings treated as errors
```

Exit codes: `0` = no errors, `1` = errors found, `2` = tool/IO error.

## Quick Examples

**Graph (nodes + relationships)**:
```gram
(alice:Person {name: "Alice"})
(bob:Person {name: "Bob"})
(alice)-[:KNOWS {since: 2020}]->(bob)
```

**Annotated data**:
```gram
@timestamp(2024-01-15) @source("api") (event:Event {type: "login"})
```

**Schema definition**:
```gram
{ kind: "schema" }
(User::Entity)
(email::Property)
(User)==[:HAS::]==>(email)
```

**General list pattern**:
```gram
[playlist:Playlist | [s1:Song {title: "A"}], [s2:Song {title: "B"}], [s3:Song {title: "C"}]]
```

## Working with Gram Files

- Always validate with `gram check` before using files downstream
- `.gram` files are UTF-8 text; whitespace and line endings are not significant
- Each identifier may be defined only once per file; forward references are allowed
- Pattern notation `[...]` and path notation `(...)` can be mixed in the same file
- Use `gram check --json` when integrating into build pipelines or CI
