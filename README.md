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


## FAQ

- Annotation vs self-loop?

  Q: What is the difference between an annotation and a self-loop? 
  A: An annotation provides extra information about a single target, while a self-loop provides 
  information about a source,target pair where either the source or target may have been different,
  but happen to be the same. 

  For example, `@physics("rigid")(a:Player)` annotates a player entity with information for the physics subsystem.
  The information is particular to the player and not about how the player relates to itself. 

  As a self-loop, `(a:Player)-[:MESSAGE]->(a:Player)` is a message a player sent to themselves that could've
  been sent to another player. The message has a specific source and target, which happen to be the same.

