# Research: Extended Annotation (Identifiers and Labels)

**Feature**: 003-extended-annotation  
**Date**: 2025-02-16  
**Status**: Complete

## Research Questions

1. How should `@@` be tokenized in a tree-sitter grammar so it is distinct from `@`?
2. Should the `@@` annotation header reuse the existing `_subject` rule (identifier, labels) for consistency?
3. What are best practices for optional identifier and optional labels in a single header?
4. Where should comprehensive grammar syntax/semantics documentation live?

## Findings

### 1. Tokenization of `@@` vs `@`

**Decision**: Treat `@@` as a distinct literal in the grammar (e.g. `"@@"` in a sequence). Do not rely on a symbol token that includes `@`; use explicit `seq("@", "@")` or a dedicated token so the parser sees two distinct annotation introducers.

**Rationale**:
- Tree-sitter matches longest literal first when rules are ordered; `"@@"` before `"@"` in a choice ensures `@@` is recognized as one unit for the introducer.
- Alternatively, a single rule `annotation_introducer: choice("@@", "@")` with `@@` first gives clear precedence and produces a single node type for "introducer" with the text distinguishing kind.
- Existing `symbol` rule allows `@` in identifiers (`[a-zA-Z_][0-9a-zA-Z_.\-@]*`); annotation keys are currently `$.symbol`, so `@` alone is not a symbol. Keeping `@` and `@@` as structural tokens (not part of symbol) avoids ambiguity.

**Alternatives considered**:
- Single token matching `@(@)?`: Possible but less clear in the grammar rule structure; explicit `seq("@","@")` vs `"@"` is more readable.
- External scanner: Unnecessary; grammar can distinguish with a top-level choice on the introducer.

### 2. Reuse of `_subject` for `@@` header

**Decision**: Reuse the same structural components as `_subject` for the `@@` header: optional identifier, optional labels, same order (identifier then labels). Do not reuse the full `_subject` rule if it includes record (e.g. `{ ... }`), unless the proposal allows records in annotation headers. For annotation headers, use optional identifier followed by optional labels only (no record in header).

**Rationale**:
- Spec and proposal require "same order/convention used in subject position elsewhere" (FR-006, spec Assumptions).
- Grammar already has `_subject` with identifier, labels, record in various combinations. For `@@` header, identifier and/or labels only keeps annotations simple; record in header can be deferred.
- Reusing `identifier` and `labels` rules (and `_label`) ensures consistency; the header can be a new rule `annotation_header: optional(identifier), optional(labels)` with ordering enforced, or a choice of (identifier only, labels only, identifier + labels) to avoid "both optional but at least one" ambiguity.

**Alternatives considered**:
- New dedicated header rules that duplicate identifier/labels structure: Rejected to avoid drift from subject syntax.
- Allowing record in `@@` header: Deferred; spec does not require it.

### 3. Optional identifier + optional labels (at least one required)

**Decision**: Model the `@@` header as a choice: (1) identifier only, (2) labels only, (3) identifier then labels. Require at least one of identifier or labels so that `@@ (` with nothing before the paren is invalid. In the grammar, express this as a choice of three alternatives rather than two optional elements (to avoid ambiguous empty match).

**Rationale**:
- Tree-sitter handles "optional A, optional B, at least one required" by either a choice of (A alone, B alone, A B) or a precedence that prefers the longer match. Using a choice of three forms is explicit and avoids empty-header parses.
- Aligns with spec edge case: "Empty or invalid header after `@@` (e.g. `@@ (a)`) rejected."

**Alternatives considered**:
- Two optional fields with a conflict: Can lead to ambiguity; explicit choice is clearer.

### 4. Documentation location and scope

**Decision**: Add comprehensive grammar syntax and semantics documentation to this feature's `quickstart.md`, and ensure the repository's `examples/` and any existing grammar docs reference it. The documentation will cover: arity (0, 1, 2, N), annotations (`@` vs `@@`, property-style and identifier/labels), nodes, relationships, paths, generic (bracket) patterns, and all value types (symbol, string, number, boolean, range, array, map, tagged string).

**Rationale**:
- User requirement: "comprehensive documentation of the grammar syntax and semantics, covering each arity, annotation, nodes, relationships, paths, generic patterns and all value types."
- Keeping it in the feature quickstart makes the extension self-contained and gives implementers and writers a single reference; it can be promoted to a top-level `docs/` or `grammar.md` in a later change.
- Proposal (proposals/extended-annotation.md) and existing grammar.js are the sources of truth for semantics and syntax.

**Alternatives considered**:
- Separate `grammar-reference.md` in specs: Acceptable; folded into quickstart for Phase 1 to satisfy "comprehensive documentation" in one place.

## Summary Table

| Topic              | Decision                                                                 | Rationale / Note                    |
|-------------------|--------------------------------------------------------------------------|-------------------------------------|
| `@@` tokenization | Distinct literal/rule (`@@` before `@` in choice)                        | Clear, no scanner needed            |
| Header structure  | Reuse identifier + labels rules; no record in header; at least one required | Consistency with subject; spec      |
| Empty `@@` header | Invalid (reject via grammar choice)                                     | Spec edge case                      |
| Documentation     | In quickstart.md for this feature; full syntax/semantics reference       | User-requested coverage              |
