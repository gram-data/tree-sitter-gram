use assert_cmd::Command;
use predicates::prelude::*;
use std::fs;
use tempfile::TempDir;

fn gram() -> Command {
    Command::cargo_bin("gram").unwrap()
}

// --- install ---

#[test]
fn skill_install_no_agents_detected() {
    let dir = TempDir::new().unwrap();
    gram()
        .args(["skill", "install"])
        .current_dir(dir.path())
        .assert()
        .success()
        .stdout(predicate::str::contains("No gram-compatible agents detected"));
}

#[test]
fn skill_install_project_local_claude() {
    let dir = TempDir::new().unwrap();
    fs::create_dir(dir.path().join(".claude")).unwrap();

    gram()
        .args(["skill", "install"])
        .current_dir(dir.path())
        .assert()
        .success()
        .stdout(predicate::str::contains("claude"));

    let installed = dir.path().join(".claude/skills/gram/SKILL.md");
    assert!(installed.exists(), "SKILL.md should be installed for claude");

    let content = fs::read_to_string(&installed).unwrap();
    assert!(content.contains("name: gram"), "installed SKILL.md should contain 'name: gram'");
}

#[test]
fn skill_install_overwrites_with_warning() {
    let dir = TempDir::new().unwrap();
    let skill_dir = dir.path().join(".claude/skills/gram");
    fs::create_dir_all(&skill_dir).unwrap();
    fs::write(skill_dir.join("SKILL.md"), "old content").unwrap();

    gram()
        .args(["skill", "install"])
        .current_dir(dir.path())
        .assert()
        .success()
        .stdout(predicate::str::contains("overwritten"));

    let content = fs::read_to_string(skill_dir.join("SKILL.md")).unwrap();
    assert_ne!(content, "old content", "file should have been overwritten");
}

#[test]
fn skill_install_agent_flag_restricts_target() {
    let dir = TempDir::new().unwrap();
    fs::create_dir(dir.path().join(".claude")).unwrap();
    fs::create_dir(dir.path().join(".cursor")).unwrap();

    gram()
        .args(["skill", "install", "--agent", "claude"])
        .current_dir(dir.path())
        .assert()
        .success();

    assert!(dir.path().join(".claude/skills/gram/SKILL.md").exists());
    assert!(!dir.path().join(".cursor/skills/gram/SKILL.md").exists(),
        "cursor should not have been installed when --agent claude was specified");
}

#[test]
fn skill_install_unknown_agent_exits_2() {
    let dir = TempDir::new().unwrap();
    gram()
        .args(["skill", "install", "--agent", "bogus"])
        .current_dir(dir.path())
        .assert()
        .failure()
        .code(2)
        .stderr(predicate::str::contains("unknown agent"))
        .stderr(predicate::str::contains("claude"));
}

// --- list ---

#[test]
fn skill_list_nothing_installed() {
    let dir = TempDir::new().unwrap();
    gram()
        .args(["skill", "list"])
        .current_dir(dir.path())
        .assert()
        .success()
        .stdout(predicate::str::contains("No gram skill installations found"));
}

#[test]
fn skill_list_shows_installed() {
    let dir = TempDir::new().unwrap();
    let skill_dir = dir.path().join(".cursor/skills/gram");
    fs::create_dir_all(&skill_dir).unwrap();
    fs::write(skill_dir.join("SKILL.md"), "---\nname: gram\n---\n").unwrap();

    gram()
        .args(["skill", "list"])
        .current_dir(dir.path())
        .assert()
        .success()
        .stdout(predicate::str::contains("cursor"));
}

// --- remove ---

#[test]
fn skill_remove_not_installed() {
    let dir = TempDir::new().unwrap();
    gram()
        .args(["skill", "remove"])
        .current_dir(dir.path())
        .assert()
        .success()
        .stdout(predicate::str::contains("not installed"));
}

#[test]
fn skill_list_and_remove_roundtrip() {
    let dir = TempDir::new().unwrap();
    fs::create_dir(dir.path().join(".claude")).unwrap();

    // install
    gram()
        .args(["skill", "install"])
        .current_dir(dir.path())
        .assert()
        .success();

    // list shows it
    gram()
        .args(["skill", "list"])
        .current_dir(dir.path())
        .assert()
        .success()
        .stdout(predicate::str::contains("claude"));

    // remove
    gram()
        .args(["skill", "remove"])
        .current_dir(dir.path())
        .assert()
        .success()
        .stdout(predicate::str::contains("removed"));

    // list shows nothing
    gram()
        .args(["skill", "list"])
        .current_dir(dir.path())
        .assert()
        .success()
        .stdout(predicate::str::contains("No gram skill installations found"));
}

#[test]
fn skill_remove_unknown_agent_exits_2() {
    let dir = TempDir::new().unwrap();
    gram()
        .args(["skill", "remove", "--agent", "bogus"])
        .current_dir(dir.path())
        .assert()
        .failure()
        .code(2)
        .stderr(predicate::str::contains("unknown agent"));
}
