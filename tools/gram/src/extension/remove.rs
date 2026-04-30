use clap::Args;

use super::{load_installed, save_installed};

#[derive(Args)]
pub struct RemoveArgs {
    /// Extension name to remove
    pub name: String,
}

pub fn run(args: RemoveArgs) -> i32 {
    let mut installed = load_installed();

    let entry = match installed.installed.iter().find(|e| e.name == args.name) {
        Some(e) => e.clone(),
        None => {
            eprintln!("error: '{}' is not installed", args.name);
            return 1;
        }
    };

    let bin_path = std::path::Path::new(&entry.bin_path);
    if bin_path.exists() {
        if let Err(e) = std::fs::remove_file(bin_path) {
            eprintln!("error: failed to remove {}: {e}", bin_path.display());
            return 1;
        }
    }

    installed.installed.retain(|e| e.name != args.name);

    if let Err(e) = save_installed(&installed) {
        eprintln!("error: removed binary but failed to update extensions.toml: {e}");
        return 1;
    }

    eprintln!("Removed '{}'", args.name);
    0
}
