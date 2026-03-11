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
├── extension.toml          # Extension metadata; points at grammar repo (repository + rev)
├── languages/
│   └── gram/
│       ├── config.toml     # Zed language config (brackets, suffixes, etc.)
│       ├── highlights.scm # → ../../../../queries/ (symlink; edit queries/ in repo root)
│       ├── indents.scm
│       ├── locals.scm
│       └── injections.scm
├── test.gram               # Example file for testing
└── .gitignore              # Ignores grammars/ (populated by Zed from extension.toml)
```

Query files (`.scm`) in `languages/gram/` are symlinks to the canonical `queries/` directory at the repo root. Edit `queries/*.scm` there; do not edit the copies under `editors/zed` directly. Running `scripts/prepare-zed-extension.sh` copies `queries/*.scm` into this directory (e.g. for distribution) and updates extension version/rev.

The `grammars/` directory is created by Zed when it loads the extension (it clones the grammar from the URL in `extension.toml`). It is gitignored. If you see a nested `editors/zed/grammars/gram/...` path, that is the cloned repo inside Zed’s cache; you can ignore or delete `editors/zed/grammars/` locally.

### Keeping the grammar revision in sync

The extension pins the tree-sitter-gram grammar with `repository` and `rev` in `extension.toml`. Zed uses that to fetch and build the parser. To keep it aligned with the latest version:

| Goal | Command | What it does |
|------|---------|---------------|
| **Local testing** | `npm run zed:dev` | Sets `repository = "file://<repo-root>"` and `rev = HEAD`. Zed uses your local clone at the current commit, so you can test grammar/query changes without pushing. |
| **Prepare for publish** | `npm run zed:publish` | Sets `repository` to the public GitHub URL (from `package.json`) and `rev = HEAD`. Run this before committing a release so the published extension points at the correct commit on GitHub. |

After either command, `extension.toml` is updated in place. For local dev you typically don’t commit that change (so the repo keeps a rev that matches the last release). For a release, run `zed:publish`, then commit and push so the extension and the tagged release stay aligned.

**If Zed shows an old version (e.g. 0.1.11) after installing the dev extension:** Zed may be using a cached clone of the grammar (at an old rev) or an older copy of the extension. Try: (1) Uninstall the Gram extension from Zed’s Extensions panel. (2) Delete the grammar cache: remove `editors/zed/grammars/` if it exists (Zed recreates it when needed). (3) Run `npm run zed:dev` again so `extension.toml` has the current version and rev. (4) In Zed, run “Install Dev Extension” and select `editors/zed` again. Restart Zed and recheck the extension version.

## Contributing

Contributions are welcome! Please see the main [repository](https://github.com/gram-data/tree-sitter-gram) for contribution guidelines.

To improve syntax highlighting and editor behavior:

1. Edit the canonical query files under `queries/` at the repo root (e.g. `queries/highlights.scm`).
2. The extension uses those via symlinks in `languages/gram/`; run `scripts/prepare-zed-extension.sh` if you need to copy them for distribution.
3. Test with various Gram files, then submit a pull request.

## License

This extension is part of the tree-sitter-gram project and is licensed under the ISC License. See the main repository's [LICENSE](../../LICENSE) file for details.

## Learn More

- [Gram Data GitHub Organization](https://github.com/gram-data)
- [Gram Notation Documentation](https://gram-data.github.io)
- [Tree-sitter Grammar Repository](https://github.com/gram-data/tree-sitter-gram)
- [Zed Editor](https://zed.dev)
