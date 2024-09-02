# Gram - a lightweight, flexible graph notation

Gram describes the structure and content of graphs, without semantics. 

A graph is composed from a sequence of patterns, where each pattern
is a sequence of graph elements.

## Graph elements - nodes

The smallest graph pattern is an empty node. 
```
()
```

Nodes may include properties using classic curly-braces-styled notation. This expression
is like an anonymous object that appears inside some other data structure, perhaps a list
like `const people = [{name:ABK}]`:

```
({name:"ABK"})
```

Nodes may self-identify themselves. This is like an object that is aware of the variable
name you've given it in a programming language -- `const abk = {name:"ABK"}`
```
(abk {name:"ABK"})
```

Or, the identity could be considered the representative value of the node as in these examples:
```
(1), (true), (`heir to the Iron Throne`)
```

Nodes may also provide labels to associate with other nodes. This is like having an 
introspectable object in a programming language -- `const abk:Person = {name:"ABK"}`:
```
(abk:Person {name:"ABK"}), (michael:Person {name:"Michael"})
```

It's ok to use multiple labels, which could be subsets, singletons, or intersections:
```
(abk:Person:Author {name:"ABK"}), (one:Person:King:Fictional {name: "John Snow"}),
(drogon:Dragon:Fictional {name:"Drogon"})
```


## Development

### Build

```
npm run prebuildify
```

```
npm run build
```


### Test

```
npx tree-sitter test
```

Run tests matching a specific filter:
```
npx tree-sitter test -f 'Node'
```