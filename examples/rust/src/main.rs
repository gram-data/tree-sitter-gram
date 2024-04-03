use tree_sitter::{Parser, Language};

fn main() {

  let mut parser = Parser::new();

  parser.set_language(&tree_sitter_gram::language()).expect("Error loading Gram grammar");

  let source_code = "(hello)-->(world)";
  let tree = parser.parse(source_code, None).unwrap();
  let root_node = tree.root_node();

  println!("root_node: {:?}", root_node.to_string());
}
