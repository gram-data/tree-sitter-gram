# Contracts: Refactor Terminology

**Feature**: 001-refactor-terminology

## Overview

No API contracts are required for this feature. This is a terminology refactoring that:
- Renames grammar rules and field names
- Updates internal node type and field names in generated parser code
- Updates documentation and examples

The refactoring does not introduce new APIs, endpoints, or external interfaces. The syntax of gram files remains unchanged, ensuring backward compatibility at the user-facing level.

## Impact on Existing Contracts

**Language Bindings**: Generated code will use new node type names (`bracket` instead of `subject`) and field names (`subject` instead of `attributes`). This is a breaking change for any code that directly references these names, but:
- The AST structure remains identical
- Only names change, not structure or behavior
- Version bump will be required for published packages

**No External API Changes**: No REST APIs, GraphQL schemas, or other external contracts are affected.

