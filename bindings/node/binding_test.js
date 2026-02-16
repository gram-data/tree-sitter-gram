/// <reference types="node" />

const assert = require("node:assert");
const { test } = require("node:test");

test("can load grammar", () => {
  const parser = new (require("tree-sitter"))();
  assert.doesNotThrow(() => parser.setLanguage(require(".")));
});

test("annotation node kinds: identified_annotation and property_annotation", () => {
  const Parser = require("tree-sitter");
  const GramLang = require(".");
  const parser = new Parser();
  parser.setLanguage(GramLang);

  const annotated = (root) => root.child(0) ?? null;

  const withIdentified = parser.parse("@@p (a)");
  const ap1 = annotated(withIdentified.rootNode);
  assert(ap1?.type === "annotated_pattern", "root should have annotated_pattern child");
  const annotations1 = ap1.childForFieldName("annotations");
  assert(annotations1, "annotations node should exist");
  const first1 = annotations1.child(0);
  assert.strictEqual(first1?.type, "identified_annotation", "@@ form should be identified_annotation");
  assert(first1?.childForFieldName("identifier"), "identified_annotation should have identifier field");

  const withProperty = parser.parse("@x(1) ()");
  const ap2 = annotated(withProperty.rootNode);
  assert(ap2?.type === "annotated_pattern", "root should have annotated_pattern child");
  const annotations2 = ap2.childForFieldName("annotations");
  assert(annotations2, "annotations node should exist");
  const first2 = annotations2.child(0);
  assert.strictEqual(first2?.type, "property_annotation", "@ form should be property_annotation");
  assert(first2?.childForFieldName("key"), "property_annotation should have key field");
  assert(first2?.childForFieldName("value"), "property_annotation should have value field");
});
