use clap::Args;

use super::install::SUPPORTED_AGENTS;

#[derive(Args)]
pub struct ListArgs {
    /// List home-directory agent paths instead of project-local
    #[arg(long)]
    pub global: bool,
}

pub fn run(args: ListArgs) -> i32 {
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

    let mut found = false;
    for (name, config_dir) in SUPPORTED_AGENTS {
        let skill_path = root.join(config_dir).join("skills").join("gram").join("SKILL.md");
        if skill_path.exists() {
            println!("{:<8} {}", name, skill_path.display());
            found = true;
        }
    }

    if !found {
        println!("No gram skill installations found.");
    }

    0
}
