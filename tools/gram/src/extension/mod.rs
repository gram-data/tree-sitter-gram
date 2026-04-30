pub mod install;
pub mod list;
pub mod registry;
pub mod remove;

use clap::{Args, Subcommand};
use directories::BaseDirs;
use serde::{Deserialize, Serialize};
use std::path::PathBuf;

#[derive(Args)]
#[command(about = "Manage gram extensions")]
pub struct ExtensionArgs {
    #[command(subcommand)]
    pub command: ExtensionCommand,
}

#[derive(Subcommand)]
pub enum ExtensionCommand {
    /// Download and install an extension
    Install(install::InstallArgs),
    /// List available and installed extensions
    List(list::ListArgs),
    /// Uninstall an extension
    Remove(remove::RemoveArgs),
}

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct InstalledExtension {
    pub name: String,
    pub version: String,
    pub bin_path: String,
    pub installed_at: String,
}

#[derive(Debug, Clone, Serialize, Deserialize, Default)]
pub struct ExtensionsToml {
    #[serde(default)]
    pub installed: Vec<InstalledExtension>,
}

pub fn gram_bin_dir() -> PathBuf {
    BaseDirs::new()
        .expect("cannot determine home directory")
        .home_dir()
        .join(".gram")
        .join("bin")
}

pub fn extensions_toml_path() -> PathBuf {
    BaseDirs::new()
        .expect("cannot determine home directory")
        .home_dir()
        .join(".gram")
        .join("extensions.toml")
}

pub fn load_installed() -> ExtensionsToml {
    let path = extensions_toml_path();
    if !path.exists() {
        return ExtensionsToml::default();
    }
    let content = std::fs::read_to_string(&path).unwrap_or_default();
    toml::from_str(&content).unwrap_or_default()
}

pub fn save_installed(data: &ExtensionsToml) -> Result<(), String> {
    let path = extensions_toml_path();
    if let Some(parent) = path.parent() {
        std::fs::create_dir_all(parent).map_err(|e| e.to_string())?;
    }
    let content = toml::to_string(data).map_err(|e| e.to_string())?;
    std::fs::write(&path, content).map_err(|e| e.to_string())?;
    Ok(())
}

pub fn run(args: ExtensionArgs) -> i32 {
    match args.command {
        ExtensionCommand::Install(a) => install::run(a),
        ExtensionCommand::List(a) => list::run(a),
        ExtensionCommand::Remove(a) => remove::run(a),
    }
}
