import sys

import tree_sitter, tree_sitter_gram

from tree_sitter import Language, Parser

GRAM_LANGUAGE = Language(tree_sitter_gram.language())
