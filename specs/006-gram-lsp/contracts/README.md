# Contracts: Gram LSP (`tools/lsp`)

**Feature**: 006-gram-lsp  
**Date**: 2026-04-26

Behavior contracts for the Rust language server, CLI output, and navigation semantics so implementation and tests stay aligned with [spec.md](../spec.md).

| Contract | Description |
|----------|-------------|
| [lsp-capabilities.md](./lsp-capabilities.md) | Capabilities advertised and LSP methods the server implements for MVP vs deferred |
| [cli-diagnostics.md](./cli-diagnostics.md) | JSON envelope for `check` (or equivalent) subcommand |
| [navigation-semantics.md](./navigation-semantics.md) | Definition/reference rules tied to locals query intent |
