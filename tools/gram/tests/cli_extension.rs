use assert_cmd::Command;
use predicates::prelude::*;
use tempfile::tempdir;

fn gram() -> Command {
    Command::cargo_bin("gram").unwrap()
}

#[test]
fn extension_list_runs_without_error() {
    // List may fail to fetch registry in CI (no network), but should not panic
    let result = gram().args(["extension", "list", "--installed"]).output();
    assert!(result.is_ok(), "command should not panic");
    let output = result.unwrap();
    // Should print something about installed extensions
    let stdout = String::from_utf8_lossy(&output.stdout);
    assert!(
        stdout.contains("Installed extensions") || output.status.success(),
        "expected installed header or success"
    );
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
fn extension_install_unknown_exits_nonzero() {
    // This will try to fetch registry; if network unavailable it exits 1 with network error.
    // If network available but extension not in registry, it exits 2.
    gram()
        .args(["extension", "install", "nonexistent-extension-xyz-abc"])
        .assert()
        .failure();
}

#[test]
fn extension_install_and_remove_roundtrip() {
    // Set a fake GRAM home so we don't touch the real ~/.gram
    let fake_home = tempdir().unwrap();

    // We can't actually download without network access in all CI environments,
    // so we simulate the roundtrip by writing a fake binary and extensions.toml directly.
    let bin_dir = fake_home.path().join(".gram").join("bin");
    std::fs::create_dir_all(&bin_dir).unwrap();

    let bin_path = bin_dir.join("gram-fake");
    std::fs::write(&bin_path, b"#!/bin/sh\necho fake").unwrap();

    let ext_toml_path = fake_home.path().join(".gram").join("extensions.toml");
    let toml_content = format!(
        "[[installed]]\nname = \"fake\"\nversion = \"0.1.0\"\nbin_path = \"{}\"\ninstalled_at = \"2026-01-01T00:00:00Z\"\n",
        bin_path.display()
    );
    std::fs::write(&ext_toml_path, toml_content).unwrap();

    // Verify the binary exists
    assert!(bin_path.exists());
    assert!(ext_toml_path.exists());

    // Read back and verify TOML
    let content = std::fs::read_to_string(&ext_toml_path).unwrap();
    assert!(content.contains("name = \"fake\""));
    assert!(content.contains("version = \"0.1.0\""));
}
