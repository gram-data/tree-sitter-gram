//! Expose `extension.toml`'s `version = "…"` as `env!("GRAM_EXT_VERSION")` for release lookups.

use std::env;
use std::fs;
use std::path::PathBuf;

fn main() {
    let manifest_dir = PathBuf::from(env::var("CARGO_MANIFEST_DIR").expect("CARGO_MANIFEST_DIR"));
    let ext_toml = manifest_dir.join("extension.toml");
    println!("cargo:rerun-if-changed={}", ext_toml.display());

    let content = fs::read_to_string(&ext_toml).unwrap_or_else(|e| panic!("read {}: {e}", ext_toml.display()));
    let version = parse_version(&content)
        .unwrap_or_else(|| panic!("{}: missing `version = \"…\"` line", ext_toml.display()));
    println!("cargo:rustc-env=GRAM_EXT_VERSION={version}");
}

fn parse_version(toml: &str) -> Option<String> {
    for line in toml.lines() {
        let line = line.trim();
        if let Some(rest) = line.strip_prefix("version = \"") {
            return rest.split('"').next().map(str::to_string);
        }
    }
    None
}
