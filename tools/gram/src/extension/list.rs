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
    #[arg(long)]
    pub json: bool,
}

#[derive(Serialize)]
struct ListEntry {
    name: String,
    description: String,
    #[serde(skip_serializing_if = "Option::is_none")]
    version: Option<String>,
    #[serde(skip_serializing_if = "Option::is_none")]
    source: Option<String>,
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

    let installed_entries: Vec<_> = entries.iter().filter(|e| e.status == "installed").collect();
    let available_entries: Vec<_> = entries.iter().filter(|e| e.status == "available").collect();

    if show_installed {
        if installed_entries.is_empty() {
            println!("Installed extensions: (none)");
        } else {
            println!("Installed extensions:");
            for e in &installed_entries {
                let ver = e.version.as_deref().unwrap_or("unknown");
                println!("  {}  {}  {}", e.name, ver, e.description);
            }
        }
    }

    if show_available && !available_entries.is_empty() {
        println!("Available extensions:");
        for e in &available_entries {
            let src = e.source.as_deref().unwrap_or("");
            println!("  {}  {}  ({})", e.name, e.description, src);
        }
    }

    0
}
