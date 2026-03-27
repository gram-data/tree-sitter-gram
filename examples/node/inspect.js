const Parser = require("tree-sitter");
const GramLang = require("tree-sitter-gram");

const parser = new Parser();
parser.setLanguage(GramLang);

const gramCode = `(hello:Greeting {text: "hi"})-[:TO]->(world:Place {name: "Earth"})
(alice:Person)-[:KNOWS]->(bob:Person)`;

const tree = parser.parse(gramCode);

console.log("Parse tree:");
console.log(tree.rootNode.toString());
console.log();

function walk(node, source, stats) {
  switch (node.type) {
    case "node":
      stats.nodes.push(source.slice(node.startIndex, node.endIndex));
      break;
    case "relationship":
      stats.relationships.push(source.slice(node.startIndex, node.endIndex));
      break;
  }
  for (let i = 0; i < node.childCount; i++) {
    walk(node.child(i), source, stats);
  }
}

const stats = { nodes: [], relationships: [] };
walk(tree.rootNode, gramCode, stats);

for (const n of stats.nodes) {
  console.log("  node:", n);
}
for (const r of stats.relationships) {
  console.log("  relationship:", r);
}

console.log(`\nSummary: ${stats.nodes.length} nodes, ${stats.relationships.length} relationships`);
