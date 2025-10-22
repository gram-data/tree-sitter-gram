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

; Brackets and delimiters
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
(property key: (symbol) @property)
(property key: (string_literal) @property)
(property key: (integer) @property)
(mapping key: (symbol) @property)
(mapping key: (string_literal) @property)
(mapping key: (integer) @property)

; Annotation keys
(annotation key: (symbol) @attribute)

; Annotations inside nodes
(node annotations: (annotations) @attribute)

; Annotations inside relationship arrows
[
    (right_arrow annotations: (annotations) @attribute)
    (left_arrow annotations: (annotations) @attribute)
    (undirected_arrow annotations: (annotations) @attribute)
    (bidirectional_arrow annotations: (annotations) @attribute)
]

; Subject brackets (special highlighting)
(subject) @type

; Node with labels
(node (labels (symbol) @type))

; Relationship arrows (special highlighting for graph syntax)
(relationship) @keyword

; Arrow operators in relationships
(right_arrow) @operator
(left_arrow) @operator
(undirected_arrow) @operator
(bidirectional_arrow) @operator

; Error highlighting
(ERROR) @error
