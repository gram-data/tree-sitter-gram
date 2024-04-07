const Parser = require('tree-sitter');
const GramLang = require('tree-sitter-gram');

const parser = new Parser();
parser.setLanguage(GramLang);

const gramCode = `(hello)
(hello)-->(world)
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

console.log(reduce(cst.rootNode, pretty, ""));


// console.log("---");
// console.log("nodes: " + nodes.length);
// console.log("relationships: " + relationships.length);
// console.log("identifiers: " + Array.from(identifiers).join(", "));
// console.log("labels: " + Array.from(labels).join(", "));