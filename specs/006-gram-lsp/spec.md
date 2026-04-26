# Feature Specification: Gram language server for editors and tools

**Feature Branch**: `006-gram-lsp`  
**Created**: 2026-04-26  
**Status**: Draft  
**Input**: User description: "An LSP server for the gram grammar which can improve editors and cli tools, helping users to understand syntax and semantics"

## Clarifications

### Session 2026-04-26

- Q: How should semantic richness extend beyond bare name resolution (e.g. identifiers as references vs part of element definitions)? → A: Each identifier occurrence MUST be classified for assistance purposes as either a **reference** (use site such as a pattern reference) or **definition-introducing** (including identifiers that participate in introducing a subject-pattern **element** or other introducing construct). Hover and related explanations MUST reflect that role where the parse supports it.
- Q: What scope applies for “element definitions must appear only once”? → A: **Per file**—for each distinct **named** element-introducing identifier, the file MAY contain **zero or one** introducing site (**absence is valid**); a second introducing use of the same name in that file MUST produce semantic diagnostics. The same introducing name MAY appear in different files without violating this rule.
- Q: Do anonymous nested subject-pattern elements count toward duplicate element definitions? → A: **No**—only **named** element-introducing positions participate in the duplicate-element rule; **anonymous** nested elements (no introducing identifier attributed to that element position) MUST NOT trigger duplicate-element diagnostics regardless of how many appear.

## User Scenarios & Testing *(mandatory)*

### User Story 1 - Understand and fix syntax problems quickly (Priority: P1)

An author editing a Gram (`.gram`) file sees clear, human-readable messages when the text does not conform to the language rules, with stable locations that point to the offending span. They can correct mistakes without guessing from silent failure or generic “invalid file” feedback.

**Why this priority**: Syntax understanding is the foundation for every other assistance feature; it unblocks authors immediately.

**Independent Test**: Open or paste invalid `.gram` text in an editor connected to the language assistance; verify at least one diagnostic appears with a message and range; fix the text and verify the diagnostic clears or updates.

**Acceptance Scenarios**:

1. **Given** a `.gram` file containing a syntax error, **When** the file is analyzed, **Then** the user receives at least one diagnostic whose message describes the problem in plain language and whose range covers the relevant source span.
2. **Given** the user fixes the reported syntax issue, **When** the file is analyzed again, **Then** the prior diagnostic for that issue is no longer reported (or is replaced by an accurate follow-up if another issue remains).
3. **Given** a `.gram` file with no syntax errors, **When** the file is analyzed, **Then** no syntax-level diagnostics are reported for that file.

---

### User Story 2 - On-demand explanations at the cursor (Priority: P2)

An author positions the cursor on a construct or name and requests a short explanation of what it means in context (structure, role, or relationship to surrounding Gram). This reduces reliance on external docs for routine reading and small edits.

**Why this priority**: Directly supports “understanding semantics” in the sense of meaning-in-context for authors; builds trust before deeper navigation features.

**Independent Test**: Place the cursor on several distinct construct kinds in a sample `.gram` file; request the contextual explanation affordance; verify each response is non-empty, relevant to the position, and does not contradict the visible source.

**Acceptance Scenarios**:

1. **Given** a valid `.gram` file and a cursor on a recognizable Gram construct, **When** the user requests contextual explanation, **Then** they receive text that identifies the construct’s role or meaning at that position.
2. **Given** the cursor on whitespace or non-informative positions, **When** the user requests contextual explanation, **Then** the result is empty, a brief “nothing here” style message, or the nearest meaningful parent—behavior is consistent and documented in release notes for authors.
3. **Given** a file with syntax errors near the cursor, **When** the user requests contextual explanation, **Then** the server responds without crashing and either provides best-effort context or a clear indication that explanations are limited until syntax is fixed.
4. **Given** an identifier at a **reference** site, **When** the user requests contextual explanation, **Then** the response states in plain language that the identifier is a reference (or equivalent). **Given** an identifier at a **definition-introducing** site (including inside a subject-pattern element), **When** the user requests contextual explanation, **Then** the response states that the identifier introduces a definition and distinguishes element-style introduction from other introducing forms when applicable.

---

### User Story 3 - Navigate definitions and uses (Priority: P3)

An author jumps from a use of a name to where it is introduced, and can enumerate uses of a name they care about, within the scope the product defines for a workspace. This supports refactoring and reading larger models.

**Why this priority**: Semantic navigation (names and references) is the highest-leverage step after syntax and hover for professional editing.

**Independent Test**: In a small multi-file workspace with known definitions and references, invoke “go to definition” from a reference and “find references” from a definition; verify targets match the intended definitions and all expected references appear.

**Acceptance Scenarios**:

1. **Given** a workspace with at least two `.gram` files, a definition in one file, and a valid reference in another (according to the product’s scoping rules), **When** the user invokes navigation from the reference, **Then** the editor reveals the definition location.
2. **Given** a definition with multiple references within the supported scope, **When** the user invokes reference enumeration from the definition, **Then** all listed locations correspond to references to that definition (no duplicates beyond what the protocol allows, no obvious false positives in the fixture set).
3. **Given** ambiguous or unresolvable names under the product’s rules, **When** the user attempts navigation, **Then** the outcome is predictable: either a disambiguation list, no result with a clear editor-visible indication, or a single best match—documented as the chosen policy for authors.

---

### User Story 4 - Suggestions while typing (Priority: P4)

An author typing in a `.gram` file receives ranked suggestions appropriate to the cursor context (language keywords or constructs, and where applicable, names in scope). Accepting a suggestion inserts text that keeps the file closer to valid Gram.

**Why this priority**: Speeds authoring and teaches structure through lawful completions.

**Independent Test**: Trigger suggestions at defined fixture positions (after specific tokens, inside specific constructs); verify suggestion lists are non-empty where expected and contain at least one valid continuation for the fixture.

**Acceptance Scenarios**:

1. **Given** a cursor position where the grammar allows a bounded set of continuations, **When** the user requests suggestions, **Then** at least one offered completion is syntactically valid if accepted at that position.
2. **Given** a cursor position where name suggestions are supported, **When** the user requests suggestions, **Then** visible names respect the same scoping rules as navigation (Story 3).
3. **Given** a highly incomplete or invalid region, **When** the user requests suggestions, **Then** the server returns an empty list or safe partial results without crashing.

---

### User Story 5 - Consistent analysis for command-line workflows (Priority: P5)

A maintainer or integrator runs a command-line check on `.gram` sources (single file or folder) and sees the same categories of syntax issues (and optionally the same messages) as in the editor, so CI and local editing stay aligned.

**Why this priority**: Reduces drift between “green locally” and “red in automation”; supports teams who rely on scripts.

**Independent Test**: Run the documented check entry point on a fixture with known syntax issues; compare message intent and locations to editor diagnostics for the same file.

**Acceptance Scenarios**:

1. **Given** a `.gram` file with known syntax errors, **When** the CLI check is run, **Then** the process exits with non-success and prints or emits structured output that includes each diagnostic message and location in a machine-friendly form.
2. **Given** a clean `.gram` file, **When** the CLI check is run, **Then** the process exits with success and emits no syntax diagnostics.
3. **Given** the same file analyzed in the editor and via CLI, **When** results are compared for syntax-level issues, **Then** the set of reported syntax problems is equivalent for the supported rule set (allowing formatting differences in how locations are serialized).
4. **Given** a `.gram` file containing duplicate **element-introducing** definitions for the same name (per the clarified per-file rule), **When** the file is analyzed in the editor and via CLI, **Then** the same semantic duplicate diagnostics are reported in both channels (count and locations per file, subject to serialization formatting).

---

### Edge Cases

- Empty files, single-line files, and very large files: analysis completes or fails with a bounded, user-visible error; no unbounded hang on fixtures up to the size limit defined in assumptions.
- Partial input while typing: diagnostics update incrementally without requiring a full manual save where the editor protocol allows unsaved buffers.
- Mixed or non-UTF-8 encodings: behavior is defined by assumptions (UTF-8 only recommended); if unsupported encodings are encountered, the server reports a clear diagnostic or error.
- Workspace with no `.gram` files: opening the workspace does not crash; features degrade gracefully.
- **Duplicate element definitions (same file)**: for each distinct **named** element-introducing identifier, **at most one** introducing site per file (**zero is allowed**); a second introducing use in that file MUST yield semantic diagnostics on the duplicate sites. Cross-file reuse of the same introducing name is allowed and MUST NOT by itself trigger the duplicate-element rule.
- **Anonymous nested elements**: nested subject-pattern elements **without** an attributed introducing identifier MUST NOT be reported as duplicate-element violations, regardless of count or nesting depth.
- **Cross-file same name**: two files may each introduce the same name; “go to definition” from a reference MAY offer multiple targets or a documented disambiguation policy—consistent with FR-004 ambiguity handling.

## Requirements *(mandatory)*

### Functional Requirements

- **FR-001**: The language assistance MUST report syntax-level problems for `.gram` sources as structured diagnostics with human-readable text and source ranges.
- **FR-002**: The language assistance MUST support opening, changing, and closing `.gram` documents in an editor session without requiring a full workspace restart for routine edits.
- **FR-003**: The language assistance MUST expose contextual explanations for cursor positions on valid or mostly valid `.gram` text, as described in User Story 2.
- **FR-004**: The language assistance MUST support “go to definition” from a reference to its introducing definition, and “find references” from a definition, within a documented workspace scope (minimum: all `.gram` files under a single workspace root opened together).
- **FR-005**: The language assistance MUST offer completions at cursor positions where the Gram language permits continuations, including construct-appropriate suggestions and name suggestions where scoping is defined.
- **FR-006**: A documented command-line entry point MUST analyze `.gram` files or directories and emit syntax diagnostics with locations in a machine-friendly form, aligned with FR-001 for the supported rule set.
- **FR-007**: For any operation in FR-001–FR-011, failures MUST surface as editor-visible diagnostics, protocol-appropriate error responses, or non-zero CLI exit codes—not silent crashes.
- **FR-008**: Release-facing documentation MUST state the workspace scoping rules for navigation and completions, the encoding assumption, **per-file duplicate element-definition** behavior (**named** identifiers only; **at most one** introducing site per name per file with **absence** allowed; **anonymous** nested elements excluded), identifier **role** semantics (reference vs definition-introducing), and any intentional limitations on “semantic” features (for example, name resolution across `.gram` files in the workspace vs duplicate-element enforcement per file).
- **FR-009**: The language assistance MUST classify each analyzable identifier occurrence as **reference** (use site, including pattern references) or **definition-introducing** (including identifiers that introduce a subject-pattern **element** or other introducing construct in the Gram model). Contextual explanations (FR-003) MUST state the active role in plain language where classification is available.
- **FR-010**: The language assistance MUST enforce **at most one** **named** element-introducing definition per distinct identifier per **single** `.gram` file (**zero** introducing sites for that name are valid). If the same name appears in more than one element-introducing position in that file, every duplicate after the first MUST surface as a semantic diagnostic (severity Error unless the product explicitly documents a lower default). **Anonymous** nested subject-pattern elements without an attributed introducing identifier MUST be excluded from this rule and MUST NOT produce duplicate-element diagnostics.
- **FR-011**: The duplicate-element rule (FR-010) applies **per file only**; introducing the same name in introducing roles in different files does not violate FR-010. The CLI check (FR-006) MUST emit the same duplicate-element diagnostics as the editor for each file analyzed.

### Key Entities

- **Gram document**: A `.gram` source buffer or file subject to analysis; has path (if saved), text content, and version for incremental updates.
- **Workspace**: The set of Gram documents and roots the user opened together; defines the boundary for cross-file navigation and consistency with CLI checks when configured the same way.
- **Diagnostic**: A message, severity, and source range tied to a document; used for syntax, semantic issues (including duplicate element definitions), and other analyzable issues.
- **Symbol / name**: An introduced identifier or navigable construct, with definition and reference sites according to documented scoping rules.
- **Identifier role**: For an identifier at a given position, whether it acts as a **reference**, as **definition-introducing** (including as part of a subject-pattern element), or is **indeterminate** when the tree is too broken to classify.
- **Position / range**: Character offsets or equivalent editor coordinates used for diagnostics, hover, navigation, and completions.

## Success Criteria *(mandatory)*

### Measurable Outcomes

- **SC-001**: In a curated suite of at least ten `.gram` fixtures covering common mistakes, at least 90% of intentional syntax errors produce at least one diagnostic whose range intersects the erroneous span.
- **SC-002**: For a panel of three internal or pilot authors unfamiliar with a sample model, each completes five hover requests on valid constructs in under 30 seconds per request (including reading time), with at least four of five responses rated “helpful” or “mostly helpful” in a simple rubric.
- **SC-003**: For a two-file workspace fixture with one cross-file reference, navigation from reference to definition succeeds in 100% of trials (minimum ten repeated trials across clean restarts).
- **SC-004**: CLI and editor report the same count of syntax-level diagnostics on the same UTF-8 `.gram` inputs for the supported rule set in 100% of cases in the regression suite used for releases.
- **SC-005**: Opening a 5,000-line `.gram` file (synthetic fixture) yields first diagnostics or explicit “ready” feedback within 10 seconds on a reference developer machine configuration documented for the project.
- **SC-006**: In a regression fixture with two intentional duplicate **named** element-introducing definitions for the same identifier in one `.gram` file, 100% of duplicate introducing sites after the first receive a semantic diagnostic in both editor publish and CLI output for that file.
- **SC-007**: In a regression fixture containing only **anonymous** nested subject-pattern elements (no duplicate **named** element-introducing definitions), duplicate-element semantic diagnostic count is **zero** in both editor and CLI.

## Assumptions

- Primary encoding is UTF-8; other encodings are out of scope unless later specified.
- “Semantics” in this release means name resolution, **per-role identifier classification** (reference vs definition-introducing, including subject-pattern **elements**), **per-file** enforcement that each **named** element-introducing identifier appears **at most once** (or **absent**), with **anonymous** nested elements excluded from duplicate-element rules, structure-aware hover, and diagnostics derived from the Gram language model—not arbitrary external ontology reasoning or execution of embedded code in tagged strings.
- Editors integrate through the standard language server protocol; authors obtain the server from the same distribution channel as other Gram tooling.
- The reference developer machine for SC-005 is a current mid-range laptop with SSD and default project-recommended editor settings.
