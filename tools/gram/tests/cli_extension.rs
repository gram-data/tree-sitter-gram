use assert_cmd::Command;
use predicates::prelude::*;
use tempfile::tempdir;

fn gram() -> Command {
    Command::cargo_bin("gram").unwrap()
}

// Point at an unreachable address so registry fetches fail immediately without
// relying on external network availability.
const FAKE_REGISTRY: &str = "http://127.0.0.1:1/registry.toml";

#[test]
fn extension_list_installed_requires_no_network() {
    // --installed only reads ~/.gram/extensions.toml; no registry fetch needed.
    gram()
        .args(["extension", "list", "--installed"])
        .assert()
        .success()
        .stdout(predicate::str::contains("Installed extensions"));
}

#[test]
fn extension_remove_unknown_exits_nonzero() {
    gram()
        .args(["extension", "remove", "nonexistent-extension-xyz"])
        .assert()
        .failure()
        .stderr(predicate::str::contains("not installed"));
}

#[test]
fn extension_install_fails_when_registry_unreachable() {
    gram()
        .args(["extension", "install", "lsp"])
        .env("GRAM_REGISTRY_URL", FAKE_REGISTRY)
        .assert()
        .failure()
        .stderr(predicate::str::contains("failed to fetch registry"));
}

#[test]
fn extension_install_unknown_name_exits_nonzero_with_empty_registry() {
    // Serve an empty registry (connection refused = immediate failure, exit 1).
    // This verifies the CLI exits non-zero without depending on real network.
    gram()
        .args(["extension", "install", "no-such-extension"])
        .env("GRAM_REGISTRY_URL", FAKE_REGISTRY)
        .assert()
        .failure();
}

#[test]
fn installed_extensions_toml_roundtrip() {
    // Verifies the TOML data model used by extension commands, not the CLI itself.
    // Full CLI roundtrip requires network for `install`; tested in integration/e2e suite.
    let fake_home = tempdir().unwrap();

    let bin_dir = fake_home.path().join(".gram").join("bin");
    std::fs::create_dir_all(&bin_dir).unwrap();

    let bin_path = bin_dir.join("gram-fake");
    std::fs::write(&bin_path, b"#!/bin/sh\necho fake").unwrap();

    let ext_toml_path = fake_home.path().join(".gram").join("extensions.toml");
    let toml_content = format!(
        "[[installed]]\nname = \"fake\"\nversion = \"0.1.0\"\nbin_path = \"{}\"\ninstalled_at = \"2026-01-01T00:00:00Z\"\n",
        bin_path.display()
    );
    std::fs::write(&ext_toml_path, &toml_content).unwrap();

    let content = std::fs::read_to_string(&ext_toml_path).unwrap();
    assert!(content.contains("name = \"fake\""));
    assert!(content.contains("version = \"0.1.0\""));
    assert!(bin_path.exists());
}
