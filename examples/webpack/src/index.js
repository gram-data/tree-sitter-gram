const Parser = require('web-tree-sitter');
Parser.init().then(() => { 
  console.log('Parser initialized');
});