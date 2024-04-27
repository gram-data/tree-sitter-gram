#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 106
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 69
#define ALIAS_COUNT 0
#define TOKEN_COUNT 34
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 10
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 15

enum ts_symbol_identifiers {
  anon_sym_COMMA = 1,
  anon_sym_LPAREN = 2,
  anon_sym_RPAREN = 3,
  anon_sym_LBRACK = 4,
  anon_sym_RBRACK = 5,
  sym_operator = 6,
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
  anon_sym_LT_DASH = 26,
  anon_sym_DASH_GT = 27,
  anon_sym_EQ = 28,
  anon_sym_LT_EQ = 29,
  anon_sym_EQ_GT = 30,
  anon_sym_TILDE = 31,
  anon_sym_LT_TILDE = 32,
  anon_sym_TILDE_GT = 33,
  sym_gram = 34,
  sym_pattern = 35,
  sym__path = 36,
  sym_node = 37,
  sym_relationship = 38,
  sym_series = 39,
  sym_members = 40,
  sym__member = 41,
  sym__attributes = 42,
  sym__identifier = 43,
  sym_labels = 44,
  sym_record = 45,
  sym_value_pair = 46,
  sym_type_pair = 47,
  sym__value = 48,
  sym__numeric_literal = 49,
  sym__string_literal = 50,
  sym__relationship_value = 51,
  sym_single_undirected = 52,
  sym_single_bidirectional = 53,
  sym_single_right = 54,
  sym_single_left = 55,
  sym_double_undirected = 56,
  sym_double_bidirectional = 57,
  sym_double_right = 58,
  sym_double_left = 59,
  sym_squiggle_undirected = 60,
  sym_squiggle_bidirectional = 61,
  sym_squiggle_right = 62,
  sym_squiggle_left = 63,
  aux_sym_gram_repeat1 = 64,
  aux_sym_pattern_repeat1 = 65,
  aux_sym_members_repeat1 = 66,
  aux_sym_labels_repeat1 = 67,
  aux_sym_record_repeat1 = 68,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_COMMA] = ",",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [sym_operator] = "operator",
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
  [anon_sym_LT_DASH] = "<-",
  [anon_sym_DASH_GT] = "->",
  [anon_sym_EQ] = "=",
  [anon_sym_LT_EQ] = "<=",
  [anon_sym_EQ_GT] = "=>",
  [anon_sym_TILDE] = "~",
  [anon_sym_LT_TILDE] = "<~",
  [anon_sym_TILDE_GT] = "~>",
  [sym_gram] = "gram",
  [sym_pattern] = "pattern",
  [sym__path] = "_path",
  [sym_node] = "node",
  [sym_relationship] = "relationship",
  [sym_series] = "series",
  [sym_members] = "members",
  [sym__member] = "_member",
  [sym__attributes] = "_attributes",
  [sym__identifier] = "_identifier",
  [sym_labels] = "labels",
  [sym_record] = "record",
  [sym_value_pair] = "value_pair",
  [sym_type_pair] = "type_pair",
  [sym__value] = "_value",
  [sym__numeric_literal] = "_numeric_literal",
  [sym__string_literal] = "_string_literal",
  [sym__relationship_value] = "_relationship_value",
  [sym_single_undirected] = "single_undirected",
  [sym_single_bidirectional] = "single_bidirectional",
  [sym_single_right] = "single_right",
  [sym_single_left] = "single_left",
  [sym_double_undirected] = "double_undirected",
  [sym_double_bidirectional] = "double_bidirectional",
  [sym_double_right] = "double_right",
  [sym_double_left] = "double_left",
  [sym_squiggle_undirected] = "squiggle_undirected",
  [sym_squiggle_bidirectional] = "squiggle_bidirectional",
  [sym_squiggle_right] = "squiggle_right",
  [sym_squiggle_left] = "squiggle_left",
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
  [sym_operator] = sym_operator,
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
  [anon_sym_LT_DASH] = anon_sym_LT_DASH,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_LT_EQ] = anon_sym_LT_EQ,
  [anon_sym_EQ_GT] = anon_sym_EQ_GT,
  [anon_sym_TILDE] = anon_sym_TILDE,
  [anon_sym_LT_TILDE] = anon_sym_LT_TILDE,
  [anon_sym_TILDE_GT] = anon_sym_TILDE_GT,
  [sym_gram] = sym_gram,
  [sym_pattern] = sym_pattern,
  [sym__path] = sym__path,
  [sym_node] = sym_node,
  [sym_relationship] = sym_relationship,
  [sym_series] = sym_series,
  [sym_members] = sym_members,
  [sym__member] = sym__member,
  [sym__attributes] = sym__attributes,
  [sym__identifier] = sym__identifier,
  [sym_labels] = sym_labels,
  [sym_record] = sym_record,
  [sym_value_pair] = sym_value_pair,
  [sym_type_pair] = sym_type_pair,
  [sym__value] = sym__value,
  [sym__numeric_literal] = sym__numeric_literal,
  [sym__string_literal] = sym__string_literal,
  [sym__relationship_value] = sym__relationship_value,
  [sym_single_undirected] = sym_single_undirected,
  [sym_single_bidirectional] = sym_single_bidirectional,
  [sym_single_right] = sym_single_right,
  [sym_single_left] = sym_single_left,
  [sym_double_undirected] = sym_double_undirected,
  [sym_double_bidirectional] = sym_double_bidirectional,
  [sym_double_right] = sym_double_right,
  [sym_double_left] = sym_double_left,
  [sym_squiggle_undirected] = sym_squiggle_undirected,
  [sym_squiggle_bidirectional] = sym_squiggle_bidirectional,
  [sym_squiggle_right] = sym_squiggle_right,
  [sym_squiggle_left] = sym_squiggle_left,
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
  [sym_operator] = {
    .visible = true,
    .named = true,
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
  [anon_sym_LT_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_TILDE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_TILDE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_TILDE_GT] = {
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
  [sym_members] = {
    .visible = true,
    .named = true,
  },
  [sym__member] = {
    .visible = false,
    .named = true,
  },
  [sym__attributes] = {
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
  [sym_single_undirected] = {
    .visible = true,
    .named = true,
  },
  [sym_single_bidirectional] = {
    .visible = true,
    .named = true,
  },
  [sym_single_right] = {
    .visible = true,
    .named = true,
  },
  [sym_single_left] = {
    .visible = true,
    .named = true,
  },
  [sym_double_undirected] = {
    .visible = true,
    .named = true,
  },
  [sym_double_bidirectional] = {
    .visible = true,
    .named = true,
  },
  [sym_double_right] = {
    .visible = true,
    .named = true,
  },
  [sym_double_left] = {
    .visible = true,
    .named = true,
  },
  [sym_squiggle_undirected] = {
    .visible = true,
    .named = true,
  },
  [sym_squiggle_bidirectional] = {
    .visible = true,
    .named = true,
  },
  [sym_squiggle_right] = {
    .visible = true,
    .named = true,
  },
  [sym_squiggle_left] = {
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
  field_operator = 6,
  field_record = 7,
  field_right = 8,
  field_type = 9,
  field_value = 10,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_cardinality] = "cardinality",
  [field_identifier] = "identifier",
  [field_key] = "key",
  [field_labels] = "labels",
  [field_left] = "left",
  [field_operator] = "operator",
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
  [8] = {.index = 12, .length = 1},
  [9] = {.index = 13, .length = 3},
  [10] = {.index = 16, .length = 3},
  [11] = {.index = 19, .length = 2},
  [12] = {.index = 21, .length = 2},
  [13] = {.index = 23, .length = 3},
  [14] = {.index = 26, .length = 3},
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
    {field_operator, 0},
  [13] =
    {field_left, 0},
    {field_right, 2},
    {field_value, 1},
  [16] =
    {field_identifier, 0},
    {field_labels, 1},
    {field_record, 2},
  [19] =
    {field_key, 0},
    {field_value, 2},
  [21] =
    {field_key, 0},
    {field_type, 2},
  [23] =
    {field_cardinality, 3},
    {field_key, 0},
    {field_type, 2},
  [26] =
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
  [100] = 100,
  [101] = 101,
  [102] = 102,
  [103] = 103,
  [104] = 104,
  [105] = 105,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(15);
      ADVANCE_MAP(
        '!', 32,
        '"', 2,
        '\'', 4,
        '(', 17,
        ')', 18,
        '*', 34,
        '+', 35,
        ',', 16,
        '-', 54,
        '0', 38,
        ':', 28,
        '<', 6,
        '=', 59,
        '?', 33,
        '[', 19,
        ']', 20,
        '`', 8,
        '{', 29,
        '}', 30,
        '~', 63,
        '.', 37,
        '@', 37,
        '_', 37,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(39);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 1:
      ADVANCE_MAP(
        '"', 2,
        '\'', 4,
        '(', 17,
        ')', 18,
        '-', 22,
        '0', 38,
        ':', 27,
        '<', 7,
        ']', 20,
        '`', 8,
        '{', 29,
        '.', 37,
        '@', 37,
        '_', 37,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (lookahead == '%' ||
          lookahead == '*' ||
          lookahead == '+' ||
          lookahead == '/' ||
          lookahead == '=' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(24);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(39);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
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
      if (lookahead == '-') ADVANCE(56);
      if (lookahead == '=') ADVANCE(60);
      if (lookahead == '~') ADVANCE(64);
      END_STATE();
    case 7:
      ADVANCE_MAP(
        '<', 11,
        '%', 24,
        '*', 24,
        '+', 24,
        '-', 24,
        '/', 24,
        '=', 24,
        '|', 24,
        '~', 24,
      );
      END_STATE();
    case 8:
      if (lookahead == '\\') ADVANCE(9);
      if (lookahead == '`') ADVANCE(51);
      if (lookahead != 0) ADVANCE(8);
      END_STATE();
    case 9:
      if (lookahead == '\\') ADVANCE(9);
      if (lookahead == '`') ADVANCE(52);
      if (lookahead != 0) ADVANCE(8);
      END_STATE();
    case 10:
      if (lookahead == '`') ADVANCE(53);
      if (lookahead != 0) ADVANCE(10);
      END_STATE();
    case 11:
      if (lookahead == '%' ||
          lookahead == '*' ||
          lookahead == '+' ||
          lookahead == '-' ||
          lookahead == '/' ||
          lookahead == '=' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(24);
      END_STATE();
    case 12:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(41);
      END_STATE();
    case 13:
      if (eof) ADVANCE(15);
      if (lookahead == '(') ADVANCE(17);
      if (lookahead == ')') ADVANCE(18);
      if (lookahead == ':') ADVANCE(27);
      if (lookahead == '<') ADVANCE(7);
      if (lookahead == '[') ADVANCE(19);
      if (lookahead == ']') ADVANCE(20);
      if (lookahead == '{') ADVANCE(29);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(13);
      if (lookahead == '%' ||
          lookahead == '*' ||
          lookahead == '+' ||
          lookahead == '-' ||
          lookahead == '/' ||
          lookahead == '=' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(24);
      END_STATE();
    case 14:
      if (eof) ADVANCE(15);
      ADVANCE_MAP(
        '(', 17,
        ',', 16,
        '-', 55,
        '<', 6,
        '=', 58,
        '[', 19,
        ']', 20,
        '{', 29,
        '~', 62,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(14);
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
      ACCEPT_TOKEN(sym_operator);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym_operator);
      ADVANCE_MAP(
        '0', 40,
        '>', 26,
        '%', 25,
        '*', 25,
        '+', 25,
        '-', 25,
        '/', 25,
        '=', 25,
        '|', 25,
        '~', 25,
      );
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(39);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_operator);
      if (lookahead == '>') ADVANCE(26);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_operator);
      ADVANCE_MAP(
        '>', 26,
        '%', 25,
        '*', 25,
        '+', 25,
        '-', 25,
        '/', 25,
        '=', 25,
        '|', 25,
        '~', 25,
      );
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym_operator);
      ADVANCE_MAP(
        '>', 26,
        '%', 23,
        '*', 23,
        '+', 23,
        '-', 23,
        '/', 23,
        '=', 23,
        '|', 23,
        '~', 23,
      );
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym_operator);
      if (lookahead == '>') ADVANCE(21);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == ':') ADVANCE(31);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_COLON_COLON);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_QMARK);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '`') ADVANCE(10);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(37);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(12);
      if (lookahead == 'x') ADVANCE(45);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(44);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(46);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(12);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(39);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(46);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(12);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(46);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_decimal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(41);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_hexadecimal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(43);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(42);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(46);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_hexadecimal);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(43);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_octal);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(44);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_measurement);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(43);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(42);
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
      if (lookahead == '\\') ADVANCE(9);
      if (lookahead == '`') ADVANCE(51);
      if (lookahead != 0) ADVANCE(8);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_tagged_string);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '0') ADVANCE(40);
      if (lookahead == '>') ADVANCE(57);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(39);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '>') ADVANCE(57);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_LT_DASH);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '>') ADVANCE(61);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_EQ_GT);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_TILDE);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_TILDE);
      if (lookahead == '>') ADVANCE(65);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_LT_TILDE);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_TILDE_GT);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 14},
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
  [14] = {.lex_state = 14},
  [15] = {.lex_state = 14},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 13},
  [19] = {.lex_state = 13},
  [20] = {.lex_state = 13},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 13},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 13},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 13},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 13},
  [30] = {.lex_state = 13},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 13},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 13},
  [40] = {.lex_state = 14},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 13},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 13},
  [47] = {.lex_state = 13},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 14},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 13},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 14},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 14},
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
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
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
    [anon_sym_LT_DASH] = ACTIONS(1),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_LT_EQ] = ACTIONS(1),
    [anon_sym_EQ_GT] = ACTIONS(1),
    [anon_sym_TILDE] = ACTIONS(1),
    [anon_sym_LT_TILDE] = ACTIONS(1),
    [anon_sym_TILDE_GT] = ACTIONS(1),
  },
  [1] = {
    [sym_gram] = STATE(87),
    [sym_pattern] = STATE(17),
    [sym__path] = STATE(28),
    [sym_node] = STATE(2),
    [sym_relationship] = STATE(28),
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
  [0] = 8,
    ACTIONS(13), 1,
      anon_sym_DASH,
    ACTIONS(15), 1,
      anon_sym_LT_DASH,
    ACTIONS(17), 1,
      anon_sym_EQ,
    ACTIONS(19), 1,
      anon_sym_LT_EQ,
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
    STATE(33), 13,
      sym__relationship_value,
      sym_single_undirected,
      sym_single_bidirectional,
      sym_single_right,
      sym_single_left,
      sym_double_undirected,
      sym_double_bidirectional,
      sym_double_right,
      sym_double_left,
      sym_squiggle_undirected,
      sym_squiggle_bidirectional,
      sym_squiggle_right,
      sym_squiggle_left,
  [42] = 11,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(25), 1,
      anon_sym_RBRACK,
    ACTIONS(27), 1,
      sym_operator,
    ACTIONS(29), 1,
      anon_sym_COLON,
    STATE(30), 1,
      sym_labels,
    STATE(39), 1,
      sym__attributes,
    STATE(43), 1,
      sym_record,
    STATE(91), 1,
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
  [86] = 9,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(29), 1,
      anon_sym_COLON,
    ACTIONS(35), 1,
      anon_sym_RPAREN,
    STATE(30), 1,
      sym_labels,
    STATE(43), 1,
      sym_record,
    STATE(92), 1,
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
  [124] = 5,
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
    STATE(68), 6,
      sym__path,
      sym_relationship,
      sym__member,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
  [153] = 8,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(29), 1,
      anon_sym_COLON,
    STATE(30), 1,
      sym_labels,
    STATE(43), 1,
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
  [188] = 8,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(29), 1,
      anon_sym_COLON,
    STATE(30), 1,
      sym_labels,
    STATE(43), 1,
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
  [223] = 8,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(29), 1,
      anon_sym_COLON,
    STATE(30), 1,
      sym_labels,
    STATE(43), 1,
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
  [258] = 8,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(29), 1,
      anon_sym_COLON,
    STATE(30), 1,
      sym_labels,
    STATE(43), 1,
      sym_record,
    STATE(80), 1,
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
  [293] = 8,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(29), 1,
      anon_sym_COLON,
    STATE(30), 1,
      sym_labels,
    STATE(43), 1,
      sym_record,
    STATE(81), 1,
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
  [328] = 8,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(29), 1,
      anon_sym_COLON,
    STATE(30), 1,
      sym_labels,
    STATE(43), 1,
      sym_record,
    STATE(82), 1,
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
  [363] = 5,
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
    STATE(54), 6,
      sym__path,
      sym_relationship,
      sym__member,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
  [392] = 3,
    STATE(61), 3,
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
  [412] = 1,
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
      anon_sym_LT_EQ,
      anon_sym_TILDE,
      anon_sym_LT_TILDE,
  [427] = 1,
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
      anon_sym_LT_EQ,
      anon_sym_TILDE,
      anon_sym_LT_TILDE,
  [442] = 7,
    ACTIONS(53), 1,
      ts_builtin_sym_end,
    ACTIONS(55), 1,
      anon_sym_LPAREN,
    ACTIONS(58), 1,
      anon_sym_LBRACK,
    ACTIONS(61), 1,
      anon_sym_LBRACE,
    STATE(2), 1,
      sym_node,
    STATE(28), 2,
      sym__path,
      sym_relationship,
    STATE(16), 4,
      sym_pattern,
      sym_series,
      sym_record,
      aux_sym_gram_repeat1,
  [468] = 7,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    ACTIONS(7), 1,
      anon_sym_LBRACK,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(64), 1,
      ts_builtin_sym_end,
    STATE(2), 1,
      sym_node,
    STATE(28), 2,
      sym__path,
      sym_relationship,
    STATE(16), 4,
      sym_pattern,
      sym_series,
      sym_record,
      aux_sym_gram_repeat1,
  [494] = 5,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(29), 1,
      anon_sym_COLON,
    STATE(29), 1,
      sym_labels,
    STATE(47), 1,
      sym_record,
    ACTIONS(66), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      sym_operator,
  [512] = 1,
    ACTIONS(68), 7,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_operator,
      anon_sym_LBRACE,
  [522] = 1,
    ACTIONS(70), 7,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_operator,
      anon_sym_LBRACE,
  [532] = 3,
    ACTIONS(74), 1,
      anon_sym_COMMA,
    STATE(21), 1,
      aux_sym_pattern_repeat1,
    ACTIONS(72), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [545] = 3,
    ACTIONS(79), 1,
      anon_sym_COLON,
    STATE(26), 1,
      aux_sym_labels_repeat1,
    ACTIONS(77), 4,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      sym_operator,
      anon_sym_LBRACE,
  [558] = 1,
    ACTIONS(81), 6,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
  [567] = 3,
    ACTIONS(79), 1,
      anon_sym_COLON,
    STATE(22), 1,
      aux_sym_labels_repeat1,
    ACTIONS(83), 4,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      sym_operator,
      anon_sym_LBRACE,
  [580] = 3,
    ACTIONS(87), 1,
      anon_sym_COMMA,
    STATE(21), 1,
      aux_sym_pattern_repeat1,
    ACTIONS(85), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [593] = 3,
    ACTIONS(91), 1,
      anon_sym_COLON,
    STATE(26), 1,
      aux_sym_labels_repeat1,
    ACTIONS(89), 4,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      sym_operator,
      anon_sym_LBRACE,
  [606] = 2,
    ACTIONS(94), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
    ACTIONS(96), 4,
      anon_sym_BANG,
      anon_sym_QMARK,
      anon_sym_STAR,
      anon_sym_PLUS,
  [617] = 3,
    ACTIONS(87), 1,
      anon_sym_COMMA,
    STATE(25), 1,
      aux_sym_pattern_repeat1,
    ACTIONS(98), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [630] = 3,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    STATE(57), 1,
      sym_record,
    ACTIONS(100), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      sym_operator,
  [642] = 3,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    STATE(46), 1,
      sym_record,
    ACTIONS(102), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      sym_operator,
  [654] = 1,
    ACTIONS(72), 5,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [662] = 1,
    ACTIONS(89), 5,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      sym_operator,
      anon_sym_COLON,
      anon_sym_LBRACE,
  [670] = 3,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_node,
    STATE(23), 2,
      sym__path,
      sym_relationship,
  [681] = 3,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_node,
    STATE(31), 2,
      sym__path,
      sym_relationship,
  [692] = 1,
    ACTIONS(104), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [699] = 1,
    ACTIONS(106), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [706] = 1,
    ACTIONS(108), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [713] = 1,
    ACTIONS(110), 4,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [720] = 3,
    ACTIONS(112), 1,
      anon_sym_RBRACK,
    ACTIONS(114), 1,
      sym_operator,
    STATE(90), 1,
      sym_members,
  [730] = 3,
    ACTIONS(116), 1,
      anon_sym_LBRACK,
    ACTIONS(118), 1,
      anon_sym_DASH,
    ACTIONS(120), 1,
      anon_sym_DASH_GT,
  [740] = 3,
    ACTIONS(122), 1,
      anon_sym_COMMA,
    ACTIONS(125), 1,
      anon_sym_RBRACE,
    STATE(41), 1,
      aux_sym_record_repeat1,
  [750] = 2,
    ACTIONS(127), 1,
      sym_symbol,
    STATE(63), 2,
      sym_value_pair,
      sym_type_pair,
  [758] = 1,
    ACTIONS(129), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      sym_operator,
  [764] = 3,
    ACTIONS(131), 1,
      anon_sym_COMMA,
    ACTIONS(133), 1,
      anon_sym_RBRACE,
    STATE(41), 1,
      aux_sym_record_repeat1,
  [774] = 2,
    ACTIONS(127), 1,
      sym_symbol,
    STATE(55), 2,
      sym_value_pair,
      sym_type_pair,
  [782] = 1,
    ACTIONS(135), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      sym_operator,
  [788] = 1,
    ACTIONS(137), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      sym_operator,
  [794] = 3,
    ACTIONS(139), 1,
      anon_sym_COMMA,
    ACTIONS(141), 1,
      anon_sym_RBRACK,
    STATE(56), 1,
      aux_sym_members_repeat1,
  [804] = 3,
    ACTIONS(143), 1,
      anon_sym_LBRACK,
    ACTIONS(145), 1,
      anon_sym_TILDE,
    ACTIONS(147), 1,
      anon_sym_TILDE_GT,
  [814] = 3,
    ACTIONS(149), 1,
      anon_sym_LBRACK,
    ACTIONS(151), 1,
      anon_sym_TILDE,
    ACTIONS(153), 1,
      anon_sym_TILDE_GT,
  [824] = 3,
    ACTIONS(155), 1,
      anon_sym_LBRACK,
    ACTIONS(157), 1,
      anon_sym_EQ,
    ACTIONS(159), 1,
      anon_sym_EQ_GT,
  [834] = 3,
    ACTIONS(161), 1,
      anon_sym_LBRACK,
    ACTIONS(163), 1,
      anon_sym_EQ,
    ACTIONS(165), 1,
      anon_sym_EQ_GT,
  [844] = 3,
    ACTIONS(167), 1,
      anon_sym_LBRACK,
    ACTIONS(169), 1,
      anon_sym_DASH,
    ACTIONS(171), 1,
      anon_sym_DASH_GT,
  [854] = 3,
    ACTIONS(139), 1,
      anon_sym_COMMA,
    ACTIONS(173), 1,
      anon_sym_RBRACK,
    STATE(48), 1,
      aux_sym_members_repeat1,
  [864] = 3,
    ACTIONS(131), 1,
      anon_sym_COMMA,
    ACTIONS(175), 1,
      anon_sym_RBRACE,
    STATE(44), 1,
      aux_sym_record_repeat1,
  [874] = 3,
    ACTIONS(177), 1,
      anon_sym_COMMA,
    ACTIONS(180), 1,
      anon_sym_RBRACK,
    STATE(56), 1,
      aux_sym_members_repeat1,
  [884] = 1,
    ACTIONS(182), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      sym_operator,
  [890] = 2,
    ACTIONS(184), 1,
      anon_sym_COLON,
    ACTIONS(186), 1,
      anon_sym_COLON_COLON,
  [897] = 1,
    ACTIONS(188), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [902] = 2,
    ACTIONS(190), 1,
      anon_sym_EQ,
    ACTIONS(192), 1,
      anon_sym_EQ_GT,
  [909] = 1,
    ACTIONS(194), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [914] = 2,
    ACTIONS(196), 1,
      anon_sym_DASH,
    ACTIONS(198), 1,
      anon_sym_DASH_GT,
  [921] = 1,
    ACTIONS(125), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [926] = 2,
    ACTIONS(200), 1,
      anon_sym_EQ,
    ACTIONS(202), 1,
      anon_sym_EQ_GT,
  [933] = 2,
    ACTIONS(204), 1,
      anon_sym_DASH,
    ACTIONS(206), 1,
      anon_sym_DASH_GT,
  [940] = 2,
    ACTIONS(208), 1,
      anon_sym_TILDE,
    ACTIONS(210), 1,
      anon_sym_TILDE_GT,
  [947] = 2,
    ACTIONS(212), 1,
      anon_sym_TILDE,
    ACTIONS(214), 1,
      anon_sym_TILDE_GT,
  [954] = 1,
    ACTIONS(180), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [959] = 1,
    ACTIONS(216), 1,
      anon_sym_LPAREN,
  [963] = 1,
    ACTIONS(218), 1,
      anon_sym_LPAREN,
  [967] = 1,
    ACTIONS(220), 1,
      anon_sym_LPAREN,
  [971] = 1,
    ACTIONS(222), 1,
      anon_sym_LPAREN,
  [975] = 1,
    ACTIONS(224), 1,
      anon_sym_LPAREN,
  [979] = 1,
    ACTIONS(226), 1,
      anon_sym_LPAREN,
  [983] = 1,
    ACTIONS(228), 1,
      anon_sym_LPAREN,
  [987] = 1,
    ACTIONS(230), 1,
      anon_sym_LPAREN,
  [991] = 1,
    ACTIONS(232), 1,
      anon_sym_RBRACK,
  [995] = 1,
    ACTIONS(234), 1,
      anon_sym_RBRACK,
  [999] = 1,
    ACTIONS(236), 1,
      anon_sym_RBRACK,
  [1003] = 1,
    ACTIONS(238), 1,
      anon_sym_RBRACK,
  [1007] = 1,
    ACTIONS(240), 1,
      anon_sym_RBRACK,
  [1011] = 1,
    ACTIONS(242), 1,
      anon_sym_RBRACK,
  [1015] = 1,
    ACTIONS(244), 1,
      sym_symbol,
  [1019] = 1,
    ACTIONS(246), 1,
      anon_sym_LPAREN,
  [1023] = 1,
    ACTIONS(248), 1,
      anon_sym_LPAREN,
  [1027] = 1,
    ACTIONS(250), 1,
      anon_sym_LPAREN,
  [1031] = 1,
    ACTIONS(252), 1,
      ts_builtin_sym_end,
  [1035] = 1,
    ACTIONS(254), 1,
      anon_sym_LPAREN,
  [1039] = 1,
    ACTIONS(256), 1,
      sym_symbol,
  [1043] = 1,
    ACTIONS(258), 1,
      anon_sym_RBRACK,
  [1047] = 1,
    ACTIONS(260), 1,
      anon_sym_RBRACK,
  [1051] = 1,
    ACTIONS(262), 1,
      anon_sym_RPAREN,
  [1055] = 1,
    ACTIONS(264), 1,
      sym_symbol,
  [1059] = 1,
    ACTIONS(266), 1,
      anon_sym_LPAREN,
  [1063] = 1,
    ACTIONS(268), 1,
      anon_sym_LPAREN,
  [1067] = 1,
    ACTIONS(270), 1,
      anon_sym_LPAREN,
  [1071] = 1,
    ACTIONS(272), 1,
      anon_sym_LPAREN,
  [1075] = 1,
    ACTIONS(274), 1,
      anon_sym_LPAREN,
  [1079] = 1,
    ACTIONS(276), 1,
      anon_sym_LPAREN,
  [1083] = 1,
    ACTIONS(278), 1,
      anon_sym_LPAREN,
  [1087] = 1,
    ACTIONS(280), 1,
      anon_sym_LPAREN,
  [1091] = 1,
    ACTIONS(282), 1,
      anon_sym_LPAREN,
  [1095] = 1,
    ACTIONS(284), 1,
      anon_sym_LPAREN,
  [1099] = 1,
    ACTIONS(286), 1,
      anon_sym_LPAREN,
  [1103] = 1,
    ACTIONS(288), 1,
      anon_sym_LPAREN,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 42,
  [SMALL_STATE(4)] = 86,
  [SMALL_STATE(5)] = 124,
  [SMALL_STATE(6)] = 153,
  [SMALL_STATE(7)] = 188,
  [SMALL_STATE(8)] = 223,
  [SMALL_STATE(9)] = 258,
  [SMALL_STATE(10)] = 293,
  [SMALL_STATE(11)] = 328,
  [SMALL_STATE(12)] = 363,
  [SMALL_STATE(13)] = 392,
  [SMALL_STATE(14)] = 412,
  [SMALL_STATE(15)] = 427,
  [SMALL_STATE(16)] = 442,
  [SMALL_STATE(17)] = 468,
  [SMALL_STATE(18)] = 494,
  [SMALL_STATE(19)] = 512,
  [SMALL_STATE(20)] = 522,
  [SMALL_STATE(21)] = 532,
  [SMALL_STATE(22)] = 545,
  [SMALL_STATE(23)] = 558,
  [SMALL_STATE(24)] = 567,
  [SMALL_STATE(25)] = 580,
  [SMALL_STATE(26)] = 593,
  [SMALL_STATE(27)] = 606,
  [SMALL_STATE(28)] = 617,
  [SMALL_STATE(29)] = 630,
  [SMALL_STATE(30)] = 642,
  [SMALL_STATE(31)] = 654,
  [SMALL_STATE(32)] = 662,
  [SMALL_STATE(33)] = 670,
  [SMALL_STATE(34)] = 681,
  [SMALL_STATE(35)] = 692,
  [SMALL_STATE(36)] = 699,
  [SMALL_STATE(37)] = 706,
  [SMALL_STATE(38)] = 713,
  [SMALL_STATE(39)] = 720,
  [SMALL_STATE(40)] = 730,
  [SMALL_STATE(41)] = 740,
  [SMALL_STATE(42)] = 750,
  [SMALL_STATE(43)] = 758,
  [SMALL_STATE(44)] = 764,
  [SMALL_STATE(45)] = 774,
  [SMALL_STATE(46)] = 782,
  [SMALL_STATE(47)] = 788,
  [SMALL_STATE(48)] = 794,
  [SMALL_STATE(49)] = 804,
  [SMALL_STATE(50)] = 814,
  [SMALL_STATE(51)] = 824,
  [SMALL_STATE(52)] = 834,
  [SMALL_STATE(53)] = 844,
  [SMALL_STATE(54)] = 854,
  [SMALL_STATE(55)] = 864,
  [SMALL_STATE(56)] = 874,
  [SMALL_STATE(57)] = 884,
  [SMALL_STATE(58)] = 890,
  [SMALL_STATE(59)] = 897,
  [SMALL_STATE(60)] = 902,
  [SMALL_STATE(61)] = 909,
  [SMALL_STATE(62)] = 914,
  [SMALL_STATE(63)] = 921,
  [SMALL_STATE(64)] = 926,
  [SMALL_STATE(65)] = 933,
  [SMALL_STATE(66)] = 940,
  [SMALL_STATE(67)] = 947,
  [SMALL_STATE(68)] = 954,
  [SMALL_STATE(69)] = 959,
  [SMALL_STATE(70)] = 963,
  [SMALL_STATE(71)] = 967,
  [SMALL_STATE(72)] = 971,
  [SMALL_STATE(73)] = 975,
  [SMALL_STATE(74)] = 979,
  [SMALL_STATE(75)] = 983,
  [SMALL_STATE(76)] = 987,
  [SMALL_STATE(77)] = 991,
  [SMALL_STATE(78)] = 995,
  [SMALL_STATE(79)] = 999,
  [SMALL_STATE(80)] = 1003,
  [SMALL_STATE(81)] = 1007,
  [SMALL_STATE(82)] = 1011,
  [SMALL_STATE(83)] = 1015,
  [SMALL_STATE(84)] = 1019,
  [SMALL_STATE(85)] = 1023,
  [SMALL_STATE(86)] = 1027,
  [SMALL_STATE(87)] = 1031,
  [SMALL_STATE(88)] = 1035,
  [SMALL_STATE(89)] = 1039,
  [SMALL_STATE(90)] = 1043,
  [SMALL_STATE(91)] = 1047,
  [SMALL_STATE(92)] = 1051,
  [SMALL_STATE(93)] = 1055,
  [SMALL_STATE(94)] = 1059,
  [SMALL_STATE(95)] = 1063,
  [SMALL_STATE(96)] = 1067,
  [SMALL_STATE(97)] = 1071,
  [SMALL_STATE(98)] = 1075,
  [SMALL_STATE(99)] = 1079,
  [SMALL_STATE(100)] = 1083,
  [SMALL_STATE(101)] = 1087,
  [SMALL_STATE(102)] = 1091,
  [SMALL_STATE(103)] = 1095,
  [SMALL_STATE(104)] = 1099,
  [SMALL_STATE(105)] = 1103,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_gram, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__path, 1, 0, 0),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(68),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [41] = {.entry = {.count = 1, .reusable = false}}, SHIFT(54),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(61),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 2, 0, 0),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 3, 0, 4),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2, 0, 0),
  [55] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [58] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [61] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2, 0, 0), SHIFT_REPEAT(45),
  [64] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_gram, 1, 0, 0),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 1, 0, 1),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record, 4, 0, 0),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record, 3, 0, 0),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pattern_repeat1, 2, 0, 0),
  [74] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_pattern_repeat1, 2, 0, 0), SHIFT_REPEAT(34),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_labels, 3, 0, 0),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relationship, 3, 0, 9),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_labels, 2, 0, 0),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pattern, 2, 0, 0),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_labels_repeat1, 2, 0, 0),
  [91] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_labels_repeat1, 2, 0, 0), SHIFT_REPEAT(83),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_pair, 3, 0, 12),
  [96] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pattern, 1, 0, 0),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 2, 0, 5),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 1, 0, 2),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_series, 2, 0, 0),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_series, 4, 0, 4),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_series, 3, 0, 0),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_series, 3, 0, 4),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [114] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [116] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [118] = {.entry = {.count = 1, .reusable = false}}, SHIFT(88),
  [120] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [122] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_record_repeat1, 2, 0, 0), SHIFT_REPEAT(42),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_record_repeat1, 2, 0, 0),
  [127] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 1, 0, 3),
  [131] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [133] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 2, 0, 7),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 2, 0, 6),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_members, 3, 0, 8),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [145] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [151] = {.entry = {.count = 1, .reusable = false}}, SHIFT(71),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [157] = {.entry = {.count = 1, .reusable = false}}, SHIFT(85),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [163] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [169] = {.entry = {.count = 1, .reusable = false}}, SHIFT(69),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_members, 2, 0, 8),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [177] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_members_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_members_repeat1, 2, 0, 0),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 3, 0, 10),
  [184] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_pair, 4, 0, 13),
  [190] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [192] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_pair, 3, 0, 11),
  [196] = {.entry = {.count = 1, .reusable = false}}, SHIFT(96),
  [198] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [200] = {.entry = {.count = 1, .reusable = false}}, SHIFT(100),
  [202] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [204] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [206] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [208] = {.entry = {.count = 1, .reusable = false}}, SHIFT(102),
  [210] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [212] = {.entry = {.count = 1, .reusable = false}}, SHIFT(104),
  [214] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_left, 2, 0, 0),
  [218] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_right, 2, 0, 0),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_undirected, 2, 0, 0),
  [222] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_right, 2, 0, 0),
  [224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_undirected, 2, 0, 0),
  [226] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_left, 2, 0, 0),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_bidirectional, 2, 0, 0),
  [230] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_right, 2, 0, 0),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [236] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_bidirectional, 2, 0, 0),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_left, 2, 0, 0),
  [250] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_bidirectional, 2, 0, 0),
  [252] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [254] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_undirected, 2, 0, 0),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [260] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [266] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_undirected, 5, 0, 14),
  [268] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_right, 5, 0, 14),
  [270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_left, 5, 0, 14),
  [272] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_bidirectional, 5, 0, 14),
  [274] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_undirected, 5, 0, 14),
  [276] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_right, 5, 0, 14),
  [278] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_left, 5, 0, 14),
  [280] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_bidirectional, 5, 0, 14),
  [282] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_undirected, 5, 0, 14),
  [284] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_right, 5, 0, 14),
  [286] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_left, 5, 0, 14),
  [288] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_bidirectional, 5, 0, 14),
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

TS_PUBLIC const TSLanguage *tree_sitter_gram(void) {
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
