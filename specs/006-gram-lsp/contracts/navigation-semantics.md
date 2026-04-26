# Contract: Navigation and scope semantics

**Feature**: 006-gram-lsp  
**Date**: 2026-04-26

## Goal

Cross-file and in-file **go to definition**, **find references**, and **name completions** MUST follow the same conceptual model as the canonical Tree-sitter locals queries in `queries/locals.scm` (see [../../../queries/locals.scm](../../../queries/locals.scm) and [../004-editor-improvements/contracts/locals.md](../004-editor-improvements/contracts/locals.md)).

## Definitions (introducing sites)

Treat as a **definition** of an identifier `name` when `name` appears in:

- Subject of a `subject_pattern`,
- Subject of a `node_pattern` **that carries** introducing structure (`labels` and/or `record`)—that is, the identifier **introduces** a named element in the sense of duplicate-element rules,
- Subject used as relationship “kind” where the grammar marks a definition site,
- Identifier or labels in an `identified_annotation`,

**MVP note (LSP vs `locals.scm`)**: `queries/locals.scm` also marks bare `node_pattern` identifiers on `relationship_pattern` left/right as `@local.definition` for editor locals. For **navigation and references** in `gram-lsp`, bare left/right endpoints **without** `labels`/`record` are instead classified as **references** (use sites that bind to a prior introducing occurrence in the file). This matches graph-pattern reading: `(a)-[]->(b)` reuses `a` and `b`, it does not introduce new names.

## References (use sites)

Treat as a **reference** when `name` appears in a `pattern_reference` (or equivalent `@local.reference` capture).

## Scope

- **Minimum (MVP)**: For each workspace root, consider all UTF-8 `.gram` files discovered under that root plus any open documents. References may resolve to definitions in **any** indexed file under the same workspace folder set.
- **Name equality**: Identifier text matches exact UTF-8 string of captured name (no case folding unless grammar adds it later).

## Ambiguity

If multiple definitions share the same name in the indexed set:

- **Find references**: return all reference sites that bind to **any** of those definitions, partitioned consistently in tests; OR document that only one definition wins — pick one policy and test it.
- **Go to definition**: return multiple `Location` / `LocationLink` entries or use client disambiguation; MUST NOT crash.

Policy choice MUST be stated in user-facing release notes (FR-008).

## Duplicate element definitions (semantic)

Per [spec.md](../spec.md) clarifications (Session 2026-04-26):

- **Element-introducing (named)**: Positions are **named** definition-introducing identifier sites that participate in a **subject-pattern element** (nested patterns in `subject_pattern_elements`, per grammar intent—not pattern references). **Anonymous** nested elements (no introducing identifier attributed to that element) are **excluded**—they MUST NOT produce duplicate-element diagnostics.
- **Cardinality**: For each distinct **named** element-introducing identifier, a file MAY contain **zero or one** introducing site (**absence is valid**). More than one introducing site for the same name in the same file MUST be semantic diagnostics (editor + CLI).
- **Cross-file**: The same introducing name MAY appear in introducing roles in **different** files; that is not a duplicate-element violation under this contract.
