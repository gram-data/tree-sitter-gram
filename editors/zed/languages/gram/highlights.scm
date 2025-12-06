; Strings
(string_literal) @string
(string_content) @string

; Numbers
(integer) @number
(decimal) @number
(hexadecimal) @number
(octal) @number
(measurement) @number

; Boolean literals
(boolean_literal) @boolean

; Symbols and identifiers
(symbol) @variable

; Keywords and operators
[
    "@"
    "|"
    ":"
    "::"
] @operator

; Subject Patterns and delimiters
[
    "["
    "]"
    "("
    ")"
    "{"
    "}"
] @punctuation.bracket

; Comma separator
[
    ","
] @punctuation.delimiter

; Field names in records and maps
(record_property key: (symbol) @property)
(record_property key: (string_literal) @property)
(record_property key: (integer) @property)
(map_entry key: (symbol) @property)
(map_entry key: (string_literal) @property)
(map_entry key: (integer) @property)

; Annotation keys
(annotation key: (symbol) @attribute)

; Subject Pattern notation (special highlighting)
(subject_pattern) @type

; Node with labels
(node_pattern (labels (symbol) @type))

; Relationship arrows (special highlighting for graph syntax)
(relationship_pattern) @keyword

; Arrow operators in relationships
(right_arrow) @operator
(left_arrow) @operator
(undirected_arrow) @operator
(bidirectional_arrow) @operator

; Error highlighting
(ERROR) @error
