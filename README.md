# tree-sitter-gram

A [tree-sitter](https://tree-sitter.github.io/tree-sitter/) grammar 
for [gram](https://gram-data.github.io) notation.

## About Gram

Gram is a subject-based notation for structured data.

### Patterns and Subjects

A **pattern** is a generic data structure with a value and nested elements:

```ts
interface Pattern<V> {
  value: V;
  elements: Pattern<V>[];
}
```

A **subject pattern** is `Pattern<Subject>` — a pattern where values are subjects.
A subject combines an optional identifier, labels, and/or a record of properties.

### Syntactic Forms

Gram provides two syntactic forms for writing subject patterns:

#### Bracket Notation (`subject_pattern`)

The bracket notation `[ subject | elements ]` explicitly shows the pattern structure:
- `subject` - optional identifier, labels, and/or properties (before `|`)
- `elements` - comma-separated nested patterns (after `|`)

```gram
// A team pattern with members as elements
[devrel:Team {name: "Developer Relations"} | abk, adam, alex]

// A simple atomic subject (no elements)
[:Person {name: "Andreas", roles: ["author"]}]
```

#### Path Notation (`node_pattern` and `relationship_pattern`)

For graph-like data, gram provides familiar path syntax as syntactic sugar:

| Bracket Notation | Path Notation |
|------------------|---------------|
| `[]` | `()` |
| `[a]` | `(a)` |
| `[a:Person]` | `(a:Person)` |
| `[a:Person {name: "A"}]` | `(a:Person {name: "A"})` |

Relationship patterns connect nodes with arrows:

```gram
// Path notation for graph relationships
(a:Person)-[:KNOWS]->(b:Person)

// Bracket notation can group related path patterns
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