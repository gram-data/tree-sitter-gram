# Gram Notation — EBNF Grammar

**Derived from:** `grammar.js` (tree-sitter reference implementation)  
**Notation:** W3C-style EBNF  
**Date:** 2026-03-01

---

## Notation Key

| Syntax | Meaning |
|---|---|
| `=` | definition |
| `;` | end of rule |
| `\|` | alternation |
| `,` | concatenation |
| `[ ... ]` | optional (zero or one) |
| `{ ... }` | repetition (zero or more) |
| `( ... )` | grouping |
| `"..."` | literal terminal |
| `/.../` | regular expression terminal |
| `(*...*)`| comment |

---

## 1. Document

```ebnf
gram_pattern = [ record ], { top_level_pattern } ;

top_level_pattern = annotated_pattern
                  | subject_pattern
                  | node_pattern
                  | relationship_pattern
                  ;
```

**Note:** The leading `record` is a **document header** — metadata about the file rather than a graph element. Example: `{ kind: "schema" }`. It is not part of the graph structure.

---

## 2. Patterns

### 2.1 Annotated Pattern

```ebnf
annotated_pattern = annotations, ( subject_pattern | path_pattern ) ;
```

### 2.2 Subject Pattern (Square-Bracket / Pattern Notation)

```ebnf
subject_pattern = "[", [ subject ], [ "|", subject_pattern_elements ], "]" ;

subject_pattern_elements = subject_pattern_element, { ",", subject_pattern_element } ;

subject_pattern_element = subject_pattern
                        | path_pattern
                        | pattern_reference
                        ;

pattern_reference = identifier ;
```

**Note:** A bare `identifier` inside elements is a **reference** to a previously (or forward-) defined pattern. A bracketed `[ ... ]` is always a **definition**.

### 2.3 Path Pattern (Parenthesis / Path Notation)

```ebnf
path_pattern = relationship_pattern | node_pattern ;

node_pattern = "(", [ subject ], ")" ;

relationship_pattern = node_pattern, relationship_kind, path_pattern ;
```

**Note:** `relationship_pattern` is right-recursive: `(a)-[r1]->(b)-[r2]->(c)` parses as `(a)-[r1]->( (b)-[r2]->(c) )`. When lowering to `Pattern<V>`, each relationship becomes an independent two-element pattern; the walk structure is not preserved in the data model.

---

## 3. Annotations

Annotations wrap a pattern with metadata. They produce a `Pattern<V>` with one element (the annotated pattern) and a subject carrying the annotation data.

```ebnf
annotations = ( identified_annotation, { property_annotation } )
            | property_annotation, { property_annotation }
            ;

(* @key(value) — attaches a single key/value metadata pair *)
property_annotation = "@", symbol, "(", value, ")" ;

(* @@id:Label — syntactic sugar for the wrapper subject's identity and labels *)
identified_annotation = "@@", ( identifier
                               | labels
                               | identifier, labels
                               ) ;
```

**Stylistic note:** `@@` identified annotations are intended for schema/ontology contexts where the annotation wrapper itself needs to be a typed, referenceable entity.

---

## 4. Subject

A subject is the value portion of a pattern — its identity, labels, and properties.

```ebnf
subject = identifier
        | labels
        | record
        | identifier, labels
        | identifier, record
        | labels, record
        | identifier, labels, record
        ;
```

All components are optional individually, but at least one must be present (the outer `[ subject ]` in `subject_pattern` handles the fully-absent case).

---

## 5. Labels

```ebnf
labels = label, { label } ;

label = label_separator, ( symbol | quoted_name ) ;

label_separator = ":" | "::" ;
```

**Stylistic note:** `:` and `::` are **semantically equivalent**. By convention, `::` suggests schema or ontology intent (e.g. type assertions), but the parser assigns no distinct meaning.

---

## 6. Record and Map

The property system has two bounded levels, intentionally shallower than JSON but deeper than Cypher:

```ebnf
(* Appears in subject position — values may be any value including map *)
record = "{", [ record_property, { ",", record_property } ], "}" ;

record_property = key_name, label_separator, value ;

(* Appears in value position — values must be scalar *)
map = "{", [ map_entry, { ",", map_entry } ], "}" ;

map_entry = key_name, ":", scalar_value ;
```

**Depth budget:**

| Level | Construct | Value constraint |
|---|---|---|
| 0 | scalar | primitives only |
| 1 | `array`, `map` | scalar values only |
| 2 | `record` | any value (including `array` and `map`) |
| structural | node, relationship, pattern | promote instead of nesting deeper |

**Note:** `record` and `map` share surface syntax `{ key: value }` but are distinguished by **context**: `record` appears in subject position (attached to a node, relationship, or pattern); `map` appears in value position (as a property value inside a `record_property`). The double-colon separator `::` is permitted on `record_property` but not `map_entry`, providing a visual cue for the distinction.

---

## 7. Relationship Kinds

All arrow families are **semantically equivalent** — the choice is stylistic. By convention, `=`/`=>` and `~`/`~>` arrows suggest schema or ontology definitions (paired with `::` labels), while `-`/`->` is the default for data graphs.

```ebnf
relationship_kind = undirected_arrow
                  | right_arrow
                  | left_arrow
                  | bidirectional_arrow
                  ;
```

### 7.1 Undirected

```ebnf
undirected_arrow = "-",  [ "[", [ subject ], "]" ], "-"
                 | "=",  [ "[", [ subject ], "]" ], "="
                 | "~",  [ "[", [ subject ], "]" ], "~"
                 ;
```

### 7.2 Right Arrow (directed a → b)

```ebnf
right_arrow = "-",  [ "[", [ subject ], "]" ], "->"
            | "=",  [ "[", [ subject ], "]" ], "=>"
            | "~",  [ "[", [ subject ], "]" ], "~>"
            ;
```

### 7.3 Left Arrow (directed b → a)

```ebnf
left_arrow = "<-", [ "[", [ subject ], "]" ], "-"
           | "<=", [ "[", [ subject ], "]" ], "="
           | "<~", [ "[", [ subject ], "]" ], "~"
           ;
```

### 7.4 Bidirectional

```ebnf
bidirectional_arrow = "<-", [ "[", [ subject ], "]" ], "->"
                    | "<=", [ "[", [ subject ], "]" ], "=>"
                    | "<~", [ "[", [ subject ], "]" ], "~>"
                    ;
```

### 7.5 Directionality and Element Order

Direction controls the element order when lowering to `Pattern<V>`:

| Arrow | `Pattern<V>` elements | Notes |
|---|---|---|
| `(a)-[r]->(b)` | `[r \| a, b]` | right arrow: left-to-right |
| `(a)<-[r]-(b)` | `[r \| b, a]` | left arrow: reversed |
| `(a)-[r]-(b)` | `[r \| a, b]` | undirected: falls through to right-facing |
| `(a)<-[r]->(b)` | `[r \| a, b]` | bidirectional: falls through to right-facing |

**Once lowered to `Pattern<V>`, arrow kind is not preserved.** If consumers need to distinguish undirected or bidirectional from directed, they must retain the AST node kind from the parse phase. Semantic distinction between relationship types is best expressed through labels and schema conventions rather than arrow choice.

---

## 8. Values

```ebnf
value = range
      | numeric_literal
      | boolean_literal
      | tagged_string
      | symbol
      | string_literal
      | array
      | map
      ;

(* scalar_value excludes array and map — used inside array and map *)
scalar_value = range
             | numeric_literal
             | boolean_literal
             | tagged_string
             | symbol
             | string_literal
             ;

array = "[", scalar_value, { ",", scalar_value }, "]" ;
```

---

## 9. Literals

### 9.1 Boolean

```ebnf
boolean_literal = "true" | "false" ;
```

### 9.2 Numeric

```ebnf
numeric_literal = integer | decimal | hexadecimal | octal | measurement ;

integer     = /\-?(0|[1-9]\d*)/ ;

decimal     = /\-?(0|[1-9]\d*)\.\d+/ ;

hexadecimal = /0x[0-9a-fA-F]+/ ;

octal       = /0[0-7]+/ ;

measurement = /\-?(0|[1-9]\d*)([a-zA-Z]+)/ ;
             (* e.g. 5m, 10kg, 3.5s — unit immediately follows digits, no space *)
```

### 9.3 Range

```ebnf
range = numeric_literal, "..", numeric_literal   (* bounded: lower..upper *)
      | numeric_literal, "..."                   (* lower-bounded: lower... *)
      | "...", numeric_literal                   (* upper-bounded: ...upper *)
      ;
```

**Note:** Range is right-associative (higher precedence than other numeric forms in ambiguous contexts).

### 9.4 String Literals

Four quoting styles, all producing the same `string` value type:

```ebnf
string_literal = single_quoted_string
               | double_quoted_string
               | backtick_string
               | fenced_string
               ;

single_quoted_string = "'", /(\\'|[^'\\\n])*/, "'" ;

double_quoted_string = '"', /(\\"|[^"\\\n])*/, '"' ;

backtick_string      = "`", /(\\'|[^`\\\n])*/, "`" ;

fenced_string        = "```", "\n", [ /([^`]|`[^`]|``[^`])+/ ], "```" ;
                      (* multiline; content begins after the newline *)
```

Supported escape sequences in single, double, and backtick strings: `\\`, `\'`, `\"`, `` \` ``, `\b`, `\f`, `\n`, `\r`, `\t`.

### 9.5 Tagged String

A tagged string attaches a type tag (a `symbol`) to a string value, expressed in two forms. See [Tagged strings and injections](tagged-strings-and-injections.md) for well-known tags, language injection, and the `::` schema convention.

```ebnf
tagged_string = symbol, "`", /([^`\\\n])*/, "`"
              | "```", symbol, "\n", [ /([^`]|`[^`]|``[^`])+/ ], "```"
              ;
```

Examples:
```gram
url`https://example.com`
date`2024-01-15`
```

```gram
```html
<p>Hello</p>
```
```

---

## 10. Identifiers and Symbols

```ebnf
quoted_name = backtick_string ;

double_quoted_name = double_quoted_string ;

key_name = symbol | quoted_name | double_quoted_name ;

identifier = symbol | quoted_name | integer ;

symbol = /[a-zA-Z_][0-9a-zA-Z_.\-@]*/ ;
```

**Notes:**
- Symbols start with a letter or underscore; subsequent characters may include digits, `.`, `-`, and `@`.
- `quoted_name` and `integer` are valid identifiers, allowing backtick-quoted or numeric node identities.
- Record and map keys may be `symbol`, `quoted_name`, or `double_quoted_name`.
- The reserved property key `_` is used internally to store anonymous scalar values (e.g. `["hello"]` stores `"hello"` under `_`). It is a valid symbol and may appear in user-written records, but consuming code should treat it as conventionally reserved.

---

## 11. Whitespace and Comments

```ebnf
comment    = "//", /.*/ ;   (* line comment, extends to end of line *)

whitespace = /\s+/ ;        (* spaces, tabs, newlines — all equivalent *)
```

Both are **ignored everywhere** (they appear in the grammar's `extras`, meaning they may occur freely between any two tokens). There are no significant-whitespace rules, with one exception: the fenced string body begins **after** the newline that follows the opening ` ``` `.

---

## 12. Complete Rule Index

| Rule | Section |
|---|---|
| `gram_pattern` | §1 |
| `top_level_pattern` | §1 |
| `annotated_pattern` | §2.1 |
| `subject_pattern` | §2.2 |
| `subject_pattern_elements` | §2.2 |
| `subject_pattern_element` | §2.2 |
| `pattern_reference` | §2.2 |
| `path_pattern` | §2.3 |
| `node_pattern` | §2.3 |
| `relationship_pattern` | §2.3 |
| `annotations` | §3 |
| `property_annotation` | §3 |
| `identified_annotation` | §3 |
| `subject` | §4 |
| `labels` | §5 |
| `label` | §5 |
| `label_separator` | §5 |
| `record` | §6 |
| `record_property` | §6 |
| `map` | §6 |
| `map_entry` | §6 |
| `relationship_kind` | §7 |
| `undirected_arrow` | §7.1 |
| `right_arrow` | §7.2 |
| `left_arrow` | §7.3 |
| `bidirectional_arrow` | §7.4 |
| `value` | §8 |
| `scalar_value` | §8 |
| `array` | §8 |
| `boolean_literal` | §9.1 |
| `numeric_literal` | §9.2 |
| `integer` | §9.2 |
| `decimal` | §9.2 |
| `hexadecimal` | §9.2 |
| `octal` | §9.2 |
| `measurement` | §9.2 |
| `range` | §9.3 |
| `string_literal` | §9.4 |
| `tagged_string` | §9.5 |
| `identifier` | §10 |
| `symbol` | §10 |
| `comment` | §11 |
| `whitespace` | §11 |
