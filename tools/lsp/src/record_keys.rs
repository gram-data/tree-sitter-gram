//! Duplicate keys within a single `record` or `map` literal.

use tree_sitter::Node;

use crate::diagnostics::{Diagnostic, DiagnosticSeverity};

pub fn duplicate_key_diagnostics(root: Node, source: &[u8]) -> Vec<Diagnostic> {
    let mut out = Vec::new();
    walk(root, source, &mut out);
    out
}

fn walk(node: Node, source: &[u8], out: &mut Vec<Diagnostic>) {
    match node.kind() {
        "record" => check_entries(node, source, "record_property", out),
        "map" => check_entries(node, source, "map_entry", out),
        _ => {}
    }
    let mut c = node.walk();
    for child in node.children(&mut c) {
        walk(child, source, out);
    }
}

fn check_entries(
    container: Node,
    source: &[u8],
    entry_kind: &str,
    out: &mut Vec<Diagnostic>,
) {
    let mut seen: Vec<(String, usize, usize)> = Vec::new();
    let mut c = container.walk();
    for child in container.children(&mut c) {
        if child.kind() != entry_kind {
            continue;
        }
        let Some(key) = child.child_by_field_name("key") else {
            continue;
        };
        let Some(id) = key_identity(key, source) else {
            continue;
        };
        let (start, end) = (key.start_byte(), key.end_byte());
        if let Some((_, first_start, first_end)) = seen.iter().find(|(k, _, _)| k == &id) {
            out.push(Diagnostic {
                start_byte: start,
                end_byte: end,
                message: format!(
                    "duplicate key `{id}` (first at bytes {first_start}..{first_end})"
                ),
                severity: DiagnosticSeverity::Error,
                code: Some("duplicate-key".into()),
            });
        } else {
            seen.push((id, start, end));
        }
    }
}

/// Human-readable key text for diagnostics and duplicate comparison.
fn key_identity(key: Node, source: &[u8]) -> Option<String> {
    match key.kind() {
        "symbol" => {
            let t = key.utf8_text(source).ok()?;
            if t.is_empty() {
                None
            } else {
                Some(t.to_string())
            }
        }
        "quoted_name" | "double_quoted_name" => {
            let mut c = key.walk();
            for ch in key.children(&mut c) {
                if ch.kind() == "string_content" {
                    let t = ch.utf8_text(source).ok()?;
                    return if t.is_empty() { None } else { Some(t.to_string()) };
                }
            }
            None
        }
        _ => None,
    }
}
