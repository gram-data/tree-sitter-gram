# Implementation Plan: Line-Based and End-of-Line Comments

**Branch**: `001-line-comments` | **Date**: 2025-11-10 | **Spec**: [spec.md](./spec.md)
**Input**: Feature specification from `/specs/001-line-comments/spec.md`

**Note**: This template is filled in by the `/speckit.plan` command. See `.specify/templates/commands/plan.md` for the execution workflow.

## Summary

Add support for line-based and end-of-line comments in gram files to enable self-documenting gram files. Comments will be implemented using tree-sitter's `extras` array with a `comment` rule, following standard tree-sitter patterns. The implementation uses `//` as the comment marker syntax (both line-based and end-of-line). Comments are automatically ignored during parsing but can appear in the AST for tooling purposes. String literal content is preserved automatically by tree-sitter's tokenization.

**Phase 0 Complete**: Research completed - see [research.md](./research.md)  
**Phase 1 Complete**: Design artifacts created - see [data-model.md](./data-model.md), [contracts/](./contracts/), [quickstart.md](./quickstart.md)

## Technical Context

**Language/Version**: JavaScript (Node.js), tree-sitter grammar DSL  
**Primary Dependencies**: tree-sitter-cli ^0.25.10, tree-sitter ^0.25.0  
**Storage**: N/A (parser grammar definition)  
**Testing**: tree-sitter test (corpus-based), Node.js test runner for bindings  
**Target Platform**: Cross-platform (tree-sitter generates C parser, bindings for Node.js, Python, Rust, Go, Swift, C)  
**Project Type**: Parser grammar (tree-sitter)  
**Performance Goals**: Comments must not significantly impact parsing performance; parsing should remain efficient for large gram files  
**Constraints**: Must maintain 100% backward compatibility with existing gram files; comments must not break existing parsing behavior; comment markers in string literals must be preserved  
**Scale/Scope**: Grammar modification affecting all gram file parsing; impacts all language bindings (Node.js, Python, Rust, Go, Swift, C)

## Constitution Check

*GATE: Must pass before Phase 0 research. Re-check after Phase 1 design.*

**Grammar Expressiveness and Clarity (Principle I)**:
- [x] Grammar rules use descriptive names aligned with Gram terminology (comment rule named `comment`)
- [x] Rule structure is organized hierarchically (comment in extras, separate from main rules)
- [x] Complex rules are decomposed into named helper functions (using `token()` helper)
- [x] Field annotations used for important AST components (N/A for comments in extras)
- [x] Precedence and associativity explicitly declared (N/A for comments)

**Comprehensive and Illustrative Testing (Principle II)**:
- [x] Corpus tests added/updated in `test/corpus/` with descriptive names (planned: `comments.txt`)
- [x] Tests include both positive and negative cases (planned: line-based, end-of-line, string preservation, invalid cases)
- [x] Tests follow "source ===> tree" format with minimal examples (will use standard corpus format)
- [x] Binding tests added for affected language adapters (comments don't affect bindings, but tests will verify)
- [ ] All test suites pass (`npx tree-sitter test`, `npm test`, etc.) (pending implementation)

**Minimal Binding Examples (Principle III)**:
- [x] Examples updated in `examples/` if AST structure changes (comments don't change AST structure, but examples can demonstrate comment usage)
- [x] Examples remain minimal and focused on core usage (will add minimal comment examples)
- [x] Examples are executable and independently verifiable (existing examples remain valid)

**Status**: ✅ All constitution checks pass. Comments are implemented using standard tree-sitter patterns that align with all principles.

## Project Structure

### Documentation (this feature)

```text
specs/[###-feature]/
├── plan.md              # This file (/speckit.plan command output)
├── research.md          # Phase 0 output (/speckit.plan command)
├── data-model.md        # Phase 1 output (/speckit.plan command)
├── quickstart.md        # Phase 1 output (/speckit.plan command)
├── contracts/           # Phase 1 output (/speckit.plan command)
└── tasks.md             # Phase 2 output (/speckit.tasks command - NOT created by /speckit.plan)
```

### Source Code (repository root)

```text
grammar.js              # Grammar definition (authoritative source)
src/                    # Generated C parser (auto-generated, do not edit)
├── parser.c
└── grammar.json

test/corpus/            # Tree-sitter corpus tests
└── comments.txt       # New test file for comment feature

bindings/              # Language bindings (may need updates)
├── node/
├── python/
├── rust/
├── go/
├── swift/
└── c/

examples/              # Binding examples (may need updates)
├── node/
├── python/
├── rust/
└── ...
```

**Structure Decision**: This is a tree-sitter grammar project. The grammar is defined in `grammar.js` at the root, which generates the C parser in `src/`. Tests are in `test/corpus/` using tree-sitter's corpus format. Language bindings are in `bindings/` and examples in `examples/`. No new directories needed - modifications to existing files only.

## Complexity Tracking

> **Fill ONLY if Constitution Check has violations that must be justified**

| Violation | Why Needed | Simpler Alternative Rejected Because |
|-----------|------------|-------------------------------------|
| [e.g., 4th project] | [current need] | [why 3 projects insufficient] |
| [e.g., Repository pattern] | [specific problem] | [why direct DB access insufficient] |
