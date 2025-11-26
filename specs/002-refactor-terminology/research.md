# Research: Refactor Terminology

**Feature**: 001-refactor-terminology  
**Date**: 2025-01-27  
**Status**: Complete

## Research Summary

This terminology refactoring is a straightforward find-and-replace operation with no technical unknowns. All decisions are clear from the specification.

## Decisions

### Decision 1: Terminology Mapping

**Decision**: Rename `subject` → `bracket` (grammar rule) and `attributes` → `subject` (field name)

**Rationale**: 
- `bracket` accurately describes the `[...]` syntax notation (the container)
- `subject` logically refers to the content/data within brackets (the primary data)
- This aligns terminology with semantic meaning

**Alternatives considered**:
- Keeping current terminology - **Rejected**: Current naming is confusing (subject = container, attributes = content)
- Other names for bracket (e.g., `container`, `pattern_bracket`) - **Rejected**: `bracket` is most descriptive and concise
- Other names for subject (e.g., `content`, `data`) - **Rejected**: `subject` aligns with Gram notation philosophy where subjects are the primary data entities

### Decision 2: Scope of Changes

**Decision**: Update all files that reference the old terminology: grammar, generated code, tests, docs, examples, editor integrations

**Rationale**: Consistency is critical - mixed terminology would be more confusing than the current state

**Alternatives considered**:
- Only update grammar and let generated code update automatically - **Rejected**: Tests, docs, and examples would be inconsistent
- Gradual migration - **Rejected**: All-or-nothing approach ensures consistency

### Decision 3: Backward Compatibility

**Decision**: Maintain syntax-level backward compatibility (no changes to gram file syntax)

**Rationale**: Users' existing gram files must continue to work without modification

**Alternatives considered**:
- Breaking change requiring user migration - **Rejected**: Unnecessary burden on users for internal terminology change

### Decision 4: Test File Renaming

**Decision**: Rename test files like `subjects.txt` to `brackets.txt` to reflect new terminology

**Rationale**: File names should match the terminology they test

**Alternatives considered**:
- Keep old file names - **Rejected**: Would create confusion about what the file tests

## Technical Notes

- Tree-sitter automatically regenerates parser code from grammar.js
- Node type names in generated code come directly from grammar rule names
- Field names in generated code come directly from field() annotations
- Test corpus files must match generated node type and field names exactly
- Syntax highlighting queries reference node type names and must be updated

## No Clarifications Needed

All aspects of this refactoring are clear from the specification. No research questions or clarifications required.

