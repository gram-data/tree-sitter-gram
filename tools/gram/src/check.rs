use ariadne::{Color, Label, Report, ReportKind, sources};
use clap::Args;
use gram_lsp::{analyze_source, DiagnosticSeverity};
use gram_lsp::utf16::byte_range_to_lsp_range;
use std::io::{self, Read};
use std::path::PathBuf;
use walkdir::WalkDir;

use crate::types::{CheckResult, Diagnostic, FileResult, Position, Range, Severity};

#[derive(Args)]
#[command(about = "Validate .gram files for parse and semantic errors")]
pub struct CheckArgs {
    /// Validate an inline gram expression
    #[arg(short = 'e', long = "expression")]
    pub expression: Option<String>,

    /// Output diagnostics as machine-readable JSON
    #[arg(long, conflicts_with = "tree")]
    pub json: bool,

    /// Output the parse tree as an s-expression
    #[arg(long, conflicts_with = "json")]
    pub tree: bool,

    /// Treat warnings as errors (exit non-zero on any diagnostic)
    #[arg(long)]
    pub strict: bool,

    /// Files, directories, or paths to check (omit to read from stdin)
    #[arg(num_args = 0..)]
    pub paths: Vec<PathBuf>,
}

/// Raw result before any rendering — keeps the source text for ariadne.
struct SourceResult {
    path: String,
    source: String,
    diags: Vec<gram_lsp::Diagnostic>,
}

pub fn run(args: CheckArgs) -> i32 {
    if args.tree {
        return run_tree(&args);
    }

    let mut results: Vec<SourceResult> = Vec::new();

    if let Some(expr) = &args.expression {
        results.push(analyze(expr.clone(), "-e".to_string()));
    } else if args.paths.is_empty() {
        match read_stdin() {
            Ok(src) => results.push(analyze(src, "-".to_string())),
            Err(e) => {
                eprintln!("error reading stdin: {e}");
                return 2;
            }
        }
    } else {
        for path in &args.paths {
            if path.is_dir() {
                let mut found = false;
                for entry in WalkDir::new(path)
                    .into_iter()
                    .filter_map(|e| e.ok())
                    .filter(|e| e.path().extension().and_then(|s| s.to_str()) == Some("gram"))
                {
                    found = true;
                    match std::fs::read_to_string(entry.path()) {
                        Ok(src) => results.push(analyze(src, entry.path().display().to_string())),
                        Err(e) => {
                            eprintln!("{}: {e}", entry.path().display());
                            return 2;
                        }
                    }
                }
                if !found {
                    eprintln!("note: no .gram files found in {}", path.display());
                }
            } else {
                match std::fs::read_to_string(path) {
                    Ok(src) => results.push(analyze(src, path.display().to_string())),
                    Err(e) => {
                        eprintln!("{}: {e}", path.display());
                        return 2;
                    }
                }
            }
        }
    }

    let has_errors = results
        .iter()
        .any(|r| r.diags.iter().any(|d| matches!(d.severity, DiagnosticSeverity::Error)));
    let has_warnings = results
        .iter()
        .any(|r| r.diags.iter().any(|d| matches!(d.severity, DiagnosticSeverity::Warning)));

    if args.json {
        let check_result = CheckResult {
            schema_version: 1,
            tool: format!("gram/{}", env!("CARGO_PKG_VERSION")),
            files: results.iter().map(to_file_result).collect(),
        };
        match serde_json::to_string_pretty(&check_result) {
            Ok(json) => println!("{json}"),
            Err(e) => {
                eprintln!("error serializing JSON: {e}");
                return 2;
            }
        }
    } else {
        print_pretty(&results);
    }

    if has_errors || (args.strict && has_warnings) {
        1
    } else {
        0
    }
}

fn analyze(source: String, path: String) -> SourceResult {
    let (_, diags) = analyze_source(&source);
    SourceResult { path, source, diags }
}

fn to_file_result(r: &SourceResult) -> FileResult {
    let diagnostics = r
        .diags
        .iter()
        .map(|d| {
            let ((start_line, start_char), (end_line, end_char)) =
                byte_range_to_lsp_range(&r.source, d.start_byte, d.end_byte);
            Diagnostic {
                severity: match d.severity {
                    DiagnosticSeverity::Error => Severity::Error,
                    DiagnosticSeverity::Warning => Severity::Warning,
                    DiagnosticSeverity::Information => Severity::Information,
                    DiagnosticSeverity::Hint => Severity::Hint,
                },
                message: d.message.clone(),
                range: Range {
                    start: Position { line: start_line, character: start_char },
                    end: Position { line: end_line, character: end_char },
                },
                code: d.code.clone(),
            }
        })
        .collect();
    FileResult { path: r.path.clone(), diagnostics }
}

fn print_pretty(results: &[SourceResult]) {
    for r in results {
        for d in &r.diags {
            let kind = match d.severity {
                DiagnosticSeverity::Error => ReportKind::Error,
                DiagnosticSeverity::Warning => ReportKind::Warning,
                DiagnosticSeverity::Information | DiagnosticSeverity::Hint => ReportKind::Advice,
            };
            let color = match d.severity {
                DiagnosticSeverity::Error => Color::Red,
                DiagnosticSeverity::Warning => Color::Yellow,
                DiagnosticSeverity::Information | DiagnosticSeverity::Hint => Color::Cyan,
            };

            let start = byte_to_char(&r.source, d.start_byte);
            let end = byte_to_char(&r.source, d.end_byte).max(start + 1);

            let mut report = Report::build(kind, (r.path.clone(), start..end))
                .with_message(&d.message)
                .with_label(
                    Label::new((r.path.clone(), start..end))
                        .with_message(&d.message)
                        .with_color(color),
                );

            if let Some(code) = &d.code {
                report = report.with_code(code);
            }

            report
                .finish()
                .eprint(sources([(r.path.clone(), r.source.as_str())]))
                .ok();
        }
    }
}

fn byte_to_char(s: &str, byte: usize) -> usize {
    let byte = byte.min(s.len());
    // Snap back to a valid char boundary so we never slice mid-codepoint.
    let byte = (0..=byte).rev().find(|&i| s.is_char_boundary(i)).unwrap_or(0);
    s[..byte].chars().count()
}

fn run_tree(args: &CheckArgs) -> i32 {
    if args.paths.len() > 1 {
        eprintln!("error: --tree accepts at most one input");
        return 2;
    }
    let src = if let Some(expr) = &args.expression {
        expr.clone()
    } else if args.paths.is_empty() {
        match read_stdin() {
            Ok(s) => s,
            Err(e) => {
                eprintln!("error reading stdin: {e}");
                return 2;
            }
        }
    } else {
        match std::fs::read_to_string(&args.paths[0]) {
            Ok(s) => s,
            Err(e) => {
                eprintln!("{}: {e}", args.paths[0].display());
                return 2;
            }
        }
    };

    let tree = gram_lsp::parse(&src);
    println!("{}", tree.root_node().to_sexp());
    0
}

fn read_stdin() -> io::Result<String> {
    let mut buf = String::new();
    io::stdin().read_to_string(&mut buf)?;
    Ok(buf)
}
