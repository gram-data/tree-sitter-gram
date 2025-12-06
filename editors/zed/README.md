# Gram Language Support for Zed

A [Zed](https://zed.dev) extension providing syntax highlighting and language support for [Gram notation](https://gram-data.github.io) - a subject-oriented notation for structured data.

## Features

- **Syntax Highlighting**: Full syntax highlighting for all Gram constructs including subjects, nodes, relationships, and data types
- **Subject Pattern Matching**: Automatic matching for `()`, `[]`, and `{}`
- **File Type Detection**: Automatic recognition of `.gram` files
- **Smart Indentation**: Proper indentation handling for nested structures

## Installation

### From Zed Extensions (Coming Soon)

Once published, you'll be able to install directly from Zed:

1. Open Zed
2. Press `Cmd+Shift+P` (macOS) or `Ctrl+Shift+P` (Linux/Windows)
3. Type "extensions" and select "zed: extensions"
4. Search for "gram" and install

### Manual Installation

For now, install manually by copying the extension:

```bash
# Clone the repository if you haven't already
git clone https://github.com/gram-data/tree-sitter-gram.git

# Copy or symlink the extension to your Zed extensions directory
# On macOS/Linux:
ln -s $(pwd)/tree-sitter-gram/editors/zed ~/.config/zed/extensions/gram

# On Windows:
mklink /D "%APPDATA%\Zed\extensions\gram" "path\to\tree-sitter-gram\editors\zed"
```

Then restart Zed.

## Usage

Once installed, the extension automatically provides syntax highlighting for any file with a `.gram` extension.

### Example Gram Syntax

```gram
// Simple subject with properties
(:Person {
  name: "Andreas",
  age: 35,
  roles: ["author", "developer"]
})

// Relationships between nodes
(alice:Person {name: "Alice"})-->(bob:Person {name: "Bob"})

// Complex subject with annotations
@type("Employee")
[:Person {
  id: 12345,
  name: "John Doe",
  department: "Engineering",
  salary: 75000.50,
  active: true,
  skills: ["JavaScript", "Rust", "Python"]
}]

// Measurements and special values
(:Measurement {
  distance: 100km,
  weight: 5.5kg,
  temperature: -10.5celsius,
  count: 0x1A,
  nullable: null
})
```

## Syntax Highlighting

The extension provides highlighting for:

- **Subject Patterns**: `[...]` and `[:type ...]` subject pattern notation (containing subjects)
- **Nodes**: `(...)` parentheses
- **Relationships**: `->`, `--`, `<-`, `<-->`, etc.
- **Strings**: Single, double, and backtick quoted strings
- **Numbers**: Integers, decimals, hex, octal, and measurements
- **Booleans**: `true` and `false`
- **Null**: `null` literal
- **Comments**: `//` and `/* */`
- **Operators**: `:`, `::`, `@`
- **Properties**: Object keys and annotation keys
- **Errors**: Invalid syntax

## Development

To work on this extension:

1. Clone the main repository:
   ```bash
   git clone https://github.com/gram-data/tree-sitter-gram.git
   cd tree-sitter-gram
   ```

2. Install as a dev extension in Zed:
   - Open Zed command palette (`Cmd+Shift+P` / `Ctrl+Shift+P`)
   - Run "zed: install dev extension"
   - Select the `editors/zed` directory
   - Restart Zed

3. Make changes to the extension files
4. Restart Zed to see changes

### Extension Structure

```
editors/zed/
├── extension.toml           # Extension metadata
├── grammars/
│   └── tree-sitter-gram/   # Grammar files
│       ├── grammar.js      # Tree-sitter grammar definition
│       └── src/            # Generated parser source
├── languages/
│   └── gram/
│       ├── config.toml     # Language configuration
│       └── queries/        # Syntax highlighting queries
│           └── highlights.scm
└── example.gram            # Example file for testing
```

## Contributing

Contributions are welcome! Please see the main [repository](https://github.com/gram-data/tree-sitter-gram) for contribution guidelines.

To improve syntax highlighting:
1. Edit `languages/gram/queries/highlights.scm`
2. Test with various Gram files
3. Submit a pull request

## License

This extension is part of the tree-sitter-gram project and is licensed under the ISC License. See the main repository's [LICENSE](../../LICENSE) file for details.

## Learn More

- [Gram Data GitHub Organization](https://github.com/gram-data)
- [Gram Notation Documentation](https://gram-data.github.io)
- [Tree-sitter Grammar Repository](https://github.com/gram-data/tree-sitter-gram)
- [Zed Editor](https://zed.dev)
