use tree_sitter::{Language, Parser, Tree};

/// Tree-sitter `Language` for Gram (cheap handle; safe to recreate).
pub fn language() -> Language {
    let raw_fn = tree_sitter_gram::LANGUAGE.into_raw();
    unsafe {
        let ptr = raw_fn();
        Language::from_raw(ptr as *const tree_sitter::ffi::TSLanguage)
    }
}

pub fn parser() -> Parser {
    let mut p = Parser::new();
    p.set_language(&language()).expect("gram language");
    p
}

pub fn parse(source: &str) -> Tree {
    let mut p = parser();
    p.parse(source, None).expect("parse")
}
