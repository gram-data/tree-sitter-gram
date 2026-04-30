use assert_cmd::Command;
use predicates::prelude::*;
use std::io::Write;
use tempfile::NamedTempFile;

fn gram() -> Command {
    Command::cargo_bin("gram").unwrap()
}

#[test]
fn valid_file_exits_zero() {
    gram()
        .args(["check", "tests/fixtures/valid.gram"])
        .assert()
        .success()
        .stderr(predicate::str::is_empty());
}

#[test]
fn invalid_file_exits_one() {
    gram()
        .args(["check", "tests/fixtures/invalid.gram"])
        .assert()
        .code(1)
        .stderr(predicate::str::contains("error"));
}

#[test]
fn invalid_file_reports_filename() {
    gram()
        .args(["check", "tests/fixtures/invalid.gram"])
        .assert()
        .code(1)
        .stderr(predicate::str::contains("invalid.gram"));
}

#[test]
fn expression_valid_exits_zero() {
    gram()
        .args(["check", "-e", "(alice)-[:KNOWS]->(bob)"])
        .assert()
        .success();
}

#[test]
fn expression_invalid_exits_one() {
    gram()
        .args(["check", "-e", "(alice)-[:KNOWS->(bob)"])
        .assert()
        .code(1);
}

#[test]
fn json_output_has_schema_version() {
    let output = gram()
        .args(["check", "--json", "tests/fixtures/valid.gram"])
        .assert()
        .success()
        .get_output()
        .stdout
        .clone();

    let json: serde_json::Value = serde_json::from_slice(&output).expect("valid JSON");
    assert_eq!(json["schema_version"], 1);
    assert!(json["tool"].as_str().unwrap_or("").starts_with("gram/"));
    assert!(json["files"].is_array());
}

#[test]
fn json_output_invalid_file_has_diagnostics() {
    let output = gram()
        .args(["check", "--json", "tests/fixtures/invalid.gram"])
        .assert()
        .code(1)
        .get_output()
        .stdout
        .clone();

    let json: serde_json::Value = serde_json::from_slice(&output).expect("valid JSON");
    let files = json["files"].as_array().expect("files array");
    assert!(!files.is_empty());
    let diags = files[0]["diagnostics"].as_array().expect("diagnostics array");
    assert!(!diags.is_empty());
    assert_eq!(diags[0]["severity"], "error");
}

#[test]
fn tree_output_is_sexp() {
    gram()
        .args(["check", "--tree", "tests/fixtures/valid.gram"])
        .assert()
        .success()
        .stdout(predicate::str::starts_with("("));
}

#[test]
fn directory_with_gram_files() {
    gram()
        .args(["check", "tests/fixtures/"])
        .assert()
        .code(1); // invalid.gram is in there
}

#[test]
fn empty_directory_exits_zero() {
    let dir = tempfile::tempdir().unwrap();
    gram()
        .args(["check", dir.path().to_str().unwrap()])
        .assert()
        .success()
        .stderr(predicate::str::contains("no .gram files"));
}

#[test]
fn stdin_valid_exits_zero() {
    gram()
        .args(["check"])
        .write_stdin("(a)-[:R]->(b)\n")
        .assert()
        .success();
}

#[test]
fn stdin_invalid_exits_one() {
    gram()
        .args(["check"])
        .write_stdin("(a)-[:R->(b)\n")
        .assert()
        .code(1);
}

#[test]
fn strict_flag_treats_warnings_as_errors() {
    // A valid file should have no warnings so --strict still exits 0
    gram()
        .args(["check", "--strict", "tests/fixtures/valid.gram"])
        .assert()
        .success();
}

#[test]
fn multiple_files_all_checked() {
    gram()
        .args([
            "check",
            "tests/fixtures/valid.gram",
            "tests/fixtures/invalid.gram",
        ])
        .assert()
        .code(1)
        .stderr(predicate::str::contains("invalid.gram"));
}

#[test]
fn tempfile_valid_content() {
    let mut f = NamedTempFile::with_suffix(".gram").unwrap();
    writeln!(f, "(x:Foo)-[:BAR]->(y:Baz)").unwrap();
    gram()
        .args(["check", f.path().to_str().unwrap()])
        .assert()
        .success();
}
