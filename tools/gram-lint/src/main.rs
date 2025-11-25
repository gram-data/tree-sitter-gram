use clap::Parser;
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

    /// Gram files to lint
    #[arg(num_args = 1..)]
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

    for file in args.files {
        let source_code = match std::fs::read_to_string(&file) {
            Ok(content) => content,
            Err(e) => {
                eprintln!("{}: {}", file.display(), e);
                has_errors = true;
                continue;
            }
        };

        let tree = parser.parse(&source_code, None).unwrap();
        let root_node = tree.root_node();

        if args.tree {
            println!("{}", root_node);
        }

        if root_node.has_error() {
            eprintln!("{}: parse error", file.display());
            has_errors = true;
        }
    }

    if has_errors {
        std::process::exit(1);
    }
}

