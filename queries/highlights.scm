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

; Definition-like identifiers (FR-001): @type
; subject/node subject is _subject (use wildcard _ as it may be hidden in some runtimes)
(subject_pattern subject: (_ identifier: (_) @type))
(subject_pattern subject: (_ labels: (labels (symbol) @type)))
(node_pattern subject: (_ identifier: (_) @type))
(node_pattern subject: (_ labels: (labels (symbol) @type)))
(relationship_pattern left: (node_pattern subject: (_ identifier: (_) @type)))
(relationship_pattern left: (node_pattern subject: (_ labels: (labels (symbol) @type))))
(relationship_pattern right: (node_pattern subject: (_ identifier: (_) @type)))
(relationship_pattern right: (node_pattern subject: (_ labels: (labels (symbol) @type))))
; Arrow kind: subject is inside optional brackets on the arrow
(relationship_pattern kind: (right_arrow subject: (_ identifier: (_) @type)))
(relationship_pattern kind: (right_arrow subject: (_ labels: (labels (symbol) @type))))
(relationship_pattern kind: (left_arrow subject: (_ identifier: (_) @type)))
(relationship_pattern kind: (left_arrow subject: (_ labels: (labels (symbol) @type))))
(relationship_pattern kind: (undirected_arrow subject: (_ identifier: (_) @type)))
(relationship_pattern kind: (undirected_arrow subject: (_ labels: (labels (symbol) @type))))
(relationship_pattern kind: (bidirectional_arrow subject: (_ identifier: (_) @type)))
(relationship_pattern kind: (bidirectional_arrow subject: (_ labels: (labels (symbol) @type))))
(identified_annotation identifier: (_) @type)
(identified_annotation labels: (labels (symbol) @type))

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
(record_property key: (string_literal) @property)
(record_property key: (integer) @property)
(map_entry key: (symbol) @property)
(map_entry key: (string_literal) @property)
(map_entry key: (integer) @property)

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
