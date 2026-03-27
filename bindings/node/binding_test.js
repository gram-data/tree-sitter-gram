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

  // Find the symbol 'a' in the pattern
  function findSymbol(node, text) {
    if (node.isNamed && node.type === "symbol" && node.text === text) {
      return node;
    }
    for (let i = 0; i < node.childCount; i++) {
      const result = findSymbol(node.child(i), text);
      if (result) return result;
    }
    return null;
  }

  const symbol = findSymbol(pattern, "a");
  assert(symbol, "pattern should contain symbol 'a'");
  assert.strictEqual(symbol.type, "symbol");
});
