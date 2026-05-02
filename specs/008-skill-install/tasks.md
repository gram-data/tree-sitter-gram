# Tasks: gram skill subcommand

**Input**: Design documents from `specs/008-skill-install/`
**Prerequisites**: plan.md, spec.md, research.md, data-model.md, contracts/skill-subcommand.md

**Organization**: Tasks are grouped by user story to enable independent implementation and testing.

## Format: `[ID] [P?] [Story] Description`

- **[P]**: Can run in parallel (different files, no dependencies)
- **[Story]**: Which user story this task belongs to (US1–US4)

---

## Phase 1: Setup (Shared Infrastructure)

**Purpose**: Add new dependencies and create the repository-level skill directory.

- [X] T001 Add `agent-skills = "0.2"` and `agent-skills-rs = "0.3"` to `tools/gram/Cargo.toml`
- [X] T002 [P] Create directory `skills/gram/` at the repository root (the conventional path for `npx skills` discovery)
- [X] T003 [P] Create stub `skills/gram/SKILL.md` with valid but minimal frontmatter so the file exists for `include_str!` compilation

---

## Phase 2: Foundational (Blocking Prerequisites)

**Purpose**: Wire the `skill` module into the CLI. Nothing else can compile without this.

**⚠️ CRITICAL**: No user story work can begin until this phase is complete.

- [X] T004 Create `tools/gram/src/skill/mod.rs` with `SkillArgs`, `SkillCommand` enum (Install/List/Remove), `run()`, and `const SKILL_MD: &str = include_str!("../../../../skills/gram/SKILL.md")`
- [X] T005 Create empty `tools/gram/src/skill/install.rs`, `list.rs`, and `remove.rs` (each with a stub `pub fn run(args: ...) -> i32 { 0 }`) so the module compiles
- [X] T006 Add `mod skill;` and `Commands::Skill(skill::SkillArgs)` arm to `tools/gram/src/main.rs`, wiring to `skill::run(args)`
- [X] T007 Run `cargo build -p gram-data` to confirm the module compiles cleanly with the stub implementations

**Checkpoint**: `gram skill install`, `gram skill list`, and `gram skill remove` are reachable subcommands (no-ops) — foundation ready.

---

## Phase 3: User Story 1 — Ship a valid SKILL.md (Priority: P1) 🎯 MVP

**Goal**: `skills/gram/SKILL.md` exists in the repo with valid, complete frontmatter and practical instructions for AI agents working with gram notation.

**Independent Test**: Run `cargo build -p gram-data` (fails at `include_str!` if SKILL.md is malformed); also manually validate with `npx skills validate skills/gram/SKILL.md` or by parsing with `agent-skills`.

- [X] T008 [US1] Write full `skills/gram/SKILL.md` content: frontmatter with `name: gram`, `description` (≤1024 chars, specific enough to trigger on `.gram` files or graph data tasks), `license: MIT`, `compatibility` stating `cargo install gram-data` as the prerequisite, and `metadata` with author/homepage
- [X] T009 [US1] Write the SKILL.md body in `skills/gram/SKILL.md`: cover gram notation overview, how to run `gram check`, common patterns (nodes, relationships, properties), and example `.gram` snippets an agent should recognize
- [X] T010 [US1] Add a compile-time validation call in `tools/gram/src/skill/mod.rs` that invokes `agent_skills::Skill::parse(SKILL_MD)` in a `#[test]` to confirm the bundled content passes spec validation at build time

**Checkpoint**: `skills/gram/SKILL.md` is valid per the agentskills.io spec and the binary compiles with the bundled content.

---

## Phase 4: User Story 2 — Install skill to all present agents (Priority: P1)

**Goal**: `gram skill install` detects agents present in the current directory and installs `SKILL.md` to each, printing a per-agent summary.

**Independent Test**: Create a temp directory with a `.claude/` subdirectory; run `gram skill install`; confirm `.claude/skills/gram/SKILL.md` was created with the correct content.

- [X] T011 [US2] Implement `InstallArgs` in `tools/gram/src/skill/install.rs`: `--agent <NAME>` (optional, restrict to one agent) and `--global` flag (install to home-dir paths instead of project-local)
- [X] T012 [US2] Implement agent detection in `tools/gram/src/skill/install.rs` using `agent-skills-rs`: discover which of the six agents (claude, cursor, codex, copilot, gemini, kiro) have a config directory present under `cwd` (project-local) or `~` (if `--global`)
- [X] T013 [US2] Implement install logic in `tools/gram/src/skill/install.rs`: for each detected agent, create the `skills/gram/` subdirectory if absent, write `SKILL_MD` to `SKILL.md`, and record the outcome (`Installed`, `Overwritten`, `Failed`)
- [X] T014 [US2] Add overwrite handling in `tools/gram/src/skill/install.rs`: if `SKILL.md` already exists at the target path, overwrite it and print a warning line `(overwritten)` in the summary
- [X] T015 [US2] Implement `--agent` validation in `tools/gram/src/skill/install.rs`: if the provided name is not in the supported list, print the supported names and exit with code 2
- [X] T016 [US2] Implement the install summary output in `tools/gram/src/skill/install.rs` matching the contract format: `✓ claude  →  .claude/skills/gram/SKILL.md` / `  codex      not detected`
- [X] T017 [US2] Set correct exit codes in `tools/gram/src/skill/install.rs`: 0 if all detected agents succeeded (including skipped-not-detected), 1 if any I/O failure occurred, 2 for bad arguments

**Checkpoint**: `gram skill install` places a valid SKILL.md at every detected agent's path; `gram skill install --agent claude` restricts to Claude Code only; `gram skill install --global` targets home-directory paths.

---

## Phase 5: User Story 3 — Marketplace discoverability (Priority: P2)

**Goal**: The gram repository structure allows `npx skills add gram-data/tree-sitter-gram` to succeed without the gram CLI installed. The SKILL.md `compatibility` field instructs agents to install gram when needed.

**Independent Test**: Run `npx skills add gram-data/tree-sitter-gram --dry-run` after this phase and confirm it resolves the skill without error.

- [X] T018 [P] [US3] Verify `skills/gram/SKILL.md` is at the repository root path expected by `npx skills` discovery (the file from T008–T009 already satisfies this; this task is a validation checkpoint — document the result in `specs/008-skill-install/research.md`)
- [X] T019 [P] [US3] Confirm the `compatibility` field in `skills/gram/SKILL.md` contains the exact install command `cargo install gram-data` so an agent surfacing this skill can tell a user how to install the CLI prerequisite

**Checkpoint**: Third-party skill installers can discover and install gram's skill from the public GitHub repo without any gram CLI involvement.

---

## Phase 6: User Story 4 — List and remove installed skills (Priority: P3)

**Goal**: `gram skill list` shows all installed locations; `gram skill remove` deletes them.

**Independent Test**: Install the skill, run `gram skill list`, confirm output; run `gram skill remove`, confirm files are gone and `gram skill list` shows nothing.

- [X] T020 [US4] Implement `ListArgs` in `tools/gram/src/skill/list.rs`: `--global` flag mirroring install
- [X] T021 [US4] Implement list logic in `tools/gram/src/skill/list.rs`: for each of the six agents, check whether `skills/gram/SKILL.md` exists at the relevant scope path; print agent name and absolute path for each found; print "No gram skill installations found." if none
- [X] T022 [US4] Implement `RemoveArgs` in `tools/gram/src/skill/remove.rs`: `--agent <NAME>` (optional) and `--global` flag
- [X] T023 [US4] Implement remove logic in `tools/gram/src/skill/remove.rs`: for each matched agent location, delete `SKILL.md`; if the `skills/gram/` directory is now empty, remove it too; print per-agent outcome (`removed` / `not installed`)
- [X] T024 [US4] Set exit codes in `tools/gram/src/skill/remove.rs`: 0 for all outcomes including "not installed", 1 for I/O errors

**Checkpoint**: Full lifecycle works — install, list, remove — across project-local and global scopes and all six agent targets.

---

## Phase 7: Polish & Cross-Cutting Concerns

**Purpose**: Integration tests, documentation, and final validation.

- [X] T025 Create `tools/gram/tests/cli_skill.rs` with integration test `skill_install_no_agents_detected`: run `gram skill install` in a temp dir with no agent config dirs; assert exit 0 and output contains "No" or "not detected"
- [X] T026 [P] Add integration test `skill_install_project_local` to `tools/gram/tests/cli_skill.rs`: create a temp dir with `.claude/` present; run `gram skill install`; assert `.claude/skills/gram/SKILL.md` exists and its content matches `skills/gram/SKILL.md`
- [X] T027 [P] Add integration test `skill_install_unknown_agent` to `tools/gram/tests/cli_skill.rs`: run `gram skill install --agent bogus`; assert exit 2 and output lists supported agent names
- [X] T028 [P] Add integration test `skill_list_and_remove` to `tools/gram/tests/cli_skill.rs`: install to temp dir, assert list shows entry, remove, assert list shows nothing
- [X] T029 Update `tools/gram/README.md` to document the `gram skill` subcommand with install, list, and remove usage examples
- [X] T030 Run `cargo test -p gram-data` and confirm all tests pass (existing + new cli_skill tests)

---

## Dependencies & Execution Order

### Phase Dependencies

- **Phase 1 (Setup)**: No dependencies — start immediately
- **Phase 2 (Foundational)**: Depends on Phase 1 (Cargo.toml must have new deps before module compiles)
- **Phase 3–6 (User Stories)**: All depend on Phase 2 completion; US1 and US2 are both P1 and should be done before US3/US4
- **Phase 7 (Polish)**: Depends on all user story phases complete

### User Story Dependencies

- **US1 (P1)**: Depends only on Phase 2 — write the SKILL.md content
- **US2 (P1)**: Depends on US1 (needs valid SKILL.md to install); implement install subcommand
- **US3 (P2)**: Depends on US1 (file must exist at correct path); mostly validation
- **US4 (P3)**: Depends on US2 (install must work before list/remove are meaningful)

### Within Each Phase

- T004 → T005 → T006 → T007 (foundational: module → stubs → wire → build)
- T008 → T009 → T010 (US1: frontmatter → body → validation test)
- T011 → T012 → T013 → T014 → T015 → T016 → T017 (US2: args → detect → write → overwrite → validate → output → exit codes)

---

## Parallel Opportunities

### Phase 1

```
T001 (Cargo.toml deps)     T002 (create skills/gram/)     T003 (stub SKILL.md)
can all start together
```

### Phase 3 (US1)

```
T008 + T009 can be done together (frontmatter and body are independent sections of the same file)
T010 after T008+T009 (test needs valid content)
```

### Phase 7 (Polish)

```
T025, T026, T027, T028 — all test cases can be written in parallel (separate test functions)
T029 (README) — independent, can run alongside tests
```

---

## Implementation Strategy

### MVP (User Stories 1 + 2 only — ~9 tasks)

1. Complete Phase 1: Setup (T001–T003)
2. Complete Phase 2: Foundational (T004–T007)
3. Complete Phase 3: US1 — valid SKILL.md (T008–T010)
4. Complete Phase 4: US2 — install subcommand (T011–T017)
5. **STOP and VALIDATE**: run `gram skill install` in a test directory, confirm SKILL.md placed correctly
6. Tag as shippable — users can now install gram's skill to their agents

### Full Delivery (all stories)

Continue with Phase 5 (US3 discoverability validation), Phase 6 (US4 list/remove), Phase 7 (polish + tests).

### Solo Developer Order

Phase 1 → 2 → 3 → 4 → 6 → 5 → 7 (skip validation-only US3 until the end)
