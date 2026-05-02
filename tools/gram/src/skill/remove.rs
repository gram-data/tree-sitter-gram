use clap::Args;

use super::install::SUPPORTED_AGENTS;

#[derive(Args)]
pub struct RemoveArgs {
    /// Remove from a specific agent only (claude, cursor, codex, copilot, gemini, kiro)
    #[arg(long)]
    pub agent: Option<String>,
    /// Remove from home-directory agent paths instead of project-local
    #[arg(long)]
    pub global: bool,
}

pub fn run(args: RemoveArgs) -> i32 {
    if let Some(ref name) = args.agent {
        if !SUPPORTED_AGENTS.iter().any(|(id, _)| *id == name.as_str()) {
            eprintln!("error: unknown agent '{name}'");
            eprintln!("supported agents: {}", SUPPORTED_AGENTS.iter().map(|(id, _)| *id).collect::<Vec<_>>().join(", "));
            return 2;
        }
    }

    let roots: Vec<std::path::PathBuf> = if args.global {
        match directories::BaseDirs::new() {
            Some(d) => vec![d.home_dir().to_path_buf()],
            None => {
                eprintln!("error: could not determine home directory");
                return 1;
            }
        }
    } else {
        let project = std::env::current_dir().unwrap_or_else(|_| std::path::PathBuf::from("."));
        let mut r = vec![project];
        if let Some(d) = directories::BaseDirs::new() {
            r.push(d.home_dir().to_path_buf());
        }
        r
    };

    let mut any_failure = false;

    for (name, config_dir) in SUPPORTED_AGENTS {
        if args.agent.as_deref().map_or(false, |a| a != *name) {
            continue;
        }

        // Find first root where this agent's skill is installed.
        let found = roots.iter().find_map(|root| {
            let skill_dir = root.join(config_dir).join("skills").join("gram");
            let skill_path = skill_dir.join("SKILL.md");
            if skill_path.exists() { Some((skill_dir, skill_path)) } else { None }
        });
        let (skill_dir, skill_path) = match found {
            Some(p) => p,
            None => {
                println!("  {:<8}   not installed", name);
                continue;
            }
        };

        match std::fs::remove_file(&skill_path) {
            Ok(()) => {
                // Remove the gram/ dir too if now empty
                let _ = std::fs::remove_dir(&skill_dir);
                println!("✓ {:<8} removed  {}", name, skill_path.display());
            }
            Err(e) => {
                eprintln!("✗ {:<8}   failed: {}", name, e);
                any_failure = true;
            }
        }
    }

    if any_failure { 1 } else { 0 }
}
