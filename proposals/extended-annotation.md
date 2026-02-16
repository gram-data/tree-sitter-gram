### **gram-semantics.md**

# Gram Notation Semantics

**Status**: ⚠️ Proposal (Updates Pending)
**Reference**: Gram serialization and parsing

## Overview

Gram notation is a text format for representing `Pattern Subject` structures. It supports both generic **Pattern Notation** (using brackets) and specialized **Graph Notation** (using ASCII art for paths and `@` for annotations).

The core semantic principle is that **Graph Notation is syntactic sugar for Pattern Notation**. Every graph expression can be deterministically mapped to a generic pattern structure.

## Pattern Notation

### Definition Rule

**Brackets create definitions, bare identifiers create references**.

* `[...]` always defines a pattern (anonymous or identified).
* A bare identifier always references an existing pattern.
* Each identified pattern can only be defined once.

### Pattern Arity & Topology

The semantic role of a pattern is determined by its **arity** (the number of elements it contains). This maps generic patterns to Graph/ECS concepts:

| Arity | Notation | Topology | Semantic Role |
| --- | --- | --- | --- |
| **0** | `[a]` | **Node** | **Entity**: An atomic unit of existence. |
| **1** | `[b | a]` | **Wrapper** | **Annotation**: `b` wraps `a`, providing context or metadata. |
| **2** | `[r | a, b]` | **Relationship** | **Connection**: `r` connects or maps `a` to `b`. |
| **N** | `[C | a, b, c]` | **Component** | **Composition**: `C` is a composite structure containing multiple elements. |

### Examples

```gram
[a]                 // 0-arity: Defines node 'a'
[b | a]            // 1-arity: Defines wrapper 'b' around 'a'
[r | a, b]         // 2-arity: Defines relationship 'r' between 'a' and 'b'
[group | a, b, c]  // N-arity: Defines component 'group' containing 'a', 'b', 'c'

```

## Graph Notation Mapping

Graph notation provides shorthand for common topological structures. These map directly to pattern structures.

### 1. Nodes & Relationships

Standard Cypher-like syntax maps to 0-arity and 2-arity patterns.

| Graph Syntax | Equivalent Pattern | Logic |
| --- | --- | --- |
| `(a)` | `[a]` | Node definition. |
| `(a)-[r]->(b)` | `[r | a, b]` | Relationship definition (left-to-right). |
| `(a)<-[r]-(b)` | `[r | b, a]` | Relationship definition (right-to-left). |

### 2. Path Composition

Chained paths are **Components** (N-arity patterns), not recursive structures. A path is an anonymous pattern containing a sequence of relationships.

* **Graph:** `(a)-[r1]->(b)-[r2]->(c)`
* **Pattern:** `[ | [r1 | a, b], [r2 | b, c] ]`

*Note: The path itself is an anonymous component holding the defined relationships.*

### 3. Annotations (Unary Patterns)

The `@` syntax is syntactic sugar for **1-arity patterns** (Wrappers). It allows metadata, labels, or properties to wrap any graph element.

* **Syntax:** `@<Header> <Body>`
* **Mapping:** The `<Header>` becomes the defining pattern, and the `<Body>` becomes the single element inside it.

| Graph Syntax | Equivalent Pattern | Semantics |
| --- | --- | --- |
| `@desc (a)` | `[{desc} | a]` | Anonymous wrapper with property. |
| `@p (a)` | `[p | a]` | Identified wrapper `p` around `a`. |
| `@:L (a)` | `[:L | a]` | Labeled wrapper around `a`. |
| `@p:L (a)` | `[p:L | a]` | Full definition wrapper. |

#### Complex Annotation Example

Annotating a relationship or path wraps the entire structure:

* **Graph:** `@verified (a)-[r]->(b)`
* **Pattern:** `[{verified} | [r | a, b] ]`

## Semantic Constraints

### Single Definition

An identified pattern can only be defined once within a file.

* *Valid:* `[a] [b | a]`
* *Invalid:* `[a] [a]`

### Immutability

Once defined, a pattern's structure, labels, and properties cannot be changed.

### No Direct Self-Reference

A pattern cannot contain itself as a direct element.

### Forward References

References to patterns defined later in the file are allowed (e.g., `[r | a, b]` is valid even if `[a]` and `[b]` appear later).

## See Also

* **[Gram Serialization](https://www.google.com/search?q=../features/gram-serialization.md)** - Implementation specification
* **[Extended Semantics](https://www.google.com/search?q=../../design/EXTENDED-SEMANTICS.md)** - Extended semantics (historical)
