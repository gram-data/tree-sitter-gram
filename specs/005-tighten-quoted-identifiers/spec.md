# Feature Specification: Tighten Quoted Names

**Feature Branch**: `005-tighten-quoted-identifiers`  
**Created**: 2026-03-27  
**Status**: Draft  
**Input**: User description: "Improve rules for quoted identifiers, labels, and keys as described above, preserving JSON and Cypher friendlieness, while tightening some of the rules."

## User Scenarios & Testing *(mandatory)*

### User Story 1 - Use quoted identifiers consistently (Priority: P1)

As a person authoring gram patterns, I want identifiers to accept bare names and backtick-quoted names, so I can name patterns and pattern elements with Cypher-friendly syntax without allowing overly broad string forms.

**Why this priority**: Identifier syntax appears across pattern definitions and references, so tightening it without losing expressiveness delivers the biggest language-level value.

**Independent Test**: Author a set of patterns and references that use bare names, numeric identifiers where already supported, and backtick-quoted names. Confirm those forms are accepted, while single-quoted, double-quoted, and fenced string forms in identifier positions are rejected.

**Acceptance Scenarios**:

1. **Given** a pattern author uses a bare identifier in a supported identifier position, **When** the pattern is validated, **Then** the identifier is accepted without any syntax change.
2. **Given** a pattern author uses a backtick-quoted identifier containing spaces or punctuation that is not valid in a bare name, **When** the pattern is validated, **Then** the identifier is accepted in that position.
3. **Given** a pattern author uses a single-quoted, double-quoted, or fenced string where an identifier is expected, **When** the pattern is validated, **Then** the pattern is rejected with the quoted form treated as unsupported in that position.

---

### User Story 2 - Apply a single label with richer text (Priority: P2)

As a person modeling labeled nodes and relationships, I want a single label to support either a bare name or a backtick-quoted name, so I can express labels with whitespace or alternate characters without splitting them into multiple labels.

**Why this priority**: Labels are a primary authoring construct, and this change directly addresses the current inability to express a single label that contains whitespace or non-bare characters.

**Independent Test**: Author patterns with one and multiple labels using both bare and backtick-quoted label names. Confirm single-label inputs with whitespace are accepted only when backtick-quoted and remain a single label.

**Acceptance Scenarios**:

1. **Given** a labeled pattern uses a bare label name, **When** the pattern is validated, **Then** the label is accepted exactly as it is today.
2. **Given** a labeled pattern uses one backtick-quoted label containing whitespace or alternate punctuation, **When** the pattern is validated, **Then** that text is accepted as one label rather than being split or rejected.
3. **Given** a labeled pattern uses a quoted form other than backticks for a label, **When** the pattern is validated, **Then** the label is rejected as unsupported syntax.

---

### User Story 3 - Keep keys JSON-friendly while tightening names (Priority: P3)

As a person authoring record and map data, I want keys to accept bare names, backtick-quoted names, and double-quoted names, so I can preserve both Cypher-style authoring and JSON-style readability while avoiding broader string forms in key positions.

**Why this priority**: Keys need a narrower but still practical set of quoting choices, and preserving double-quoted keys avoids breaking common JSON-like data authoring.

**Independent Test**: Author record and map entries with bare, backtick-quoted, and double-quoted keys. Confirm those keys are accepted and that single-quoted and fenced string keys are rejected.

**Acceptance Scenarios**:

1. **Given** a record or map entry uses a double-quoted key, **When** the entry is validated, **Then** the key is accepted without requiring conversion to another quoting style.
2. **Given** a record or map entry uses a backtick-quoted key containing whitespace or reserved punctuation, **When** the entry is validated, **Then** the key is accepted.
3. **Given** a record or map entry uses a single-quoted or fenced string key, **When** the entry is validated, **Then** the key is rejected as unsupported in key positions.

---

### Edge Cases

- A fenced multi-line string that is valid as a value MUST be rejected when used where an identifier, label, or key name is expected.
- A double-quoted string MUST remain valid for keys but MUST be rejected for identifiers and labels.
- A backtick-quoted name that contains whitespace or punctuation MUST still be treated as a single identifier, label, or key rather than being split into multiple tokens.
- Existing bare-name inputs MUST continue to be accepted everywhere they are currently valid.
- Numeric identifiers that are already supported MUST remain unchanged by this feature and MUST not expand label or key syntax unless they were already valid there.

## Requirements *(mandatory)*

This feature treats annotation syntax semantically rather than as a separate language construct: `@key(value)` contributes a property on the wrapper subject, while `@@identifier:Label` contributes the wrapper subject's identifier and labels. Together they are syntactic sugar for the corresponding subject in bracket-pattern notation.

### Functional Requirements

- **FR-001**: The language MUST continue to accept bare names in every identifier, label, and key position where they are currently valid.
- **FR-002**: The language MUST accept backtick-quoted names in identifier positions used for pattern authorship and pattern reference.
- **FR-003**: The language MUST accept backtick-quoted names as a single label, including when the label text contains whitespace or characters not permitted in a bare name.
- **FR-004**: The language MUST accept record and map keys written as bare names, backtick-quoted names, or double-quoted names.
- **FR-005**: The language MUST reject fenced multi-line strings when used in identifier, label, or key positions.
- **FR-006**: The language MUST reject single-quoted strings when used in identifier, label, or key positions.
- **FR-007**: The language MUST reject double-quoted strings when used in identifier and label positions.
- **FR-008**: The language MUST preserve existing value syntax for string content outside identifier, label, and key positions.
- **FR-009**: The language MUST preserve existing valid inputs that use bare names and double-quoted keys without requiring authors to rewrite them.
- **FR-010**: This feature MUST not broaden quoting rules for property annotation keys or tagged-content language tags.

### Key Entities *(include if feature involves data)*

- **Identifier**: A name used to define or reference a pattern element; it may be bare, backtick-quoted, or numeric where numeric identifiers are already supported.
- **Label**: A type-like name attached to a pattern element; it may be bare or backtick-quoted and must remain a single label even when quoted text contains whitespace.
- **Key**: A name used for record or map entries; it may be bare, backtick-quoted, or double-quoted.
- **Quoted Name Form**: A constrained quoting style used to preserve authoring flexibility while preventing unrelated string syntaxes from being treated as names.

### Assumptions

- Annotation sugar remains semantically equivalent to the corresponding bracket-pattern subject, even where the sugar uses narrower syntax than full `[ ... ]` notation.
- The scope of "keys" in this feature is limited to record and map entry keys.
- Property annotation keys and tagged-content language tags remain bare-name only in this feature.
- Existing support for general string literals as values remains unchanged.
- Existing support for numeric identifiers remains unchanged.

## Success Criteria *(mandatory)*

### Measurable Outcomes

- **SC-001**: 100% of acceptance examples that use bare names or backtick-quoted names in supported identifier positions are accepted during feature validation.
- **SC-002**: 100% of acceptance examples that use a single backtick-quoted label containing whitespace or alternate punctuation are accepted as one label during feature validation.
- **SC-003**: 100% of acceptance examples that use bare, backtick-quoted, or double-quoted keys are accepted during feature validation.
- **SC-004**: 100% of acceptance examples that use fenced strings, single-quoted strings, or other unsupported quoted forms in identifier, label, or key positions are rejected during feature validation.
- **SC-005**: Existing documented examples that rely on bare names and double-quoted keys continue to validate without author changes.
