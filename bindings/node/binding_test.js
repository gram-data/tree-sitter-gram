/// <reference types="node" />

const assert = require("node:assert");
const { test } = require("node:test");

test("can load grammar", () => {
  const parser = new (require("tree-sitter"))();
  assert.doesNotThrow(() => parser.setLanguage(require(".")));
});

test("parses a simple node pattern", () => {
  const Parser = require("tree-sitter");
  const GramLang = require(".");
  const parser = new Parser();
  parser.setLanguage(GramLang);

  const tree = parser.parse("(a)");
  const pattern = tree.rootNode.child(0);
  assert(pattern, "root should have a pattern child");
  assert.strictEqual(pattern.type, "pattern");
  const node = pattern.child(0);
  assert(node, "pattern should contain a node child");
  assert.strictEqual(node.type, "node");
  assert(node.childForFieldName("identifier"), "node should have an identifier field");
});
