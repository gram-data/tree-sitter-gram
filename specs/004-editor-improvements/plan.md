# Implementation Plan: Editor Support and Syntax Highlighting Improvements

**Branch**: `004-editor-improvements` | **Date**: 2025-03-11 | **Spec**: [spec.md](./spec.md)  
**Input**: Feature specification from `/specs/004-editor-improvements/spec.md`

## Summary

Deliver improved editor support for .gram files by extending the Tree-sitter query set (highlights, locals, indents, injections) and adding documentation. No grammar changes. Single canonical query files in `queries/` consumed by Zed via `scripts/prepare-zed-extension.sh`. Highlights differentiate definition-like vs reference identifiers and capture tagged-string tag and comment; locals enable go-to-definition and highlight-references at file scope; indents use 2 spaces per level; injections use tag-as-language with minimal overrides (md→markdown, ts→typescript). Docs cover well-known tags and `::` schema convention.

## Technical Context

**Language/Version**: Tree-sitter query language (scheme-like .scm); grammar.js (JavaScript, Node); parser generated to C via tree-sitter-cli  
**Primary Dependencies**: tree-sitter, tree-sitter-cli (npm); editors consume queries (Zed, Neovim, Helix, Emacs)  
**Storage**: N/A (query and doc files only)  
**Testing**: `npx tree-sitter test` (corpus in test/corpus/); manual/visual check in editors  
**Target Platform**: Any editor that supports Tree-sitter queries (Zed in-repo; others via npm package and queries/)  
**Project Type**: Single (grammar + queries + bindings)  
**Performance Goals**: Queries and indents must not cause noticeable editor lag on typical .gram files (< ~10k lines)  
**Constraints**: Single canonical `queries/*.scm`; Zed extension must not duplicate query logic (sync from queries/)  
**Scale/Scope**: All .gram files; file-level scope for locals; 2-space indent; minimal injection overrides md, ts

## Constitution Check

*GATE: Must pass before Phase 0 research. Re-check after Phase 1 design.*

**Grammar Expressiveness and Clarity (Principle I)**:
- [x] No grammar changes in this feature; existing grammar.js remains authoritative
- [x] N/A — rule structure unchanged

**Comprehensive and Illustrative Testing (Principle II)**:
- [ ] Corpus tests added/updated for any new query-relevant patterns if needed (e.g. corpus file exercising definition vs reference for visual verification)
- [ ] Tests follow "source ===> tree" format; existing corpus remains valid
- [x] No binding changes; binding tests N/A for query-only feature
- [ ] All test suites pass (`npx tree-sitter test`, `npm test`) after changes

**Comprehensive and Illustrative Testing (Principle II)**:
- [ ] Corpus tests added/updated for any new query-relevant patterns if needed (e.g. corpus file exercising definition vs reference for visual verification)
- [ ] Tests follow "source ===> tree" format; existing corpus remains valid
- [x] No binding changes; binding tests N/A for query-only feature
- [ ] All test suites pass (`npx tree-sitter test`, `npm test`) after changes

**Minimal Binding Examples (Principle III)**:
- [x] No AST structure change; examples in examples/ unchanged

*Post Phase 1 design*: Research, data-model, and contracts complete. No grammar changes; Principle I N/A. Principle II satisfied by existing corpus plus manual/visual verification of queries; add corpus only if new patterns need regression coverage. Principle III satisfied (no example updates).

## Project Structure

### Documentation (this feature)

```text
specs/004-editor-improvements/
├── plan.md              # This file
├── research.md          # Phase 0
├── data-model.md        # Phase 1
├── quickstart.md        # Phase 1
├── contracts/           # Phase 1 (query and doc contracts)
└── tasks.md             # Phase 2 (created by /speckit.tasks)
```

### Source Code (repository root)

```text
queries/
├── highlights.scm       # Canonical; extend (definition vs reference, tag, comment)
├── locals.scm          # New (definition, reference, optional scope)
├── indents.scm         # New (2 spaces per level)
└── injections.scm      # Existing; ensure minimal overrides md, ts + dynamic

editors/zed/languages/gram/
├── config.toml
├── highlights.scm       # Synced from queries/
├── injections.scm       # Synced from queries/
├── locals.scm           # Synced from queries/ (after add)
└── indents.scm          # Synced from queries/ (after add)

docs/
├── tagged-strings-and-injections.md   # New or extend: well-known tags, :: convention
└── (cross-links from gram-reference / gram-ebnf as needed)

grammar.js               # No changes
src/                     # Generated; no hand edit
test/corpus/             # Add/update only if new coverage needed for query behavior
scripts/
└── prepare-zed-extension.sh   # Already syncs queries/*.scm → Zed
```

**Structure Decision**: Single repo; canonical queries in `queries/`; Zed and other editors consume from there. No new top-level apps or services.

## Complexity Tracking

> **Fill ONLY if Constitution Check has violations that must be justified**

| Violation | Why Needed | Simpler Alternative Rejected Because |
|-----------|------------|-------------------------------------|
| (none)    | —          | —                                   |
