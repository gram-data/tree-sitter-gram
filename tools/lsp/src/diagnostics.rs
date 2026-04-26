use tower_lsp::lsp_types as lsp;
use tree_sitter::{Node, Tree};

use crate::elements;
use crate::record_keys;
use crate::top_level;
use crate::utf16;

#[derive(Clone, Debug, PartialEq, Eq)]
pub enum DiagnosticSeverity {
    Error,
    Warning,
    Information,
    Hint,
}

#[derive(Clone, Debug)]
pub struct Diagnostic {
    pub start_byte: usize,
    pub end_byte: usize,
    pub message: String,
    pub severity: DiagnosticSeverity,
    pub code: Option<String>,
}

/// Full analysis: syntax (parse tree ERROR / MISSING) + semantic checks (duplicate
/// subject-pattern **elements**, duplicate **record** / **map** keys).
pub fn analyze_source(source: &str) -> (Tree, Vec<Diagnostic>) {
    let tree = crate::parse::parse(source);
    let mut diags = Vec::new();
    collect_syntax_nodes(tree.root_node(), source.as_bytes(), &mut diags);
    diags.extend(elements::duplicate_element_diagnostics(tree.root_node(), source.as_bytes()));
    diags.extend(top_level::duplicate_top_level_element_diagnostics(
        tree.root_node(),
        source.as_bytes(),
    ));
    diags.extend(record_keys::duplicate_key_diagnostics(
        tree.root_node(),
        source.as_bytes(),
    ));
    diags.sort_by_key(|d| (d.start_byte, d.end_byte));
    (tree, diags)
}

fn collect_syntax_nodes(node: Node, source: &[u8], out: &mut Vec<Diagnostic>) {
    if node.is_error() {
        let msg = node
            .utf8_text(source)
            .map(|t| format!("unexpected: {t:?}"))
            .unwrap_or_else(|_| "invalid syntax".into());
        out.push(Diagnostic {
            start_byte: node.start_byte(),
            end_byte: node.end_byte(),
            message: msg,
            severity: DiagnosticSeverity::Error,
            code: Some("syntax-error".into()),
        });
    } else if node.is_missing() {
        let msg = format!("expected {}", node.kind());
        out.push(Diagnostic {
            start_byte: node.start_byte(),
            end_byte: node.end_byte(),
            message: msg,
            severity: DiagnosticSeverity::Error,
            code: Some("missing-node".into()),
        });
    }
    let mut cursor = node.walk();
    for child in node.children(&mut cursor) {
        collect_syntax_nodes(child, source, out);
    }
}

/// Convert to LSP `Diagnostic` with UTF-16 ranges.
pub fn to_lsp_diagnostic(source: &str, d: &Diagnostic) -> lsp::Diagnostic {
    let ((start_line, start_char), (end_line, end_char)) =
        utf16::byte_range_to_lsp_range(source, d.start_byte, d.end_byte);
    lsp::Diagnostic {
        range: lsp::Range {
            start: lsp::Position {
                line: start_line,
                character: start_char,
            },
            end: lsp::Position {
                line: end_line,
                character: end_char,
            },
        },
        severity: Some(match d.severity {
            DiagnosticSeverity::Error => lsp::DiagnosticSeverity::ERROR,
            DiagnosticSeverity::Warning => lsp::DiagnosticSeverity::WARNING,
            DiagnosticSeverity::Information => lsp::DiagnosticSeverity::INFORMATION,
            DiagnosticSeverity::Hint => lsp::DiagnosticSeverity::HINT,
        }),
        code: d.code.clone().map(lsp::NumberOrString::String),
        source: Some("gram-lsp".into()),
        message: d.message.clone(),
        ..Default::default()
    }
}
