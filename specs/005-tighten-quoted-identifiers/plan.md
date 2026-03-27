# Implementation Plan: Tighten Quoted Names

**Branch**: `005-tighten-quoted-identifiers` | **Date**: 2026-03-27 | **Spec**: [spec.md](./spec.md)  
**Input**: Feature specification from `/specs/005-tighten-quoted-identifiers/spec.md`

**Note**: This template is filled in by the `/speckit.plan` command. See `.specify/templates/commands/plan.md` for the execution workflow.

## Summary

Tighten name handling in the Gram grammar by separating general string values from name-like quoted forms. Introduce dedicated rules so identifiers accept bare names, backtick-quoted names, and existing numeric identifiers; labels accept bare names or a single backtick-quoted label; record and map keys accept bare names, backtick-quoted names, or double-quoted names. Preserve value syntax and keep property annotation keys and tagged-string tags restricted to bare symbols. Treat `@key(value)` and `@@identifier:Label` as syntactic sugar for the wrapper subject's properties, identifier, and labels rather than as independent semantic constructs. Update corpus tests, syntax queries, and grammar documentation to reflect the narrower, position-specific quoting rules.

**Phase 0 Complete**: Research completed — see [research.md](./research.md)  
**Phase 1 Complete**: Design artifacts created — see [data-model.md](./data-model.md), [contracts/](./contracts/), [quickstart.md](./quickstart.md)

## Technical Context

**Language/Version**: JavaScript grammar DSL (`grammar.js`), generated C parser (`src/`), Node.js package tooling  
**Primary Dependencies**: `tree-sitter`, `tree-sitter-cli`, Node.js binding toolchain; Tree-sitter queries for editor support  
**Storage**: N/A (grammar, parser artifacts, docs, and tests in-repo)  
**Testing**: `npx tree-sitter test`, `npm test`, targeted corpus regressions for parse-tree shape, query smoke checks for highlights/locals  
**Target Platform**: Cross-platform Tree-sitter grammar consumed by Node, Python, Rust, Go, Swift, C bindings, and editor integrations  
**Project Type**: Single grammar/parser repository  
**Performance Goals**: No meaningful parse slowdown; quoted-name support remains tokenizable without an external scanner and preserves current editor responsiveness on typical `.gram` files  
**Constraints**: `grammar.js` remains the source of truth; `src/parser.c` and related generated files must be regenerated, not edited; value string syntax remains unchanged; property annotation keys and tagged-string tags must remain bare `symbol`; existing bare-name syntax and JSON-style double-quoted keys must remain valid; annotation sugar stays semantically equivalent to the wrapper subject in bracket-pattern notation even where the sugar is syntactically narrower  
**Scale/Scope**: Localized grammar change affecting identifier, label, and key positions; expected updates in corpus fixtures, documentation (`docs/`), and Tree-sitter queries (`queries/` plus synced editor copies)

## Constitution Check

*GATE: Must pass before Phase 0 research. Re-check after Phase 1 design.*

**Grammar Expressiveness and Clarity (Principle I)**:
- [x] Grammar rules can use descriptive names aligned with Gram terminology (`symbol`, name-like quoted rules, key-specific rule) without overloading `string_literal`
- [x] Rule structure remains hierarchical by separating identifier, label, key, and value concerns rather than broadening `symbol`
- [x] Complex behavior is decomposed into named helper rules instead of embedding all quoting variants in `_identifier`
- [x] Field annotations remain stable for important AST components (`identifier`, `labels`, `key`, `value`)
- [x] Existing precedence and associativity for `_value` and `_scalar_value` remain explicit and unchanged

**Comprehensive and Illustrative Testing (Principle II)**:
- [x] Plan includes corpus updates in `test/corpus/` for accepted and rejected quoted-name forms
- [x] Plan includes both positive and negative cases for identifiers, labels, and keys
- [x] Planned fixtures remain minimal and in the existing corpus format
- [x] No new binding logic is expected; binding tests remain targeted only if AST node kinds or fields change
- [ ] All test suites pass (`npx tree-sitter test`, `npm test`) after implementation

**Minimal Binding Examples (Principle III)**:
- [x] No example expansion is required unless an example currently relies on now-invalid quoted identifiers
- [x] Existing examples remain minimal and focused on parser usage
- [x] Any touched examples can be kept executable and independently verifiable

**Post Phase 1 design**: Research resolved the grammar split, compatibility decisions, and repo touchpoints. Design remains constitution-compliant because it narrows behavior through clearer rule decomposition, keeps tests illustrative, and avoids unnecessary complexity in bindings or examples.

## Project Structure

### Documentation (this feature)

```text
specs/005-tighten-quoted-identifiers/
├── plan.md              # This file
├── research.md          # Phase 0
├── data-model.md        # Phase 1
├── quickstart.md        # Phase 1
├── contracts/           # Phase 1 (grammar and AST contracts)
└── tasks.md             # Phase 2 output (/speckit.tasks command)
```

### Source Code (repository root)

```text
grammar.js                   # Authoritative grammar rules for identifiers, labels, keys, and values

src/                         # Generated parser artifacts (regenerate; do not hand edit)
├── parser.c
├── grammar.json
└── node-types.json

test/corpus/                 # Grammar behavior contract
├── identifiers.txt          # Update accepted/rejected identifier forms
├── labeled_nodes.txt        # Extend or add quoted-label coverage
├── labeled_relationships.txt
├── value_pair.txt           # Preserve double-quoted key behavior; tighten unsupported key forms
└── ...existing fixtures...

queries/                     # Canonical query definitions
├── highlights.scm           # Add captures for quoted labels/keys if visible node types change
├── locals.scm               # Keep definition/reference captures aligned with new label/name nodes
└── injections.scm           # No scope broadening; tagged-string tags remain symbol-only

editors/zed/languages/gram/  # Synced query copies consumed by Zed
├── highlights.scm
├── locals.scm
└── injections.scm

docs/                        # Language reference and formal grammar docs
├── gram-reference.md
├── gram-ebnf.md
├── gram.ebnf
└── tagged-strings-and-injections.md

examples/                    # Minimal parser usage and sample gram files
└── data/
```

**Structure Decision**: Single grammar project. The feature is implemented primarily in `grammar.js`, with matching updates to generated parser artifacts, corpus tests, syntax queries, and grammar documentation. No new services, packages, or runtime layers are introduced.

## Complexity Tracking

> **Fill ONLY if Constitution Check has violations that must be justified**

| Violation | Why Needed | Simpler Alternative Rejected Because |
|-----------|------------|-------------------------------------|
| (none)    | —          | —                                   |
