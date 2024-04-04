const Parser = require('tree-sitter');
const GramLang = require('tree-sitter-gram');

const parser = new Parser();
parser.setLanguage(GramLang);

const gramCode = `(hello)
(hello),(goodbye)
(hello)-->(world)
(hello:Greeting)~~>(world:Subject:General)
(:Greeting)==>(:Subject)
`;
const cst = parser.parse(gramCode);

const nodes = [];
const relationships = [];
const identifiers = new Set();
const labels = new Set();

console.log(cst.rootNode.toString());

//the root node is a gram, containing a sequence of patterns as children
for (const pattern of cst.rootNode.children) {
  for (const part of pattern.children) {
    if (part.type === "part") {
      for (const element of part.children) {
        switch (element.type) {
          case "node":
            nodes.push(element);
            // console.log("node: " + element);
            attributes = element.children[1];// skip first child, which is a "("
            if (attributes.identifierNode !== null) {
              identifiers.add(attributes.identifierNode.text); 
            }
            if (attributes.labelsNode !== null) {
              const labelsNode = attributes.labelsNode;
              // console.log("labels: " + labelsNode);
              for (const label of labelsNode.children) {
                if (label.text !== ":") { // skip over separator chars
                  labels.add(label.text);
                }
              }
            }
            break;
          case "single_arrow_right":
          case "double_arrow_right":
          case "squiggle_arrow_right":
          case "single_arrow_left":
          case "double_arrow_left":
          case "squiggle_arrow_left":
            relationships.push(element);
            break;
          default:
            console.log("unknown element type: " + element.type);
        }
      }
    }
  }
}

console.log("---");
console.log("nodes: " + nodes.length);
console.log("relationships: " + relationships.length);
console.log("identifiers: " + Array.from(identifiers).join(", "));
console.log("labels: " + Array.from(labels).join(", "));