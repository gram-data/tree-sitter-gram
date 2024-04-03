package main

import (
	"context"
	"fmt"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/javascript"
	"github.com/gram-data/tree-sitter-gram/tree_sitter_gram"

)

func main() {
	
	parser := sitter.NewParser()
	parser.SetLanguage(javascript.GetLanguage())
	
	sourceCode := []byte("let a = 1")
	tree, _ := parser.ParseCtx(context.Background(), nil, sourceCode)
	
	n := tree.RootNode()
	
	fmt.Println(n) // (program (lexical_declaration (variable_declarator (identifier) (number))))
	
	child := n.NamedChild(0)
	fmt.Println(child.Type()) // lexical_declaration
	fmt.Println(child.StartByte()) // 0
	fmt.Println(child.EndByte()) // 9
}