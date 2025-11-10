<!--
Sync Impact Report:
Version change: (none) → 1.0.0
Modified principles: (none - initial creation)
Added sections: Core Principles (3 principles), Grammar Development, Testing Standards, Binding Examples
Removed sections: (none - initial creation)
Templates requiring updates:
  ✅ .specify/templates/plan-template.md - Constitution Check section updated
  ✅ .specify/templates/spec-template.md - No changes needed (generic template)
  ✅ .specify/templates/tasks-template.md - No changes needed (generic template)
Follow-up TODOs: None
-->

# tree-sitter-gram Constitution

## Core Principles

### I. Grammar Expressiveness and Clarity

The grammar definition in `grammar.js` MUST prioritize expressiveness and clarity above all else. Grammar rules MUST use descriptive names that align with Gram terminology (`subject`, `relationship`, `node`, `pattern`). Rule structure MUST be organized hierarchically to reflect the language's conceptual model. Complex rules MUST be decomposed into smaller, named helper functions (e.g., `commaSep1()`) rather than inline repetition. Field annotations MUST be used for important AST node components to improve tree structure clarity. Precedence and associativity MUST be explicitly declared using `prec.left()`, `prec.right()`, or `prec()` to avoid ambiguity. The grammar MUST remain readable as documentation of the language structure, not just a parser specification.

**Rationale**: A clear, expressive grammar serves as both executable parser and living documentation. When grammar rules mirror the language's conceptual model, maintenance becomes easier, errors are caught earlier, and the parser's output (AST structure) becomes more intuitive for consumers.

### II. Comprehensive and Illustrative Testing

All grammar changes MUST be accompanied by comprehensive corpus tests in `test/corpus/`. Tests MUST be illustrative, demonstrating both positive cases and edge cases for each language feature. Corpus files MUST use descriptive names with underscores (e.g., `number_values.txt`, `labeled_relationships.txt`) and follow the paired "source ===> tree" format. Each test MUST include minimal, focused examples that clearly demonstrate the feature being tested. New node types MUST be tested in both positive and negative samples. Regression tests MUST be placed near related fixtures. All tests MUST pass (`npx tree-sitter test`) before any grammar change is considered complete. Binding tests MUST be added alongside implementation for each language adapter, gating platform-specific logic with capability checks.

**Rationale**: Comprehensive, illustrative tests serve multiple purposes: they validate correctness, document expected behavior, catch regressions, and provide examples for users learning the grammar. Tests that are minimal and focused are easier to understand and maintain, while comprehensive coverage ensures confidence in parser behavior across all language features.

### III. Minimal Binding Examples

Language binding examples in `examples/` MUST be minimal and focused on demonstrating core usage patterns. Each binding example MUST include only the essential code needed to parse Gram notation and traverse the resulting AST. Examples MUST avoid unnecessary complexity, framework-specific patterns, or production-ready features that obscure the core binding usage. Examples MUST be kept in sync with grammar changes that affect the AST structure. Each example MUST include a README or inline comments explaining the minimal usage pattern. Examples MUST be executable and verifiable independently.

**Rationale**: Minimal examples reduce cognitive load for developers integrating the parser into their projects. By focusing on core usage patterns, examples become more accessible and easier to understand. Keeping examples minimal also reduces maintenance burden and ensures they remain current with grammar evolution.

## Grammar Development

Grammar modifications MUST follow the established workflow: edit `grammar.js`, run `npx tree-sitter generate` to regenerate `src/parser.c`, add or update corpus tests, verify with `npx tree-sitter test`, and update binding examples if AST structure changes. The generated C parser in `src/` MUST never be edited by hand. Grammar rule names MUST use lowerCamelCase and align with Gram terminology. String literal variants (quoted, backticked, tagged, fenced) MUST be consistently supported across all contexts where strings are accepted.

## Testing Standards

Corpus tests MUST use UTF-8 encoding with LF line endings. Test files MUST be organized by language feature, with descriptive filenames. Each test case MUST be separated by `==================` delimiters. Expected AST output MUST use proper indentation to show tree structure clearly. Binding tests MUST be placed beside their implementations (e.g., `bindings/node/binding_test.js`) and MUST gate platform-specific logic with capability checks. All test suites (`npx tree-sitter test`, `npm test`, language-specific test runners) MUST pass before code review.

## Binding Examples

Examples MUST be organized by language in `examples/` subdirectories. Each example MUST demonstrate parsing a simple Gram file and basic AST traversal. Examples MUST avoid including build tooling, complex dependencies, or framework integration unless specifically demonstrating those patterns. Examples MUST be kept minimal to focus attention on parser usage rather than project setup. When grammar changes affect AST structure, affected examples MUST be updated to reflect the new structure.

## Governance

This constitution supersedes all other development practices and guidelines. All pull requests and code reviews MUST verify compliance with these principles. Grammar changes that reduce expressiveness or clarity MUST be justified in the Complexity Tracking section of implementation plans. Test coverage gaps MUST be addressed before merging. Binding examples that grow beyond minimal usage patterns MUST be moved to separate documentation or tutorial materials.

Amendments to this constitution require:
1. Documentation of the rationale for change
2. Update to version number following semantic versioning (MAJOR for principle removals/redefinitions, MINOR for new principles, PATCH for clarifications)
3. Propagation of changes to dependent templates and documentation
4. Update to the Sync Impact Report at the top of this file

**Version**: 1.0.0 | **Ratified**: 2025-11-10 | **Last Amended**: 2025-11-10
