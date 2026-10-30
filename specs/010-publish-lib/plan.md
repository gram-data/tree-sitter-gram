# 010 – Publish lib target & rename check → lint

Tracks [Issue #10](https://github.com/gram-data/tree-sitter-gram/issues/10).

## Goals

1. Extract shared diagnostic types into a `gram-diagnostics` crate publishable from this workspace.
2. Move analysis logic from `gram-lsp` into `gram-data`, and flip the dependency so `gram-lsp` depends on `gram-data` rather than the reverse.
3. Add a `[lib]` target to `gram-data` so downstream tools (e.g. `relate-cli`) can depend on it as a crate instead of shelling out to the binary.
4. Rename the `check` subcommand to `lint` for consistency with `cypher-data`; keep `check` as a hidden alias.
5. Add markdown support to the lib (extracting ` ```gram ` fenced blocks) using **tree-sitter-markdown + injection**, not a separate gramdoc grammar.

---

## Part 0 – Extract `gram-diagnostics` crate

`cypher-data` v0.2.1 is now published. Comparing `types.rs` between the two crates:

| Field | gram-data | cypher-data |
|-------|-----------|-------------|
| `Severity` | ✓ identical | ✓ identical |
| `Position` | `u32` fields | `u32` fields |
| `Range` | ✓ identical | ✓ identical |
| `Diagnostic.severity` | ✓ | ✓ |
| `Diagnostic.rule` | **missing** | `String` |
| `Diagnostic.message` | ✓ | ✓ |
| `Diagnostic.range` | ✓ | ✓ |
| `Diagnostic.code` | `Option<String>` | `Option<String>` |
| `FileResult` | ✓ identical | ✓ identical |
| Top-level result | `CheckResult` | `LintResult` |

The only structural difference is that `gram-data` is missing `rule: String` on `Diagnostic` and uses the stale name `CheckResult` instead of `LintResult`.

### New workspace member: `crates/gram-diagnostics`

```
crates/
  gram-diagnostics/
    Cargo.toml
    src/lib.rs
```

**`crates/gram-diagnostics/Cargo.toml`:**
```toml
[package]
name = "gram-diagnostics"
description = "Shared diagnostic types for gram-data and cypher-data"
version.workspace = true
edition.workspace = true
license.workspace = true
repository.workspace = true
publish = true

[dependencies]
serde = { version = "1", features = ["derive"] }
```

**`crates/gram-diagnostics/src/lib.rs`** — exports all shared types:
- `Severity`, `Position`, `Range`, `Diagnostic` (with `rule: String`), `FileResult`, `LintResult`

### Updates needed after extraction

- `tools/gram/src/types.rs`: delete (types now come from `gram-diagnostics`)
- `tools/gram/Cargo.toml`: add `gram-diagnostics = { path = "../../crates/gram-diagnostics" }`
- `tools/gram/src/check.rs` / `src/lint.rs`: import from `gram_diagnostics` instead of `crate::types`
- `gram-data`'s `Diagnostic` gains `rule: String` — update construction sites in `check.rs` to populate it (rule name = `"ParseError"` for parse errors, or relevant semantic rule name)
- `CheckResult` → `LintResult` in all uses

`cypher-data` will independently take a dep on the published `gram-diagnostics` crate in a follow-up.

---

## Part 0b – Invert `gram-lsp` / `gram-data` dependency

Currently `gram-data` depends on `gram-lsp` to borrow `analyze_source`. This means any downstream crate taking `gram-data` as a library dependency transitively pulls in `tower-lsp`, `tokio`, `async-trait`, and the rest of the LSP server stack — dead weight for anyone who just wants to lint `.gram` files.

The fix is to move the analysis modules from `gram-lsp` into `gram-data`, then flip `gram-lsp` to depend on `gram-data` for analysis. `gram-lsp` retains sole responsibility for LSP wire protocol.

### Modules to move: `tools/lsp/src/` → `tools/gram/src/`

| Module | What it does |
|--------|-------------|
| `diagnostics.rs` | `analyze_source`, internal `Diagnostic`/`DiagnosticSeverity` (replaced by `gram-diagnostics` types) |
| `elements.rs` | Duplicate element detection |
| `top_level.rs` | Duplicate top-level element detection |
| `record_keys.rs` | Duplicate record key detection |
| `parse.rs` | `parse()`, `language()` wrappers |
| `symbols.rs` | `SymbolIndex` |
| `utf16.rs` | `byte_range_to_lsp_range`, `byte_to_line_col` |

`lsp.rs` stays in `gram-lsp` — it owns the LSP server loop, document store, and `tower-lsp` handler impl.

### Dependency changes

**`tools/gram/Cargo.toml`** — replace `gram-lsp` dep with direct tree-sitter dep:
```toml
# remove:
gram-lsp = { path = "../lsp" }
# add:
tree-sitter = "0.25"
```

**`tools/lsp/Cargo.toml`** — add `gram-data` dep, remove analysis-only deps that move with the code:
```toml
gram-data = { path = "../gram" }
```

### In `gram-lsp`'s `lsp.rs`

Replace all direct calls to `gram_lsp::analyze_source`, `gram_lsp::parse`, `gram_lsp::SymbolIndex` with their `gram_data::` equivalents. The `to_lsp_diagnostic` conversion (internal `Diagnostic` → `lsp_types::Diagnostic`) stays in `gram-lsp` since it touches `tower-lsp` types.

### User-visible install story (unchanged)

```
cargo install gram-data   # gram binary: lint, extension, skill, dispatch
cargo install gram-lsp    # gram-lsp binary: LSP server for editors
```

`gram lsp stdio` continues to work via the existing external-subcommand dispatch — PATH-based, no compile-time link required.

---

## Part 1 – Rename `check` → `lint`

Low complexity, do first so the CLI is already consistent when the lib ships.

### Changes

- `tools/gram/src/check.rs` → `tools/gram/src/lint.rs`
  - Rename `CheckArgs` → `LintArgs`
  - `CheckResult` → `LintResult` (resolved by Part 0)
- `tools/gram/src/main.rs`
  - Add `Lint(lint::LintArgs)` as primary variant
  - Add `#[command(hide = true)] Check(lint::LintArgs)` hidden alias, routing to `lint::run`

---

## Part 2 – `[lib]` target with public linting API

### Cargo changes (`tools/gram/Cargo.toml`)

```toml
[lib]
name = "gram_data"
path = "src/lib.rs"
```

The existing `[[bin]]` stays as-is.

### Public API (`src/lib.rs`)

```rust
pub use gram_diagnostics::{Diagnostic, FileResult, LintResult, Position, Range, Severity};

pub mod lint {
    pub use gram_diagnostics::{Diagnostic, LintResult, Severity};

    pub struct LintOptions {
        pub strict: bool,
    }

    pub fn lint_source(source: &str, opts: &LintOptions) -> Vec<Diagnostic>;
    pub fn lint_file(path: &Path, opts: &LintOptions) -> anyhow::Result<Vec<Diagnostic>>;
}
```

---

## Part 3 – Markdown support via tree-sitter injection

### Correction from issue comment

The issue comment proposes a `tree-sitter-gramdoc` grammar or extending `tree-sitter-cypherdoc`. This is the wrong approach **for gram embedded in markdown**.

> Not to be confused with `proposals/tree-sitter-gramdoc.md`, which goes the opposite direction: documentation comments (`/** ... */`) inside gram, injected with a separate `gramdoc` grammar (https://github.com/gram-data/tree-sitter-gramdoc). That proposal does not conflict with the decision below.

Tree-sitter has a first-class **language injection** mechanism: a host grammar (markdown) parses the document structure, and content inside designated nodes is parsed by a different grammar. No new grammar is needed.

The correct approach:
1. Add `queries/injections.scm` to this repo declaring that ` ```gram ` fenced code blocks get their content parsed by the gram grammar (enables editor injection automatically).
2. For the lib API, use `tree-sitter-markdown` to parse the host document, then run a tree-sitter query to find fenced code blocks with a `gram` info string, and extract their content.

### Dependency (`tools/gram/Cargo.toml`)

```toml
tree-sitter-markdown = "0.3"   # https://github.com/tree-sitter-grammars/tree-sitter-markdown
```

### Public API addition to `src/lib.rs`

```rust
pub mod markdown {
    use super::lint::{Diagnostic, LintOptions};

    pub struct Snippet {
        pub source: String,
        pub fence_start_line: usize,   // 0-based line in the host document
    }

    /// Extract all ```gram fenced blocks from a Markdown document.
    pub fn extract_snippets(doc_source: &str) -> Vec<Snippet>;

    /// Lint all ```gram snippets in a Markdown document.
    /// Returns one (Snippet, diagnostics) pair per fenced block.
    pub fn lint_markdown(doc_source: &str, opts: &LintOptions) -> Vec<(Snippet, Vec<Diagnostic>)>;
}
```

### `queries/injections.scm` (repo root)

```scheme
((fenced_code_block
  (info_string (language) @_lang)
  (code_fence_content) @injection.content)
 (#eq? @_lang "gram")
 (#set! injection.language "gram"))
```

This makes editors with tree-sitter-markdown + tree-sitter-gram automatically syntax-highlight ` ```gram ` blocks in Markdown.

---

## Part 4 – READMEs for all published crates

Four crates are published from this repo. Current README state:

| Crate | README exists | `readme` in Cargo.toml | Needs update |
|-------|--------------|------------------------|--------------|
| `tree-sitter-gram` (root) | ✓ | ✓ | No |
| `gram-lsp` (`tools/lsp`) | ✓ | ✓ | Minor (mention `gram lint` alias once rename lands) |
| `gram-data` (`tools/gram`) | ✓ | **missing** | Yes — add lib usage section, update `check`→`lint` |
| `gram-diagnostics` (`crates/gram-diagnostics`) | none | — | Write from scratch |

### `gram-data` README updates

1. Add `readme = "README.md"` to `tools/gram/Cargo.toml` so crates.io renders it.
2. Replace all `gram check` examples with `gram lint` (keep a note that `gram check` is a legacy alias).
3. Add a **"Rust library"** section after the CLI usage:

```markdown
## Rust library

`gram-data` publishes a library target alongside the CLI binary.

Add to `Cargo.toml`:
```toml
gram-data = "0.3"
```

### Lint a source string

```rust
use gram_data::lint::{LintOptions, lint_source};

let diags = lint_source("(alice)-[:KNOWS]->(bob)", &LintOptions { strict: false });
```

### Lint a file

```rust
use std::path::Path;
use gram_data::lint::{LintOptions, lint_file};

let diags = lint_file(Path::new("graph.gram"), &LintOptions { strict: false })?;
```

### Extract and lint gram snippets from Markdown

```rust
use gram_data::markdown::{extract_snippets, lint_markdown};
use gram_data::lint::LintOptions;

let snippets = extract_snippets(doc_source);
let results = lint_markdown(doc_source, &LintOptions { strict: false });
```

Diagnostic types (`Diagnostic`, `Severity`, `Position`, `Range`) are re-exported
from [`gram-diagnostics`](https://crates.io/crates/gram-diagnostics).
```

### `gram-diagnostics` README (new)

Target audience: library authors building tools that consume gram or cypher diagnostics.

Sections:
- **What it is**: shared LSP-compatible diagnostic types used by `gram-data` and `cypher-data`
- **Why it exists**: lets `relate` and other multi-language tools accept a single `Diagnostic` type regardless of which linter produced it
- **Types**: brief table of exported types (`Severity`, `Position`, `Range`, `Diagnostic`, `FileResult`, `LintResult`)
- **Usage**: minimal `Cargo.toml` snippet + import example
- **Note**: intentionally contains only types and derives — no parsing logic

---

## Sequencing

| Step | What | Files touched |
|------|------|---------------|
| 0a | Create `gram-diagnostics` crate + README | `crates/gram-diagnostics/`, `Cargo.toml` (workspace) |
| 0b | Move analysis modules from `gram-lsp` → `gram-data`; flip dep | `tools/gram/src/`, `tools/lsp/src/lsp.rs`, both `Cargo.toml`s |
| 1 | Rename check → lint; add `rule` field; drop `types.rs` | `tools/gram/src/main.rs`, `check.rs`→`lint.rs`, `types.rs` |
| 2 | Add `[lib]` + `src/lib.rs` (lint module only) | `tools/gram/Cargo.toml`, `src/lib.rs` |
| 3 | Add tree-sitter-markdown dep + markdown module | `tools/gram/Cargo.toml`, `src/lib.rs` |
| 4 | Add `queries/injections.scm` | `queries/injections.scm` |
| 5 | Update `tree-sitter.json` to reference injections | `tree-sitter.json` |
| 6 | Update `gram-data` README (`check`→`lint`, lib section, `readme` field) | `tools/gram/README.md`, `tools/gram/Cargo.toml` |
| 7 | Minor `gram-lsp` README touch-up (mention `gram lint`) | `tools/lsp/README.md` |
| 8 | Publish `gram-diagnostics` + `gram-data` + `gram-lsp` version bump | `Cargo.toml` version |

---

## Out of scope

- Schema validation in lint — tracked separately per the issue's own note.
