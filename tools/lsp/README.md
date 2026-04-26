# gram-lsp

Rust [Language Server Protocol](https://microsoft.github.io/language-server-protocol/) implementation for **Gram** (`.gram`) files in the [tree-sitter-gram](https://github.com/gram-data/tree-sitter-gram) workspace. It shares parsing and diagnostics with the `tree-sitter-gram` crate and the `gram-lint` tool.

## Features

- **stdio LSP** — diagnostics, hover, go to definition, find references, basic completions.
- **`gram-lsp check`** — same analysis as the editor path; `--json` emits the schema described in `specs/006-gram-lsp/contracts/cli-diagnostics.md`.
- **Semantic checks** — duplicate *named* element definitions inside a `subject_pattern_elements` list (per spec).

## Build

From the **repository root**:

```bash
cargo build --release -p gram-lsp
```

The binary is `target/release/gram-lsp` (debug: `target/debug/gram-lsp`).

Install it with:

```bash
cargo install --path tools/lsp/
```

## Run

### Language server (stdio)

```bash
gram-lsp stdio
```

Editors should launch this command and speak LSP over the process stdin/stdout. The server uses UTF-8 sources and UTF-16 positions on the wire, as required by LSP.

### CLI check

Human-readable diagnostics on stderr:

```bash
gram-lsp check path/to/models path/to/file.gram
```

Machine-readable JSON on stdout (non-zero exit if any error-level diagnostic):

```bash
gram-lsp check --json path/to/file.gram
```

## Tests

```bash
cargo test -p gram-lsp
cargo clippy -p gram-lsp --all-targets -- -D warnings
```

## Zed

The **Gram** Zed extension (`editors/zed/`; [editors/zed/README.md](../../editors/zed/README.md)) starts **`gram-lsp stdio`**. Unless you override the binary in Zed settings (see below), the extension uses **`gram-lsp` on `PATH`** if `worktree.which` finds it; otherwise it downloads **`gram-lsp-{target}.tar.gz`** from the GitHub release tagged **`v` + `extension.toml` `version`**, built by [gram-lsp-release-assets.yml](../../.github/workflows/gram-lsp-release-assets.yml).

The extension manifest declares `download_file` and `process:exec` for that flow. If you restrict [extension capabilities](https://zed.dev/docs/extensions/capabilities.html), allow `download_file` for `github.com` under `gram-data/tree-sitter-gram`.

### Optional: custom binary path

If `gram-lsp` is not on `PATH`, point Zed at it in `~/.config/zed/settings.json` (macOS), `$XDG_CONFIG_HOME/zed/settings.json` (Linux), or `.zed/settings.json`:

```json
{
  "lsp": {
    "gram-lsp": {
      "binary": {
        "path": "/absolute/path/to/tree-sitter-gram/target/release/gram-lsp",
        "arguments": ["stdio"]
      }
    }
  }
}
```

The key under `"lsp"` must match the language server id in `extension.toml` (`gram-lsp`). If another extension registers servers for Gram, you can order or disable them with `languages.Gram.language_servers`; see [Configuring languages | Zed](https://zed.dev/docs/configuring-languages.html).

Open a `.gram` file and use **Zed: open LSP logs** if diagnostics or hover do not appear.

## See also

- Spec: `specs/006-gram-lsp/spec.md`
- CLI contract: `specs/006-gram-lsp/contracts/cli-diagnostics.md`
- Quickstart: `specs/006-gram-lsp/quickstart.md`
