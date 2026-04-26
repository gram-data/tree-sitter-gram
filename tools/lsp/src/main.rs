//! Gram LSP server and CLI (`gram-lsp`).

use std::path::PathBuf;

use clap::{Parser, Subcommand};
use serde::Serialize;

#[derive(Parser, Debug)]
#[command(name = "gram-lsp")]
#[command(about = "Language server and diagnostics for Gram notation")]
#[command(version = env!("CARGO_PKG_VERSION"))]
struct Args {
    #[command(subcommand)]
    command: Command,
}

#[derive(Subcommand, Debug)]
enum Command {
    /// Run the LSP server over stdio (JSON-RPC).
    Stdio,
    /// Check `.gram` files and emit diagnostics (use `--json` for machine output).
    Check {
        /// Emit `cli-diagnostics` JSON (schema_version 1) on stdout
        #[arg(long)]
        json: bool,
        /// Paths to `.gram` files or directories
        #[arg(required = true)]
        paths: Vec<PathBuf>,
    },
}

#[derive(Serialize)]
struct CheckOutput {
    schema_version: u32,
    files: Vec<FileOut>,
}

#[derive(Serialize)]
struct FileOut {
    path: String,
    diagnostics: Vec<JsonDiag>,
}

#[derive(Serialize)]
struct JsonDiag {
    range: JsonRange,
    severity: u8,
    message: String,
    #[serde(skip_serializing_if = "Option::is_none")]
    source: Option<String>,
    #[serde(skip_serializing_if = "Option::is_none")]
    code: Option<String>,
}

#[derive(Serialize)]
struct JsonRange {
    start: JsonPos,
    end: JsonPos,
}

#[derive(Serialize)]
struct JsonPos {
    line: u32,
    character: u32,
}

fn main() {
    let args = Args::parse();
    let rt = tokio::runtime::Builder::new_multi_thread()
        .enable_all()
        .build()
        .expect("runtime");
    match args.command {
        Command::Stdio => {
            if let Err(e) = rt.block_on(gram_lsp::run_stdio()) {
                eprintln!("gram-lsp: {e}");
                std::process::exit(1);
            }
        }
        Command::Check { json, paths } => {
            let code = run_check(&paths, json);
            std::process::exit(code);
        }
    }
}

/// Returns process exit code (0 = ok, 1 = errors).
fn run_check(paths: &[PathBuf], json: bool) -> i32 {
    let mut files_out = Vec::new();
    let mut has_error = false;
    let mut file_list = Vec::new();
    for p in paths {
        collect_gram_paths(p, &mut file_list);
    }
    if file_list.is_empty() {
        eprintln!("gram-lsp: no .gram files found");
        return 1;
    }
    for path in file_list {
        let display = path.display().to_string();
        let text = match std::fs::read_to_string(&path) {
            Ok(t) => t,
            Err(e) => {
                eprintln!("{display}: {e}");
                has_error = true;
                continue;
            }
        };
        let (_, diags) = gram_lsp::analyze_source(&text);
        if diags
            .iter()
            .any(|d| matches!(d.severity, gram_lsp::DiagnosticSeverity::Error))
        {
            has_error = true;
        }
        let jd: Vec<JsonDiag> = diags
            .iter()
            .map(|d| {
                let ((sl, sc), (el, ec)) =
                    gram_lsp::utf16::byte_range_to_lsp_range(&text, d.start_byte, d.end_byte);
                JsonDiag {
                    range: JsonRange {
                        start: JsonPos {
                            line: sl,
                            character: sc,
                        },
                        end: JsonPos {
                            line: el,
                            character: ec,
                        },
                    },
                    severity: match d.severity {
                        gram_lsp::DiagnosticSeverity::Error => 1,
                        gram_lsp::DiagnosticSeverity::Warning => 2,
                        gram_lsp::DiagnosticSeverity::Information => 3,
                        gram_lsp::DiagnosticSeverity::Hint => 4,
                    },
                    message: d.message.clone(),
                    source: Some("gram-lsp".into()),
                    code: d.code.clone(),
                }
            })
            .collect();
        files_out.push(FileOut {
            path: display,
            diagnostics: jd,
        });
    }
    if json {
        let out = CheckOutput {
            schema_version: 1,
            files: files_out,
        };
        println!("{}", serde_json::to_string_pretty(&out).expect("json"));
    } else {
        for f in &files_out {
            for d in &f.diagnostics {
                eprintln!(
                    "{}:{}:{}: {:?}: {}",
                    f.path,
                    d.range.start.line + 1,
                    d.range.start.character + 1,
                    d.severity,
                    d.message
                );
            }
        }
    }
    i32::from(has_error)
}

fn collect_gram_paths(p: &PathBuf, out: &mut Vec<PathBuf>) {
    if p.is_file() {
        if p.extension().and_then(|s| s.to_str()) == Some("gram") {
            out.push(p.clone());
        }
        return;
    }
    if p.is_dir() {
        if let Ok(rd) = std::fs::read_dir(p) {
            for e in rd.flatten() {
                collect_gram_paths(&e.path(), out);
            }
        }
    }
}
