# Proposal: gramdoc — structured documentation comments for gram

**Status**: Proposal (open questions pending)
**Affects**: `grammar.js`, `queries/injections.scm`, `test/corpus/`, new repository `tree-sitter-gramdoc`
**Origin**: `relateby/pattern-rs` ontology spike (`data/schema/ontology/`, branch `spike/ontology-graph-spec-gram`)
**Prior art**: [cypherdoc](https://github.com/gram-data/tree-sitter-cypher/blob/main/proposals/cypherdoc-injection.md)
**Baseline**: checked against `240a78a`

## Summary

Add `/** ... */` documentation comments to gram, with a structured sub-language, `gramdoc`, for their content.

1. tree-sitter-gram recognizes a `/** ... */` block as a `doc_comment` node.
2. `queries/injections.scm` injects the language `gramdoc` into `doc_comment` nodes.
3. `gramdoc` is a standalone tree-sitter grammar in the gram-data org (its own repository, as with cypherdoc), adopted here by injection.

## Motivation

The ontology spike expresses the [Neo4j ontology-graph-spec](https://github.com/neo4j/ontology-graph-spec) in gram. That spec adds `description`, `aliases` and `reference` to graph-type-like definitions so that people and LLMs can tell what an element *means*: a schema tells an agent what exists, not what it means.

Gram's stance is that qualification is external. A node doesn't know its context, so nesting meaning inside an element is the wrong shape. Meaning should attach from outside (annotations, element references), and the same element should be able to carry different meanings in different contexts (language, audience).

That leaves a gap for the human-readable layer. We want descriptions and aliases for an element, and for individual properties of an element, without nesting them in the element's record and without inventing a property-addressing syntax. A documentation comment placed next to the thing it documents does both. It is also "meta-meta data": it can sit on the original element or on any annotation attached to it.

### Driving example

```gram
/**
 * A human individual.
 *
 * @property name The full name of the person.
 */
(Person {
    name: "STRING!"
})

/**
 * Un être humain.
 *
 * @property name Le nom complet de la personne.
 */
[:French {
      name: "nom"
} | Person ]
```

The second pattern is an annotation-style context (`:French`) over `Person`, with its own gramdoc. `@property name` addresses a property by name inside the comment rather than in the structure.

## Current state

- The only comment form is `comment: token(seq("//", /.*/))`, an `extras` entry (`grammar.js`). `/** */` and `/* */` are not comments.
- Parsing the driving example today produces `ERROR` nodes for each `/** ... */` block, and the `@property name ...` text inside is parsed as an annotation.
- `//` comments are kept as `(comment)` nodes. `test/corpus/comments.txt` covers top-level, end-of-line and before-pattern placement; its `:error` cases are only where `//` would swallow a closing delimiter.
- Not covered by the corpus, but probed against the current grammar: `comment` nodes parse as siblings of `record_property` inside records, between subject-pattern elements, inside relationship records, and before or between annotations. Positional doc comments are therefore feasible at the parser level.
- Relation to `specs/010-publish-lib/plan.md`: that plan rejected a `tree-sitter-gramdoc` grammar, but for gram embedded in markdown (use markdown injection instead). This proposal is the opposite direction, documentation inside gram, and does not conflict with it. That plan's wording should be updated or cross-referenced if this is accepted.

### Downstream note

From reading `relateby/pattern-rs` `crates/gram-codec` (not executed): `parse_gram` uses the nom parser and discards comments. The tree-sitter path (`parse_gram_cst`) retains `comment` nodes as `SyntaxKind::Comment`, but lowering to `Pattern<Subject>` drops them, and record-internal comments are likely not captured at all. That is a separate pattern-rs follow-up once the grammar side is settled.

## Proposed design

### Host grammar (tree-sitter-gram)

- Add a `doc_comment` token for `/** ... */`, as an `extras` entry alongside `comment`. Its precedence over any future block-comment form must be explicit (see open question 5). `/**/` is an empty plain block, not a doc comment, if block comments are added.
- Add to `queries/injections.scm`:

  ```scm
  ((doc_comment) @injection.content
    (#set! injection.language "gramdoc"))
  ```

- Corpus tests for doc comments:
  - at top level
  - before annotations
  - before elements
  - inside records, before a `record_property`
  - inside subject-pattern element lists
  - unterminated blocks (`:error`)

### Sub-grammar (`tree-sitter-gramdoc`, separate repository)

Modeled on the cypherdoc layout:

- `grammar.js`, `queries/{highlights,tags}.scm`, and `test/corpus/*.txt` split by concern (tags, names, descriptions).
- A leading `*` on each line is whitespace via `extras`; the grammar handles `/**` and `*/` itself.
- Structure: optional name, free-prose description, then tags. Named nodes (`name`, `description`, one per tag kind) so queries can address them.
- Injected content is the whole `/** ... */` text, as in cypherdoc.

### Attachment

A doc comment documents the next element in source order: an element, an annotation, or a `record_property` when placed inside a record. Because annotations are patterns whose single element is the annotated thing, a doc comment can sit on the original element or on any annotation attached to it. Attachment is a consumer rule over adjacency unless we decide the host grammar should make it structural (open question 6).

### Tag set

A gram element is `[id:Label1:Label2 {properties} | e1, e2, ...]`: a subject (identifier, labels, record) plus a sequence of pattern elements. The tags mirror those parts, and the description prose covers the ontology spec's `description`.

**Subject**
- `@property <name> <description>` documents a property in the record, so no property-addressing syntax is needed in the structure.
- `@label <name> <description>` documents a label.
- `@alias <name>` (repeatable) and `@reference <target> [description]` cover the ontology spec's `aliases` and `reference`.

**Pattern elements**
- `@elements <description>` documents the intent of the sequence as a whole.
- `@element <description>` (repeatable) documents one member. Position is implied by order of appearance: the nth `@element` documents the nth member, so no addressing syntax is needed, and anonymous members are covered. A count mismatch with the documented element is a lint matter (question 8), not a parse error.
- `@source <cardinality> <description>` and `@target <cardinality> <description>` document the two ends of a relationship (arity 2, `[r | source, target]`). They are the relationship-specific, property-graph-friendly form of the first two `@element` entries, and are expected to dominate early use. They may coexist with `@element`/`@elements`.

**Cardinality** uses punctuation shorthand, regex-style:

| Form | Meaning | Ontology spec equivalent |
| --- | --- | --- |
| `1` | exactly one | `count: 1` |
| `?` | zero or one | `min_count: 0`, `max_count: 1` |
| `+` | one or more | `min_count: 1` |
| `*` | zero or more (unconstrained) | no count |
| `n` | exactly n (`1` above is the case n = 1) | `count: n` |
| `n..m` | between n and m, inclusive | `min_count: n`, `max_count: m` |
| `n..` | at least n (`+` is `1..`) | `min_count: n` |
| `..m` | at most m, minimum 0 (`?` is `..1`) | `max_count: m` |

The meaning follows the ontology spec's relationship end (`reference/relationships.adoc`): the cardinality at an end is the **number of relationships of this kind per node at that end**, not the number of nodes at the other end. For `[:ACTED_IN | person, movie]`, `@target + ...` says every movie has at least one incoming `ACTED_IN`, matching the spec's `to: {node: movie, min_count: 1}`. `@source` maps to the spec's `from`, `@target` to `to`. This is the reverse of UML multiplicity, so the README and proposal should say so explicitly (question 9).

**Deferred beyond the first tag set**: `@see`, `@deprecated`, `@example`.

## Alternatives considered

- **Nest description/aliases/reference in the element's record.** Rejected: it contradicts gram's external-qualification stance and cannot carry multiple contexts for one element.
- **Annotations carrying a `description` property.** Works structurally but cannot document individual properties without a property-addressing syntax, and is verbose for prose.
- **Plain `//` comments by convention.** Already parse, but have no structure for tools, and no injection point.
- **Reuse cypherdoc.** Its tag syntax and type braces are Cypher-shaped; sharing a grammar would couple two projects' release cycles. Reusing its layout and conventions is cheaper.

## Compatibility and risks

- **Source compatibility**: `/** */` text currently produces errors, so no valid existing gram changes meaning. Plain `/* */` is unaffected unless adopted (question 5).
- **Parser generation**: the new `doc_comment` token is generated into `src/`; bindings, `tree-sitter.json` and the `tools/` crates that match on node kinds need regeneration and a check that they ignore the new extra.
- **Sigil overlap**: tags use `@`, as gram annotations do. They cannot clash grammatically since tags live inside comments (question 2 covers readability).
- **Token vs. nested grammar**: the host treats the comment as one opaque token; all structure lives in the injection, so editors without injection support still highlight it as a comment.

## Open questions

1. **Tag syntax.** cypherdoc uses `@param {type} name - description` (distinct required/optional nodes, a deliberately retained `-`). The driving example uses `@property name description` with no braces or dash. Which do we adopt, and do we want `{type}` at all, given gram already has `::` and tagged strings for types?
2. **Sigil overlap.** Is `@` in tags acceptable alongside `@key(id)` annotations for readability?
3. **Tag set.** Should arbitrary user tags be allowed beyond those above, and when do `@see`, `@deprecated` and `@example` join?
4. **Description format.** Plain prose, or Markdown (gram already injects `md`)?
5. **Block comments.** Do we also add plain `/* */`, or only `/** */`?
6. **Attachment.** Adjacency convention only, or structural? What about a doc comment followed by annotations and then an element?
7. **Context variants.** The French example documents the same element in a second context. Does gramdoc need a language/context marker, or does the surrounding annotation carry that?
8. **pato / lint.** Should `pato` validate that `@property` and `@label` names exist on the documented element, that `@element` count matches the sequence, and that `@source`/`@target` appear only on arity-2 elements? (See `proposals/gram-lint-rules.md`.)
9. **Cardinality.** Confirm the punctuation forms (`n`, `n..m`, `n..`, `..m`, plus `?`, `+`, `*`) and the ontology-spec meaning (relationships per node at that end, the reverse of UML), and whether the description is required after the cardinality.

## Implementation plan

1. Settle the open questions above.
2. Implement `doc_comment` and the injection rule in tree-sitter-gram, with corpus tests; regenerate the parser and run the test suite.
3. Create `tree-sitter-gramdoc` in the gram-data org.
4. Update editor integrations (`editors/`, `queries/`) and `tools/lsp` as needed for the new node and injection.
5. Follow-up in `relateby/pattern-rs`: retain doc comments through the CST, decide where they live at the `Pattern` level, then resume the ontology spike.
