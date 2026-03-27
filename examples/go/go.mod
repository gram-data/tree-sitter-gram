module github.com/tree-sitter/tree-sitter-gram/examples/go

go 1.23

require (
	github.com/tree-sitter/go-tree-sitter v0.25.0
	github.com/tree-sitter/tree-sitter-gram v0.3.5
)

require github.com/mattn/go-pointer v0.0.1 // indirect

replace github.com/tree-sitter/tree-sitter-gram => ../..
