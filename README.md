# tree-sitter-gram

A [tree-sitter](https://tree-sitter.github.io/tree-sitter/) grammar 
for [gram](https://gram-data.github.io) notation.

Gram is a subject-based notation for structured data.

If this is an object:
```
{
  "name":"Andreas",
  "roles":["author"]
}
```

Implicitly the object is a person. To become a subject, the implicit
information can be explicit.

As a subject:
```
(:Person {
  name: "Andreas",
  roles: ["author"]
})
```

Learn more about `gram` at the [gram-data github org](https://github.com/gram-data) notation.

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