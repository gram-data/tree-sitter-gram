# Tasks: Unified `gram` CLI with Extensions

**Input**: Design documents from `specs/007-unified-gram-cli/`
**Prerequisites**: plan.md ✓, spec.md ✓, research.md ✓, data-model.md ✓, contracts/ ✓, quickstart.md ✓

**Organization**: Tasks are grouped by user story to enable independent implementation and testing of each story.

## Format: `[ID] [P?] [Story] Description`

- **[P]**: Can run in parallel (different files, no dependencies on incomplete tasks)
- **[Story]**: Which user story this task belongs to (US1–US4)
- Exact file paths are included in every description

## Path Conventions

New crate lives at `tools/gram/` within the existing workspace. All source paths are relative to the repository root.

---

## Phase 1: Setup (Workspace Registration)

**Purpose**: Register the new crate and create the scaffolding that all subsequent work depends on.

- [X] T001 Add `"tools/gram"` to the `members` array in root `Cargo.toml`
- [X] T002 Create `tools/gram/Cargo.toml` with `[[bin]] name = "gram"`, edition 2021, version 0.3.6, and dependencies: clap 4.5 (features=["derive","cargo"]), serde + serde_json 1.x, reqwest 0.12 (features=["blocking"]), directories 5.x, walkdir 2.x, toml 0.8; workspace path deps for `gram-lsp` (`path = "../lsp"`) and `tree-sitter-gram`
- [X] T003 [P] Create directory structure: `tools/gram/src/extension/` and `tools/gram/tests/`

---

## Phase 2: Foundational (Blocking Prerequisites)

**Purpose**: Core CLI skeleton and shared types that MUST exist before any user story implementation can begin.

**⚠️ CRITICAL**: No user story work can begin until this phase is complete.

- [X] T004 Create `tools/gram/src/main.rs` with clap `Cli` struct: `check` subcommand (`CheckArgs` with PATHS, `-e/--expression`, `--json`, `--tree`, `--strict`), `extension` subcommand (`ExtensionSubcommand` enum for install/list/remove), and a catch-all `args: Vec<String>` for dispatch fallthrough
- [X] T005 [P] Create `tools/gram/src/types.rs` with serde-derived structs: `Severity` enum (`error`/`warning`/`information`/`hint`), `Position` (`line: u32`, `character: u32`), `Range` (`start`, `end`), `Diagnostic` (`severity`, `message`, `range`), `FileResult` (`path: String`, `diagnostics: Vec<Diagnostic>`), `CheckResult` (`schema_version: u32`, `tool: String`, `files: Vec<FileResult>`)
- [X] T006 [P] Create stub module files — each with a `pub fn run(...)` stub returning `Ok(())` — so `cargo build -p gram` succeeds: `tools/gram/src/check.rs`, `tools/gram/src/dispatch.rs`, `tools/gram/src/extension/mod.rs`, `tools/gram/src/extension/install.rs`, `tools/gram/src/extension/list.rs`, `tools/gram/src/extension/remove.rs`, `tools/gram/src/extension/registry.rs`

**Checkpoint**: `cargo build -p gram` succeeds — user story implementation can now begin in parallel.

---

## Phase 3: User Story 1 — Check gram files (Priority: P1) 🎯 MVP

**Goal**: Deliver a working `gram check` command that replaces `gram-lint` and `gram-lsp check` for all file-checking use cases.

**Independent Test**: `cargo build -p gram && ./target/debug/gram check <valid.gram>` exits 0; `gram check <invalid.gram>` exits 1 and prints an error with file name and line number.

### Implementation for User Story 1

- [X] T007 [P] [US1] Implement single-file checking in `tools/gram/src/check.rs`: read file bytes, call gram-lsp library's `analyze_source()`, collect returned diagnostics into a `FileResult`
- [X] T008 [P] [US1] Implement recursive directory traversal in `tools/gram/src/check.rs` using walkdir: collect all `*.gram` files under each directory argument, run single-file check on each
- [X] T009 [US1] Implement stdin reading (no PATH args and no `-e`) and `-e` inline expression in `tools/gram/src/check.rs`: read from `std::io::stdin()` or parse the expression string directly
- [X] T010 [US1] Implement `--json` output in `tools/gram/src/check.rs`: build `CheckResult` with `schema_version: 1` and `tool: "gram/<version>"`, serialize with `serde_json::to_string_pretty` and print to stdout
- [X] T011 [US1] Implement `--tree` flag in `tools/gram/src/check.rs`: call tree-sitter parse on the input and print the s-expression via `tree.root_node().to_sexp()`
- [X] T012 [US1] Implement exit code logic in `tools/gram/src/check.rs`: exit 0 (no errors), exit 1 (at least one error-severity diagnostic), exit 2 (invocation error); respect `--strict` by treating warnings as errors
- [X] T013 [US1] Wire `check` subcommand in `tools/gram/src/main.rs` to call `check::run()` and pass the process exit code from the result
- [X] T014 [P] [US1] Write integration tests in `tools/gram/tests/cli_check.rs` using `assert_cmd`: valid file exits 0, invalid file exits 1 with error message, directory traversal finds all files, `-e` expression, stdin pipe, `--json` output validates schema, `--tree` outputs s-expression, empty directory exits 0 with informational message

**Checkpoint**: User Story 1 is fully functional and independently testable — MVP deliverable.

---

## Phase 4: User Story 2 — Install and use extensions (Priority: P2)

**Goal**: Deliver `gram extension install/list/remove` so users can install `gram-lsp` (and future extensions) without a Rust toolchain.

**Independent Test**: `gram extension install lsp` downloads to `~/.gram/bin/gram-lsp`; `gram extension list --installed` shows `lsp`; `gram extension remove lsp` removes the binary.

> **Note**: Acceptance scenario 2 (`gram lsp stdio` dispatching to the installed binary) also requires User Story 3 (dispatch). US2 install/list/remove can be tested independently; the `gram lsp stdio` flow requires Phase 6.

### Implementation for User Story 2

- [X] T015 [P] [US2] Implement `RegistryEntry` struct and registry manifest fetching in `tools/gram/src/extension/registry.rs`: HTTP GET the manifest URL with reqwest blocking, parse `[[extension]]` TOML array into `Vec<RegistryEntry>`
- [X] T016 [P] [US2] Implement `InstalledExtension` struct (`name`, `version`, `bin_path`, `installed_at`) and `~/.gram/extensions.toml` read/write helpers in `tools/gram/src/extension/mod.rs` using the `directories` crate for home dir resolution
- [X] T017 [US2] Implement platform target triple detection in `tools/gram/src/extension/install.rs`: map `std::env::consts::OS` + `ARCH` (and optionally the build-time `TARGET` env var) to supported triples (`x86_64-unknown-linux-musl`, `aarch64-unknown-linux-musl`, `x86_64-apple-darwin`, `aarch64-apple-darwin`, `x86_64-pc-windows-msvc`)
- [X] T018 [US2] Implement GitHub Releases API query in `tools/gram/src/extension/install.rs`: fetch `https://api.github.com/repos/<github>/releases/latest` for latest or `/releases/tags/v<version>` for pinned; extract matching asset URL for the detected target triple
- [X] T019 [US2] Implement archive download + extract in `tools/gram/src/extension/install.rs`: download to a temp file, extract `.tar.gz` (Unix) or `.zip` (Windows), atomically rename the binary into `~/.gram/bin/<bin-name>`, set executable permissions (Unix), and record entry in `~/.gram/extensions.toml`
- [X] T020 [US2] Implement `~/.gram/bin/` PATH check in `tools/gram/src/extension/install.rs`: after install, check if the bin dir is on `$PATH` and print a one-time warning with the appropriate `export PATH` snippet if not
- [X] T021 [US2] Implement `gram extension list` in `tools/gram/src/extension/list.rs`: show installed extensions (from `extensions.toml`) and available extensions (from registry); support `--installed`, `--available`, and `--json` flags
- [X] T022 [US2] Implement `gram extension remove` in `tools/gram/src/extension/remove.rs`: delete `~/.gram/bin/<bin-name>`, remove the entry from `~/.gram/extensions.toml`, exit non-zero if not installed
- [X] T023 [US2] Wire all extension subcommands in `tools/gram/src/extension/mod.rs`: dispatch to `install::run`, `list::run`, `remove::run` based on the clap subcommand
- [X] T024 [P] [US2] Write integration tests for extension commands in `tools/gram/tests/cli_extension.rs`: list shows registry entries, install writes binary to temp dir (mock or real download), remove deletes binary and errors when not installed, network failure exits 1 with clear error

**Checkpoint**: User Story 2 is fully functional — extension install/list/remove work independently.

---

## Phase 5: User Story 4 — CI/CD pipeline integration (Priority: P2)

**Goal**: Enable teams to install and run `gram` in CI without a Rust toolchain via cargo-dist release artifacts.

**Independent Test**: The GitHub Actions release workflow produces `gram-<target>.tar.gz` artifacts; a fresh environment can install `gram` via the installer script and run `gram check` successfully.

### Implementation for User Story 4

- [X] T025 [US4] Configure cargo-dist in `tools/gram/Cargo.toml` `[package.metadata.dist]`: set `targets` to all 5 supported platform triples, enable installer generation, and set the install path to `~/.gram/bin/`
- [X] T026 [US4] Extend `.github/workflows/release.yml` to include `gram` in the build matrix and upload platform-specific archives to GitHub Releases following the naming convention `gram-<target-triple>.(tar.gz|zip)`
- [X] T027 [P] [US4] Remove `tools/gram-lint/` crate from workspace entirely (decision revised from deprecation-shim to immediate removal; see research.md §7)
- [X] T028 [US4] Verify in `tools/gram/src/check.rs` that the tool handles a directory containing no `.gram` files gracefully: collect zero `FileResult`s, print an informational message to stderr, and exit 0

**Checkpoint**: User Story 4 is complete — `gram` can be installed and used in CI pipelines without Rust.

---

## Phase 6: User Story 3 — Third-party sub-command dispatch (Priority: P3)

**Goal**: Enable third-party tools named `gram-<name>` to be invoked transparently via `gram <name>`, completing the extension dispatch chain.

**Independent Test**: Place a script named `gram-fmt` on `$PATH`; `gram fmt file.gram` executes it with `file.gram` as an argument and forwards its exit code.

### Implementation for User Story 3

- [X] T029 [US3] Implement `$PATH` search for `gram-<name>` binary in `tools/gram/src/dispatch.rs`: iterate `$PATH` entries, look for an executable file named `gram-<subcommand>`, return the first match
- [X] T030 [US3] Implement exec with argument and exit code forwarding in `tools/gram/src/dispatch.rs`: on Unix use `std::os::unix::process::CommandExt::exec` for true process replacement; on Windows use `Command::spawn` + `wait` and forward the exit code
- [X] T031 [US3] Implement the "unknown sub-command" error in `tools/gram/src/dispatch.rs` when no matching `gram-<name>` binary is found: print the error message from `contracts/cli-commands.md` and exit 2
- [X] T032 [US3] Ensure built-in priority in `tools/gram/src/main.rs`: `check`, `extension`, `help`, `--version`, `-V` are matched before the catch-all dispatch path is reached
- [X] T033 [P] [US3] Write integration tests for dispatch in `tools/gram/tests/cli_dispatch.rs`: PATH binary found (args forwarded, exit code passes through), no binary found (prints error + exits 2), built-in name (check) is not dispatched to PATH binary

**Checkpoint**: All user stories are independently functional — the full extension dispatch chain works end-to-end.

---

## Phase 7: Polish & Cross-Cutting Concerns

**Purpose**: Quality gates and final validation across all user stories.

- [X] T034 [P] Run `cargo test -p gram` and fix all test failures
- [X] T035 [P] Run `cargo clippy -p gram -- -D warnings` and fix all warnings
- [X] T036 Validate every `gram check` and `gram extension` scenario in `specs/007-unified-gram-cli/quickstart.md` works with the built binary
- [X] T037 [P] Verify `gram --version` outputs the correct semver from `tools/gram/Cargo.toml`
- [X] T038 Verify `cargo build` succeeds for the entire workspace (no regressions in `tools/gram-lint` or `tools/lsp`)

---

## Dependencies & Execution Order

### Phase Dependencies

- **Setup (Phase 1)**: No dependencies — start immediately
- **Foundational (Phase 2)**: Depends on Phase 1 completion — **BLOCKS all user stories**
- **User Story 1 (Phase 3, P1)**: Depends on Foundational — no dependencies on other stories
- **User Story 2 (Phase 4, P2)**: Depends on Foundational — no dependencies on US1
- **User Story 4 (Phase 5, P2)**: Depends on Foundational; full CI test requires US1 complete
- **User Story 3 (Phase 6, P3)**: Depends on Foundational; required for US2 scenario 2 (`gram lsp stdio`)
- **Polish (Phase 7)**: Depends on all desired user stories being complete

### User Story Dependencies

- **US1 (P1)**: Independent after Foundational
- **US2 (P2)**: Independent after Foundational for install/list/remove; requires US3 for `gram lsp stdio`
- **US4 (P2)**: Independent after Foundational; release automation benefits from US1 being complete
- **US3 (P3)**: Independent after Foundational; enables full US2 extension dispatch

### Within Each User Story

- Models/types before services
- Services before wiring in `mod.rs`
- Core implementation before integration tests
- Story complete before moving to next priority

### Parallel Opportunities

- Phase 1: T003 can run immediately while T001+T002 proceed
- Phase 2: T005 and T006 can run in parallel with T004
- Phase 3: T007 and T008 can run in parallel; T014 (tests) can run in parallel after T012
- Phase 4: T015 and T016 can run in parallel; T024 (tests) at end
- Phase 5: T027 can run in parallel with other US4 tasks
- Phase 6: T033 (tests) can run in parallel after T032
- Phase 7: T034, T035, T037 can all run in parallel

---

## Parallel Example: User Story 1

```bash
# Launch file-check and directory-traversal in parallel (different sub-functions):
Task T007: "Implement single-file checking in tools/gram/src/check.rs"
Task T008: "Implement directory traversal in tools/gram/src/check.rs"

# Launch after T012 completes:
Task T014: "Write integration tests in tools/gram/tests/cli_check.rs"
```

## Parallel Example: User Story 2

```bash
# Launch registry and installed-record work in parallel:
Task T015: "Implement RegistryEntry struct in tools/gram/src/extension/registry.rs"
Task T016: "Implement InstalledExtension struct in tools/gram/src/extension/mod.rs"

# After T015–T022 complete:
Task T024: "Write integration tests in tools/gram/tests/cli_extension.rs"
```

---

## Implementation Strategy

### MVP First (User Story 1 Only)

1. Complete Phase 1: Setup (T001–T003)
2. Complete Phase 2: Foundational (T004–T006) — **required, blocks everything**
3. Complete Phase 3: User Story 1 (T007–T014)
4. **STOP and VALIDATE**: `cargo test -p gram` passes for cli_check tests; run quickstart check scenarios
5. Ship or demo — developers previously using `gram-lint` can migrate immediately

### Incremental Delivery

1. Setup + Foundational → skeleton compiles
2. User Story 1 → `gram check` works → **MVP, deploy/demo**
3. User Story 2 → `gram extension install/list/remove` works → deploy/demo
4. User Story 4 → release pipeline produces artifacts → CI adoption enabled
5. User Story 3 → `gram <external-cmd>` dispatch works → full ecosystem composability
6. Polish → production quality

### Parallel Team Strategy

With multiple developers after Foundational is complete:
- Developer A: User Story 1 (check command)
- Developer B: User Story 2 (extension system, starting with registry + types)
- Developer C: User Story 3 (dispatch — short task, then helps others)

Each story completes and integrates independently; no shared-file conflicts between stories (different source files per story).

---

## Notes

- `[P]` tasks target different source files with no dependencies on incomplete tasks in the same phase
- `[US1]`–`[US4]` labels map to user stories from `specs/007-unified-gram-cli/spec.md`
- No test tasks are included by default (spec does not request TDD); integration tests are written after implementation within each story phase
- The `gram-lsp` library's `analyze_source()` is the key reuse point for US1 — verify its public API signature in `tools/lsp/src/lib.rs` before starting T007
- US3 dispatch uses `exec` (Unix) for true process replacement; use `spawn+wait` on Windows — this distinction matters for signal handling
- Atomic install in T019 (download → temp file → rename) is required by data-model.md invariant 3
