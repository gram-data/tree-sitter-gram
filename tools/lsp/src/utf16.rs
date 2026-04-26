//! Map UTF-8 byte offsets to LSP positions (UTF-16 code units).

use tree_sitter::Point;

/// UTF-16 column of `line_prefix` (full line content before cursor on that line).
fn utf16_col_in_line(line_prefix: &str) -> u32 {
    let mut utf16 = 0u32;
    for ch in line_prefix.chars() {
        utf16 += ch.len_utf16() as u32;
    }
    utf16
}

/// Convert a UTF-8 byte index in `source` to LSP `(line, character)` with UTF-16 `character`.
pub fn byte_offset_to_position(source: &str, byte_idx: usize) -> (u32, u32) {
    let byte_idx = byte_idx.min(source.len());
    let mut line = 0u32;
    let mut line_start = 0usize;
    for (i, ch) in source.char_indices() {
        if i == byte_idx {
            let col = utf16_col_in_line(&source[line_start..i]);
            return (line, col);
        }
        if ch == '\n' {
            line += 1;
            line_start = i + ch.len_utf8();
        }
    }
    (line, utf16_col_in_line(&source[line_start..]))
}

/// Byte range (start inclusive, end exclusive) to LSP `(line, char)` pairs.
pub fn byte_range_to_lsp_range(source: &str, start_byte: usize, end_byte: usize) -> ((u32, u32), (u32, u32)) {
    let start = byte_offset_to_position(source, start_byte);
    let end = byte_offset_to_position(source, end_byte.max(start_byte));
    (start, end)
}

/// Map tree-sitter `Point` to byte offset then to LSP range.
pub fn point_range_to_lsp_range(source: &str, start: Point, end: Point) -> ((u32, u32), (u32, u32)) {
    let start_byte = point_to_byte_offset(source, start);
    let end_byte = point_to_byte_offset(source, end).max(start_byte);
    byte_range_to_lsp_range(source, start_byte, end_byte)
}

fn point_to_byte_offset(source: &str, point: Point) -> usize {
    let mut row = 0usize;
    let mut line_start = 0usize;
    for (i, ch) in source.char_indices() {
        if row == point.row {
            let line_slice = &source[line_start..];
            let col_b = point.column;
            if col_b <= line_slice.len() {
                return line_start + col_b;
            }
            return line_start + line_slice.len();
        }
        if ch == '\n' {
            row += 1;
            line_start = i + ch.len_utf8();
        }
    }
    source.len()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn ascii_lines() {
        let s = "ab\ncd";
        assert_eq!(byte_offset_to_position(s, 0), (0, 0));
        assert_eq!(byte_offset_to_position(s, 1), (0, 1));
        assert_eq!(byte_offset_to_position(s, 2), (0, 2)); // start of `\n`
        assert_eq!(byte_offset_to_position(s, 3), (1, 0)); // `c`
    }
}
