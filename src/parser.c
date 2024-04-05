#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 95
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 59
#define ALIAS_COUNT 0
#define TOKEN_COUNT 29
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 5
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 6

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
  sym_symbol = 10,
  sym_integer = 11,
  sym_decimal = 12,
  sym_hexadecimal = 13,
  sym_octal = 14,
  sym_measurement = 15,
  sym_single_quoted_string = 16,
  sym_double_quoted_string = 17,
  sym_backticked_string = 18,
  sym_tagged_string = 19,
  anon_sym_DASH = 20,
  anon_sym_DASH_GT = 21,
  anon_sym_LT_DASH = 22,
  anon_sym_EQ = 23,
  aux_sym_double_arrow_right_token1 = 24,
  aux_sym_double_arrow_left_token1 = 25,
  anon_sym_TILDE = 26,
  anon_sym_TILDE_GT = 27,
  anon_sym_LT_TILDE = 28,
  sym_gram = 29,
  sym_pattern = 30,
  sym_part = 31,
  sym_node = 32,
  sym_series = 33,
  sym_attributes = 34,
  sym_members = 35,
  sym__identifier = 36,
  sym_labels = 37,
  sym_record = 38,
  sym_pair = 39,
  sym__value = 40,
  sym__numeric_literal = 41,
  sym__string_literal = 42,
  sym__relationship = 43,
  sym_undirected_single = 44,
  sym_single_arrow_right = 45,
  sym_single_arrow_left = 46,
  sym_undirected_double_arrow = 47,
  sym_double_arrow_right = 48,
  sym_double_arrow_left = 49,
  sym_undirected_squiggle = 50,
  sym_squiggle_arrow_right = 51,
  sym_squiggle_arrow_left = 52,
  aux_sym_gram_repeat1 = 53,
  aux_sym_pattern_repeat1 = 54,
  aux_sym_part_repeat1 = 55,
  aux_sym_members_repeat1 = 56,
  aux_sym_labels_repeat1 = 57,
  aux_sym_record_repeat1 = 58,
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
  [sym_part] = "part",
  [sym_node] = "node",
  [sym_series] = "series",
  [sym_attributes] = "attributes",
  [sym_members] = "members",
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
  [sym_part] = sym_part,
  [sym_node] = sym_node,
  [sym_series] = sym_series,
  [sym_attributes] = sym_attributes,
  [sym_members] = sym_members,
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
  [sym_part] = {
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(17);
      if (lookahead == '"') ADVANCE(2);
      if (lookahead == '\'') ADVANCE(4);
      if (lookahead == '(') ADVANCE(19);
      if (lookahead == ')') ADVANCE(20);
      if (lookahead == ',') ADVANCE(18);
      if (lookahead == '-') ADVANCE(54);
      if (lookahead == '0') ADVANCE(27);
      if (lookahead == ':') ADVANCE(24);
      if (lookahead == '<') ADVANCE(6);
      if (lookahead == '=') ADVANCE(59);
      if (lookahead == '>') ADVANCE(8);
      if (lookahead == '[') ADVANCE(21);
      if (lookahead == ']') ADVANCE(22);
      if (lookahead == '`') ADVANCE(10);
      if (lookahead == 'o') ADVANCE(29);
      if (lookahead == '{') ADVANCE(25);
      if (lookahead == '|') ADVANCE(23);
      if (lookahead == '}') ADVANCE(26);
      if (lookahead == '~') ADVANCE(64);
      if (lookahead == '.' ||
          lookahead == '@' ||
          lookahead == '_') ADVANCE(36);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(28);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(2);
      if (lookahead == '\'') ADVANCE(4);
      if (lookahead == '-') ADVANCE(7);
      if (lookahead == '0') ADVANCE(37);
      if (lookahead == '`') ADVANCE(10);
      if (lookahead == 'o') ADVANCE(12);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(38);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(13);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(49);
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(50);
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 4:
      if (lookahead == '\'') ADVANCE(47);
      if (lookahead == '\\') ADVANCE(5);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 5:
      if (lookahead == '\'') ADVANCE(48);
      if (lookahead == '\\') ADVANCE(5);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 6:
      if (lookahead == '-') ADVANCE(57);
      if (lookahead == '=') ADVANCE(62);
      if (lookahead == '~') ADVANCE(66);
      END_STATE();
    case 7:
      if (lookahead == '0') ADVANCE(39);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(38);
      END_STATE();
    case 8:
      if (lookahead == '=') ADVANCE(9);
      END_STATE();
    case 9:
      if (lookahead == '>') ADVANCE(60);
      END_STATE();
    case 10:
      if (lookahead == '\\') ADVANCE(11);
      if (lookahead == '`') ADVANCE(51);
      if (lookahead != 0) ADVANCE(10);
      END_STATE();
    case 11:
      if (lookahead == '\\') ADVANCE(11);
      if (lookahead == '`') ADVANCE(52);
      if (lookahead != 0) ADVANCE(10);
      END_STATE();
    case 12:
      if (lookahead == '`') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(43);
      if (lookahead == '.' ||
          lookahead == '8' ||
          lookahead == '9' ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(13);
      END_STATE();
    case 13:
      if (lookahead == '`') ADVANCE(14);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(13);
      END_STATE();
    case 14:
      if (lookahead == '`') ADVANCE(53);
      if (lookahead != 0) ADVANCE(14);
      END_STATE();
    case 15:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(40);
      END_STATE();
    case 16:
      if (eof) ADVANCE(17);
      if (lookahead == '"') ADVANCE(2);
      if (lookahead == '\'') ADVANCE(4);
      if (lookahead == '(') ADVANCE(19);
      if (lookahead == ')') ADVANCE(20);
      if (lookahead == ',') ADVANCE(18);
      if (lookahead == '-') ADVANCE(55);
      if (lookahead == ':') ADVANCE(24);
      if (lookahead == '<') ADVANCE(6);
      if (lookahead == '=') ADVANCE(58);
      if (lookahead == '[') ADVANCE(21);
      if (lookahead == ']') ADVANCE(22);
      if (lookahead == '`') ADVANCE(10);
      if (lookahead == '{') ADVANCE(25);
      if (lookahead == '|') ADVANCE(23);
      if (lookahead == '~') ADVANCE(63);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(16)
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '@' ||
          lookahead == '_') ADVANCE(36);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.') ADVANCE(33);
      if (lookahead == 'x') ADVANCE(31);
      if (lookahead == '8' ||
          lookahead == '9' ||
          lookahead == '@' ||
          lookahead == '_') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(32);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(34);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.') ADVANCE(33);
      if (lookahead == '@' ||
          lookahead == '_') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(28);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(34);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '`') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(29);
      if (lookahead == '.' ||
          lookahead == '8' ||
          lookahead == '9' ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '`') ADVANCE(14);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.' ||
          lookahead == '@' ||
          lookahead == '_') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(35);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(31);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(34);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_symbol);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(32);
      if (lookahead == '.' ||
          lookahead == '8' ||
          lookahead == '9' ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_symbol);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(33);
      if (lookahead == '.' ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '@' ||
          lookahead == '_') ADVANCE(36);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(34);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_symbol);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(35);
      if (lookahead == '.' ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(15);
      if (lookahead == 'x') ADVANCE(45);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(44);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(46);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(15);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(38);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(46);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(15);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(46);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_decimal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(40);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_hexadecimal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(41);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(46);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_hexadecimal);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(42);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_octal);
      if (lookahead == '`') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(43);
      if (lookahead == '.' ||
          lookahead == '8' ||
          lookahead == '9' ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(13);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_octal);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(44);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_measurement);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(41);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(46);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_measurement);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(46);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_single_quoted_string);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_single_quoted_string);
      if (lookahead == '\'') ADVANCE(47);
      if (lookahead == '\\') ADVANCE(5);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_double_quoted_string);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_double_quoted_string);
      if (lookahead == '"') ADVANCE(49);
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_backticked_string);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_backticked_string);
      if (lookahead == '\\') ADVANCE(11);
      if (lookahead == '`') ADVANCE(51);
      if (lookahead != 0) ADVANCE(10);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_tagged_string);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '0') ADVANCE(39);
      if (lookahead == '>') ADVANCE(56);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(38);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '>') ADVANCE(56);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_LT_DASH);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '>') ADVANCE(60);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(aux_sym_double_arrow_right_token1);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(aux_sym_double_arrow_left_token1);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(aux_sym_double_arrow_left_token1);
      if (lookahead == '<') ADVANCE(61);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_TILDE);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_TILDE);
      if (lookahead == '>') ADVANCE(65);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_TILDE_GT);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_LT_TILDE);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 16},
  [3] = {.lex_state = 16},
  [4] = {.lex_state = 16},
  [5] = {.lex_state = 16},
  [6] = {.lex_state = 16},
  [7] = {.lex_state = 16},
  [8] = {.lex_state = 1},
  [9] = {.lex_state = 16},
  [10] = {.lex_state = 16},
  [11] = {.lex_state = 16},
  [12] = {.lex_state = 16},
  [13] = {.lex_state = 16},
  [14] = {.lex_state = 16},
  [15] = {.lex_state = 16},
  [16] = {.lex_state = 16},
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
  [46] = {.lex_state = 16},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 16},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 16},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 16},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 16},
  [58] = {.lex_state = 16},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 16},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 16},
  [65] = {.lex_state = 16},
  [66] = {.lex_state = 16},
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
  [81] = {.lex_state = 16},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 16},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 0},
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
    [sym_gram] = STATE(77),
    [sym_pattern] = STATE(17),
    [sym_part] = STATE(21),
    [sym_node] = STATE(2),
    [sym_series] = STATE(17),
    [sym_record] = STATE(17),
    [aux_sym_gram_repeat1] = STATE(17),
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
      aux_sym_part_repeat1,
    ACTIONS(11), 5,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
    STATE(53), 10,
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
  [41] = 9,
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
    STATE(4), 1,
      aux_sym_part_repeat1,
    ACTIONS(25), 5,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
    STATE(53), 10,
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
  [82] = 9,
    ACTIONS(29), 1,
      anon_sym_DASH,
    ACTIONS(32), 1,
      anon_sym_LT_DASH,
    ACTIONS(35), 1,
      anon_sym_EQ,
    ACTIONS(38), 1,
      aux_sym_double_arrow_left_token1,
    ACTIONS(41), 1,
      anon_sym_TILDE,
    ACTIONS(44), 1,
      anon_sym_LT_TILDE,
    STATE(4), 1,
      aux_sym_part_repeat1,
    ACTIONS(27), 5,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
    STATE(53), 10,
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
  [123] = 11,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(47), 1,
      anon_sym_RBRACK,
    ACTIONS(49), 1,
      anon_sym_PIPE,
    ACTIONS(51), 1,
      anon_sym_COLON,
    ACTIONS(53), 1,
      sym_symbol,
    STATE(39), 1,
      sym_labels,
    STATE(40), 1,
      sym_record,
    STATE(43), 1,
      sym_attributes,
    STATE(63), 1,
      sym_members,
    STATE(25), 2,
      sym__identifier,
      sym__string_literal,
    ACTIONS(55), 4,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [161] = 9,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(51), 1,
      anon_sym_COLON,
    ACTIONS(53), 1,
      sym_symbol,
    ACTIONS(57), 1,
      anon_sym_RPAREN,
    STATE(39), 1,
      sym_labels,
    STATE(40), 1,
      sym_record,
    STATE(69), 1,
      sym_attributes,
    STATE(25), 2,
      sym__identifier,
      sym__string_literal,
    ACTIONS(55), 4,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [193] = 8,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(51), 1,
      anon_sym_COLON,
    ACTIONS(53), 1,
      sym_symbol,
    STATE(39), 1,
      sym_labels,
    STATE(40), 1,
      sym_record,
    STATE(59), 1,
      sym_attributes,
    STATE(25), 2,
      sym__identifier,
      sym__string_literal,
    ACTIONS(55), 4,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [222] = 3,
    STATE(48), 3,
      sym__value,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(59), 4,
      sym_integer,
      sym_hexadecimal,
      sym_octal,
      sym_measurement,
    ACTIONS(61), 5,
      sym_decimal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [241] = 8,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(51), 1,
      anon_sym_COLON,
    ACTIONS(53), 1,
      sym_symbol,
    STATE(39), 1,
      sym_labels,
    STATE(40), 1,
      sym_record,
    STATE(75), 1,
      sym_attributes,
    STATE(25), 2,
      sym__identifier,
      sym__string_literal,
    ACTIONS(55), 4,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [270] = 8,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(51), 1,
      anon_sym_COLON,
    ACTIONS(53), 1,
      sym_symbol,
    STATE(39), 1,
      sym_labels,
    STATE(40), 1,
      sym_record,
    STATE(74), 1,
      sym_attributes,
    STATE(25), 2,
      sym__identifier,
      sym__string_literal,
    ACTIONS(55), 4,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [299] = 8,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(51), 1,
      anon_sym_COLON,
    ACTIONS(53), 1,
      sym_symbol,
    STATE(39), 1,
      sym_labels,
    STATE(40), 1,
      sym_record,
    STATE(73), 1,
      sym_attributes,
    STATE(25), 2,
      sym__identifier,
      sym__string_literal,
    ACTIONS(55), 4,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [328] = 8,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(51), 1,
      anon_sym_COLON,
    ACTIONS(53), 1,
      sym_symbol,
    STATE(39), 1,
      sym_labels,
    STATE(40), 1,
      sym_record,
    STATE(72), 1,
      sym_attributes,
    STATE(25), 2,
      sym__identifier,
      sym__string_literal,
    ACTIONS(55), 4,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [357] = 8,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(51), 1,
      anon_sym_COLON,
    ACTIONS(53), 1,
      sym_symbol,
    STATE(39), 1,
      sym_labels,
    STATE(40), 1,
      sym_record,
    STATE(71), 1,
      sym_attributes,
    STATE(25), 2,
      sym__identifier,
      sym__string_literal,
    ACTIONS(55), 4,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [386] = 1,
    ACTIONS(63), 11,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
      anon_sym_DASH,
      anon_sym_LT_DASH,
      anon_sym_EQ,
      aux_sym_double_arrow_left_token1,
      anon_sym_TILDE,
      anon_sym_LT_TILDE,
  [400] = 1,
    ACTIONS(65), 11,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
      anon_sym_DASH,
      anon_sym_LT_DASH,
      anon_sym_EQ,
      aux_sym_double_arrow_left_token1,
      anon_sym_TILDE,
      anon_sym_LT_TILDE,
  [414] = 1,
    ACTIONS(27), 11,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
      anon_sym_DASH,
      anon_sym_LT_DASH,
      anon_sym_EQ,
      aux_sym_double_arrow_left_token1,
      anon_sym_TILDE,
      anon_sym_LT_TILDE,
  [428] = 7,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    ACTIONS(7), 1,
      anon_sym_LBRACK,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(67), 1,
      ts_builtin_sym_end,
    STATE(2), 1,
      sym_node,
    STATE(21), 1,
      sym_part,
    STATE(18), 4,
      sym_pattern,
      sym_series,
      sym_record,
      aux_sym_gram_repeat1,
  [453] = 7,
    ACTIONS(69), 1,
      ts_builtin_sym_end,
    ACTIONS(71), 1,
      anon_sym_LPAREN,
    ACTIONS(74), 1,
      anon_sym_LBRACK,
    ACTIONS(77), 1,
      anon_sym_LBRACE,
    STATE(2), 1,
      sym_node,
    STATE(21), 1,
      sym_part,
    STATE(18), 4,
      sym_pattern,
      sym_series,
      sym_record,
      aux_sym_gram_repeat1,
  [478] = 1,
    ACTIONS(80), 7,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_PIPE,
      anon_sym_LBRACE,
  [488] = 1,
    ACTIONS(82), 7,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_PIPE,
      anon_sym_LBRACE,
  [498] = 3,
    ACTIONS(86), 1,
      anon_sym_COMMA,
    STATE(23), 1,
      aux_sym_pattern_repeat1,
    ACTIONS(84), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [511] = 3,
    ACTIONS(90), 1,
      anon_sym_COMMA,
    STATE(22), 1,
      aux_sym_pattern_repeat1,
    ACTIONS(88), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [524] = 3,
    ACTIONS(86), 1,
      anon_sym_COMMA,
    STATE(22), 1,
      aux_sym_pattern_repeat1,
    ACTIONS(93), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [537] = 1,
    ACTIONS(88), 5,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [545] = 3,
    ACTIONS(51), 1,
      anon_sym_COLON,
    STATE(37), 1,
      sym_labels,
    ACTIONS(95), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_PIPE,
  [557] = 3,
    ACTIONS(99), 1,
      anon_sym_COLON,
    STATE(27), 1,
      aux_sym_labels_repeat1,
    ACTIONS(97), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_PIPE,
  [569] = 3,
    ACTIONS(103), 1,
      anon_sym_COLON,
    STATE(27), 1,
      aux_sym_labels_repeat1,
    ACTIONS(101), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_PIPE,
  [581] = 3,
    ACTIONS(99), 1,
      anon_sym_COLON,
    STATE(26), 1,
      aux_sym_labels_repeat1,
    ACTIONS(106), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_PIPE,
  [593] = 1,
    ACTIONS(101), 4,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_PIPE,
      anon_sym_COLON,
  [600] = 1,
    ACTIONS(108), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [607] = 1,
    ACTIONS(110), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [614] = 1,
    ACTIONS(112), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [621] = 3,
    ACTIONS(114), 1,
      anon_sym_COMMA,
    ACTIONS(117), 1,
      anon_sym_RBRACE,
    STATE(33), 1,
      aux_sym_record_repeat1,
  [631] = 3,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_node,
    STATE(24), 1,
      sym_part,
  [641] = 3,
    ACTIONS(119), 1,
      anon_sym_COMMA,
    ACTIONS(122), 1,
      anon_sym_RBRACK,
    STATE(35), 1,
      aux_sym_members_repeat1,
  [651] = 3,
    ACTIONS(124), 1,
      anon_sym_LBRACK,
    ACTIONS(126), 1,
      anon_sym_TILDE,
    ACTIONS(128), 1,
      anon_sym_TILDE_GT,
  [661] = 1,
    ACTIONS(130), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_PIPE,
  [667] = 3,
    ACTIONS(132), 1,
      anon_sym_COMMA,
    ACTIONS(134), 1,
      anon_sym_RBRACK,
    STATE(42), 1,
      aux_sym_members_repeat1,
  [677] = 1,
    ACTIONS(136), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_PIPE,
  [683] = 1,
    ACTIONS(138), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_PIPE,
  [689] = 3,
    ACTIONS(140), 1,
      anon_sym_COMMA,
    ACTIONS(142), 1,
      anon_sym_RBRACE,
    STATE(33), 1,
      aux_sym_record_repeat1,
  [699] = 3,
    ACTIONS(132), 1,
      anon_sym_COMMA,
    ACTIONS(144), 1,
      anon_sym_RBRACK,
    STATE(35), 1,
      aux_sym_members_repeat1,
  [709] = 3,
    ACTIONS(49), 1,
      anon_sym_PIPE,
    ACTIONS(146), 1,
      anon_sym_RBRACK,
    STATE(78), 1,
      sym_members,
  [719] = 3,
    ACTIONS(148), 1,
      anon_sym_LBRACK,
    ACTIONS(150), 1,
      anon_sym_EQ,
    ACTIONS(152), 1,
      aux_sym_double_arrow_right_token1,
  [729] = 3,
    ACTIONS(140), 1,
      anon_sym_COMMA,
    ACTIONS(154), 1,
      anon_sym_RBRACE,
    STATE(41), 1,
      aux_sym_record_repeat1,
  [739] = 3,
    ACTIONS(156), 1,
      anon_sym_LBRACK,
    ACTIONS(158), 1,
      anon_sym_DASH,
    ACTIONS(160), 1,
      anon_sym_DASH_GT,
  [749] = 1,
    ACTIONS(122), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [754] = 1,
    ACTIONS(162), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [759] = 2,
    ACTIONS(164), 1,
      anon_sym_TILDE,
    ACTIONS(166), 1,
      anon_sym_TILDE_GT,
  [766] = 2,
    ACTIONS(168), 1,
      anon_sym_LBRACK,
    ACTIONS(170), 1,
      anon_sym_DASH,
  [773] = 2,
    ACTIONS(172), 1,
      anon_sym_EQ,
    ACTIONS(174), 1,
      aux_sym_double_arrow_right_token1,
  [780] = 2,
    ACTIONS(176), 1,
      anon_sym_DASH,
    ACTIONS(178), 1,
      anon_sym_DASH_GT,
  [787] = 2,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    STATE(16), 1,
      sym_node,
  [794] = 2,
    ACTIONS(180), 1,
      sym_symbol,
    STATE(55), 1,
      sym_pair,
  [801] = 1,
    ACTIONS(117), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [806] = 2,
    ACTIONS(182), 1,
      anon_sym_LBRACK,
    ACTIONS(184), 1,
      anon_sym_TILDE,
  [813] = 2,
    ACTIONS(186), 1,
      anon_sym_LBRACK,
    ACTIONS(188), 1,
      anon_sym_EQ,
  [820] = 2,
    ACTIONS(180), 1,
      sym_symbol,
    STATE(45), 1,
      sym_pair,
  [827] = 1,
    ACTIONS(190), 1,
      anon_sym_RBRACK,
  [831] = 1,
    ACTIONS(192), 1,
      sym_symbol,
  [835] = 1,
    ACTIONS(194), 1,
      anon_sym_COLON,
  [839] = 1,
    ACTIONS(196), 1,
      anon_sym_LPAREN,
  [843] = 1,
    ACTIONS(146), 1,
      anon_sym_RBRACK,
  [847] = 1,
    ACTIONS(198), 1,
      sym_symbol,
  [851] = 1,
    ACTIONS(200), 1,
      sym_symbol,
  [855] = 1,
    ACTIONS(202), 1,
      sym_symbol,
  [859] = 1,
    ACTIONS(204), 1,
      anon_sym_LPAREN,
  [863] = 1,
    ACTIONS(206), 1,
      anon_sym_LPAREN,
  [867] = 1,
    ACTIONS(208), 1,
      anon_sym_RPAREN,
  [871] = 1,
    ACTIONS(210), 1,
      anon_sym_LPAREN,
  [875] = 1,
    ACTIONS(212), 1,
      anon_sym_RBRACK,
  [879] = 1,
    ACTIONS(214), 1,
      anon_sym_RBRACK,
  [883] = 1,
    ACTIONS(216), 1,
      anon_sym_RBRACK,
  [887] = 1,
    ACTIONS(218), 1,
      anon_sym_RBRACK,
  [891] = 1,
    ACTIONS(220), 1,
      anon_sym_RBRACK,
  [895] = 1,
    ACTIONS(222), 1,
      anon_sym_LPAREN,
  [899] = 1,
    ACTIONS(224), 1,
      ts_builtin_sym_end,
  [903] = 1,
    ACTIONS(226), 1,
      anon_sym_RBRACK,
  [907] = 1,
    ACTIONS(228), 1,
      anon_sym_LPAREN,
  [911] = 1,
    ACTIONS(230), 1,
      anon_sym_LPAREN,
  [915] = 1,
    ACTIONS(232), 1,
      anon_sym_DASH,
  [919] = 1,
    ACTIONS(234), 1,
      anon_sym_LPAREN,
  [923] = 1,
    ACTIONS(236), 1,
      anon_sym_EQ,
  [927] = 1,
    ACTIONS(238), 1,
      anon_sym_LPAREN,
  [931] = 1,
    ACTIONS(240), 1,
      anon_sym_TILDE,
  [935] = 1,
    ACTIONS(242), 1,
      anon_sym_LPAREN,
  [939] = 1,
    ACTIONS(244), 1,
      anon_sym_LPAREN,
  [943] = 1,
    ACTIONS(246), 1,
      anon_sym_LPAREN,
  [947] = 1,
    ACTIONS(248), 1,
      anon_sym_LPAREN,
  [951] = 1,
    ACTIONS(250), 1,
      anon_sym_LPAREN,
  [955] = 1,
    ACTIONS(252), 1,
      anon_sym_LPAREN,
  [959] = 1,
    ACTIONS(254), 1,
      anon_sym_LPAREN,
  [963] = 1,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
  [967] = 1,
    ACTIONS(258), 1,
      anon_sym_LPAREN,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 41,
  [SMALL_STATE(4)] = 82,
  [SMALL_STATE(5)] = 123,
  [SMALL_STATE(6)] = 161,
  [SMALL_STATE(7)] = 193,
  [SMALL_STATE(8)] = 222,
  [SMALL_STATE(9)] = 241,
  [SMALL_STATE(10)] = 270,
  [SMALL_STATE(11)] = 299,
  [SMALL_STATE(12)] = 328,
  [SMALL_STATE(13)] = 357,
  [SMALL_STATE(14)] = 386,
  [SMALL_STATE(15)] = 400,
  [SMALL_STATE(16)] = 414,
  [SMALL_STATE(17)] = 428,
  [SMALL_STATE(18)] = 453,
  [SMALL_STATE(19)] = 478,
  [SMALL_STATE(20)] = 488,
  [SMALL_STATE(21)] = 498,
  [SMALL_STATE(22)] = 511,
  [SMALL_STATE(23)] = 524,
  [SMALL_STATE(24)] = 537,
  [SMALL_STATE(25)] = 545,
  [SMALL_STATE(26)] = 557,
  [SMALL_STATE(27)] = 569,
  [SMALL_STATE(28)] = 581,
  [SMALL_STATE(29)] = 593,
  [SMALL_STATE(30)] = 600,
  [SMALL_STATE(31)] = 607,
  [SMALL_STATE(32)] = 614,
  [SMALL_STATE(33)] = 621,
  [SMALL_STATE(34)] = 631,
  [SMALL_STATE(35)] = 641,
  [SMALL_STATE(36)] = 651,
  [SMALL_STATE(37)] = 661,
  [SMALL_STATE(38)] = 667,
  [SMALL_STATE(39)] = 677,
  [SMALL_STATE(40)] = 683,
  [SMALL_STATE(41)] = 689,
  [SMALL_STATE(42)] = 699,
  [SMALL_STATE(43)] = 709,
  [SMALL_STATE(44)] = 719,
  [SMALL_STATE(45)] = 729,
  [SMALL_STATE(46)] = 739,
  [SMALL_STATE(47)] = 749,
  [SMALL_STATE(48)] = 754,
  [SMALL_STATE(49)] = 759,
  [SMALL_STATE(50)] = 766,
  [SMALL_STATE(51)] = 773,
  [SMALL_STATE(52)] = 780,
  [SMALL_STATE(53)] = 787,
  [SMALL_STATE(54)] = 794,
  [SMALL_STATE(55)] = 801,
  [SMALL_STATE(56)] = 806,
  [SMALL_STATE(57)] = 813,
  [SMALL_STATE(58)] = 820,
  [SMALL_STATE(59)] = 827,
  [SMALL_STATE(60)] = 831,
  [SMALL_STATE(61)] = 835,
  [SMALL_STATE(62)] = 839,
  [SMALL_STATE(63)] = 843,
  [SMALL_STATE(64)] = 847,
  [SMALL_STATE(65)] = 851,
  [SMALL_STATE(66)] = 855,
  [SMALL_STATE(67)] = 859,
  [SMALL_STATE(68)] = 863,
  [SMALL_STATE(69)] = 867,
  [SMALL_STATE(70)] = 871,
  [SMALL_STATE(71)] = 875,
  [SMALL_STATE(72)] = 879,
  [SMALL_STATE(73)] = 883,
  [SMALL_STATE(74)] = 887,
  [SMALL_STATE(75)] = 891,
  [SMALL_STATE(76)] = 895,
  [SMALL_STATE(77)] = 899,
  [SMALL_STATE(78)] = 903,
  [SMALL_STATE(79)] = 907,
  [SMALL_STATE(80)] = 911,
  [SMALL_STATE(81)] = 915,
  [SMALL_STATE(82)] = 919,
  [SMALL_STATE(83)] = 923,
  [SMALL_STATE(84)] = 927,
  [SMALL_STATE(85)] = 931,
  [SMALL_STATE(86)] = 935,
  [SMALL_STATE(87)] = 939,
  [SMALL_STATE(88)] = 943,
  [SMALL_STATE(89)] = 947,
  [SMALL_STATE(90)] = 951,
  [SMALL_STATE(91)] = 955,
  [SMALL_STATE(92)] = 959,
  [SMALL_STATE(93)] = 963,
  [SMALL_STATE(94)] = 967,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_gram, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_part, 1),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_part, 2),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_part_repeat1, 2),
  [29] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_part_repeat1, 2), SHIFT_REPEAT(46),
  [32] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_part_repeat1, 2), SHIFT_REPEAT(50),
  [35] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_part_repeat1, 2), SHIFT_REPEAT(44),
  [38] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_part_repeat1, 2), SHIFT_REPEAT(57),
  [41] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_part_repeat1, 2), SHIFT_REPEAT(36),
  [44] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_part_repeat1, 2), SHIFT_REPEAT(56),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [53] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [59] = {.entry = {.count = 1, .reusable = false}}, SHIFT(48),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 3),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 2),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_gram, 1),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2),
  [71] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2), SHIFT_REPEAT(6),
  [74] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2), SHIFT_REPEAT(5),
  [77] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2), SHIFT_REPEAT(58),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record, 4),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record, 3),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pattern, 1),
  [86] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pattern_repeat1, 2),
  [90] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_pattern_repeat1, 2), SHIFT_REPEAT(34),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pattern, 2),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attributes, 1, .production_id = 1),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_labels, 3),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_labels_repeat1, 2),
  [103] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_labels_repeat1, 2), SHIFT_REPEAT(64),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_labels, 2),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_series, 2),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_series, 3),
  [112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_series, 4),
  [114] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_record_repeat1, 2), SHIFT_REPEAT(54),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_record_repeat1, 2),
  [119] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_members_repeat1, 2), SHIFT_REPEAT(66),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_members_repeat1, 2),
  [124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [126] = {.entry = {.count = 1, .reusable = false}}, SHIFT(68),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attributes, 2, .production_id = 4),
  [132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_members, 2),
  [136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attributes, 1, .production_id = 2),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attributes, 1, .production_id = 3),
  [140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [142] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [144] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_members, 3),
  [146] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [150] = {.entry = {.count = 1, .reusable = false}}, SHIFT(82),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [158] = {.entry = {.count = 1, .reusable = false}}, SHIFT(70),
  [160] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [162] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pair, 3, .production_id = 5),
  [164] = {.entry = {.count = 1, .reusable = false}}, SHIFT(92),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [168] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [172] = {.entry = {.count = 1, .reusable = false}}, SHIFT(89),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [176] = {.entry = {.count = 1, .reusable = false}}, SHIFT(86),
  [178] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [182] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [188] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [192] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_arrow_left, 2),
  [198] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [200] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [202] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_arrow_right, 2),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_squiggle, 2),
  [208] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [210] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_single, 2),
  [212] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [214] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [216] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [218] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [220] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [222] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_arrow_right, 2),
  [224] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_arrow_left, 2),
  [230] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_arrow_right, 2),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [234] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_double_arrow, 2),
  [236] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [238] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_arrow_left, 2),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [242] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_single, 5),
  [244] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_arrow_right, 5),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_arrow_left, 5),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_double_arrow, 5),
  [250] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_arrow_right, 5),
  [252] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_arrow_left, 5),
  [254] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_squiggle, 5),
  [256] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_arrow_right, 5),
  [258] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_arrow_left, 5),
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
