# Tasks: Line-Based and End-of-Line Comments

**Input**: Design documents from `/specs/001-line-comments/`
**Prerequisites**: plan.md (required), spec.md (required for user stories), research.md, data-model.md, contracts/

**Tests**: Corpus tests are required for tree-sitter grammar changes. Tests will be written in `test/corpus/comments.txt` following tree-sitter corpus format.

**Organization**: Tasks are organized by user story to enable independent implementation and testing. Note: Both user stories share the same grammar implementation (same `//` comment rule), but are separated for clarity and testing.

## Format: `[ID] [P?] [Story] Description`

- **[P]**: Can run in parallel (different files, no dependencies)
- **[Story]**: Which user story this task belongs to (e.g., US1, US2)
- Include exact file paths in descriptions

## Path Conventions

- **Grammar project**: `grammar.js` at root, `test/corpus/` for tests, `examples/` for examples
- **Generated code**: `src/` (auto-generated, do not edit manually)

---

## Phase 1: Setup (Shared Infrastructure)

**Purpose**: Verify prerequisites and prepare for grammar modification

- [ ] T001 Verify tree-sitter CLI is installed and accessible (`npx tree-sitter --version`)
- [ ] T002 [P] Verify existing grammar tests pass (`npx tree-sitter test`)
- [ ] T003 [P] Create backup or branch checkpoint before grammar modifications

---

## Phase 2: Foundational (Blocking Prerequisites)

**Purpose**: Core grammar infrastructure that MUST be complete before user stories

**⚠️ CRITICAL**: No user story work can begin until this phase is complete

- [ ] T004 Add `extras` array to grammar.js if not present (check current grammar.js structure)
- [ ] T005 Add `comment` rule definition to grammar.js using `token(seq('//', /.*/))` pattern

**Checkpoint**: Foundation ready - comment rule infrastructure in place, user story implementation can now begin

---

## Phase 3: User Story 1 - Add Line-Based Comments (Priority: P1) 🎯 MVP

**Goal**: Enable developers to add line-based comments (entire lines starting with `//`) to gram files for documentation

**Independent Test**: Add a line comment to an existing gram file and verify the parser ignores the comment and successfully parses the gram syntax as if the comment were not present

### Tests for User Story 1

> **NOTE**: Corpus tests are required for tree-sitter grammar changes. Write tests covering line-based comment scenarios.

- [ ] T006 [P] [US1] Create corpus test file `test/corpus/comments.txt` with line-based comment test cases
- [ ] T007 [P] [US1] Add test case for standalone line comment in `test/corpus/comments.txt`
- [ ] T008 [P] [US1] Add test case for multiple line comments in `test/corpus/comments.txt`
- [ ] T009 [P] [US1] Add test case for line comment with special characters in `test/corpus/comments.txt`
- [ ] T010 [P] [US1] Add test case for line comment at file start in `test/corpus/comments.txt`
- [ ] T011 [P] [US1] Add test case for line comment at file end in `test/corpus/comments.txt`
- [ ] T012 [P] [US1] Add test case for empty line comment (`//` only) in `test/corpus/comments.txt`
- [ ] T013 [P] [US1] Add test case verifying comment markers in string literals are preserved in `test/corpus/comments.txt`

### Implementation for User Story 1

- [ ] T014 [US1] Add `comment` rule to `extras` array in `grammar.js` (if not already done in Phase 2)
- [ ] T015 [US1] Regenerate parser from grammar (`npx tree-sitter generate`)
- [ ] T016 [US1] Run corpus tests to verify line-based comments work (`npx tree-sitter test -f 'comments'`)
- [ ] T017 [US1] Verify existing tests still pass (`npx tree-sitter test`)

**Checkpoint**: At this point, User Story 1 should be fully functional - line-based comments are supported and tested

---

## Phase 4: User Story 2 - Add End-of-Line Comments (Priority: P2)

**Goal**: Enable developers to add end-of-line comments (comments after gram syntax on a line) to gram files for contextual documentation

**Independent Test**: Add an end-of-line comment after valid gram syntax on a line and verify the parser ignores the comment portion and successfully parses the gram syntax before the comment

**Note**: End-of-line comments use the same `//` rule as line-based comments, so the grammar implementation is shared. This phase focuses on testing end-of-line scenarios.

### Tests for User Story 2

- [ ] T018 [P] [US2] Add test case for end-of-line comment after node in `test/corpus/comments.txt`
- [ ] T019 [P] [US2] Add test case for end-of-line comment after relationship in `test/corpus/comments.txt`
- [ ] T020 [P] [US2] Add test case for end-of-line comment after subject in `test/corpus/comments.txt`
- [ ] T021 [P] [US2] Add test case for end-of-line comment after pattern element in `test/corpus/comments.txt`
- [ ] T022 [P] [US2] Add test case for multiple end-of-line comments in `test/corpus/comments.txt`
- [ ] T023 [P] [US2] Add test case for end-of-line comment with special characters in `test/corpus/comments.txt`
- [ ] T024 [P] [US2] Add test case for comment between pattern elements (after comma) in `test/corpus/comments.txt`
- [ ] T025 [P] [US2] Add negative test case verifying in-line comments are rejected (comment between adjacent tokens) in `test/corpus/comments.txt`

### Implementation for User Story 2

- [ ] T026 [US2] Verify end-of-line comments work with existing grammar rule (no additional grammar changes needed)
- [ ] T027 [US2] Run corpus tests to verify end-of-line comments work (`npx tree-sitter test -f 'comments'`)
- [ ] T028 [US2] Verify all existing tests still pass (`npx tree-sitter test`)

**Checkpoint**: At this point, User Stories 1 AND 2 should both work independently - both line-based and end-of-line comments are supported and tested

---

## Phase 5: Polish & Cross-Cutting Concerns

**Purpose**: Improvements that affect multiple user stories and ensure completeness

- [ ] T029 [P] Verify backward compatibility by running all existing corpus tests (`npx tree-sitter test`)
- [ ] T030 [P] Verify comment markers in string literals are preserved (test with all string literal types: single-quoted, double-quoted, backticked, tagged, fenced)
- [ ] T031 [P] Update minimal binding examples in `examples/node/inspect.js` to demonstrate comment usage
- [ ] T032 [P] Update minimal binding examples in `examples/python/inspect.py` to demonstrate comment usage
- [ ] T033 [P] Update minimal binding examples in `examples/rust/src/main.rs` to demonstrate comment usage
- [ ] T034 [P] Update minimal binding examples in `examples/go/inspect.go` to demonstrate comment usage
- [ ] T035 Run Node.js binding tests (`npm test`) to verify bindings work with comments
- [ ] T036 Verify AST equivalence: parse a gram file with comments, remove comments, parse again, compare ASTs
- [ ] T037 Update README.md or documentation to mention comment support (if documentation exists)
- [ ] T038 Run quickstart.md validation: verify examples in quickstart.md work correctly

---

## Dependencies & Execution Order

### Phase Dependencies

- **Setup (Phase 1)**: No dependencies - can start immediately
- **Foundational (Phase 2)**: Depends on Setup completion - BLOCKS all user stories
- **User Stories (Phase 3+)**: All depend on Foundational phase completion
  - User Story 1 (P1) can start after Foundational
  - User Story 2 (P2) can start after Foundational (shares grammar rule with US1, but tests are independent)
- **Polish (Final Phase)**: Depends on all desired user stories being complete

### User Story Dependencies

- **User Story 1 (P1)**: Can start after Foundational (Phase 2) - No dependencies on other stories
- **User Story 2 (P2)**: Can start after Foundational (Phase 2) - Shares grammar implementation with US1 but tests are independent

### Within Each User Story

- Tests MUST be written before implementation verification
- Grammar rule must be added before regeneration
- Regeneration must happen before running tests
- All tests must pass before story is complete

### Parallel Opportunities

- All Setup tasks marked [P] can run in parallel
- All Foundational tasks can run sequentially (T004 must complete before T005)
- All test cases for a user story marked [P] can run in parallel (they're all in the same file but can be written independently)
- User Story 1 and User Story 2 can be worked on in parallel after Foundational (they share grammar but have separate tests)
- All Polish tasks marked [P] can run in parallel

---

## Parallel Example: User Story 1

```bash
# Launch all test cases for User Story 1 together (all in same file but independent):
Task: "Add test case for standalone line comment in test/corpus/comments.txt"
Task: "Add test case for multiple line comments in test/corpus/comments.txt"
Task: "Add test case for line comment with special characters in test/corpus/comments.txt"
Task: "Add test case for line comment at file start in test/corpus/comments.txt"
Task: "Add test case for line comment at file end in test/corpus/comments.txt"
Task: "Add test case for empty line comment in test/corpus/comments.txt"
Task: "Add test case verifying comment markers in string literals are preserved in test/corpus/comments.txt"
```

---

## Implementation Strategy

### MVP First (User Story 1 Only)

1. Complete Phase 1: Setup
2. Complete Phase 2: Foundational (CRITICAL - blocks all stories)
3. Complete Phase 3: User Story 1 (line-based comments)
4. **STOP and VALIDATE**: Test User Story 1 independently
5. Verify backward compatibility
6. Deploy/demo if ready

### Incremental Delivery

1. Complete Setup + Foundational → Foundation ready
2. Add User Story 1 → Test independently → Verify backward compatibility → Deploy/Demo (MVP!)
3. Add User Story 2 → Test independently → Verify backward compatibility → Deploy/Demo
4. Polish phase → Update examples → Final validation → Deploy
5. Each story adds value without breaking previous stories

### Parallel Team Strategy

With multiple developers:

1. Team completes Setup + Foundational together
2. Once Foundational is done:
   - Developer A: User Story 1 (line-based comments)
   - Developer B: User Story 2 (end-of-line comments) - can start in parallel since grammar rule is shared
3. Stories complete and integrate independently
4. Team works on Polish phase together

---

## Notes

- [P] tasks = different files or independent test cases, no dependencies
- [Story] label maps task to specific user story for traceability
- Each user story should be independently completable and testable
- Grammar rule is shared between US1 and US2 (same `//` pattern), but tests are separate
- Corpus tests follow tree-sitter format: "source ===> tree" sections
- Always regenerate parser (`npx tree-sitter generate`) after grammar changes
- Always run full test suite (`npx tree-sitter test`) after changes to verify backward compatibility
- Comments in `extras` don't change AST structure, so bindings don't need code changes (only example updates)
- Avoid: editing generated files in `src/`, breaking existing tests, forgetting to regenerate parser

