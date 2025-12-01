# tree-sitter-gram

A [tree-sitter](https://tree-sitter.github.io/tree-sitter/) grammar 
for [gram](https://gram-data.github.io) notation.

## About Gram

Gram is a subject-based notation for structured data. It uses **annotated patterns** 
as its canonical form, with familiar graph path-like syntax as convenient syntactic sugar.

### Annotated Patterns

An `annotated_pattern` is the generic pattern notation shaped like `[ subject | elements ]`. 
This bracket notation (`subject_pattern`) explicitly shows structure:
- `subject` - optional identifier, labels, and/or record (before `|`)
- `elements` - comma-separated nested patterns (after `|`)

```gram
// A team pattern with members as elements
[devrel:Team {name: "Developer Relations"} | abk, adam, alex]

// A simple atomic subject
[:Person {name: "Andreas", roles: ["author"]}]
```

### Path-Like Syntax (Syntactic Sugar)

For graph-like data, gram provides syntactic sugar using parentheses for `node_pattern` 
and arrows for `relationship_pattern`. These are equivalent representations of subjects:

| Subject Pattern (Generic) | Node Pattern (Graph Sugar) |
|---------------------------|----------------------------|
| `[]` | `()` |
| `[a]` | `(a)` |
| `[a:Person]` | `(a:Person)` |
| `[a:Person {name: "A"}]` | `(a:Person {name: "A"})` |

Relationship patterns connect nodes with arrows. These can be members of a `subject_pattern`:

```gram
// Using node_pattern and relationship_pattern syntax (graph sugar)
(a:Person)-[:KNOWS]->(b:Person)

// Using subject_pattern to group related path patterns
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