#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 100
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 66
#define ALIAS_COUNT 0
#define TOKEN_COUNT 34
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 9
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 14

enum ts_symbol_identifiers {
  anon_sym_COMMA = 1,
  anon_sym_LPAREN = 2,
  anon_sym_RPAREN = 3,
  anon_sym_LBRACK = 4,
  anon_sym_RBRACK = 5,
  anon_sym_PIPE = 6,
  anon_sym_COLON = 7,
  anon_sym_LBRACE = 8,
  anon_sym_RBRACE = 9,
  anon_sym_COLON_COLON = 10,
  anon_sym_BANG = 11,
  anon_sym_QMARK = 12,
  anon_sym_STAR = 13,
  anon_sym_PLUS = 14,
  sym_symbol = 15,
  sym_integer = 16,
  sym_decimal = 17,
  sym_hexadecimal = 18,
  sym_octal = 19,
  sym_measurement = 20,
  sym_single_quoted_string = 21,
  sym_double_quoted_string = 22,
  sym_backticked_string = 23,
  sym_tagged_string = 24,
  anon_sym_DASH = 25,
  anon_sym_DASH_GT = 26,
  anon_sym_LT_DASH = 27,
  anon_sym_EQ = 28,
  anon_sym_EQ_GT = 29,
  anon_sym_LT_EQ_EQ = 30,
  anon_sym_TILDE = 31,
  anon_sym_TILDE_GT = 32,
  anon_sym_LT_TILDE = 33,
  sym_gram = 34,
  sym_pattern = 35,
  sym__path = 36,
  sym_node = 37,
  sym_relationship = 38,
  sym_series = 39,
  sym__attributes = 40,
  sym_members = 41,
  sym__member = 42,
  sym__identifier = 43,
  sym_labels = 44,
  sym_record = 45,
  sym_value_pair = 46,
  sym_type_pair = 47,
  sym__value = 48,
  sym__numeric_literal = 49,
  sym__string_literal = 50,
  sym__relationship_value = 51,
  sym_undirected_single = 52,
  sym_single_arrow_right = 53,
  sym_single_arrow_left = 54,
  sym_undirected_double_arrow = 55,
  sym_double_arrow_right = 56,
  sym_double_arrow_left = 57,
  sym_undirected_squiggle = 58,
  sym_squiggle_arrow_right = 59,
  sym_squiggle_arrow_left = 60,
  aux_sym_gram_repeat1 = 61,
  aux_sym_pattern_repeat1 = 62,
  aux_sym_members_repeat1 = 63,
  aux_sym_labels_repeat1 = 64,
  aux_sym_record_repeat1 = 65,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_COMMA] = ",",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_PIPE] = "|",
  [anon_sym_COLON] = ":",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_COLON_COLON] = "::",
  [anon_sym_BANG] = "!",
  [anon_sym_QMARK] = "\?",
  [anon_sym_STAR] = "*",
  [anon_sym_PLUS] = "+",
  [sym_symbol] = "symbol",
  [sym_integer] = "integer",
  [sym_decimal] = "decimal",
  [sym_hexadecimal] = "hexadecimal",
  [sym_octal] = "octal",
  [sym_measurement] = "measurement",
  [sym_single_quoted_string] = "single_quoted_string",
  [sym_double_quoted_string] = "double_quoted_string",
  [sym_backticked_string] = "backticked_string",
  [sym_tagged_string] = "tagged_string",
  [anon_sym_DASH] = "-",
  [anon_sym_DASH_GT] = "->",
  [anon_sym_LT_DASH] = "<-",
  [anon_sym_EQ] = "=",
  [anon_sym_EQ_GT] = "=>",
  [anon_sym_LT_EQ_EQ] = "<==",
  [anon_sym_TILDE] = "~",
  [anon_sym_TILDE_GT] = "~>",
  [anon_sym_LT_TILDE] = "<~",
  [sym_gram] = "gram",
  [sym_pattern] = "pattern",
  [sym__path] = "_path",
  [sym_node] = "node",
  [sym_relationship] = "relationship",
  [sym_series] = "series",
  [sym__attributes] = "_attributes",
  [sym_members] = "members",
  [sym__member] = "_member",
  [sym__identifier] = "_identifier",
  [sym_labels] = "labels",
  [sym_record] = "record",
  [sym_value_pair] = "value_pair",
  [sym_type_pair] = "type_pair",
  [sym__value] = "_value",
  [sym__numeric_literal] = "_numeric_literal",
  [sym__string_literal] = "_string_literal",
  [sym__relationship_value] = "_relationship_value",
  [sym_undirected_single] = "undirected_single",
  [sym_single_arrow_right] = "single_arrow_right",
  [sym_single_arrow_left] = "single_arrow_left",
  [sym_undirected_double_arrow] = "undirected_double_arrow",
  [sym_double_arrow_right] = "double_arrow_right",
  [sym_double_arrow_left] = "double_arrow_left",
  [sym_undirected_squiggle] = "undirected_squiggle",
  [sym_squiggle_arrow_right] = "squiggle_arrow_right",
  [sym_squiggle_arrow_left] = "squiggle_arrow_left",
  [aux_sym_gram_repeat1] = "gram_repeat1",
  [aux_sym_pattern_repeat1] = "pattern_repeat1",
  [aux_sym_members_repeat1] = "members_repeat1",
  [aux_sym_labels_repeat1] = "labels_repeat1",
  [aux_sym_record_repeat1] = "record_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_COLON_COLON] = anon_sym_COLON_COLON,
  [anon_sym_BANG] = anon_sym_BANG,
  [anon_sym_QMARK] = anon_sym_QMARK,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [sym_symbol] = sym_symbol,
  [sym_integer] = sym_integer,
  [sym_decimal] = sym_decimal,
  [sym_hexadecimal] = sym_hexadecimal,
  [sym_octal] = sym_octal,
  [sym_measurement] = sym_measurement,
  [sym_single_quoted_string] = sym_single_quoted_string,
  [sym_double_quoted_string] = sym_double_quoted_string,
  [sym_backticked_string] = sym_backticked_string,
  [sym_tagged_string] = sym_tagged_string,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [anon_sym_LT_DASH] = anon_sym_LT_DASH,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_EQ_GT] = anon_sym_EQ_GT,
  [anon_sym_LT_EQ_EQ] = anon_sym_LT_EQ_EQ,
  [anon_sym_TILDE] = anon_sym_TILDE,
  [anon_sym_TILDE_GT] = anon_sym_TILDE_GT,
  [anon_sym_LT_TILDE] = anon_sym_LT_TILDE,
  [sym_gram] = sym_gram,
  [sym_pattern] = sym_pattern,
  [sym__path] = sym__path,
  [sym_node] = sym_node,
  [sym_relationship] = sym_relationship,
  [sym_series] = sym_series,
  [sym__attributes] = sym__attributes,
  [sym_members] = sym_members,
  [sym__member] = sym__member,
  [sym__identifier] = sym__identifier,
  [sym_labels] = sym_labels,
  [sym_record] = sym_record,
  [sym_value_pair] = sym_value_pair,
  [sym_type_pair] = sym_type_pair,
  [sym__value] = sym__value,
  [sym__numeric_literal] = sym__numeric_literal,
  [sym__string_literal] = sym__string_literal,
  [sym__relationship_value] = sym__relationship_value,
  [sym_undirected_single] = sym_undirected_single,
  [sym_single_arrow_right] = sym_single_arrow_right,
  [sym_single_arrow_left] = sym_single_arrow_left,
  [sym_undirected_double_arrow] = sym_undirected_double_arrow,
  [sym_double_arrow_right] = sym_double_arrow_right,
  [sym_double_arrow_left] = sym_double_arrow_left,
  [sym_undirected_squiggle] = sym_undirected_squiggle,
  [sym_squiggle_arrow_right] = sym_squiggle_arrow_right,
  [sym_squiggle_arrow_left] = sym_squiggle_arrow_left,
  [aux_sym_gram_repeat1] = aux_sym_gram_repeat1,
  [aux_sym_pattern_repeat1] = aux_sym_pattern_repeat1,
  [aux_sym_members_repeat1] = aux_sym_members_repeat1,
  [aux_sym_labels_repeat1] = aux_sym_labels_repeat1,
  [aux_sym_record_repeat1] = aux_sym_record_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_QMARK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [sym_symbol] = {
    .visible = true,
    .named = true,
  },
  [sym_integer] = {
    .visible = true,
    .named = true,
  },
  [sym_decimal] = {
    .visible = true,
    .named = true,
  },
  [sym_hexadecimal] = {
    .visible = true,
    .named = true,
  },
  [sym_octal] = {
    .visible = true,
    .named = true,
  },
  [sym_measurement] = {
    .visible = true,
    .named = true,
  },
  [sym_single_quoted_string] = {
    .visible = true,
    .named = true,
  },
  [sym_double_quoted_string] = {
    .visible = true,
    .named = true,
  },
  [sym_backticked_string] = {
    .visible = true,
    .named = true,
  },
  [sym_tagged_string] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_EQ_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_TILDE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_TILDE_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_TILDE] = {
    .visible = true,
    .named = false,
  },
  [sym_gram] = {
    .visible = true,
    .named = true,
  },
  [sym_pattern] = {
    .visible = true,
    .named = true,
  },
  [sym__path] = {
    .visible = false,
    .named = true,
  },
  [sym_node] = {
    .visible = true,
    .named = true,
  },
  [sym_relationship] = {
    .visible = true,
    .named = true,
  },
  [sym_series] = {
    .visible = true,
    .named = true,
  },
  [sym__attributes] = {
    .visible = false,
    .named = true,
  },
  [sym_members] = {
    .visible = true,
    .named = true,
  },
  [sym__member] = {
    .visible = false,
    .named = true,
  },
  [sym__identifier] = {
    .visible = false,
    .named = true,
  },
  [sym_labels] = {
    .visible = true,
    .named = true,
  },
  [sym_record] = {
    .visible = true,
    .named = true,
  },
  [sym_value_pair] = {
    .visible = true,
    .named = true,
  },
  [sym_type_pair] = {
    .visible = true,
    .named = true,
  },
  [sym__value] = {
    .visible = false,
    .named = true,
  },
  [sym__numeric_literal] = {
    .visible = false,
    .named = true,
  },
  [sym__string_literal] = {
    .visible = false,
    .named = true,
  },
  [sym__relationship_value] = {
    .visible = false,
    .named = true,
  },
  [sym_undirected_single] = {
    .visible = true,
    .named = true,
  },
  [sym_single_arrow_right] = {
    .visible = true,
    .named = true,
  },
  [sym_single_arrow_left] = {
    .visible = true,
    .named = true,
  },
  [sym_undirected_double_arrow] = {
    .visible = true,
    .named = true,
  },
  [sym_double_arrow_right] = {
    .visible = true,
    .named = true,
  },
  [sym_double_arrow_left] = {
    .visible = true,
    .named = true,
  },
  [sym_undirected_squiggle] = {
    .visible = true,
    .named = true,
  },
  [sym_squiggle_arrow_right] = {
    .visible = true,
    .named = true,
  },
  [sym_squiggle_arrow_left] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_gram_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_pattern_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_members_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_labels_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_record_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_cardinality = 1,
  field_identifier = 2,
  field_key = 3,
  field_labels = 4,
  field_left = 5,
  field_record = 6,
  field_right = 7,
  field_type = 8,
  field_value = 9,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_cardinality] = "cardinality",
  [field_identifier] = "identifier",
  [field_key] = "key",
  [field_labels] = "labels",
  [field_left] = "left",
  [field_record] = "record",
  [field_right] = "right",
  [field_type] = "type",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 3},
  [5] = {.index = 6, .length = 2},
  [6] = {.index = 8, .length = 2},
  [7] = {.index = 10, .length = 2},
  [8] = {.index = 12, .length = 3},
  [9] = {.index = 15, .length = 3},
  [10] = {.index = 18, .length = 2},
  [11] = {.index = 20, .length = 2},
  [12] = {.index = 22, .length = 3},
  [13] = {.index = 25, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_identifier, 0},
  [1] =
    {field_labels, 0},
  [2] =
    {field_record, 0},
  [3] =
    {field_identifier, 1, .inherited = true},
    {field_labels, 1, .inherited = true},
    {field_record, 1, .inherited = true},
  [6] =
    {field_identifier, 0},
    {field_labels, 1},
  [8] =
    {field_identifier, 0},
    {field_record, 1},
  [10] =
    {field_labels, 0},
    {field_record, 1},
  [12] =
    {field_left, 0},
    {field_right, 2},
    {field_value, 1},
  [15] =
    {field_identifier, 0},
    {field_labels, 1},
    {field_record, 2},
  [18] =
    {field_key, 0},
    {field_value, 2},
  [20] =
    {field_key, 0},
    {field_type, 2},
  [22] =
    {field_cardinality, 3},
    {field_key, 0},
    {field_type, 2},
  [25] =
    {field_identifier, 2, .inherited = true},
    {field_labels, 2, .inherited = true},
    {field_record, 2, .inherited = true},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(14);
      if (lookahead == '!') ADVANCE(26);
      if (lookahead == '"') ADVANCE(2);
      if (lookahead == '\'') ADVANCE(4);
      if (lookahead == '(') ADVANCE(16);
      if (lookahead == ')') ADVANCE(17);
      if (lookahead == '*') ADVANCE(28);
      if (lookahead == '+') ADVANCE(29);
      if (lookahead == ',') ADVANCE(15);
      if (lookahead == '-') ADVANCE(48);
      if (lookahead == '0') ADVANCE(32);
      if (lookahead == ':') ADVANCE(22);
      if (lookahead == '<') ADVANCE(6);
      if (lookahead == '=') ADVANCE(53);
      if (lookahead == '?') ADVANCE(27);
      if (lookahead == '[') ADVANCE(18);
      if (lookahead == ']') ADVANCE(19);
      if (lookahead == '`') ADVANCE(9);
      if (lookahead == '{') ADVANCE(23);
      if (lookahead == '|') ADVANCE(20);
      if (lookahead == '}') ADVANCE(24);
      if (lookahead == '~') ADVANCE(57);
      if (lookahead == '.' ||
          lookahead == '@' ||
          lookahead == '_') ADVANCE(31);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(33);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(2);
      if (lookahead == '\'') ADVANCE(4);
      if (lookahead == '(') ADVANCE(16);
      if (lookahead == ')') ADVANCE(17);
      if (lookahead == '-') ADVANCE(7);
      if (lookahead == '0') ADVANCE(32);
      if (lookahead == ':') ADVANCE(21);
      if (lookahead == ']') ADVANCE(19);
      if (lookahead == '`') ADVANCE(9);
      if (lookahead == '{') ADVANCE(23);
      if (lookahead == '|') ADVANCE(20);
      if (lookahead == '.' ||
          lookahead == '@' ||
          lookahead == '_') ADVANCE(31);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(33);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(43);
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(44);
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 4:
      if (lookahead == '\'') ADVANCE(41);
      if (lookahead == '\\') ADVANCE(5);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 5:
      if (lookahead == '\'') ADVANCE(42);
      if (lookahead == '\\') ADVANCE(5);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 6:
      if (lookahead == '-') ADVANCE(51);
      if (lookahead == '=') ADVANCE(8);
      if (lookahead == '~') ADVANCE(59);
      END_STATE();
    case 7:
      if (lookahead == '0') ADVANCE(34);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(33);
      END_STATE();
    case 8:
      if (lookahead == '=') ADVANCE(55);
      END_STATE();
    case 9:
      if (lookahead == '\\') ADVANCE(10);
      if (lookahead == '`') ADVANCE(45);
      if (lookahead != 0) ADVANCE(9);
      END_STATE();
    case 10:
      if (lookahead == '\\') ADVANCE(10);
      if (lookahead == '`') ADVANCE(46);
      if (lookahead != 0) ADVANCE(9);
      END_STATE();
    case 11:
      if (lookahead == '`') ADVANCE(47);
      if (lookahead != 0) ADVANCE(11);
      END_STATE();
    case 12:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(35);
      END_STATE();
    case 13:
      if (eof) ADVANCE(14);
      if (lookahead == '(') ADVANCE(16);
      if (lookahead == ',') ADVANCE(15);
      if (lookahead == '-') ADVANCE(49);
      if (lookahead == '<') ADVANCE(6);
      if (lookahead == '=') ADVANCE(52);
      if (lookahead == '[') ADVANCE(18);
      if (lookahead == ']') ADVANCE(19);
      if (lookahead == '{') ADVANCE(23);
      if (lookahead == '~') ADVANCE(56);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(13)
      END_STATE();
    case 14:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == ':') ADVANCE(25);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_COLON_COLON);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_QMARK);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '`') ADVANCE(11);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(31);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(12);
      if (lookahead == 'x') ADVANCE(39);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(38);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(40);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(12);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(33);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(40);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(12);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(40);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_decimal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(35);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_hexadecimal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(37);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(36);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(40);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_hexadecimal);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(37);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_octal);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(38);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_measurement);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(37);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(36);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(40);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_measurement);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(40);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_single_quoted_string);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_single_quoted_string);
      if (lookahead == '\'') ADVANCE(41);
      if (lookahead == '\\') ADVANCE(5);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_double_quoted_string);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_double_quoted_string);
      if (lookahead == '"') ADVANCE(43);
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_backticked_string);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_backticked_string);
      if (lookahead == '\\') ADVANCE(10);
      if (lookahead == '`') ADVANCE(45);
      if (lookahead != 0) ADVANCE(9);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_tagged_string);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '0') ADVANCE(34);
      if (lookahead == '>') ADVANCE(50);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(33);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '>') ADVANCE(50);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_LT_DASH);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '>') ADVANCE(54);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_EQ_GT);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_LT_EQ_EQ);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_TILDE);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_TILDE);
      if (lookahead == '>') ADVANCE(58);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_TILDE_GT);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_LT_TILDE);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 13},
  [3] = {.lex_state = 1},
  [4] = {.lex_state = 1},
  [5] = {.lex_state = 1},
  [6] = {.lex_state = 1},
  [7] = {.lex_state = 1},
  [8] = {.lex_state = 1},
  [9] = {.lex_state = 1},
  [10] = {.lex_state = 1},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 1},
  [13] = {.lex_state = 1},
  [14] = {.lex_state = 13},
  [15] = {.lex_state = 13},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 13},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 13},
  [58] = {.lex_state = 13},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 13},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_COLON_COLON] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [anon_sym_QMARK] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [sym_symbol] = ACTIONS(1),
    [sym_integer] = ACTIONS(1),
    [sym_decimal] = ACTIONS(1),
    [sym_hexadecimal] = ACTIONS(1),
    [sym_octal] = ACTIONS(1),
    [sym_measurement] = ACTIONS(1),
    [sym_single_quoted_string] = ACTIONS(1),
    [sym_double_quoted_string] = ACTIONS(1),
    [sym_backticked_string] = ACTIONS(1),
    [sym_tagged_string] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [anon_sym_LT_DASH] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_EQ_GT] = ACTIONS(1),
    [anon_sym_LT_EQ_EQ] = ACTIONS(1),
    [anon_sym_TILDE] = ACTIONS(1),
    [anon_sym_TILDE_GT] = ACTIONS(1),
    [anon_sym_LT_TILDE] = ACTIONS(1),
  },
  [1] = {
    [sym_gram] = STATE(82),
    [sym_pattern] = STATE(16),
    [sym__path] = STATE(25),
    [sym_node] = STATE(2),
    [sym_relationship] = STATE(25),
    [sym_series] = STATE(16),
    [sym_record] = STATE(16),
    [aux_sym_gram_repeat1] = STATE(16),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
    [anon_sym_LBRACK] = ACTIONS(7),
    [anon_sym_LBRACE] = ACTIONS(9),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 8,
    ACTIONS(13), 1,
      anon_sym_DASH,
    ACTIONS(15), 1,
      anon_sym_LT_DASH,
    ACTIONS(17), 1,
      anon_sym_EQ,
    ACTIONS(19), 1,
      anon_sym_LT_EQ_EQ,
    ACTIONS(21), 1,
      anon_sym_TILDE,
    ACTIONS(23), 1,
      anon_sym_LT_TILDE,
    ACTIONS(11), 6,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
    STATE(34), 10,
      sym__relationship_value,
      sym_undirected_single,
      sym_single_arrow_right,
      sym_single_arrow_left,
      sym_undirected_double_arrow,
      sym_double_arrow_right,
      sym_double_arrow_left,
      sym_undirected_squiggle,
      sym_squiggle_arrow_right,
      sym_squiggle_arrow_left,
  [39] = 11,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(25), 1,
      anon_sym_RBRACK,
    ACTIONS(27), 1,
      anon_sym_PIPE,
    ACTIONS(29), 1,
      anon_sym_COLON,
    STATE(31), 1,
      sym_labels,
    STATE(39), 1,
      sym__attributes,
    STATE(50), 1,
      sym_record,
    STATE(85), 1,
      sym_members,
    STATE(18), 3,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(31), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(33), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [83] = 9,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(29), 1,
      anon_sym_COLON,
    ACTIONS(35), 1,
      anon_sym_RPAREN,
    STATE(31), 1,
      sym_labels,
    STATE(50), 1,
      sym_record,
    STATE(87), 1,
      sym__attributes,
    STATE(18), 3,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(31), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(33), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [121] = 5,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_node,
    ACTIONS(37), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(39), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
    STATE(65), 6,
      sym__path,
      sym_relationship,
      sym__member,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
  [150] = 8,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(29), 1,
      anon_sym_COLON,
    STATE(31), 1,
      sym_labels,
    STATE(50), 1,
      sym_record,
    STATE(79), 1,
      sym__attributes,
    STATE(18), 3,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(31), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(33), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [185] = 8,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(29), 1,
      anon_sym_COLON,
    STATE(31), 1,
      sym_labels,
    STATE(50), 1,
      sym_record,
    STATE(78), 1,
      sym__attributes,
    STATE(18), 3,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(31), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(33), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [220] = 8,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(29), 1,
      anon_sym_COLON,
    STATE(31), 1,
      sym_labels,
    STATE(50), 1,
      sym_record,
    STATE(77), 1,
      sym__attributes,
    STATE(18), 3,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(31), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(33), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [255] = 8,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(29), 1,
      anon_sym_COLON,
    STATE(31), 1,
      sym_labels,
    STATE(50), 1,
      sym_record,
    STATE(76), 1,
      sym__attributes,
    STATE(18), 3,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(31), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(33), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [290] = 8,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(29), 1,
      anon_sym_COLON,
    STATE(31), 1,
      sym_labels,
    STATE(50), 1,
      sym_record,
    STATE(75), 1,
      sym__attributes,
    STATE(18), 3,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(31), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(33), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [325] = 5,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_node,
    ACTIONS(41), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(43), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
    STATE(52), 6,
      sym__path,
      sym_relationship,
      sym__member,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
  [354] = 8,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(29), 1,
      anon_sym_COLON,
    STATE(31), 1,
      sym_labels,
    STATE(50), 1,
      sym_record,
    STATE(74), 1,
      sym__attributes,
    STATE(18), 3,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(31), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(33), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [389] = 3,
    STATE(60), 3,
      sym__value,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(45), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(47), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [409] = 1,
    ACTIONS(49), 12,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
      anon_sym_DASH,
      anon_sym_LT_DASH,
      anon_sym_EQ,
      anon_sym_LT_EQ_EQ,
      anon_sym_TILDE,
      anon_sym_LT_TILDE,
  [424] = 1,
    ACTIONS(51), 12,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
      anon_sym_DASH,
      anon_sym_LT_DASH,
      anon_sym_EQ,
      anon_sym_LT_EQ_EQ,
      anon_sym_TILDE,
      anon_sym_LT_TILDE,
  [439] = 7,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    ACTIONS(7), 1,
      anon_sym_LBRACK,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(53), 1,
      ts_builtin_sym_end,
    STATE(2), 1,
      sym_node,
    STATE(25), 2,
      sym__path,
      sym_relationship,
    STATE(17), 4,
      sym_pattern,
      sym_series,
      sym_record,
      aux_sym_gram_repeat1,
  [465] = 7,
    ACTIONS(55), 1,
      ts_builtin_sym_end,
    ACTIONS(57), 1,
      anon_sym_LPAREN,
    ACTIONS(60), 1,
      anon_sym_LBRACK,
    ACTIONS(63), 1,
      anon_sym_LBRACE,
    STATE(2), 1,
      sym_node,
    STATE(25), 2,
      sym__path,
      sym_relationship,
    STATE(17), 4,
      sym_pattern,
      sym_series,
      sym_record,
      aux_sym_gram_repeat1,
  [491] = 5,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(29), 1,
      anon_sym_COLON,
    STATE(29), 1,
      sym_labels,
    STATE(49), 1,
      sym_record,
    ACTIONS(66), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_PIPE,
  [509] = 1,
    ACTIONS(68), 7,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_PIPE,
      anon_sym_LBRACE,
  [519] = 1,
    ACTIONS(70), 7,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_PIPE,
      anon_sym_LBRACE,
  [529] = 3,
    ACTIONS(74), 1,
      anon_sym_COLON,
    STATE(26), 1,
      aux_sym_labels_repeat1,
    ACTIONS(72), 4,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_PIPE,
      anon_sym_LBRACE,
  [542] = 3,
    ACTIONS(78), 1,
      anon_sym_COLON,
    STATE(22), 1,
      aux_sym_labels_repeat1,
    ACTIONS(76), 4,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_PIPE,
      anon_sym_LBRACE,
  [555] = 2,
    ACTIONS(81), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
    ACTIONS(83), 4,
      anon_sym_BANG,
      anon_sym_QMARK,
      anon_sym_STAR,
      anon_sym_PLUS,
  [566] = 3,
    ACTIONS(87), 1,
      anon_sym_COMMA,
    STATE(28), 1,
      aux_sym_pattern_repeat1,
    ACTIONS(85), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [579] = 3,
    ACTIONS(87), 1,
      anon_sym_COMMA,
    STATE(24), 1,
      aux_sym_pattern_repeat1,
    ACTIONS(89), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [592] = 3,
    ACTIONS(74), 1,
      anon_sym_COLON,
    STATE(22), 1,
      aux_sym_labels_repeat1,
    ACTIONS(91), 4,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_PIPE,
      anon_sym_LBRACE,
  [605] = 1,
    ACTIONS(93), 6,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
  [614] = 3,
    ACTIONS(97), 1,
      anon_sym_COMMA,
    STATE(28), 1,
      aux_sym_pattern_repeat1,
    ACTIONS(95), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [627] = 3,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    STATE(53), 1,
      sym_record,
    ACTIONS(100), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_PIPE,
  [639] = 1,
    ACTIONS(76), 5,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_PIPE,
      anon_sym_COLON,
      anon_sym_LBRACE,
  [647] = 3,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    STATE(51), 1,
      sym_record,
    ACTIONS(102), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_PIPE,
  [659] = 1,
    ACTIONS(95), 5,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [667] = 1,
    ACTIONS(104), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [674] = 3,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_node,
    STATE(27), 2,
      sym__path,
      sym_relationship,
  [685] = 1,
    ACTIONS(106), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [692] = 1,
    ACTIONS(108), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [699] = 3,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_node,
    STATE(32), 2,
      sym__path,
      sym_relationship,
  [710] = 1,
    ACTIONS(110), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [717] = 3,
    ACTIONS(27), 1,
      anon_sym_PIPE,
    ACTIONS(112), 1,
      anon_sym_RBRACK,
    STATE(84), 1,
      sym_members,
  [727] = 3,
    ACTIONS(114), 1,
      anon_sym_COMMA,
    ACTIONS(116), 1,
      anon_sym_RBRACK,
    STATE(41), 1,
      aux_sym_members_repeat1,
  [737] = 3,
    ACTIONS(118), 1,
      anon_sym_COMMA,
    ACTIONS(121), 1,
      anon_sym_RBRACK,
    STATE(41), 1,
      aux_sym_members_repeat1,
  [747] = 2,
    ACTIONS(123), 1,
      sym_symbol,
    STATE(43), 2,
      sym_value_pair,
      sym_type_pair,
  [755] = 3,
    ACTIONS(125), 1,
      anon_sym_COMMA,
    ACTIONS(127), 1,
      anon_sym_RBRACE,
    STATE(46), 1,
      aux_sym_record_repeat1,
  [765] = 2,
    ACTIONS(123), 1,
      sym_symbol,
    STATE(62), 2,
      sym_value_pair,
      sym_type_pair,
  [773] = 3,
    ACTIONS(129), 1,
      anon_sym_COMMA,
    ACTIONS(132), 1,
      anon_sym_RBRACE,
    STATE(45), 1,
      aux_sym_record_repeat1,
  [783] = 3,
    ACTIONS(125), 1,
      anon_sym_COMMA,
    ACTIONS(134), 1,
      anon_sym_RBRACE,
    STATE(45), 1,
      aux_sym_record_repeat1,
  [793] = 3,
    ACTIONS(136), 1,
      anon_sym_LBRACK,
    ACTIONS(138), 1,
      anon_sym_DASH,
    ACTIONS(140), 1,
      anon_sym_DASH_GT,
  [803] = 3,
    ACTIONS(142), 1,
      anon_sym_LBRACK,
    ACTIONS(144), 1,
      anon_sym_TILDE,
    ACTIONS(146), 1,
      anon_sym_TILDE_GT,
  [813] = 1,
    ACTIONS(148), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_PIPE,
  [819] = 1,
    ACTIONS(150), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_PIPE,
  [825] = 1,
    ACTIONS(152), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_PIPE,
  [831] = 3,
    ACTIONS(114), 1,
      anon_sym_COMMA,
    ACTIONS(154), 1,
      anon_sym_RBRACK,
    STATE(40), 1,
      aux_sym_members_repeat1,
  [841] = 1,
    ACTIONS(156), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_PIPE,
  [847] = 3,
    ACTIONS(158), 1,
      anon_sym_LPAREN,
    ACTIONS(160), 1,
      anon_sym_LBRACK,
    ACTIONS(162), 1,
      anon_sym_EQ,
  [857] = 3,
    ACTIONS(164), 1,
      anon_sym_LBRACK,
    ACTIONS(166), 1,
      anon_sym_EQ,
    ACTIONS(168), 1,
      anon_sym_EQ_GT,
  [867] = 2,
    ACTIONS(170), 1,
      anon_sym_EQ,
    ACTIONS(172), 1,
      anon_sym_EQ_GT,
  [874] = 2,
    ACTIONS(174), 1,
      anon_sym_LBRACK,
    ACTIONS(176), 1,
      anon_sym_DASH,
  [881] = 2,
    ACTIONS(178), 1,
      anon_sym_DASH,
    ACTIONS(180), 1,
      anon_sym_DASH_GT,
  [888] = 2,
    ACTIONS(182), 1,
      anon_sym_LBRACK,
    ACTIONS(184), 1,
      anon_sym_TILDE,
  [895] = 1,
    ACTIONS(186), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [900] = 1,
    ACTIONS(188), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [905] = 1,
    ACTIONS(132), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [910] = 2,
    ACTIONS(190), 1,
      anon_sym_TILDE,
    ACTIONS(192), 1,
      anon_sym_TILDE_GT,
  [917] = 2,
    ACTIONS(194), 1,
      anon_sym_COLON,
    ACTIONS(196), 1,
      anon_sym_COLON_COLON,
  [924] = 1,
    ACTIONS(121), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [929] = 1,
    ACTIONS(198), 1,
      anon_sym_LPAREN,
  [933] = 1,
    ACTIONS(200), 1,
      anon_sym_LPAREN,
  [937] = 1,
    ACTIONS(202), 1,
      anon_sym_LPAREN,
  [941] = 1,
    ACTIONS(204), 1,
      anon_sym_LPAREN,
  [945] = 1,
    ACTIONS(206), 1,
      anon_sym_LPAREN,
  [949] = 1,
    ACTIONS(208), 1,
      anon_sym_LPAREN,
  [953] = 1,
    ACTIONS(210), 1,
      sym_symbol,
  [957] = 1,
    ACTIONS(212), 1,
      anon_sym_LPAREN,
  [961] = 1,
    ACTIONS(214), 1,
      anon_sym_RBRACK,
  [965] = 1,
    ACTIONS(216), 1,
      anon_sym_RBRACK,
  [969] = 1,
    ACTIONS(218), 1,
      anon_sym_RBRACK,
  [973] = 1,
    ACTIONS(220), 1,
      anon_sym_RBRACK,
  [977] = 1,
    ACTIONS(222), 1,
      anon_sym_RBRACK,
  [981] = 1,
    ACTIONS(224), 1,
      anon_sym_RBRACK,
  [985] = 1,
    ACTIONS(226), 1,
      anon_sym_LPAREN,
  [989] = 1,
    ACTIONS(228), 1,
      anon_sym_LPAREN,
  [993] = 1,
    ACTIONS(230), 1,
      ts_builtin_sym_end,
  [997] = 1,
    ACTIONS(232), 1,
      sym_symbol,
  [1001] = 1,
    ACTIONS(234), 1,
      anon_sym_RBRACK,
  [1005] = 1,
    ACTIONS(236), 1,
      anon_sym_RBRACK,
  [1009] = 1,
    ACTIONS(238), 1,
      anon_sym_DASH,
  [1013] = 1,
    ACTIONS(240), 1,
      anon_sym_RPAREN,
  [1017] = 1,
    ACTIONS(242), 1,
      anon_sym_EQ,
  [1021] = 1,
    ACTIONS(244), 1,
      sym_symbol,
  [1025] = 1,
    ACTIONS(246), 1,
      anon_sym_TILDE,
  [1029] = 1,
    ACTIONS(248), 1,
      anon_sym_LPAREN,
  [1033] = 1,
    ACTIONS(250), 1,
      anon_sym_LPAREN,
  [1037] = 1,
    ACTIONS(252), 1,
      anon_sym_LPAREN,
  [1041] = 1,
    ACTIONS(254), 1,
      anon_sym_LPAREN,
  [1045] = 1,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
  [1049] = 1,
    ACTIONS(258), 1,
      anon_sym_LPAREN,
  [1053] = 1,
    ACTIONS(260), 1,
      anon_sym_LPAREN,
  [1057] = 1,
    ACTIONS(262), 1,
      anon_sym_LPAREN,
  [1061] = 1,
    ACTIONS(264), 1,
      anon_sym_LPAREN,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 39,
  [SMALL_STATE(4)] = 83,
  [SMALL_STATE(5)] = 121,
  [SMALL_STATE(6)] = 150,
  [SMALL_STATE(7)] = 185,
  [SMALL_STATE(8)] = 220,
  [SMALL_STATE(9)] = 255,
  [SMALL_STATE(10)] = 290,
  [SMALL_STATE(11)] = 325,
  [SMALL_STATE(12)] = 354,
  [SMALL_STATE(13)] = 389,
  [SMALL_STATE(14)] = 409,
  [SMALL_STATE(15)] = 424,
  [SMALL_STATE(16)] = 439,
  [SMALL_STATE(17)] = 465,
  [SMALL_STATE(18)] = 491,
  [SMALL_STATE(19)] = 509,
  [SMALL_STATE(20)] = 519,
  [SMALL_STATE(21)] = 529,
  [SMALL_STATE(22)] = 542,
  [SMALL_STATE(23)] = 555,
  [SMALL_STATE(24)] = 566,
  [SMALL_STATE(25)] = 579,
  [SMALL_STATE(26)] = 592,
  [SMALL_STATE(27)] = 605,
  [SMALL_STATE(28)] = 614,
  [SMALL_STATE(29)] = 627,
  [SMALL_STATE(30)] = 639,
  [SMALL_STATE(31)] = 647,
  [SMALL_STATE(32)] = 659,
  [SMALL_STATE(33)] = 667,
  [SMALL_STATE(34)] = 674,
  [SMALL_STATE(35)] = 685,
  [SMALL_STATE(36)] = 692,
  [SMALL_STATE(37)] = 699,
  [SMALL_STATE(38)] = 710,
  [SMALL_STATE(39)] = 717,
  [SMALL_STATE(40)] = 727,
  [SMALL_STATE(41)] = 737,
  [SMALL_STATE(42)] = 747,
  [SMALL_STATE(43)] = 755,
  [SMALL_STATE(44)] = 765,
  [SMALL_STATE(45)] = 773,
  [SMALL_STATE(46)] = 783,
  [SMALL_STATE(47)] = 793,
  [SMALL_STATE(48)] = 803,
  [SMALL_STATE(49)] = 813,
  [SMALL_STATE(50)] = 819,
  [SMALL_STATE(51)] = 825,
  [SMALL_STATE(52)] = 831,
  [SMALL_STATE(53)] = 841,
  [SMALL_STATE(54)] = 847,
  [SMALL_STATE(55)] = 857,
  [SMALL_STATE(56)] = 867,
  [SMALL_STATE(57)] = 874,
  [SMALL_STATE(58)] = 881,
  [SMALL_STATE(59)] = 888,
  [SMALL_STATE(60)] = 895,
  [SMALL_STATE(61)] = 900,
  [SMALL_STATE(62)] = 905,
  [SMALL_STATE(63)] = 910,
  [SMALL_STATE(64)] = 917,
  [SMALL_STATE(65)] = 924,
  [SMALL_STATE(66)] = 929,
  [SMALL_STATE(67)] = 933,
  [SMALL_STATE(68)] = 937,
  [SMALL_STATE(69)] = 941,
  [SMALL_STATE(70)] = 945,
  [SMALL_STATE(71)] = 949,
  [SMALL_STATE(72)] = 953,
  [SMALL_STATE(73)] = 957,
  [SMALL_STATE(74)] = 961,
  [SMALL_STATE(75)] = 965,
  [SMALL_STATE(76)] = 969,
  [SMALL_STATE(77)] = 973,
  [SMALL_STATE(78)] = 977,
  [SMALL_STATE(79)] = 981,
  [SMALL_STATE(80)] = 985,
  [SMALL_STATE(81)] = 989,
  [SMALL_STATE(82)] = 993,
  [SMALL_STATE(83)] = 997,
  [SMALL_STATE(84)] = 1001,
  [SMALL_STATE(85)] = 1005,
  [SMALL_STATE(86)] = 1009,
  [SMALL_STATE(87)] = 1013,
  [SMALL_STATE(88)] = 1017,
  [SMALL_STATE(89)] = 1021,
  [SMALL_STATE(90)] = 1025,
  [SMALL_STATE(91)] = 1029,
  [SMALL_STATE(92)] = 1033,
  [SMALL_STATE(93)] = 1037,
  [SMALL_STATE(94)] = 1041,
  [SMALL_STATE(95)] = 1045,
  [SMALL_STATE(96)] = 1049,
  [SMALL_STATE(97)] = 1053,
  [SMALL_STATE(98)] = 1057,
  [SMALL_STATE(99)] = 1061,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_gram, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__path, 1),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [41] = {.entry = {.count = 1, .reusable = false}}, SHIFT(52),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(60),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 3, .production_id = 4),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 2),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_gram, 1),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2),
  [57] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2), SHIFT_REPEAT(4),
  [60] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2), SHIFT_REPEAT(3),
  [63] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2), SHIFT_REPEAT(42),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 1, .production_id = 1),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record, 4),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record, 3),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_labels, 2),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_labels_repeat1, 2),
  [78] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_labels_repeat1, 2), SHIFT_REPEAT(72),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_pair, 3, .production_id = 11),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pattern, 2),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pattern, 1),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_labels, 3),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relationship, 3, .production_id = 8),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pattern_repeat1, 2),
  [97] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_pattern_repeat1, 2), SHIFT_REPEAT(37),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 2, .production_id = 5),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 1, .production_id = 2),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_series, 3),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_series, 4, .production_id = 4),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_series, 2),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_series, 3, .production_id = 4),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [114] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_members, 3),
  [118] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_members_repeat1, 2), SHIFT_REPEAT(5),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_members_repeat1, 2),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [127] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [129] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_record_repeat1, 2), SHIFT_REPEAT(44),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_record_repeat1, 2),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [138] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [142] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [144] = {.entry = {.count = 1, .reusable = false}}, SHIFT(67),
  [146] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [148] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 2, .production_id = 6),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 1, .production_id = 3),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 2, .production_id = 7),
  [154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_members, 2),
  [156] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 3, .production_id = 9),
  [158] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_arrow_left, 1),
  [160] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [166] = {.entry = {.count = 1, .reusable = false}}, SHIFT(69),
  [168] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [170] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [172] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [176] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [178] = {.entry = {.count = 1, .reusable = false}}, SHIFT(91),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [182] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [186] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_pair, 3, .production_id = 10),
  [188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_pair, 4, .production_id = 12),
  [190] = {.entry = {.count = 1, .reusable = false}}, SHIFT(97),
  [192] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [194] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [196] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_arrow_right, 2),
  [200] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_squiggle, 2),
  [202] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_arrow_right, 2),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_double_arrow, 2),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_arrow_left, 2),
  [208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_arrow_right, 2),
  [210] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [212] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_arrow_left, 2),
  [214] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [216] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [218] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [220] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [224] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [226] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_arrow_left, 2),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_single, 2),
  [230] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [236] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [246] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_single, 5, .production_id = 13),
  [250] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_arrow_right, 5, .production_id = 13),
  [252] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_arrow_left, 5, .production_id = 13),
  [254] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_double_arrow, 5, .production_id = 13),
  [256] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_arrow_right, 5, .production_id = 13),
  [258] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_arrow_left, 5, .production_id = 13),
  [260] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_squiggle, 5, .production_id = 13),
  [262] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_arrow_right, 5, .production_id = 13),
  [264] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_arrow_left, 5, .production_id = 13),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_gram() {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
