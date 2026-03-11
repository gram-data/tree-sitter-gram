# Feature Specification: Editor Support and Syntax Highlighting Improvements

**Feature Branch**: `004-editor-improvements`  
**Created**: 2025-03-11  
**Status**: Draft  
**Input**: User description: "editor improvements as described in the proposals/editor-improvements.md document"

## Clarifications

### Session 2025-03-11

- Q: Should references resolve at file-only scope or also within subject-pattern scope? → A: File-only scope.
- Q: Should the spec call out a primary target (e.g. schema-style .gram) or treat all .gram files equally? → A: All .gram files (no primary target).
- Q: Should the spec add a glossary mapping spec terms to the example's terminology? → A: No glossary; example is illustrative only.
- Q: What indent width or style should the spec require for "consistent indentation"? → A: 2 spaces.
- Q: Should the spec list a minimal set of injection overrides for testability? → A: List minimal set in spec.

## User Scenarios & Testing *(mandatory)*

### User Story 1 - Improved syntax highlighting for .gram files (Priority: P1)

Authors editing Gram (`.gram`) files see clearer visual distinction between defining identifiers (subjects, nodes, relationships, annotations) and references to them. Tagged-string tags (e.g. `sql`, `ts`) are highlighted distinctly from their content, and comments are highlighted when the grammar exposes them.

**Why this priority**: Core editing experience; enables readers to scan structure and intent without an LSP.

**Independent Test**: Open a .gram file with mixed definitions and references; verify definition-like identifiers and references use different highlight styles; verify tagged-string tag vs content and comments are distinct.

**Acceptance Scenarios**:

1. **Given** a .gram file with subject patterns, node patterns, and pattern references, **When** the file is opened in an editor using the grammar’s highlight queries, **Then** definition-like identifiers and reference identifiers use different highlight styles.
2. **Given** a .gram file containing tagged strings (e.g. `sql\`SELECT 1\``), **When** the file is opened, **Then** the tag (`sql`) is highlighted distinctly from the string content.
3. **Given** the grammar exposes a named `comment` node, **When** comments are present in a .gram file, **Then** they are captured and highlighted as comments.

---

### User Story 2 - Go to definition and highlight references (Priority: P2)

Authors can use “go to definition” and “highlight references” for identifiers in tree-sitter–aware editors (e.g. Neovim, Helix, Emacs) without an LSP. Definitions are where an identifier is introduced (subject in subject pattern, identifier in node pattern, subject in relationship arrows, identifier in identified annotation); references are where an identifier is used in a pattern reference.

**Why this priority**: High value for navigation and refactoring; depends on a single canonical locals query set.

**Independent Test**: In an editor that supports tree-sitter locals, open a .gram file, place cursor on a reference, invoke “go to definition”; place cursor on a definition, invoke “highlight references.” Verify correct targets.

**Acceptance Scenarios**:

1. **Given** a .gram file with at least one subject/node/relationship definition and one pattern reference to it, **When** the author places the cursor on the reference and invokes “go to definition”, **Then** the editor jumps to the corresponding definition.
2. **Given** a .gram file with a definition and multiple references, **When** the author places the cursor on the definition and invokes “highlight references”, **Then** all references to that definition are visually highlighted.
3. **Given** file-level scope, **When** multiple definitions could match a name, **Then** references resolve to a matching definition in the file (file-wide scope; no subject-pattern scoping).

---

### User Story 3 - Consistent indentation (Priority: P3)

Authors get consistent indentation for brackets and multi-line structures (2 spaces per level) so that structure is easy to read and maintain.

**Why this priority**: Improves readability and reduces manual formatting; no semantic impact.

**Independent Test**: Create or open a .gram file with nested brackets and multi-line constructs; use editor auto-indent; verify indentation follows defined rules.

**Acceptance Scenarios**:

1. **Given** a .gram file with nested bracket structures, **When** the author uses editor indentation features (e.g. indent selection, new line), **Then** indentation aligns with the defined indentation rules.
2. **Given** multi-line patterns or records, **When** the author inserts new lines or reformats, **Then** indent depth reflects the current nesting level.

---

### User Story 4 - Language injection in tagged strings (Priority: P4)

Authors see syntax highlighting for the injected language inside tagged string content (e.g. SQL inside `sql\`...\``, TypeScript inside `ts\`...\``). Well-known tags (e.g. `md`, `ts`, `sql`, `json`, `html`) are mapped to the appropriate language where needed (e.g. `md` → markdown, `ts` → typescript); other tags use the tag name as the language identifier when the editor supports it.

**Why this priority**: Makes embedded content readable and consistent with standalone files.

**Independent Test**: Add tagged strings with known tags (`sql`, `ts`, `md`); verify content is highlighted with the expected language; verify overrides (e.g. `md` → markdown) work.

**Acceptance Scenarios**:

1. **Given** a tagged string whose tag matches a common parser name (e.g. `sql`, `json`, `html`), **When** the file is opened in an editor that supports dynamic injection, **Then** the content is highlighted using that language (language is captured from the tag; no pre-defined set).
2. **Given** a tagged string with a tag that does not match a parser name (e.g. `md`, `ts`), **When** an override from the minimal set applies (md→markdown, ts→typescript), **Then** the content is highlighted with the overridden language.
3. **Given** a tagged string with an unknown or unmapped tag, **When** no parser is available, **Then** the content may be plain or fall back to a default; the grammar and query set do not require enumerating every possible tag.

---

### User Story 5 - Documented conventions for downstream and editors (Priority: P5)

Downstream consumers and editor integrations have clear documentation for tagged strings, well-known tags, and the `::` schema convention so they can implement consistent behavior without changing the core grammar.

**Why this priority**: Enables ecosystem consistency and reduces support burden; no new grammar rules.

**Independent Test**: Read the documentation; verify it describes well-known tags (e.g. md, ts, date, datetime, time, sql, json, html) and the convention that `::` denotes type/schema slots with tagged-string values.

**Acceptance Scenarios**:

1. **Given** a maintainer or editor author, **When** they consult the documentation, **Then** they find a convention table (or equivalent) for well-known tags and how to map them to parsers.
2. **Given** the same audience, **When** they need to handle schema/type slots, **Then** they find that `::` is documented as the convention for type/schema and that values are often tagged strings (e.g. `ts`, `SQL`).

---

### Edge Cases

- Unknown or custom tag names: injection may have no parser; documentation should state that editors can add their own tag → parser mappings.
- Malformed or partial structures: highlight and indent queries should not crash; errors remain visible (e.g. existing `ERROR` capture).
- Multiple definitions with the same name in the file: references resolve to any matching definition in the file (file-wide scope).
- Empty or minimal tagged string content: injection still applies so that when content is added, highlighting is correct.

## Requirements *(mandatory)*

### Functional Requirements

- **FR-001**: The highlight query set MUST distinguish definition-like identifiers (subject, node, relationship, annotation definitions) from reference identifiers (pattern references) so they can be styled differently.
- **FR-002**: The highlight query set MUST capture the tag of a tagged string separately from its content so the tag can be highlighted distinctly.
- **FR-003**: If the grammar exposes a named `comment` node, the highlight query set MUST capture it for comment highlighting.
- **FR-004**: There MUST be a single canonical highlight query file consumed by the Zed extension via the existing sync mechanism (no duplicate maintenance).
- **FR-005**: A locals query set MUST define `@local.definition` for identifiers that define (subject in subject pattern, identifier in node pattern, subject in relationship arrows, identifier in identified annotation) and `@local.reference` for pattern-reference identifiers.
- **FR-006**: The locals query set MAY define `@local.scope` at file level so that references resolve to definitions within the same file.
- **FR-007**: An indentation query set MUST define indentation for brackets and multi-line structures so tree-sitter–aware editors can apply consistent indent; indent width is 2 spaces per level.
- **FR-008**: An injection query set MUST support dynamic injection: capture the tag symbol as the injection language name and the tagged string body as the injection content. The language is not pre-defined; it is taken from the tag. Both forms (inline e.g. `` tag`content` `` and multiline ``` ```tag\ncontent\n``` ```) are supported with the same semantics (one tag, one content region).
- **FR-009**: The injection query set MUST provide overrides only when the tag text does not match the editor’s parser name (e.g. `md` → markdown, `ts` → typescript). The spec defines a minimal override set for testability: `md` → markdown, `ts` → typescript. Tags that already match the parser name (e.g. `sql`, `json`, `html`) need no override. Additional overrides (e.g. `zod`) may be documented or added by editors without changing the spec.
- **FR-010**: Documentation MUST describe well-known tags (e.g. md, ts, date, datetime, time, sql, json, html) as a convention table and MUST document that `::` is used for type/schema slots with values often given as tagged strings.

### Key Entities

- **Identifier**: A symbol, string literal, or integer used as subject/node/relationship identity, annotation identity/labels, pattern reference, or record/map key; has a role (definition vs reference) for highlighting and navigation.
- **Tagged string**: A construct with a tag (symbol) and content (string content). The tag is captured as the injection language (not pre-defined); the content is captured for injection. Both inline (e.g. `` tag`content` ``) and multiline (``` ```tag\ncontent\n``` ```) forms have the same semantics. Overrides apply only when the tag does not match the editor’s parser name (e.g. `md` → markdown).
- **Scope**: A region (the file) within which references resolve to definitions; used by locals for “go to definition” and “highlight references.”
- **Well-known tag**: A documented convention for tag names (e.g. md, ts, sql) and suggested or standard parser mappings; not enforced by the grammar.

## Success Criteria *(mandatory)*

### Measurable Outcomes

- **SC-001**: Authors can visually distinguish definitions from references in .gram files without using “go to definition.”
- **SC-002**: In supported editors, authors can complete “go to definition” from a reference to the correct definition in under two actions (e.g. key chord or command).
- **SC-003**: In supported editors, “highlight references” from a definition highlights all and only the references that resolve to that definition within the defined scope.
- **SC-004**: Indentation in .gram files follows a single documented set of rules (2 spaces per level) so that nested brackets and multi-line structures align consistently.
- **SC-005**: Tagged string content is highlighted with the expected language for well-known tags (and overrides) in editors that support tree-sitter injection.
- **SC-006**: Downstream and editor implementers can implement tag and schema behavior using documentation alone, without changing the core grammar.

## Assumptions

- The grammar already supports tagged strings with any symbol as tag; no grammar change is required for tag enumeration.
- The grammar already allows `::` in record properties; no grammar change is required for the schema convention.
- Tree-sitter query semantics for `@local.definition`, `@local.reference`, `@local.scope`, and injection captures (`@injection.language`, `@injection.content`) are used as intended by supporting editors.
- Editors that do not support locals or injection will still benefit from improved highlights and indentation where they consume the same query files.
- Scope is file-wide only; references resolve to definitions anywhere in the file.
- All .gram files are in scope equally; no primary file type or style (e.g. schema-style) is designated; highlights, locals, indentation, and injection apply to every .gram file the same way.
- Example .gram files (e.g. example.schema.gram) are illustrative only; Key Entities and spec terminology are canonical; no normative glossary mapping to example terms is required.
