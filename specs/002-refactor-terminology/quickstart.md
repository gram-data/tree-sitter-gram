# Quickstart: Refactor Terminology

**Feature**: 001-refactor-terminology  
**Date**: 2025-01-27

## Overview

This quickstart guides you through the terminology refactoring process: renaming `subject` → `bracket` and `attributes` → `subject` across the codebase.

## Prerequisites

- Tree-sitter CLI installed (`npm install -g tree-sitter-cli`)
- Node.js and npm available
- Git repository checked out on branch `001-refactor-terminology`

## Step-by-Step Process

### 1. Update Grammar Rules

**File**: `grammar.js`

1. Rename rule `subject` to `bracket`:
   ```javascript
   // Before:
   subject: ($) => seq(...)
   
   // After:
   bracket: ($) => seq(...)
   ```

2. Rename field `attributes` to `subject`:
   ```javascript
   // Before:
   field("attributes", optional($._attributes))
   
   // After:
   field("subject", optional($._subject))
   ```

3. Update all references to `subject` rule:
   - In `_pattern_element`: `choice($.bracket, $._path)`
   - In `_sub_pattern_element`: `choice($.bracket, $._path, $.reference)`

### 2. Regenerate Parser Code

```bash
npx tree-sitter generate
```

This automatically updates:
- `src/parser.c`
- `src/grammar.json`
- `src/node-types.json`

### 3. Update Test Corpus Files

**Files**: `test/corpus/*.txt`

1. Update expected AST outputs:
   - Change `(subject` → `(bracket`
   - Change `attributes:` → `subject:`

2. Rename test files:
   - `subjects.txt` → `brackets.txt`

3. Verify tests pass:
   ```bash
   npx tree-sitter test
   ```

### 4. Update Documentation

**Files**: `README.md`, `WARP.md`, `AGENTS.md`, `editors/zed/README.md`

Search and replace:
- "subject" (when referring to bracket notation) → "bracket"
- "attributes" (when referring to content) → "subject"

### 5. Update Query Files

**Files**: `queries/highlights.scm`, `editors/zed/languages/gram/highlights.scm`

Update node type references:
- `(subject)` → `(bracket)`
- Field references: `attributes:` → `subject:`

### 6. Update Examples (if needed)

**Files**: `examples/*/`

Review examples for node type or field name references:
- Update code comments
- Update any hardcoded node type checks

### 7. Verify Everything Works

```bash
# Run all tests
npx tree-sitter test
npm test
cargo test

# Check syntax highlighting (if editor available)
# Open a .gram file and verify highlighting works
```

## Verification Checklist

- [ ] Grammar rules renamed in `grammar.js`
- [ ] Parser regenerated (`npx tree-sitter generate`)
- [ ] All corpus tests pass (`npx tree-sitter test`)
- [ ] Test file `subjects.txt` renamed to `brackets.txt`
- [ ] Documentation files updated
- [ ] Query files updated
- [ ] Examples reviewed and updated
- [ ] All language binding tests pass
- [ ] Syntax highlighting works in editors

## Common Issues

**Issue**: Tests fail after renaming  
**Solution**: Ensure all expected outputs in corpus files use new node type and field names

**Issue**: Syntax highlighting broken  
**Solution**: Verify query files reference `bracket` node type, not `subject`

**Issue**: Generated code still has old names  
**Solution**: Run `npx tree-sitter generate` again after grammar changes

## Success Criteria

- All tests pass
- No references to old terminology remain (verified by search)
- Generated code uses new terminology
- Documentation is consistent

