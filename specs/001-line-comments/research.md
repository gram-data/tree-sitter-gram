# Research: Line-Based and End-of-Line Comments

**Feature**: Line-Based and End-of-Line Comments  
**Date**: 2025-11-10  
**Status**: Complete

## Research Questions

1. What comment marker syntax should be used for gram files?
2. How does tree-sitter handle comments in grammar definitions?
3. What are best practices for implementing comments in tree-sitter grammars?
4. How to ensure comments don't interfere with string literals?

## Findings

### Comment Marker Syntax

**Decision**: Use `//` for both line-based and end-of-line comments

**Rationale**:
- `//` is the most widely recognized comment syntax (used in JavaScript, C++, Java, C#, Go, Rust, Swift, and many others)
- Familiar to developers across multiple language ecosystems
- Simple two-character sequence that's unlikely to appear accidentally in gram syntax
- Consistent with modern language conventions
- Easy to type and visually distinct

**Alternatives considered**:
- `#` (Python, shell, YAML style): Rejected because `#` might be used in gram syntax for other purposes in the future, and `//` is more universally recognized
- `--` (SQL, Lua style): Rejected because it's less common and could conflict with relationship arrows (`-->`)
- `/* */` block comments: Not needed for this feature (only line-based and end-of-line required)

### Tree-sitter Comment Implementation

**Decision**: Use tree-sitter's `extras` array with a `comment` rule

**Rationale**:
- Tree-sitter's standard approach for handling comments is to include them in the `extras` array
- Comments in `extras` are automatically ignored during parsing but can still be captured in the AST if needed
- This approach is well-documented and widely used across tree-sitter grammars
- No external scanner needed for simple line comments

**Implementation Pattern**:
```javascript
module.exports = grammar({
  name: "gram",
  
  extras: $ => [
    /\s/,           // Whitespace (already handled)
    $.comment,      // Comments
  ],
  
  rules: {
    // ... existing rules ...
    
    comment: $ => token(seq('//', /.*/)),
  }
});
```

**Key Points**:
- Comments are defined as a rule using `token()` to ensure they're treated as a single token
- The pattern `/.*/` matches everything after `//` until end of line
- Including comments in `extras` means they're automatically skipped during parsing
- Comments can still appear in the AST if needed for syntax highlighting or other tooling

### String Literal Handling

**Decision**: Comments are handled at the lexical level before string parsing, so comment markers inside strings are automatically preserved

**Rationale**:
- Tree-sitter's parsing model handles this correctly by design
- String literals are parsed as complete tokens before comment detection
- The regex pattern `/.*/` in the comment rule only matches after `//` is found outside of string contexts
- No special handling needed - tree-sitter's tokenization ensures strings are parsed first

**Verification**: Tree-sitter grammars (JavaScript, Python, etc.) handle this correctly without special cases. The parser's tokenization phase processes string literals before applying comment rules.

### End-of-Line Comments

**Decision**: The same `//` syntax works for both line-based and end-of-line comments

**Rationale**:
- The regex pattern `/.*/` matches everything after `//` until the end of the line
- If `//` appears after gram syntax on a line, everything after it is treated as a comment
- If `//` appears at the start of a line (or after only whitespace), the entire line is treated as a comment
- No separate rule needed - the same pattern handles both cases

**Example**:
```
(hello)-->(world)  // This is an end-of-line comment
// This is a line-based comment
```

### In-Line Comments (Not Supported)

**Decision**: In-line comments are explicitly not supported per requirements

**Rationale**:
- Requirements specify "not in-line" comments
- In-line comments would require more complex parsing logic
- In-line comments can break gram syntax where tokens must be adjacent
- Line-based and end-of-line comments provide sufficient documentation capability

**What this means**:
- Comments cannot appear between tokens that must be adjacent (e.g., `[` and `]`, `(` and `)`)
- Comments can only appear at the start of a line or after gram syntax on a line
- This is enforced by the comment rule only matching `//` followed by content until end of line

## Testing Strategy

**Decision**: Create comprehensive corpus tests covering all comment scenarios

**Test Cases Needed**:
1. Line-based comments (standalone lines)
2. End-of-line comments (after gram syntax)
3. Multiple comments in a file
4. Comments at file start and end
5. Comment markers inside string literals (should be preserved)
6. Comments with special characters
7. Empty comments (`//` with nothing after)
8. Comments between pattern elements (should work if after comma/whitespace)

**Test File**: `test/corpus/comments.txt`

## Performance Considerations

**Decision**: No performance concerns identified

**Rationale**:
- Comments in `extras` are handled efficiently by tree-sitter
- No additional parsing overhead beyond token recognition
- Comments are skipped during parsing, not processed
- Existing tree-sitter grammars with comments show no performance degradation

## Backward Compatibility

**Decision**: 100% backward compatible - existing gram files without comments will parse identically

**Rationale**:
- Adding comments to `extras` doesn't change existing parsing behavior
- Files without comments are unaffected
- The comment rule only matches when `//` is present
- No breaking changes to existing grammar rules

## References

- Tree-sitter documentation: https://tree-sitter.github.io/tree-sitter/creating-parsers/3-writing-the-grammar.html
- Tree-sitter JavaScript grammar (reference implementation): Uses `//` and `/* */` comments in extras
- Tree-sitter Python grammar: Uses `#` for comments in extras
- Tree-sitter Rust grammar: Uses `//` and `/* */` comments in extras

