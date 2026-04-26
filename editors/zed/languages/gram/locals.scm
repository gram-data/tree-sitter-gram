; Locals: go to definition and highlight references (file scope)
; FR-005, FR-006 — specs/004-editor-improvements/contracts/locals.md

; File scope: all definitions and references in one scope
(gram_pattern) @local.scope

; Definitions: identifiers that define a pattern or annotation
(subject_pattern subject: (_ identifier: (_) @local.definition))
(subject_pattern subject: (_ labels: (labels (symbol) @local.definition)))
(subject_pattern subject: (_ labels: (labels (quoted_name) @local.definition)))
(node_pattern subject: (_ identifier: (_) @local.definition))
(node_pattern subject: (_ labels: (labels (symbol) @local.definition)))
(node_pattern subject: (_ labels: (labels (quoted_name) @local.definition)))
(relationship_pattern left: (node_pattern subject: (_ identifier: (_) @local.definition)))
(relationship_pattern left: (node_pattern subject: (_ labels: (labels (symbol) @local.definition))))
(relationship_pattern left: (node_pattern subject: (_ labels: (labels (quoted_name) @local.definition))))
(relationship_pattern right: (node_pattern subject: (_ identifier: (_) @local.definition)))
(relationship_pattern right: (node_pattern subject: (_ labels: (labels (symbol) @local.definition))))
(relationship_pattern right: (node_pattern subject: (_ labels: (labels (quoted_name) @local.definition))))
(relationship_pattern kind: (right_arrow subject: (_ identifier: (_) @local.definition)))
(relationship_pattern kind: (right_arrow subject: (_ labels: (labels (symbol) @local.definition))))
(relationship_pattern kind: (right_arrow subject: (_ labels: (labels (quoted_name) @local.definition))))
(relationship_pattern kind: (left_arrow subject: (_ identifier: (_) @local.definition)))
(relationship_pattern kind: (left_arrow subject: (_ labels: (labels (symbol) @local.definition))))
(relationship_pattern kind: (left_arrow subject: (_ labels: (labels (quoted_name) @local.definition))))
(relationship_pattern kind: (undirected_arrow subject: (_ identifier: (_) @local.definition)))
(relationship_pattern kind: (undirected_arrow subject: (_ labels: (labels (symbol) @local.definition))))
(relationship_pattern kind: (undirected_arrow subject: (_ labels: (labels (quoted_name) @local.definition))))
(relationship_pattern kind: (bidirectional_arrow subject: (_ identifier: (_) @local.definition)))
(relationship_pattern kind: (bidirectional_arrow subject: (_ labels: (labels (symbol) @local.definition))))
(relationship_pattern kind: (bidirectional_arrow subject: (_ labels: (labels (quoted_name) @local.definition))))
(identified_annotation identifier: (_) @local.definition)
(identified_annotation labels: (labels (symbol) @local.definition))
(identified_annotation labels: (labels (quoted_name) @local.definition))

; References: pattern_reference identifier
(pattern_reference identifier: (_) @local.reference)
