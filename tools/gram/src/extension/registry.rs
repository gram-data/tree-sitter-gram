use std::collections::HashMap;

use serde::Deserialize;

// The registry lives in its own repository so that listing an extension never needs a
// change to this one (extensions depend on this repo's crates).
const REGISTRY_URL: &str =
    "https://raw.githubusercontent.com/gram-data/gram-extensions/main/registry.toml";

#[derive(Debug, Clone, Deserialize)]
pub struct RegistryEntry {
    pub name: String,
    pub description: String,
    pub github: String,
    pub bin: String,
}

#[derive(Debug, Deserialize)]
struct RegistryManifest {
    #[serde(default)]
    extension: Vec<RegistryEntry>,
}

/// The latest release of each extension, generated next to the registry by a workflow
/// in gram-extensions (`versions.toml`).
#[derive(Debug, Default, Deserialize)]
pub struct Versions {
    #[serde(default)]
    pub updated_at: Option<String>,
    #[serde(default)]
    pub versions: HashMap<String, String>,
}

fn registry_url() -> String {
    std::env::var("GRAM_REGISTRY_URL").unwrap_or_else(|_| REGISTRY_URL.to_string())
}

fn get_text(url: &str, what: &str) -> Result<String, String> {
    let client = reqwest::blocking::Client::builder()
        .user_agent("gram-data")
        .build()
        .map_err(|e| e.to_string())?;

    let resp = client
        .get(url)
        .send()
        .map_err(|e| format!("failed to fetch {what}: {e}"))?;

    if !resp.status().is_success() {
        return Err(format!("{what} fetch returned status {}", resp.status()));
    }

    resp.text()
        .map_err(|e| format!("failed to read {what} response: {e}"))
}

pub fn fetch() -> Result<Vec<RegistryEntry>, String> {
    let text = get_text(&registry_url(), "registry")?;

    let manifest: RegistryManifest =
        toml::from_str(&text).map_err(|e| format!("failed to parse registry: {e}"))?;

    Ok(manifest.extension)
}

/// The versions file sits beside the registry file. Without a registry file name to
/// swap (a custom `GRAM_REGISTRY_URL` ending in something else) there is no versions file.
fn versions_url(registry_url: &str) -> Option<String> {
    registry_url
        .strip_suffix("registry.toml")
        .map(|base| format!("{base}versions.toml"))
}

pub fn fetch_versions() -> Result<Versions, String> {
    let url = versions_url(&registry_url()).ok_or("no versions file beside the registry")?;
    let text = get_text(&url, "versions")?;
    toml::from_str(&text).map_err(|e| format!("failed to parse versions: {e}"))
}

/// Whether `latest` is a higher dotted-numeric version than `installed`.
/// Non-numeric parts compare as 0, so a pre-release suffix never reports an update.
pub fn is_newer(latest: &str, installed: &str) -> bool {
    fn parts(v: &str) -> Vec<u64> {
        v.trim_start_matches('v')
            .split('.')
            .map(|p| p.parse().unwrap_or(0))
            .collect()
    }
    parts(latest) > parts(installed)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn versions_url_replaces_the_file_name() {
        assert_eq!(
            versions_url("https://example.com/x/main/registry.toml").as_deref(),
            Some("https://example.com/x/main/versions.toml")
        );
        assert_eq!(versions_url("https://example.com/other.toml"), None);
    }

    #[test]
    fn is_newer_compares_numerically() {
        assert!(is_newer("0.4.10", "0.4.9"));
        assert!(is_newer("v1.0.0", "0.9.9"));
        assert!(!is_newer("0.4.1", "0.4.1"));
        assert!(!is_newer("0.4.0", "0.4.1"));
    }
}
