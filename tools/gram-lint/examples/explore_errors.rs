use tree_sitter::Parser as TreeSitterParser;

fn find_errors(node: tree_sitter::Node, source: &str, depth: usize) {
    let indent = "  ".repeat(depth);

    if node.is_error() {
        let start = node.start_position();
        let end = node.end_position();
        let text = node
            .utf8_text(source.as_bytes())
            .unwrap_or("<invalid utf8>");

        println!(
            "{}ERROR at line {}, column {}:",
            indent,
            start.row + 1,
            start.column + 1
        );
        println!("{}  Text: {:?}", indent, text);
        println!(
            "{}  Range: [{},{}] to [{},{}]",
            indent,
            start.row + 1,
            start.column + 1,
            end.row + 1,
            end.column + 1
        );
        println!("{}  Kind: {}", indent, node.kind());
    } else if node.is_missing() {
        let start = node.start_position();
        println!(
            "{}MISSING {} at line {}, column {}",
            indent,
            node.kind(),
            start.row + 1,
            start.column + 1
        );
    }

    // Recurse through children
    let mut cursor = node.walk();
    for child in node.children(&mut cursor) {
        find_errors(child, source, depth + 1);
    }
}

fn main() {
    let mut parser = TreeSitterParser::new();
    let raw_fn = tree_sitter_gram::LANGUAGE.into_raw();
    let language = unsafe {
        let ptr = raw_fn();
        tree_sitter::Language::from_raw(ptr as *const tree_sitter::ffi::TSLanguage)
    };
    parser
        .set_language(&language)
        .expect("Error loading Gram grammar");

    let test_cases = vec![
        ("Valid", "(person {name: 'Bob'})"),
        (
            "Invalid tokens",
            "(person {name: 'Bob'} invalid syntax here)",
        ),
        ("Unclosed paren", "(person {name: 'Bob'}"),
        ("Unclosed record", "(person {name: 'Bob')"),
        ("Invalid property", "(person {name:})"),
    ];

    for (label, source) in test_cases {
        println!("\n{}", "=".repeat(50));
        println!("Test: {}", label);
        println!("Source: {}", source);
        println!("{}", "-".repeat(50));

        let tree = parser.parse(source, None).unwrap();
        let root = tree.root_node();

        if root.has_error() {
            find_errors(root, source, 0);
        } else {
            println!("No errors found");
        }
    }
}
