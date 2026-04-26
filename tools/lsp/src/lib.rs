//! Shared analysis for the Gram LSP and `gram-lsp check` CLI.

pub mod diagnostics;
pub mod elements;
pub mod lsp;
pub mod record_keys;
pub mod top_level;
pub mod parse;
pub mod symbols;
pub mod utf16;

pub use diagnostics::{analyze_source, Diagnostic, DiagnosticSeverity};
pub use parse::{language, parse};
pub use symbols::SymbolIndex;

/// Run the language server on stdio (JSON-RPC over stdin/stdout).
pub async fn run_stdio() -> Result<(), Box<dyn std::error::Error + Send + Sync>> {
    lsp::run_stdio().await
}

#[cfg(test)]
mod analyze_tests {
    use super::*;

    #[test]
    fn duplicate_named_elements_in_list() {
        let src = "[ | (dup:Person), (dup:Movie) ]\n";
        let (_, diags) = analyze_source(src);
        assert!(
            diags
                .iter()
                .any(|d| d.code.as_deref() == Some("duplicate-element")),
            "{diags:?}"
        );
    }

    #[test]
    fn anonymous_nested_brackets_no_duplicate_element_diag() {
        let src = "[ | [], () ]\n";
        let (_, diags) = analyze_source(src);
        assert!(!diags
            .iter()
            .any(|d| d.code.as_deref() == Some("duplicate-element")));
    }

    #[test]
    fn duplicate_record_keys() {
        let src = "(:Person { name: 1, name: 2 })\n";
        let (_, diags) = analyze_source(src);
        assert!(
            diags.iter().any(|d| d.code.as_deref() == Some("duplicate-key")),
            "{diags:?}"
        );
    }

    #[test]
    fn distinct_record_keys_ok() {
        let src = "(:Person { name: 1, age: 2 })\n";
        let (_, diags) = analyze_source(src);
        assert!(!diags
            .iter()
            .any(|d| d.code.as_deref() == Some("duplicate-key")));
    }

    #[test]
    fn duplicate_top_level_node_patterns() {
        let src = "(dup:Person)\n(dup:Movie)\n";
        let (_, diags) = analyze_source(src);
        assert!(
            diags
                .iter()
                .filter(|d| d.code.as_deref() == Some("duplicate-element"))
                .count()
                >= 1,
            "{diags:?}"
        );
    }

    #[test]
    fn distinct_top_level_node_patterns_ok() {
        let src = "(a:Person)\n(b:Movie)\n";
        let (_, diags) = analyze_source(src);
        assert!(!diags
            .iter()
            .any(|d| d.code.as_deref() == Some("duplicate-element")));
    }

    #[test]
    fn duplicate_names_in_one_relationship_pattern() {
        let src = "(dup:Person)-->(dup:Movie)\n";
        let (_, diags) = analyze_source(src);
        assert!(
            diags
                .iter()
                .any(|d| d.code.as_deref() == Some("duplicate-element")),
            "{diags:?}"
        );
    }

    #[test]
    fn symbols_see_pattern_reference() {
        let src = "(a:Person)\n(b:Person)\n(a)-[]->(b)\n";
        let tree = parse::parse(src);
        let idx = SymbolIndex::from_tree(&tree, src.as_bytes());
        assert!(
            idx.refs.iter().any(|(n, _, _)| n == "a"),
            "refs: {:?}",
            idx.refs
        );
    }
}
