# Feature Specification: Line-Based and End-of-Line Comments

**Feature Branch**: `001-line-comments`  
**Created**: 2025-11-10  
**Status**: Draft  
**Input**: User description: "Allow line-based or end-of-line comments in gram files, but not in-line, to allow gram files to be self-documenting"

## User Scenarios & Testing *(mandatory)*

### User Story 1 - Add Line-Based Comments (Priority: P1)

A developer writing a gram file wants to add explanatory comments on their own lines to document the structure and purpose of the gram file content. These comments should be ignored by the parser and not affect the parsing of gram syntax.

**Why this priority**: Line-based comments are the most common form of documentation in code files and provide the foundation for self-documenting gram files. This is essential for making gram files readable and maintainable.

**Independent Test**: Can be fully tested by adding a line comment to an existing gram file and verifying that the parser ignores the comment and successfully parses the gram syntax as if the comment were not present.

**Acceptance Scenarios**:

1. **Given** a gram file with valid gram syntax, **When** a developer adds a line comment (entire line starting with comment marker), **Then** the parser ignores the comment and parses the gram syntax correctly
2. **Given** a gram file with multiple line comments, **When** the file is parsed, **Then** all comments are ignored and the gram syntax is parsed correctly
3. **Given** a gram file with a line comment containing special characters, **When** the file is parsed, **Then** the comment is ignored without causing parsing errors

---

### User Story 2 - Add End-of-Line Comments (Priority: P2)

A developer writing a gram file wants to add brief explanatory comments at the end of a line containing gram syntax, allowing inline documentation without requiring a separate line.

**Why this priority**: End-of-line comments allow developers to add contextual explanations right next to the code they document, improving readability while keeping the file compact.

**Independent Test**: Can be fully tested by adding an end-of-line comment after valid gram syntax on a line and verifying that the parser ignores the comment portion and successfully parses the gram syntax before the comment.

**Acceptance Scenarios**:

1. **Given** a gram file with valid gram syntax on a line, **When** a developer adds an end-of-line comment after the syntax, **Then** the parser ignores the comment and parses the gram syntax correctly
2. **Given** a gram file with end-of-line comments on multiple lines, **When** the file is parsed, **Then** all comments are ignored and all gram syntax is parsed correctly
3. **Given** a gram file with an end-of-line comment containing special characters, **When** the file is parsed, **Then** the comment is ignored without causing parsing errors

---

### Edge Cases

- What happens when a comment marker appears inside a string literal? (Should be treated as part of the string, not a comment)
- What happens when a comment appears at the very beginning of a file?
- What happens when a comment appears at the very end of a file (after all gram syntax)?
- What happens when multiple comment markers appear on the same line?
- How are comments handled when they appear between pattern elements separated by commas?
- What happens when a comment marker appears in a position that would be considered "in-line" (e.g., between tokens that must be adjacent)?

## Requirements *(mandatory)*

### Functional Requirements

- **FR-001**: The parser MUST support line-based comments where an entire line is treated as a comment and ignored during parsing
- **FR-002**: The parser MUST support end-of-line comments where text after a comment marker on a line is ignored, but gram syntax before the comment marker is parsed normally
- **FR-003**: The parser MUST NOT support in-line comments (comments that appear between tokens that must be adjacent in gram syntax)
- **FR-004**: Comments MUST be ignored by the parser and must not affect the parsing of gram syntax
- **FR-005**: Comments MUST NOT cause parsing errors when they contain special characters, whitespace, or other content
- **FR-006**: Comment markers appearing inside string literals MUST be treated as part of the string content, not as comment delimiters
- **FR-007**: Gram files with comments MUST parse to the same AST structure as equivalent gram files without comments (when comments are removed)

### Key Entities *(include if feature involves data)*

- **Comment**: Text that is ignored by the parser, used for documentation purposes. Comments can be line-based (entire line) or end-of-line (portion of a line after comment marker).
- **Comment Marker**: The syntax that indicates the start of a comment (e.g., `//` for line comments).
- **Gram Syntax**: The actual language constructs (subjects, nodes, relationships, patterns) that are parsed and represented in the AST.

## Success Criteria *(mandatory)*

### Measurable Outcomes

- **SC-001**: Developers can add line-based comments to gram files without causing parsing errors in 100% of cases where comments follow the defined syntax rules
- **SC-002**: Developers can add end-of-line comments to gram files without causing parsing errors in 100% of cases where comments follow the defined syntax rules
- **SC-003**: Gram files with comments parse to identical AST structures as equivalent files without comments (when comments are removed), maintaining 100% functional equivalence
- **SC-004**: Comment markers inside string literals are correctly preserved as string content in 100% of cases, never triggering comment parsing
- **SC-005**: All existing gram files without comments continue to parse correctly after comment support is added, maintaining 100% backward compatibility
