//! Duplicate **named** element introductions across top-level patterns in a `gram_pattern`.

use tree_sitter::Node;

use crate::diagnostics::{Diagnostic, DiagnosticSeverity};
use crate::elements::introducing_from_path_pattern;

/// Same rule as `subject_pattern_elements`: named introduction requires identifier plus labels
/// and/or record on the subject (or equivalent on the pattern). Anonymous top-level patterns
/// are skipped.
pub fn duplicate_top_level_element_diagnostics(root: Node, source: &[u8]) -> Vec<Diagnostic> {
    let mut out = Vec::new();
    let gram = if root.kind() == "gram_pattern" {
        root
    } else {
        return out;
    };

    let mut seen: Vec<(String, usize, usize)> = Vec::new();
    let mut cursor = gram.walk();
    for child in gram.children(&mut cursor) {
        let spans = match child.kind() {
            "annotated_pattern" => child
                .child_by_field_name("elements")
                .map(|n| introducing_from_path_pattern(n, source))
                .unwrap_or_default(),
            "node_pattern" | "subject_pattern" | "relationship_pattern" => {
                introducing_from_path_pattern(child, source)
            }
            _ => continue,
        };

        for (name, start, end) in spans {
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

    out
}
