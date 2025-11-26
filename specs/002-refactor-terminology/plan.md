# Implementation Plan: Refactor Terminology

**Branch**: `001-refactor-terminology` | **Date**: 2025-01-27 | **Spec**: [spec.md](./spec.md)
**Input**: Feature specification from `/specs/001-refactor-terminology/spec.md`

**Note**: This template is filled in by the `/speckit.plan` command. See `.specify/templates/commands/plan.md` for the execution workflow.

## Summary

Refactor terminology in the grammar to improve clarity: rename the grammar rule `subject` to `bracket` (the `[...]` notation container) and rename the field `attributes` to `subject` (the content/data within brackets). This is a systematic find-and-replace operation across grammar rules, generated code, tests, documentation, and examples. The syntax of gram files remains unchanged - only internal terminology changes, ensuring backward compatibility at the syntax level.

## Technical Context

**Language/Version**: JavaScript (Node.js) for grammar definition, generated C code for parser  
**Primary Dependencies**: tree-sitter (CLI and runtime), tree-sitter CLI for code generation  
**Storage**: N/A (parser generation, no data storage)  
**Testing**: tree-sitter test framework (`npx tree-sitter test`), language-specific test runners  
**Target Platform**: Cross-platform (parser generates C code compiled for target platforms)  
**Project Type**: Grammar/parser project (tree-sitter grammar definition)  
**Performance Goals**: N/A (terminology change, no performance impact)  
**Constraints**: Must maintain backward compatibility at syntax level (existing gram files continue to parse)  
**Scale/Scope**: ~24 files need updates (grammar.js, generated code, tests, docs, examples, editor integrations)

## Constitution Check

*GATE: Must pass before Phase 0 research. Re-check after Phase 1 design.*

**Grammar Expressiveness and Clarity (Principle I)**:
- [x] Grammar rules use descriptive names aligned with Gram terminology - **PASS**: Renaming improves alignment (bracket = container, subject = content)
- [x] Rule structure is organized hierarchically - **PASS**: No structural changes, only name changes
- [x] Complex rules are decomposed into named helper functions - **PASS**: No changes to rule complexity
- [x] Field annotations used for important AST components - **PASS**: Field name change (`attributes` → `subject`) maintains annotation structure
- [x] Precedence and associativity explicitly declared - **PASS**: No precedence changes

**Comprehensive and Illustrative Testing (Principle II)**:
- [x] Corpus tests added/updated in `test/corpus/` with descriptive names - **PASS**: Tests will be updated with new terminology, file names renamed
- [x] Tests include both positive and negative cases - **PASS**: Existing test coverage maintained, only terminology updated
- [x] Tests follow "source ===> tree" format with minimal examples - **PASS**: Format unchanged, only expected output terminology updated
- [x] Binding tests added for affected language adapters - **PASS**: Generated code updates automatically, binding tests verify functionality
- [x] All test suites pass (`npx tree-sitter test`, `npm test`, etc.) - **PASS**: Tests will pass after terminology updates

**Minimal Binding Examples (Principle III)**:
- [x] Examples updated in `examples/` if AST structure changes - **PASS**: Examples will be updated to use new node type/field names
- [x] Examples remain minimal and focused on core usage - **PASS**: Only terminology changes, no complexity added
- [x] Examples are executable and independently verifiable - **PASS**: Examples remain executable after terminology updates

**GATE STATUS (Post-Design)**: ✅ **PASS** - All principles satisfied. Terminology refactoring improves clarity without violating any principles. Research and design phases confirm no violations.

## Project Structure

### Documentation (this feature)

```text
specs/001-refactor-terminology/
├── plan.md              # This file (/speckit.plan command output)
├── research.md          # Phase 0 output (/speckit.plan command)
├── data-model.md        # Phase 1 output (/speckit.plan command)
├── quickstart.md        # Phase 1 output (/speckit.plan command)
├── contracts/           # Phase 1 output (/speckit.plan command)
└── tasks.md             # Phase 2 output (/speckit.tasks command - NOT created by /speckit.plan)
```

### Source Code (repository root)

```text
grammar.js                    # Grammar definition (rule names updated)
src/                          # Generated parser code (regenerated after grammar changes)
├── parser.c                  # Generated C parser
├── grammar.json              # Generated grammar metadata
└── node-types.json           # Generated node type definitions

test/corpus/                  # Test corpus files
├── subjects.txt              # Renamed to brackets.txt
└── [other test files]        # Expected outputs updated

queries/                      # Syntax highlighting queries
└── highlights.scm            # Node type references updated

editors/                      # Editor integrations
└── zed/
    └── languages/gram/
        └── highlights.scm     # Node type references updated

examples/                     # Language binding examples
├── rust/
├── python/
├── node/
└── [other languages]         # Examples updated if they reference node types

bindings/                     # Language bindings (generated code updates automatically)
├── rust/
├── python/
├── node/
└── [other languages]

README.md                     # Documentation updated
WARP.md                       # Documentation updated
AGENTS.md                     # Documentation updated
```

**Structure Decision**: Existing tree-sitter grammar project structure. No structural changes needed - only terminology updates within existing files. The refactoring affects:
1. Grammar definition (`grammar.js`)
2. Generated code (auto-updated via `npx tree-sitter generate`)
3. Test corpus files (`test/corpus/`)
4. Documentation files (root level and editor docs)
5. Example files (if they reference node types)
6. Query files (syntax highlighting)

## Complexity Tracking

> **Fill ONLY if Constitution Check has violations that must be justified**

No violations - terminology refactoring improves clarity and aligns with constitution principles.
