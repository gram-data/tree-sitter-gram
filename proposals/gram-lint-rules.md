# Gram Lint Rules

**Status:** Proposal (for discussion and iteration)
**Scope:** `tools/lsp/`, `tools/gram/`, `queries/`, new `queries/lint/`

---

## 1. Motivation

`gram check` currently detects two categories of problem:

| Category | Examples | Implementation |
|----------|---------|----------------|
| Parse errors | unexpected token, missing bracket | tree-sitter `ERROR` / `MISSING` nodes |
| Semantic errors | duplicate element names, duplicate record keys | hand-written Rust traversals in `gram_lsp` |

The Rust semantic checks are correct but bespoke. Each rule requires new code in `gram_lsp`, a new test, and a recompile. The checks also re-implement concepts — scoping, symbol tracking, definition/reference relationships — that tree-sitter already has a standard model for. As the rule surface grows (multi-type definitions, convention checks, schema-aware validation), the maintenance cost compounds.

A query-driven lint system, grounded in tree-sitter's standard navigation model, addresses this directly.

---

## 2. Foundation: Code Navigation Queries

Tree-sitter's code navigation layer (`tags.scm`, `locals.scm`) provides a declarative model for definitions and references that is already understood by GitHub, language servers, and other tools in the ecosystem. Investing in these files first gives gram a formal semantic model that lint rules, the LSP, and future tooling can all build on.

### `tags.scm` — cross-file navigation

`tags.scm` declares which nodes are definitions and which are references, at the file level. For gram:

```scheme
; Named node pattern — introduces an element
(node_pattern
  identifier: (symbol) @name) @definition.variable

; Named edge pattern — introduces a relationship element
(edge_pattern
  identifier: (symbol) @name) @definition.variable

; Node label — defines a type (meaningful in schema files)
(node_pattern
  labels: (labels (symbol) @name)) @definition.type

; Edge label — defines a relationship type
(edge_pattern
  labels: (labels (symbol) @name)) @definition.type

; Reference — identifier used without introducing a new element
(node_pattern
  identifier: (symbol) @name
  !labels) @reference
```

With `tags.scm` in place, GitHub understands gram definitions and renders "jump to definition" links for any hosted gram file. It also provides the data model for cross-file validation: a `:Person` label in a graph file is a `@reference` whose `@definition.type` lives in a schema file.

### `locals.scm` — within-file scoping

`locals.scm` refines the model to within-file scoping. Gram has two scope levels:

- **Top-level scope**: the whole file; named elements defined at the top level are visible everywhere
- **List pattern scope**: `[| (a), (b) ]` introduces a local scope where `a` and `b` are defined; they do not conflict with top-level names of the same spelling

```scheme
; The whole document is the root scope
(gram_pattern) @local.scope

; A list pattern (subject_pattern_elements) is a nested scope
(list_pattern) @local.scope

; Named element introductions are definitions
(node_pattern
  identifier: (symbol) @local.definition)

(edge_pattern
  identifier: (symbol) @local.definition)

; Uses of a name that refer back to a definition are references
(node_pattern
  identifier: (symbol) @local.reference
  !labels)
```

The scoping rules encoded here are exactly what the current `SymbolIndex` in `tools/lsp/src/symbols.rs` computes imperatively. Once `locals.scm` is in place, the LSP can use tree-sitter's query engine to resolve go-to-definition and find-references, and the Rust code becomes a thin wrapper rather than a bespoke traversal.

---

## 3. Architecture: Two-Layer Lint System

Not every rule fits neatly into a query. The design distinguishes two layers with different strengths:

```
┌─────────────────────────────────────────────────┐
│  gram check (output: ariadne diagnostics / JSON) │
└───────────────────┬─────────────────────────────┘
                    │
        ┌───────────┴───────────┐
        │                       │
┌───────▼──────┐     ┌──────────▼──────────┐
│  Query layer │     │  Analysis layer      │
│  .scm rules  │     │  Rust passes         │
│              │     │                      │
│  structural  │     │  cross-node state    │
│  convention  │     │  cross-file context  │
│  fast        │     │  symbol tables       │
└──────────────┘     └─────────────────────┘
```

### Query layer

Each lint rule is a tree-sitter query file under `queries/lint/`. A rule file captures problematic patterns with named captures; the engine converts each match into a diagnostic.

Example — `queries/lint/unlabeled-top-level-node.scm`:
```scheme
; A top-level node pattern with no label and no properties is likely incomplete.
(gram_pattern
  (node_pattern
    !labels
    !properties) @warn.unlabeled-node)
```

Example — `queries/lint/duplicate-record-key.scm`:
```scheme
; Duplicate property key in a record.
(properties
  (property (key (symbol) @dup.key))
  (property (key (symbol) @dup.key)))
```

Rules are loaded at startup from the `queries/lint/` directory. This means new rules can be added without changing Rust, and users can eventually supply their own rule files (a `~/.gram/lint/` override directory is a natural extension).

### Analysis layer

Rules that require state across nodes stay in Rust. The key examples:

- **Multi-type definition**: `alice` is labeled `:Person` in one pattern and `:Movie` in another. Detecting this requires a map from name → observed types built by a single traversal.
- **Undefined reference**: `(alice)-[]->(bob)` where `bob` was never introduced. Requires the scope-aware symbol table.
- **Schema/graph cross-file validation**: checking that element types in a `kind: "graph"` file match definitions in a linked `kind: "schema"` file.

The analysis layer is intentionally narrower than it is today. `locals.scm` takes over the structural scoping work; Rust focuses on logic that genuinely requires imperative computation.

---

## 4. Retiring the Rust Symbol-Tracking Code

The current `gram_lsp` library has several modules that implement symbol tracking in Rust:

| Module | Current role | Replacement |
|--------|-------------|-------------|
| `symbols.rs` (`SymbolIndex`) | definition/reference index for LSP | `locals.scm` + query engine |
| `elements.rs` | duplicate element detection in list patterns | `locals.scm` scope + analysis pass |
| `top_level.rs` | duplicate top-level element detection | same |
| `record_keys.rs` | duplicate property key detection | query rule |

The migration is incremental: write the query equivalents, verify they produce identical diagnostics, then delete the Rust. `record_keys.rs` is probably the simplest starting point — duplicate key detection inside a single `(properties ...)` node is a pure structural query with no cross-node state.

---

## 5. File Role Metadata (`kind`)

A top-level record with a `kind` key signals the intended role of a gram file:

```gram
{ kind: "graph" }
(alice:Person)-[:KNOWS]->(bob:Person)
```

```gram
{ kind: "schema" }
(:Person { name: "" })-[:KNOWS]->(:Person { name: "" })
```

This metadata is valuable at two levels:

**Structural level (query layer):** A rule can check that the `kind` value is a recognised string, that a schema file contains only unlabeled or typed node patterns, that a graph file does not define new type-introducing patterns without a corresponding schema, etc.

**Semantic level (analysis layer):** When two files are checked together, `kind: "graph"` establishes that `:Person` is a reference whose definition should exist in a `kind: "schema"` file. This is the entry point for cross-file validation.

The `kind` field is also the natural home for future vocabulary: `kind: "query"`, `kind: "migration"`, `kind: "fixture"`. Each role can carry its own lint profile.

---

## 6. Suggested Remediation Hints

As discussed separately, tree-sitter's `MISSING` nodes already carry "expected X" information. A related improvement is surfacing lookahead suggestions for `ERROR` nodes via `LookaheadIterator` (available in tree-sitter 0.25). This sits in the parse-error layer rather than the semantic lint layer, but architecturally it belongs to the same investment: make diagnostics actionable, not just descriptive.

The query lint rules have a natural place for this too — a rule capture can carry a note string:

```scheme
; Unlabeled top-level node — suggest adding a label
(gram_pattern
  (node_pattern
    !labels
    !properties) @warn.unlabeled-node)
; note: "Consider adding a label, e.g. (alice:Person)"
```

Exact syntax for rule metadata is an open question (TOML sidecar? inline comments parsed by convention?), but the intent is that each rule can optionally carry a suggestion string rendered as a note in the ariadne output.

---

## 7. Phased Roadmap

### Phase 1 — Navigation foundation
- Write `queries/tags.scm`: named node/edge definitions, label type definitions, bare-identifier references
- Write `queries/locals.scm`: document scope, list-pattern scope, definition/reference captures
- Verify go-to-definition and find-references in the LSP use the query results
- Retire `symbols.rs` (`SymbolIndex`)

### Phase 2 — Query lint engine
- Infrastructure in `gram check` to load and run `.scm` rules from `queries/lint/`
- Port `record_keys.rs` duplicate-key detection to a query rule; retire the Rust
- Add first convention rules: label casing, missing top-level record, unknown `kind` value
- `kind` detection: surface file role in diagnostics context

### Phase 3 — Semantic lint rules
- Multi-type definition rule in the analysis layer (built on locals model)
- Port remaining duplicate-element detection to use locals model; retire `elements.rs` and `top_level.rs`
- `LookaheadIterator` spike for expected-token hints on `ERROR` nodes

### Phase 4 — Schema integration
- Cross-file validation framework: resolve `@reference` captures against `@definition.type` in linked schema files
- `kind: "graph"` / `kind: "schema"` enforcement rules
- Property type checking against schema-declared shapes

---

## 8. Open Questions

- **Query rule metadata format**: How does a `.scm` rule carry its diagnostic message and severity? Inline comment convention, sidecar TOML, or a structured header block?
- **User-supplied rules**: Should `~/.gram/lint/` be supported from day one, or deferred until the built-in rule format stabilises?
- **`locals.scm` disambiguation**: In gram, whether an identifier is a definition or a reference depends on context (presence of labels, position in the pattern). The query needs to handle this without false positives. Needs a careful read of the grammar to get right before implementation.
- **Multi-file invocation**: `gram check *.gram` today checks files independently. Cross-file validation requires a session that knows about all files together. What is the right CLI surface — a `--schema` flag, a config file, directory-wide inference from `kind` headers?
- **Compatibility with `gram-lsp`**: The LSP already serves go-to-definition and find-references. Replacing the Rust symbol table with `locals.scm`-driven queries should be transparent to editors, but needs careful regression testing with the Zed extension.
