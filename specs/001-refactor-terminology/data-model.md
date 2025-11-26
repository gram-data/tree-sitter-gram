# Data Model: Refactor Terminology

**Feature**: 001-refactor-terminology  
**Date**: 2025-01-27

## Overview

This feature does not introduce new data entities or modify data structures. It is a terminology refactoring that renames existing grammar rules and field names. The AST structure remains the same - only the names change.

## Terminology Changes

### Grammar Rule Renaming

**Before**: `subject` (grammar rule)  
**After**: `bracket` (grammar rule)

**Impact**: 
- Rule name in `grammar.js`
- Node type name in generated `node-types.json`
- Node type name in generated `parser.c`
- References in other grammar rules (`_pattern_element`, `_sub_pattern_element`)

### Field Name Renaming

**Before**: `attributes` (field within subject rule)  
**After**: `subject` (field within bracket rule)

**Impact**:
- Field name in `grammar.js` field() annotation
- Field name in generated `node-types.json`
- Field name in generated parser code
- References in test corpus expected outputs

## AST Structure (Unchanged)

The actual structure of the AST remains identical - only names change:

```
Before:
(subject
  attributes: (...)
  pattern: (...)
)

After:
(bracket
  subject: (...)
  pattern: (...)
)
```

## Validation Rules

No new validation rules needed. Existing validation remains:
- Bracket syntax: `[content | pattern]`
- Subject content: identifier, labels, record (unchanged)
- Pattern syntax: comma-separated elements (unchanged)

## State Transitions

N/A - No state changes, only terminology changes.

## Relationships

No relationship changes. The hierarchy remains:
- `gram` → `pattern` → `pattern_element` → (`bracket` | `node` | `relationship`)
- `bracket` → `subject` (field) + `pattern` (field)

