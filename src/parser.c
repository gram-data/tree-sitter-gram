#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 97
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 62
#define ALIAS_COUNT 0
#define TOKEN_COUNT 30
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 6
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 7

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
  sym_symbol = 11,
  sym_integer = 12,
  sym_decimal = 13,
  sym_hexadecimal = 14,
  sym_octal = 15,
  sym_measurement = 16,
  sym_single_quoted_string = 17,
  sym_double_quoted_string = 18,
  sym_backticked_string = 19,
  sym_tagged_string = 20,
  anon_sym_DASH = 21,
  anon_sym_DASH_GT = 22,
  anon_sym_LT_DASH = 23,
  anon_sym_EQ = 24,
  aux_sym_double_arrow_right_token1 = 25,
  aux_sym_double_arrow_left_token1 = 26,
  anon_sym_TILDE = 27,
  anon_sym_TILDE_GT = 28,
  anon_sym_LT_TILDE = 29,
  sym_gram = 30,
  sym_pattern = 31,
  sym_path = 32,
  sym_node = 33,
  sym_series = 34,
  sym_attributes = 35,
  sym_members = 36,
  sym__member = 37,
  sym__identifier = 38,
  sym_labels = 39,
  sym_record = 40,
  sym_value_pair = 41,
  sym_type_pair = 42,
  sym__value = 43,
  sym__numeric_literal = 44,
  sym__string_literal = 45,
  sym__relationship = 46,
  sym_undirected_single = 47,
  sym_single_arrow_right = 48,
  sym_single_arrow_left = 49,
  sym_undirected_double_arrow = 50,
  sym_double_arrow_right = 51,
  sym_double_arrow_left = 52,
  sym_undirected_squiggle = 53,
  sym_squiggle_arrow_right = 54,
  sym_squiggle_arrow_left = 55,
  aux_sym_gram_repeat1 = 56,
  aux_sym_pattern_repeat1 = 57,
  aux_sym_path_repeat1 = 58,
  aux_sym_members_repeat1 = 59,
  aux_sym_labels_repeat1 = 60,
  aux_sym_record_repeat1 = 61,
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
  [aux_sym_double_arrow_right_token1] = "double_arrow_right_token1",
  [aux_sym_double_arrow_left_token1] = "double_arrow_left_token1",
  [anon_sym_TILDE] = "~",
  [anon_sym_TILDE_GT] = "~>",
  [anon_sym_LT_TILDE] = "<~",
  [sym_gram] = "gram",
  [sym_pattern] = "pattern",
  [sym_path] = "path",
  [sym_node] = "node",
  [sym_series] = "series",
  [sym_attributes] = "attributes",
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
  [sym__relationship] = "_relationship",
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
  [aux_sym_path_repeat1] = "path_repeat1",
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
  [aux_sym_double_arrow_right_token1] = aux_sym_double_arrow_right_token1,
  [aux_sym_double_arrow_left_token1] = aux_sym_double_arrow_left_token1,
  [anon_sym_TILDE] = anon_sym_TILDE,
  [anon_sym_TILDE_GT] = anon_sym_TILDE_GT,
  [anon_sym_LT_TILDE] = anon_sym_LT_TILDE,
  [sym_gram] = sym_gram,
  [sym_pattern] = sym_pattern,
  [sym_path] = sym_path,
  [sym_node] = sym_node,
  [sym_series] = sym_series,
  [sym_attributes] = sym_attributes,
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
  [sym__relationship] = sym__relationship,
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
  [aux_sym_path_repeat1] = aux_sym_path_repeat1,
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
  [aux_sym_double_arrow_right_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_double_arrow_left_token1] = {
    .visible = false,
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
  [sym_path] = {
    .visible = true,
    .named = true,
  },
  [sym_node] = {
    .visible = true,
    .named = true,
  },
  [sym_series] = {
    .visible = true,
    .named = true,
  },
  [sym_attributes] = {
    .visible = true,
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
  [sym__relationship] = {
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
  [aux_sym_path_repeat1] = {
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
  field_identifier = 1,
  field_key = 2,
  field_labels = 3,
  field_record = 4,
  field_type = 5,
  field_value = 6,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_identifier] = "identifier",
  [field_key] = "key",
  [field_labels] = "labels",
  [field_record] = "record",
  [field_type] = "type",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 2},
  [5] = {.index = 5, .length = 2},
  [6] = {.index = 7, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_identifier, 0},
  [1] =
    {field_labels, 0},
  [2] =
    {field_record, 0},
  [3] =
    {field_identifier, 0},
    {field_labels, 1},
  [5] =
    {field_key, 0},
    {field_value, 2},
  [7] =
    {field_key, 0},
    {field_type, 2},
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(15);
      if (lookahead == '"') ADVANCE(2);
      if (lookahead == '\'') ADVANCE(4);
      if (lookahead == '(') ADVANCE(17);
      if (lookahead == ')') ADVANCE(18);
      if (lookahead == ',') ADVANCE(16);
      if (lookahead == '-') ADVANCE(45);
      if (lookahead == '0') ADVANCE(29);
      if (lookahead == ':') ADVANCE(23);
      if (lookahead == '<') ADVANCE(6);
      if (lookahead == '=') ADVANCE(50);
      if (lookahead == '>') ADVANCE(8);
      if (lookahead == '[') ADVANCE(19);
      if (lookahead == ']') ADVANCE(20);
      if (lookahead == '`') ADVANCE(10);
      if (lookahead == '{') ADVANCE(24);
      if (lookahead == '|') ADVANCE(21);
      if (lookahead == '}') ADVANCE(25);
      if (lookahead == '~') ADVANCE(55);
      if (lookahead == '.' ||
          lookahead == '@' ||
          lookahead == '_') ADVANCE(28);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(30);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(27);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(2);
      if (lookahead == '\'') ADVANCE(4);
      if (lookahead == '(') ADVANCE(17);
      if (lookahead == ')') ADVANCE(18);
      if (lookahead == '-') ADVANCE(7);
      if (lookahead == '0') ADVANCE(29);
      if (lookahead == ':') ADVANCE(22);
      if (lookahead == ']') ADVANCE(20);
      if (lookahead == '`') ADVANCE(10);
      if (lookahead == '{') ADVANCE(24);
      if (lookahead == '|') ADVANCE(21);
      if (lookahead == '.' ||
          lookahead == '@' ||
          lookahead == '_') ADVANCE(28);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(30);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(27);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(40);
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(41);
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 4:
      if (lookahead == '\'') ADVANCE(38);
      if (lookahead == '\\') ADVANCE(5);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 5:
      if (lookahead == '\'') ADVANCE(39);
      if (lookahead == '\\') ADVANCE(5);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 6:
      if (lookahead == '-') ADVANCE(48);
      if (lookahead == '=') ADVANCE(53);
      if (lookahead == '~') ADVANCE(57);
      END_STATE();
    case 7:
      if (lookahead == '0') ADVANCE(31);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(30);
      END_STATE();
    case 8:
      if (lookahead == '=') ADVANCE(9);
      END_STATE();
    case 9:
      if (lookahead == '>') ADVANCE(51);
      END_STATE();
    case 10:
      if (lookahead == '\\') ADVANCE(11);
      if (lookahead == '`') ADVANCE(42);
      if (lookahead != 0) ADVANCE(10);
      END_STATE();
    case 11:
      if (lookahead == '\\') ADVANCE(11);
      if (lookahead == '`') ADVANCE(43);
      if (lookahead != 0) ADVANCE(10);
      END_STATE();
    case 12:
      if (lookahead == '`') ADVANCE(44);
      if (lookahead != 0) ADVANCE(12);
      END_STATE();
    case 13:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(32);
      END_STATE();
    case 14:
      if (eof) ADVANCE(15);
      if (lookahead == '(') ADVANCE(17);
      if (lookahead == ',') ADVANCE(16);
      if (lookahead == '-') ADVANCE(46);
      if (lookahead == '<') ADVANCE(6);
      if (lookahead == '=') ADVANCE(49);
      if (lookahead == '[') ADVANCE(19);
      if (lookahead == ']') ADVANCE(20);
      if (lookahead == '{') ADVANCE(24);
      if (lookahead == '~') ADVANCE(54);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(14)
      END_STATE();
    case 15:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == ':') ADVANCE(26);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_COLON_COLON);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '`') ADVANCE(12);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(27);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(28);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(13);
      if (lookahead == 'x') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(35);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(37);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(30);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(37);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(13);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(37);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_decimal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(32);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_hexadecimal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(34);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(33);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(37);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_hexadecimal);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(34);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_octal);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(35);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_measurement);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(34);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(33);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(37);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_measurement);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(37);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_single_quoted_string);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_single_quoted_string);
      if (lookahead == '\'') ADVANCE(38);
      if (lookahead == '\\') ADVANCE(5);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_double_quoted_string);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_double_quoted_string);
      if (lookahead == '"') ADVANCE(40);
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_backticked_string);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_backticked_string);
      if (lookahead == '\\') ADVANCE(11);
      if (lookahead == '`') ADVANCE(42);
      if (lookahead != 0) ADVANCE(10);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_tagged_string);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '0') ADVANCE(31);
      if (lookahead == '>') ADVANCE(47);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(30);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '>') ADVANCE(47);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_LT_DASH);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '>') ADVANCE(51);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(aux_sym_double_arrow_right_token1);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(aux_sym_double_arrow_left_token1);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(aux_sym_double_arrow_left_token1);
      if (lookahead == '<') ADVANCE(52);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_TILDE);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_TILDE);
      if (lookahead == '>') ADVANCE(56);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_TILDE_GT);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_LT_TILDE);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 14},
  [3] = {.lex_state = 14},
  [4] = {.lex_state = 14},
  [5] = {.lex_state = 1},
  [6] = {.lex_state = 1},
  [7] = {.lex_state = 1},
  [8] = {.lex_state = 1},
  [9] = {.lex_state = 1},
  [10] = {.lex_state = 1},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 1},
  [13] = {.lex_state = 1},
  [14] = {.lex_state = 1},
  [15] = {.lex_state = 1},
  [16] = {.lex_state = 14},
  [17] = {.lex_state = 14},
  [18] = {.lex_state = 14},
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
  [43] = {.lex_state = 14},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 14},
  [53] = {.lex_state = 14},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 14},
  [58] = {.lex_state = 0},
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
  [83] = {.lex_state = 14},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 14},
  [86] = {.lex_state = 0},
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
    [aux_sym_double_arrow_right_token1] = ACTIONS(1),
    [aux_sym_double_arrow_left_token1] = ACTIONS(1),
    [anon_sym_TILDE] = ACTIONS(1),
    [anon_sym_TILDE_GT] = ACTIONS(1),
    [anon_sym_LT_TILDE] = ACTIONS(1),
  },
  [1] = {
    [sym_gram] = STATE(79),
    [sym_pattern] = STATE(20),
    [sym_path] = STATE(24),
    [sym_node] = STATE(4),
    [sym_series] = STATE(20),
    [sym_record] = STATE(20),
    [aux_sym_gram_repeat1] = STATE(20),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
    [anon_sym_LBRACK] = ACTIONS(7),
    [anon_sym_LBRACE] = ACTIONS(9),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 9,
    ACTIONS(13), 1,
      anon_sym_DASH,
    ACTIONS(15), 1,
      anon_sym_LT_DASH,
    ACTIONS(17), 1,
      anon_sym_EQ,
    ACTIONS(19), 1,
      aux_sym_double_arrow_left_token1,
    ACTIONS(21), 1,
      anon_sym_TILDE,
    ACTIONS(23), 1,
      anon_sym_LT_TILDE,
    STATE(3), 1,
      aux_sym_path_repeat1,
    ACTIONS(11), 6,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
    STATE(56), 10,
      sym__relationship,
      sym_undirected_single,
      sym_single_arrow_right,
      sym_single_arrow_left,
      sym_undirected_double_arrow,
      sym_double_arrow_right,
      sym_double_arrow_left,
      sym_undirected_squiggle,
      sym_squiggle_arrow_right,
      sym_squiggle_arrow_left,
  [42] = 9,
    ACTIONS(27), 1,
      anon_sym_DASH,
    ACTIONS(30), 1,
      anon_sym_LT_DASH,
    ACTIONS(33), 1,
      anon_sym_EQ,
    ACTIONS(36), 1,
      aux_sym_double_arrow_left_token1,
    ACTIONS(39), 1,
      anon_sym_TILDE,
    ACTIONS(42), 1,
      anon_sym_LT_TILDE,
    STATE(3), 1,
      aux_sym_path_repeat1,
    ACTIONS(25), 6,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
    STATE(56), 10,
      sym__relationship,
      sym_undirected_single,
      sym_single_arrow_right,
      sym_single_arrow_left,
      sym_undirected_double_arrow,
      sym_double_arrow_right,
      sym_double_arrow_left,
      sym_undirected_squiggle,
      sym_squiggle_arrow_right,
      sym_squiggle_arrow_left,
  [84] = 9,
    ACTIONS(13), 1,
      anon_sym_DASH,
    ACTIONS(15), 1,
      anon_sym_LT_DASH,
    ACTIONS(17), 1,
      anon_sym_EQ,
    ACTIONS(19), 1,
      aux_sym_double_arrow_left_token1,
    ACTIONS(21), 1,
      anon_sym_TILDE,
    ACTIONS(23), 1,
      anon_sym_LT_TILDE,
    STATE(2), 1,
      aux_sym_path_repeat1,
    ACTIONS(45), 6,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
    STATE(56), 10,
      sym__relationship,
      sym_undirected_single,
      sym_single_arrow_right,
      sym_single_arrow_left,
      sym_undirected_double_arrow,
      sym_double_arrow_right,
      sym_double_arrow_left,
      sym_undirected_squiggle,
      sym_squiggle_arrow_right,
      sym_squiggle_arrow_left,
  [126] = 11,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(47), 1,
      anon_sym_RBRACK,
    ACTIONS(49), 1,
      anon_sym_PIPE,
    ACTIONS(51), 1,
      anon_sym_COLON,
    STATE(36), 1,
      sym_labels,
    STATE(45), 1,
      sym_attributes,
    STATE(47), 1,
      sym_record,
    STATE(82), 1,
      sym_members,
    STATE(28), 3,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(53), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(55), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [170] = 9,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(51), 1,
      anon_sym_COLON,
    ACTIONS(57), 1,
      anon_sym_RPAREN,
    STATE(36), 1,
      sym_labels,
    STATE(47), 1,
      sym_record,
    STATE(84), 1,
      sym_attributes,
    STATE(28), 3,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(53), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(55), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [208] = 8,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(51), 1,
      anon_sym_COLON,
    STATE(36), 1,
      sym_labels,
    STATE(47), 1,
      sym_record,
    STATE(77), 1,
      sym_attributes,
    STATE(28), 3,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(53), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(55), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [243] = 8,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(51), 1,
      anon_sym_COLON,
    STATE(36), 1,
      sym_labels,
    STATE(47), 1,
      sym_record,
    STATE(76), 1,
      sym_attributes,
    STATE(28), 3,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(53), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(55), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [278] = 8,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(51), 1,
      anon_sym_COLON,
    STATE(36), 1,
      sym_labels,
    STATE(47), 1,
      sym_record,
    STATE(75), 1,
      sym_attributes,
    STATE(28), 3,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(53), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(55), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [313] = 8,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(51), 1,
      anon_sym_COLON,
    STATE(36), 1,
      sym_labels,
    STATE(47), 1,
      sym_record,
    STATE(74), 1,
      sym_attributes,
    STATE(28), 3,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(53), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(55), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [348] = 8,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(51), 1,
      anon_sym_COLON,
    STATE(36), 1,
      sym_labels,
    STATE(47), 1,
      sym_record,
    STATE(73), 1,
      sym_attributes,
    STATE(28), 3,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(53), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(55), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [383] = 8,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(51), 1,
      anon_sym_COLON,
    STATE(36), 1,
      sym_labels,
    STATE(47), 1,
      sym_record,
    STATE(72), 1,
      sym_attributes,
    STATE(28), 3,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(53), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(55), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [418] = 5,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    STATE(4), 1,
      sym_node,
    ACTIONS(59), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    STATE(62), 5,
      sym_path,
      sym__member,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(61), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [446] = 5,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    STATE(4), 1,
      sym_node,
    ACTIONS(63), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    STATE(37), 5,
      sym_path,
      sym__member,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(65), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [474] = 3,
    STATE(58), 3,
      sym__value,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(67), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(69), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [494] = 1,
    ACTIONS(25), 12,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
      anon_sym_DASH,
      anon_sym_LT_DASH,
      anon_sym_EQ,
      aux_sym_double_arrow_left_token1,
      anon_sym_TILDE,
      anon_sym_LT_TILDE,
  [509] = 1,
    ACTIONS(71), 12,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
      anon_sym_DASH,
      anon_sym_LT_DASH,
      anon_sym_EQ,
      aux_sym_double_arrow_left_token1,
      anon_sym_TILDE,
      anon_sym_LT_TILDE,
  [524] = 1,
    ACTIONS(73), 12,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
      anon_sym_DASH,
      anon_sym_LT_DASH,
      anon_sym_EQ,
      aux_sym_double_arrow_left_token1,
      anon_sym_TILDE,
      anon_sym_LT_TILDE,
  [539] = 7,
    ACTIONS(75), 1,
      ts_builtin_sym_end,
    ACTIONS(77), 1,
      anon_sym_LPAREN,
    ACTIONS(80), 1,
      anon_sym_LBRACK,
    ACTIONS(83), 1,
      anon_sym_LBRACE,
    STATE(4), 1,
      sym_node,
    STATE(24), 1,
      sym_path,
    STATE(19), 4,
      sym_pattern,
      sym_series,
      sym_record,
      aux_sym_gram_repeat1,
  [564] = 7,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    ACTIONS(7), 1,
      anon_sym_LBRACK,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(86), 1,
      ts_builtin_sym_end,
    STATE(4), 1,
      sym_node,
    STATE(24), 1,
      sym_path,
    STATE(19), 4,
      sym_pattern,
      sym_series,
      sym_record,
      aux_sym_gram_repeat1,
  [589] = 1,
    ACTIONS(88), 7,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_PIPE,
      anon_sym_LBRACE,
  [599] = 1,
    ACTIONS(90), 7,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_PIPE,
      anon_sym_LBRACE,
  [609] = 3,
    ACTIONS(94), 1,
      anon_sym_COMMA,
    STATE(25), 1,
      aux_sym_pattern_repeat1,
    ACTIONS(92), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [622] = 3,
    ACTIONS(94), 1,
      anon_sym_COMMA,
    STATE(23), 1,
      aux_sym_pattern_repeat1,
    ACTIONS(96), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [635] = 3,
    ACTIONS(100), 1,
      anon_sym_COMMA,
    STATE(25), 1,
      aux_sym_pattern_repeat1,
    ACTIONS(98), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [648] = 3,
    ACTIONS(105), 1,
      anon_sym_COLON,
    STATE(26), 1,
      aux_sym_labels_repeat1,
    ACTIONS(103), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_PIPE,
  [660] = 3,
    ACTIONS(110), 1,
      anon_sym_COLON,
    STATE(26), 1,
      aux_sym_labels_repeat1,
    ACTIONS(108), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_PIPE,
  [672] = 3,
    ACTIONS(51), 1,
      anon_sym_COLON,
    STATE(48), 1,
      sym_labels,
    ACTIONS(112), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_PIPE,
  [684] = 1,
    ACTIONS(98), 5,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [692] = 3,
    ACTIONS(110), 1,
      anon_sym_COLON,
    STATE(27), 1,
      aux_sym_labels_repeat1,
    ACTIONS(114), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_PIPE,
  [704] = 1,
    ACTIONS(116), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [711] = 1,
    ACTIONS(118), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [718] = 1,
    ACTIONS(103), 4,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_PIPE,
      anon_sym_COLON,
  [725] = 1,
    ACTIONS(120), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [732] = 2,
    ACTIONS(122), 1,
      sym_symbol,
    STATE(60), 2,
      sym_value_pair,
      sym_type_pair,
  [740] = 1,
    ACTIONS(124), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_PIPE,
  [746] = 3,
    ACTIONS(126), 1,
      anon_sym_COMMA,
    ACTIONS(128), 1,
      anon_sym_RBRACK,
    STATE(46), 1,
      aux_sym_members_repeat1,
  [756] = 3,
    ACTIONS(130), 1,
      anon_sym_COMMA,
    ACTIONS(133), 1,
      anon_sym_RBRACE,
    STATE(38), 1,
      aux_sym_record_repeat1,
  [766] = 3,
    ACTIONS(135), 1,
      anon_sym_COMMA,
    ACTIONS(138), 1,
      anon_sym_RBRACK,
    STATE(39), 1,
      aux_sym_members_repeat1,
  [776] = 3,
    ACTIONS(140), 1,
      anon_sym_COMMA,
    ACTIONS(142), 1,
      anon_sym_RBRACE,
    STATE(42), 1,
      aux_sym_record_repeat1,
  [786] = 3,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    STATE(4), 1,
      sym_node,
    STATE(29), 1,
      sym_path,
  [796] = 3,
    ACTIONS(140), 1,
      anon_sym_COMMA,
    ACTIONS(144), 1,
      anon_sym_RBRACE,
    STATE(38), 1,
      aux_sym_record_repeat1,
  [806] = 3,
    ACTIONS(146), 1,
      anon_sym_LBRACK,
    ACTIONS(148), 1,
      anon_sym_DASH,
    ACTIONS(150), 1,
      anon_sym_DASH_GT,
  [816] = 2,
    ACTIONS(122), 1,
      sym_symbol,
    STATE(40), 2,
      sym_value_pair,
      sym_type_pair,
  [824] = 3,
    ACTIONS(49), 1,
      anon_sym_PIPE,
    ACTIONS(152), 1,
      anon_sym_RBRACK,
    STATE(81), 1,
      sym_members,
  [834] = 3,
    ACTIONS(126), 1,
      anon_sym_COMMA,
    ACTIONS(154), 1,
      anon_sym_RBRACK,
    STATE(39), 1,
      aux_sym_members_repeat1,
  [844] = 1,
    ACTIONS(156), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_PIPE,
  [850] = 1,
    ACTIONS(158), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_PIPE,
  [856] = 3,
    ACTIONS(160), 1,
      anon_sym_LBRACK,
    ACTIONS(162), 1,
      anon_sym_EQ,
    ACTIONS(164), 1,
      aux_sym_double_arrow_right_token1,
  [866] = 3,
    ACTIONS(166), 1,
      anon_sym_LBRACK,
    ACTIONS(168), 1,
      anon_sym_TILDE,
    ACTIONS(170), 1,
      anon_sym_TILDE_GT,
  [876] = 2,
    ACTIONS(172), 1,
      anon_sym_EQ,
    ACTIONS(174), 1,
      aux_sym_double_arrow_right_token1,
  [883] = 2,
    ACTIONS(176), 1,
      anon_sym_DASH,
    ACTIONS(178), 1,
      anon_sym_DASH_GT,
  [890] = 2,
    ACTIONS(180), 1,
      anon_sym_LBRACK,
    ACTIONS(182), 1,
      anon_sym_EQ,
  [897] = 2,
    ACTIONS(184), 1,
      anon_sym_LBRACK,
    ACTIONS(186), 1,
      anon_sym_TILDE,
  [904] = 2,
    ACTIONS(188), 1,
      anon_sym_TILDE,
    ACTIONS(190), 1,
      anon_sym_TILDE_GT,
  [911] = 2,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    STATE(16), 1,
      sym_node,
  [918] = 2,
    ACTIONS(192), 1,
      anon_sym_LBRACK,
    ACTIONS(194), 1,
      anon_sym_DASH,
  [925] = 1,
    ACTIONS(196), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [930] = 1,
    ACTIONS(198), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [935] = 1,
    ACTIONS(133), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [940] = 2,
    ACTIONS(200), 1,
      anon_sym_COLON,
    ACTIONS(202), 1,
      anon_sym_COLON_COLON,
  [947] = 1,
    ACTIONS(138), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [952] = 1,
    ACTIONS(204), 1,
      anon_sym_LPAREN,
  [956] = 1,
    ACTIONS(206), 1,
      anon_sym_LPAREN,
  [960] = 1,
    ACTIONS(208), 1,
      anon_sym_LPAREN,
  [964] = 1,
    ACTIONS(210), 1,
      anon_sym_LPAREN,
  [968] = 1,
    ACTIONS(212), 1,
      anon_sym_LPAREN,
  [972] = 1,
    ACTIONS(214), 1,
      anon_sym_LPAREN,
  [976] = 1,
    ACTIONS(216), 1,
      anon_sym_LPAREN,
  [980] = 1,
    ACTIONS(218), 1,
      anon_sym_LPAREN,
  [984] = 1,
    ACTIONS(220), 1,
      sym_symbol,
  [988] = 1,
    ACTIONS(222), 1,
      anon_sym_RBRACK,
  [992] = 1,
    ACTIONS(224), 1,
      anon_sym_RBRACK,
  [996] = 1,
    ACTIONS(226), 1,
      anon_sym_RBRACK,
  [1000] = 1,
    ACTIONS(228), 1,
      anon_sym_RBRACK,
  [1004] = 1,
    ACTIONS(230), 1,
      anon_sym_RBRACK,
  [1008] = 1,
    ACTIONS(232), 1,
      anon_sym_RBRACK,
  [1012] = 1,
    ACTIONS(234), 1,
      anon_sym_LPAREN,
  [1016] = 1,
    ACTIONS(236), 1,
      ts_builtin_sym_end,
  [1020] = 1,
    ACTIONS(238), 1,
      sym_symbol,
  [1024] = 1,
    ACTIONS(240), 1,
      anon_sym_RBRACK,
  [1028] = 1,
    ACTIONS(152), 1,
      anon_sym_RBRACK,
  [1032] = 1,
    ACTIONS(242), 1,
      anon_sym_DASH,
  [1036] = 1,
    ACTIONS(244), 1,
      anon_sym_RPAREN,
  [1040] = 1,
    ACTIONS(246), 1,
      anon_sym_EQ,
  [1044] = 1,
    ACTIONS(248), 1,
      sym_symbol,
  [1048] = 1,
    ACTIONS(250), 1,
      anon_sym_TILDE,
  [1052] = 1,
    ACTIONS(252), 1,
      anon_sym_LPAREN,
  [1056] = 1,
    ACTIONS(254), 1,
      anon_sym_LPAREN,
  [1060] = 1,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
  [1064] = 1,
    ACTIONS(258), 1,
      anon_sym_LPAREN,
  [1068] = 1,
    ACTIONS(260), 1,
      anon_sym_LPAREN,
  [1072] = 1,
    ACTIONS(262), 1,
      anon_sym_LPAREN,
  [1076] = 1,
    ACTIONS(264), 1,
      anon_sym_LPAREN,
  [1080] = 1,
    ACTIONS(266), 1,
      anon_sym_LPAREN,
  [1084] = 1,
    ACTIONS(268), 1,
      anon_sym_LPAREN,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 42,
  [SMALL_STATE(4)] = 84,
  [SMALL_STATE(5)] = 126,
  [SMALL_STATE(6)] = 170,
  [SMALL_STATE(7)] = 208,
  [SMALL_STATE(8)] = 243,
  [SMALL_STATE(9)] = 278,
  [SMALL_STATE(10)] = 313,
  [SMALL_STATE(11)] = 348,
  [SMALL_STATE(12)] = 383,
  [SMALL_STATE(13)] = 418,
  [SMALL_STATE(14)] = 446,
  [SMALL_STATE(15)] = 474,
  [SMALL_STATE(16)] = 494,
  [SMALL_STATE(17)] = 509,
  [SMALL_STATE(18)] = 524,
  [SMALL_STATE(19)] = 539,
  [SMALL_STATE(20)] = 564,
  [SMALL_STATE(21)] = 589,
  [SMALL_STATE(22)] = 599,
  [SMALL_STATE(23)] = 609,
  [SMALL_STATE(24)] = 622,
  [SMALL_STATE(25)] = 635,
  [SMALL_STATE(26)] = 648,
  [SMALL_STATE(27)] = 660,
  [SMALL_STATE(28)] = 672,
  [SMALL_STATE(29)] = 684,
  [SMALL_STATE(30)] = 692,
  [SMALL_STATE(31)] = 704,
  [SMALL_STATE(32)] = 711,
  [SMALL_STATE(33)] = 718,
  [SMALL_STATE(34)] = 725,
  [SMALL_STATE(35)] = 732,
  [SMALL_STATE(36)] = 740,
  [SMALL_STATE(37)] = 746,
  [SMALL_STATE(38)] = 756,
  [SMALL_STATE(39)] = 766,
  [SMALL_STATE(40)] = 776,
  [SMALL_STATE(41)] = 786,
  [SMALL_STATE(42)] = 796,
  [SMALL_STATE(43)] = 806,
  [SMALL_STATE(44)] = 816,
  [SMALL_STATE(45)] = 824,
  [SMALL_STATE(46)] = 834,
  [SMALL_STATE(47)] = 844,
  [SMALL_STATE(48)] = 850,
  [SMALL_STATE(49)] = 856,
  [SMALL_STATE(50)] = 866,
  [SMALL_STATE(51)] = 876,
  [SMALL_STATE(52)] = 883,
  [SMALL_STATE(53)] = 890,
  [SMALL_STATE(54)] = 897,
  [SMALL_STATE(55)] = 904,
  [SMALL_STATE(56)] = 911,
  [SMALL_STATE(57)] = 918,
  [SMALL_STATE(58)] = 925,
  [SMALL_STATE(59)] = 930,
  [SMALL_STATE(60)] = 935,
  [SMALL_STATE(61)] = 940,
  [SMALL_STATE(62)] = 947,
  [SMALL_STATE(63)] = 952,
  [SMALL_STATE(64)] = 956,
  [SMALL_STATE(65)] = 960,
  [SMALL_STATE(66)] = 964,
  [SMALL_STATE(67)] = 968,
  [SMALL_STATE(68)] = 972,
  [SMALL_STATE(69)] = 976,
  [SMALL_STATE(70)] = 980,
  [SMALL_STATE(71)] = 984,
  [SMALL_STATE(72)] = 988,
  [SMALL_STATE(73)] = 992,
  [SMALL_STATE(74)] = 996,
  [SMALL_STATE(75)] = 1000,
  [SMALL_STATE(76)] = 1004,
  [SMALL_STATE(77)] = 1008,
  [SMALL_STATE(78)] = 1012,
  [SMALL_STATE(79)] = 1016,
  [SMALL_STATE(80)] = 1020,
  [SMALL_STATE(81)] = 1024,
  [SMALL_STATE(82)] = 1028,
  [SMALL_STATE(83)] = 1032,
  [SMALL_STATE(84)] = 1036,
  [SMALL_STATE(85)] = 1040,
  [SMALL_STATE(86)] = 1044,
  [SMALL_STATE(87)] = 1048,
  [SMALL_STATE(88)] = 1052,
  [SMALL_STATE(89)] = 1056,
  [SMALL_STATE(90)] = 1060,
  [SMALL_STATE(91)] = 1064,
  [SMALL_STATE(92)] = 1068,
  [SMALL_STATE(93)] = 1072,
  [SMALL_STATE(94)] = 1076,
  [SMALL_STATE(95)] = 1080,
  [SMALL_STATE(96)] = 1084,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_gram, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_path, 2),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_path_repeat1, 2),
  [27] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_path_repeat1, 2), SHIFT_REPEAT(43),
  [30] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_path_repeat1, 2), SHIFT_REPEAT(57),
  [33] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_path_repeat1, 2), SHIFT_REPEAT(49),
  [36] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_path_repeat1, 2), SHIFT_REPEAT(53),
  [39] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_path_repeat1, 2), SHIFT_REPEAT(50),
  [42] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_path_repeat1, 2), SHIFT_REPEAT(54),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_path, 1),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [53] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [59] = {.entry = {.count = 1, .reusable = false}}, SHIFT(62),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [63] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [67] = {.entry = {.count = 1, .reusable = false}}, SHIFT(58),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 2),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 3),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2),
  [77] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2), SHIFT_REPEAT(6),
  [80] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2), SHIFT_REPEAT(5),
  [83] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2), SHIFT_REPEAT(44),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_gram, 1),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record, 4),
  [90] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record, 3),
  [92] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pattern, 2),
  [94] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pattern, 1),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pattern_repeat1, 2),
  [100] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_pattern_repeat1, 2), SHIFT_REPEAT(41),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_labels_repeat1, 2),
  [105] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_labels_repeat1, 2), SHIFT_REPEAT(71),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_labels, 3),
  [110] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attributes, 1, .production_id = 1),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_labels, 2),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_series, 4),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_series, 2),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_series, 3),
  [122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attributes, 1, .production_id = 2),
  [126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_members, 2),
  [130] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_record_repeat1, 2), SHIFT_REPEAT(35),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_record_repeat1, 2),
  [135] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_members_repeat1, 2), SHIFT_REPEAT(13),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_members_repeat1, 2),
  [140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [142] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [144] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [146] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [148] = {.entry = {.count = 1, .reusable = false}}, SHIFT(64),
  [150] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_members, 3),
  [156] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attributes, 1, .production_id = 3),
  [158] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attributes, 2, .production_id = 4),
  [160] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [162] = {.entry = {.count = 1, .reusable = false}}, SHIFT(67),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [168] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [172] = {.entry = {.count = 1, .reusable = false}}, SHIFT(91),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [176] = {.entry = {.count = 1, .reusable = false}}, SHIFT(88),
  [178] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [182] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [188] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [192] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_pair, 3, .production_id = 5),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_pair, 3, .production_id = 6),
  [200] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [202] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_arrow_right, 2),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_single, 2),
  [208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_squiggle, 2),
  [210] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_arrow_right, 2),
  [212] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_double_arrow, 2),
  [214] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_arrow_left, 2),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_arrow_right, 2),
  [218] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_arrow_left, 2),
  [220] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [224] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [234] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_arrow_left, 2),
  [236] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [246] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [248] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [252] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_single, 5),
  [254] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_arrow_right, 5),
  [256] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_arrow_left, 5),
  [258] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_double_arrow, 5),
  [260] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_arrow_right, 5),
  [262] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_arrow_left, 5),
  [264] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_squiggle, 5),
  [266] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_arrow_right, 5),
  [268] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_arrow_left, 5),
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
