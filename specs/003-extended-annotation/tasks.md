# Tasks: Extended Annotation (Identifiers and Labels)

**Input**: Design documents from `/specs/003-extended-annotation/`
**Prerequisites**: plan.md (required), spec.md (required for user stories), research.md, data-model.md, contracts/

**Tests**: Corpus tests are included; the feature specification requires each form to be validated by a test suite (SC-002).

**Organization**: Tasks are grouped by user story to enable independent implementation and testing of each story.

## Format: `[ID] [P?] [Story] Description`

- **[P]**: Can run in parallel (different files, no dependencies)
- **[Story]**: Which user story this task belongs to (e.g. US1, US2, US3, US4)
- Include exact file paths in descriptions

## Path Conventions

- Repository root: `grammar.js`, `src/`, `test/corpus/`, `bindings/`, `examples/`
- All paths are relative to the repository root unless stated otherwise

---

## Phase 1: Setup (Shared Infrastructure)

**Purpose**: Verify environment and branch so grammar work can proceed

- [ ] T001 Verify current branch is `003-extended-annotation` and repository root contains `grammar.js`
- [ ] T002 Verify Tree-sitter CLI and Node.js: run `npx tree-sitter --version` and `node --version` from repository root
- [ ] T003 [P] Verify existing corpus passes: run `npx tree-sitter test` from repository root (baseline before changes)

---

## Phase 2: Foundational (Blocking Prerequisites)

**Purpose**: Grammar and parser changes that MUST be complete before any user story validation. All `@@` vs `@` and annotation rule structure is implemented here.

**⚠️ CRITICAL**: No user story corpus validation can succeed until this phase is complete.

- [ ] T004 In `grammar.js` set `annotations` to enforce stacking: `choice(seq($.identified_annotation, repeat($.property_annotation)), repeat1($.property_annotation))` so at most one `@@` (first) and zero or more `@`; at least one annotation total
- [ ] T005 In `grammar.js` add `property_annotation` rule: `seq("@", field("key", $.symbol), "(", field("value", $._value), ")")`
- [ ] T006 In `grammar.js` add `identified_annotation` rule: `seq("@@", field("header", $.annotation_header))` only (no parentheses, no body; body is the parent `annotated_pattern.elements` that follows the whole stack)
- [ ] T007 In `grammar.js` add `annotation_header` rule as a choice of: (1) identifier only, (2) labels only, (3) identifier then labels; reuse `_identifier` and `labels`; use descriptive field names so AST is clear
- [ ] T008 Run `npx tree-sitter generate` from repository root to regenerate `src/parser.c` and `src/node-types.json`
- [ ] T009 Create `test/corpus/extended_annotations.txt` with corpus file header and delimiter structure (e.g. first `====================` block) so subsequent story phases can add cases

**Checkpoint**: Parser accepts `@@` and `@` and produces distinct annotation nodes; corpus file exists. User story phases add and validate specific forms.

---

## Phase 3: User Story 1 - Annotations with an identifier (Priority: P1) 🎯 MVP

**Goal**: Authors can write `@@p (a)` and `@@r1 (a)-[r]->(b)` (identifier as short name / pseudo-id); the annotation header is recognized as identifier only and the body as the annotated element. Property-like terms (e.g. verified) use `@verified(true)`, not `@@verified`.

**Independent Test**: Parse a document containing `@@p (a)` and `@@r1 (a)-[r]->(b)`; confirm AST has identified_annotation nodes with header containing identifier and body containing node or path.

### Corpus tests for User Story 1

- [ ] T010 [P] [US1] Add positive corpus case for `@@p (a)` (identifier-only) with expected tree in `test/corpus/extended_annotations.txt`
- [ ] T011 [P] [US1] Add positive corpus case for `@@r1 (a)-[r]->(b)` (identifier-only wrapping relationship; use short name / pseudo-id like r1, not property-like terms) with expected tree in `test/corpus/extended_annotations.txt`
- [ ] T012 [US1] Run `npx tree-sitter test -f extended_annotations` from repository root and fix grammar or expected trees until US1 cases pass

**Checkpoint**: User Story 1 is fully testable; identifier-only `@@` form parses and corpus passes.

---

## Phase 4: User Story 2 - Annotations with labels only (Priority: P2)

**Goal**: Authors can write `@@:L (a)` and `@@::Label (a)`; the annotation header is recognized as labels only (no identifier).

**Independent Test**: Parse documents containing `@@:L (a)` and `@@::Label (a)`; confirm AST has identified_annotation with header containing labels only.

### Corpus tests for User Story 2

- [ ] T013 [P] [US2] Add positive corpus case for `@@:L (a)` (labels-only) with expected tree in `test/corpus/extended_annotations.txt`
- [ ] T014 [P] [US2] Add positive corpus case for `@@::Label (a)` or multiple labels if supported with expected tree in `test/corpus/extended_annotations.txt`
- [ ] T015 [US2] Run `npx tree-sitter test -f extended_annotations` from repository root and fix grammar or expected trees until US2 cases pass

**Checkpoint**: User Stories 1 and 2 are independently testable; labels-only `@@` form parses and corpus passes.

---

## Phase 5: User Story 3 - Annotations with identifier and labels (Priority: P3)

**Goal**: Authors can write `@@p:L (a)`; the annotation header is recognized as both identifier and labels in subject order.

**Independent Test**: Parse a document containing `@@p:L (a)`; confirm AST has identified_annotation with header containing both identifier and labels.

### Corpus tests for User Story 3

- [ ] T016 [P] [US3] Add positive corpus case for `@@p:L (a)` (identifier and labels) with expected tree in `test/corpus/extended_annotations.txt`
- [ ] T017 [US3] Run `npx tree-sitter test -f extended_annotations` from repository root and fix grammar or expected trees until US3 cases pass

**Checkpoint**: User Stories 1–3 are independently testable; identifier+labels `@@` form parses and corpus passes.

---

## Phase 6: User Story 4 - Property-style annotations (Priority: P4)

**Goal**: Single `@` remains property-style (key with value); existing `@desc (a)` and `@desc("text")` parse as property_annotation; no regression on existing annotation usage.

**Independent Test**: Parse documents with `@desc("historic route") (a)-->(b)` and existing corpus files that use `@key(value)`; confirm they parse as property-style and existing corpus tests still pass.

### Corpus tests for User Story 4

- [ ] T018 [P] [US4] Add positive corpus case for `@desc (a)` (property key with symbol value) in `test/corpus/extended_annotations.txt`
- [ ] T019 [P] [US4] Add positive corpus case for `@desc("historic route") (a)-->(b)` (property key with string value before path) in `test/corpus/extended_annotations.txt`
- [ ] T020 [US4] Run full `npx tree-sitter test` from repository root and fix any regressions in existing corpus (e.g. `test/corpus/annotation.txt`, `test/corpus/node_annotations.txt`, `test/corpus/relationship_annotations.txt`)

**Checkpoint**: All four annotation forms (identifier-only, labels-only, identifier+labels, property-style) are validated; no regressions on existing single-`@` usage.

---

## Phase 7: Polish & Cross-Cutting Concerns

**Purpose**: Edge cases, examples, bindings, and full suite validation.

- [ ] T021 [P] Add negative or edge-case corpus example for invalid empty header `@@ (a)` in `test/corpus/extended_annotations.txt` (expect parse error or defined invalid structure per spec)
- [ ] T022 Run `npx tree-sitter test` and `npm test` from repository root; ensure all corpus and binding tests pass
- [ ] T023 [P] If AST node or field names for annotations changed, update parsing/traversal code in `examples/` to handle `identified_annotation` and `property_annotation` (list paths in examples that reference annotations)
- [ ] T024 [P] If AST changed, update or add binding tests in `bindings/node/` (or other bindings) that assert annotation node kinds and header/body fields
- [ ] T025 Validate quickstart steps: follow `specs/003-extended-annotation/quickstart.md` implementation steps and confirm grammar reference matches implemented syntax

---

## Dependencies & Execution Order

### Phase Dependencies

- **Setup (Phase 1)**: No dependencies — can start immediately
- **Foundational (Phase 2)**: Depends on Setup — BLOCKS all user story validation
- **User Stories (Phase 3–6)**: All depend on Foundational completion. US2–US4 depend on the same grammar; each story adds corpus cases and re-runs tests. Stories can be implemented in order P1→P2→P3→P4.
- **Polish (Phase 7)**: Depends on all user story phases complete

### User Story Dependencies

- **User Story 1 (P1)**: Can start after Foundational (Phase 2). No dependency on other stories; adds identifier-only corpus cases.
- **User Story 2 (P2)**: Can start after Foundational. Same grammar; adds labels-only corpus cases.
- **User Story 3 (P3)**: Can start after Foundational. Same grammar; adds identifier+labels corpus cases.
- **User Story 4 (P4)**: Can start after Foundational. Verifies property_annotation and backward compatibility; adds property-style corpus cases and full regression run.

### Within Each User Story

- Add corpus cases (with expected trees) before or with the run step
- Run `npx tree-sitter test -f extended_annotations` (or full test) and fix until passing
- Story complete when its corpus cases pass and independent test criteria are met

### Parallel Opportunities

- Phase 1: T003 [P] can run after T001–T002
- Phase 2: T009 (create corpus file) can run after T008
- Phase 3: T010 and T011 [P] can run in parallel (same file but different line ranges; or sequential to avoid merge conflicts)
- Phase 4: T013 and T014 [P] can run in parallel
- Phase 7: T021, T023, T024 [P] can run in parallel after T020

---

## Parallel Example: User Story 1

```bash
# Add both US1 corpus cases (can be done in one edit or two):
# Task T010: Add @@p (a) source ===> tree in test/corpus/extended_annotations.txt
# Task T011: Add @@r1 (a)-[r]->(b) source ===> tree in test/corpus/extended_annotations.txt

# Then run (sequential):
# Task T012: npx tree-sitter test -f extended_annotations
```

---

## Implementation Strategy

### MVP First (User Story 1 Only)

1. Complete Phase 1: Setup
2. Complete Phase 2: Foundational (grammar + generate + corpus file)
3. Complete Phase 3: User Story 1 (identifier-only corpus + test)
4. **STOP and VALIDATE**: Run `npx tree-sitter test -f extended_annotations`; confirm `@@p (a)` and `@@r1 (a)-[r]->(b)` pass
5. Demo: show parsing of identifier-only extended annotations

### Incremental Delivery

1. Setup + Foundational → Parser supports `@@` and `@`; corpus file exists
2. Add US1 → Identifier-only validated (MVP)
3. Add US2 → Labels-only validated
4. Add US3 → Identifier+labels validated
5. Add US4 → Property-style and regression validated
6. Polish → Edge cases, examples, bindings, full suite

### Single-Developer Order

Execute phases sequentially: Setup → Foundational → US1 → US2 → US3 → US4 → Polish. Within Foundational, T004–T007 are sequential (same file); T008–T009 after. Within each story, add corpus then run test.

---

## Notes

- [P] tasks use different files or non-overlapping edits where possible; same-file edits (e.g. multiple corpus blocks) may be done in one commit
- [Story] label maps task to spec user story for traceability
- Each user story is independently testable via its corpus cases and independent test criteria in the spec
- Commit after each task or logical group (e.g. after T008, after T012)
- Stop at any checkpoint to validate that story’s acceptance criteria
- Avoid: vague tasks; editing the same grammar rule from two stories (grammar is in Foundational only)
