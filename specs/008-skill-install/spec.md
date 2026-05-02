# Feature Specification: gram skill subcommand

**Feature Branch**: `008-skill-install`
**Created**: 2026-05-02
**Status**: Draft
**Input**: User description: "A new 'skill' subcommand for the gram CLI which installs an agentic skill into well-known locations. Preferably, we leverage an existing crate that knows how to install skills for a variety of agents (claude, codex, cursor, etc)"

## Background

An open standard called **SKILL.md** (from agentskills.io) has been adopted by 35+ AI coding agents including Claude Code, GitHub Copilot, Cursor, OpenAI Codex, Gemini CLI, and Amazon Kiro. A skill is a directory containing a `SKILL.md` file with YAML frontmatter (name, description, compatibility) and Markdown body text. Agents load skill metadata at startup and pull the full content only when the task matches.

This feature has two mutually reinforcing goals:

1. **CLI-first path**: A gram user runs `gram skill install` to place gram's SKILL.md into their agents.
2. **Skill-first path**: A user discovers gram's skill via a skills marketplace (skills.sh, Claude marketplace, etc.), installs it, and learns they need the gram CLI as a prerequisite — driving CLI adoption.

The gram repository itself ships the SKILL.md. The `gram skill` subcommand installs it from the bundled copy.

---

## User Scenarios & Testing *(mandatory)*

### User Story 1 - Ship a gram SKILL.md in the repository (Priority: P1)

The gram repository contains a valid `skills/gram/SKILL.md` file. This file is the skill itself — discoverable from GitHub by any skills registry or marketplace, installable by any agent-skills-compatible CLI, and bundled into the `gram` binary for offline install.

**Why this priority**: Everything else depends on having a valid, well-authored SKILL.md. Without it there is nothing to install.

**Independent Test**: Can be fully tested by running a SKILL.md validator against `skills/gram/SKILL.md` and confirming all required frontmatter fields are present, the `name` matches the directory, and the body provides meaningful gram-specific instructions for an AI agent.

**Acceptance Scenarios**:

1. **Given** the gram repository, **When** a user browses to `skills/gram/SKILL.md`, **Then** the file has valid SKILL.md frontmatter (name, description, compatibility) and body instructions for working with `.gram` files.
2. **Given** the SKILL.md `compatibility` field, **When** an agent reads it, **Then** it clearly states that the gram CLI is a prerequisite and shows how to install it (`cargo install gram-data`).
3. **Given** the SKILL.md `description` field, **When** an agent loads it at startup, **Then** the description is specific enough for the agent to know when to invoke the skill (e.g., when working with `.gram` files or graph data).

---

### User Story 2 - Install gram's skill to all present agents (Priority: P1)

A developer who already has the gram CLI wants to enable gram-aware assistance in their AI coding tools. They run a single command and gram's skill is placed into every agent present in their environment.

**Why this priority**: Core CLI-first use case. One command, all agents, zero manual path hunting.

**Independent Test**: Can be fully tested by running `gram skill install` in a directory where at least one agent's config location exists, then confirming the skill file was placed at the correct path and the SKILL.md content is intact.

**Acceptance Scenarios**:

1. **Given** Claude Code is present (`.claude/` directory or `~/.claude/` exists), **When** `gram skill install` is run, **Then** `SKILL.md` is placed at `.claude/skills/gram/SKILL.md` (project-local) and the command reports the path.
2. **Given** multiple agents are present (e.g., Claude Code, Cursor, Codex), **When** `gram skill install` is run, **Then** the skill is installed to each detected agent and the output lists each one with its install path.
3. **Given** no supported agents are detected, **When** `gram skill install` is run, **Then** the command exits with a clear message and lists the agents it looked for.
4. **Given** `--global` is passed, **When** `gram skill install --global` is run, **Then** the skill is installed to home-directory agent paths (e.g., `~/.claude/skills/gram/`) rather than project-local ones.
5. **Given** `--agent claude` is passed, **When** the command runs, **Then** only Claude Code's location receives the skill; other agents are untouched.

---

### User Story 3 - Discover gram's skill via a marketplace (Priority: P2)

A user discovers gram's skill on skills.sh, the Claude Code marketplace, or through a documentation link, and installs it with a third-party tool (e.g., `npx skills add gram-data/tree-sitter-gram`). The installed SKILL.md tells their agent that the gram CLI is a prerequisite and how to install it.

**Why this priority**: This is the skill-first discovery path — it drives CLI adoption from users who encounter gram through their agents before finding the CLI.

**Independent Test**: Can be fully tested by installing gram's skill via `npx skills add gram-data/tree-sitter-gram` and verifying the SKILL.md is placed correctly, then confirming the agent surface the compatibility/prerequisite note when gram tasks arise.

**Acceptance Scenarios**:

1. **Given** the gram repository on GitHub, **When** a user runs `npx skills add gram-data/tree-sitter-gram`, **Then** the skill is installed to the user's agents (the gram CLI is not required for this path).
2. **Given** an agent has the gram skill installed but the gram CLI is not on PATH, **When** the user asks the agent to work with a `.gram` file, **Then** the agent surfaces the prerequisite note from SKILL.md's `compatibility` field, telling the user to install `gram`.
3. **Given** the gram repository, **When** the skills.sh crawler indexes it, **Then** `gram-data/tree-sitter-gram` appears as a discoverable skill entry (automatic — no manual submission needed).

---

### User Story 4 - List and remove installed skills (Priority: P3)

A developer wants to audit or clean up gram's skill from their agents.

**Why this priority**: Lifecycle completeness. Less frequent than install but necessary for a trustworthy tool.

**Independent Test**: Can be tested by installing the skill, running `gram skill list`, confirming it appears, then running `gram skill remove` and confirming it is gone from all reported locations.

**Acceptance Scenarios**:

1. **Given** the skill is installed to one or more agents, **When** `gram skill list` is run, **Then** each installation is shown with agent name and path.
2. **Given** `gram skill remove` is run, **Then** the SKILL.md is deleted from every detected location and each removal is confirmed in the output.
3. **Given** `--agent cursor` is passed to `remove`, **Then** only Cursor's installation is removed.

---

### Edge Cases

- What if a `skills/gram/` directory already exists at the target? Overwrite `SKILL.md`, warn the user, preserve any other files.
- What if the agent's skills subdirectory does not exist yet? Create it (and any missing parent directories).
- What if the skill source file is unreadable or the bundled copy is missing? Exit with a clear error.
- What if `--agent` receives an unrecognised name? Exit with error listing supported agent names.
- Project-local vs. global: if both `.claude/` (project) and `~/.claude/` (global) exist, install to project-local unless `--global` is specified.

---

## Requirements *(mandatory)*

### Functional Requirements

**Skill content (the SKILL.md itself):**

- **FR-001**: The gram repository MUST contain a valid SKILL.md at `skills/gram/SKILL.md`.
- **FR-002**: The SKILL.md `name` field MUST be `gram` and MUST match the parent directory name.
- **FR-003**: The SKILL.md `description` MUST be specific enough for agents to invoke it when working with `.gram` files or graph data.
- **FR-004**: The SKILL.md `compatibility` field MUST state that the gram CLI is required and provide the install command (`cargo install gram-data`).
- **FR-005**: The SKILL.md body MUST include practical instructions for an AI agent working with gram notation, covering at minimum: file format overview, validation with `gram check`, and common patterns.

**`gram skill` CLI subcommand:**

- **FR-006**: The CLI MUST provide a `gram skill` subcommand with `install`, `list`, and `remove` sub-subcommands.
- **FR-007**: `gram skill install` MUST detect which supported agents are present (project-local first, then global) and install gram's SKILL.md to each one.
- **FR-008**: `gram skill install --agent <name>` MUST install to only the named agent.
- **FR-009**: `gram skill install --global` MUST install to home-directory agent locations instead of project-local ones.
- **FR-010**: The system MUST support at minimum: Claude Code, Cursor, OpenAI Codex, GitHub Copilot, Gemini CLI, and Amazon Kiro.
- **FR-011**: On install, if the destination directory does not exist, the system MUST create it.
- **FR-012**: On install, if a `SKILL.md` already exists at the target, the system MUST overwrite it and warn the user.
- **FR-013**: `gram skill list` MUST display each detected installation with agent name and absolute path.
- **FR-014**: `gram skill remove` MUST delete gram's SKILL.md from all detected installed locations (or from the `--agent`-specified location only).
- **FR-015**: After `install` and `remove`, the command MUST print a per-agent summary showing which were affected and which were skipped (with reason).
- **FR-016**: The command MUST work on macOS, Linux, and Windows.

**Discoverability:**

- **FR-017**: The gram repository structure MUST be compatible with `npx skills add gram-data/tree-sitter-gram` so users can install without the gram CLI.

### Key Entities

- **Skill**: A named directory containing `SKILL.md` with YAML frontmatter and Markdown body, following the agentskills.io open standard.
- **Agent**: A supported AI coding assistant with a known convention for where skill directories are placed (project-local and/or global).
- **AgentLocation**: The resolved filesystem path (project-local or global) where a given agent reads skills from.

---

## Success Criteria *(mandatory)*

### Measurable Outcomes

- **SC-001**: `gram skill install` places a valid SKILL.md at every detected agent's skills path in a single command invocation.
- **SC-002**: The installed SKILL.md is byte-for-byte identical to `skills/gram/SKILL.md` in the gram repository.
- **SC-003**: `gram skill install` completes in under 2 seconds regardless of how many agents are present.
- **SC-004**: The command runs without error on macOS, Linux, and Windows for all six required agent targets.
- **SC-005**: `npx skills add gram-data/tree-sitter-gram` succeeds without requiring the gram CLI to be installed.
- **SC-006**: The SKILL.md `compatibility` field causes the agent to surface the gram CLI install instruction when a user asks about `.gram` files without gram installed.

---

## Assumptions

- **Existing crate**: `agent-skills-rs` (crates.io) provides multi-agent install path resolution and installation logic. Planning should validate this crate's API covers all required agents before committing.
- **SKILL.md parsing/validation**: The `agent-skills` crate (crates.io) handles frontmatter parsing and spec validation.
- **Skill content is bundled**: The gram SKILL.md is compiled into the binary (e.g., via `include_str!`) so `gram skill install` works offline.
- **Agent detection is filesystem-based**: No process inspection or agent API calls. Detection checks for known config directory markers.
- **skills.sh discoverability is automatic**: Once `skills/gram/SKILL.md` exists in the public GitHub repo, skills.sh indexes it without manual submission.
- **No skill registry of gram's own**: gram does not host its own skill registry — the public GitHub repo is the distribution point.
- **Scope excludes**: Fetching skills from external registries, transforming or templating skill content during install, agent version detection.
