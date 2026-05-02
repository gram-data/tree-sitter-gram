# Implementation Plan: gram skill subcommand

**Branch**: `008-skill-install` | **Date**: 2026-05-02 | **Spec**: [spec.md](./spec.md)
**Input**: Feature specification from `specs/008-skill-install/spec.md`

## Summary

Add a `gram skill` subcommand that installs gram's own SKILL.md (the cross-agent open standard for AI coding assistant skills) into the correct locations for each detected agent. The gram repository ships `skills/gram/SKILL.md`; the CLI bundles this at compile time and places it into agent-specific paths on demand. Discoverability from skills marketplaces (skills.sh, Claude marketplace) is achieved by hosting the skill at the expected GitHub path, requiring no separate registry work.

## Technical Context

**Language/Version**: Rust 2021 edition, workspace version 0.3.7+
**Primary Dependencies**:
- `agent-skills 0.2.0` — parse and validate SKILL.md (Frontmatter, Skill::parse)
- `agent-skills-rs 0.3.1` — multi-agent install path resolution and installation (install_skill, InstallResult)
- `clap 4.5` (derive) — already present
**Storage**: Filesystem only — writes SKILL.md directories under project-local or `~` agent config dirs
**Testing**: `cargo test` integration tests + `assert_cmd` CLI tests (already used for extension tests)
**Target Platform**: macOS, Linux, Windows (same matrix as gram release)
**Project Type**: Single Rust workspace; new code lives in `tools/gram/`
**Performance Goals**: Install completes in <2s for up to 6 agents
**Constraints**: Offline capable — SKILL.md bundled via `include_str!`; no network call needed
**Scale/Scope**: One skill (gram's own), 6 agent targets, 3 platforms

## Constitution Check

*GATE: Must pass before implementation. Re-check after design.*

**Grammar Expressiveness and Clarity (Principle I)**:
- [N/A] This feature adds a CLI subcommand; no grammar.js changes are involved.

**Comprehensive and Illustrative Testing (Principle II)**:
- [ ] Integration tests added in `tools/gram/tests/cli_skill.rs`
- [ ] Tests cover: install to project-local path, install with --global, install --agent, list, remove
- [ ] Tests cover: no agents detected, already-installed overwrite warning
- [ ] Tests follow existing `assert_cmd` pattern used in `cli_check.rs` and `cli_extension.rs`

**Minimal Binding Examples (Principle III)**:
- [N/A] No AST structure changes; no binding example updates required.

> **Constitution verdict**: Compliant. Only Principle II applies; tests must be written alongside implementation.

## Project Structure

### Documentation (this feature)

```text
specs/008-skill-install/
├── plan.md              # This file
├── research.md          # Phase 0 output
├── data-model.md        # Phase 1 output
├── quickstart.md        # Phase 1 output
├── contracts/
│   └── skill-subcommand.md   # CLI command schema
└── tasks.md             # Phase 2 output (/speckit-tasks)
```

### Source Code

```text
skills/                          # NEW — repo-level skills directory
└── gram/
    └── SKILL.md                 # gram's own skill (bundled into binary)

tools/gram/src/
├── main.rs                      # add Commands::Skill arm
├── skill/                       # NEW — parallel to extension/
│   ├── mod.rs                   # SkillArgs, SkillCommand, run(), agent detection
│   ├── install.rs               # install subcommand
│   ├── list.rs                  # list subcommand
│   └── remove.rs                # remove subcommand
└── extension/                   # existing, unchanged

tools/gram/tests/
└── cli_skill.rs                 # NEW — integration tests
```

**Structure Decision**: Single project, new `skill/` module mirrors `extension/` module pattern exactly. The `skills/gram/SKILL.md` lives at the repo root so `npx skills add gram-data/tree-sitter-gram` finds it without any path configuration.

## Complexity Tracking

No constitution violations. No unjustified complexity.
