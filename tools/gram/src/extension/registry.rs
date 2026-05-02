use serde::Deserialize;

const REGISTRY_URL: &str =
    "https://raw.githubusercontent.com/gram-data/tree-sitter-gram/main/registry.toml";

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

pub fn fetch() -> Result<Vec<RegistryEntry>, String> {
    let url = std::env::var("GRAM_REGISTRY_URL")
        .unwrap_or_else(|_| REGISTRY_URL.to_string());

    let client = reqwest::blocking::Client::builder()
        .user_agent("gram-data")
        .build()
        .map_err(|e| e.to_string())?;

    let resp = client
        .get(&url)
        .send()
        .map_err(|e| format!("failed to fetch registry: {e}"))?;

    if !resp.status().is_success() {
        return Err(format!("registry fetch returned status {}", resp.status()));
    }

    let text = resp
        .text()
        .map_err(|e| format!("failed to read registry response: {e}"))?;

    let manifest: RegistryManifest =
        toml::from_str(&text).map_err(|e| format!("failed to parse registry: {e}"))?;

    Ok(manifest.extension)
}
