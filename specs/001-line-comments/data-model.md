# Data Model: Line-Based and End-of-Line Comments

**Feature**: Line-Based and End-of-Line Comments  
**Date**: 2025-11-10

## Overview

This feature adds comment support to the gram parser. Comments are handled at the lexical level and included in the `extras` array, meaning they are ignored during parsing but can still appear in the AST for tooling purposes (e.g., syntax highlighting).

## Entities

### Comment

**Type**: Lexical token (not a grammar rule node)

**Description**: Represents a comment in a gram file. Comments can be line-based (entire line) or end-of-line (portion after `//`).

**Properties**:
- **text**: The full comment text including the `//` marker and all content until end of line
- **position**: Start and end positions in the source file (for syntax highlighting)

**Behavior**:
- Comments are included in the `extras` array, so they are automatically ignored during parsing
- Comments do not affect the AST structure of gram syntax
- Comments can appear anywhere whitespace is allowed
- Comments are captured as tokens for editor tooling (syntax highlighting, etc.)

**Constraints**:
- Must start with `//`
- Extends to end of line (no multi-line comments)
- Cannot appear inside string literals (comment markers in strings are part of string content)
- Cannot appear between tokens that must be adjacent (enforced by grammar structure)

### Gram Syntax (Existing)

**No changes required** to existing gram syntax entities:
- `subject`: No changes
- `node`: No changes
- `relationship`: No changes
- `pattern`: No changes
- `record`: No changes
- All other existing entities: No changes

**Rationale**: Comments are handled at the lexical level and do not interact with gram syntax rules. The parser treats comments as whitespace-equivalent for parsing purposes.

## AST Structure

### Comment in AST

Comments appear in the AST as optional nodes that can be queried but are ignored during semantic parsing:

```
gram
├── comment (optional, in extras)
├── pattern
│   ├── comment (optional, in extras)
│   └── elements
│       └── subject
│           └── comment (optional, in extras)
```

**Note**: Comments are not explicitly represented as nodes in the main AST structure. They are part of the `extras` and can be queried separately if needed for tooling.

### AST Equivalence

**Requirement**: Gram files with comments must parse to identical AST structures as equivalent files without comments.

**Implementation**: 
- Comments are in `extras`, so they don't affect the main AST structure
- Removing all comments from a file produces the same AST as a file without comments
- This is automatically handled by tree-sitter's `extras` mechanism

## Validation Rules

### Comment Syntax Validation

1. **Comment Marker**: Must be exactly `//` (two forward slashes)
2. **Comment Content**: Can contain any characters except newline
3. **Comment Position**: 
   - Can appear at start of line (line-based comment)
   - Can appear after gram syntax on a line (end-of-line comment)
   - Cannot appear between adjacent tokens (e.g., `[` and `]`)

### String Literal Preservation

1. **Comment markers in strings**: Must be preserved as string content
2. **Implementation**: Handled automatically by tree-sitter's tokenization (strings are parsed before comments)

## State Transitions

N/A - Comments are lexical tokens, not stateful entities.

## Relationships

### Comment to Gram Syntax

- **Relationship**: Comments are adjacent to but independent of gram syntax
- **Interaction**: Comments do not affect parsing of gram syntax
- **Position**: Comments can appear where whitespace is allowed

### Comment to String Literals

- **Relationship**: Mutually exclusive - comment markers inside strings are string content, not comments
- **Implementation**: Tree-sitter's tokenization ensures strings are parsed before comment detection

## Edge Cases

### Empty Comments

**Case**: `//` with nothing after (just `//` on a line)

**Handling**: Valid comment - matches the pattern `//` followed by `.*` (which can be empty)

### Comments with Special Characters

**Case**: Comments containing special gram syntax characters (e.g., `// This has [brackets] and (parens)`)

**Handling**: Valid - comment content is treated as plain text, not parsed as gram syntax

### Multiple Comments

**Case**: Multiple `//` markers on the same line

**Handling**: First `//` starts the comment, everything after (including subsequent `//`) is comment content

### Comments Between Pattern Elements

**Case**: Comments appearing between comma-separated pattern elements

**Handling**: Valid if the comment appears after whitespace/comma and before the next element (same as end-of-line comment behavior)

### Comments at File Boundaries

**Case**: Comments at the very start or end of a file

**Handling**: Valid - comments can appear anywhere, including file boundaries

## Implementation Notes

- Comments are defined as a grammar rule but included in `extras`
- The `token()` wrapper ensures comments are treated as single tokens
- The regex pattern `/.*/` matches everything after `//` until end of line
- No special handling needed for string literals - tree-sitter handles this correctly

