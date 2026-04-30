# Data Model: Unified `gram` CLI with Extensions

**Feature**: 007-unified-gram-cli  
**Phase**: 1 — Design & Contracts  
**Date**: 2026-04-30

---

## Entities

### Extension

An installable capability that extends the `gram` CLI with additional sub-commands or tools.

| Field | Type | Description |
|-------|------|-------------|
| `name` | String | Unique short name (e.g., `lsp`) |
| `description` | String | Human-readable description |
| `version` | SemVer | Installed version |
| `bin_name` | String | Binary name on disk (e.g., `gram-lsp`) |
| `install_path` | Path | Absolute path to installed binary (`~/.gram/bin/<bin_name>`) |

**Validation rules**:
- `name` MUST match `[a-z][a-z0-9-]*`
- `version` MUST be a valid semantic version (MAJOR.MINOR.PATCH)
- `install_path` must be within the gram bin directory

**State transitions**:
```
[not installed] → install → [installed]
[installed] → remove → [not installed]
[installed] → install (upgrade/downgrade) → [installed]
```

---

### RegistryEntry

A record in the extension registry manifest describing an available extension.

| Field | Type | Description |
|-------|------|-------------|
| `name` | String | Extension name (matches `Extension.name`) |
| `description` | String | Human-readable description |
| `github` | String | GitHub `owner/repo` (e.g., `gram-data/tree-sitter-gram`) |
| `bin` | String | Base binary name (e.g., `gram-lsp`) |

**Artifact naming convention** (derived, not stored):  
`<bin>-<target-triple>.(tar.gz|zip)`  
e.g., `gram-lsp-aarch64-apple-darwin.tar.gz`

---

### Diagnostic

A parse or semantic error/warning produced by `gram check`.

| Field | Type | Description |
|-------|------|-------------|
| `severity` | Severity | `error`, `warning`, `information`, or `hint` |
| `message` | String | Human-readable description of the issue |
| `range` | Range | Location in the source file |

---

### Range

A span within a source file, using 0-based line and character offsets.

| Field | Type | Description |
|-------|------|-------------|
| `start` | Position | Start position (inclusive) |
| `end` | Position | End position (exclusive) |

---

### Position

A point in a source file.

| Field | Type | Description |
|-------|------|-------------|
| `line` | u32 | 0-based line number |
| `character` | u32 | 0-based character offset (UTF-16 code units for LSP compatibility) |

---

### FileResult

The result of running `gram check` against a single source file.

| Field | Type | Description |
|-------|------|-------------|
| `path` | String | File path as provided to the command |
| `diagnostics` | Vec\<Diagnostic\> | All diagnostics for this file (may be empty) |

---

### CheckResult

The aggregate result of a `gram check` invocation.

| Field | Type | Description |
|-------|------|-------------|
| `schema_version` | u32 | Always `1` |
| `tool` | String | `"gram/<version>"` |
| `files` | Vec\<FileResult\> | Results for each checked file |

---

## Relationships

```
CheckResult
  └── 1..* FileResult
        └── 0..* Diagnostic
                └── Range (start: Position, end: Position)

RegistryEntry  ←→  Extension   (registry entry describes an installable extension)
```

---

## Runtime State

| Location | Contents |
|----------|---------|
| `~/.gram/bin/` | Installed extension binaries |
| `~/.gram/extensions.toml` | Local record of installed extensions and versions |
| GitHub Releases API | Canonical source of available extension versions |
| Registry manifest URL | List of known extensions (fetched on demand) |

---

## Invariants

1. At most one `gram-<name>` binary exists in `~/.gram/bin/` at any time.
2. A built-in sub-command name (`check`, `extension`) can never be overridden by an installed extension or a PATH binary.
3. `gram extension install` is atomic: either the binary is fully written and the local record updated, or no change occurs (download to temp file, then rename).
4. Exit code 0 means no errors were found; any non-zero exit code indicates at least one diagnostic with severity `error` was emitted.
