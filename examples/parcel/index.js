
const Parser = require('web-tree-sitter');

Parser.init().then(async () => {
  console.log("Tree-sitter initialized");
});

// async function loadLang() {
//   console.log("loading parser...")
//   const parser = new Parser();

//   const GramLang = await Parser.Language.load('./tree-sitter-gram.wasm');
//   // parser.setLanguage(GramLang);
  
//   // console.log(GramLang);
  
//   console.log("done?")
// }

// loadLang();
