# Research: gram skill subcommand

**Date**: 2026-05-02 | **Branch**: `008-skill-install`

---

## Decision: Use SKILL.md open standard

**Decision**: Adopt the agentskills.io SKILL.md format as the sole skill format.

**Rationale**: SKILL.md is an open standard originated by Anthropic and now adopted by 35+ agents (Claude Code, Cursor, Codex, Copilot, Gemini CLI, Kiro, Roo Code, OpenHands, Goose, and others). Writing one SKILL.md covers the entire ecosystem. The format has YAML frontmatter (name, description, compatibility, license, metadata) and a Markdown body. Agents load only frontmatter at startup (~100 tokens) and pull the body on demand, making it efficient.

**Alternatives considered**:
- Agent-specific files per tool — ruled out; O(n) maintenance burden per new agent.
- Custom format — ruled out; no ecosystem benefit, defeats discoverability.

---

## Decision: Use `agent-skills-rs` for installation logic

**Decision**: Depend on `agent-skills-rs 0.3.1` for detecting agents and resolving install paths.

**Rationale**: The crate provides `install_skill(source, mode)` → `InstallResult`, `discover_skills()`, and `InstallConfig`, abstracting away the per-agent path logic. This means gram does not need to hardcode `~/.claude/skills/`, `~/.cursor/skills/`, etc. — the crate owns that knowledge and is versioned independently.

**Alternatives considered**:
- Hardcode paths in gram — ruled out; every new agent requires a gram release.
- Build a custom abstraction — ruled out; `agent-skills-rs` already solves this cleanly.

---

## Decision: Use `agent-skills` for SKILL.md parsing and validation

**Decision**: Depend on `agent-skills 0.2.0` for frontmatter parsing and spec validation.

**Rationale**: `Skill::parse(content)` validates the frontmatter against the spec (name format, description length, compatibility constraints). Using it to parse the bundled SKILL.md at startup catches any accidental corruption. Key types: `Skill`, `Frontmatter`, `SkillName`, `SkillDescription`, `Compatibility`.

**Alternatives considered**:
- Manual YAML parsing — ruled out; loses spec validation.
- Use `agent-skills-rs` only — ruled out; it doesn't expose parsing/validation.

---

## Decision: Bundle SKILL.md at compile time

**Decision**: Embed `skills/gram/SKILL.md` into the binary using `include_str!`.

**Rationale**: Makes `gram skill install` work offline. The binary is self-contained — no network request or file lookup required. The macro fails at compile time if the path doesn't exist, catching missing-skill errors early.

**Alternatives considered**:
- Fetch from GitHub at install time — ruled out; breaks offline use and adds network dependency.
- Read from adjacent file at runtime — ruled out; breaks after `cargo install`.

---

## Decision: skills/gram/SKILL.md at repo root for marketplace discoverability

**Decision**: Place the skill at `skills/gram/SKILL.md` in the repository root.

**Rationale**: The `npx skills` reference CLI (Vercel Labs) and skills.sh discover skills by looking for a `skills/` directory in GitHub repos. Placing gram's skill there means `npx skills add gram-data/tree-sitter-gram` works without any configuration — the skill is installable by third-party tools without requiring the gram CLI. This is the skill-first discovery path.

**Alternatives considered**:
- `tools/gram/skills/gram/SKILL.md` — ruled out; not in the conventional discovery path.
- Hosting on a separate skill registry — ruled out; unnecessary; GitHub is the source of truth.

---

## Decision: Project-local install by default, `--global` opt-in

**Decision**: Default to project-local agent paths (e.g., `.claude/skills/gram/`); add `--global` flag for home-directory paths (`~/.claude/skills/gram/`).

**Rationale**: Project-local scoping is safer — it doesn't pollute the global agent config, and is the conventional default for tools like `npx skills`. The user can always opt into global with `--global`.

**Alternatives considered**:
- Always install globally — ruled out; unexpected side effects on other projects.
- Always install project-locally — ruled out; some users want global availability.

---

## Agent install paths (reference)

| Agent | Project-local | Global |
|---|---|---|
| Claude Code | `.claude/skills/gram/SKILL.md` | `~/.claude/skills/gram/SKILL.md` |
| Cursor | `.cursor/skills/gram/SKILL.md` | `~/.cursor/skills/gram/SKILL.md` |
| OpenAI Codex | `.codex/skills/gram/SKILL.md` | `~/.codex/skills/gram/SKILL.md` |
| GitHub Copilot | `.github/skills/gram/SKILL.md` | `~/.github/skills/gram/SKILL.md` |
| Gemini CLI | `.gemini/skills/gram/SKILL.md` | `~/.gemini/skills/gram/SKILL.md` |
| Amazon Kiro | `.kiro/skills/gram/SKILL.md` | `~/.kiro/skills/gram/SKILL.md` |

Agent detection: check for presence of the agent's top-level config directory (`.claude/`, `.cursor/`, etc. project-local; or `~/.claude/`, etc. globally). `agent-skills-rs` handles this logic.

---

## SKILL.md frontmatter specification

Required fields:
- `name`: 1–64 chars, lowercase letters/numbers/hyphens, must match parent directory (`gram`)
- `description`: 1–1024 chars; describes what the skill does AND when to invoke it

Optional fields:
- `license`: MIT
- `compatibility`: states gram CLI prerequisite and install command
- `metadata`: author, version, homepage

Progressive disclosure: agents load only name+description at startup; full body loaded when task matches description. Keep body under 5000 tokens.
