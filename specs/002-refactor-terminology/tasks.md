# Tasks: Refactor Terminology

**Input**: Design documents from `/specs/001-refactor-terminology/`
**Prerequisites**: plan.md (required), spec.md (required for user stories), research.md, data-model.md, contracts/

**Tests**: Tests are NOT explicitly requested in the specification. This refactoring focuses on terminology updates and verification through existing test suite.

**Organization**: Tasks are grouped by user story to enable independent implementation and testing of each story.

## Format: `[ID] [P?] [Story] Description`

- **[P]**: Can run in parallel (different files, no dependencies)
- **[Story]**: Which user story this task belongs to (e.g., US1, US2, US3)
- Include exact file paths in descriptions

## Phase 1: Setup (Shared Infrastructure)

**Purpose**: Prepare for terminology refactoring

- [x] T001 Verify tree-sitter CLI is installed and accessible (`npx tree-sitter --version`)
- [x] T002 [P] Create backup branch or ensure current work is committed
- [x] T003 [P] Review current grammar.js structure to understand all references to `subject` rule

---

## Phase 2: Foundational (Blocking Prerequisites)

**Purpose**: Core grammar changes that MUST be complete before test/documentation updates

**⚠️ CRITICAL**: Grammar changes must be complete and parser regenerated before updating tests and documentation

- [x] T004 [US1] Rename grammar rule `subject` to `bracket` in `grammar.js` (line 19)
- [x] T005 [US1] Rename field `attributes` to `subject` in bracket rule in `grammar.js` (line 22)
- [x] T006 [US1] Update reference to `$.subject` in `_pattern_element` rule to `$.bracket` in `grammar.js` (line 17)
- [x] T007 [US1] Update reference to `$.subject` in `_sub_pattern_element` rule to `$.bracket` in `grammar.js` (line 29)
- [x] T008 [US1] Regenerate parser code by running `npx tree-sitter generate` from repository root
- [x] T009 [US1] Verify generated code in `src/node-types.json` uses `bracket` node type and `subject` field name

**Checkpoint**: Grammar updated and parser regenerated - test and documentation updates can now begin

---

## Phase 3: User Story 1 - Grammar Rules Updated (Priority: P1) 🎯 MVP

**Goal**: Grammar rules renamed and parser regenerated with new terminology

**Independent Test**: Run `npx tree-sitter generate` and verify `src/node-types.json` contains `bracket` node type with `subject` field. Verify grammar.js parses correctly.

**Checkpoint**: At this point, grammar uses new terminology and parser is regenerated. This is the MVP - core terminology change is complete.

---

## Phase 4: User Story 2 - Documentation and Examples Updated (Priority: P2)

**Goal**: All documentation files updated to use new terminology consistently

**Independent Test**: Search all documentation files for old terminology (`subject` meaning bracket, `attributes` meaning content) and verify zero matches remain. All examples demonstrate new terminology.

### Implementation for User Story 2

- [x] T010 [P] [US2] Update README.md: replace "subject" (bracket notation) with "bracket" and "attributes" (content) with "subject"
- [x] T011 [P] [US2] Update WARP.md: replace terminology references in `README.md`
- [x] T012 [P] [US2] Update AGENTS.md: replace terminology references in `AGENTS.md`
- [x] T013 [P] [US2] Update editor documentation: replace terminology in `editors/zed/README.md`
- [x] T014 [P] [US2] Review and update example gram files in `examples/data/` for terminology in comments
- [x] T015 [P] [US2] Review and update any terminology in `examples/node/inspect.js` if it references node types
- [x] T016 [P] [US2] Review and update any terminology in `examples/html/index.html` if it references node types
- [x] T017 [US2] Verify all documentation files use consistent new terminology (run comprehensive search)

**Checkpoint**: At this point, all documentation reflects new terminology. Users reading docs will see consistent terminology.

---

## Phase 5: User Story 3 - Test Files and Corpus Updated (Priority: P2)

**Goal**: All test corpus files updated with new node type and field names, tests pass

**Independent Test**: Run `npx tree-sitter test` and verify all corpus tests pass. Verify test file `subjects.txt` is renamed to `brackets.txt`.

### Implementation for User Story 3

- [x] T018 [US3] Rename test file `test/corpus/subjects.txt` to `test/corpus/brackets.txt`
- [x] T019 [P] [US3] Update expected AST outputs in `test/corpus/brackets.txt`: change `(subject` to `(bracket` and `attributes:` to `subject:`
- [x] T020 [P] [US3] Update expected AST outputs in `test/corpus/patterns.txt` if it contains subject node references
- [x] T021 [P] [US3] Update expected AST outputs in `test/corpus/graph_global.txt` if it contains subject node references
- [x] T022 [P] [US3] Update expected AST outputs in `test/corpus/annotation.txt` if it contains subject node references
- [x] T023 [P] [US3] Search all files in `test/corpus/` for `(subject` and `attributes:` and update to `(bracket` and `subject:`
- [x] T024 [US3] Run `npx tree-sitter test` and verify all tests pass
- [x] T025 [US3] Verify no old terminology remains in test corpus files (comprehensive search)

**Checkpoint**: At this point, all tests pass with new terminology. Grammar is fully validated with updated tests.

---

## Phase 6: User Story 4 - Generated Code and Bindings Updated (Priority: P3)

**Goal**: Query files, binding examples, and generated code verified with new terminology

**Independent Test**: Verify syntax highlighting queries reference `bracket` node type. Verify binding examples (if any) use new terminology. Verify generated code uses new names.

### Implementation for User Story 4

- [x] T026 [P] [US4] Update syntax highlighting query file `queries/highlights.scm`: replace `(subject)` with `(bracket)` and `attributes:` with `subject:`
- [x] T027 [P] [US4] Update editor query file `editors/zed/languages/gram/highlights.scm`: replace `(subject)` with `(bracket)` and `attributes:` with `subject:`
- [x] T028 [P] [US4] Verify `src/node-types.json` contains `bracket` node type with `subject` field (from T009, double-check)
- [x] T029 [P] [US4] Review `examples/rust/src/main.rs` for any node type references and update if needed
- [x] T030 [P] [US4] Review `examples/python/inspect.py` for any node type references and update if needed
- [x] T031 [P] [US4] Review `examples/go/inspect.go` for any node type references and update if needed
- [x] T032 [US4] Verify syntax highlighting works correctly in editor (test with sample .gram file)
- [x] T033 [US4] Run language binding tests: `npm test`, `cargo test`, `python -m pytest` to verify bindings work

**Checkpoint**: At this point, all generated code, queries, and examples use new terminology. Full refactoring is complete.

---

## Phase 7: Polish & Cross-Cutting Concerns

**Purpose**: Final verification and cleanup

- [x] T034 [P] Run comprehensive search for old terminology across entire codebase (grep for "subject" and "attributes" in context)
- [x] T035 [P] Verify no old terminology in generated code: check `src/parser.c`, `src/grammar.json` for any remaining references
- [x] T036 Run complete test suite: `npx tree-sitter test && npm test && cargo test`
- [x] T037 [P] Update `tree-sitter.json` if it contains any terminology references
- [x] T038 [P] Update `package.json` description/comments if they reference old terminology
- [x] T039 Verify quickstart.md steps work correctly (follow quickstart.md validation)
- [x] T040 Create summary of all files changed for commit message

---

## Dependencies & Execution Order

### Phase Dependencies

- **Setup (Phase 1)**: No dependencies - can start immediately
- **Foundational (Phase 2)**: Depends on Setup completion - BLOCKS all user stories
- **User Story 1 (Phase 3)**: Part of Foundational - grammar changes must complete first
- **User Stories 2-4 (Phase 4-6)**: All depend on Phase 2/3 completion (grammar must be updated first)
  - User Stories 2, 3, and 4 can proceed in parallel after grammar is updated
  - Or sequentially in priority order (US2 → US3 → US4)
- **Polish (Phase 7)**: Depends on all user stories being complete

### User Story Dependencies

- **User Story 1 (P1)**: Must complete first - grammar changes are foundational
- **User Story 2 (P2)**: Can start after US1 - Documentation updates independent of tests
- **User Story 3 (P2)**: Can start after US1 - Test updates depend on grammar but independent of docs
- **User Story 4 (P3)**: Can start after US1 - Query and example updates depend on grammar but independent of docs/tests

### Within Each User Story

- Grammar rule updates before parser regeneration
- Parser regeneration before test/documentation updates
- Test file updates before running test suite
- Query file updates before verifying syntax highlighting
- Story complete before moving to next priority

### Parallel Opportunities

- Setup tasks T002 and T003 can run in parallel
- Documentation updates (US2 tasks T010-T016) can all run in parallel
- Test corpus file updates (US3 tasks T020-T023) can run in parallel
- Query file updates and example reviews (US4 tasks T026-T031) can run in parallel
- Polish phase search tasks (T034, T035, T037, T038) can run in parallel
- User Stories 2, 3, and 4 can be worked on in parallel after US1 completes

---

## Parallel Example: User Story 2 (Documentation)

```bash
# Launch all documentation updates in parallel:
Task: "Update README.md: replace terminology"
Task: "Update WARP.md: replace terminology references"
Task: "Update AGENTS.md: replace terminology references"
Task: "Update editor documentation: replace terminology in editors/zed/README.md"
Task: "Review and update example gram files in examples/data/"
Task: "Review and update any terminology in examples/node/inspect.js"
Task: "Review and update any terminology in examples/html/index.html"
```

---

## Parallel Example: User Story 3 (Tests)

```bash
# Launch all test corpus updates in parallel:
Task: "Update expected AST outputs in test/corpus/brackets.txt"
Task: "Update expected AST outputs in test/corpus/patterns.txt"
Task: "Update expected AST outputs in test/corpus/graph_global.txt"
Task: "Update expected AST outputs in test/corpus/annotation.txt"
Task: "Search all files in test/corpus/ for old terminology"
```

---

## Implementation Strategy

### MVP First (User Story 1 Only)

1. Complete Phase 1: Setup
2. Complete Phase 2: Foundational (grammar changes + regeneration)
3. **STOP and VALIDATE**: Verify grammar.js uses new terminology, parser regenerated, node-types.json updated
4. This is the core terminology change - MVP complete!

### Incremental Delivery

1. Complete Setup + Foundational → Grammar updated (MVP!)
2. Add User Story 2 → Documentation updated → Verify consistency
3. Add User Story 3 → Tests updated → Verify all tests pass
4. Add User Story 4 → Queries and examples updated → Verify full functionality
5. Polish → Final verification

### Parallel Team Strategy

With multiple developers:

1. Team completes Setup + Foundational together (grammar changes)
2. Once grammar is updated and parser regenerated:
   - Developer A: User Story 2 (Documentation)
   - Developer B: User Story 3 (Tests)
   - Developer C: User Story 4 (Queries/Examples)
3. Stories complete and integrate independently
4. Polish phase: Team verifies everything together

---

## Notes

- [P] tasks = different files, no dependencies
- [Story] label maps task to specific user story for traceability
- Each user story should be independently completable and testable
- Grammar changes (US1) are foundational - must complete before others
- Use comprehensive search (grep) to verify no old terminology remains
- Commit after each phase or logical group
- Stop at any checkpoint to validate story independently
- Avoid: updating tests before grammar, updating docs before verifying grammar works

