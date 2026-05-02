# Quickstart: gram skill subcommand

**For implementors** — how to build and test this feature.

---

## 1. Add dependencies

In `tools/gram/Cargo.toml`:

```toml
agent-skills = "0.2"
agent-skills-rs = "0.3"
```

---

## 2. Create the SKILL.md

Create `skills/gram/SKILL.md` at the repo root. This is the content that gets bundled and installed. Minimum viable content:

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

[Add practical instructions here for an AI agent working with .gram files]
```

---

## 3. Add the `skill` module

Create `tools/gram/src/skill/mod.rs` mirroring the `extension` module pattern:

```rust
pub mod install;
pub mod list;
pub mod remove;

use clap::{Args, Subcommand};

// Embed the SKILL.md at compile time
const SKILL_MD: &str = include_str!("../../../../skills/gram/SKILL.md");

#[derive(Args)]
#[command(about = "Manage gram agent skills")]
pub struct SkillArgs {
    #[command(subcommand)]
    pub command: SkillCommand,
}

#[derive(Subcommand)]
pub enum SkillCommand {
    /// Install gram's skill into detected agent locations
    Install(install::InstallArgs),
    /// List installed gram skill locations
    List(list::ListArgs),
    /// Remove gram's skill from agent locations
    Remove(remove::RemoveArgs),
}

pub fn run(args: SkillArgs) -> i32 {
    match args.command {
        SkillCommand::Install(a) => install::run(a),
        SkillCommand::List(a) => list::run(a),
        SkillCommand::Remove(a) => remove::run(a),
    }
}
```

---

## 4. Wire into `main.rs`

```rust
mod skill;

// In Commands enum:
/// Manage gram agent skills
Skill(skill::SkillArgs),

// In main match:
Commands::Skill(args) => skill::run(args),
```

---

## 5. Implement install

Use `agent-skills-rs` for path resolution; write the bundled `SKILL_MD` string to each resolved path:

```rust
// Pseudocode — validate against agent-skills-rs 0.3.1 API
let config = InstallConfig::new(/* scope, agent filter */);
let result = install_skill(Source::embedded(SKILL_MD), config)?;
// print result.installed / result.skipped / result.failed
```

---

## 6. Test

Run existing test suite to ensure no regressions:

```sh
cargo test -p gram-data
```

Add new integration tests in `tools/gram/tests/cli_skill.rs`:

```rust
use assert_cmd::Command;

#[test]
fn skill_install_no_agents() {
    // Run in a temp dir with no agent config dirs present
    Command::cargo_bin("gram").unwrap()
        .args(["skill", "install"])
        .current_dir(tempdir)
        .assert()
        .success()
        .stdout(predicates::str::contains("No gram-compatible agents detected"));
}
```

---

## 7. Verify marketplace discoverability

With `skills/gram/SKILL.md` in the repo, verify with:

```sh
npx skills add gram-data/tree-sitter-gram --dry-run
```

This should list gram's skill without errors, confirming the file is in the expected location for the `npx skills` reference CLI.
