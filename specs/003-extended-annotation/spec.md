# Feature Specification: Extended Annotation (Identifiers and Labels)

**Feature Branch**: `003-extended-annotation`  
**Created**: 2025-02-16  
**Status**: Draft  
**Input**: User description: "Extend the grammar to support identifiers and labels in annotation as described in proposals/extended-annotation.md"

## Clarifications

### Session 2025-02-16

- Q: How should the notation define the meaning of `@<symbol> (<body>)` so that there is exactly one interpretation (identifier wrapping body vs property key with value)? → A: Require `@@` to precede identifier and labels; single `@` remains for property-style. Example: `@@route66:Path @desc("historic route") (a)-->(b)-->(c)` — `@@` introduces identified/labeled annotation, `@` introduces property key with value.
- **Annotation stacking**: Annotations stack on the same body but the grammar allows only **one optional** `identified_annotation` (`@@`) followed by **zero or more** `property_annotation` (`@`). Example: `@@route66:Highway @name("Route 66") @description("A famous roadway in the USA") (a)-->(b)-->(c)` — at most one `@@`, then any number of `@`, then the body.

## User Scenarios & Testing *(mandatory)*

### User Story 1 - Annotations with an identifier (Priority: P1)

Authors writing Gram notation need to attach a named wrapper to a graph element (node, relationship, or path) so that the wrapper can be referred to and maps to an identified 1-arity pattern. Identified annotations use the `@@` prefix (e.g. `@@p (a)` → pattern `p` wrapping `a`).

**Why this priority**: Identified annotations are the core extension; they enable reference and semantic mapping.

**Independent Test**: Can be fully tested by parsing and validating documents that use `@@<identifier> (<body>)` and confirming the annotation header is recognized as that identifier.

**Acceptance Scenarios**:

1. **Given** a Gram document, **When** an annotation is written as `@@p (a)` where `p` is an identifier, **Then** the annotation is accepted and the header is interpreted as identifier `p`.
2. **Given** a Gram document, **When** an annotation wraps a relationship e.g. `@@r1 (a)-[r]->(b)` (identifier `r1` as short name for the wrapper), **Then** the annotation is accepted and applies to the relationship. Property-like concepts (e.g. verified) use property form: `@verified(true)`.

---

### User Story 2 - Annotations with labels only (Priority: P2)

Authors need to attach a labeled (but unnamed) wrapper to a graph element so that the wrapper is typed by label(s) only. Labeled-only annotations use `@@` (e.g. `@@:L (a)` → labeled wrapper around `a`).

**Why this priority**: Labels alone support type-like metadata without requiring a name.

**Independent Test**: Can be tested by parsing documents that use `@@:Label (<body>)` (and optionally `@@::Label`) and confirming the annotation header is recognized as labels only.

**Acceptance Scenarios**:

1. **Given** a Gram document, **When** an annotation is written as `@@:L (a)` with one or more labels, **Then** the annotation is accepted and the header is interpreted as labels only (no identifier).
2. **Given** a Gram document, **When** an annotation uses multiple labels in the same form used elsewhere in the notation, **Then** the annotation is accepted and all labels are recognized.

---

### User Story 3 - Annotations with identifier and labels (Priority: P3)

Authors need to attach a named, labeled wrapper in one annotation. Identified-and-labeled annotations use `@@` (e.g. `@@p:L (a)` → identified wrapper `p` with label `L`).

**Why this priority**: Full expressiveness after identifier-only and labels-only are supported.

**Independent Test**: Can be tested by parsing documents that use `@@<identifier>:<labels> (<body>)` and confirming both identifier and labels are recognized in the header.

**Acceptance Scenarios**:

1. **Given** a Gram document, **When** an annotation is written as `@@p:L (a)`, **Then** the annotation is accepted and the header is interpreted as identifier `p` and label(s) `L`.
2. **Given** a Gram document, **When** an annotation combines identifier and multiple labels in the same order/convention used in subject position elsewhere, **Then** the annotation is accepted and both identifier and labels are recognized.

---

### User Story 4 - Anonymous / property-style annotations (Priority: P4)

Authors need to attach a property-style annotation using a single `@` (e.g. `@desc("historic route") (a)` or `@desc (a)`), where the header is a property key and the parenthesized part is the value (or value and body). This is distinct from identified/labeled annotations, which use `@@`.

**Why this priority**: Preserves existing property-style behavior and removes ambiguity: single `@` = property key with value; `@@` = identifier and/or labels wrapping the following body.

**Independent Test**: Can be tested by parsing documents that use a single `@` followed by key and value (e.g. `@desc (a)` or `@desc("text")`) and confirming the annotation is accepted as property-style, not as an identifier wrapper.

**Acceptance Scenarios**:

1. **Given** a Gram document, **When** an annotation is written with single `@` and a key (e.g. `@desc("historic route") (a)-->(b)`), **Then** the annotation is accepted and interpreted as property key with value, not as an identifier wrapping the path.
2. **Given** existing documents using only `@<symbol> (<body>)`, **When** the extended grammar is applied, **Then** those annotations continue to parse as property-style (key and value) and do not become identifier wrappers.

---

### Edge Cases

- **Disambiguation**: Single `@` always denotes property-style (key with value); `@@` always denotes identifier and/or labels wrapping the following body. There is no lexical ambiguity between the two.
- **Stacking order**: Only one `identified_annotation` (`@@`) is allowed per annotated element; it may appear first, followed by zero or more `property_annotation` (`@`). A second `@@` before the body is invalid (e.g. `@@p @@q (a)` rejected).
- An annotation header after `@@` has only labels (e.g. `@@:L`) with no identifier: parsed as labels-only; no identifier node.
- An annotation header after `@@` has identifier and labels in the same order as subject position (identifier then labels): both are recognized.
- Empty or invalid header after `@` or `@@` (e.g. `@ (a)` or `@@ (a)`): rejected or defined as invalid by the grammar.
- Label syntax in the `@@` header matches the existing label syntax used elsewhere in the notation (e.g. `:` or `::` prefix) so behavior is consistent across the language.

## Requirements *(mandatory)*

### Functional Requirements

- **FR-001**: The notation MUST require `@@` to introduce any annotation whose header is an identifier and/or labels; the token `@@` disambiguates identified/labeled annotations from property-style annotations.
- **FR-002**: The notation MUST allow annotation headers after `@@` that are identifier-only (e.g. `@@p (a)`), so that the wrapper is identified by that name.
- **FR-003**: The notation MUST allow annotation headers after `@@` that are labels-only (e.g. `@@:L (a)`), so that the wrapper is typed by label(s) without an identifier.
- **FR-004**: The notation MUST allow annotation headers after `@@` that have both identifier and labels (e.g. `@@p:L (a)`), so that the wrapper has both a name and type/labels.
- **FR-005**: The notation MUST keep single `@` for property-style annotations (e.g. `@desc("historic route") (a)-->(b)`), where the header is a property key and the parenthesized content is the value (and optionally the annotated body); no `@@` is used for this form.
- **FR-006**: Annotation header syntax for labels after `@@` MUST be consistent with the existing label syntax used in the rest of the notation (same prefix and symbol rules).
- **FR-007**: Valid annotation forms MUST be parseable without ambiguity: `@` vs `@@` determines property-style vs identifier/labels; the structure of the `@@` header (identifier, labels, or both) MUST be deterministically recoverable from the source text.
- **FR-008**: Annotations MUST stack on a single body with this constraint: at most **one** optional `identified_annotation` (`@@`), then **zero or more** `property_annotation` (`@`). The optional `@@`, if present, MUST appear before any `@`. Valid examples: `@@p (a)`, `@k(v) (a)`, `@@p @name("x") @desc("y") (a)-->(b)`; invalid: two or more `@@` before the body (e.g. `@@p @@q (a)`).

### Key Entities

- **Annotation introducer**: Either `@` (property-style: key with value) or `@@` (identified and/or labeled wrapper). The introducer disambiguates the annotation kind.
- **Annotation header (after `@@`)**: The part of an identified/labeled annotation between `@@` and `(`. It may include an optional identifier, optional labels, or both, and determines the defining pattern of the 1-arity wrapper.
- **Property-style header (after `@`)**: The property key and value; the part between `@` and the following body (if any).
- **Identifier**: A name that identifies the wrapper pattern after `@@`; same concept as identifier in subject position. Identifiers in `@@` should read as **short names**, **GUIDs**, or **pseudo-sequences** (e.g. `r1`, `seg_ab`, `id_xyz`). Property-like terms (e.g. verified, name, description) MUST use property form: `@verified(true)`, `@name("Route 66")`, not `@@verified` or `@@name`.
- **Labels**: Type-like markers attached to the wrapper after `@@`; same concept and syntax as labels in subject position.

### Assumptions

- Identifiers in `@@` headers are naming identifiers (short names, GUIDs, pseudo-sequences), not property keys; use `@` for properties (e.g. `@verified(true)`, not `@@verified`).
- Label syntax in `@@` annotation headers reuses the same rules as labels elsewhere in the Gram notation (e.g. `:` or `::` plus symbol).
- The semantic mapping (e.g. to 1-arity patterns) is defined elsewhere; this feature covers only the syntactic extension of the annotation header and the `@@` vs `@` disambiguation.
- Existing documents that use only single `@<symbol> (<body>)` remain valid and are interpreted as property-style annotations (key with value), not as identifier wrappers.

## Success Criteria *(mandatory)*

### Measurable Outcomes

- **SC-001**: Authors can express property-style annotations with single `@` and identified/labeled annotations with `@@` (identifier-only, labels-only, identifier-plus-labels) in valid documents and have them accepted as valid notation without ambiguity.
- **SC-002**: Each form (`@` property-style and `@@` identifier-only, labels-only, identifier-plus-labels) can be validated by a test suite with at least one positive test per form and no regressions on existing single-`@` annotation usage.
- **SC-003**: Documentation and examples can describe the extended annotation syntax without referring to implementation details; a reader can write correct annotations from the specification alone.
- **SC-004**: The structure of annotations is unambiguous: `@` vs `@@` fixes the annotation kind; for `@@`, identifier, labels, or both can be reliably distinguished and mapped to the intended semantic model.
