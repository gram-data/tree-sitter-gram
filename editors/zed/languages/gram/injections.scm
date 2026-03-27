; Language injection for tagged strings: tag`content` and ```tag\ncontent\n```
;
; The tag symbol is used as the injection language so that downstream and editors
; can support arbitrary tags without changing the grammar. Well-known tags (md, ts,
; date, datetime, time, sql, json, html, etc.) are documented in docs/tagged-strings-and-injections.md.
;
; Overrides below map tags that do not match common parser names. The final
; rule uses the tag's text as the language name for all other tags (e.g. "sql",
; "json", "html" often match parser names).

; md -> markdown
(tagged_string
  tag: (symbol) @_tag
  content: (string_content) @injection.content)
(#eq? @_tag "md")
(#set! injection.language "markdown")

; ts -> typescript
(tagged_string
  tag: (symbol) @_tag
  content: (string_content) @injection.content)
(#eq? @_tag "ts")
(#set! injection.language "typescript")

; Dynamic: use tag text as language name for all other tags (sql, json, html, etc.)
; Editors may map additional tags (e.g. date, datetime, time) to parsers or leave as plain.
(tagged_string
  tag: (symbol) @injection.language
  content: (string_content) @injection.content)
