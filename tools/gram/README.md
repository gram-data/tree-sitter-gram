# gram

Command-line tool for working with [gram](https://github.com/gram-data/tree-sitter-gram) notation — a graph data format inspired by the property graph model.

> **Note:** This crate is published as `gram-data` on crates.io but installs a binary named `gram`.

## Install

```sh
cargo install gram-data
```

## Usage

### Validate gram files

```sh
# Check one or more files
gram check path/to/file.gram

# Check all .gram files in a directory
gram check path/to/dir/

# Check an inline expression
gram check -e '(alice)-[:KNOWS]->(bob)'

# Read from stdin
cat file.gram | gram check

# Exit non-zero on warnings too
gram check --strict file.gram

# Machine-readable output
gram check --json file.gram
```

### Manage extensions

Extensions are external binaries named `gram-<name>` installed to `~/.gram/bin/`.

```sh
# List available and installed extensions
gram extension list

# Install an extension
gram extension install <name>

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
