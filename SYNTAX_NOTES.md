# Gram Syntax Notes

Gram notation has specialized syntax for describing a hierarchy of decorated sequences of the form `[ value | elements ]`
where `value` is data/content, and `elements` are a sequence of decorated patterns.

Generically, this is a data structure called a "pattern". 

For example, `[ "digits_of_pi" | 3, 1, 4, 1, 5, 9 ]` is a sequence of integers with a string value that "decorates" them
with extra information. The semantics of the decoration is domain specific. Patterns are similar to lisp s-expressions but
with an emphasis on data representation, and not assumption about value interpretation.

More pattern examples, with differing semantics for the value:
- `[ + | 3, 6, 11 ]` could be a sum operation over the list of integers (lisp-like)
- `[ "KNOWS" | "ABK", "EE" ]` could form a "KNOWS" relationship from "ABK" to "EE"
- `[ "ABK" ]` could be an atomic element or a graph node
- `[ 42 | 20, 12, 10 ]` could be a pre-computed aggregate

Gram values are always of type `Subject`. In TypeScript, the pattern data structure would be defined as:
```ts
interface Pattern<V> {
  value: V;
  elements: Pattern<V>[];
}
```

A gram pattern is always of type: `Pattern<Subject>`.

## `gram_pattern` -- special pattern syntax for the top-level file context

The outermost pattern has no delimiters; it is the entire contents of the file. 
The value is provided by an optional curly-braced property record, and the
elements are a whitespace-separated sequence of annotated patterns.

Syntax: `[ root_record | annotated_pattern_sequence ]`

Where:
- `root_record` is a `record` which may appear only once at the top of a file
- `annotated_pattern_sequence` is a whitespace-separated sequence of `annotated_pattern`

Example:
```
{ version: "1.0" }
(node1)
(node2)-->(node3)
```

## `annotated_pattern` -- a top-level pattern element

An annotated pattern is the primary building block at the top level of a gram file. It consists of optional annotations followed by a comma-separated sequence of pattern elements.

Pattern: `annotated_pattern = [ annotations | pattern_sequence ]`

Where:
- `annotations` is zero or more `@key(value)` annotations
- `pattern_sequence` is a comma-separated sequence of pattern elements (`subject_pattern` or `path_pattern`)

Examples:
```
()                                    // Simple node pattern
@description("A node") ()             // Annotated node pattern
@title("Graph") ()-->()              // Annotated relationship pattern
@meta("data") [subject | a, b, c]   // Annotated subject pattern
```

**Note**: Annotations apply to the entire pattern, not individual elements within it. Multiple annotations can be stacked.

## `subject_pattern` -- subject pattern notation pattern

A subject pattern uses subject pattern notation `[ subject | subject_pattern_elements ]` to represent a pattern with an optional subject value and a sequence of elements.

Syntax: `[ subject | subject_pattern_elements ]`

Where:
- `subject` is optional content (identifier, labels, record) appearing before the `|`
- `subject_pattern_elements` is a comma-separated sequence of pattern elements appearing after the `|`

The elements can be:
- `subject_pattern` (nested brackets)
- `path_pattern` (node or relationship patterns)
- `pattern_reference` (identifier reference)

Examples:
```
[]                                    // Empty subject pattern
[a]                                   // Subject pattern with identifier
[a:Type]                              // Subject pattern with identifier and label
[a {k: "v"}]                          // Subject pattern with identifier and record
[a | b, c]                            // Subject pattern with elements
[devrel:Team {name: "DevRel"} | abk, adam, alex]  // Complete example
```

## `node_pattern` -- parenthesized node notation

A node pattern uses parentheses `( subject )` to represent a graph node or atomic element.

Syntax: `( subject )`

Where:
- `subject` is optional content (identifier, labels, record)

**Important**: Node patterns cannot have annotations inside the parentheses. Annotations must be applied at the `annotated_pattern` level.

Examples:
```
()                                    // Empty node
(player1)                              // Node with identifier
(player1:Player)                       // Node with identifier and label
(player1:Player {score: 100})          // Node with identifier, label, and record
```

## `relationship_pattern` -- graph relationship notation

A relationship pattern connects two path patterns with an arrow, representing a directed or undirected relationship in a graph.

Syntax: `left_path_pattern arrow right_path_pattern`

Where:
- `left_path_pattern` is a `node_pattern`
- `arrow` is one of the relationship arrow types (see below)
- `right_path_pattern` is a `path_pattern` (node or nested relationship)

### Arrow Types

**Right Arrow** (`->`, `=>`, `~>`):
- `-` followed by `->` (single dash)
- `=` followed by `=>` (double equals)
- `~` followed by `~>` (squiggle)

**Left Arrow** (`<-`, `<=`, `<~`):
- `<-` followed by `-`
- `<=` followed by `=`
- `<~` followed by `~`

**Undirected Arrow** (`-`, `=`, `~`):
- `-` followed by `-`
- `=` followed by `=`
- `~` followed by `~`

**Bidirectional Arrow** (`<->`, `<=>`, `<~>`):
- `<-` followed by `->`
- `<=` followed by `=>`
- `<~` followed by `~>`

### Arrow Subjects

Arrows can optionally include a subject in subject pattern notation between the arrow parts:
- `-[subject]->` for right arrows
- `<-[subject]-` for left arrows
- `-[subject]-` for undirected arrows
- `<-[subject]->` for bidirectional arrows

**Note**: Annotations cannot be placed inline within arrow brackets. Annotations must be applied at the `annotated_pattern` level (top-level).

Examples:
```
()-->()                               // Simple right arrow relationship
()-[KNOWS]->()                        // Relationship with subject
()-[r:KNOWS {weight: 5}]->()         // Relationship with identifier, labels, and record
()<-->()                              // Bidirectional relationship
()=~=()                               // Undirected relationship with equals
```

## `path_pattern` -- node or relationship pattern

A path pattern is either a `node_pattern` or a `relationship_pattern`. It represents a path through a graph, which can be a single node or a chain of relationships.

Examples:
```
(player1)                              // Single node path
(player1)-->(player2)                  // Two-node path
(player1)-->(player2)-->(player3)     // Three-node path
```

## `pattern_reference` -- identifier reference

A pattern reference is a bare identifier (symbol, string literal, or integer) that references another pattern. It can only appear within `subject_pattern_elements`.

Syntax: `identifier`

Where `identifier` is a `symbol`, `string_literal`, or `integer`.

Examples:
```
[a | abk, adam, alex]                  // References to other patterns
[team | "player1", "player2"]          // String literal references
[list | 1, 2, 3]                       // Integer references
```

## `subject` -- content within patterns

A subject represents the data/content portion of a pattern. It can include:
- `identifier`: A symbol, string literal, or integer
- `labels`: One or more type labels (prefixed with `:` or `::`)
- `record`: A collection of key-value properties

Subjects can combine these in various ways:
- Just an identifier: `player1`
- Just labels: `:Player`
- Just a record: `{name: "Player 1"}`
- Identifier + labels: `player1:Player`
- Identifier + record: `player1 {name: "Player 1"}`
- Labels + record: `:Player {name: "Player 1"}`
- All three: `player1:Player {name: "Player 1"}`

### `identifier`

An identifier can be:
- `symbol`: Alphanumeric string starting with letter/underscore, may contain `.`, `-`, `@` after first character
- `string_literal`: Quoted string (single, double, backtick, or fenced)
- `integer`: Numeric literal

Examples:
```
player1                                // Symbol identifier
"player 1"                             // String literal identifier
42                                      // Integer identifier
```

### `labels`

Labels are type annotations prefixed with `:` (single colon) or `::` (double colon), followed by a symbol.

Syntax: `:symbol` or `::symbol` (one or more)

Examples:
```
:Player                                // Single label
:Person:Employee                       // Multiple labels
::Type                                 // Double colon label
```

### `record`

A record is a collection of key-value pairs enclosed in curly braces `{}`.

Syntax: `{ record_property, ... }`

Where `record_property` is `key : value` or `key :: value` (single or double colon separator).

Record properties can have any `_value` type (see Values section below).

Examples:
```
{}                                     // Empty record
{name: "Player 1"}                    // Single property
{name: "Player 1", score: 100}        // Multiple properties
{name:: "Player 1"}                   // Double colon separator
```

### `map`

A map is similar to a record but only accepts scalar values (no nested structures). Maps use single colon `:` separator only.

Syntax: `{ map_entry, ... }`

Where `map_entry` is `key : scalar_value`.

Examples:
```
{key1: "value1", key2: 42}            // Map with string and number
{tags: ["a", "b"]}                    // Map with array (scalar)
```

## `annotation` -- metadata on patterns

Annotations provide metadata for patterns using the syntax `@key(value)`.

Syntax: `@key(value)`

Where:
- `key` is a `symbol`
- `value` is any `_value` type (see Values section)

Annotations can be applied to `annotated_pattern` elements (top-level patterns) only. They cannot be applied inside `node_pattern` parentheses or inline within relationship arrow brackets.

Examples:
```
@description("A node") ()             // Annotation on node pattern
@weight(5) ()-->()                    // Annotation on relationship pattern
@title("Graph") @version(1) ()        // Multiple annotations
```

## Values and Literals

### `_value` -- general value type

Values can appear in annotations, record properties, and other contexts. They include:
- `range`: Numeric range (e.g., `1..10`, `...100`, `1...`)
- `_numeric_literal`: Numbers (integer, decimal, hexadecimal, octal, measurement)
- `boolean_literal`: `true` or `false`
- `tagged_string`: String with a type tag
- `symbol`: Identifier symbol
- `string_literal`: Quoted string
- `array`: Array of scalar values
- `map`: Map of key-value pairs

### `_scalar_value` -- scalar value type

Scalar values are non-nested values used in arrays and maps:
- `range`
- `_numeric_literal`
- `boolean_literal`
- `tagged_string`
- `symbol`
- `string_literal`

### Numeric Literals

**Integer**: `-?(0|[1-9]\d*)`
- Examples: `0`, `42`, `-100`

**Decimal**: `-?(0|[1-9]\d*)\.\d+`
- Examples: `3.14`, `-0.5`, `100.0`

**Hexadecimal**: `0x[0-9a-fA-F]+`
- Examples: `0xFF`, `0x1a3f`

**Octal**: `0[0-7]+`
- Examples: `0777`, `0123`

**Measurement**: `-?(0|[1-9]\d*)([a-zA-Z]+)`
- Examples: `5px`, `100kg`, `-3.5m`

### String Literals

**Single-quoted**: `'content'`
- Examples: `'hello'`, `'it\'s'`

**Double-quoted**: `"content"`
- Examples: `"hello"`, `"say \"hi\""`

**Backtick-quoted**: `` `content` ``
- Examples: `` `hello` ``, `` `code\`here` ``

**Fenced**: ` ```\ncontent\n``` `
- Examples: Multi-line strings with triple backticks

### Tagged Strings

Tagged strings combine a type tag with string content:
- Backtick: `` tag`content` ``
- Fenced: ` ```tag\ncontent\n``` `

Examples:
```
sql`SELECT * FROM users`
```json
{"key": "value"}
```
```

### Arrays

Arrays contain comma-separated scalar values in square brackets.

Syntax: `[ scalar_value, ... ]`

Examples:
```
[]                                    // Empty array
[1, 2, 3]                             // Integer array
["a", "b", "c"]                       // String array
[1, "mixed", true]                    // Mixed scalar types
```

### Ranges

Ranges represent numeric intervals:
- `lower..upper`: Inclusive range from lower to upper
- `lower...`: Open-ended range from lower to infinity
- `...upper`: Open-ended range from negative infinity to upper

Examples:
```
1..10                                 // Range from 1 to 10
1...                                  // Range from 1 to infinity
...100                                // Range from negative infinity to 100
```

### Boolean Literals

- `true`
- `false`

## Comments

Line comments start with `//` and continue to the end of the line.

Syntax: `// comment_text`

Examples:
```
// This is a comment
()  // Comment after node
@key("value")  // Comment after annotation
```

Comments are ignored by the parser and can appear anywhere whitespace is allowed.

## Pattern Element Hierarchy

The complete hierarchy of pattern elements:

```
gram_pattern
└── top_level_pattern (whitespace-separated)
    ├── annotated_pattern
    │   ├── annotations
    │   └── element (single: subject_pattern or path_pattern)
    ├── subject_pattern
    │   ├── subject (optional, before |)
    │   └── elements (optional, comma-separated, after |)
    │       ├── subject_pattern (nested)
    │       ├── path_pattern
    │       └── pattern_reference
    ├── node_pattern
    │   └── subject (optional)
    └── relationship_pattern
        ├── left: node_pattern
        ├── kind: arrow
        └── right: path_pattern
```
