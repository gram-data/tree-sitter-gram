const Parser = require('tree-sitter');
const GramLang = require('tree-sitter-gram');

const parser = new Parser();
parser.setLanguage(GramLang);

const gramCode = `(hello)
(hello)-->(world)
(hello:Greeting)-[dear:ADJECTIVE]->(world:Subject)
`;
const cst = parser.parse(gramCode);

const nodes = [];
const relationships = [];
const identifiers = new Set();
const labels = new Set();

console.log(cst.rootNode.toString());

const reduce = (cst, f, acc) => {
  const result = (cst.children !== null && cst.children.length > 0) ?
  cst.children.reduce((acc, child) => reduce(child, f, acc), acc) : acc; 

  return f(cst, result);

}

const match = (cst, onMatchGram, onMatchPattern, onMatchNode, onMatchRelationship, onMatchRelationshipValue, otherwise) => {
  switch (cst.type) {
    case "gram":
      return onMatchGram(cst);
    case "pattern":
      return onMatchPattern(cst);
    case "path":
      return onMatchPath(cst);
    case "node":
      return onMatchNode(cst);
    case "relationship":
      return onMatchRelationship(cst);
    case "single_arrow_right":
    case "double_arrow_right":
    case "squiggle_arrow_right":
    case "single_arrow_left":
    case "double_arrow_left":
    case "squiggle_arrow_left":
      return onMatchRelationshipValue(cst);
    default:
      return otherwise(cst);
  }
}

const pretty = (cst, acc) => {
  return match(cst, 
    (gram) => "gram...\n  " + acc, 
    (pattern) => acc + "\n  ",
    (node) => acc + " (node) ",
    (relationship) => acc,
    (rel_value) => acc + "-->", 
    (cst) => acc
  );
}


console.log(reduce(cst.rootNode, pretty, ""));


const collectAttributes = (cst, acc) => {
  console.log(cst.fields);
  if (cst.identifierNode !== null) acc.identifiers.add(cst.identifierNode.text);
  if (cst.labelsNode !== null) acc.labels.add(cst.labelsNode.text);
  return acc;
}

const collectStats = (cst, acc) => {
  return match(cst,
    (gram) => acc,
    (pattern) => acc,
    (node) => { 
      acc.nodes += 1; 
      collectAttributes(node, acc);
      return acc 
    },
    (relationship) => {acc.relationships += 1; return acc },
    (rel_value) => collectAttributes(rel_value, acc),
    (otherwise) => acc
  )
}

const stats = reduce(cst.rootNode, collectStats, 
  {
    nodes:0, 
    relationships:0,
    labels: new Set(),
    identifiers: new Set()
  }
)

console.log("---");
console.dir(stats);

