use tree_sitter::{Node, Tree};

use crate::elements;
use crate::record_keys;
use crate::top_level;
use crate::utf16;

/// Internal diagnostic with byte offsets; converted to `gram_diagnostics::Diagnostic` by callers.
#[derive(Clone, Debug)]
pub(crate) struct Diagnostic {
    pub start_byte: usize,
    pub end_byte: usize,
    pub message: String,
    pub severity: DiagnosticSeverity,
    pub code: Option<String>,
    pub help: Option<String>,
}

#[derive(Clone, Debug)]
pub(crate) enum DiagnosticSeverity {
    Error,
    #[allow(dead_code)] // reserved for future semantic rules
    Warning,
}

pub(crate) fn analyze_source(source: &str) -> (Tree, Vec<Diagnostic>) {
    let tree = crate::parse::parse(source);
    let mut diags = Vec::new();
    collect_syntax_errors(tree.root_node(), source.as_bytes(), &mut diags);
    diags.extend(elements::duplicate_element_diagnostics(tree.root_node(), source.as_bytes()));
    diags.extend(top_level::duplicate_top_level_element_diagnostics(
        tree.root_node(),
        source.as_bytes(),
    ));
    diags.extend(record_keys::duplicate_key_diagnostics(tree.root_node(), source.as_bytes()));
    diags.sort_by_key(|d| (d.start_byte, d.end_byte));
    (tree, diags)
}

/// Convert `RawDiagnostic` to the public `gram_diagnostics::Diagnostic` using the full source
/// for position conversion.
pub(crate) fn to_public(source: &str, d: &Diagnostic) -> gram_diagnostics::Diagnostic {
    let ((sl, sc), (el, ec)) = utf16::byte_range_to_lsp_range(source, d.start_byte, d.end_byte);
    gram_diagnostics::Diagnostic {
        severity: match d.severity {
            DiagnosticSeverity::Error => gram_diagnostics::Severity::Error,
            DiagnosticSeverity::Warning => gram_diagnostics::Severity::Warning,
        },
        rule: d.code.clone().unwrap_or_default(),
        message: d.message.clone(),
        range: gram_diagnostics::Range {
            start: gram_diagnostics::Position { line: sl, character: sc },
            end: gram_diagnostics::Position { line: el, character: ec },
        },
        code: d.code.clone(),
        help: d.help.clone(),
    }
}

fn collect_syntax_errors(node: Node, source: &[u8], out: &mut Vec<Diagnostic>) {
    if node.is_error() {
        let token = node.utf8_text(source).unwrap_or("");
        out.push(Diagnostic {
            start_byte: node.start_byte(),
            end_byte: node.end_byte(),
            message: if token.is_empty() {
                "invalid syntax".into()
            } else {
                format!("unexpected: {token:?}")
            },
            severity: DiagnosticSeverity::Error,
            code: Some("syntax-error".into()),
            help: syntax_error_help(token),
        });
    } else if node.is_missing() {
        out.push(Diagnostic {
            start_byte: node.start_byte(),
            end_byte: node.end_byte(),
            message: format!("expected {}", node.kind()),
            severity: DiagnosticSeverity::Error,
            code: Some("missing-node".into()),
            help: missing_node_help(node.kind()),
        });
    }
    let mut cursor = node.walk();
    for child in node.children(&mut cursor) {
        collect_syntax_errors(child, source, out);
    }
}

fn syntax_error_help(token: &str) -> Option<String> {
    let t = token.trim();
    if t.starts_with('#') {
        Some("\"#\" is not valid in a node pattern; labels use a colon prefix, e.g. (node:Label), not (node#Tag)".into())
    } else if t.chars().next().map_or(false, |c| c.is_ascii_digit()) {
        Some("identifiers must start with a letter or underscore, e.g. use `counter` not `2counter`".into())
    } else {
        None
    }
}

fn missing_node_help(kind: &str) -> Option<String> {
    match kind {
        ")" => Some("opening \"(\" has no matching \")\"".into()),
        "]" => Some("opening \"[\" has no matching \"]\"".into()),
        _ => None,
    }
}
