<!-- SPECKIT START -->
For additional context about technologies to be used, project structure,
shell commands, and other important information, read the current plan
at specs/007-unified-gram-cli/plan.md
<!-- SPECKIT END -->

## Active Technologies
- Rust, edition 2021, workspace version 0.3.6 + clap 4.5 (derive), tree-sitter 0.25, tree-sitter-gram (workspace local), serde + serde_json 1.x, reqwest 0.12 (extension downloads), directories 5.x (platform-aware `~/.gram/bin`), walkdir 2.x (directory traversal), toml 0.8 (extension registry parsing) (007-unified-gram-cli)
- `~/.gram/bin/` for installed extension binaries; extension registry is a static TOML file fetched from GitHub (007-unified-gram-cli)

## Recent Changes
- 007-unified-gram-cli: Added Rust, edition 2021, workspace version 0.3.6 + clap 4.5 (derive), tree-sitter 0.25, tree-sitter-gram (workspace local), serde + serde_json 1.x, reqwest 0.12 (extension downloads), directories 5.x (platform-aware `~/.gram/bin`), walkdir 2.x (directory traversal), toml 0.8 (extension registry parsing)
