package tree_sitter_gram_test

import (
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_gram "github.com/tree-sitter/tree-sitter-gram/bindings/go"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_gram.Language())
	if language == nil {
		t.Errorf("Error loading Gram grammar")
	}
}
