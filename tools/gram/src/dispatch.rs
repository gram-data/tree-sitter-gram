use std::process::Command;

pub fn run(args: &[String]) -> i32 {
    if args.is_empty() {
        eprintln!(
            "error: no sub-command given\n\n\
             Try 'gram --help' for a list of built-in commands."
        );
        return 2;
    }

    let subcommand = &args[0];
    let binary = format!("gram-{subcommand}");

    if let Some(path) = find_on_path(&binary) {
        let remaining = &args[1..];

        #[cfg(unix)]
        {
            use std::os::unix::process::CommandExt;
            let err = Command::new(&path).args(remaining).exec();
            eprintln!("error: failed to exec {}: {err}", path.display());
            return 2;
        }

        #[cfg(not(unix))]
        match Command::new(&path).args(remaining).status() {
            Ok(status) => return status.code().unwrap_or(1),
            Err(e) => {
                eprintln!("error: failed to exec {}: {e}", path.display());
                return 2;
            }
        }
    }

    eprintln!(
        "error: unknown sub-command '{subcommand}'\n\n\
         No built-in sub-command '{subcommand}' and no 'gram-{subcommand}' binary found on PATH.\n\n\
         Try 'gram --help' for a list of built-in commands."
    );
    2
}

fn find_on_path(binary: &str) -> Option<std::path::PathBuf> {
    let path_var = std::env::var_os("PATH")?;
    for dir in std::env::split_paths(&path_var) {
        #[cfg(windows)]
        let candidate = dir.join(format!("{binary}.exe"));
        #[cfg(not(windows))]
        let candidate = dir.join(binary);

        if candidate.is_file() {
            #[cfg(unix)]
            {
                use std::os::unix::fs::PermissionsExt;
                if let Ok(meta) = std::fs::metadata(&candidate) {
                    if meta.permissions().mode() & 0o111 != 0 {
                        return Some(candidate);
                    }
                }
            }
            #[cfg(not(unix))]
            return Some(candidate);
        }
    }
    None
}
