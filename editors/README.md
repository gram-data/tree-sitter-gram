# Editor Integrations

This directory contains editor integrations for the Gram tree-sitter grammar.

## Available Integrations

### Zed Editor

The Zed integration provides full syntax highlighting and language support for Gram notation files.

**Installation:**

1. Copy or symlink the extension to your Zed extensions directory:
   ```bash
   # On macOS/Linux:
   ln -s $(pwd)/editors/zed ~/.config/zed/extensions/gram

   # On Windows:
   mklink /D "%APPDATA%\Zed\extensions\gram" "path\to\tree-sitter-gram\editors\zed"
   ```

2. Restart Zed

3. Open any `.gram` file to see syntax highlighting in action

**Features:**
- Syntax highlighting for all Gram constructs
- Bracket matching for `()`, `[]`, and `{}`
- Automatic file type detection for `.gram` files
- Proper indentation handling

**Development:**
If you're developing the extension, use Zed's "install dev extension" command:
1. Open Zed command palette (`Cmd+Shift+P` / `Ctrl+Shift+P`)
2. Run "zed: install dev extension"
3. Select the `editors/zed` directory
4. Restart Zed

## Contributing New Integrations

We welcome contributions for other editors! When adding a new editor integration:

1. Create a subdirectory under `editors/` named after the editor
2. Include all necessary configuration files
3. Add installation and usage instructions to this README
4. Test thoroughly with the examples in `examples/`

Popular editors we'd love to see integrations for:
- VS Code
- Vim/Neovim
- Emacs
- Sublime Text
- IntelliJ IDEA
- Atom (if still relevant)

## Grammar Reference

All editor integrations should support these Gram language features:

- **Subjects**: `[attributes]` and `[:type attributes]`
- **Nodes**: `(attributes)`
- **Relationships**: `->`, `--`, `<-`, `<--`, `<->`, `<-->`
- **Data types**: strings, numbers, booleans, null, arrays, objects
- **Annotations**: `@key(value)`
- **Comments**: `//` line comments and `/* */` block comments
- **Special literals**: measurements (`100km`), hex (`0xFF`), octal (`0755`)

See the main [README.md](../README.md) and [examples/](../examples/) for complete syntax documentation.
