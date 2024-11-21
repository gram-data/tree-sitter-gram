# tree-sitter-gram

A [tree-sitter](https://tree-sitter.github.io/tree-sitter/) grammar 
for [gram](https://gram-data.github.io) notation.

Gram is a subject-based notation for structured data.

If this is an object:
```
{
  "name":"Andreas",
  "roles":["author"]
}
```

Implicitly the object is a person. To become a subject, the implicit
information can be explicit.

As a subject:
```
(:Person {
  name: "Andreas",
  roles: ["author"]
})
```

Learn more about `gram` at the [gram-data github org](https://github.com/gram-data) notation.