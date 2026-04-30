use assert_cmd::Command;
use predicates::prelude::*;
use std::io::Write;
use tempfile::NamedTempFile;

fn gram() -> Command {
    Command::cargo_bin("gram").unwrap()
}

#[test]
fn unknown_subcommand_without_path_binary_exits_2() {
    gram()
        .args(["unknown-subcommand-xyz-abc"])
        .assert()
        .code(2)
        .stderr(predicate::str::contains("unknown sub-command"))
        .stderr(predicate::str::contains("unknown-subcommand-xyz-abc"));
}

#[test]
fn unknown_subcommand_error_mentions_help() {
    gram()
        .args(["totally-unknown-zzzz"])
        .assert()
        .code(2)
        .stderr(predicate::str::contains("gram --help"));
}

#[test]
#[cfg(unix)]
fn path_binary_is_dispatched() {
    use std::os::unix::fs::PermissionsExt;

    let mut script = NamedTempFile::new().unwrap();
    writeln!(script, "#!/bin/sh\necho dispatched\nexit 0").unwrap();
    let script_path = script.into_temp_path();
    std::fs::set_permissions(&script_path, std::fs::Permissions::from_mode(0o755)).unwrap();

    // Rename to gram-testdispatch in a temp dir
    let dir = tempfile::tempdir().unwrap();
    let bin_path = dir.path().join("gram-testdispatch");
    std::fs::copy(&script_path, &bin_path).unwrap();
    std::fs::set_permissions(&bin_path, std::fs::Permissions::from_mode(0o755)).unwrap();

    // Prepend temp dir to PATH
    let original_path = std::env::var("PATH").unwrap_or_default();
    let new_path = format!("{}:{}", dir.path().display(), original_path);

    gram()
        .args(["testdispatch"])
        .env("PATH", &new_path)
        .assert()
        .success()
        .stdout(predicate::str::contains("dispatched"));
}

#[test]
#[cfg(unix)]
fn path_binary_receives_arguments() {
    use std::os::unix::fs::PermissionsExt;

    let mut script = NamedTempFile::new().unwrap();
    writeln!(script, "#!/bin/sh\necho \"args: $@\"\nexit 0").unwrap();
    let script_path = script.into_temp_path();
    std::fs::set_permissions(&script_path, std::fs::Permissions::from_mode(0o755)).unwrap();

    let dir = tempfile::tempdir().unwrap();
    let bin_path = dir.path().join("gram-testargs");
    std::fs::copy(&script_path, &bin_path).unwrap();
    std::fs::set_permissions(&bin_path, std::fs::Permissions::from_mode(0o755)).unwrap();

    let original_path = std::env::var("PATH").unwrap_or_default();
    let new_path = format!("{}:{}", dir.path().display(), original_path);

    gram()
        .args(["testargs", "foo", "bar"])
        .env("PATH", &new_path)
        .assert()
        .success()
        .stdout(predicate::str::contains("args: foo bar"));
}

#[test]
fn builtin_check_not_dispatched_to_path() {
    // Even if gram-check existed on PATH, `gram check` should use the built-in.
    // We test this by verifying that `gram check --help` works (built-in behavior).
    gram()
        .args(["check", "--help"])
        .assert()
        .success()
        .stdout(predicate::str::contains("Validate"));
}
