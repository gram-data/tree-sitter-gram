use clap::Parser as CliParser;

/// Inspect all files given as arguments 
#[derive(CliParser, Debug)]
struct Args {
    /// Files to inspect
    #[clap(num_args = 1..)]
    files: Vec<std::path::PathBuf>,
}

use tree_sitter::{Parser, Language};

fn main() {

  let args = Args::parse();

  println!("Args: {:?}", args);

  let mut parser = Parser::new();

  parser.set_language(&tree_sitter_gram::language()).expect("Error loading Gram grammar");

  for file in args.files {
    println!("{}", "=".repeat(40));
    println!("Inspecting file: {:?}", file);
    let source_code = std::fs::read_to_string(file).expect("Error reading file");
    let tree = parser.parse(&source_code, None).unwrap();
    let root_node = tree.root_node();

    println!("{}", root_node);
    println!("");
  }
}
