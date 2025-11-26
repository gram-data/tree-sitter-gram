use clap::Parser;
use std::io::{self, Read};
use std::path::PathBuf;
use tree_sitter::Parser as TreeSitterParser;

/// A simple linter for gram notation files
#[derive(Parser, Debug)]
#[command(name = "gram-lint")]
#[command(about = "Lint gram notation files for parse errors")]
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
                eprintln!("{}: parse error", display_name);
                has_errors = true;
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
                eprintln!("{}: parse error", display_name);
                has_errors = true;
            }
        }
    }

    if has_errors {
        std::process::exit(1);
    }
}

