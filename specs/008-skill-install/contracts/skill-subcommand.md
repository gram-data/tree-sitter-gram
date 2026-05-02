# CLI Contract: gram skill

**Branch**: `008-skill-install` | **Date**: 2026-05-02

---

## Command Schema

```
gram skill <SUBCOMMAND> [OPTIONS]
```

### `gram skill install`

Install gram's SKILL.md into detected agent locations.

```
gram skill install [OPTIONS]

Options:
  --agent <NAME>   Install to a specific agent only.
                   Supported: claude, cursor, codex, copilot, gemini, kiro
  --global         Install to home-directory agent paths instead of project-local
  -h, --help       Print help
```

**Behavior**:
- With no options: detects all present agents in the current directory (project-local) and installs to each.
- `--global`: detects agents in home directory paths and installs to each.
- `--agent <name>`: restricts detection and installation to the named agent.
- Unknown `--agent` value: exits 1, prints supported agent list.
- No agents detected: exits 0, prints advisory message.
- Pre-existing `SKILL.md`: overwrites, prints warning per agent.
- Missing destination directory: created automatically.

**Output** (one line per agent):
```
✓ claude  →  .claude/skills/gram/SKILL.md
✓ cursor  →  .cursor/skills/gram/SKILL.md  (overwritten)
  codex      not detected
```

**Exit codes**:
- `0` — all detected agents installed (or skipped due to not detected)
- `1` — one or more installs failed due to I/O or permission error
- `2` — bad arguments (unknown agent name)

---

### `gram skill list`

Show all locations where gram's skill is installed.

```
gram skill list [OPTIONS]

Options:
  --global    Check home-directory agent paths instead of project-local
  -h, --help  Print help
```

**Output**:
```
claude   .claude/skills/gram/SKILL.md
cursor   .cursor/skills/gram/SKILL.md
```

If nothing installed:
```
No gram skill installations found.
```

**Exit codes**: `0` always.

---

### `gram skill remove`

Remove gram's SKILL.md from installed locations.

```
gram skill remove [OPTIONS]

Options:
  --agent <NAME>   Remove from a specific agent only
  --global         Remove from home-directory paths instead of project-local
  -h, --help       Print help
```

**Output**:
```
✓ claude  removed  .claude/skills/gram/SKILL.md
  cursor  not installed
```

**Exit codes**:
- `0` — completed (including "not installed" cases)
- `1` — one or more removals failed due to I/O error

---

## Supported Agent Names

| `--agent` value | Display name |
|---|---|
| `claude` | Claude Code |
| `cursor` | Cursor |
| `codex` | OpenAI Codex |
| `copilot` | GitHub Copilot |
| `gemini` | Gemini CLI |
| `kiro` | Amazon Kiro |

---

## SKILL.md Contract

The file written to agent locations conforms to the agentskills.io specification:

```yaml
---
name: gram
description: >
  Work with gram graph data files (.gram). Use this skill when the user
  is creating, reading, editing, validating, or querying gram notation,
  or when the conversation involves graph data modelling.
license: MIT
compatibility: >
  Requires the gram CLI. Install with: cargo install gram-data
  Verify with: gram --version
metadata:
  author: gram-data
  homepage: https://github.com/gram-data/tree-sitter-gram
---

# Gram Graph Data Format
[... instructions ...]
```

- `name` is always `gram`, matching the parent directory.
- `compatibility` always references `cargo install gram-data` as the install command.
- Content is identical to `skills/gram/SKILL.md` in the gram repository.
