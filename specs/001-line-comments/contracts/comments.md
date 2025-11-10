# Comment Syntax Contract

**Feature**: Line-Based and End-of-Line Comments  
**Date**: 2025-11-10

## Syntax Contract

### Comment Marker

**Syntax**: `//`

**Description**: Two forward slashes (`//`) indicate the start of a comment. Everything after `//` on the same line is treated as comment content and ignored by the parser.

### Line-Based Comments

**Syntax**: `// <comment-text>`

**Description**: When `//` appears at the start of a line (or after only whitespace), the entire line is treated as a comment.

**Examples**:
```
// This is a line-based comment
// Another comment
   // Comment with leading whitespace
```

### End-of-Line Comments

**Syntax**: `<gram-syntax> // <comment-text>`

**Description**: When `//` appears after gram syntax on a line, everything after `//` is treated as a comment, but the gram syntax before `//` is parsed normally.

**Examples**:
```
(hello)-->(world)  // This is an end-of-line comment
[Person {name: "Alice"}]  // Person subject with name
```

### Comment Content

**Allowed**: Any characters except newline

**Special Cases**:
- Comment content can include special characters, brackets, parentheses, etc. - they are treated as plain text
- Multiple `//` markers in a comment are part of the comment content (not nested comments)
- Empty comments (`//` with nothing after) are valid

### Constraints

1. **No In-Line Comments**: Comments cannot appear between tokens that must be adjacent
   - ❌ Invalid: `[ // comment ]` (between `[` and `]`)
   - ✅ Valid: `[Person] // comment` (after complete syntax)

2. **String Literals**: Comment markers inside string literals are part of the string content
   - `"This has // in the string"` - `//` is string content, not a comment

3. **Single Line Only**: Comments extend only to the end of the line (no multi-line comments)

## Parser Behavior Contract

### Parsing Behavior

1. **Comments are Ignored**: Comments do not affect the parsing of gram syntax
2. **AST Equivalence**: Files with comments parse to the same AST as equivalent files without comments
3. **Backward Compatibility**: Existing gram files without comments continue to parse correctly

### Tokenization

1. **String Literals First**: String literals are tokenized before comment detection
2. **Comment Recognition**: `//` is recognized as a comment marker only when not inside a string
3. **Whitespace Handling**: Comments can appear anywhere whitespace is allowed

### AST Representation

1. **Extras Array**: Comments are included in the `extras` array
2. **Optional Nodes**: Comments appear as optional nodes that can be queried for tooling
3. **No Semantic Impact**: Comments do not appear in the main AST structure used for semantic parsing

## Examples

### Valid Comment Usage

```gram
// File header comment
// This gram file defines a simple graph

// Define a person node
(Person {name: "Alice"})  // Person with name attribute

// Define a relationship
(hello)-->(world)  // Simple relationship

// Multiple comments
// Comment 1
// Comment 2
[Person]  // Subject comment
```

### Invalid Comment Usage

```gram
// ❌ In-line comment (invalid)
[ // comment ]  // Cannot have comment between [ and ]

// ❌ Comment marker in string (treated as string content, not comment)
"URL: https://example.com // not a comment"
```

## Testing Contract

### Test Requirements

1. **Positive Cases**: Test valid comment usage in all scenarios
2. **Negative Cases**: Test that invalid comment placement is rejected
3. **Edge Cases**: Test empty comments, special characters, file boundaries
4. **String Preservation**: Test that comment markers in strings are preserved
5. **AST Equivalence**: Test that files with/without comments produce identical ASTs

### Test File

**Location**: `test/corpus/comments.txt`

**Format**: Tree-sitter corpus format with "source ===> tree" sections

