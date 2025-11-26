# Gram Syntax Notes

Gram notation has specialized syntax for describing a hierarchy of decorated sequences of the form `[ value | elements ]`
where `value` is data/content, and `elements` are a sequence of decorated patterns.

Generically, this is a data structure called a "pattern". 

For example, `[ "digits_of_pi" | 3, 1, 4, 1, 5, 9 ]` is a sequence of integers with a string value that "decorates" them
with extra information. The semantics of the decoration is domain specific. Patterns are similar to lisp s-expressions but
with an emphasis on data representation, and not assumption about value interpretation.

More pattern examples, with differing semantics for the value:
- `[ + | 3, 6, 11 ]` could be a sum operation over the list of integers (lisp-like)
- `[ "KNOWS" | "ABK", "EE" ]` could form a "KNOWS" relationship from "ABK" to "EE"
- `[ "ABK" ]` could be an atomic element or a graph node
- `[ 42 | 20, 12, 10 ]` could be a pre-computed aggregate

Gram values are always of type `Subject`. In TypeScript, the pattern data structure would be defined as:
```ts
interface Pattern<V> {
  value: V;
  elements: Pattern<V>[];
}
```

A gram pattern is always of type: `Pattern<Subject>`.

## `gram` -- special pattern syntax for the top-level file context

The outermost pattern has no delimiters; it is the entire contents of the file. 
The value is provided by an optional curly-braced property record, and the
elements are the whitespace 

Syntax: `[ root_record | annotated_pattern_sequence ]`

Where:
- `root_record` is a `record` which may appear only once at the top of a file
- `annotated_pattern_sequence` is a whitespace-separated sequence of `annotated_pattern`

## `annotated_pattern` -- a top-level pattern element

An annotated pattern

Pattern: `annotated_pattern = [ annotation | pattern_sequence ]`

Where:
- `annotation` is syntactic sugar for defining a record
- `pattern_sequence` is a comma-separated sequence of pattern elements

## `subject_pattern` -- bracket notation pattern

A subject pattern uses bracket notation `[ subject | subject_pattern_elements ]`

Where:
- `subject` is optional content (identifier, labels, record)
- `subject_pattern_elements` is a comma-separated sequence of pattern elements (subject_pattern, path_pattern, or pattern_reference)

