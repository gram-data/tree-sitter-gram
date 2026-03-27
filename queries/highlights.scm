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

; Comment (FR-003)
(comment) @comment

; Tagged-string tag distinct from content (FR-002)
(tagged_string tag: (symbol) @attribute)

; Reference identifier: pattern_reference (FR-001)
(pattern_reference identifier: (_) @variable)

; Definition-like identifiers and labels (FR-001): @type
; Direct identifier and labels highlighting
(identifier: (_) @type)
(labels (symbol) @type)
(labels (quoted_name) @type)

; Annotation identifiers and labels
(identified_annotation identifier: (_) @type)
(identified_annotation labels: (labels (symbol) @type))
(identified_annotation labels: (labels (quoted_name) @type))

; Symbols and identifiers (generic; definition/reference/tag captured above)
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
(record_property key: (quoted_name) @property)
(record_property key: (double_quoted_name) @property)
(map_entry key: (symbol) @property)
(map_entry key: (quoted_name) @property)
(map_entry key: (double_quoted_name) @property)

; Annotation keys (property-style) and headers (identified/label-style)
(property_annotation key: (symbol) @attribute)

; Relationship arrows (special highlighting for graph syntax)
(relationship_pattern) @keyword

; Arrow operators in relationships
(right_arrow) @operator
(left_arrow) @operator
(undirected_arrow) @operator
(bidirectional_arrow) @operator

; Error highlighting
(ERROR) @error
