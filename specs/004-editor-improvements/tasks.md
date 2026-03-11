# Tasks: Editor Support and Syntax Highlighting Improvements

**Input**: Design documents from `/specs/004-editor-improvements/`  
**Prerequisites**: plan.md, spec.md, research.md, data-model.md, contracts/

**Tests**: Not requested in the feature specification; no test tasks included. Verification is manual per quickstart.md and Independent Test criteria per story.

**Organization**: Tasks are grouped by user story so each story can be implemented and verified independently.

## Format: `[ID] [P?] [Story?] Description`

- **[P]**: Can run in parallel (different files or independent edits)
- **[Story]**: User story (US1–US5)
- Include exact file paths in descriptions

## Path Conventions

- **Canonical queries**: `queries/` at repository root (highlights.scm, locals.scm, indents.scm, injections.scm)
- **Zed**: `editors/zed/languages/gram/` — synced from queries/ via script, do not edit directly
- **Docs**: `docs/tagged-strings-and-injections.md`

---

## Phase 1: Setup (Shared Infrastructure)

**Purpose**: Ensure repository is ready for query and doc work

- [X] T001 Verify `queries/` directory exists and `scripts/prepare-zed-extension.sh` copies `queries/*.scm` into `editors/zed/languages/gram/` per plan.md

---

## Phase 2: Foundational (Blocking Prerequisites)

**Purpose**: Baseline grammar and tests pass before changing queries

**⚠️ CRITICAL**: No user story work should begin until this phase is complete

- [X] T002 Run `npx tree-sitter generate`, `npx tree-sitter test`, and `npm test` at repo root to confirm baseline; fix any failing tests before editing queries

**Checkpoint**: Foundation ready — user story implementation can proceed

---

## Phase 3: User Story 1 - Improved syntax highlighting (Priority: P1) 🎯 MVP

**Goal**: Authors see definition-like vs reference identifiers styled differently; tagged-string tag and comments highlighted distinctly (FR-001, FR-002, FR-003).

**Independent Test**: Open a .gram file with subject patterns, node patterns, pattern references, and tagged strings; verify definition-like and reference identifiers use different highlight styles; verify tag vs content and `//` comments are distinct.

### Implementation for User Story 1

- [X] T003 [P] [US1] In `queries/highlights.scm` add captures for definition-like identifiers (subject in subject_pattern, node_pattern, relationship_pattern left/right/kind, identified_annotation identifier/labels) using @type or equivalent per specs/004-editor-improvements/contracts/highlights.md
- [X] T004 [P] [US1] In `queries/highlights.scm` add capture for pattern_reference identifier as @variable (or @variable.reference) and ensure it does not conflict with definition captures per contracts/highlights.md
- [X] T005 [P] [US1] In `queries/highlights.scm` add capture for tagged_string tag (symbol) as @attribute or equivalent so the tag is distinct from string content per FR-002 and contracts/highlights.md
- [X] T006 [P] [US1] In `queries/highlights.scm` add (comment) @comment for comment highlighting per FR-003 and contracts/highlights.md

**Checkpoint**: User Story 1 complete — open a .gram file and verify highlight differentiation and comment highlighting

---

## Phase 4: User Story 2 - Go to definition and highlight references (Priority: P2)

**Goal**: Authors can use “go to definition” and “highlight references” in tree-sitter–aware editors at file scope (FR-005, FR-006).

**Independent Test**: In an editor with tree-sitter locals support, open a .gram file; from a pattern_reference invoke “go to definition”; from a definition invoke “highlight references” and verify correct targets.

### Implementation for User Story 2

- [X] T007 [US2] Create `queries/locals.scm` with @local.definition (subject in subject_pattern, node_pattern, relationship_pattern left/right/kind, identified_annotation), @local.reference (pattern_reference), and optional @local.scope (gram_pattern) for file-wide scope per specs/004-editor-improvements/contracts/locals.md

**Checkpoint**: User Story 2 complete — verify go-to-definition and highlight-references in a supporting editor

---

## Phase 5: User Story 3 - Consistent indentation (Priority: P3)

**Goal**: Indentation for brackets and multi-line structures with 2 spaces per level (FR-007).

**Independent Test**: In a .gram file with nested brackets, use editor indent/format; verify 2-space step and bracket alignment.

### Implementation for User Story 3

- [X] T008 [US3] Create `queries/indents.scm` with indent captures for record `{}`, subject_pattern `[]`, node_pattern `()`, and 2-space indent per level per specs/004-editor-improvements/contracts/indents.md

**Checkpoint**: User Story 3 complete — verify indentation in an editor that uses tree-sitter indents

---

## Phase 6: User Story 4 - Language injection in tagged strings (Priority: P4)

**Goal**: Tagged string content is highlighted with the injected language; dynamic tag as language name; minimal overrides md→markdown, ts→typescript (FR-008, FR-009).

**Independent Test**: Add tagged strings with tags `sql`, `ts`, `md`; verify SQL/TypeScript/Markdown highlighting inside content and that overrides apply for md and ts.

### Implementation for User Story 4

- [X] T009 [US4] Verify and if needed update `queries/injections.scm` so overrides for md→markdown and ts→typescript appear before the dynamic rule, and both inline and fenced tagged_string forms are covered per specs/004-editor-improvements/contracts/injections.md

**Checkpoint**: User Story 4 complete — verify injection in an editor that supports tree-sitter injections

---

## Phase 7: User Story 5 - Documented conventions (Priority: P5)

**Goal**: Documentation describes well-known tags and the `::` schema convention (FR-010).

**Independent Test**: Read docs; confirm convention table for well-known tags (md, ts, date, datetime, time, sql, json, html) and that `::` is documented for type/schema slots with tagged-string values.

### Implementation for User Story 5

- [X] T010 [US5] Extend or verify `docs/tagged-strings-and-injections.md` with well-known tags convention table and `::` type/schema convention per specs/004-editor-improvements/contracts/documentation.md

**Checkpoint**: User Story 5 complete — documentation is sufficient for downstream and editor authors

---

## Phase 8: Polish & Cross-Cutting Concerns

**Purpose**: Sync Zed, validate quickstart, and cross-links

- [X] T011 Run `scripts/prepare-zed-extension.sh` from repo root to sync all `queries/*.scm` into `editors/zed/languages/gram/` and confirm script passes
- [X] T012 Run quickstart validation: `npx tree-sitter test`, `npm test`, then manual verification steps in specs/004-editor-improvements/quickstart.md
- [X] T013 [P] Add cross-links to `docs/tagged-strings-and-injections.md` from `docs/gram-reference` or `docs/gram-ebnf` if those files exist and reference tagged strings or schema

---

## Dependencies & Execution Order

### Phase Dependencies

- **Phase 1 (Setup)**: No dependencies — start immediately
- **Phase 2 (Foundational)**: Depends on Phase 1 — BLOCKS all user stories
- **Phases 3–7 (User Stories)**: Depend on Phase 2; can be done in priority order (US1 → US2 → …) or in parallel if working on different files
- **Phase 8 (Polish)**: Depends on completion of all query and doc changes (Phases 3–7)

### User Story Dependencies

- **US1 (P1)**: After Phase 2 only — no dependency on other stories
- **US2 (P2)**: After Phase 2 only — no dependency on other stories
- **US3 (P3)**: After Phase 2 only — no dependency on other stories
- **US4 (P4)**: After Phase 2 only — injections.scm may already satisfy contract
- **US5 (P5)**: After Phase 2 only — docs can be updated independently

### Within Each User Story

- US1: T003–T006 can be done in any order or in parallel (all edit highlights.scm; ensure combined result satisfies contract)
- US2–US5: Single-task phases; complete in order
- Run `scripts/prepare-zed-extension.sh` after any change to `queries/*.scm` before manual verification

### Parallel Opportunities

- Phase 1: T001 only
- Phase 2: T002 only
- Phase 3: T003, T004, T005, T006 [P] — same file but logically independent capture groups; can be implemented in one pass or split
- Phases 4–7: No parallelism within phase (one task each except US1)
- Across stories: US2 (locals.scm), US3 (indents.scm), US4 (injections.scm), US5 (docs) can be done in parallel after Phase 2
- Phase 8: T013 [P] can run in parallel with T011–T012

---

## Parallel Example: User Story 1

```text
# Option A: Single implementer — implement all four capture groups in queries/highlights.scm in one edit
T003 + T004 + T005 + T006 → one coherent update to queries/highlights.scm per contracts/highlights.md

# Option B: Split by capture type (if reviewing separately)
T003: definition-like identifiers
T004: pattern_reference as @variable
T005: tagged_string tag
T006: (comment) @comment
```

---

## Parallel Example: User Stories 2–5 After Foundation

```text
# After T002 passes, different implementers can take different stories:
Developer A: T007 (locals.scm)
Developer B: T008 (indents.scm)
Developer C: T009 (injections.scm)
Developer D: T010 (docs)
```

---

## Implementation Strategy

### MVP First (User Story 1 Only)

1. Complete Phase 1 (T001) and Phase 2 (T002)
2. Complete Phase 3 (T003–T006) — extend highlights.scm
3. Run `scripts/prepare-zed-extension.sh`
4. **STOP and VALIDATE**: Open a .gram file; verify definition vs reference, tag, and comment highlighting
5. If satisfied, MVP is done; proceed to US2–US5 as needed

### Incremental Delivery

1. Setup + Foundational → baseline ready
2. US1 (highlights) → sync Zed → verify (MVP)
3. US2 (locals) → sync → verify go-to-definition / highlight-references
4. US3 (indents) → sync → verify indentation
5. US4 (injections) → sync → verify injection
6. US5 (docs) → verify documentation
7. Polish (sync, quickstart, cross-links)

### Parallel Team Strategy

After Phase 2:

- One person: US1 (highlights) then US2 (locals)
- Another: US3 (indents) and US4 (injections)
- Another: US5 (docs)
Merge query files as needed; run prepare-zed-extension.sh once before final verification.

---

## Notes

- [P] tasks are either different files or logically independent edits to the same file
- [Story] label links each task to a user story for traceability
- No test tasks: spec does not request TDD or automated tests; use Independent Test and quickstart manual verification
- Commit after each task or after each user story checkpoint
- Always sync Zed after changing any file under `queries/`
