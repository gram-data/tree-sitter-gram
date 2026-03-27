# Contracts: Tighten Quoted Names

**Feature**: `005-tighten-quoted-identifiers`

## Overview

This feature does not introduce a REST or GraphQL API. The contracts in this directory define the grammar and AST behavior that downstream tooling can rely on for identifiers, labels, and keys after the quoting rules are tightened.

## Contract Documents

| Document | Purpose |
|----------|---------|
| [quoted-names.md](./quoted-names.md) | Defines allowed quoted forms and AST expectations for identifiers, labels, keys, and unaffected symbol-only contexts. |

## Impact on Existing Contracts

- **Grammar**: `grammar.js` will separate quoted-name syntax from general `string_literal` values.
- **AST / node types**: If visible quoted-name rules are introduced, `node-types.json` and query captures must reflect the new node types.
- **Queries**: Label and key captures must recognize quoted-name nodes wherever they carry the same semantic role as bare symbols.
- **Corpus**: Corpus fixtures remain the executable contract for accepted and rejected syntax.
