# Locals Query Contract

**Feature**: 004-editor-improvements  
**File**: `queries/locals.scm`

## Required captures

| Capture | Node / pattern | Spec reference |
|--------|----------------|----------------|
| @local.definition | Identifier where it defines: subject in subject_pattern, subject in node_pattern, subject in relationship_pattern (left, right, kind), identifier/labels in identified_annotation | FR-005 |
| @local.reference | Identifier in pattern_reference | FR-005 |
| @local.scope (optional) | gram_pattern (root) | FR-006 |

## Scope rule

File-only. All definitions and references share one scope (the file). References resolve to any matching definition in the file. No subject-pattern or finer-grained scope (per spec clarification).

## Behavior

- Editors that support tree-sitter locals use these for “go to definition” (from reference to definition) and “highlight references” (from definition to references).
- When multiple definitions share the same name, resolution is file-wide; editor may pick first or allow disambiguation.

## Single source of truth

locals.scm MUST exist under `queries/` and be synced to Zed via `scripts/prepare-zed-extension.sh`.

## Test requirements

- In an editor with locals support: from a pattern_reference identifier, “go to definition” jumps to a subject/node/relationship/annotation definition with the same name.
- From a definition, “highlight references” highlights all pattern_reference identifiers that match within the file.
