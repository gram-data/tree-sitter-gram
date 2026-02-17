# Implementation Plan: Extended Annotation (Identifiers and Labels)

**Branch**: `003-extended-annotation` | **Date**: 2025-02-16 | **Spec**: [spec.md](./spec.md)
**Input**: Feature specification from `/specs/003-extended-annotation/spec.md`

**Note**: This template is filled in by the `/speckit.plan` command. See `.specify/templates/commands/plan.md` for the execution workflow.

## Summary

Extend the Gram grammar so that annotations support identifiers and labels in addition to the existing property-style form. Disambiguation is achieved by requiring `@@` for identifier/label annotations and keeping single `@` for property-style (key with value). Grammar changes are confined to the annotation rule and related helpers; new corpus tests and comprehensive grammar documentation (syntax and semantics for arity, annotations, nodes, relationships, paths, generic patterns, and value types) are produced.

**Phase 0 Complete**: Research completed — see [research.md](./research.md)  
**Phase 1 Complete**: Design artifacts created — see [data-model.md](./data-model.md), [contracts/](./contracts/), [quickstart.md](./quickstart.md)

## Technical Context

**Language/Version**: JavaScript (Node.js), tree-sitter grammar DSL  
**Primary Dependencies**: tree-sitter-cli (project version), tree-sitter (bindings)  
**Storage**: N/A (parser grammar definition)  
**Testing**: tree-sitter test (corpus), Node.js test runner for bindings  
**Target Platform**: Cross-platform (generated C parser; bindings: Node, Python, Rust, Go, Swift, C)  
**Project Type**: Parser grammar (tree-sitter)  
**Performance Goals**: Parsing remains efficient; `@@` vs `@` is a single-token distinction  
**Constraints**: Backward compatibility for existing single-`@` annotations (property-style); no ambiguity in annotation form. Identifiers in `@@` are naming identifiers (short names, GUIDs, pseudo-sequences); property-like terms (e.g. verified, name) use `@key(value)` (e.g. `@verified(true)`), not `@@verified`.  
**Scale/Scope**: Grammar change to annotation rules; new corpus fixtures; documentation covering full grammar syntax and semantics

## Constitution Check

*GATE: Must pass before Phase 0 research. Re-check after Phase 1 design.*

**Grammar Expressiveness and Clarity (Principle I)**:
- [x] Grammar rules use descriptive names aligned with Gram terminology (identified_annotation, property_annotation; identifier and labels as direct fields)
- [x] Rule structure is organized hierarchically (annotations → identified_annotation or property_annotation; introducer + identifier/labels or key+value; body at annotated_pattern.elements)
- [x] Complex rules are decomposed into named helper functions (e.g. commaSep1; identified_annotation has optional identifier and optional labels as direct fields via choice)
- [x] Field annotations used for important AST components (annotations, key, value, identifier, labels, elements)
- [x] Precedence and associativity explicitly declared where needed (e.g. _value)

**Comprehensive and Illustrative Testing (Principle II)**:
- [x] Corpus tests added/updated in `test/corpus/` with descriptive names (e.g. extended_annotations.txt)
- [x] Tests include both positive and negative cases (@@ and @ forms, invalid headers)
- [x] Tests follow "source ===> tree" format with minimal examples
- [x] Binding tests added for affected language adapters if AST shape changes
- [ ] All test suites pass (pending implementation)

**Minimal Binding Examples (Principle III)**:
- [x] Examples updated in `examples/` if AST structure changes (annotation node shape)
- [x] Examples remain minimal and focused on core usage
- [x] Examples are executable and independently verifiable

**Status**: ✅ Constitution checks pass. Design aligns with all principles.

## Project Structure

### Documentation (this feature)

```text
specs/003-extended-annotation/
├── plan.md              # This file
├── research.md          # Phase 0
├── data-model.md        # Phase 1
├── quickstart.md        # Phase 1 (includes grammar syntax/semantics reference)
├── contracts/           # Phase 1 (annotation AST contract)
└── tasks.md             # Phase 2 output (/speckit.tasks — not created by plan)
```

### Source Code (repository root)

```text
grammar.js               # Grammar definition (annotation rules updated)
src/                     # Generated C parser (regenerate with npx tree-sitter generate)
├── parser.c
├── grammar.json
└── node-types.json

test/corpus/             # Corpus tests
├── extended_annotations.txt   # New: @@ and @ forms, positive and edge cases
└── ...existing...

bindings/                # Language bindings (update if AST changes)
├── node/
├── python/
├── rust/
├── go/
├── swift/
└── c/

examples/                # Minimal usage examples (update if annotation AST changes)
└── ...
```

**Structure Decision**: Single grammar project. Annotation changes are localized to `grammar.js` and corpus; bindings and examples updated only if the annotation AST node/field names change.

## Complexity Tracking

> **Fill ONLY if Constitution Check has violations that must be justified**

| Violation | Why Needed | Simpler Alternative Rejected Because |
|-----------|------------|-------------------------------------|
| (None)    | —          | —                                   |
