# Highlights Query Contract

**Feature**: 004-editor-improvements  
**File**: `queries/highlights.scm`

## Required captures

| Capture | Node / pattern | Spec reference |
|--------|----------------|----------------|
| Definition-like identifier | Subject in subject_pattern, node_pattern, relationship left/right/kind; identifier/labels in identified_annotation | FR-001 |
| Reference identifier | Identifier in pattern_reference | FR-001 |
| Tagged-string tag | tagged_string tag: (symbol) | FR-002 |
| Comment | (comment) | FR-003 |

## Capture naming (implementation choice)

- Definition-like identifiers: `@type` or equivalent so themes can style as type/definition.
- Reference identifiers: `@variable` or equivalent so themes can style as variable/use.
- Tagged-string tag: `@attribute` or equivalent so tag is distinct from content.
- Comment: `@comment`.

## Existing captures to keep

- string_literal, string_content, number, boolean_literal, symbol (where not overridden by definition/reference/tag)
- record_property key, map_entry key → @property
- property_annotation key, identified_annotation → @attribute (or as above for tag)
- subject_pattern → @type (or definition capture)
- node_pattern labels (symbol) → @type
- relationship_pattern → @keyword
- right_arrow, left_arrow, etc. → @operator
- Brackets, comma → @punctuation.*
- ERROR → @error

## Single source of truth

highlights.scm MUST exist only under `queries/`. Zed consumes it via `scripts/prepare-zed-extension.sh` (FR-004).

## Test requirements

- Corpus or manual test: file with subject_pattern, node_pattern, pattern_reference shows definition-like and reference identifiers with different highlight groups.
- File with tagged_string shows tag and content with different highlight groups.
- File with `//` comment shows comment highlighted as @comment.
