# `gram` CLI with Extensions

**Status:** Proposal (summary of discussion)
**Scope:** `tools/gram-lint`, `tools/lsp`, and a new unified `gram` binary.

---

## 1. Motivation

Two separate CLI tools currently exist:

| Tool | Purpose | Notable capabilities |
|------|---------|----------------------|
| `gram-lint` | Parse error linter | stdin, `-e` inline expressions, `--tree` s-expression output |
| `gram-lsp` | LSP server + file checker | `check` subcommand, JSON output, directory traversal, full diagnostics |

`gram-lsp check` largely supersedes `gram-lint`, but each tool has unique features the other lacks. Users must know which tool to reach for, and the surface area grows with every new capability added as a separate binary.

A unified `gram` CLI consolidates these and provides a principled home for future sub-commands.

---

## 2. Design

### Base binary

`gram` is a lightweight base binary. It owns a small set of built-in sub-commands and dispatches unknown sub-commands to external binaries on `$PATH`.

Built-in sub-commands (initial):

| Sub-command | Replaces | Notes |
|-------------|---------|-------|
| `gram check` | `gram-lint` + `gram-lsp check` | stdin, `-e`, `--tree`, `--json`, directory traversal |
| `gram extension` | — | install, list, remove extensions |

### First-party extensions

Heavier capabilities (LSP server, future language tooling) ship as optional extensions. The LSP server becomes:

```
gram lsp stdio     # start LSP server over JSON-RPC
```

installed via:

```
gram extension install lsp
```

### Sub-command dispatch

Unknown sub-commands fall through to a `gram-*` binary search on `$PATH`, following the same pattern as `cargo` and `git`:

```
gram lsp stdio  →  exec gram-lsp stdio
gram foo bar    →  exec gram-foo bar
```

Built-in sub-commands take priority. This gives third parties a natural extension point without coordination.

---

## 3. Cargo features for compile-time bundling

For users who build from source or want a single self-contained binary, Cargo features allow extensions to be compiled in:

```toml
[features]
default = []
lsp = ["dep:tokio", "dep:tower-lsp", "dep:gram-lsp"]
```

```
cargo install gram --features lsp
```

This is optional — the external binary model works without it.

---

## 4. Extension discovery and installation

### Registry: a curated manifest

A `extensions.toml` manifest (hosted in this repo or a dedicated `gram-data/gram-extensions` repo) lists known extensions:

```toml
[[extension]]
name = "lsp"
description = "Language server protocol support"
github = "gram-data/tree-sitter-gram"
bin = "gram-lsp"
```

`gram extension list` fetches the manifest. No custom server is required.

### Installation: prebuilt binaries from GitHub Releases

Extensions publish platform-specific binaries as GitHub Release artifacts following a standard naming convention:

```
gram-lsp-x86_64-unknown-linux-musl.tar.gz
gram-lsp-aarch64-apple-darwin.tar.gz
gram-lsp-x86_64-pc-windows-msvc.zip
```

`gram extension install lsp`:
1. Reads the manifest to find the GitHub repo
2. Queries the GitHub Releases API for the latest (or pinned) version
3. Detects the current platform target triple
4. Downloads and unpacks the binary to `~/.gram/bin/`

This requires no Rust toolchain — only `gram` itself.

### Release automation: `cargo-dist`

[cargo-dist](https://github.com/axodotdev/cargo-dist) automates building and uploading platform artifacts to GitHub Releases. Adding it to `gram-lsp` (and future extensions) is the primary setup cost per extension.

---

## 5. CI/CD usage

```yaml
- name: Install gram
  run: curl -fsSL https://github.com/gram-data/tree-sitter-gram/releases/latest/download/gram-installer.sh | sh

- name: Install lsp extension
  run: gram extension install lsp

- name: Lint gram files
  run: gram check **/*.gram
```

No Rust or cargo required. The binary download takes seconds.

Version pinning:

```yaml
- run: gram extension install lsp@0.3.6
```

---

## 6. Migration path

1. Create `tools/gram/` — the new base binary with `check` and `extension` sub-commands
2. Migrate `gram-lint` features into `gram check` (stdin, `-e`, `--tree`)
3. Add `gram-lsp` features to `gram check` (`--json`, directory traversal)
4. Wire up subprocess dispatch for `gram lsp` → `gram-lsp`
5. Add `cargo-dist` to `gram-lsp` release workflow
6. Add the manifest and implement `gram extension install`
7. Deprecate standalone `gram-lint` binary

---

## 7. Open questions

- Where should `~/.gram/bin/` be added to `$PATH`? (installer script, shell profile, or documented manual step)
- Should `gram extension install` support a lockfile for reproducible environments?
- Is `gram check` the right name, or `gram lint`? (`check` aligns with `cargo check`; `lint` is more familiar for non-Rust users)
