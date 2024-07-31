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
is equivalent to an anoynmous object:

```
({name:"ABK"})
```

Nodes may self-identify themselves. This is like an object that is aware of the variable
name you've given it in a programming language -- `const abk = {name:"ABK"}`
```
(abk {name:"ABK"})
```

Nodes may also provide labels to associate sets of nodes. This is like having an 
introspectable object in a programming language -- `const abk:Person = {name:"ABK"}`:
```
(abk:Person {name:"ABK"}), (michael:Person {name:"Michael"})
```

It's ok to add multiple labels, which could be subsets, or cross:
```
(abk:Person:Author:Fictional {name:"ABK"})
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