use clap::Args;

use super::install::SUPPORTED_AGENTS;

#[derive(Args)]
pub struct ListArgs {
    /// List home-directory agent paths instead of project-local
    #[arg(long)]
    pub global: bool,
}

pub fn run(args: ListArgs) -> i32 {
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

    let mut found = false;
    for (name, config_dir) in SUPPORTED_AGENTS {
        for root in &roots {
            let skill_path = root.join(config_dir).join("skills").join("gram").join("SKILL.md");
            if skill_path.exists() {
                println!("{:<8} {}", name, skill_path.display());
                found = true;
                break;
            }
        }
    }

    if !found {
        println!("No gram skill installations found.");
    }

    0
}
