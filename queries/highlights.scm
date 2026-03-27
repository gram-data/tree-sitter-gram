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
; Node and subject pattern identifiers (symbols, quoted names, integers in subject)
(node_pattern subject: (symbol) @type)
(node_pattern subject: (quoted_name) @type)
(node_pattern subject: (integer) @type)
(subject_pattern subject: (symbol) @type)
(subject_pattern subject: (quoted_name) @type)
(subject_pattern subject: (integer) @type)

; Labels (symbols and quoted names)
(labels (symbol) @type)
(labels (quoted_name) @type)

; Relationship arrow identifiers (in arrow brackets)
(right_arrow subject: (symbol) @type)
(right_arrow subject: (quoted_name) @type)
(right_arrow subject: (integer) @type)
(left_arrow subject: (symbol) @type)
(left_arrow subject: (quoted_name) @type)
(left_arrow subject: (integer) @type)
(undirected_arrow subject: (symbol) @type)
(undirected_arrow subject: (quoted_name) @type)
(undirected_arrow subject: (integer) @type)
(bidirectional_arrow subject: (symbol) @type)
(bidirectional_arrow subject: (quoted_name) @type)
(bidirectional_arrow subject: (integer) @type)

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
