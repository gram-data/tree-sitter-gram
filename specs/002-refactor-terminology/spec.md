# Feature Specification: Refactor Terminology

**Feature Branch**: `001-refactor-terminology`  
**Created**: 2025-01-27  
**Status**: Draft  
**Input**: User description: "Revise terminology for some syntactic element: \"subject\" should be renamed to \"bracket\" to clarify that it is the generic notation for patterns; \"attributes\" should then be renamed to \"subject\" because subjects are the content or primary data for a pattern."

## User Scenarios & Testing *(mandatory)*

### User Story 1 - Grammar Rules Updated (Priority: P1)

Developers and users of the grammar need consistent terminology that accurately reflects the semantic meaning of syntax elements. The current term "subject" refers to the bracket notation `[...]` which is the generic container for patterns, while "attributes" refers to the actual content/data within those brackets. This terminology is confusing because "subject" should logically refer to the content (data), not the container.

**Why this priority**: This is foundational terminology that affects all documentation, examples, and user understanding. Getting the terminology right is critical for clarity and adoption.

**Independent Test**: Can be tested by verifying that all grammar rules, generated parser code, and test files use the new terminology consistently. The grammar should parse the same syntax but with renamed rules and fields.

**Acceptance Scenarios**:

1. **Given** the grammar file `grammar.js`, **When** the terminology is refactored, **Then** the rule `subject` is renamed to `bracket` and the field `attributes` is renamed to `subject`
2. **Given** the parser is regenerated, **When** parsing gram files, **Then** the AST uses `bracket` as the node type and `subject` as the field name for content
3. **Given** existing test corpus files, **When** they are updated with new terminology, **Then** all tests pass with the new node type and field names

---

### User Story 2 - Documentation and Examples Updated (Priority: P2)

Users reading documentation and examples need to see consistent terminology that matches the grammar implementation. All references to "subject" (meaning the bracket notation) and "attributes" (meaning the content) must be updated throughout documentation.

**Why this priority**: Documentation is the primary way users learn the grammar. Inconsistent terminology between code and docs creates confusion.

**Independent Test**: Can be tested by searching all documentation files for old terminology and verifying they use the new terms. All examples should demonstrate the new terminology.

**Acceptance Scenarios**:

1. **Given** README.md and other documentation files, **When** terminology is updated, **Then** all references to "subject" (bracket notation) are changed to "bracket" and "attributes" (content) are changed to "subject"
2. **Given** example gram files, **When** they are reviewed, **Then** any comments or documentation within examples use the new terminology
3. **Given** editor integration documentation (Zed, etc.), **When** terminology is updated, **Then** syntax highlighting and language server documentation reflects new terms

---

### User Story 3 - Test Files and Corpus Updated (Priority: P2)

Test corpus files contain expected AST outputs that reference node types and field names. These must be updated to match the new terminology so tests continue to validate correct parsing.

**Why this priority**: Tests ensure the grammar works correctly. If tests aren't updated, they will fail and block development.

**Independent Test**: Can be tested by running the test suite after terminology changes and verifying all corpus tests pass with updated expected outputs.

**Acceptance Scenarios**:

1. **Given** test corpus files in `test/corpus/`, **When** terminology is updated, **Then** all expected AST outputs use `bracket` node type and `subject` field name
2. **Given** the test suite, **When** `npx tree-sitter test` is run, **Then** all tests pass with the new terminology
3. **Given** test file names like `subjects.txt`, **When** terminology is updated, **Then** file names are renamed to reflect new terminology (e.g., `brackets.txt`)

---

### User Story 4 - Generated Code and Bindings Updated (Priority: P3)

Generated parser code and language bindings may expose node type names and field names in their APIs. These should be updated to use the new terminology for consistency.

**Why this priority**: While generated code updates automatically, any API documentation or examples using bindings should reflect the new terminology. This is lower priority because generated code updates automatically when grammar changes.

**Independent Test**: Can be tested by regenerating parser code and verifying node-types.json and generated C/Rust/Python/etc. bindings use new terminology. Any binding examples should be updated.

**Acceptance Scenarios**:

1. **Given** the grammar is updated, **When** `npx tree-sitter generate` is run, **Then** `src/node-types.json` uses `bracket` as node type and `subject` as field name
2. **Given** language binding examples, **When** terminology is updated, **Then** any code examples using node types or fields use the new terminology
3. **Given** syntax highlighting queries, **When** terminology is updated, **Then** query files reference the new node type names

---

### Edge Cases

- What happens to existing gram files that users have written? (They continue to work - only internal terminology changes, not syntax)
- How are breaking changes handled in published packages? (Version bump required for any API changes in bindings)
- What if some files are missed in the refactoring? (Comprehensive search and replace with verification)
- How do we ensure consistency across all language bindings? (Generated code updates automatically, manual review for examples/docs)

## Requirements *(mandatory)*

### Functional Requirements

- **FR-001**: Grammar rule `subject` MUST be renamed to `bracket` in `grammar.js`
- **FR-002**: Field name `attributes` within the bracket rule MUST be renamed to `subject` in `grammar.js`
- **FR-003**: All references to the old `subject` rule name MUST be updated throughout `grammar.js` (in `_pattern_element`, `_sub_pattern_element`, etc.)
- **FR-004**: Generated parser code (`src/node-types.json`, `src/grammar.json`, `src/parser.c`) MUST be regenerated to reflect new terminology
- **FR-005**: All test corpus files MUST be updated to use `bracket` node type and `subject` field name in expected AST outputs
- **FR-006**: Test file names containing "subject" (e.g., `subjects.txt`) MUST be renamed to reflect new terminology
- **FR-007**: All documentation files (README.md, WARP.md, AGENTS.md, etc.) MUST be updated to use new terminology
- **FR-008**: All example gram files MUST be reviewed and updated if they contain terminology references in comments
- **FR-009**: Syntax highlighting query files (`queries/highlights.scm`, editor integrations) MUST be updated to reference new node type names
- **FR-010**: Editor integration documentation (Zed README, etc.) MUST be updated with new terminology
- **FR-011**: All language binding examples (Rust, Python, Node.js, etc.) MUST be updated if they reference node types or field names
- **FR-012**: The test suite MUST pass completely after all terminology changes
- **FR-013**: Generated code validation MUST pass (parser compiles, bindings work correctly)

### Key Entities

- **Bracket**: The syntax element `[...]` that serves as the generic container for patterns. Previously called "subject".
- **Subject**: The content or primary data within a bracket. Can include identifier, labels, and record. Previously called "attributes".
- **Grammar Rule**: A named production rule in the grammar definition that defines valid syntax.
- **Node Type**: The type name assigned to parsed syntax elements in the AST.
- **Field Name**: The name given to child elements or properties within a node type.

## Success Criteria *(mandatory)*

### Measurable Outcomes

- **SC-001**: 100% of grammar rules and field names are updated to new terminology (verified by search)
- **SC-002**: All test corpus files pass with updated expected outputs (100% test pass rate)
- **SC-003**: Zero references to old terminology remain in documentation files (verified by comprehensive search)
- **SC-004**: Generated parser code successfully compiles and produces correct ASTs for all test cases
- **SC-005**: All language bindings continue to function correctly with updated node type and field names
- **SC-006**: Documentation is consistent across all files (README, examples, editor docs) with new terminology
- **SC-007**: Syntax highlighting continues to work correctly in editor integrations with updated node type references

## Assumptions

- The syntax of gram files (the actual notation users write) does not change - only internal terminology changes
- Existing gram files written by users will continue to parse correctly (backward compatible at syntax level)
- Generated code will automatically update when grammar is regenerated
- Test corpus files can be updated in a single pass
- Documentation updates are straightforward find-and-replace operations
- Editor integrations will work correctly after query file updates
- No breaking changes to published API contracts if bindings expose node type names (or version bump is acceptable)

## Dependencies

- Tree-sitter CLI must be available to regenerate parser code
- All test corpus files must be updated before running test suite
- Documentation updates should be coordinated to ensure consistency
- Editor integration updates may require testing in actual editors

## Out of Scope

- Changing the actual syntax/notation of gram files (only terminology changes)
- Adding new features or grammar rules
- Changing the semantic meaning or behavior of parsing
- Updating external projects or dependencies that reference the grammar
- Creating migration guides for users (terminology is internal, syntax unchanged)
