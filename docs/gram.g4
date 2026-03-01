/**
 * Gram Notation — ANTLR4 Grammar
 *
 * Derived from: grammar.js (tree-sitter reference implementation)
 * Standard:     ANTLR4 (https://www.antlr.org)
 * File ext:     .g4
 * Date:         2026-03-01
 *
 * Usage:
 *   antlr4 -Dlanguage=<Target> gram.g4
 *
 * Targets: Java, Python3, JavaScript, TypeScript, Go, Rust, C#, C++
 *
 * Notes:
 *   - Parser rules begin with a lowercase letter
 *   - Lexer rules begin with an uppercase letter
 *   - Whitespace and line comments are sent to a hidden channel
 *     (not discarded) so tooling can recover them for round-trip
 *     serialization
 */

grammar gram;


// ============================================================
// PARSER RULES
// ============================================================


// ------------------------------------------------------------
// Document
//
// A gram document is an optional header record followed by zero
// or more top-level patterns.
//
// The leading record is a document header — metadata about the
// file, not a graph element. Example: { kind: "schema" }
// ------------------------------------------------------------

gramPattern
    : record? topLevelPattern* EOF
    ;

topLevelPattern
    : annotatedPattern
    | subjectPattern
    | nodePattern
    | relationshipPattern
    ;


// ------------------------------------------------------------
// Annotated Pattern
//
// One or more annotations wrap a subject or path pattern.
// All @ annotations and the optional @@ annotation merge into
// a single wrapper subject:
//   - @@ contributes identity and labels
//   - @ forms contribute properties (keys must be unique)
//   - at most one @@ is permitted per annotation stack
//
// Result: Pattern<Subject> with one element (the wrapped pattern)
// and a subject carrying the merged annotation data.
// ------------------------------------------------------------

annotatedPattern
    : annotations ( subjectPattern | pathPattern )
    ;

annotations
    : identifiedAnnotation propertyAnnotation*
    | propertyAnnotation+
    ;

// @key(value) — contributes one property to the merged wrapper record
propertyAnnotation
    : '@' SYMBOL '(' value ')'
    ;

// @@id:Label — contributes identity and labels to the merged wrapper subject
// At most one @@ per annotation stack (enforced by the annotations rule above)
identifiedAnnotation
    : '@@' identifier
    | '@@' labels
    | '@@' identifier labels
    ;


// ------------------------------------------------------------
// Subject Pattern — square-bracket / pattern notation
//
// '[' always defines a new pattern.
// A bare identifier inside elements is a reference to a pattern
// defined elsewhere in the file (forward references are permitted).
// The '|' separates the subject from its elements.
// ------------------------------------------------------------

subjectPattern
    : '[' subject? ( '|' subjectPatternElements )? ']'
    ;

subjectPatternElements
    : subjectPatternElement ( ',' subjectPatternElement )*
    ;

subjectPatternElement
    : subjectPattern        // inline definition
    | pathPattern           // inline path
    | patternReference      // reference by identity
    ;

patternReference
    : identifier
    ;


// ------------------------------------------------------------
// Path Pattern — parenthesis / path notation
//
// Nodes in path notation are always atomic (no inline elements).
//
// relationshipPattern is right-recursive:
//   (a)-[r1]->(b)-[r2]->(c)
//   parses as: (a)-[r1]->( (b)-[r2]->(c) )
//
// A path with a single relationship resolves to that relationship.
// A path with multiple relationships is an anonymous walk — a
// connected sequence with no identity of its own.
//
// When lowering to Pattern<V>, each relationship becomes an
// independent two-element pattern; walk structure is not preserved.
// ------------------------------------------------------------

pathPattern
    : relationshipPattern
    | nodePattern
    ;

nodePattern
    : '(' subject? ')'
    ;

relationshipPattern
    : nodePattern relationshipKind pathPattern
    ;


// ------------------------------------------------------------
// Subject
//
// The value portion of a pattern: identity, labels, properties.
// All components are individually optional but at least one
// must be present (the outer subject? handles fully absent).
// ------------------------------------------------------------

subject
    : identifier
    | labels
    | record
    | identifier labels
    | identifier record
    | labels record
    | identifier labels record
    ;


// ------------------------------------------------------------
// Labels
//
// ':' and '::' are semantically equivalent — purely stylistic.
// By convention '::' suggests schema or ontology intent.
// Labels are unordered and stored as a set.
// ------------------------------------------------------------

labels
    : label+
    ;

label
    : labelSeparator SYMBOL
    ;

labelSeparator
    : ':'
    | '::'
    ;


// ------------------------------------------------------------
// Record and Map
//
// The property system has two bounded levels — intentionally
// deeper than Cypher but shallower than JSON:
//
//   depth 0  scalar              primitives only
//   depth 1  array, map          scalar values only
//   depth 2  record              any value incl. array and map
//   structural                   promote instead of nesting deeper
//
// record and map share surface syntax { key: value } but are
// distinguished by context:
//   record  — subject position (node, relationship, or pattern)
//   map     — value position (inside a record property value)
//
// '::' is permitted on record properties but not map entries,
// providing a visual cue for the distinction.
// ------------------------------------------------------------

record
    : '{' ( recordProperty ( ',' recordProperty )* )? '}'
    ;

recordProperty
    : identifier labelSeparator value
    ;

map
    : '{' ( mapEntry ( ',' mapEntry )* )? '}'
    ;

mapEntry
    : identifier ':' scalarValue
    ;


// ------------------------------------------------------------
// Relationship Kinds
//
// All three arrow families (-, =, ~) are semantically equivalent.
// Choice is stylistic: '-'/'->' for data graphs;
// '='/'=>' and '~'/'~>' suggest schema/ontology definitions.
//
// Directionality encodes element order in Pattern<V>:
//   (a)-[r]->(b)   →  [r | a, b]   right: left-to-right
//   (a)<-[r]-(b)   →  [r | b, a]   left:  reversed
//   (a)-[r]-(b)    →  [r | a, b]   undirected: falls through to right
//   (a)<-[r]->(b)  →  [r | a, b]   bidirectional: falls through to right
//
// Arrow kind is NOT preserved once lowered to Pattern<V>.
// ------------------------------------------------------------

relationshipKind
    : undirectedArrow
    | rightArrow
    | leftArrow
    | bidirectionalArrow
    ;

undirectedArrow
    : '-'  ( '[' subject? ']' )? '-'
    | '='  ( '[' subject? ']' )? '='
    | '~'  ( '[' subject? ']' )? '~'
    ;

rightArrow
    : '-'  ( '[' subject? ']' )? '->'
    | '='  ( '[' subject? ']' )? '=>'
    | '~'  ( '[' subject? ']' )? '~>'
    ;

leftArrow
    : '<-' ( '[' subject? ']' )? '-'
    | '<=' ( '[' subject? ']' )? '='
    | '<~' ( '[' subject? ']' )? '~'
    ;

bidirectionalArrow
    : '<-' ( '[' subject? ']' )? '->'
    | '<=' ( '[' subject? ']' )? '=>'
    | '<~' ( '[' subject? ']' )? '~>'
    ;


// ------------------------------------------------------------
// Values
//
// value      — full set; used in record properties and annotations
// scalarValue — excludes array and map; used inside array and map
//               to bound nesting depth to two levels
// ------------------------------------------------------------

value
    : range
    | numericLiteral
    | booleanLiteral
    | taggedString
    | SYMBOL
    | stringLiteral
    | array
    | map
    ;

scalarValue
    : range
    | numericLiteral
    | booleanLiteral
    | taggedString
    | SYMBOL
    | stringLiteral
    ;

// array is non-empty — [] parses as an empty subjectPattern, not an array
array
    : '[' scalarValue ( ',' scalarValue )* ']'
    ;


// ------------------------------------------------------------
// Identifiers
//
// An identifier may be a symbol, string literal, or integer,
// allowing quoted or numeric node identities:
//   [a]        symbol identifier
//   ["node-1"] string identifier
//   [42]       integer identifier
//
// The reserved property key '_' stores anonymous scalar values
// (e.g. ["hello"] stores "hello" under '_'). It is a valid
// symbol but conventionally reserved.
// ------------------------------------------------------------

identifier
    : SYMBOL
    | stringLiteral
    | INTEGER
    ;


// ============================================================
// LEXER RULES
// ============================================================


// ------------------------------------------------------------
// Boolean
// ------------------------------------------------------------

booleanLiteral
    : TRUE
    | FALSE
    ;

TRUE  : 'true' ;
FALSE : 'false' ;


// ------------------------------------------------------------
// Numeric Literals
// ------------------------------------------------------------

numericLiteral
    : INTEGER
    | DECIMAL
    | HEXADECIMAL
    | OCTAL
    | MEASUREMENT
    ;

// Range — higher precedence than plain numeric in ambiguous contexts
range
    : numericLiteral '..' numericLiteral    // bounded:       lower..upper
    | numericLiteral '...'                  // lower-bounded: lower...
    | '...'          numericLiteral         // upper-bounded: ...upper
    ;

INTEGER
    : '-'? ( '0' | [1-9] [0-9]* )
    ;

DECIMAL
    : '-'? ( '0' | [1-9] [0-9]* ) '.' [0-9]+
    ;

HEXADECIMAL
    : '0x' [0-9a-fA-F]+
    ;

OCTAL
    : '0' [0-7]+
    ;

// Unit suffix immediately follows digits with no space.
// Examples: 5m, 10kg, 2.5s
// Note: any alphabetic suffix is accepted; unit validation
// is left to consumers.
MEASUREMENT
    : '-'? ( '0' | [1-9] [0-9]* ) [a-zA-Z]+
    ;


// ------------------------------------------------------------
// String Literals
//
// Four quoting styles, all producing the same string value type.
//
// Escape sequences (single, double, backtick forms):
//   \\  \'  \"  \`  \b  \f  \n  \r  \t
//
// Fenced strings are multiline; content begins after the newline
// that follows the opening ```.
// ------------------------------------------------------------

stringLiteral
    : SINGLE_QUOTED_STRING
    | DOUBLE_QUOTED_STRING
    | BACKTICK_STRING
    | FENCED_STRING
    ;

SINGLE_QUOTED_STRING
    : '\'' ( '\\\'' | ~['\\\n] )* '\''
    ;

DOUBLE_QUOTED_STRING
    : '"' ( '\\"' | ~["\\\n] )* '"'
    ;

BACKTICK_STRING
    : '`' ( '\\`' | ~[`\\\n] )* '`'
    ;

FENCED_STRING
    : '```' '\n' FENCED_CONTENT? '```'
    ;

fragment FENCED_CONTENT
    : ( ~'`' | '`' ~'`' | '``' ~'`' )+
    ;


// ------------------------------------------------------------
// Tagged String
//
// Attaches a type tag (a SYMBOL) to a string value.
// Two forms: inline backtick and fenced multiline.
//
// Examples:
//   url`https://example.com`
//   date`2024-01-15`
//   ```html
//   <p>Hello</p>
//   ```
// ------------------------------------------------------------

taggedString
    : TAGGED_BACKTICK_STRING
    | TAGGED_FENCED_STRING
    ;

TAGGED_BACKTICK_STRING
    : SYMBOL_FRAG '`' ( '\\`' | ~[`\\\n] )* '`'
    ;

TAGGED_FENCED_STRING
    : '```' SYMBOL_FRAG '\n' FENCED_CONTENT? '```'
    ;


// ------------------------------------------------------------
// Symbol
//
// Starts with a letter or underscore.
// Subsequent characters may include digits, '.', '-', and '@'.
// Hyphens are legal in symbol names: reading-club is valid.
// ------------------------------------------------------------

SYMBOL
    : SYMBOL_FRAG
    ;

fragment SYMBOL_FRAG
    : [a-zA-Z_] [0-9a-zA-Z_.\-@]*
    ;


// ------------------------------------------------------------
// Whitespace and Comments
//
// Both are routed to a hidden channel rather than discarded,
// preserving them for tools that need round-trip fidelity
// (formatters, diff tools, serializers).
//
// Exception: the newline immediately after the opening ``` of a
// fenced string is significant and is consumed by FENCED_STRING /
// TAGGED_FENCED_STRING above.
// ------------------------------------------------------------

COMMENT
    : '//' ~[\r\n]* -> channel(HIDDEN)
    ;

WS
    : [ \t\r\n]+ -> channel(HIDDEN)
    ;
