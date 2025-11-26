# Repository Guidelines

## Project Structure & Module Organization
- `grammar.js` is the authoritative grammar and regenerates `src/parser.c` through the Tree-sitter CLI.
- `src/` holds the generated C parser; do not edit by hand.
- `bindings/` hosts language adapters (`node`, `rust`, `python`, `go`, `swift`, `c`) referenced by their package manifests.
- `test/corpus/` stores fixture-based grammar tests; keep additions minimal and descriptive.
- `examples/` captures gram notation patterns; update it when syntax changes.
- `dist/` and `prebuilds/` carry published artifacts and should only change during releases.

## Build, Test, and Development Commands
- `npx tree-sitter generate` refreshes parser sources after grammar edits.
- `npx tree-sitter test` runs the corpus suite; add `-f "<name>"` to focus on one fixture.
- `npm test` executes Node bindings (`bindings/node/*_test.js`) with the Node test runner.
- `npm start` opens the Tree-sitter playground (CLI required) for interactive checks.
- `make all` builds C archives and shared libraries; `make test` proxies to Tree-sitter tests.
- `python -m pip install .` or `cargo build --release` spot-check Python and Rust packaging.

## Coding Style & Naming Conventions
- Follow `.editorconfig`: 2-space JS/JSON/TOML, 4-space C/Rust/Python/Swift, tabs for Go and Makefiles.
- Grammar rule names stay lowerCamelCase and align with Gram terminology (`bracket`, `subject`, `relationship`, etc.).
- Name corpus files descriptively with underscores (`test/corpus/number_values.txt`) and keep UTF-8 LF endings.
- Run `npx eslint bindings/node` before submitting Node binding changes.

## Testing Guidelines
- Extend corpus files with paired “source ===> tree” sections that capture minimal reproductions.
- Mirror new node types in both positive and negative samples; keep regressions near related fixtures.
- For bindings, add unit tests beside the implementation and gate platform-specific logic with capability checks.
- Ensure `npx tree-sitter test`, `npm test`, and relevant language builds pass before review.

## Commit & Pull Request Guidelines
- Commits stay short and present-tense (`add named fields`, `bump tree-sitter 0.24.6`) and group grammar, generated code, and bindings together.
- Pull requests should summarize parser changes, list new or altered fixtures, and link issues or release goals when relevant.
- Include CLI output snippets for key commands and flag follow-up tasks (e.g., regenerating prebuilds).
- Request reviews from maintainers over any binding you modify, and update release notes for behavior changes.
