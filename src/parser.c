#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 82
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 53
#define ALIAS_COUNT 0
#define TOKEN_COUNT 26
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 5
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 6

enum ts_symbol_identifiers {
  anon_sym_COMMA = 1,
  anon_sym_LPAREN = 2,
  anon_sym_RPAREN = 3,
  anon_sym_COLON = 4,
  anon_sym_LBRACE = 5,
  anon_sym_RBRACE = 6,
  sym_symbol = 7,
  sym_integer = 8,
  sym_decimal = 9,
  sym_hexadecimal = 10,
  sym_octal = 11,
  sym_single_quoted_string = 12,
  sym_double_quoted_string = 13,
  sym_backticked_string = 14,
  anon_sym_DASH = 15,
  anon_sym_LBRACK = 16,
  anon_sym_RBRACK = 17,
  anon_sym_DASH_GT = 18,
  anon_sym_LT_DASH = 19,
  anon_sym_EQ = 20,
  aux_sym_double_arrow_right_token1 = 21,
  aux_sym_double_arrow_left_token1 = 22,
  anon_sym_TILDE = 23,
  anon_sym_TILDE_GT = 24,
  anon_sym_LT_TILDE = 25,
  sym_gram = 26,
  sym_pattern = 27,
  sym_part = 28,
  sym_node = 29,
  sym_attributes = 30,
  sym__identifier = 31,
  sym_labels = 32,
  sym_record = 33,
  sym_pair = 34,
  sym__value = 35,
  sym__numeric_literal = 36,
  sym__string_literal = 37,
  sym__relationship = 38,
  sym_undirected_single = 39,
  sym_single_arrow_right = 40,
  sym_single_arrow_left = 41,
  sym_undirected_double_arrow = 42,
  sym_double_arrow_right = 43,
  sym_double_arrow_left = 44,
  sym_undirected_squiggle = 45,
  sym_squiggle_arrow_right = 46,
  sym_squiggle_arrow_left = 47,
  aux_sym_gram_repeat1 = 48,
  aux_sym_pattern_repeat1 = 49,
  aux_sym_part_repeat1 = 50,
  aux_sym_labels_repeat1 = 51,
  aux_sym_record_repeat1 = 52,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_COMMA] = ",",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_COLON] = ":",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [sym_symbol] = "symbol",
  [sym_integer] = "integer",
  [sym_decimal] = "decimal",
  [sym_hexadecimal] = "hexadecimal",
  [sym_octal] = "octal",
  [sym_single_quoted_string] = "single_quoted_string",
  [sym_double_quoted_string] = "double_quoted_string",
  [sym_backticked_string] = "backticked_string",
  [anon_sym_DASH] = "-",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
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
  [sym_part] = "part",
  [sym_node] = "node",
  [sym_attributes] = "attributes",
  [sym__identifier] = "_identifier",
  [sym_labels] = "labels",
  [sym_record] = "record",
  [sym_pair] = "pair",
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
  [aux_sym_part_repeat1] = "part_repeat1",
  [aux_sym_labels_repeat1] = "labels_repeat1",
  [aux_sym_record_repeat1] = "record_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [sym_symbol] = sym_symbol,
  [sym_integer] = sym_integer,
  [sym_decimal] = sym_decimal,
  [sym_hexadecimal] = sym_hexadecimal,
  [sym_octal] = sym_octal,
  [sym_single_quoted_string] = sym_single_quoted_string,
  [sym_double_quoted_string] = sym_double_quoted_string,
  [sym_backticked_string] = sym_backticked_string,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
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
  [sym_part] = sym_part,
  [sym_node] = sym_node,
  [sym_attributes] = sym_attributes,
  [sym__identifier] = sym__identifier,
  [sym_labels] = sym_labels,
  [sym_record] = sym_record,
  [sym_pair] = sym_pair,
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
  [aux_sym_part_repeat1] = aux_sym_part_repeat1,
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
  [anon_sym_DASH] = {
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
  [sym_part] = {
    .visible = true,
    .named = true,
  },
  [sym_node] = {
    .visible = true,
    .named = true,
  },
  [sym_attributes] = {
    .visible = true,
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
  [sym_pair] = {
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
  [aux_sym_part_repeat1] = {
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
  field_value = 5,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_identifier] = "identifier",
  [field_key] = "key",
  [field_labels] = "labels",
  [field_record] = "record",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 2},
  [5] = {.index = 5, .length = 2},
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(18);
      if (lookahead == '"') ADVANCE(2);
      if (lookahead == '\'') ADVANCE(4);
      if (lookahead == '(') ADVANCE(20);
      if (lookahead == ')') ADVANCE(21);
      if (lookahead == ',') ADVANCE(19);
      if (lookahead == '-') ADVANCE(41);
      if (lookahead == '0') ADVANCE(25);
      if (lookahead == ':') ADVANCE(22);
      if (lookahead == '<') ADVANCE(6);
      if (lookahead == '=') ADVANCE(48);
      if (lookahead == '>') ADVANCE(10);
      if (lookahead == '[') ADVANCE(43);
      if (lookahead == ']') ADVANCE(44);
      if (lookahead == '`') ADVANCE(12);
      if (lookahead == 'o') ADVANCE(27);
      if (lookahead == '{') ADVANCE(23);
      if (lookahead == '}') ADVANCE(24);
      if (lookahead == '~') ADVANCE(53);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(26);
      if (lookahead == '.' ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(2);
      if (lookahead == '\'') ADVANCE(4);
      if (lookahead == '-') ADVANCE(9);
      if (lookahead == '0') ADVANCE(8);
      if (lookahead == '`') ADVANCE(12);
      if (lookahead == 'o') ADVANCE(14);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(31);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(37);
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(38);
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 4:
      if (lookahead == '\'') ADVANCE(35);
      if (lookahead == '\\') ADVANCE(5);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 5:
      if (lookahead == '\'') ADVANCE(36);
      if (lookahead == '\\') ADVANCE(5);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 6:
      if (lookahead == '-') ADVANCE(46);
      if (lookahead == '=') ADVANCE(51);
      if (lookahead == '~') ADVANCE(55);
      END_STATE();
    case 7:
      if (lookahead == '.') ADVANCE(15);
      END_STATE();
    case 8:
      if (lookahead == '.') ADVANCE(15);
      if (lookahead == 'x') ADVANCE(16);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(34);
      END_STATE();
    case 9:
      if (lookahead == '0') ADVANCE(7);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(31);
      END_STATE();
    case 10:
      if (lookahead == '=') ADVANCE(11);
      END_STATE();
    case 11:
      if (lookahead == '>') ADVANCE(49);
      END_STATE();
    case 12:
      if (lookahead == '\\') ADVANCE(13);
      if (lookahead == '`') ADVANCE(39);
      if (lookahead != 0) ADVANCE(12);
      END_STATE();
    case 13:
      if (lookahead == '\\') ADVANCE(13);
      if (lookahead == '`') ADVANCE(40);
      if (lookahead != 0) ADVANCE(12);
      END_STATE();
    case 14:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(34);
      END_STATE();
    case 15:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(32);
      END_STATE();
    case 16:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(33);
      END_STATE();
    case 17:
      if (eof) ADVANCE(18);
      if (lookahead == '"') ADVANCE(2);
      if (lookahead == '\'') ADVANCE(4);
      if (lookahead == '(') ADVANCE(20);
      if (lookahead == ')') ADVANCE(21);
      if (lookahead == ',') ADVANCE(19);
      if (lookahead == '-') ADVANCE(42);
      if (lookahead == ':') ADVANCE(22);
      if (lookahead == '<') ADVANCE(6);
      if (lookahead == '=') ADVANCE(47);
      if (lookahead == '[') ADVANCE(43);
      if (lookahead == '`') ADVANCE(12);
      if (lookahead == '{') ADVANCE(23);
      if (lookahead == '~') ADVANCE(52);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(17)
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.') ADVANCE(28);
      if (lookahead == 'x') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(27);
      if (lookahead == '8' ||
          lookahead == '9' ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.') ADVANCE(28);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(26);
      if (('@' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym_symbol);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(27);
      if (lookahead == '.' ||
          lookahead == '8' ||
          lookahead == '9' ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_symbol);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(28);
      if (lookahead == '.' ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_symbol);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(29);
      if (lookahead == '.' ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(15);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(31);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_decimal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(32);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_hexadecimal);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(33);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_octal);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(34);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_single_quoted_string);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_single_quoted_string);
      if (lookahead == '\'') ADVANCE(35);
      if (lookahead == '\\') ADVANCE(5);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_double_quoted_string);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_double_quoted_string);
      if (lookahead == '"') ADVANCE(37);
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_backticked_string);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_backticked_string);
      if (lookahead == '\\') ADVANCE(13);
      if (lookahead == '`') ADVANCE(39);
      if (lookahead != 0) ADVANCE(12);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '0') ADVANCE(7);
      if (lookahead == '>') ADVANCE(45);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(31);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '>') ADVANCE(45);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_LT_DASH);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '>') ADVANCE(49);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(aux_sym_double_arrow_right_token1);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(aux_sym_double_arrow_left_token1);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(aux_sym_double_arrow_left_token1);
      if (lookahead == '<') ADVANCE(50);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_TILDE);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_TILDE);
      if (lookahead == '>') ADVANCE(54);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_TILDE_GT);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_LT_TILDE);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 17},
  [3] = {.lex_state = 17},
  [4] = {.lex_state = 17},
  [5] = {.lex_state = 17},
  [6] = {.lex_state = 17},
  [7] = {.lex_state = 17},
  [8] = {.lex_state = 17},
  [9] = {.lex_state = 17},
  [10] = {.lex_state = 17},
  [11] = {.lex_state = 17},
  [12] = {.lex_state = 1},
  [13] = {.lex_state = 17},
  [14] = {.lex_state = 17},
  [15] = {.lex_state = 17},
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
  [33] = {.lex_state = 17},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 17},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 17},
  [41] = {.lex_state = 17},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 17},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 17},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 17},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 17},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 17},
  [71] = {.lex_state = 17},
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
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [sym_symbol] = ACTIONS(1),
    [sym_integer] = ACTIONS(1),
    [sym_decimal] = ACTIONS(1),
    [sym_hexadecimal] = ACTIONS(1),
    [sym_octal] = ACTIONS(1),
    [sym_single_quoted_string] = ACTIONS(1),
    [sym_double_quoted_string] = ACTIONS(1),
    [sym_backticked_string] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
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
    [sym_gram] = STATE(63),
    [sym_pattern] = STATE(17),
    [sym_part] = STATE(19),
    [sym_node] = STATE(4),
    [aux_sym_gram_repeat1] = STATE(17),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 9,
    ACTIONS(9), 1,
      anon_sym_DASH,
    ACTIONS(11), 1,
      anon_sym_LT_DASH,
    ACTIONS(13), 1,
      anon_sym_EQ,
    ACTIONS(15), 1,
      aux_sym_double_arrow_left_token1,
    ACTIONS(17), 1,
      anon_sym_TILDE,
    ACTIONS(19), 1,
      anon_sym_LT_TILDE,
    STATE(3), 1,
      aux_sym_part_repeat1,
    ACTIONS(7), 3,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
    STATE(48), 10,
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
  [39] = 9,
    ACTIONS(23), 1,
      anon_sym_DASH,
    ACTIONS(26), 1,
      anon_sym_LT_DASH,
    ACTIONS(29), 1,
      anon_sym_EQ,
    ACTIONS(32), 1,
      aux_sym_double_arrow_left_token1,
    ACTIONS(35), 1,
      anon_sym_TILDE,
    ACTIONS(38), 1,
      anon_sym_LT_TILDE,
    STATE(3), 1,
      aux_sym_part_repeat1,
    ACTIONS(21), 3,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
    STATE(48), 10,
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
  [78] = 9,
    ACTIONS(9), 1,
      anon_sym_DASH,
    ACTIONS(11), 1,
      anon_sym_LT_DASH,
    ACTIONS(13), 1,
      anon_sym_EQ,
    ACTIONS(15), 1,
      aux_sym_double_arrow_left_token1,
    ACTIONS(17), 1,
      anon_sym_TILDE,
    ACTIONS(19), 1,
      anon_sym_LT_TILDE,
    STATE(2), 1,
      aux_sym_part_repeat1,
    ACTIONS(41), 3,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
    STATE(48), 10,
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
  [117] = 8,
    ACTIONS(43), 1,
      anon_sym_RPAREN,
    ACTIONS(45), 1,
      anon_sym_COLON,
    ACTIONS(47), 1,
      anon_sym_LBRACE,
    STATE(37), 1,
      sym_record,
    STATE(38), 1,
      sym_labels,
    STATE(69), 1,
      sym_attributes,
    STATE(23), 2,
      sym__identifier,
      sym__string_literal,
    ACTIONS(49), 4,
      sym_symbol,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
  [146] = 7,
    ACTIONS(45), 1,
      anon_sym_COLON,
    ACTIONS(47), 1,
      anon_sym_LBRACE,
    STATE(37), 1,
      sym_record,
    STATE(38), 1,
      sym_labels,
    STATE(60), 1,
      sym_attributes,
    STATE(23), 2,
      sym__identifier,
      sym__string_literal,
    ACTIONS(49), 4,
      sym_symbol,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
  [172] = 7,
    ACTIONS(45), 1,
      anon_sym_COLON,
    ACTIONS(47), 1,
      anon_sym_LBRACE,
    STATE(37), 1,
      sym_record,
    STATE(38), 1,
      sym_labels,
    STATE(59), 1,
      sym_attributes,
    STATE(23), 2,
      sym__identifier,
      sym__string_literal,
    ACTIONS(49), 4,
      sym_symbol,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
  [198] = 7,
    ACTIONS(45), 1,
      anon_sym_COLON,
    ACTIONS(47), 1,
      anon_sym_LBRACE,
    STATE(37), 1,
      sym_record,
    STATE(38), 1,
      sym_labels,
    STATE(58), 1,
      sym_attributes,
    STATE(23), 2,
      sym__identifier,
      sym__string_literal,
    ACTIONS(49), 4,
      sym_symbol,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
  [224] = 7,
    ACTIONS(45), 1,
      anon_sym_COLON,
    ACTIONS(47), 1,
      anon_sym_LBRACE,
    STATE(37), 1,
      sym_record,
    STATE(38), 1,
      sym_labels,
    STATE(57), 1,
      sym_attributes,
    STATE(23), 2,
      sym__identifier,
      sym__string_literal,
    ACTIONS(49), 4,
      sym_symbol,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
  [250] = 7,
    ACTIONS(45), 1,
      anon_sym_COLON,
    ACTIONS(47), 1,
      anon_sym_LBRACE,
    STATE(37), 1,
      sym_record,
    STATE(38), 1,
      sym_labels,
    STATE(56), 1,
      sym_attributes,
    STATE(23), 2,
      sym__identifier,
      sym__string_literal,
    ACTIONS(49), 4,
      sym_symbol,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
  [276] = 7,
    ACTIONS(45), 1,
      anon_sym_COLON,
    ACTIONS(47), 1,
      anon_sym_LBRACE,
    STATE(37), 1,
      sym_record,
    STATE(38), 1,
      sym_labels,
    STATE(55), 1,
      sym_attributes,
    STATE(23), 2,
      sym__identifier,
      sym__string_literal,
    ACTIONS(49), 4,
      sym_symbol,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
  [302] = 3,
    ACTIONS(51), 1,
      sym_integer,
    STATE(34), 3,
      sym__value,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(53), 6,
      sym_decimal,
      sym_hexadecimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
  [319] = 1,
    ACTIONS(21), 9,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_LT_DASH,
      anon_sym_EQ,
      aux_sym_double_arrow_left_token1,
      anon_sym_TILDE,
      anon_sym_LT_TILDE,
  [331] = 1,
    ACTIONS(55), 9,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_LT_DASH,
      anon_sym_EQ,
      aux_sym_double_arrow_left_token1,
      anon_sym_TILDE,
      anon_sym_LT_TILDE,
  [343] = 1,
    ACTIONS(57), 9,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_LT_DASH,
      anon_sym_EQ,
      aux_sym_double_arrow_left_token1,
      anon_sym_TILDE,
      anon_sym_LT_TILDE,
  [355] = 5,
    ACTIONS(59), 1,
      ts_builtin_sym_end,
    ACTIONS(61), 1,
      anon_sym_LPAREN,
    STATE(4), 1,
      sym_node,
    STATE(19), 1,
      sym_part,
    STATE(16), 2,
      sym_pattern,
      aux_sym_gram_repeat1,
  [372] = 5,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    ACTIONS(64), 1,
      ts_builtin_sym_end,
    STATE(4), 1,
      sym_node,
    STATE(19), 1,
      sym_part,
    STATE(16), 2,
      sym_pattern,
      aux_sym_gram_repeat1,
  [389] = 3,
    ACTIONS(68), 1,
      anon_sym_COMMA,
    STATE(24), 1,
      aux_sym_pattern_repeat1,
    ACTIONS(66), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [400] = 3,
    ACTIONS(68), 1,
      anon_sym_COMMA,
    STATE(18), 1,
      aux_sym_pattern_repeat1,
    ACTIONS(70), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [411] = 3,
    ACTIONS(74), 1,
      anon_sym_COLON,
    STATE(20), 1,
      aux_sym_labels_repeat1,
    ACTIONS(72), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [422] = 3,
    ACTIONS(79), 1,
      anon_sym_COLON,
    STATE(22), 1,
      aux_sym_labels_repeat1,
    ACTIONS(77), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [433] = 3,
    ACTIONS(79), 1,
      anon_sym_COLON,
    STATE(20), 1,
      aux_sym_labels_repeat1,
    ACTIONS(81), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [444] = 3,
    ACTIONS(45), 1,
      anon_sym_COLON,
    STATE(39), 1,
      sym_labels,
    ACTIONS(83), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [455] = 3,
    ACTIONS(87), 1,
      anon_sym_COMMA,
    STATE(24), 1,
      aux_sym_pattern_repeat1,
    ACTIONS(85), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [466] = 3,
    ACTIONS(90), 1,
      anon_sym_COMMA,
    ACTIONS(93), 1,
      anon_sym_RBRACE,
    STATE(25), 1,
      aux_sym_record_repeat1,
  [476] = 1,
    ACTIONS(72), 3,
      anon_sym_RPAREN,
      anon_sym_COLON,
      anon_sym_RBRACK,
  [482] = 3,
    ACTIONS(95), 1,
      anon_sym_LBRACK,
    ACTIONS(97), 1,
      anon_sym_TILDE,
    ACTIONS(99), 1,
      anon_sym_TILDE_GT,
  [492] = 3,
    ACTIONS(101), 1,
      anon_sym_COMMA,
    ACTIONS(103), 1,
      anon_sym_RBRACE,
    STATE(25), 1,
      aux_sym_record_repeat1,
  [502] = 3,
    ACTIONS(101), 1,
      anon_sym_COMMA,
    ACTIONS(105), 1,
      anon_sym_RBRACE,
    STATE(28), 1,
      aux_sym_record_repeat1,
  [512] = 3,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    STATE(4), 1,
      sym_node,
    STATE(31), 1,
      sym_part,
  [522] = 1,
    ACTIONS(85), 3,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
  [528] = 3,
    ACTIONS(107), 1,
      anon_sym_LBRACK,
    ACTIONS(109), 1,
      anon_sym_EQ,
    ACTIONS(111), 1,
      aux_sym_double_arrow_right_token1,
  [538] = 3,
    ACTIONS(113), 1,
      anon_sym_DASH,
    ACTIONS(115), 1,
      anon_sym_LBRACK,
    ACTIONS(117), 1,
      anon_sym_DASH_GT,
  [548] = 1,
    ACTIONS(119), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [553] = 2,
    ACTIONS(121), 1,
      anon_sym_LBRACK,
    ACTIONS(123), 1,
      anon_sym_EQ,
  [560] = 1,
    ACTIONS(125), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [565] = 1,
    ACTIONS(127), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [570] = 1,
    ACTIONS(129), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [575] = 1,
    ACTIONS(131), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [580] = 2,
    ACTIONS(133), 1,
      anon_sym_DASH,
    ACTIONS(135), 1,
      anon_sym_DASH_GT,
  [587] = 2,
    ACTIONS(137), 1,
      sym_symbol,
    STATE(29), 1,
      sym_pair,
  [594] = 2,
    ACTIONS(139), 1,
      anon_sym_EQ,
    ACTIONS(141), 1,
      aux_sym_double_arrow_right_token1,
  [601] = 2,
    ACTIONS(143), 1,
      anon_sym_DASH,
    ACTIONS(145), 1,
      anon_sym_LBRACK,
  [608] = 2,
    ACTIONS(147), 1,
      anon_sym_TILDE,
    ACTIONS(149), 1,
      anon_sym_TILDE_GT,
  [615] = 1,
    ACTIONS(93), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [620] = 2,
    ACTIONS(137), 1,
      sym_symbol,
    STATE(45), 1,
      sym_pair,
  [627] = 1,
    ACTIONS(151), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [632] = 2,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    STATE(13), 1,
      sym_node,
  [639] = 2,
    ACTIONS(153), 1,
      anon_sym_LBRACK,
    ACTIONS(155), 1,
      anon_sym_TILDE,
  [646] = 1,
    ACTIONS(157), 1,
      anon_sym_LPAREN,
  [650] = 1,
    ACTIONS(159), 1,
      anon_sym_LPAREN,
  [654] = 1,
    ACTIONS(161), 1,
      anon_sym_LPAREN,
  [658] = 1,
    ACTIONS(163), 1,
      anon_sym_LPAREN,
  [662] = 1,
    ACTIONS(165), 1,
      anon_sym_LPAREN,
  [666] = 1,
    ACTIONS(167), 1,
      anon_sym_RBRACK,
  [670] = 1,
    ACTIONS(169), 1,
      anon_sym_RBRACK,
  [674] = 1,
    ACTIONS(171), 1,
      anon_sym_RBRACK,
  [678] = 1,
    ACTIONS(173), 1,
      anon_sym_RBRACK,
  [682] = 1,
    ACTIONS(175), 1,
      anon_sym_RBRACK,
  [686] = 1,
    ACTIONS(177), 1,
      anon_sym_RBRACK,
  [690] = 1,
    ACTIONS(179), 1,
      sym_symbol,
  [694] = 1,
    ACTIONS(181), 1,
      anon_sym_LPAREN,
  [698] = 1,
    ACTIONS(183), 1,
      ts_builtin_sym_end,
  [702] = 1,
    ACTIONS(185), 1,
      anon_sym_LPAREN,
  [706] = 1,
    ACTIONS(187), 1,
      anon_sym_LPAREN,
  [710] = 1,
    ACTIONS(189), 1,
      anon_sym_LPAREN,
  [714] = 1,
    ACTIONS(191), 1,
      anon_sym_COLON,
  [718] = 1,
    ACTIONS(193), 1,
      anon_sym_DASH,
  [722] = 1,
    ACTIONS(195), 1,
      anon_sym_RPAREN,
  [726] = 1,
    ACTIONS(197), 1,
      anon_sym_EQ,
  [730] = 1,
    ACTIONS(199), 1,
      sym_symbol,
  [734] = 1,
    ACTIONS(201), 1,
      anon_sym_TILDE,
  [738] = 1,
    ACTIONS(203), 1,
      anon_sym_LPAREN,
  [742] = 1,
    ACTIONS(205), 1,
      anon_sym_LPAREN,
  [746] = 1,
    ACTIONS(207), 1,
      anon_sym_LPAREN,
  [750] = 1,
    ACTIONS(209), 1,
      anon_sym_LPAREN,
  [754] = 1,
    ACTIONS(211), 1,
      anon_sym_LPAREN,
  [758] = 1,
    ACTIONS(213), 1,
      anon_sym_LPAREN,
  [762] = 1,
    ACTIONS(215), 1,
      anon_sym_LPAREN,
  [766] = 1,
    ACTIONS(217), 1,
      anon_sym_LPAREN,
  [770] = 1,
    ACTIONS(219), 1,
      anon_sym_LPAREN,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 39,
  [SMALL_STATE(4)] = 78,
  [SMALL_STATE(5)] = 117,
  [SMALL_STATE(6)] = 146,
  [SMALL_STATE(7)] = 172,
  [SMALL_STATE(8)] = 198,
  [SMALL_STATE(9)] = 224,
  [SMALL_STATE(10)] = 250,
  [SMALL_STATE(11)] = 276,
  [SMALL_STATE(12)] = 302,
  [SMALL_STATE(13)] = 319,
  [SMALL_STATE(14)] = 331,
  [SMALL_STATE(15)] = 343,
  [SMALL_STATE(16)] = 355,
  [SMALL_STATE(17)] = 372,
  [SMALL_STATE(18)] = 389,
  [SMALL_STATE(19)] = 400,
  [SMALL_STATE(20)] = 411,
  [SMALL_STATE(21)] = 422,
  [SMALL_STATE(22)] = 433,
  [SMALL_STATE(23)] = 444,
  [SMALL_STATE(24)] = 455,
  [SMALL_STATE(25)] = 466,
  [SMALL_STATE(26)] = 476,
  [SMALL_STATE(27)] = 482,
  [SMALL_STATE(28)] = 492,
  [SMALL_STATE(29)] = 502,
  [SMALL_STATE(30)] = 512,
  [SMALL_STATE(31)] = 522,
  [SMALL_STATE(32)] = 528,
  [SMALL_STATE(33)] = 538,
  [SMALL_STATE(34)] = 548,
  [SMALL_STATE(35)] = 553,
  [SMALL_STATE(36)] = 560,
  [SMALL_STATE(37)] = 565,
  [SMALL_STATE(38)] = 570,
  [SMALL_STATE(39)] = 575,
  [SMALL_STATE(40)] = 580,
  [SMALL_STATE(41)] = 587,
  [SMALL_STATE(42)] = 594,
  [SMALL_STATE(43)] = 601,
  [SMALL_STATE(44)] = 608,
  [SMALL_STATE(45)] = 615,
  [SMALL_STATE(46)] = 620,
  [SMALL_STATE(47)] = 627,
  [SMALL_STATE(48)] = 632,
  [SMALL_STATE(49)] = 639,
  [SMALL_STATE(50)] = 646,
  [SMALL_STATE(51)] = 650,
  [SMALL_STATE(52)] = 654,
  [SMALL_STATE(53)] = 658,
  [SMALL_STATE(54)] = 662,
  [SMALL_STATE(55)] = 666,
  [SMALL_STATE(56)] = 670,
  [SMALL_STATE(57)] = 674,
  [SMALL_STATE(58)] = 678,
  [SMALL_STATE(59)] = 682,
  [SMALL_STATE(60)] = 686,
  [SMALL_STATE(61)] = 690,
  [SMALL_STATE(62)] = 694,
  [SMALL_STATE(63)] = 698,
  [SMALL_STATE(64)] = 702,
  [SMALL_STATE(65)] = 706,
  [SMALL_STATE(66)] = 710,
  [SMALL_STATE(67)] = 714,
  [SMALL_STATE(68)] = 718,
  [SMALL_STATE(69)] = 722,
  [SMALL_STATE(70)] = 726,
  [SMALL_STATE(71)] = 730,
  [SMALL_STATE(72)] = 734,
  [SMALL_STATE(73)] = 738,
  [SMALL_STATE(74)] = 742,
  [SMALL_STATE(75)] = 746,
  [SMALL_STATE(76)] = 750,
  [SMALL_STATE(77)] = 754,
  [SMALL_STATE(78)] = 758,
  [SMALL_STATE(79)] = 762,
  [SMALL_STATE(80)] = 766,
  [SMALL_STATE(81)] = 770,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_gram, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_part, 2),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_part_repeat1, 2),
  [23] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_part_repeat1, 2), SHIFT_REPEAT(33),
  [26] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_part_repeat1, 2), SHIFT_REPEAT(43),
  [29] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_part_repeat1, 2), SHIFT_REPEAT(32),
  [32] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_part_repeat1, 2), SHIFT_REPEAT(35),
  [35] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_part_repeat1, 2), SHIFT_REPEAT(27),
  [38] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_part_repeat1, 2), SHIFT_REPEAT(49),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_part, 1),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [51] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 2),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 3),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2),
  [61] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2), SHIFT_REPEAT(5),
  [64] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_gram, 1),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pattern, 2),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pattern, 1),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_labels_repeat1, 2),
  [74] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_labels_repeat1, 2), SHIFT_REPEAT(61),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_labels, 2),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_labels, 3),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attributes, 1, .production_id = 1),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pattern_repeat1, 2),
  [87] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_pattern_repeat1, 2), SHIFT_REPEAT(30),
  [90] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_record_repeat1, 2), SHIFT_REPEAT(46),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_record_repeat1, 2),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [97] = {.entry = {.count = 1, .reusable = false}}, SHIFT(54),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [109] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [113] = {.entry = {.count = 1, .reusable = false}}, SHIFT(66),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pair, 3, .production_id = 5),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record, 4),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attributes, 1, .production_id = 3),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attributes, 1, .production_id = 2),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attributes, 2, .production_id = 4),
  [133] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [135] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [139] = {.entry = {.count = 1, .reusable = false}}, SHIFT(76),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [147] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record, 3),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_arrow_right, 2),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_arrow_left, 2),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_arrow_left, 2),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_double_arrow, 2),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_squiggle, 2),
  [167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_arrow_right, 2),
  [183] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_arrow_left, 2),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_arrow_right, 2),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_single, 2),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [197] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [203] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_single, 5),
  [205] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_arrow_right, 5),
  [207] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_arrow_left, 5),
  [209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_double_arrow, 5),
  [211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_arrow_right, 5),
  [213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_arrow_left, 5),
  [215] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_squiggle, 5),
  [217] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_arrow_right, 5),
  [219] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_arrow_left, 5),
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
