//! Definition / reference index aligned with the **current** Gram tree shape (see `grammar.js` / generated parser).
//!
//! `queries/locals.scm` still uses `node_pattern subject: ...` patterns; the parser emits `identifier`/`labels`
//! directly on `node_pattern`. Until queries are updated, this module uses a small AST walk so navigation works.

use tree_sitter::{Node, Tree};

#[derive(Debug, Default, Clone)]
pub struct SymbolIndex {
    /// (name, start_byte, end_byte)
    pub defs: Vec<(String, usize, usize)>,
    pub refs: Vec<(String, usize, usize)>,
}

impl SymbolIndex {
    pub fn from_tree(tree: &Tree, source: &[u8]) -> Self {
        let mut idx = SymbolIndex::default();
        walk(tree.root_node(), source, &mut idx);
        idx
    }

    /// First definition span in this index for `name` (stable file order).
    pub fn first_definition(&self, name: &str) -> Option<(usize, usize)> {
        self.defs
            .iter()
            .find(|(n, _, _)| n == name)
            .map(|(_, s, e)| (*s, *e))
    }

    pub fn all_references(&self, name: &str) -> Vec<(usize, usize)> {
        self.refs
            .iter()
            .filter(|(n, _, _)| n == name)
            .map(|(_, s, e)| (*s, *e))
            .collect()
    }

    pub fn reference_at(&self, byte_offset: usize) -> Option<&str> {
        self.refs
            .iter()
            .find(|(_, s, e)| *s <= byte_offset && byte_offset < *e)
            .map(|(n, _, _)| n.as_str())
    }

    pub fn definition_at(&self, byte_offset: usize) -> Option<&str> {
        self.defs
            .iter()
            .find(|(_, s, e)| *s <= byte_offset && byte_offset < *e)
            .map(|(n, _, _)| n.as_str())
    }
}

fn walk(node: Node, source: &[u8], idx: &mut SymbolIndex) {
    match node.kind() {
        "pattern_reference" => {
            if let Some(id) = node.child_by_field_name("identifier") {
                if let Ok(text) = id.utf8_text(source) {
                    idx
                        .refs
                        .push((text.to_string(), id.start_byte(), id.end_byte()));
                }
            }
        }
        "node_pattern" => {
            if let Some(id) = node.child_by_field_name("identifier") {
                if let Ok(text) = id.utf8_text(source) {
                    let has_labels = node.child_by_field_name("labels").is_some();
                    let has_record = node.child_by_field_name("record").is_some();
                    if has_labels || has_record {
                        idx.defs
                            .push((text.to_string(), id.start_byte(), id.end_byte()));
                    } else if relationship_parent_field(node).is_some() {
                        idx.refs
                            .push((text.to_string(), id.start_byte(), id.end_byte()));
                    }
                }
            }
        }
        "subject_pattern" => {
            if let Some(id) = node.child_by_field_name("identifier") {
                if let Ok(text) = id.utf8_text(source) {
                    let has_labels = node.child_by_field_name("labels").is_some();
                    let has_record = node.child_by_field_name("record").is_some();
                    if has_labels || has_record {
                        idx.defs
                            .push((text.to_string(), id.start_byte(), id.end_byte()));
                    }
                }
            }
        }
        _ => {}
    }
    let mut c = node.walk();
    for child in node.children(&mut c) {
        walk(child, source, idx);
    }
}

/// If `node` is a direct `left` / `right` child of a `relationship_pattern`, return that field name.
fn relationship_parent_field(node: Node) -> Option<&'static str> {
    let parent = node.parent()?;
    if parent.kind() != "relationship_pattern" {
        return None;
    }
    for field in ["left", "right"] {
        if let Some(ch) = parent.child_by_field_name(field) {
            if ch.id() == node.id() {
                return Some(field);
            }
        }
    }
    None
}
