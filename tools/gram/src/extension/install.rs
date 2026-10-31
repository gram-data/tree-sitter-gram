use clap::Args;
use std::io::Read;

use super::registry::fetch as fetch_registry;
use super::{gram_bin_dir, load_installed, save_installed, InstalledExtension};

#[derive(Args)]
pub struct InstallArgs {
    /// Extension name, optionally with pinned version (e.g., lsp or lsp@0.3.6)
    pub name: String,
    /// Overwrite an already-installed version without prompting
    #[arg(long)]
    pub force: bool,
}

#[cfg(all(target_os = "linux", target_arch = "x86_64"))]
const TARGET: &str = "x86_64-unknown-linux-musl";
#[cfg(all(target_os = "linux", target_arch = "aarch64"))]
const TARGET: &str = "aarch64-unknown-linux-musl";
#[cfg(all(target_os = "macos", target_arch = "x86_64"))]
const TARGET: &str = "x86_64-apple-darwin";
#[cfg(all(target_os = "macos", target_arch = "aarch64"))]
const TARGET: &str = "aarch64-apple-darwin";
#[cfg(all(target_os = "windows", target_arch = "x86_64"))]
const TARGET: &str = "x86_64-pc-windows-msvc";
#[cfg(not(any(
    all(target_os = "linux", target_arch = "x86_64"),
    all(target_os = "linux", target_arch = "aarch64"),
    all(target_os = "macos", target_arch = "x86_64"),
    all(target_os = "macos", target_arch = "aarch64"),
    all(target_os = "windows", target_arch = "x86_64"),
)))]
const TARGET: &str = "unsupported";

pub fn run(args: InstallArgs) -> i32 {
    let (name, version_pin) = parse_name_version(&args.name);

    if TARGET == "unsupported" {
        eprintln!("error: unsupported platform for extension install");
        return 1;
    }

    let entries = match fetch_registry() {
        Ok(e) => e,
        Err(e) => {
            eprintln!("error: {e}");
            return 1;
        }
    };

    let entry = match entries.iter().find(|e| e.name == name) {
        Some(e) => e.clone(),
        None => {
            eprintln!(
                "error: unknown extension '{name}'. Run 'gram extension list' to see available extensions."
            );
            return 2;
        }
    };

    let mut installed = load_installed();
    if let Some(existing) = installed.installed.iter().find(|e| e.name == name) {
        if !args.force {
            eprintln!(
                "error: '{name}' is already installed (version {}). Use --force to overwrite.",
                existing.version
            );
            return 1;
        }
    }

    let version = match resolve_version(&entry.github, version_pin.as_deref()) {
        Ok(v) => v,
        Err(e) => {
            eprintln!("error: {e}");
            return 1;
        }
    };

    let archive_ext = if TARGET.contains("windows") {
        "zip"
    } else {
        "tar.gz"
    };
    let artifact = format!("{}-{}.{}", entry.bin, TARGET, archive_ext);
    let url = format!(
        "https://github.com/{}/releases/download/v{}/{}",
        entry.github, version, artifact
    );

    eprintln!("Downloading {artifact} ...");

    let binary_data = match download_and_extract(&url, &entry.bin) {
        Ok(data) => data,
        Err(e) => {
            eprintln!("error: {e}");
            return 1;
        }
    };

    let bin_dir = gram_bin_dir();
    if let Err(e) = std::fs::create_dir_all(&bin_dir) {
        eprintln!("error: failed to create {}: {e}", bin_dir.display());
        return 1;
    }

    #[cfg(windows)]
    let bin_name = format!("{}.exe", entry.bin);
    #[cfg(not(windows))]
    let bin_name = entry.bin.clone();

    let final_path = bin_dir.join(&bin_name);
    let tmp_path = bin_dir.join(format!(".{bin_name}.tmp"));

    if let Err(e) = std::fs::write(&tmp_path, &binary_data) {
        eprintln!("error: failed to write binary: {e}");
        return 1;
    }

    #[cfg(unix)]
    {
        use std::os::unix::fs::PermissionsExt;
        if let Err(e) = std::fs::set_permissions(&tmp_path, std::fs::Permissions::from_mode(0o755))
        {
            eprintln!("error: failed to set permissions: {e}");
            let _ = std::fs::remove_file(&tmp_path);
            return 1;
        }
    }

    // On Windows, rename fails if the destination already exists; remove it first.
    #[cfg(windows)]
    if final_path.exists() {
        if let Err(e) = std::fs::remove_file(&final_path) {
            eprintln!("error: failed to remove existing binary: {e}");
            let _ = std::fs::remove_file(&tmp_path);
            return 1;
        }
    }

    if let Err(e) = std::fs::rename(&tmp_path, &final_path) {
        eprintln!("error: failed to install binary: {e}");
        let _ = std::fs::remove_file(&tmp_path);
        return 1;
    }

    installed.installed.retain(|e| e.name != name);
    installed.installed.push(InstalledExtension {
        name: name.to_string(),
        version: version.clone(),
        bin_path: final_path.display().to_string(),
        installed_at: current_timestamp(),
    });

    if let Err(e) = save_installed(&installed) {
        eprintln!("warning: installed but failed to record in extensions.toml: {e}");
    }

    eprintln!(
        "Installed '{}' v{} to {}",
        name,
        version,
        final_path.display()
    );

    warn_if_not_on_path(&bin_dir);
    0
}

fn parse_name_version(input: &str) -> (&str, Option<String>) {
    if let Some(idx) = input.find('@') {
        (&input[..idx], Some(input[idx + 1..].to_string()))
    } else {
        (input, None)
    }
}

fn resolve_version(github: &str, pin: Option<&str>) -> Result<String, String> {
    if let Some(v) = pin {
        return Ok(v.to_string());
    }

    let url = format!("https://api.github.com/repos/{}/releases/latest", github);
    let client = reqwest::blocking::Client::builder()
        .user_agent("gram-data")
        .build()
        .map_err(|e| e.to_string())?;

    let resp = client
        .get(&url)
        .send()
        .map_err(|e| format!("failed to fetch releases: {e}"))?;

    if !resp.status().is_success() {
        return Err(format!("GitHub API returned status {}", resp.status()));
    }

    let json: serde_json::Value = resp.json().map_err(|e| e.to_string())?;
    let tag = json["tag_name"]
        .as_str()
        .ok_or("no tag_name in release response")?;

    Ok(tag.trim_start_matches('v').to_string())
}

fn download_and_extract(url: &str, bin_name: &str) -> Result<Vec<u8>, String> {
    let client = reqwest::blocking::Client::builder()
        .user_agent("gram-data")
        .build()
        .map_err(|e| e.to_string())?;

    let resp = client
        .get(url)
        .send()
        .map_err(|e| format!("download failed: {e}"))?;

    if !resp.status().is_success() {
        return Err(format!("download returned status {}", resp.status()));
    }

    let bytes = resp.bytes().map_err(|e| e.to_string())?;

    if url.ends_with(".tar.gz") {
        extract_from_tar_gz(&bytes, bin_name)
    } else if url.ends_with(".zip") {
        extract_from_zip(&bytes, bin_name)
    } else {
        Err(format!("unsupported archive format in URL: {url}"))
    }
}

fn extract_from_tar_gz(data: &[u8], bin_name: &str) -> Result<Vec<u8>, String> {
    use flate2::read::GzDecoder;
    use tar::Archive;

    let gz = GzDecoder::new(data);
    let mut archive = Archive::new(gz);

    for entry in archive.entries().map_err(|e| e.to_string())? {
        let mut entry = entry.map_err(|e| e.to_string())?;
        let path = entry.path().map_err(|e| e.to_string())?;
        let filename = path.file_name().and_then(|n| n.to_str()).unwrap_or("");

        if filename == bin_name {
            let mut buf = Vec::new();
            entry.read_to_end(&mut buf).map_err(|e| e.to_string())?;
            return Ok(buf);
        }
    }

    Err(format!("binary '{bin_name}' not found in archive"))
}

fn extract_from_zip(data: &[u8], bin_name: &str) -> Result<Vec<u8>, String> {
    use std::io::Cursor;
    use zip::ZipArchive;

    let cursor = Cursor::new(data);
    let mut archive = ZipArchive::new(cursor).map_err(|e| e.to_string())?;

    for i in 0..archive.len() {
        let mut file = archive.by_index(i).map_err(|e| e.to_string())?;
        let filename = file.name().to_string();
        let basename = std::path::Path::new(&filename)
            .file_name()
            .and_then(|n| n.to_str())
            .unwrap_or("");

        if basename == bin_name || basename == format!("{bin_name}.exe") {
            let mut buf = Vec::new();
            file.read_to_end(&mut buf).map_err(|e| e.to_string())?;
            return Ok(buf);
        }
    }

    Err(format!("binary '{bin_name}' not found in archive"))
}

fn warn_if_not_on_path(bin_dir: &std::path::Path) {
    let path_var = std::env::var_os("PATH").unwrap_or_default();
    let on_path = std::env::split_paths(&path_var).any(|p| p == bin_dir);

    if !on_path {
        eprintln!("\nwarning: {} is not on your PATH.", bin_dir.display());
        let shell = detect_shell();
        eprintln!(
            "{}",
            path_instructions(&shell, &bin_dir.display().to_string())
        );
    }
}

const KNOWN_SHELLS: [&str; 6] = ["fish", "zsh", "bash", "nu", "pwsh", "powershell"];

fn shell_name(shell: &str) -> &str {
    let name = shell.rsplit(['/', '\\']).next().unwrap_or("");
    let name = name.strip_prefix('-').unwrap_or(name);
    name.strip_suffix(".exe").unwrap_or(name)
}

/// The shell that is running `gram`: the parent process when it is a known shell,
/// since `$SHELL` is the login shell and can differ (fish started from zsh), else `$SHELL`.
fn pick_shell(parent: Option<&str>, login_shell: &str) -> String {
    match parent {
        Some(p) if KNOWN_SHELLS.contains(&shell_name(p)) => p.to_string(),
        _ => login_shell.to_string(),
    }
}

#[cfg(unix)]
fn parent_process_name() -> Option<String> {
    let ppid = std::os::unix::process::parent_id();
    let out = std::process::Command::new("ps")
        .args(["-p", &ppid.to_string(), "-o", "comm="])
        .output()
        .ok()?;
    out.status
        .success()
        .then(|| String::from_utf8_lossy(&out.stdout).trim().to_string())
        .filter(|s| !s.is_empty())
}

#[cfg(not(unix))]
fn parent_process_name() -> Option<String> {
    None
}

fn detect_shell() -> String {
    pick_shell(
        parent_process_name().as_deref(),
        &std::env::var("SHELL").unwrap_or_default(),
    )
}

/// How to put `bin_dir` on PATH for the shell named by `shell` (a path such as
/// `/opt/homebrew/bin/fish`, or empty when unknown; Windows has no `SHELL`).
fn path_instructions(shell: &str, bin_dir: &str) -> String {
    match shell_name(shell) {
        "fish" => format!("Add it for fish (saved across sessions):\n  fish_add_path {bin_dir}"),
        "zsh" => format!(
            "Add it for zsh:\n  echo 'export PATH=\"{bin_dir}:$PATH\"' >> ~/.zshrc"
        ),
        "bash" => {
            let rc = if cfg!(target_os = "macos") {
                "~/.bash_profile"
            } else {
                "~/.bashrc"
            };
            format!("Add it for bash:\n  echo 'export PATH=\"{bin_dir}:$PATH\"' >> {rc}")
        }
        "nu" => format!(
            "Add it for nushell, in your env.nu:\n  $env.PATH = ($env.PATH | prepend \"{bin_dir}\")"
        ),
        "pwsh" | "powershell" => format!(
            "Add it for PowerShell (user PATH):\n  [Environment]::SetEnvironmentVariable(\"Path\", \"{bin_dir};\" + [Environment]::GetEnvironmentVariable(\"Path\", \"User\"), \"User\")"
        ),
        _ if cfg!(windows) => format!(
            "Add it to your user PATH (System Properties > Environment Variables):\n  {bin_dir}"
        ),
        _ => format!(
            "Add it to your shell profile, in the form your shell uses:\n  export PATH=\"{bin_dir}:$PATH\""
        ),
    }
}

fn current_timestamp() -> String {
    use std::time::{SystemTime, UNIX_EPOCH};
    let secs = SystemTime::now()
        .duration_since(UNIX_EPOCH)
        .unwrap_or_default()
        .as_secs();
    let (y, mo, d, h, mi, s) = unix_secs_to_parts(secs);
    format!("{y:04}-{mo:02}-{d:02}T{h:02}:{mi:02}:{s:02}Z")
}

fn unix_secs_to_parts(secs: u64) -> (u64, u64, u64, u64, u64, u64) {
    let s = secs % 60;
    let m = (secs / 60) % 60;
    let h = (secs / 3600) % 24;
    let days = secs / 86400;
    let (y, doy) = days_to_year(days);
    let (mo, d) = doy_to_month_day(doy, is_leap_year(y));
    (y, mo, d, h, m, s)
}

fn is_leap_year(y: u64) -> bool {
    (y.is_multiple_of(4) && !y.is_multiple_of(100)) || y.is_multiple_of(400)
}

fn days_to_year(mut days: u64) -> (u64, u64) {
    let mut y = 1970u64;
    loop {
        let dy = if is_leap_year(y) { 366 } else { 365 };
        if days < dy {
            return (y, days);
        }
        days -= dy;
        y += 1;
    }
}

fn doy_to_month_day(mut doy: u64, leap: bool) -> (u64, u64) {
    let months: [u64; 12] = if leap {
        [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    } else {
        [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    };
    let mut mo = 1u64;
    for &dim in &months {
        if doy < dim {
            return (mo, doy + 1);
        }
        doy -= dim;
        mo += 1;
    }
    (12, 31)
}

#[cfg(test)]
mod path_tests {
    use super::{path_instructions, pick_shell};

    const DIR: &str = "/home/u/.gram/bin";

    #[test]
    fn fish_uses_fish_add_path() {
        let out = path_instructions("/opt/homebrew/bin/fish", DIR);
        assert!(out.contains("fish_add_path /home/u/.gram/bin"));
        assert!(!out.contains("export"));
    }

    #[test]
    fn zsh_appends_to_zshrc() {
        let out = path_instructions("/bin/zsh", DIR);
        assert!(out.contains("~/.zshrc"));
        assert!(out.contains("export PATH=\"/home/u/.gram/bin:$PATH\""));
    }

    #[test]
    fn bash_appends_to_a_bash_rc_file() {
        let out = path_instructions("/bin/bash", DIR);
        assert!(out.contains("~/.bashrc") || out.contains("~/.bash_profile"));
    }

    #[test]
    fn nushell_and_powershell_have_their_own_syntax() {
        assert!(path_instructions("/usr/bin/nu", DIR).contains("prepend"));
        assert!(
            path_instructions("C:\\Program Files\\PowerShell\\pwsh.exe", DIR)
                .contains("SetEnvironmentVariable")
        );
    }

    #[test]
    fn unknown_shell_falls_back_to_export() {
        let out = path_instructions("", DIR);
        assert!(out.contains("shell profile") || out.contains("user PATH"));
    }

    #[test]
    fn the_running_shell_wins_over_the_login_shell() {
        assert_eq!(pick_shell(Some("-fish"), "/bin/zsh"), "-fish");
        assert_eq!(
            pick_shell(Some("/opt/homebrew/bin/fish"), "/bin/zsh"),
            "/opt/homebrew/bin/fish"
        );
    }

    #[test]
    fn a_parent_that_is_not_a_shell_falls_back_to_the_login_shell() {
        assert_eq!(pick_shell(Some("cargo"), "/bin/zsh"), "/bin/zsh");
        assert_eq!(pick_shell(None, "/bin/zsh"), "/bin/zsh");
    }

    #[test]
    fn a_leading_dash_from_a_login_shell_is_ignored() {
        assert!(path_instructions("-fish", DIR).contains("fish_add_path"));
    }
}
