# Development

## Install `tree-sitter` CLI

Follow [tree-sitter installation](https://tree-sitter.github.io/tree-sitter/creating-parsers#installation) instructions

## Build testable grammar

```
npx tree-sitter generate
```

## Test

```
npx tree-sitter test
```

Run tests matching a specific filter:
```
npx tree-sitter test -f 'Node'
```

# Publish

## Local Python

```
python -m pip install .
```

## Release to npm, pypi

1. Bump all build files to matching version (global search & replace)
  - `tree-sitter version 1.2.3`
  - `npm run zed:publish`
2. Commit changes
  - `git commit -am "Release 1.2.3" `
3. Tag with new version using 
  - `git tag -a <version> -m "<description>"`
4. Push the tags to trigger deployment
  - `git push --follow-tags`
