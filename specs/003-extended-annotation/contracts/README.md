# Contracts: Extended Annotation

**Feature**: 003-extended-annotation

## Overview

This feature does not introduce REST or GraphQL APIs. The "contracts" here define the **AST shape** and **grammar rules** that the parser must satisfy for annotations. Downstream tools (editors, serializers, semantic analyzers) can rely on these shapes.

## Contract Documents

| Document            | Purpose |
|---------------------|--------|
| [annotations.md](./annotations.md) | Annotation rule contract: `@` vs `@@`, identifier/labels and body structure, expected node/field names. |

## Impact on Existing Contracts

**Grammar**: The annotation rule is extended (and possibly split into `property_annotation` and `identified_annotation`). Generated `node-types.json` may gain new node types or fields.

**Bindings**: Any code that walks annotation nodes must handle (1) property-style `@key(value)` and (2) identified/labeled `@@` with identifier and/or labels. **identified_annotation** exposes **identifier** and **labels** as direct fields; body is **annotated_pattern.elements**. Field names must be stable for consumers.

**Corpus tests**: Act as the executable contract; expected trees in `test/corpus/extended_annotations.txt` must match the parser output.
