use clap::Args;

use super::install::{self, InstallArgs};
use super::{load_installed, registry};

#[derive(Args)]
pub struct UpgradeArgs {
    /// Extension to upgrade
    #[arg(required_unless_present = "all", conflicts_with = "all")]
    pub name: Option<String>,
    /// Upgrade every installed extension
    #[arg(long)]
    pub all: bool,
    /// Show what would be upgraded without installing anything
    #[arg(long)]
    pub dry_run: bool,
}

pub fn run(args: UpgradeArgs) -> i32 {
    let installed = load_installed();

    let targets: Vec<_> = match &args.name {
        Some(name) => match installed.installed.iter().find(|e| &e.name == name) {
            Some(e) => vec![e.clone()],
            None => {
                eprintln!("error: '{name}' is not installed");
                return 1;
            }
        },
        None => installed.installed.clone(),
    };

    if targets.is_empty() {
        eprintln!("No extensions installed.");
        return 0;
    }

    let versions = match registry::fetch_versions() {
        Ok(v) => v,
        Err(e) => {
            eprintln!("error: could not determine latest versions: {e}");
            return 1;
        }
    };

    let mut failed = false;
    for ext in targets {
        let Some(latest) = versions.versions.get(&ext.name) else {
            eprintln!("{}: no latest version known, skipping", ext.name);
            continue;
        };
        if !registry::is_newer(latest, &ext.version) {
            eprintln!("{} is up to date ({})", ext.name, ext.version);
            continue;
        }
        if args.dry_run {
            eprintln!("{}: would upgrade {} -> {latest}", ext.name, ext.version);
            continue;
        }
        eprintln!("{}: upgrading {} -> {latest}", ext.name, ext.version);
        let code = install::run(InstallArgs {
            name: format!("{}@{latest}", ext.name),
            force: true,
        });
        if code != 0 {
            failed = true;
        }
    }

    i32::from(failed)
}
