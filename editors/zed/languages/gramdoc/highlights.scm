; Copied from gram-data/tree-sitter-gramdoc v0.2.0 (queries/highlights.scm).
; gramdoc is injected into gram `/** ... */` doc comments (see queries/injections.scm).

; Name
(document (name) @title)

; Tag keywords
"@property" @keyword
"@alias" @keyword
"@label" @keyword
"@elements" @keyword
"@element" @keyword
"@source" @keyword
"@target" @keyword
(self_tag) @keyword
"@reference" @keyword
(tag_name) @keyword

; Tag arguments
(property_tag name: (identifier) @variable.parameter)
(label_tag name: (identifier) @type)
(cardinality) @number
(alias) @string
(reference_target) @string.special

; Descriptions
(description_line) @comment
