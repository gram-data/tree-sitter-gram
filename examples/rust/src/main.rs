use clap::Parser as CliParser;
use tree_sitter::{Node, Parser};

/// Inspect all .gram files given as arguments
#[derive(CliParser, Debug)]
struct Args {
    /// Files to inspect
    #[clap(num_args = 1..)]
    files: Vec<std::path::PathBuf>,
}

fn main() {
    let args = Args::parse();

    let mut parser = Parser::new();
    parser
        .set_language(&tree_sitter_gram::LANGUAGE.into())
        .expect("Error loading Gram grammar");

    for file in &args.files {
        println!("{}", "=".repeat(40));
        println!("Inspecting file: {:?}", file);
        let source_code = std::fs::read_to_string(file).expect("Error reading file");
        let tree = parser.parse(&source_code, None).unwrap();
        let root = tree.root_node();

        println!("Parse tree:");
        println!("{}", root.to_sexp());

        let mut nodes = 0u32;
        let mut relationships = 0u32;
        walk(root, &source_code, &mut nodes, &mut relationships);

        println!(
            "\nSummary: {} nodes, {} relationships",
            nodes, relationships
        );
    }
}

fn walk(node: Node, source: &str, nodes: &mut u32, relationships: &mut u32) {
    match node.kind() {
        "node_pattern" => {
            *nodes += 1;
            println!("  node: {}", &source[node.byte_range()]);
        }
        "relationship_pattern" => {
            *relationships += 1;
            println!("  relationship: {}", &source[node.byte_range()]);
        }
        _ => {}
    }
    for i in 0..node.child_count() {
        walk(node.child(i).unwrap(), source, nodes, relationships);
    }
}
