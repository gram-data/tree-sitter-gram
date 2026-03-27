package main

import (
	"fmt"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_gram "github.com/tree-sitter/tree-sitter-gram/bindings/go"
)

func main() {
	parser := tree_sitter.NewParser()
	parser.SetLanguage(tree_sitter.NewLanguage(tree_sitter_gram.Language()))

	sourceCode := []byte(`(hello:Greeting {text: "hi"})-[:TO]->(world:Place)`)
	tree := parser.Parse(sourceCode, nil)

	fmt.Println("Parse tree:")
	fmt.Println(tree.RootNode().ToSexp())

	nodes := 0
	relationships := 0
	var walk func(*tree_sitter.Node)
	walk = func(node *tree_sitter.Node) {
		switch node.Kind() {
		case "node_pattern":
			nodes++
			fmt.Printf("  node: %s\n", node.Utf8Text(sourceCode))
		case "relationship_pattern":
			relationships++
			fmt.Printf("  relationship: %s\n", node.Utf8Text(sourceCode))
		}
		for i := uint(0); i < node.ChildCount(); i++ {
			walk(node.Child(i))
		}
	}
	walk(tree.RootNode())

	fmt.Printf("\nSummary: %d nodes, %d relationships\n", nodes, relationships)
}
