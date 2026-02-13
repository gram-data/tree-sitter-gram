use clap::Parser;
use std::io::{self, Read};
use std::path::PathBuf;
use tree_sitter::{Node, Parser as TreeSitterParser};

/// A simple linter for gram notation files
#[derive(Parser, Debug)]
#[command(name = "gram-lint")]
#[command(about = "Lint gram notation files for parse errors")]
#[command(version = env!("CARGO_PKG_VERSION"))]
struct Args {
    /// Output the s-expression parse tree
    #[arg(short = 't', long = "tree")]
    tree: bool,

    /// Lint a gram expression directly (can be used multiple times)
    #[arg(short = 'e', long = "expression")]
    expressions: Vec<String>,

    /// Gram files to lint (use "-" or omit to read from stdin)
    #[arg(num_args = 0..)]
    files: Vec<PathBuf>,
}

fn report_errors(node: Node, source: &str, display_name: &str) -> bool {
    let mut found_errors = false;

    if node.is_error() {
        let start = node.start_position();
        let end = node.end_position();
        let text = node
            .utf8_text(source.as_bytes())
            .unwrap_or("<invalid utf8>");

        eprintln!(
            "{}:{}:{}: error: unexpected token(s)",
            display_name,
            start.row + 1,
            start.column + 1
        );

        // Show the line with the error
        if let Some(line) = source.lines().nth(start.row) {
            eprintln!("  | {}", line);
            eprintln!(
                "  | {}^{}",
                " ".repeat(start.column),
                "~".repeat((end.column - start.column).saturating_sub(1))
            );
        }

        eprintln!("  = unexpected: {:?}", text);
        found_errors = true;
    } else if node.is_missing() {
        let start = node.start_position();

        eprintln!(
            "{}:{}:{}: error: expected {}",
            display_name,
            start.row + 1,
            start.column + 1,
            node.kind()
        );

        // Show the line where the missing token was expected
        if let Some(line) = source.lines().nth(start.row) {
            eprintln!("  | {}", line);
            eprintln!("  | {}^", " ".repeat(start.column));
        }

        found_errors = true;
    }

    // Recurse through children
    let mut cursor = node.walk();
    for child in node.children(&mut cursor) {
        if report_errors(child, source, display_name) {
            found_errors = true;
        }
    }

    found_errors
}

fn main() {
    let args = Args::parse();

    let mut parser = TreeSitterParser::new();
    // Convert LanguageFn to Language using the raw function pointer
    let raw_fn = tree_sitter_gram::LANGUAGE.into_raw();
    let language = unsafe {
        let ptr = raw_fn();
        tree_sitter::Language::from_raw(ptr as *const tree_sitter::ffi::TSLanguage)
    };
    parser
        .set_language(&language)
        .expect("Error loading Gram grammar");

    let mut has_errors = false;

    // If expressions are provided, lint those instead of files/stdin
    if !args.expressions.is_empty() {
        for (index, expression) in args.expressions.iter().enumerate() {
            let display_name = if args.expressions.len() > 1 {
                format!("-e #{}", index + 1)
            } else {
                "-e".to_string()
            };

            let tree = parser.parse(expression, None).unwrap();
            let root_node = tree.root_node();

            if args.tree {
                println!("{}", root_node);
            }

            if root_node.has_error() {
                if report_errors(root_node, expression, &display_name) {
                    has_errors = true;
                }
            }
        }
    } else {
        // If no files provided, read from stdin
        let files: Vec<PathBuf> = if args.files.is_empty() {
            vec![PathBuf::from("-")]
        } else {
            args.files
        };

        for file in files {
            let (source_code, display_name) = if file.to_str() == Some("-") {
                // Read from stdin
                let mut buffer = String::new();
                match io::stdin().read_to_string(&mut buffer) {
                    Ok(_) => (buffer, "<stdin>".to_string()),
                    Err(e) => {
                        eprintln!("<stdin>: {}", e);
                        has_errors = true;
                        continue;
                    }
                }
            } else {
                // Read from file
                match std::fs::read_to_string(&file) {
                    Ok(content) => (content, file.display().to_string()),
                    Err(e) => {
                        eprintln!("{}: {}", file.display(), e);
                        has_errors = true;
                        continue;
                    }
                }
            };

            let tree = parser.parse(&source_code, None).unwrap();
            let root_node = tree.root_node();

            if args.tree {
                println!("{}", root_node);
            }

            if root_node.has_error() {
                if report_errors(root_node, &source_code, &display_name) {
                    has_errors = true;
                }
            }
        }
    }

    if has_errors {
        std::process::exit(1);
    }
}
