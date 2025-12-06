# tree-sitter-gram

A [tree-sitter](https://tree-sitter.github.io/tree-sitter/) grammar 
for [gram](https://gram-data.github.io) notation.

## About Gram

Gram is a pattern-based notation for structured data.

### Patterns and Subjects

A **pattern** is a generic data structure with a value and nested elements:

```ts
interface Pattern<V> {
  value: V;
  elements: Pattern<V>[];
}
```

Gram patterns are always `Pattern<Subject>` — patterns where values are **subjects**.
A **subject** is content combining an optional identifier, labels, and/or a record of properties.

### Pattern Elements

The `gram_pattern` (top-level structure) consists of a sequence of patterns. Syntactically, `subject_pattern`, `node_pattern`, `relationship_pattern`, and `annotated_pattern` are peers.

They correlate to the underlying data structure based on the number of elements:

- **Node Pattern** `()`: A pattern with **0 elements**.
- **Annotated Pattern** `@a (b)`: A pattern with **1 element**.
- **Relationship Pattern** `(a)-->(b)`: A pattern with **2 elements**.
- **Subject Pattern** `[ s | ... ]`: A pattern with an **arbitrary number of elements**.

#### Path Flattening

A path is a flattened tree of relationships. For example:

```gram
(a)-[r1]->(b)-[r2]->(c) 
// is equivalent to:
[ | [r1 | (a), (b)], [r2 | (b),(c)] ]
```

#### Subject Pattern Notation

The subject pattern notation uses `[ subject | elements ]` to explicitly show pattern structure:

```gram
// A team with members as elements
[devrel:Team {name: "Developer Relations"} | abk, adam, alex]

// A simple atomic pattern (no elements)
[:Person {name: "Andreas", roles: ["author"]}]
```

#### Node Notation (Syntactic Sugar)

Parentheses `( subject )` provide familiar graph node syntax:

```gram
()                           // Empty node
(a)                          // Node with identifier
(a:Person)                   // Node with identifier and label
(a:Person {name: "Alice"})   // Node with identifier, label, and properties
```

#### Relationship Notation (Syntactic Sugar)

Arrows connect nodes to express graph relationships:

```gram
// Path notation for graph relationships
(a:Person)-[:KNOWS]->(b:Person)

// Subject Pattern notation can contain path patterns
[social:Graph | 
  (a:Person {name: "Alice"}),
  (b:Person {name: "Bob"}),
  (a)-[:KNOWS]->(b)
]
```

### Comments

Gram files support comments using `//` syntax:
```gram
// This is a line comment
(hello)-->(world)  // End-of-line comment
```

Learn more about `gram` at the [gram-data github org](https://github.com/gram-data).

## Editor Support

This repository includes editor integrations for syntax highlighting and language support:

- **[Zed Editor](editors/zed/)** - Full syntax highlighting and language support
- More editors coming soon! Contributions welcome.

See [editors/README.md](editors/README.md) for installation instructions and available features.

## Language Bindings

Tree-sitter bindings are available for multiple languages:

- **Node.js**: `npm install @gram-data/tree-sitter-gram`
- **Rust**: Available via `Cargo.toml`
- **Python**: Install via `pip install .`
- **Go**: Import from this repository
- **Swift**: Available via Swift Package Manager
- **C**: Build with included Makefile

## Development

Generate the parser after grammar changes:
```bash
npx tree-sitter generate
npx tree-sitter test
```

Run language binding tests:
```bash
npm test                    # Node.js bindings
cargo test                  # Rust bindings
python -m pytest           # Python bindings
make test                   # C bindings
```

See [DEVELOP.md](DEVELOP.md) for detailed development guidelines.