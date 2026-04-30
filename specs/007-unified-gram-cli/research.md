# Research: Unified `gram` CLI with Extensions

**Feature**: 007-unified-gram-cli  
**Phase**: 0 — Outline & Research  
**Date**: 2026-04-30

---

## 1. Sub-command Dispatch Pattern

**Decision**: Exec `gram-<name>` binary found on `$PATH`, passing all remaining arguments verbatim; forward the child's exit code.

**Rationale**: This is the established pattern used by `git` and `cargo`. It gives third parties a stable extension point without any registration. The implementation is a simple `$PATH` search followed by `std::process::Command::exec` (or `spawn` + `wait` on Windows). Built-in sub-commands take priority by matching before the PATH search.

**Alternatives considered**:
- Dynamic library plugins: Rejected — requires ABI stability and adds significant complexity.
- Subprocess via shell: Rejected — shell injection risk; direct exec is safer and faster.

---

## 2. Extension Registry Format

**Decision**: Static TOML manifest hosted as a file in the `gram-data` GitHub organization repository. Fetched on demand (no caching server required).

**Rationale**: A static file is the simplest possible registry. GitHub's raw content CDN provides adequate availability. TOML is already a first-class Rust ecosystem format (used by Cargo) and is human-readable.

**Manifest structure**:
```toml
[[extension]]
name = "lsp"
description = "Language server protocol support"
github = "gram-data/tree-sitter-gram"
bin = "gram-lsp"
```

**Alternatives considered**:
- JSON manifest: Valid but TOML is more idiomatic for this ecosystem.
- Custom registry server: Rejected — unnecessary operational complexity.
- Crates.io metadata: Rejected — conflates binary distribution with library publication.

---

## 3. Extension Installation Mechanism

**Decision**: Download platform-specific pre-built binary archives from GitHub Releases using `reqwest`, verify content type, unpack to `~/.gram/bin/`.

**Naming convention for release artifacts**:
```
gram-lsp-x86_64-unknown-linux-musl.tar.gz
gram-lsp-aarch64-apple-darwin.tar.gz
gram-lsp-x86_64-pc-windows-msvc.zip
```

**Rationale**: GitHub Releases are a stable, authenticated artifact host. cargo-dist already handles building and uploading these artifacts for the existing release workflow. `reqwest` is the idiomatic async HTTP client in the Rust ecosystem; we use its blocking feature to avoid async in the install path.

**Platform detection**: `std::env::consts::ARCH` + `std::env::consts::OS` map to target triples. Build-time `TARGET` env var (via `build.rs`) is more reliable for cross-compilation scenarios.

**Alternatives considered**:
- `curl`/`wget` subprocess: Rejected — not available on all platforms; hard to handle errors.
- binstall integration: Considered but adds a dependency on an external tool the user may not have.

---

## 4. Installation Directory and PATH Management

**Decision**: Install extension binaries to `~/.gram/bin/`. Use the `directories` crate to compute the platform-appropriate home directory (`BaseDirs::new().home_dir()`).

**PATH warning**: On first install, `gram` checks whether `~/.gram/bin/` is on `$PATH` and emits a one-time warning if not, with the appropriate shell configuration snippet.

**Alternatives considered**:
- `/usr/local/bin/`: Requires root on many systems; unacceptable for a user-scoped install.
- `$GRAM_HOME/bin/`: Configurable via env var — supported as override but `~/.gram/bin/` is the default.

---

## 5. Reusing gram-lsp Library for Diagnostics

**Decision**: Declare `gram-lsp` (the `tools/lsp` crate) as a workspace dependency in `tools/gram/Cargo.toml` and call its public `analyze_source()` function directly.

**Rationale**: The `gram-lsp` library already implements parse-error detection, duplicate element checks, duplicate record key checks, and symbol validation. Re-implementing this in `gram` would create drift. The library crate is already separated from the binary in `tools/lsp/src/lib.rs`.

**Impact**: `gram check` inherits all diagnostic capabilities of `gram-lsp check` automatically, including future improvements.

---

## 6. JSON Diagnostic Output Schema

**Decision**: Use the same `schema_version: 1` JSON format already produced by `gram-lsp check --json`, with the addition of a top-level `tool` field for version identification.

**Schema** (see `contracts/json-diagnostics.md` for full definition):
```json
{
  "schema_version": 1,
  "tool": "gram/0.4.0",
  "files": [
    {
      "path": "data/example.gram",
      "diagnostics": [
        {
          "severity": "error",
          "message": "Unexpected token",
          "range": {
            "start": { "line": 3, "character": 5 },
            "end":   { "line": 3, "character": 12 }
          }
        }
      ]
    }
  ]
}
```

**Alternatives considered**:
- SARIF format: Standard for static analysis tools; deferred as a stretch goal since it adds schema complexity.
- Newline-delimited JSON: Common for streaming; deferred — the full-file format is simpler for CI consumers.

---

## 7. `gram-lint` Removal

**Decision**: Remove `gram-lint` from the workspace immediately. The crate is deleted rather than kept with a deprecation shim.

**Rationale**: The project is pre-1.0 and `gram-lint` had no published adoption surface beyond early internal use. `gram check` is a strict superset: same input modes (files, directories, stdin, `-e`), same `--tree` flag, plus JSON output and semantic diagnostics. The cost of a forced migration is low; the cost of maintaining a shim indefinitely is not. A note in the release changelog is sufficient for any existing users.

---

## 8. cargo-dist Release Automation

**Decision**: Add cargo-dist to `tools/gram/Cargo.toml` for the new binary. Extend the existing `release.yml` and `gram-lsp-release-assets.yml` workflows to include `gram` artifacts.

**Rationale**: cargo-dist already handles the gram-lsp binary release pipeline. Extending it to `gram` reuses the existing CI investment and produces the naming convention expected by the extension installer.

---

## 9. Version Pinning for Extension Install

**Decision**: Support `gram extension install lsp@0.3.6` syntax. The version suffix maps to a GitHub Release tag (`v0.3.6`). Without a version, the latest release is fetched via the GitHub Releases API.

**Rationale**: Reproducible CI environments require pinned versions. The `@version` syntax is familiar from npm and other package managers.

---

## Summary of Resolved Unknowns

| Unknown | Resolution |
|---------|-----------|
| Dispatch mechanism | Direct exec of `gram-<name>` binary on PATH |
| Registry format | Static TOML on GitHub, fetched on demand |
| Extension storage | `~/.gram/bin/` via `directories` crate |
| Diagnostics library | Reuse `gram-lsp` lib crate via workspace dep |
| JSON output schema | Extend existing schema_version 1 format |
| Release automation | cargo-dist, extend existing `release.yml` |
| gram-lint lifecycle | Deprecated but kept for one major release |
