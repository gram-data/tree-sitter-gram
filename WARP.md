# WARP.md

This file provides guidance to WARP (warp.dev) when working with code in this repository.

## Project Overview

This is a Tree-sitter parser for the Gram notation language. Gram is a subject-based notation for structured data that extends JSON-like structures with subjects, relationships, and graph patterns.

Key concepts:
- **Subjects**: Explicitly typed objects using `[subject | patterns]` syntax (bracket notation)
- **Nodes**: Graph nodes using `(subject)` syntax  
- **Relationships**: Directional connections between nodes using arrows (`-->`, `<--`, `==`, etc.)
- **Patterns**: Comma-separated sequences of brackets (subjects), nodes, and relationships

## Architecture

### Core Grammar Structure (`grammar.js`)
The grammar is organized hierarchically:
- `gram` → `pattern` → `pattern_element` → (`bracket` | `node` | `relationship`)
- Brackets contain `subject` (identifiers, labels (`:Label`), and records (`{key: value}`))
- Multiple relationship types with different arrow styles (single `-`, double `=`, squiggle `~`)

### Multi-Language Support
This parser provides bindings for multiple languages:
- **C**: `bindings/c/` (core implementation)
- **JavaScript/Node.js**: `bindings/node/` 
- **Python**: Python packaging via `pyproject.toml`
- **Go**: `bindings/go/` with Go modules
- **Rust**: `bindings/rust/` with Cargo integration
- **Swift**: Swift package support

### Test Structure
- `test/corpus/`: Tree-sitter corpus tests organized by language feature
- Each `.txt` file contains test cases with input and expected AST output
- Tests cover: nodes, relationships, patterns, annotations, values, etc.

## Common Development Commands

### Parser Development
```bash
# Generate parser from grammar
npx tree-sitter generate

# Run all tests
npx tree-sitter test

# Run specific tests (filter by name)
npx tree-sitter test -f 'Node'

# Launch interactive playground
npm start
```

### Language Bindings

#### Node.js
```bash
# Install locally
npm install

# Run Node.js binding tests
npm test
```

#### Python
```bash
# Install locally for development
python -m pip install .

# Build wheels (requires build tools)
python -m build
```

#### Go
```bash
# Run Go tests
go test ./bindings/go/

# Install Go module
go mod download
```

#### Rust
```bash
# Build Rust binding
cargo build

# Run Rust tests
cargo test
```

#### C/Make
```bash
# Build static and shared libraries
make all

# Run tests via Make
make test

# Install system-wide
make install

# Clean build artifacts
make clean
```

## Version Management

All package files must be kept in sync when releasing:
- `package.json`: version field
- `pyproject.toml`: project.version
- `Cargo.toml`: package.version (currently behind at 0.0.1)
- `tree-sitter.json`: metadata.version
- `Makefile`: VERSION variable

Release process:
1. Update version across all files
2. Commit changes
3. Tag with `git tag -a <version> -m "<description>"`  
4. Push with `git push --follow-tags`

## Grammar Development Patterns

When modifying `grammar.js`:
- Use `field()` for important AST node components
- Leverage `choice()` and `optional()` for variants
- Create helper functions like `commaSep1()` for repeated patterns
- Test relationship precedence with `prec.right()`
- Consider Unicode support (math symbols, Greek letters, pictographs)

String literals support multiple styles:
- Single/double quoted with escape sequences
- Backticked strings
- Tagged strings (`tag`content``)
- Fenced strings (```content```)

## Testing Guidelines

Each corpus test file should:
- Use `==================` separators between tests
- Include descriptive test names
- Provide input Gram notation
- Show expected AST structure with proper indentation
- Cover both positive cases and edge cases

When adding new grammar features:
1. Add rules to `grammar.js`
2. Run `npx tree-sitter generate` 
3. Create corresponding tests in `test/corpus/`
4. Verify with `npx tree-sitter test`
5. Update language bindings as needed