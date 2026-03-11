# Contracts: Editor Support and Syntax Highlighting

**Feature**: 004-editor-improvements  
**Date**: 2025-03-11

This directory holds behavior contracts for the query files and documentation. They define required captures, override sets, and doc content so implementation and tests can be validated against the spec.

| Contract | Description |
|----------|-------------|
| [highlights.md](./highlights.md) | Highlight capture names and node mapping (definition vs reference, tag, comment) |
| [locals.md](./locals.md) | Locals capture names and file scope |
| [indents.md](./indents.md) | Indentation rules and 2-space step |
| [injections.md](./injections.md) | Injection language capture and minimal overrides (md, ts) |
| [documentation.md](./documentation.md) | Well-known tags table and `::` schema convention |
