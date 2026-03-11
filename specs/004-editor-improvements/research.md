# Research: Editor Support and Syntax Highlighting Improvements

**Feature**: 004-editor-improvements  
**Date**: 2025-03-11

## 1. Highlight captures: definition vs reference

**Decision**: Use distinct capture names so definitions can be styled differently from references. Definitions (subject in subject_pattern, identifier in node_pattern, subject in relationship arrows, identifier in identified_annotation) → `@type` or a custom capture (e.g. `@identifier.definition`) that themes can map to a type-like or definition style. References (pattern_reference identifier) → keep `@variable` or use `@variable.reference`.

**Rationale**: Tree-sitter and editor themes commonly use `@type` for type/definition-like identifiers and `@variable` for uses; Neovim/Helix/Emacs map these to different highlight groups. Using `@type` for definition-like identifiers and `@variable` for pattern references aligns with existing grammar terminology (subject_pattern already captured as `@type` in places) and gives immediate visual distinction without requiring theme changes.

**Alternatives considered**:
- Single `@variable` for all: Rejected; spec requires differentiation (FR-001).
- Custom names only (e.g. `@gram.definition`): Possible but less portable; `@type` / `@variable` are widely recognized.

---

## 2. Highlight: tagged-string tag and comment

**Decision**: Capture tagged_string’s `tag` field (symbol) as a dedicated capture (e.g. `@type` or `@attribute`) so the tag is highlighted distinctly from `string_content`. Capture `(comment)` as `@comment` when present in the grammar (grammar.js exposes `comment`).

**Rationale**: FR-002 and FR-003 require distinct tag and comment highlighting. The grammar has `tagged_string` with `field("tag", $.symbol)` and `comment: ($) => token(seq("//", /.*/))`, so both are available. Using `@attribute` for the tag keeps tags visually distinct from general `@variable` and fits “metadata” semantics.

**Alternatives considered**:
- Reuse `@variable` for tag: Rejected; spec requires distinct tag (FR-002).
- Omit comment capture until grammar exposes it: Not applicable; grammar already exposes `comment` in extras.

---

## 3. Locals: file scope only

**Decision**: Implement locals with `@local.definition` and `@local.reference` only. Use a single file-level `@local.scope` (e.g. on `gram_pattern` or the root) so all definitions and references are in one scope. Do not add subject-pattern or finer-grained scope nodes.

**Rationale**: Spec clarification: file-only scope (no subject-pattern scoping). Tree-sitter locals resolve references to definitions within the same scope; one file scope gives correct “go to definition” and “highlight references” for the whole file. Simpler query set and fewer edge cases.

**Alternatives considered**:
- Subject-pattern scope: Rejected per spec (clarification: file-only).
- No @local.scope: Some editors still resolve by name within file; defining one root scope is the documented pattern and avoids ambiguity.

---

## 4. Indentation: 2 spaces and indent captures

**Decision**: Add `indents.scm` using standard indent captures (`@indent`, `@indent.end`, `@extend` as needed). Indent width is 2 spaces per level. Capture bracket-delimited blocks (e.g. record `{}`, pattern `[]`, `()`) so that content inside increases indent by one level; closing bracket aligns with opening.

**Rationale**: Spec requires 2 spaces per level (FR-007, clarification). Tree-sitter indent queries use captures like `@indent` (increase indent), `@indent.end` (decrease), `@extend` (continue scope). Align with nvim-treesitter/Helix patterns: opening bracket → indent begin, closing → indent end, 2-space step.

**Alternatives considered**:
- 4 spaces: Rejected; spec says 2 spaces.
- Rely only on editor default: Rejected; spec requires defined rules (FR-007).

---

## 5. Injections: dynamic tag + minimal overrides

**Decision**: Keep current injection approach: capture tag as `@injection.language`, content as `@injection.content`. Overrides only for tags that do not match parser names: minimal set `md` → markdown, `ts` → typescript. All other tags use the tag’s text as the language name (dynamic). Support both inline and fenced tagged_string forms in the same way.

**Rationale**: Spec (FR-008, FR-009) and existing `queries/injections.scm` already follow this. No research change; document the decision and ensure override order in queries (specific overrides first, then generic dynamic rule) so that `md` and `ts` are overridden before the catch-all.

**Alternatives considered**:
- Enumerate all well-known tags in queries: Rejected; spec says language is captured from tag, not pre-defined.
- Remove overrides: Rejected; spec requires minimal set (md, ts) for testability.

---

## 6. Single canonical queries and Zed sync

**Decision**: Maintain exactly one set of query files under `queries/` (highlights.scm, locals.scm, indents.scm, injections.scm). Zed extension gets them via `scripts/prepare-zed-extension.sh` copying `queries/*.scm` into `editors/zed/languages/gram/`. Do not maintain separate copies in Zed; remove or stop editing any duplicate under editors/zed that diverges from queries/.

**Rationale**: FR-004 and plan require single source of truth. prepare-zed-extension.sh already copies all .scm from queries/ to Zed; adding locals.scm and indents.scm to queries/ and re-running the script is sufficient. No NEEDS CLARIFICATION.

**Alternatives considered**:
- Separate Zed-specific queries: Rejected; would duplicate maintenance.

---

## Summary table

| Topic              | Decision                                      | Status   |
|--------------------|-----------------------------------------------|----------|
| Definition vs ref  | @type (or definition) vs @variable           | Resolved |
| Tagged-string tag  | Capture tag as @attribute (or @type)          | Resolved |
| Comment            | (comment) @comment                            | Resolved |
| Locals scope       | File-only; one @local.scope at root           | Resolved |
| Indent             | indents.scm; 2 spaces; bracket blocks           | Resolved |
| Injections         | Dynamic + md/ts overrides; both forms          | Resolved |
| Canonical queries  | queries/ only; Zed sync via script             | Resolved |
