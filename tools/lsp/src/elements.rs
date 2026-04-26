//! Per-file duplicate **named** element-introducing definitions under `subject_pattern_elements`
//! (comma-separated list after `|`). See `top_level.rs` for duplicates across file-level patterns.

use tree_sitter::Node;

use crate::diagnostics::{Diagnostic, DiagnosticSeverity};

/// Direct children of `subject_pattern_elements` that introduce a **named** subject (`identifier` field).
/// Anonymous subjects (labels-only, record-only, etc.) are skipped per spec.
pub fn duplicate_element_diagnostics(root: Node, source: &[u8]) -> Vec<Diagnostic> {
    let mut out = Vec::new();
    walk(root, source, &mut out);
    out
}

fn walk(node: Node, source: &[u8], out: &mut Vec<Diagnostic>) {
    if node.kind() == "subject_pattern_elements" {
        check_elements_list(node, source, out);
    }
    let mut c = node.walk();
    for child in node.children(&mut c) {
        walk(child, source, out);
    }
}

fn check_elements_list(elements: Node, source: &[u8], out: &mut Vec<Diagnostic>) {
    let mut seen: Vec<(String, usize, usize)> = Vec::new();
    let mut cursor = elements.walk();
    for child in elements.children(&mut cursor) {
        if let Some((name, start, end)) = direct_child_introducing_name(child, source) {
            if let Some((_, first_start, first_end)) = seen.iter().find(|(n, _, _)| n == &name) {
                out.push(Diagnostic {
                    start_byte: start,
                    end_byte: end,
                    message: format!(
                        "duplicate element-introducing name `{name}` (first at bytes {first_start}..{first_end})"
                    ),
                    severity: DiagnosticSeverity::Error,
                    code: Some("duplicate-element".into()),
                });
            } else {
                seen.push((name, start, end));
            }
        }
    }
}

/// `subject_pattern` / `node_pattern` direct children of `subject_pattern_elements` with a named `identifier`.
fn direct_child_introducing_name(node: Node, source: &[u8]) -> Option<(String, usize, usize)> {
    match node.kind() {
        "subject_pattern" | "node_pattern" => pattern_introducing_name(node, source),
        _ => None,
    }
}

/// Parser emits `identifier` + optional `labels`/`record` on `node_pattern` / `subject_pattern` (not always `subject:` wrapper).
pub(crate) fn pattern_introducing_name(pattern: Node, source: &[u8]) -> Option<(String, usize, usize)> {
    if let Some(subject) = pattern.child_by_field_name("subject") {
        if let Some(span) = subject_named_identifier_span(subject, source) {
            return Some(span);
        }
    }
    if let Some(id) = pattern.child_by_field_name("identifier") {
        let has_labels = pattern.child_by_field_name("labels").is_some();
        let has_record = pattern.child_by_field_name("record").is_some();
        if !has_labels && !has_record {
            return None;
        }
        let text = id.utf8_text(source).ok()?.to_string();
        if text.is_empty() {
            return None;
        }
        return Some((text, id.start_byte(), id.end_byte()));
    }
    None
}

fn subject_named_identifier_span(subject: Node, source: &[u8]) -> Option<(String, usize, usize)> {
    let id = subject.child_by_field_name("identifier")?;
    let has_labels = subject.child_by_field_name("labels").is_some();
    let has_record = subject.child_by_field_name("record").is_some();
    if !has_labels && !has_record {
        return None;
    }
    let text = id.utf8_text(source).ok()?.to_string();
    if text.is_empty() {
        return None;
    }
    Some((text, id.start_byte(), id.end_byte()))
}

/// Introducing names from a `node_pattern`, `subject_pattern`, or `relationship_pattern` subtree
/// (used for top-level duplicate checks and relationship chains).
pub(crate) fn introducing_from_path_pattern(node: Node, source: &[u8]) -> Vec<(String, usize, usize)> {
    match node.kind() {
        "node_pattern" | "subject_pattern" => pattern_introducing_name(node, source)
            .into_iter()
            .collect(),
        "relationship_pattern" => {
            let mut v = Vec::new();
            if let Some(left) = node.child_by_field_name("left") {
                v.extend(introducing_from_path_pattern(left, source));
            }
            if let Some(right) = node.child_by_field_name("right") {
                v.extend(introducing_from_path_pattern(right, source));
            }
            v
        }
        _ => Vec::new(),
    }
}
