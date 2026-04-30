# CLI Commands Contract

**Tool**: `gram`  
**Version**: 0.4.0+

---

## gram check

Validate one or more `.gram` files for parse and semantic errors.

```
gram check [OPTIONS] [PATHS]...
```

### Arguments

| Argument | Description |
|----------|-------------|
| `PATHS` | Files, directories, or glob patterns to check. If absent and `-e` is not set, reads from stdin. |

### Options

| Flag | Description |
|------|-------------|
| `-e, --expression <EXPR>` | Validate an inline gram expression instead of reading files |
| `--json` | Output diagnostics as machine-readable JSON (see json-diagnostics.md) |
| `--tree` | Output the parse tree as an s-expression (implies checking a single input) |
| `--strict` | Treat warnings as errors (exit non-zero on any diagnostic) |
| `-h, --help` | Print help |

### Behavior

- Files are processed sequentially; directory arguments are traversed recursively, collecting all `.gram` files.
- Stdin is read when no `PATHS` and no `-e` are provided.
- `--json` and `--tree` are mutually exclusive.
- Glob patterns are expanded by the shell; `gram` does not expand globs itself.

### Exit Codes

| Code | Meaning |
|------|---------|
| 0 | No errors found (warnings do not affect exit code unless `--strict`) |
| 1 | One or more parse/semantic errors found |
| 2 | Invocation error (invalid arguments, file not found, etc.) |

### Output (human-readable, default)

```
error[parse]: unexpected token
  --> data/example.gram:3:5
   |
 3 |   (a)-[:REL->(b)
   |            ^
```

---

## gram extension install

Download and install an extension from the registry.

```
gram extension install <NAME>[@VERSION]
```

### Arguments

| Argument | Description |
|----------|-------------|
| `NAME` | Extension name as listed in the registry (e.g., `lsp`) |
| `@VERSION` | Optional pinned version (e.g., `@0.3.6`). Without it, installs the latest release. |

### Options

| Flag | Description |
|------|-------------|
| `--force` | Overwrite an already-installed version without prompting |
| `-h, --help` | Print help |

### Behavior

1. Reads the registry manifest to find the extension's GitHub repository.
2. Queries the GitHub Releases API for the specified or latest version.
3. Detects the current platform target triple.
4. Downloads the matching archive to a temporary file.
5. Unpacks the binary to `~/.gram/bin/<bin-name>`.
6. Records the installed version in `~/.gram/extensions.toml`.
7. Warns if `~/.gram/bin/` is not on `$PATH`.

### Exit Codes

| Code | Meaning |
|------|---------|
| 0 | Extension installed successfully |
| 1 | Installation failed (network error, no matching artifact, etc.) |
| 2 | Invocation error (unknown extension name, invalid version, etc.) |

---

## gram extension list

List available and installed extensions.

```
gram extension list [OPTIONS]
```

### Options

| Flag | Description |
|------|-------------|
| `--installed` | Show only installed extensions |
| `--available` | Show only registry entries (fetches registry) |
| `--json` | Output as JSON array |
| `-h, --help` | Print help |

### Output (human-readable, default)

```
Installed extensions:
  lsp  0.3.6  Language server protocol support

Available extensions:
  lsp  Language server protocol support  (gram-data/tree-sitter-gram)
```

---

## gram extension remove

Uninstall an extension.

```
gram extension remove <NAME>
```

### Behavior

- Removes the binary from `~/.gram/bin/`.
- Removes the entry from `~/.gram/extensions.toml`.
- Exits non-zero if the extension is not installed.

---

## gram <unknown-subcommand>

Dispatch to an external binary named `gram-<subcommand>` on `$PATH`.

### Behavior

- Searches `$PATH` for a binary named `gram-<subcommand>`.
- If found: execs it with all remaining arguments forwarded; forwards exit code.
- If not found: prints an error message and exits with code 2.

### Error message (not found)

```
error: unknown sub-command 'foo'

No built-in sub-command 'foo' and no 'gram-foo' binary found on PATH.

Try 'gram --help' for a list of built-in commands.
```

---

## Built-in Sub-commands (Priority Over PATH)

The following sub-command names are reserved and always handled by the built-in implementation, regardless of any `gram-*` binary on `$PATH`:

- `check`
- `extension`
- `help`
- `--version` / `-V`
