use clap::Args;
use agent_skills_rs::{install_skill, InstallConfig};
use agent_skills_rs::embedded::register_embedded_skill;

use super::SKILL_MD;

pub const SUPPORTED_AGENTS: &[(&str, &str)] = &[
    ("claude",  ".claude"),
    ("cursor",  ".cursor"),
    ("codex",   ".codex"),
    ("copilot", ".github"),
    ("gemini",  ".gemini"),
    ("kiro",    ".kiro"),
];

#[derive(Args)]
pub struct InstallArgs {
    /// Install to a specific agent only (claude, cursor, codex, copilot, gemini, kiro)
    #[arg(long)]
    pub agent: Option<String>,
    /// Install to home-directory agent paths instead of project-local
    #[arg(long)]
    pub global: bool,
}

enum Outcome {
    Installed(std::path::PathBuf),
    Overwritten(std::path::PathBuf),
    NotDetected,
    Failed(String),
}

// Returns candidate roots for agent detection. When not --global, project-local is
// checked first; home dir is the fallback so users with only global agent configs
// (e.g. ~/.claude/) are still detected.
fn candidate_roots(global: bool) -> Option<Vec<std::path::PathBuf>> {
    if global {
        let home = directories::BaseDirs::new()?.home_dir().to_path_buf();
        Some(vec![home])
    } else {
        let project = std::env::current_dir().unwrap_or_else(|_| std::path::PathBuf::from("."));
        let mut roots = vec![project];
        if let Some(d) = directories::BaseDirs::new() {
            roots.push(d.home_dir().to_path_buf());
        }
        Some(roots)
    }
}

pub fn run(args: InstallArgs) -> i32 {
    if let Some(ref name) = args.agent {
        if !SUPPORTED_AGENTS.iter().any(|(id, _)| *id == name.as_str()) {
            eprintln!("error: unknown agent '{name}'");
            eprintln!("supported agents: {}", SUPPORTED_AGENTS.iter().map(|(id, _)| *id).collect::<Vec<_>>().join(", "));
            return 2;
        }
    }

    let roots = match candidate_roots(args.global) {
        Some(r) => r,
        None => {
            eprintln!("error: could not determine home directory");
            return 1;
        }
    };

    let skill = match register_embedded_skill(SKILL_MD, &[]) {
        Ok(s) => s,
        Err(e) => {
            eprintln!("error: failed to load bundled skill: {e}");
            return 1;
        }
    };

    let agents: Vec<_> = SUPPORTED_AGENTS.iter()
        .filter(|(id, _)| args.agent.as_deref().map_or(true, |a| a == *id))
        .collect();

    let mut any_failure = false;
    let mut any_installed = false;

    for (name, config_dir) in &agents {
        // Use first root where this agent's config dir exists (project-local before global).
        let agent_root = roots.iter()
            .map(|r| r.join(config_dir))
            .find(|p| p.exists());

        let agent_root = match agent_root {
            Some(r) => r,
            None => {
                print_outcome(name, &Outcome::NotDetected);
                continue;
            }
        };

        any_installed = true;
        let skill_path = agent_root.join("skills").join("gram").join("SKILL.md");
        let pre_existing = skill_path.exists();

        let config = InstallConfig::new(agent_root.join("skills"));
        match install_skill(&skill, &config) {
            Ok(result) => {
                let installed_path = result.path.join("SKILL.md");
                let outcome = if pre_existing {
                    Outcome::Overwritten(installed_path)
                } else {
                    Outcome::Installed(installed_path)
                };
                print_outcome(name, &outcome);
            }
            Err(e) => {
                print_outcome(name, &Outcome::Failed(e.to_string()));
                any_failure = true;
            }
        }
    }

    if !any_installed && !any_failure {
        println!("No gram-compatible agents detected. Looked for: {}",
            agents.iter().map(|(id, dir)| format!("{id} ({dir}/)", )).collect::<Vec<_>>().join(", "));
    }

    if any_failure { 1 } else { 0 }
}

fn print_outcome(agent: &str, outcome: &Outcome) {
    match outcome {
        Outcome::Installed(path) => println!("✓ {:<8} → {}", agent, path.display()),
        Outcome::Overwritten(path) => println!("✓ {:<8} → {} (overwritten)", agent, path.display()),
        Outcome::NotDetected => println!("  {:<8}   not detected", agent),
        Outcome::Failed(msg) => eprintln!("✗ {:<8}   failed: {}", agent, msg),
    }
}
