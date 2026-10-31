# gram

Command-line tool and Rust library for working with [gram](https://github.com/gram-data/tree-sitter-gram) notation — a graph data format inspired by the property graph model.

> **Note:** This crate is published as `gram-data` on crates.io but installs a binary named `gram`.

## Install

```sh
cargo install gram-data
```

## CLI usage

### Lint gram files

```sh
# Lint one or more files
gram lint path/to/file.gram

# Lint all .gram files in a directory
gram lint path/to/dir/

# Lint an inline expression
gram lint -e '(alice)-[:KNOWS]->(bob)'

# Read from stdin
cat file.gram | gram lint

# Exit non-zero on warnings too
gram lint --strict file.gram

# Machine-readable JSON output
gram lint --json file.gram
```

> `gram check` is a legacy alias for `gram lint`.

### Manage extensions

Extensions are external binaries named `gram-<name>` installed to `~/.gram/bin/`.

```sh
# List available and installed extensions, with latest versions
gram extension list

# Install an extension
gram extension install <name>

# Upgrade one extension, or all of them (--dry-run shows what would change)
gram extension upgrade <name>
gram extension upgrade --all

# Remove an extension
gram extension remove <name>
```

### Install agent skills

`gram skill` installs gram's SKILL.md into AI coding agents (Claude Code, Cursor, Codex, Copilot, Gemini CLI, Kiro). The skill tells the agent how to work with `.gram` files and surfaces `cargo install gram-data` as a prerequisite for users who discover the skill first.

```sh
# Install to all detected agents in the current project
gram skill install

# Install globally (home-directory paths)
gram skill install --global

# Install to a specific agent only
gram skill install --agent claude

# List installed locations
gram skill list

# Remove from all detected locations
gram skill remove
```

Supported agents: `claude`, `cursor`, `codex`, `copilot`, `gemini`, `kiro`

### Dispatch to extensions

Any subcommand not built into `gram` is dispatched to a `gram-<name>` binary on `PATH` or in `~/.gram/bin/`:

```sh
gram lsp          # runs gram-lsp
gram my-tool arg  # runs gram-my-tool arg
```

## Exit codes

| Code | Meaning |
|------|---------|
| `0`  | No errors (warnings allowed unless `--strict`) |
| `1`  | Parse or semantic errors found |
| `2`  | Tool or I/O error |

## Rust library

`gram-data` also publishes a library target for tools that want to lint `.gram` files or extract gram snippets from Markdown without shelling out to the binary.

```toml
[dependencies]
gram-data = "0.3"
```

Diagnostic types are re-exported from [`gram-diagnostics`](https://crates.io/crates/gram-diagnostics), which is also used by [`cypher-data`](https://crates.io/crates/cypher-data), so multi-language tools receive a single `Diagnostic` type regardless of which linter ran.

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

// Just extract
let snippets = extract_snippets(doc_source);

// Extract and lint in one pass
let results = lint_markdown(doc_source, &LintOptions { strict: false });
for (snippet, diags) in results {
    for d in diags {
        eprintln!("line {}: {}", snippet.fence_start_line + 1 + d.range.start.line as usize, d.message);
    }
}
```

Recognised fence tags: ` ```gram ` and ` ~~~gram ` (case-insensitive).
