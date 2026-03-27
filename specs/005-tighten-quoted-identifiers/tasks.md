# Tasks: Tighten Quoted Names

**Input**: Design documents from `/specs/005-tighten-quoted-identifiers/`  
**Prerequisites**: plan.md, spec.md, research.md, data-model.md, contracts/, quickstart.md

**Tests**: Include corpus and validation tasks because this feature changes grammar behavior and the design artifacts require executable regression coverage.

**Organization**: Tasks are grouped by user story so each story can be implemented and validated independently.

## Format: `[ID] [P?] [Story?] Description`

- **[P]**: Can run in parallel (different files, no dependency on incomplete tasks)
- **[Story]**: User story label (US1, US2, US3)
- Include exact file paths in descriptions

## Path Conventions

- **Grammar source**: `grammar.js`
- **Generated parser artifacts**: `src/parser.c`, `src/grammar.json`, `src/node-types.json`
- **Corpus tests**: `test/corpus/`
- **Canonical queries**: `queries/`
- **Zed copies**: `editors/zed/languages/gram/` synced from `queries/`
- **Language docs**: `docs/`

---

## Phase 1: Setup (Shared Context)

**Purpose**: Confirm implementation scope and touchpoints before editing grammar behavior

- [X] T001 Review `specs/005-tighten-quoted-identifiers/plan.md`, `specs/005-tighten-quoted-identifiers/research.md`, and `specs/005-tighten-quoted-identifiers/contracts/quoted-names.md` against `grammar.js`, `queries/highlights.scm`, `queries/locals.scm`, and `docs/gram-ebnf.md`

---

## Phase 2: Foundational (Blocking Prerequisites)

**Purpose**: Establish the shared quoted-name building blocks that all user stories depend on

**⚠️ CRITICAL**: No user story work should begin until this phase is complete

- [X] T002 Run baseline validation with `npx tree-sitter test` and `npm test` for `grammar.js`, `src/parser.c`, and current `test/corpus/`
- [X] T003 Implement shared quoted-name helper rules and shared name decomposition rules in `grammar.js` for backtick-quoted names, double-quoted key names, and symbol-only property annotation/tag contexts
- [X] T004 Run `npx tree-sitter generate` to refresh `src/parser.c`, `src/grammar.json`, and `src/node-types.json` from `grammar.js`

**Checkpoint**: Shared quoted-name foundations are ready; user story work can proceed

---

## Phase 3: User Story 1 - Use quoted identifiers consistently (Priority: P1) 🎯 MVP

**Goal**: Identifiers accept bare names, backtick-quoted names, and existing numeric identifiers, while rejecting broader string forms.

**Independent Test**: Validate that bare names, backtick-quoted names, and numeric identifiers parse in identifier positions, while single-quoted, double-quoted, and fenced forms fail in those positions.

### Tests for User Story 1

> **NOTE**: Update the corpus fixtures first so identifier behavior is specified before final implementation validation.

- [X] T005 [P] [US1] Update accepted and rejected identifier cases in `test/corpus/identifiers.txt` for bare, backtick-quoted, numeric, double-quoted, single-quoted, and fenced identifier forms
- [X] T006 [P] [US1] Update quoted identifier coverage in `test/corpus/text_graphs.txt` and `test/corpus/number_graphs.txt` for identifier positions outside simple node fixtures

### Implementation for User Story 1

- [X] T007 [US1] Update `_identifier` and all identifier-bearing grammar paths in `grammar.js` to accept `symbol`, backtick-quoted names, and existing `integer` identifiers only
- [X] T008 [US1] Run `npx tree-sitter generate` to refresh `src/parser.c`, `src/grammar.json`, and `src/node-types.json` after the identifier changes in `grammar.js`
- [X] T009 [US1] Run focused identifier validation with `npx tree-sitter test` for `test/corpus/identifiers.txt`, `test/corpus/text_graphs.txt`, and `test/corpus/number_graphs.txt`

**Checkpoint**: User Story 1 is complete when identifier positions accept only the intended forms and existing numeric identifiers still work.

---

## Phase 4: User Story 2 - Apply a single label with richer text (Priority: P2)

**Goal**: Labels accept bare names or one backtick-quoted label so whitespace and alternate characters can remain a single label.

**Independent Test**: Validate that bare labels and backtick-quoted labels parse as one label in node, relationship, subject-pattern, and identified-annotation label positions, while double-quoted, single-quoted, fenced, and numeric labels fail.

### Tests for User Story 2

> **NOTE**: Capture both parsing behavior and label-specific edge cases before final query/doc sync.

- [X] T010 [P] [US2] Update label acceptance and rejection cases in `test/corpus/labeled_nodes.txt` and `test/corpus/subject_pattern.txt` for bare and backtick-quoted labels versus unsupported quoted forms
- [X] T011 [P] [US2] Update label coverage in `test/corpus/labeled_relationships.txt` and `test/corpus/extended_annotations.txt` for quoted labels in relationship and `@@identifier:Label` positions

### Implementation for User Story 2

- [X] T012 [US2] Update `_label` and all label-bearing grammar paths in `grammar.js` to accept `symbol` or backtick-quoted names as a single label token
- [X] T013 [P] [US2] Update quoted-label captures in `queries/highlights.scm` so label highlighting no longer assumes `labels` always contain only `symbol`
- [X] T014 [P] [US2] Update quoted-label definition/reference captures in `queries/locals.scm` so local-definition behavior follows the new label node shapes
- [X] T015 [US2] Run `npx tree-sitter generate` to refresh `src/parser.c`, `src/grammar.json`, and `src/node-types.json` after the label changes in `grammar.js`
- [X] T016 [US2] Run focused label validation with `npx tree-sitter test` for `test/corpus/labeled_nodes.txt`, `test/corpus/labeled_relationships.txt`, `test/corpus/subject_pattern.txt`, and `test/corpus/extended_annotations.txt`

**Checkpoint**: User Story 2 is complete when a quoted label remains one label everywhere labels are allowed and query captures still classify labels correctly.

---

## Phase 5: User Story 3 - Keep keys JSON-friendly while tightening names (Priority: P3)

**Goal**: Record and map keys accept bare names, backtick-quoted names, and double-quoted names, while broader quoted forms and integer keys stop parsing as keys.

**Independent Test**: Validate that record and map keys accept bare, backtick-quoted, and double-quoted forms, while single-quoted, fenced, and integer key forms fail without affecting value-string behavior.

### Tests for User Story 3

> **NOTE**: Keep coverage focused on key positions so value-string behavior stays separate and unchanged.

- [X] T017 [P] [US3] Update key acceptance and rejection cases in `test/corpus/value_pair.txt` and `test/corpus/map_values.txt` for bare, backtick-quoted, double-quoted, single-quoted, fenced, and integer keys
- [X] T018 [P] [US3] Update record-key coverage in `test/corpus/records.txt` and `test/corpus/subject_pattern.txt` for quoted keys used in subject-attached records

### Implementation for User Story 3

- [X] T019 [US3] Add a key-specific name rule in `grammar.js` and wire `record_property` plus `map_entry` to accept bare, backtick-quoted, and double-quoted keys while leaving `property_annotation.key` unchanged
- [X] T020 [P] [US3] Update key captures in `queries/highlights.scm` so record and map keys recognize bare, backtick-quoted, and double-quoted key nodes and no longer assume integer keys remain valid
- [X] T021 [US3] Run `npx tree-sitter generate` to refresh `src/parser.c`, `src/grammar.json`, and `src/node-types.json` after the key changes in `grammar.js`
- [X] T022 [US3] Run focused key validation with `npx tree-sitter test` for `test/corpus/value_pair.txt`, `test/corpus/map_values.txt`, `test/corpus/records.txt`, and `test/corpus/subject_pattern.txt`

**Checkpoint**: User Story 3 is complete when key positions stay JSON-friendly and Cypher-friendly without accepting unrelated quoted or numeric key forms.

---

## Phase 6: Polish & Cross-Cutting Concerns

**Purpose**: Sync docs, editor copies, and final validation across all stories

- [X] T023 [P] Update `docs/gram-reference.md`, `docs/gram-ebnf.md`, and `docs/gram.ebnf` to document the implemented identifier, label, key, and annotation-sugar semantics
- [X] T024 [P] Run `scripts/prepare-zed-extension.sh` to sync `queries/highlights.scm`, `queries/locals.scm`, and `queries/injections.scm` into `editors/zed/languages/gram/`
- [X] T025 Validate the implementation examples in `specs/005-tighten-quoted-identifiers/quickstart.md` against the updated `grammar.js` and refresh that file only if the final behavior differs from the planned examples
- [X] T026 Run final validation with `npx tree-sitter generate`, `npx tree-sitter test`, and `npm test` for `grammar.js`, `src/parser.c`, `src/grammar.json`, `src/node-types.json`, and updated `test/corpus/`

---

## Dependencies & Execution Order

### Phase Dependencies

- **Phase 1 (Setup)**: No dependencies; start immediately
- **Phase 2 (Foundational)**: Depends on Phase 1; blocks all user stories
- **Phase 3 (US1)**: Depends on Phase 2 only; recommended MVP
- **Phase 4 (US2)**: Depends on Phase 2 only; logically independent from US1, but shares `grammar.js` and should be merged carefully
- **Phase 5 (US3)**: Depends on Phase 2 only; logically independent from US1 and US2, but shares `grammar.js` and should be merged carefully
- **Phase 6 (Polish)**: Depends on completion of all selected user stories

### User Story Dependencies

- **US1 (P1)**: No dependency on other user stories after foundational work
- **US2 (P2)**: No dependency on other user stories after foundational work
- **US3 (P3)**: No dependency on other user stories after foundational work

### Within Each User Story

- Update corpus fixtures before final story validation
- Update `grammar.js` before regenerating `src/parser.c`, `src/grammar.json`, and `src/node-types.json`
- Regenerate parser artifacts before running story-level validation
- Keep query updates aligned with any visible node-type changes introduced by the grammar

### Parallel Opportunities

- **Setup**: T001 only
- **Foundational**: T002 must finish before T003; T004 follows T003
- **US1**: T005 and T006 can run in parallel; T007 depends on foundational work; T008 depends on T007; T009 depends on T005, T006, and T008
- **US2**: T010 and T011 can run in parallel; T013 and T014 can run in parallel after T012 clarifies the tree shape; T015 depends on T012; T016 depends on T010, T011, T013, T014, and T015
- **US3**: T017 and T018 can run in parallel; T020 can run after T019 defines the key node shapes; T021 depends on T019; T022 depends on T017, T018, T020, and T021
- **Polish**: T023 and T024 can run in parallel; T025 can run after implemented behavior settles; T026 depends on T023, T024, and T025

---

## Parallel Example: User Story 1

```text
# After T004, split identifier fixture work:
T005: Update test/corpus/identifiers.txt
T006: Update test/corpus/text_graphs.txt and test/corpus/number_graphs.txt

# Then continue serially:
T007 -> T008 -> T009
```

---

## Parallel Example: User Story 2

```text
# Label fixture work can be split by syntax surface:
T010: Update test/corpus/labeled_nodes.txt and test/corpus/subject_pattern.txt
T011: Update test/corpus/labeled_relationships.txt and test/corpus/extended_annotations.txt

# After grammar changes land:
T013: Update queries/highlights.scm
T014: Update queries/locals.scm
```

---

## Parallel Example: User Story 3

```text
# Key fixture work can be split by container type:
T017: Update test/corpus/value_pair.txt and test/corpus/map_values.txt
T018: Update test/corpus/records.txt and test/corpus/subject_pattern.txt

# After key grammar changes land:
T020: Update queries/highlights.scm
```

---

## Implementation Strategy

### MVP First (User Story 1 Only)

1. Complete Phase 1 (T001)
2. Complete Phase 2 (T002-T004)
3. Complete Phase 3 (T005-T009)
4. **STOP and VALIDATE**: Confirm identifier behavior independently
5. Ship or demo the identifier tightening as the MVP

### Incremental Delivery

1. Setup + Foundational establish shared quoted-name rules
2. Deliver US1 for identifiers
3. Deliver US2 for labels
4. Deliver US3 for keys
5. Finish with docs, Zed sync, and full validation

### Parallel Team Strategy

1. One implementer completes Phase 2 because all stories share `grammar.js`
2. After Phase 2, fixture work for US1-US3 can be split across contributors
3. Query work can split by file after the relevant grammar story lands:
   - `queries/highlights.scm` for labels and keys
   - `queries/locals.scm` for label definitions
4. Finish with one person running sync and full validation

---

## Notes

- All tasks follow the required checklist format with task ID, optional `[P]`, optional story label, and explicit file paths
- Corpus fixtures are the primary executable contract for this grammar feature
- `property_annotation.key` stays `symbol`-only even though record/map keys widen
- `scripts/prepare-zed-extension.sh` should be the only way query updates reach `editors/zed/languages/gram/`
