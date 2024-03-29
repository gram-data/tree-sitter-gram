package tree_sitter_pop_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-kgram"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_pop.Language())
	if language == nil {
		t.Errorf("Error loading Pop grammar")
	}
}
