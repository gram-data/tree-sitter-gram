pub mod install;
pub mod list;
pub mod remove;

use clap::{Args, Subcommand};

pub const SKILL_MD: &str = include_str!("../../../../skills/gram/SKILL.md");

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

#[cfg(test)]
mod tests {
    use super::SKILL_MD;
    use agent_skills::Skill;

    #[test]
    fn bundled_skill_md_is_valid() {
        Skill::parse(SKILL_MD).expect("bundled skills/gram/SKILL.md must be valid per the agentskills.io spec");
    }
}
