import tree_sitter_gram as tsgram
# import tree_sitter_python as tspython
from tree_sitter import Language, Parser

# show the tsgram
print(dir(tsgram))

GRAM_LANGUAGE = Language(tsgram.language(), "gram")
# PYTHON_LANGUAGE = Language(tspython.language(), "python")
