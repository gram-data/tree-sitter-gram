use clap::Args;
use serde::Serialize;

use super::{load_installed, registry};

#[derive(Args)]
pub struct ListArgs {
    /// Show only installed extensions
    #[arg(long, conflicts_with = "available")]
    pub installed: bool,
    /// Show only extensions available in the registry
    #[arg(long, conflicts_with = "installed")]
    pub available: bool,
    /// Output as JSON array
    #[arg(long, conflicts_with = "lines")]
    pub json: bool,
    /// One tab-separated line per extension, for sed, awk and cut. Columns: name, status
    /// (installed, outdated or available), installed version, latest version, source,
    /// description. Empty values are `-`.
    #[arg(short = 'l', long, conflicts_with = "json")]
    pub lines: bool,
}

#[derive(Serialize)]
struct ListEntry {
    name: String,
    description: String,
    #[serde(skip_serializing_if = "Option::is_none")]
    version: Option<String>,
    #[serde(skip_serializing_if = "Option::is_none")]
    source: Option<String>,
    #[serde(skip_serializing_if = "Option::is_none")]
    latest: Option<String>,
    update_available: bool,
    status: &'static str,
}

pub fn run(args: ListArgs) -> i32 {
    let show_installed = !args.available;
    let show_available = !args.installed;

    let installed_data = load_installed();

    let mut entries: Vec<ListEntry> = Vec::new();

    if show_installed {
        for ext in &installed_data.installed {
            entries.push(ListEntry {
                name: ext.name.clone(),
                description: String::new(),
                version: Some(ext.version.clone()),
                source: None,
                latest: None,
                update_available: false,
                status: "installed",
            });
        }
    }

    if show_available {
        match registry::fetch() {
            Ok(registry_entries) => {
                for re in registry_entries {
                    let already_listed = entries.iter().any(|e| e.name == re.name);
                    if already_listed {
                        // Merge description into existing entry
                        if let Some(e) = entries.iter_mut().find(|e| e.name == re.name) {
                            e.description = re.description.clone();
                            e.source = Some(re.github.clone());
                        }
                    } else {
                        entries.push(ListEntry {
                            name: re.name,
                            description: re.description,
                            version: None,
                            source: Some(re.github),
                            latest: None,
                            update_available: false,
                            status: "available",
                        });
                    }
                }
            }
            Err(e) => {
                eprintln!("warning: could not fetch registry: {e}");
            }
        }
    }

    // Latest versions come from one file beside the registry; without it the columns stay empty.
    let mut versions_updated_at: Option<String> = None;
    if show_available {
        match registry::fetch_versions() {
            Ok(v) => {
                versions_updated_at = v.updated_at.clone();
                for e in entries.iter_mut() {
                    if let Some(latest) = v.versions.get(&e.name) {
                        e.update_available = e
                            .version
                            .as_deref()
                            .is_some_and(|installed| registry::is_newer(latest, installed));
                        e.latest = Some(latest.clone());
                    }
                }
            }
            Err(e) => eprintln!("warning: could not fetch latest versions: {e}"),
        }
    }

    if args.json {
        match serde_json::to_string_pretty(&entries) {
            Ok(json) => println!("{json}"),
            Err(e) => {
                eprintln!("error serializing JSON: {e}");
                return 2;
            }
        }
        return 0;
    }

    if args.lines {
        use std::io::Write;
        let mut out = std::io::stdout().lock();
        let dash = |v: Option<&str>| match v {
            Some(v) if !v.is_empty() => v.to_string(),
            _ => "-".to_string(),
        };
        for e in &entries {
            let status = if e.update_available {
                "outdated"
            } else {
                e.status
            };
            // A closed pipe (`| head`) ends the output quietly instead of panicking.
            if writeln!(
                out,
                "{}\t{}\t{}\t{}\t{}\t{}",
                e.name,
                status,
                dash(e.version.as_deref()),
                dash(e.latest.as_deref()),
                dash(e.source.as_deref()),
                dash(Some(e.description.as_str())),
            )
            .is_err()
            {
                break;
            }
        }
        return 0;
    }

    let installed_entries: Vec<_> = entries.iter().filter(|e| e.status == "installed").collect();
    let available_entries: Vec<_> = entries.iter().filter(|e| e.status == "available").collect();

    if show_installed {
        if installed_entries.is_empty() {
            println!("Installed extensions: (none)");
        } else {
            println!("Installed extensions:");
            for e in &installed_entries {
                let ver = e.version.as_deref().unwrap_or("unknown");
                let update = match (&e.latest, e.update_available) {
                    (Some(latest), true) => format!("  (update available: {latest})"),
                    _ => String::new(),
                };
                println!("  {}  {}  {}{}", e.name, ver, e.description, update);
            }
        }
    }

    if show_available && !available_entries.is_empty() {
        println!("Available extensions:");
        for e in &available_entries {
            let src = e.source.as_deref().unwrap_or("");
            let latest = e.latest.as_deref().unwrap_or("?");
            println!(
                "  {}  {}  (latest {}, {})",
                e.name, e.description, latest, src
            );
        }
    }

    if let Some(updated_at) = versions_updated_at {
        println!("\nLatest versions last changed {updated_at}");
    }

    0
}
