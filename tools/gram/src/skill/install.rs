use clap::Args;

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

pub fn run(args: InstallArgs) -> i32 {
    if let Some(ref name) = args.agent {
        if !SUPPORTED_AGENTS.iter().any(|(id, _)| *id == name.as_str()) {
            eprintln!("error: unknown agent '{name}'");
            eprintln!("supported agents: {}", SUPPORTED_AGENTS.iter().map(|(id, _)| *id).collect::<Vec<_>>().join(", "));
            return 2;
        }
    }

    let root = if args.global {
        match directories::BaseDirs::new() {
            Some(d) => d.home_dir().to_path_buf(),
            None => {
                eprintln!("error: could not determine home directory");
                return 1;
            }
        }
    } else {
        std::env::current_dir().unwrap_or_else(|_| std::path::PathBuf::from("."))
    };

    let agents: Vec<_> = SUPPORTED_AGENTS.iter()
        .filter(|(id, _)| args.agent.as_deref().map_or(true, |a| a == *id))
        .collect();

    let mut any_failure = false;
    let mut any_installed = false;

    for (name, config_dir) in &agents {
        let agent_root = root.join(config_dir);
        if !agent_root.exists() {
            print_outcome(name, &Outcome::NotDetected);
            continue;
        }

        any_installed = true;
        let skill_dir = agent_root.join("skills").join("gram");
        let skill_path = skill_dir.join("SKILL.md");
        let pre_existing = skill_path.exists();

        if let Err(e) = std::fs::create_dir_all(&skill_dir) {
            let outcome = Outcome::Failed(e.to_string());
            print_outcome(name, &outcome);
            any_failure = true;
            continue;
        }

        match std::fs::write(&skill_path, SKILL_MD) {
            Ok(()) => {
                let outcome = if pre_existing {
                    Outcome::Overwritten(skill_path)
                } else {
                    Outcome::Installed(skill_path)
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
