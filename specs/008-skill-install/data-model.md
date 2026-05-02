# Data Model: gram skill subcommand

**Date**: 2026-05-02 | **Branch**: `008-skill-install`

---

## Core Types

### `Skill` (from `agent-skills` crate)

Represents a parsed and validated SKILL.md file.

```
Skill
  frontmatter: Frontmatter
    name: SkillName          // "gram"
    description: SkillDescription  // when-to-invoke text
    license: Option<String>  // "MIT"
    compatibility: Option<Compatibility>  // prerequisite note
    metadata: Option<Metadata>  // author, version, homepage
    allowed_tools: Option<AllowedTools>
  body: String               // Markdown instructions
```

**Validation rules** (enforced by `Skill::parse`):
- `name` must match pattern `[a-z0-9-]{1,64}` and equal the parent directory name
- `description` must be 1–1024 characters
- `compatibility` must be ≤500 characters

---

### `AgentTarget`

A supported AI agent with known skill directory conventions.

```
AgentTarget
  id: &'static str          // "claude", "cursor", "codex", "copilot", "gemini", "kiro"
  display_name: &'static str // "Claude Code", "Cursor", ...
  project_dir: &'static str  // ".claude"
  global_subpath: &'static str // ".claude/skills" relative to ~
  skills_subdir: &'static str // "skills"
```

Managed by `agent-skills-rs`; gram does not hardcode these paths.

---

### `InstallTarget`

A resolved, concrete install location for a single agent on the current machine.

```
InstallTarget
  agent: AgentTarget
  path: PathBuf              // absolute path to skills/gram/ directory
  scope: InstallScope        // ProjectLocal | Global
  pre_existing: bool         // true if SKILL.md already present
```

---

### `InstallScope`

```
enum InstallScope {
  ProjectLocal,  // relative to cwd (default)
  Global,        // relative to home dir (--global)
}
```

---

### `SkillInstallResult`

Result of a single agent install attempt.

```
SkillInstallResult
  agent_id: String
  agent_display: String
  path: PathBuf
  outcome: SkillOutcome

enum SkillOutcome {
  Installed,          // written successfully
  Overwritten,        // pre-existing, overwritten with warning
  Skipped(String),    // agent not detected, reason string
  Failed(String),     // I/O or permission error
}
```

---

## State Transitions

### Install flow

```
detect agents present
  → for each agent: resolve InstallTarget
  → for each target:
      if pre_existing → warn + overwrite → Overwritten
      else → write SKILL.md → Installed
  → print summary (Installed/Overwritten/Skipped/Failed per agent)
```

### Remove flow

```
detect agents present (or use --agent filter)
  → for each agent: check if skills/gram/SKILL.md exists
  → if exists → delete → Removed
  → if not → Skipped("not installed")
  → print summary
```

---

## File Layout on Disk

```
<scope-root>/
└── .claude/
    └── skills/
        └── gram/
            └── SKILL.md     ← written by gram skill install

<scope-root>/
└── .cursor/
    └── skills/
        └── gram/
            └── SKILL.md

... (same pattern for codex, copilot, gemini, kiro)
```

Where `<scope-root>` is `cwd` (project-local) or `~` (global).
