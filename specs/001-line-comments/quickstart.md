# Quickstart: Using Comments in Gram Files

**Feature**: Line-Based and End-of-Line Comments  
**Date**: 2025-11-10

## Overview

Gram files now support comments using the `//` syntax. Comments allow you to document your gram files, making them self-documenting and easier to understand.

## Basic Usage

### Line-Based Comments

Add a comment on its own line by starting the line with `//`:

```gram
// This is a line-based comment
// You can use it to document sections of your gram file

(Person {name: "Alice"})
```

### End-of-Line Comments

Add a comment at the end of a line containing gram syntax:

```gram
(Person {name: "Alice"})  // Person with name attribute
(hello)-->(world)  // Simple relationship
```

## Examples

### Documenting a Graph Structure

```gram
// Define person nodes
(Person {name: "Alice"})  // First person
(Person {name: "Bob"})    // Second person

// Define relationships
(Alice)-->(Bob)  // Alice knows Bob
```

### File Header Comments

```gram
// Gram file: social-network.gram
// Description: Defines a simple social network graph
// Author: Developer Name
// Date: 2025-11-10

[Person {name: "Alice"}]
```

### Section Comments

```gram
// ============================================
// Person Subjects
// ============================================

[Person {name: "Alice"}]
[Person {name: "Bob"}]

// ============================================
// Relationships
// ============================================

(Alice)-->(Bob)  // Alice knows Bob
```

## Important Rules

### ✅ What Works

- Comments at the start of lines
- Comments at the end of lines (after gram syntax)
- Comments with special characters: `// This has [brackets] and (parens)`
- Multiple comments in a file
- Empty comments: `//`

### ❌ What Doesn't Work

- In-line comments between tokens: `[ // comment ]` ❌
- Multi-line comments (comments are single-line only)
- Comment markers inside strings are treated as string content, not comments

### String Literals

Comment markers inside string literals are part of the string content:

```gram
// This is a comment
"URL: https://example.com // not a comment"  // The // inside the string is string content
```

## Best Practices

1. **Use line-based comments for section headers**:
   ```gram
   // Person Definitions
   [Person {name: "Alice"}]
   ```

2. **Use end-of-line comments for brief explanations**:
   ```gram
   (Person {name: "Alice"})  // Person node
   ```

3. **Keep comments concise and meaningful**:
   ```gram
   // Good: Clear and helpful
   (Person {name: "Alice"})  // Person with name
   
   // Bad: Obvious or redundant
   (Person {name: "Alice"})  // This is a person
   ```

4. **Use comments to explain complex patterns**:
   ```gram
   // Pattern: Person knows another Person through a relationship
   (Person {name: "Alice"})-->(Person {name: "Bob"})
   ```

## Testing Comments

To verify comments work correctly:

1. Add comments to a gram file
2. Parse the file: `npx tree-sitter parse your-file.gram`
3. Verify the AST structure matches the same file without comments
4. Check that comments don't cause parsing errors

## Next Steps

- See [contracts/comments.md](./contracts/comments.md) for the complete syntax contract
- See [data-model.md](./data-model.md) for technical details
- See [research.md](./research.md) for implementation decisions

