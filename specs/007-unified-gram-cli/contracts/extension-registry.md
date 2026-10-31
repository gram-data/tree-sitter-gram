# Extension Registry Contract

**Format**: TOML  
**Location**: `registry.toml` on `main` of [`gram-data/gram-extensions`](https://github.com/gram-data/gram-extensions); override with `GRAM_REGISTRY_URL`  

**Versions**: `versions.toml` beside `registry.toml` records `updated_at` and the latest release of each entry under `[versions]`. A workflow in gram-extensions generates it. `gram extension list` reads it to show latest versions and flag updates, and treats a missing file as no version information. With a custom `GRAM_REGISTRY_URL` the file is looked up by replacing a trailing `registry.toml`; any other URL has no versions file.
**Fetched by**: `gram extension list` and `gram extension install`

---

## Registry Manifest Format

```toml
[[extension]]
name = "lsp"
description = "Language server protocol support"
github = "gram-data/tree-sitter-gram"
bin = "gram-lsp"

[[extension]]
name = "fmt"
description = "Gram formatter"
github = "gram-data/gram-fmt"
bin = "gram-fmt"
```

### Extension Entry Fields

| Field | Type | Required | Description |
|-------|------|----------|-------------|
| `name` | string | yes | Unique short identifier; must match `[a-z][a-z0-9-]*` |
| `description` | string | yes | One-line human-readable description |
| `github` | string | yes | GitHub `owner/repo` of the project publishing release artifacts |
| `bin` | string | yes | Base binary name (without platform suffix or extension) |

---

## Release Artifact Naming Convention

Extension binaries MUST be published to GitHub Releases following this naming convention:

```
<bin>-<target-triple>.<archive-ext>
```

Where:
- `<bin>` matches the `bin` field in the registry entry
- `<target-triple>` is a Rust target triple (e.g., `x86_64-unknown-linux-musl`)
- `<archive-ext>` is `tar.gz` for Unix targets and `zip` for Windows targets

### Supported Target Triples

| Platform | Target Triple |
|----------|--------------|
| Linux x86_64 (musl) | `x86_64-unknown-linux-musl` |
| Linux aarch64 (musl) | `aarch64-unknown-linux-musl` |
| macOS x86_64 | `x86_64-apple-darwin` |
| macOS aarch64 (Apple Silicon) | `aarch64-apple-darwin` |
| Windows x86_64 (MSVC) | `x86_64-pc-windows-msvc` |

### Examples

```
gram-lsp-x86_64-unknown-linux-musl.tar.gz
gram-lsp-aarch64-apple-darwin.tar.gz
gram-lsp-x86_64-pc-windows-msvc.zip
```

---

## Local Installed Extensions Record

`gram` maintains a local record at `~/.gram/extensions.toml`:

```toml
[[installed]]
name = "lsp"
version = "0.3.6"
bin_path = "/Users/example/.gram/bin/gram-lsp"
installed_at = "2026-04-30T12:00:00Z"
```

### Installed Entry Fields

| Field | Type | Description |
|-------|------|-------------|
| `name` | string | Extension name (matches registry `name`) |
| `version` | string | Installed semantic version |
| `bin_path` | string | Absolute path to the installed binary |
| `installed_at` | string | ISO 8601 timestamp of installation |

---

## Version Resolution

- `gram extension install lsp` → fetches the latest GitHub Release tag for `gram-data/tree-sitter-gram` matching `v*`
- `gram extension install lsp@0.3.6` → fetches GitHub Release tagged `v0.3.6`
- GitHub Releases API endpoint: `https://api.github.com/repos/<github>/releases`
