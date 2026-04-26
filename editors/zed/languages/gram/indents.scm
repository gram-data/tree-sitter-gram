; Indentation: 2 spaces per level for brackets and multi-line structures
; FR-007 — specs/004-editor-improvements/contracts/indents.md

; Record {}
"{" @indent
"}" @indent.end

; Subject pattern []
"[" @indent
"]" @indent.end

; Node pattern ()
"(" @indent
")" @indent.end
