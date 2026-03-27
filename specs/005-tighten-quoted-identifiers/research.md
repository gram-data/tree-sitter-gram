# Research: Tighten Quoted Names

**Feature**: `005-tighten-quoted-identifiers`  
**Date**: 2026-03-27  
**Status**: Complete

## Research Questions

1. How should the grammar distinguish general string values from quoted names used as identifiers, labels, and keys?
2. How should key syntax remain JSON-friendly without re-introducing the full `string_literal` surface everywhere?
3. Which existing repo artifacts are affected by narrowing quoted identifier and label behavior?
4. How should query and AST stability be handled if new visible name-like node types are introduced?

## Findings

### 1. Split value strings from name-like quoted forms

**Decision**: Keep `symbol` as the existing regex-only token and keep `string_literal` as the broad value-oriented rule. Introduce dedicated quoted-name rules for name positions instead of routing identifiers and keys through `string_literal`.

**Rationale**:
- `string_literal` currently includes single-quoted, double-quoted, backticked, and fenced strings, which is too broad for identifier and label positions.
- Broadening `symbol` would unintentionally broaden property annotation keys and tagged-string tags, which the feature explicitly does not want.
- Small, position-specific rules preserve grammar readability and avoid hidden behavior changes in unrelated parts of the grammar.

**Alternatives considered**:
- Broaden `symbol` to include backticked strings: rejected because it would leak into annotation keys, tagged-string tags, and generic query captures.
- Keep `_identifier` as `symbol | string_literal | integer` and filter later: rejected because the grammar would still accept unsupported syntax.

### 2. Use position-specific name rules

**Decision**: Use separate composition rules for each syntactic role:
- Identifier positions: `symbol | backtick-quoted-name | integer`
- Label positions: `symbol | backtick-quoted-name`
- Record/map key positions: `symbol | backtick-quoted-name | double-quoted-name`

**Rationale**:
- This matches the intended product semantics exactly: Cypher-friendly backticks for identifiers and labels, JSON-friendly double quotes for keys, and no single-quoted or fenced names in any of those positions.
- It lets keys remain more permissive than identifiers without continuing to treat arbitrary string literals as keys.
- It keeps numeric identifiers unchanged while avoiding accidental expansion of numeric labels or keys.

**Alternatives considered**:
- A single shared `name` rule for identifiers, labels, and keys: rejected because keys intentionally allow double quotes while identifiers and labels do not.
- Retain integer keys because they are currently allowed: rejected for this feature because the approved spec narrows key syntax to bare, backtick-quoted, or double-quoted names only.

### 3. Preserve value syntax and symbol-only metadata syntax

**Decision**: Leave `_value`, `_scalar_value`, `property_annotation.key`, and `tagged_string.tag` unchanged.

**Rationale**:
- The feature is about names, not general values.
- Tagged strings already use `symbol` plus a string body; allowing quoted tags would expand a distinct language surface without user demand.
- Property annotation keys remain part of the wrapper subject's property shorthand, but this feature intentionally leaves that syntactic sugar narrower than record/map key syntax because the non-bracket forms do not need to mirror all `[ ... ]` capabilities.

**Alternatives considered**:
- Allow double-quoted or backtick-quoted property annotation keys: rejected as unnecessary scope expansion.
- Narrow value strings along with names: rejected because it would break unrelated string use cases and violate the requirement to preserve existing value syntax.

### 4. Treat query and doc updates as first-class work

**Decision**: Plan explicit updates to corpus fixtures, query captures, and reference docs alongside the grammar change.

**Rationale**:
- Existing tests and docs currently describe `identifier = symbol | string_literal | integer` and `label = ":" | "::" + symbol`.
- Existing query captures in `queries/highlights.scm` and `queries/locals.scm` assume labels are always `symbol` children.
- The repo already includes corpus coverage for double-quoted identifiers and string/integer keys; those artifacts must change to keep the language contract coherent.

**Alternatives considered**:
- Only update `grammar.js` and generated parser output: rejected because the repo constitution requires illustrative tests and synced docs.
- Defer query/doc updates until after implementation: rejected because editor behavior and written language contracts would drift immediately.

### 5. Document annotation sugar explicitly

**Decision**: Describe `@key(value)` as wrapper-subject property sugar and `@@identifier:Label` as wrapper-subject identifier/label sugar throughout the feature docs.

**Rationale**:
- This terminology is semantically consistent with the language model: annotations are attached information that corresponds to the subject of the implied wrapper pattern.
- It avoids implying that `@...` and `@@...` are separate semantic constructs when they are alternate surfaces for bracket-pattern notation.
- It also clarifies why syntax can differ between sugar forms and full `[ ... ]` subject syntax without creating a semantic contradiction.

**Alternatives considered**:
- Continue using annotation-specific terminology alone: rejected because it obscures the equivalence with bracket-pattern notation.
- Force syntax parity between sugar and bracket subjects: rejected because the feature only needs semantic consistency, not identical syntax across sugar forms.
### 6. Prefer visible quoted-name node types for query stability

**Decision**: Model backtick-quoted names and double-quoted key names as visible named rules rather than relying on generic `string_literal` nodes in name positions.

**Rationale**:
- Visible named rules give `queries/highlights.scm` and `queries/locals.scm` stable capture targets for labels, keys, and identifier-like nodes.
- They distinguish “quoted name” from “string value” in the syntax tree, which improves both highlighting behavior and downstream tooling clarity.
- Shared internal text rules can still be reused so escaping behavior stays consistent with current backtick and double-quoted strings.

**Alternatives considered**:
- Continue using `string_literal` in name positions and rely on parent context in queries: workable but less explicit and more brittle.
- Hide all quoted-name rules: rejected because query files would have to capture generic children and lose semantic precision.

## Compatibility Notes

- `test/corpus/identifiers.txt` currently documents double-quoted identifiers as valid; this feature intentionally makes those forms invalid and must update the corpus accordingly.
- `test/corpus/value_pair.txt` currently documents double-quoted keys; that behavior remains valid and should stay covered.
- Existing docs (`docs/gram-reference.md`, `docs/gram-ebnf.md`, `docs/gram.ebnf`) currently describe identifiers as allowing `string_literal`; they must be revised to reflect position-specific quoted-name rules.
- Query captures for labels and keys must be extended if new visible name node types are added.

## Summary Table

| Topic | Decision | Rationale |
|-------|----------|-----------|
| `symbol` scope | Keep regex-only | Avoid leaking quoted-name support into property annotation keys and tagged-string tags |
| Identifier syntax | Bare name, backtick-quoted name, integer | Tighten names while preserving Cypher-friendly identifiers and current numeric identifiers |
| Label syntax | Bare name or backtick-quoted name | Allow a single richer label without enabling unrelated string forms |
| Key syntax | Bare name, backtick-quoted name, double-quoted name | Preserve both Cypher and JSON authoring styles |
| Value syntax | Leave unchanged | String/value behavior is outside this feature’s scope |
| Query strategy | Add captures for visible quoted-name nodes | Keep highlights and locals aligned with the new tree shape |
