# Development

## Install `tree-sitter` CLI

Follow [tree-sitter installation](https://tree-sitter.github.io/tree-sitter/creating-parsers#installation) instructions

## Build testable grammar

```
npm run prebuildify
```

```
npm run build
```


## Test

```
npx tree-sitter test
```

Run tests matching a specific filter:
```
npx tree-sitter test -f 'Node'
```