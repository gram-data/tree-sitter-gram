import tree_sitter, tree_sitter_gram

GRAM_LANGUAGE = tree_sitter.Language(tree_sitter_gram.language())
parser = tree_sitter.Parser(GRAM_LANGUAGE)

gram_code = b"(hello:Greeting {text: 'hi'})-[:TO]->(world:Place)"
tree = parser.parse(gram_code)

print("Parse tree:")
print(tree.root_node)
print()

nodes = []
relationships = []

def walk(node):
    if node.type == "node_pattern":
        nodes.append(node.text.decode())
    elif node.type == "relationship_pattern":
        relationships.append(node.text.decode())
    for child in node.children:
        walk(child)

walk(tree.root_node)

for n in nodes:
    print(f"  node: {n}")
for r in relationships:
    print(f"  relationship: {r}")

print(f"\nSummary: {len(nodes)} nodes, {len(relationships)} relationships")
