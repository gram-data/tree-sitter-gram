# Writing Gram Files: A Practical Guide

Gram is a compact, readable notation for expressing graphs — nodes, relationships, and
structure — as plain text. This guide walks through gram by building a real example:
a social network inside a small technology company called **Strata Labs**.

By the end you'll have written nodes, relationships, annotations, nested patterns, and
subgraphs, and you'll understand why gram is structured the way it is.

The formal reference is in `gram-notation-reference.md`. This guide is just about getting
things done.

---

## Step 1: Create Some People

Every graph starts with nodes. In gram, a node is written with parentheses:

```gram
(alice)
(bob)
(carol)
```

That's valid gram, but it's not very useful — three anonymous blobs with no information
attached. Let's give them labels and properties.

A **label** classifies a node. It follows the node identity with a colon:

```gram
(alice:Person)
(bob:Person)
(carol:Person)
```

A **record** holds attributes as key-value pairs in curly braces:

```gram
(alice:Person {name: "Alice Hoffman", title: "Staff Engineer"})
(bob:Person   {name: "Bob Okafor",    title: "Product Manager"})
(carol:Person {name: "Carol Reyes",   title: "Engineering Manager"})
```

Labels are good for *what kind of thing* a node is. Records are good for *what we know
about it*. A node can have multiple labels — `(alice:Person:Employee)` — and any number
of properties.

Let's add a few more people and put the whole thing in a file with a document header.
The header is an optional record at the very top of the file that describes the file
itself, not the graph:

```gram
{ kind: "social-network", org: "Strata Labs" }

(alice:Person {name: "Alice Hoffman",   title: "Staff Engineer"})
(bob:Person   {name: "Bob Okafor",      title: "Product Manager"})
(carol:Person {name: "Carol Reyes",     title: "Engineering Manager"})
(dan:Person   {name: "Dan Whitfield",   title: "Senior Engineer"})
(erin:Person  {name: "Erin Matsuda",    title: "CEO"})
(frank:Person {name: "Frank Delacroix", title: "VP Engineering"})
```

We now have six people at Strata Labs. The document header tells any tool reading this
file what it's looking at, without being part of the graph itself.

---

## Step 2: Relate the People

Nodes alone are a list. Relationships make it a graph.

In gram, a relationship uses arrow syntax between two nodes:

```gram
(alice)-[:KNOWS]->(bob)
```

The label inside `[:]` describes the *kind* of relationship. The arrow direction indicates
who the relationship runs from and to. We can also give a relationship an identity, just
like a node — useful when we want to reference it later:

```gram
(alice)-[r1:KNOWS]->(bob)
```

Let's build out three kinds of relationships for Strata Labs: reporting lines,
collaboration, and family.

### Reporting Relationships

```gram
(alice)-[r1:REPORTS_TO]->(carol)
(dan)-[r2:REPORTS_TO]->(carol)
(carol)-[r3:REPORTS_TO]->(frank)
(frank)-[r4:REPORTS_TO]->(erin)
```

### Cross-Org Collaboration

Alice and Bob work together on a product initiative even though they're in different parts
of the org. Relationships can carry properties too:

```gram
(alice)-[c1:COLLABORATES_WITH {project: "Atlas", since: 2023}]->(bob)
(bob)-[c2:COLLABORATES_WITH   {project: "Atlas", since: 2023}]->(dan)
```

### Family

It turns out Erin and Frank are siblings — a connection that exists entirely outside the
org chart:

```gram
(erin)-[:SIBLING_OF]->(frank)
```

Gram doesn't distinguish between "organizational" and "personal" relationship types —
that's just a labeling convention. The graph holds whatever relationships you give it.

### The File So Far

```gram
{ kind: "social-network", org: "Strata Labs" }

// People
(alice:Person {name: "Alice Hoffman",   title: "Staff Engineer"})
(bob:Person   {name: "Bob Okafor",      title: "Product Manager"})
(carol:Person {name: "Carol Reyes",     title: "Engineering Manager"})
(dan:Person   {name: "Dan Whitfield",   title: "Senior Engineer"})
(erin:Person  {name: "Erin Matsuda",    title: "CEO"})
(frank:Person {name: "Frank Delacroix", title: "VP Engineering"})

// Reporting lines
(alice)-[r1:REPORTS_TO]->(carol)
(dan)-[r2:REPORTS_TO]->(carol)
(carol)-[r3:REPORTS_TO]->(frank)
(frank)-[r4:REPORTS_TO]->(erin)

// Cross-org collaboration
(alice)-[c1:COLLABORATES_WITH {project: "Atlas", since: 2023}]->(bob)
(bob)-[c2:COLLABORATES_WITH   {project: "Atlas", since: 2023}]->(dan)

// Family
(erin)-[:SIBLING_OF]->(frank)
```

---

## Step 3: Visualize the Network — Then Record It

Suppose you run this file through a graph visualization tool. It lays out the six nodes,
draws the edges, and produces a nice diagram. Now you want to *save* that layout — the
position and color of each node — back into the gram file so the diagram is reproducible.

This is what **annotations** are for. An annotation attaches metadata to a node (or any
pattern) without changing the node's own identity, labels, or properties.

An annotation is written with `@` before the node. Each annotation takes a single value
in parentheses — which can be any gram value type, including a map `{k: v}` for structured
metadata:

```gram
@pos({x: 120, y: 340}) @color("#4A90D9") @size(48)
  (alice:Person {name: "Alice Hoffman", title: "Staff Engineer"})
```

Multiple annotations chain left to right, all applying to the same node. Each `@key(value)`
pair becomes a property on the annotation wrapper. The node itself is unchanged —
annotations live *outside* the node, wrapping it.

Let's annotate the whole cast:

```gram
@pos({x: 120, y: 200}) @color("#4A90D9") (alice:Person {name: "Alice Hoffman",   title: "Staff Engineer"})
@pos({x: 340, y: 200}) @color("#E8A838") (bob:Person   {name: "Bob Okafor",      title: "Product Manager"})
@pos({x: 230, y: 100}) @color("#4A90D9") (carol:Person {name: "Carol Reyes",     title: "Engineering Manager"})
@pos({x: 340, y: 300}) @color("#4A90D9") (dan:Person   {name: "Dan Whitfield",   title: "Senior Engineer"})
@pos({x: 230, y:  20}) @color("#B06020") (erin:Person  {name: "Erin Matsuda",    title: "CEO"})
@pos({x: 120, y: 100}) @color("#B06020") (frank:Person {name: "Frank Delacroix", title: "VP Engineering"})
```

The colors loosely encode team: blue for Engineering, amber for Product, brown for
Leadership. This is just a convention in the data — gram doesn't enforce it.

---

## Step 4: Annotating Relationships — Pattern Notation

Now we want to record layout metadata on the relationships too — perhaps edge curvature
and label position for the visualization.

We could reach for `@` annotation syntax here, but stacking property annotations on a
relationship reference gets hard to read quickly. Instead, gram offers a cleaner approach
for attaching a record of metadata to any element: **square-bracket pattern notation**
with a record as the subject and the element as the single child.

The form is `[{key: value, ...} | element]` — a pattern whose subject is a record of
metadata and whose single element is the thing being annotated:

```gram
[{curve: 0.2, labelPos: 0.6} | (alice)-[r1:REPORTS_TO]->(carol)]
```

Or, since `r1` was already defined, we can reference it by identity:

```gram
[{curve: 0.2, labelPos: 0.6} | r1]
```

Both forms produce the same structure: a wrapper pattern carrying the layout metadata,
with the relationship as its single element. Let's annotate all the reporting lines:

```gram
[{curve: 0.2} | r1]
[{curve: 0.2} | r2]
[{curve: 0.1} | r3]
[{curve: 0.1} | r4]
```

---

## Step 5: Pattern Notation — the General Form

In step 4 we used square brackets to wrap a relationship with metadata. This is
**pattern notation** — gram's general-purpose syntax for building patterns explicitly.

Path notation (parentheses and arrows) is convenient shorthand for the most common case.
Pattern notation is the underlying form that path notation expands into. The two are
fully equivalent:

```gram
(alice)-[r1:REPORTS_TO]->(carol)   // path notation
[r1:REPORTS_TO | alice, carol]     // pattern notation — identical result
```

The `|` separates the pattern's own subject (identity, labels, properties) from its
**elements** — the patterns it contains. Direction in path notation maps to element
*order* in pattern notation: left-to-right arrow means the source comes first.

```gram
(a)-[r]->(b)    →    [r | a, b]    // a is first element
(a)<-[r]-(b)   →    [r | b, a]    // b is first element (arrow reversed)
```

Nodes have equivalent forms too:

```gram
(alice:Person {name: "Alice Hoffman"})   // path notation
[alice:Person {name: "Alice Hoffman"}]   // pattern notation — identical result
```

You can mix both styles freely in a single gram file. Path notation is natural for
expressing connections; pattern notation is useful when you need to name, group, or
wrap specific elements.

---

## Step 6: Arity — How Many Elements Can a Pattern Have?

So far we've seen patterns with:

- **0 elements** — a node: `(alice)` or `[alice]`
- **1 element** — a metadata wrapper: `[{curve: 0.2} | r1]` contains `r1` as its
  single element
- **2 elements** — a relationship: `[r1:REPORTS_TO | alice, carol]`

Can a pattern have more than two elements? Yes. Pattern notation takes any number of
comma-separated elements after the `|`:

```gram
[group | alice, bob, carol]
```

This is a pattern named `group` with three elements. It doesn't assert any particular
relationship between them — it just groups them. What that grouping *means* is up to the
application reading the file.

| Elements | Conventional role |
|---|---|
| 0 | Node / atomic value |
| 1 | Metadata wrapper |
| 2 | Relationship (directed or undirected) |
| 3+ | Group, list, hyperedge, or subgraph |

Gram doesn't enforce these roles — they're conventions. But they're consistent conventions,
and most tools will interpret them this way.

---

## Step 7: Grouping Nodes — A Subgraph

Let's say Strata Labs has a formal team structure. Alice, Dan, and Carol form the
Engineering team. We want to express that grouping in the graph.

The simplest subgraph is just a collection of nodes:

```gram
[engineering:Team {name: "Engineering"} | alice, dan, carol]
```

This creates a pattern named `engineering` with label `Team`, a `name` property, and
three elements: the three people. The elements are **references** — `alice`, `dan`, and
`carol` were already defined as nodes earlier in the file. The team pattern doesn't
redefine them; it points to them.

Let's add the other teams:

```gram
[engineering:Team {name: "Engineering"} | alice, dan, carol]
[product:Team     {name: "Product"}     | bob]
[leadership:Team  {name: "Leadership"}  | erin, frank]
```

A team is a subgraph containing only nodes. The structure is flat — members are directly
inside the team pattern. In graph terms, this is a grouping or partition: each person
belongs to exactly one team.

---

## Step 8: Grouping Relationships — A Richer Subgraph

Now let's capture the Atlas collaboration as a named subgraph. This one involves
relationships, not just nodes — and relationships already carry their nodes inside them
as elements.

Recall the collaboration edges, already named `c1` and `c2`:

```gram
(alice)-[c1:COLLABORATES_WITH {project: "Atlas", since: 2023}]->(bob)
(bob)-[c2:COLLABORATES_WITH   {project: "Atlas", since: 2023}]->(dan)
```

We can group them by reference:

```gram
[atlas:Project {name: "Atlas"} | c1, c2]
```

The `atlas` pattern contains two relationships. Each relationship already contains its
own nodes as elements. So the subgraph `atlas` carries the entire structure — nodes
and edges — reachable through its elements.

---

## Step 9: Paths and Walks

Look at the atlas collaboration edges. They form a chain in the graph:

```gram
(alice)-[c1:COLLABORATES_WITH]->(bob)-[c2:COLLABORATES_WITH]->(dan)
```

In gram's syntax, this is a **path** — a single expression where a relationship's right
side is itself another relationship rather than a terminal node. The parse tree is
right-recursive: the right side of `c1` is the entire sub-path
`(bob)-[c2:COLLABORATES_WITH]->(dan)`.

A path with a single relationship resolves to that relationship. A path with multiple
relationships — like the one above — is an **anonymous walk**: a connected sequence
through the graph with no identity of its own.

Whether a walk is meaningful in your application — whether it represents a route, a
chain of influence, a sequence of events — is a matter of interpretation. Gram records
the structure. The meaning comes from how you and your tools read it.

The `[atlas | c1, c2]` subgraph from step 8 and the path expression above describe the
same connectivity. The subgraph gives the walk a name and makes it a first-class element
of the graph; the path expression is anonymous and ephemeral. Both are valid gram.

---

## The Complete File

```gram
{ kind: "social-network", org: "Strata Labs" }

// -------------------------------------------------------
// People
// -------------------------------------------------------

@pos({x: 120, y: 200}) @color("#4A90D9")
  (alice:Person {name: "Alice Hoffman",   title: "Staff Engineer"})

@pos({x: 340, y: 200}) @color("#E8A838")
  (bob:Person   {name: "Bob Okafor",      title: "Product Manager"})

@pos({x: 230, y: 100}) @color("#4A90D9")
  (carol:Person {name: "Carol Reyes",     title: "Engineering Manager"})

@pos({x: 340, y: 300}) @color("#4A90D9")
  (dan:Person   {name: "Dan Whitfield",   title: "Senior Engineer"})

@pos({x: 230, y:  20}) @color("#B06020")
  (erin:Person  {name: "Erin Matsuda",    title: "CEO"})

@pos({x: 120, y: 100}) @color("#B06020")
  (frank:Person {name: "Frank Delacroix", title: "VP Engineering"})

// -------------------------------------------------------
// Reporting lines
// -------------------------------------------------------

(alice)-[r1:REPORTS_TO]->(carol)
(dan)-[r2:REPORTS_TO]->(carol)
(carol)-[r3:REPORTS_TO]->(frank)
(frank)-[r4:REPORTS_TO]->(erin)

[{curve: 0.2} | r1]
[{curve: 0.2} | r2]
[{curve: 0.1} | r3]
[{curve: 0.1} | r4]

// -------------------------------------------------------
// Cross-org collaboration
// -------------------------------------------------------

(alice)-[c1:COLLABORATES_WITH {project: "Atlas", since: 2023}]->(bob)
(bob)-[c2:COLLABORATES_WITH   {project: "Atlas", since: 2023}]->(dan)

// -------------------------------------------------------
// Family
// -------------------------------------------------------

(erin)-[:SIBLING_OF]->(frank)

// -------------------------------------------------------
// Teams (node subgraphs)
// -------------------------------------------------------

[engineering:Team {name: "Engineering"} | alice, dan, carol]
[product:Team     {name: "Product"}     | bob]
[leadership:Team  {name: "Leadership"}  | erin, frank]

// -------------------------------------------------------
// Projects (relationship subgraphs)
// -------------------------------------------------------

[atlas:Project {name: "Atlas"} | c1, c2]
```

---

## Bonus: The Research Paper Reading Club

Not everything at Strata Labs is on the org chart. Alice, Dan, and Bob run an informal
reading group. It crosses team boundaries and has no formal reporting structure — just
three people who meet every other Friday.

```gram
[reading-club:SocialGroup {
  name:  "Research Paper Reading Club",
  meets: "biweekly",
  day:   "Friday"
} | alice, dan, bob]
```

This is exactly the same structure as a team subgraph — a named pattern grouping nodes.
The label `SocialGroup` distinguishes it from `Team`. The properties describe the group.
The elements are the members.

Gram makes no distinction between a formal organizational structure and an informal social
one. Both are just patterns with elements. The labels and properties carry the meaning;
the structure is the same.

---

## What Gram Doesn't Say

A gram file records *structure and data*. It deliberately does not specify:

- Whether the graph is directed, undirected, or mixed (your labels and arrow choices do that)
- What operations are valid on the graph (that's your query layer)
- Whether a walk is valid or connected (that's your analysis layer)
- What the styling annotations *mean* to any particular renderer (that's your tool)

This separation is intentional. Gram is a portable substrate. The same file can be
loaded into a graph database, rendered by a visualization tool, analyzed by a path
algorithm, or diffed against another version — each layer brings its own interpretation.

---

## Quick Reference

| What you want | How to write it |
|---|---|
| A node | `(alice:Person {name: "Alice"})` |
| A relationship | `(alice)-[:KNOWS]->(bob)` |
| A named relationship | `(alice)-[r:KNOWS]->(bob)` |
| Annotate a node | `@color("#4A90D9") (alice:Person {...})` |
| Annotate a relationship | `[{curve: 0.3} \| r]` or `[{curve: 0.3} \| (alice)-[r:KNOWS]->(bob)]` |
| A group of nodes | `[team:Team \| alice, bob, carol]` |
| A group of relationships | `[project:Project \| r1, r2]` |
| A multi-hop path | `(alice)-[:KNOWS]->(bob)-[:KNOWS]->(carol)` |
| A document header | `{ kind: "social-network" }` (first line) |
| A comment | `// this is a comment` |

---

## Next Steps

- `gram-notation-reference.md` — complete syntax and semantic reference
- `gram.ebnf` — formal grammar
