#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 113
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 71
#define ALIAS_COUNT 0
#define TOKEN_COUNT 35
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 9
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 15

enum ts_symbol_identifiers {
  anon_sym_COMMA = 1,
  anon_sym_AT = 2,
  anon_sym_LPAREN = 3,
  anon_sym_RPAREN = 4,
  anon_sym_LBRACK = 5,
  anon_sym_RBRACK = 6,
  sym_operator = 7,
  anon_sym_COLON = 8,
  anon_sym_LBRACE = 9,
  anon_sym_RBRACE = 10,
  aux_sym_property_token1 = 11,
  anon_sym_BANG = 12,
  anon_sym_QMARK = 13,
  anon_sym_STAR = 14,
  anon_sym_PLUS = 15,
  sym_symbol = 16,
  sym_integer = 17,
  sym_decimal = 18,
  sym_hexadecimal = 19,
  sym_octal = 20,
  sym_measurement = 21,
  sym_single_quoted_string = 22,
  sym_double_quoted_string = 23,
  sym_backticked_string = 24,
  sym_tagged_string = 25,
  anon_sym_DASH = 26,
  anon_sym_LT_DASH = 27,
  anon_sym_DASH_GT = 28,
  anon_sym_EQ = 29,
  anon_sym_LT_EQ = 30,
  anon_sym_EQ_GT = 31,
  anon_sym_TILDE = 32,
  anon_sym_LT_TILDE = 33,
  anon_sym_TILDE_GT = 34,
  sym_gram = 35,
  sym_pattern = 36,
  sym_annotation = 37,
  sym__segment = 38,
  sym_node = 39,
  sym_relationship = 40,
  sym_series = 41,
  sym_members = 42,
  sym__member = 43,
  sym__attributes = 44,
  sym__identifier = 45,
  sym_labels = 46,
  sym_record = 47,
  sym_property = 48,
  sym__value = 49,
  sym__numeric_literal = 50,
  sym__string_literal = 51,
  sym__relationship_value = 52,
  sym_single_undirected = 53,
  sym_single_bidirectional = 54,
  sym_single_right = 55,
  sym_single_left = 56,
  sym_double_undirected = 57,
  sym_double_bidirectional = 58,
  sym_double_right = 59,
  sym_double_left = 60,
  sym_squiggle_undirected = 61,
  sym_squiggle_bidirectional = 62,
  sym_squiggle_right = 63,
  sym_squiggle_left = 64,
  aux_sym_gram_repeat1 = 65,
  aux_sym_pattern_repeat1 = 66,
  aux_sym_pattern_repeat2 = 67,
  aux_sym_members_repeat1 = 68,
  aux_sym_labels_repeat1 = 69,
  aux_sym_record_repeat1 = 70,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_COMMA] = ",",
  [anon_sym_AT] = "@",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [sym_operator] = "operator",
  [anon_sym_COLON] = ":",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [aux_sym_property_token1] = "property_token1",
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
  [sym_annotation] = "annotation",
  [sym__segment] = "_segment",
  [sym_node] = "node",
  [sym_relationship] = "relationship",
  [sym_series] = "series",
  [sym_members] = "members",
  [sym__member] = "_member",
  [sym__attributes] = "_attributes",
  [sym__identifier] = "_identifier",
  [sym_labels] = "labels",
  [sym_record] = "record",
  [sym_property] = "property",
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
  [aux_sym_pattern_repeat2] = "pattern_repeat2",
  [aux_sym_members_repeat1] = "members_repeat1",
  [aux_sym_labels_repeat1] = "labels_repeat1",
  [aux_sym_record_repeat1] = "record_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_AT] = anon_sym_AT,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [sym_operator] = sym_operator,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [aux_sym_property_token1] = aux_sym_property_token1,
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
  [sym_annotation] = sym_annotation,
  [sym__segment] = sym__segment,
  [sym_node] = sym_node,
  [sym_relationship] = sym_relationship,
  [sym_series] = sym_series,
  [sym_members] = sym_members,
  [sym__member] = sym__member,
  [sym__attributes] = sym__attributes,
  [sym__identifier] = sym__identifier,
  [sym_labels] = sym_labels,
  [sym_record] = sym_record,
  [sym_property] = sym_property,
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
  [aux_sym_pattern_repeat2] = aux_sym_pattern_repeat2,
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
  [anon_sym_AT] = {
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
  [aux_sym_property_token1] = {
    .visible = false,
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
  [sym_annotation] = {
    .visible = true,
    .named = true,
  },
  [sym__segment] = {
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
  [sym_property] = {
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
  [aux_sym_pattern_repeat2] = {
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
  field_value = 9,
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
    {field_key, 1},
    {field_value, 3},
  [23] =
    {field_cardinality, 3},
    {field_key, 0},
    {field_value, 2},
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
  [106] = 106,
  [107] = 107,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 111,
  [112] = 112,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(18);
      ADVANCE_MAP(
        '!', 38,
        '"', 3,
        '\'', 5,
        '(', 21,
        ')', 22,
        '*', 40,
        '+', 41,
        ',', 19,
        '-', 60,
        '0', 44,
        ':', 31,
        '<', 7,
        '=', 65,
        '?', 39,
        '@', 20,
        '[', 23,
        ']', 24,
        '`', 10,
        '{', 32,
        '}', 33,
        '~', 69,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(45);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(12);
      END_STATE();
    case 1:
      if (lookahead == '!') ADVANCE(9);
      if (lookahead == ':') ADVANCE(35);
      if (lookahead == '=') ADVANCE(37);
      if (('<' <= lookahead && lookahead <= '>')) ADVANCE(36);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      END_STATE();
    case 2:
      ADVANCE_MAP(
        '"', 3,
        '\'', 5,
        '(', 21,
        ')', 22,
        '-', 26,
        '0', 44,
        ':', 31,
        '<', 8,
        ']', 24,
        '`', 10,
        '{', 32,
        '.', 43,
        '@', 43,
        '_', 43,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (lookahead == '%' ||
          lookahead == '*' ||
          lookahead == '+' ||
          lookahead == '/' ||
          lookahead == '=' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(28);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(45);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(55);
      if (lookahead == '\\') ADVANCE(4);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(56);
      if (lookahead == '\\') ADVANCE(4);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 5:
      if (lookahead == '\'') ADVANCE(53);
      if (lookahead == '\\') ADVANCE(6);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 6:
      if (lookahead == '\'') ADVANCE(54);
      if (lookahead == '\\') ADVANCE(6);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 7:
      if (lookahead == '-') ADVANCE(62);
      if (lookahead == '=') ADVANCE(66);
      if (lookahead == '~') ADVANCE(70);
      END_STATE();
    case 8:
      ADVANCE_MAP(
        '<', 14,
        '%', 28,
        '*', 28,
        '+', 28,
        '-', 28,
        '/', 28,
        '=', 28,
        '|', 28,
        '~', 28,
      );
      END_STATE();
    case 9:
      if (lookahead == '=') ADVANCE(37);
      END_STATE();
    case 10:
      if (lookahead == '\\') ADVANCE(11);
      if (lookahead == '`') ADVANCE(57);
      if (lookahead != 0) ADVANCE(10);
      END_STATE();
    case 11:
      if (lookahead == '\\') ADVANCE(11);
      if (lookahead == '`') ADVANCE(58);
      if (lookahead != 0) ADVANCE(10);
      END_STATE();
    case 12:
      if (lookahead == '`') ADVANCE(13);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(12);
      END_STATE();
    case 13:
      if (lookahead == '`') ADVANCE(59);
      if (lookahead != 0) ADVANCE(13);
      END_STATE();
    case 14:
      if (lookahead == '%' ||
          lookahead == '*' ||
          lookahead == '+' ||
          lookahead == '-' ||
          lookahead == '/' ||
          lookahead == '=' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(28);
      END_STATE();
    case 15:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(47);
      END_STATE();
    case 16:
      if (eof) ADVANCE(18);
      ADVANCE_MAP(
        '(', 21,
        ')', 22,
        ':', 31,
        '<', 8,
        '@', 20,
        '[', 23,
        ']', 24,
        '{', 32,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(16);
      if (lookahead == '%' ||
          lookahead == '*' ||
          lookahead == '+' ||
          lookahead == '-' ||
          lookahead == '/' ||
          lookahead == '=' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(28);
      END_STATE();
    case 17:
      if (eof) ADVANCE(18);
      ADVANCE_MAP(
        '(', 21,
        ',', 19,
        '-', 61,
        '<', 7,
        '=', 64,
        '@', 20,
        '[', 23,
        ']', 24,
        '{', 32,
        '~', 68,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(17);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym_operator);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym_operator);
      ADVANCE_MAP(
        '0', 46,
        '>', 30,
        '%', 29,
        '*', 29,
        '+', 29,
        '-', 29,
        '/', 29,
        '=', 29,
        '|', 29,
        '~', 29,
      );
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(45);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym_operator);
      if (lookahead == '>') ADVANCE(30);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_operator);
      ADVANCE_MAP(
        '>', 30,
        '%', 29,
        '*', 29,
        '+', 29,
        '-', 29,
        '/', 29,
        '=', 29,
        '|', 29,
        '~', 29,
      );
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_operator);
      ADVANCE_MAP(
        '>', 30,
        '%', 27,
        '*', 27,
        '+', 27,
        '-', 27,
        '/', 27,
        '=', 27,
        '|', 27,
        '~', 27,
      );
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_operator);
      if (lookahead == '>') ADVANCE(25);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(aux_sym_property_token1);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(aux_sym_property_token1);
      if (lookahead == ':') ADVANCE(37);
      if (lookahead == '=' ||
          lookahead == '~') ADVANCE(34);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(aux_sym_property_token1);
      if (lookahead == '=') ADVANCE(34);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(aux_sym_property_token1);
      if (lookahead == '=' ||
          lookahead == '~') ADVANCE(34);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_QMARK);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '`') ADVANCE(13);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(15);
      if (lookahead == 'x') ADVANCE(51);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(50);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(15);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(45);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(15);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_decimal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(47);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_hexadecimal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(49);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_hexadecimal);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(49);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_octal);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(50);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_measurement);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(49);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_measurement);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_single_quoted_string);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_single_quoted_string);
      if (lookahead == '\'') ADVANCE(53);
      if (lookahead == '\\') ADVANCE(6);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_double_quoted_string);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_double_quoted_string);
      if (lookahead == '"') ADVANCE(55);
      if (lookahead == '\\') ADVANCE(4);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_backticked_string);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_backticked_string);
      if (lookahead == '\\') ADVANCE(11);
      if (lookahead == '`') ADVANCE(57);
      if (lookahead != 0) ADVANCE(10);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_tagged_string);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '0') ADVANCE(46);
      if (lookahead == '>') ADVANCE(63);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(45);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '>') ADVANCE(63);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_LT_DASH);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '>') ADVANCE(67);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_EQ_GT);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_TILDE);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_TILDE);
      if (lookahead == '>') ADVANCE(71);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_LT_TILDE);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_TILDE_GT);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 17},
  [3] = {.lex_state = 2},
  [4] = {.lex_state = 2},
  [5] = {.lex_state = 2},
  [6] = {.lex_state = 2},
  [7] = {.lex_state = 2},
  [8] = {.lex_state = 2},
  [9] = {.lex_state = 2},
  [10] = {.lex_state = 2},
  [11] = {.lex_state = 2},
  [12] = {.lex_state = 2},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 17},
  [16] = {.lex_state = 2},
  [17] = {.lex_state = 2},
  [18] = {.lex_state = 17},
  [19] = {.lex_state = 16},
  [20] = {.lex_state = 16},
  [21] = {.lex_state = 16},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 16},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 16},
  [32] = {.lex_state = 16},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 16},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 16},
  [38] = {.lex_state = 16},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 16},
  [45] = {.lex_state = 16},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 17},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 16},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 16},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 16},
  [58] = {.lex_state = 17},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 2},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 2},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 17},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 17},
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
  [91] = {.lex_state = 2},
  [92] = {.lex_state = 2},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 1},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 2},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 0},
  [111] = {.lex_state = 0},
  [112] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_AT] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [anon_sym_QMARK] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
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
    [sym_gram] = STATE(100),
    [sym_pattern] = STATE(13),
    [sym_annotation] = STATE(23),
    [sym__segment] = STATE(24),
    [sym_node] = STATE(2),
    [sym_relationship] = STATE(24),
    [sym_series] = STATE(13),
    [sym_record] = STATE(13),
    [aux_sym_gram_repeat1] = STATE(13),
    [aux_sym_pattern_repeat1] = STATE(23),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_AT] = ACTIONS(5),
    [anon_sym_LPAREN] = ACTIONS(7),
    [anon_sym_LBRACK] = ACTIONS(9),
    [anon_sym_LBRACE] = ACTIONS(11),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 8,
    ACTIONS(15), 1,
      anon_sym_DASH,
    ACTIONS(17), 1,
      anon_sym_LT_DASH,
    ACTIONS(19), 1,
      anon_sym_EQ,
    ACTIONS(21), 1,
      anon_sym_LT_EQ,
    ACTIONS(23), 1,
      anon_sym_TILDE,
    ACTIONS(25), 1,
      anon_sym_LT_TILDE,
    ACTIONS(13), 7,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
    STATE(41), 13,
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
  [43] = 11,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(27), 1,
      anon_sym_RBRACK,
    ACTIONS(29), 1,
      sym_operator,
    ACTIONS(31), 1,
      anon_sym_COLON,
    STATE(37), 1,
      sym_labels,
    STATE(54), 1,
      sym__attributes,
    STATE(57), 1,
      sym_record,
    STATE(96), 1,
      sym_members,
    STATE(21), 3,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(33), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(35), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [87] = 9,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(31), 1,
      anon_sym_COLON,
    ACTIONS(37), 1,
      anon_sym_RPAREN,
    STATE(37), 1,
      sym_labels,
    STATE(57), 1,
      sym_record,
    STATE(97), 1,
      sym__attributes,
    STATE(21), 3,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(33), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(35), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [125] = 8,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(31), 1,
      anon_sym_COLON,
    STATE(37), 1,
      sym_labels,
    STATE(57), 1,
      sym_record,
    STATE(87), 1,
      sym__attributes,
    STATE(21), 3,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(33), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(35), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [160] = 8,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(31), 1,
      anon_sym_COLON,
    STATE(37), 1,
      sym_labels,
    STATE(57), 1,
      sym_record,
    STATE(83), 1,
      sym__attributes,
    STATE(21), 3,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(33), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(35), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [195] = 5,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_node,
    ACTIONS(39), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(41), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
    STATE(72), 6,
      sym__segment,
      sym_relationship,
      sym__member,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
  [224] = 8,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(31), 1,
      anon_sym_COLON,
    STATE(37), 1,
      sym_labels,
    STATE(57), 1,
      sym_record,
    STATE(84), 1,
      sym__attributes,
    STATE(21), 3,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(33), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(35), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [259] = 5,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_node,
    ACTIONS(43), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(45), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
    STATE(46), 6,
      sym__segment,
      sym_relationship,
      sym__member,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
  [288] = 8,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(31), 1,
      anon_sym_COLON,
    STATE(37), 1,
      sym_labels,
    STATE(57), 1,
      sym_record,
    STATE(85), 1,
      sym__attributes,
    STATE(21), 3,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(33), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(35), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [323] = 8,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(31), 1,
      anon_sym_COLON,
    STATE(37), 1,
      sym_labels,
    STATE(57), 1,
      sym_record,
    STATE(86), 1,
      sym__attributes,
    STATE(21), 3,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(33), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(35), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [358] = 8,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(31), 1,
      anon_sym_COLON,
    STATE(37), 1,
      sym_labels,
    STATE(57), 1,
      sym_record,
    STATE(88), 1,
      sym__attributes,
    STATE(21), 3,
      sym__identifier,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(33), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(35), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [393] = 9,
    ACTIONS(5), 1,
      anon_sym_AT,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(9), 1,
      anon_sym_LBRACK,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(47), 1,
      ts_builtin_sym_end,
    STATE(2), 1,
      sym_node,
    STATE(23), 2,
      sym_annotation,
      aux_sym_pattern_repeat1,
    STATE(24), 2,
      sym__segment,
      sym_relationship,
    STATE(14), 4,
      sym_pattern,
      sym_series,
      sym_record,
      aux_sym_gram_repeat1,
  [426] = 9,
    ACTIONS(49), 1,
      ts_builtin_sym_end,
    ACTIONS(51), 1,
      anon_sym_AT,
    ACTIONS(54), 1,
      anon_sym_LPAREN,
    ACTIONS(57), 1,
      anon_sym_LBRACK,
    ACTIONS(60), 1,
      anon_sym_LBRACE,
    STATE(2), 1,
      sym_node,
    STATE(23), 2,
      sym_annotation,
      aux_sym_pattern_repeat1,
    STATE(24), 2,
      sym__segment,
      sym_relationship,
    STATE(14), 4,
      sym_pattern,
      sym_series,
      sym_record,
      aux_sym_gram_repeat1,
  [459] = 1,
    ACTIONS(63), 13,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_AT,
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
  [475] = 3,
    STATE(90), 3,
      sym__value,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(65), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(67), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [495] = 3,
    STATE(30), 3,
      sym__value,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(69), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(71), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [515] = 1,
    ACTIONS(73), 13,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_AT,
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
  [531] = 1,
    ACTIONS(75), 8,
      ts_builtin_sym_end,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_operator,
      anon_sym_LBRACE,
  [542] = 1,
    ACTIONS(77), 8,
      ts_builtin_sym_end,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_operator,
      anon_sym_LBRACE,
  [553] = 5,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(31), 1,
      anon_sym_COLON,
    STATE(38), 1,
      sym_labels,
    STATE(44), 1,
      sym_record,
    ACTIONS(79), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      sym_operator,
  [571] = 1,
    ACTIONS(81), 7,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
  [581] = 5,
    ACTIONS(5), 1,
      anon_sym_AT,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_node,
    STATE(28), 2,
      sym__segment,
      sym_relationship,
    STATE(42), 2,
      sym_annotation,
      aux_sym_pattern_repeat1,
  [599] = 3,
    ACTIONS(85), 1,
      anon_sym_COMMA,
    STATE(27), 1,
      aux_sym_pattern_repeat2,
    ACTIONS(83), 5,
      ts_builtin_sym_end,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [613] = 3,
    ACTIONS(85), 1,
      anon_sym_COMMA,
    STATE(26), 1,
      aux_sym_pattern_repeat2,
    ACTIONS(87), 5,
      ts_builtin_sym_end,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [627] = 3,
    ACTIONS(91), 1,
      anon_sym_COMMA,
    STATE(26), 1,
      aux_sym_pattern_repeat2,
    ACTIONS(89), 5,
      ts_builtin_sym_end,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [641] = 3,
    ACTIONS(85), 1,
      anon_sym_COMMA,
    STATE(26), 1,
      aux_sym_pattern_repeat2,
    ACTIONS(94), 5,
      ts_builtin_sym_end,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [655] = 3,
    ACTIONS(85), 1,
      anon_sym_COMMA,
    STATE(25), 1,
      aux_sym_pattern_repeat2,
    ACTIONS(94), 5,
      ts_builtin_sym_end,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [669] = 3,
    ACTIONS(98), 1,
      anon_sym_COLON,
    STATE(31), 1,
      aux_sym_labels_repeat1,
    ACTIONS(96), 4,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      sym_operator,
      anon_sym_LBRACE,
  [682] = 2,
    ACTIONS(100), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
    ACTIONS(102), 4,
      anon_sym_BANG,
      anon_sym_QMARK,
      anon_sym_STAR,
      anon_sym_PLUS,
  [693] = 3,
    ACTIONS(98), 1,
      anon_sym_COLON,
    STATE(32), 1,
      aux_sym_labels_repeat1,
    ACTIONS(104), 4,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      sym_operator,
      anon_sym_LBRACE,
  [706] = 3,
    ACTIONS(108), 1,
      anon_sym_COLON,
    STATE(32), 1,
      aux_sym_labels_repeat1,
    ACTIONS(106), 4,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      sym_operator,
      anon_sym_LBRACE,
  [719] = 1,
    ACTIONS(89), 6,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [728] = 1,
    ACTIONS(111), 5,
      ts_builtin_sym_end,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [736] = 1,
    ACTIONS(106), 5,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      sym_operator,
      anon_sym_COLON,
      anon_sym_LBRACE,
  [744] = 1,
    ACTIONS(113), 5,
      ts_builtin_sym_end,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [752] = 3,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    STATE(52), 1,
      sym_record,
    ACTIONS(115), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      sym_operator,
  [764] = 3,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    STATE(45), 1,
      sym_record,
    ACTIONS(117), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      sym_operator,
  [776] = 1,
    ACTIONS(119), 5,
      ts_builtin_sym_end,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [784] = 1,
    ACTIONS(121), 5,
      ts_builtin_sym_end,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
  [792] = 3,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_node,
    STATE(22), 2,
      sym__segment,
      sym_relationship,
  [803] = 3,
    ACTIONS(123), 1,
      anon_sym_AT,
    ACTIONS(126), 1,
      anon_sym_LPAREN,
    STATE(42), 2,
      sym_annotation,
      aux_sym_pattern_repeat1,
  [814] = 3,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_node,
    STATE(33), 2,
      sym__segment,
      sym_relationship,
  [825] = 1,
    ACTIONS(128), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      sym_operator,
  [831] = 1,
    ACTIONS(130), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      sym_operator,
  [837] = 3,
    ACTIONS(132), 1,
      anon_sym_COMMA,
    ACTIONS(134), 1,
      anon_sym_RBRACK,
    STATE(60), 1,
      aux_sym_members_repeat1,
  [847] = 3,
    ACTIONS(136), 1,
      anon_sym_COMMA,
    ACTIONS(139), 1,
      anon_sym_RBRACK,
    STATE(47), 1,
      aux_sym_members_repeat1,
  [857] = 3,
    ACTIONS(141), 1,
      anon_sym_LBRACK,
    ACTIONS(143), 1,
      anon_sym_DASH,
    ACTIONS(145), 1,
      anon_sym_DASH_GT,
  [867] = 3,
    ACTIONS(147), 1,
      anon_sym_LBRACK,
    ACTIONS(149), 1,
      anon_sym_EQ,
    ACTIONS(151), 1,
      anon_sym_EQ_GT,
  [877] = 3,
    ACTIONS(153), 1,
      anon_sym_COMMA,
    ACTIONS(155), 1,
      anon_sym_RBRACE,
    STATE(53), 1,
      aux_sym_record_repeat1,
  [887] = 3,
    ACTIONS(153), 1,
      anon_sym_COMMA,
    ACTIONS(157), 1,
      anon_sym_RBRACE,
    STATE(50), 1,
      aux_sym_record_repeat1,
  [897] = 1,
    ACTIONS(159), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      sym_operator,
  [903] = 3,
    ACTIONS(161), 1,
      anon_sym_COMMA,
    ACTIONS(164), 1,
      anon_sym_RBRACE,
    STATE(53), 1,
      aux_sym_record_repeat1,
  [913] = 3,
    ACTIONS(166), 1,
      anon_sym_RBRACK,
    ACTIONS(168), 1,
      sym_operator,
    STATE(94), 1,
      sym_members,
  [923] = 3,
    ACTIONS(170), 1,
      anon_sym_LBRACK,
    ACTIONS(172), 1,
      anon_sym_TILDE,
    ACTIONS(174), 1,
      anon_sym_TILDE_GT,
  [933] = 3,
    ACTIONS(176), 1,
      anon_sym_LBRACK,
    ACTIONS(178), 1,
      anon_sym_EQ,
    ACTIONS(180), 1,
      anon_sym_EQ_GT,
  [943] = 1,
    ACTIONS(182), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      sym_operator,
  [949] = 3,
    ACTIONS(184), 1,
      anon_sym_LBRACK,
    ACTIONS(186), 1,
      anon_sym_DASH,
    ACTIONS(188), 1,
      anon_sym_DASH_GT,
  [959] = 3,
    ACTIONS(190), 1,
      anon_sym_LBRACK,
    ACTIONS(192), 1,
      anon_sym_TILDE,
    ACTIONS(194), 1,
      anon_sym_TILDE_GT,
  [969] = 3,
    ACTIONS(132), 1,
      anon_sym_COMMA,
    ACTIONS(196), 1,
      anon_sym_RBRACK,
    STATE(47), 1,
      aux_sym_members_repeat1,
  [979] = 1,
    ACTIONS(198), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [984] = 2,
    ACTIONS(200), 1,
      sym_symbol,
    STATE(51), 1,
      sym_property,
  [991] = 2,
    ACTIONS(202), 1,
      anon_sym_EQ,
    ACTIONS(204), 1,
      anon_sym_EQ_GT,
  [998] = 2,
    ACTIONS(206), 1,
      anon_sym_TILDE,
    ACTIONS(208), 1,
      anon_sym_TILDE_GT,
  [1005] = 2,
    ACTIONS(200), 1,
      sym_symbol,
    STATE(68), 1,
      sym_property,
  [1012] = 2,
    ACTIONS(210), 1,
      anon_sym_EQ,
    ACTIONS(212), 1,
      anon_sym_EQ_GT,
  [1019] = 2,
    ACTIONS(214), 1,
      anon_sym_DASH,
    ACTIONS(216), 1,
      anon_sym_DASH_GT,
  [1026] = 1,
    ACTIONS(164), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [1031] = 2,
    ACTIONS(218), 1,
      anon_sym_TILDE,
    ACTIONS(220), 1,
      anon_sym_TILDE_GT,
  [1038] = 2,
    ACTIONS(222), 1,
      anon_sym_DASH,
    ACTIONS(224), 1,
      anon_sym_DASH_GT,
  [1045] = 1,
    ACTIONS(226), 2,
      anon_sym_AT,
      anon_sym_LPAREN,
  [1050] = 1,
    ACTIONS(139), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1055] = 1,
    ACTIONS(228), 1,
      anon_sym_LPAREN,
  [1059] = 1,
    ACTIONS(230), 1,
      anon_sym_LPAREN,
  [1063] = 1,
    ACTIONS(232), 1,
      anon_sym_LPAREN,
  [1067] = 1,
    ACTIONS(234), 1,
      anon_sym_LPAREN,
  [1071] = 1,
    ACTIONS(236), 1,
      anon_sym_LPAREN,
  [1075] = 1,
    ACTIONS(238), 1,
      anon_sym_LPAREN,
  [1079] = 1,
    ACTIONS(240), 1,
      anon_sym_LPAREN,
  [1083] = 1,
    ACTIONS(242), 1,
      anon_sym_LPAREN,
  [1087] = 1,
    ACTIONS(244), 1,
      anon_sym_LPAREN,
  [1091] = 1,
    ACTIONS(246), 1,
      anon_sym_LPAREN,
  [1095] = 1,
    ACTIONS(248), 1,
      anon_sym_RBRACK,
  [1099] = 1,
    ACTIONS(250), 1,
      anon_sym_RBRACK,
  [1103] = 1,
    ACTIONS(252), 1,
      anon_sym_RBRACK,
  [1107] = 1,
    ACTIONS(254), 1,
      anon_sym_RBRACK,
  [1111] = 1,
    ACTIONS(256), 1,
      anon_sym_RBRACK,
  [1115] = 1,
    ACTIONS(258), 1,
      anon_sym_RBRACK,
  [1119] = 1,
    ACTIONS(260), 1,
      anon_sym_LPAREN,
  [1123] = 1,
    ACTIONS(262), 1,
      anon_sym_RPAREN,
  [1127] = 1,
    ACTIONS(264), 1,
      sym_symbol,
  [1131] = 1,
    ACTIONS(266), 1,
      sym_symbol,
  [1135] = 1,
    ACTIONS(268), 1,
      anon_sym_LPAREN,
  [1139] = 1,
    ACTIONS(270), 1,
      anon_sym_RBRACK,
  [1143] = 1,
    ACTIONS(272), 1,
      aux_sym_property_token1,
  [1147] = 1,
    ACTIONS(274), 1,
      anon_sym_RBRACK,
  [1151] = 1,
    ACTIONS(276), 1,
      anon_sym_RPAREN,
  [1155] = 1,
    ACTIONS(278), 1,
      sym_symbol,
  [1159] = 1,
    ACTIONS(280), 1,
      anon_sym_LPAREN,
  [1163] = 1,
    ACTIONS(282), 1,
      ts_builtin_sym_end,
  [1167] = 1,
    ACTIONS(284), 1,
      anon_sym_LPAREN,
  [1171] = 1,
    ACTIONS(286), 1,
      anon_sym_LPAREN,
  [1175] = 1,
    ACTIONS(288), 1,
      anon_sym_LPAREN,
  [1179] = 1,
    ACTIONS(290), 1,
      anon_sym_LPAREN,
  [1183] = 1,
    ACTIONS(292), 1,
      anon_sym_LPAREN,
  [1187] = 1,
    ACTIONS(294), 1,
      anon_sym_LPAREN,
  [1191] = 1,
    ACTIONS(296), 1,
      anon_sym_LPAREN,
  [1195] = 1,
    ACTIONS(298), 1,
      anon_sym_LPAREN,
  [1199] = 1,
    ACTIONS(300), 1,
      anon_sym_LPAREN,
  [1203] = 1,
    ACTIONS(302), 1,
      anon_sym_LPAREN,
  [1207] = 1,
    ACTIONS(304), 1,
      anon_sym_LPAREN,
  [1211] = 1,
    ACTIONS(306), 1,
      anon_sym_LPAREN,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 43,
  [SMALL_STATE(4)] = 87,
  [SMALL_STATE(5)] = 125,
  [SMALL_STATE(6)] = 160,
  [SMALL_STATE(7)] = 195,
  [SMALL_STATE(8)] = 224,
  [SMALL_STATE(9)] = 259,
  [SMALL_STATE(10)] = 288,
  [SMALL_STATE(11)] = 323,
  [SMALL_STATE(12)] = 358,
  [SMALL_STATE(13)] = 393,
  [SMALL_STATE(14)] = 426,
  [SMALL_STATE(15)] = 459,
  [SMALL_STATE(16)] = 475,
  [SMALL_STATE(17)] = 495,
  [SMALL_STATE(18)] = 515,
  [SMALL_STATE(19)] = 531,
  [SMALL_STATE(20)] = 542,
  [SMALL_STATE(21)] = 553,
  [SMALL_STATE(22)] = 571,
  [SMALL_STATE(23)] = 581,
  [SMALL_STATE(24)] = 599,
  [SMALL_STATE(25)] = 613,
  [SMALL_STATE(26)] = 627,
  [SMALL_STATE(27)] = 641,
  [SMALL_STATE(28)] = 655,
  [SMALL_STATE(29)] = 669,
  [SMALL_STATE(30)] = 682,
  [SMALL_STATE(31)] = 693,
  [SMALL_STATE(32)] = 706,
  [SMALL_STATE(33)] = 719,
  [SMALL_STATE(34)] = 728,
  [SMALL_STATE(35)] = 736,
  [SMALL_STATE(36)] = 744,
  [SMALL_STATE(37)] = 752,
  [SMALL_STATE(38)] = 764,
  [SMALL_STATE(39)] = 776,
  [SMALL_STATE(40)] = 784,
  [SMALL_STATE(41)] = 792,
  [SMALL_STATE(42)] = 803,
  [SMALL_STATE(43)] = 814,
  [SMALL_STATE(44)] = 825,
  [SMALL_STATE(45)] = 831,
  [SMALL_STATE(46)] = 837,
  [SMALL_STATE(47)] = 847,
  [SMALL_STATE(48)] = 857,
  [SMALL_STATE(49)] = 867,
  [SMALL_STATE(50)] = 877,
  [SMALL_STATE(51)] = 887,
  [SMALL_STATE(52)] = 897,
  [SMALL_STATE(53)] = 903,
  [SMALL_STATE(54)] = 913,
  [SMALL_STATE(55)] = 923,
  [SMALL_STATE(56)] = 933,
  [SMALL_STATE(57)] = 943,
  [SMALL_STATE(58)] = 949,
  [SMALL_STATE(59)] = 959,
  [SMALL_STATE(60)] = 969,
  [SMALL_STATE(61)] = 979,
  [SMALL_STATE(62)] = 984,
  [SMALL_STATE(63)] = 991,
  [SMALL_STATE(64)] = 998,
  [SMALL_STATE(65)] = 1005,
  [SMALL_STATE(66)] = 1012,
  [SMALL_STATE(67)] = 1019,
  [SMALL_STATE(68)] = 1026,
  [SMALL_STATE(69)] = 1031,
  [SMALL_STATE(70)] = 1038,
  [SMALL_STATE(71)] = 1045,
  [SMALL_STATE(72)] = 1050,
  [SMALL_STATE(73)] = 1055,
  [SMALL_STATE(74)] = 1059,
  [SMALL_STATE(75)] = 1063,
  [SMALL_STATE(76)] = 1067,
  [SMALL_STATE(77)] = 1071,
  [SMALL_STATE(78)] = 1075,
  [SMALL_STATE(79)] = 1079,
  [SMALL_STATE(80)] = 1083,
  [SMALL_STATE(81)] = 1087,
  [SMALL_STATE(82)] = 1091,
  [SMALL_STATE(83)] = 1095,
  [SMALL_STATE(84)] = 1099,
  [SMALL_STATE(85)] = 1103,
  [SMALL_STATE(86)] = 1107,
  [SMALL_STATE(87)] = 1111,
  [SMALL_STATE(88)] = 1115,
  [SMALL_STATE(89)] = 1119,
  [SMALL_STATE(90)] = 1123,
  [SMALL_STATE(91)] = 1127,
  [SMALL_STATE(92)] = 1131,
  [SMALL_STATE(93)] = 1135,
  [SMALL_STATE(94)] = 1139,
  [SMALL_STATE(95)] = 1143,
  [SMALL_STATE(96)] = 1147,
  [SMALL_STATE(97)] = 1151,
  [SMALL_STATE(98)] = 1155,
  [SMALL_STATE(99)] = 1159,
  [SMALL_STATE(100)] = 1163,
  [SMALL_STATE(101)] = 1167,
  [SMALL_STATE(102)] = 1171,
  [SMALL_STATE(103)] = 1175,
  [SMALL_STATE(104)] = 1179,
  [SMALL_STATE(105)] = 1183,
  [SMALL_STATE(106)] = 1187,
  [SMALL_STATE(107)] = 1191,
  [SMALL_STATE(108)] = 1195,
  [SMALL_STATE(109)] = 1199,
  [SMALL_STATE(110)] = 1203,
  [SMALL_STATE(111)] = 1207,
  [SMALL_STATE(112)] = 1211,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_gram, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__segment, 1, 0, 0),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(72),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(46),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_gram, 1, 0, 0),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2, 0, 0),
  [51] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2, 0, 0), SHIFT_REPEAT(92),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [57] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [60] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2, 0, 0), SHIFT_REPEAT(62),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 2, 0, 0),
  [65] = {.entry = {.count = 1, .reusable = false}}, SHIFT(90),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [69] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 3, 0, 4),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record, 4, 0, 0),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record, 3, 0, 0),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 1, 0, 1),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relationship, 3, 0, 9),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pattern, 1, 0, 0),
  [85] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pattern, 3, 0, 0),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pattern_repeat2, 2, 0, 0),
  [91] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_pattern_repeat2, 2, 0, 0), SHIFT_REPEAT(43),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pattern, 2, 0, 0),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_labels, 2, 0, 0),
  [98] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_property, 3, 0, 11),
  [102] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_labels, 3, 0, 0),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_labels_repeat1, 2, 0, 0),
  [108] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_labels_repeat1, 2, 0, 0), SHIFT_REPEAT(91),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_series, 3, 0, 4),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_series, 4, 0, 4),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 1, 0, 2),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 2, 0, 5),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_series, 2, 0, 0),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_series, 3, 0, 0),
  [123] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_pattern_repeat1, 2, 0, 0), SHIFT_REPEAT(92),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pattern_repeat1, 2, 0, 0),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 2, 0, 6),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 3, 0, 10),
  [132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_members, 2, 0, 8),
  [136] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_members_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_members_repeat1, 2, 0, 0),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [143] = {.entry = {.count = 1, .reusable = false}}, SHIFT(93),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [149] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 2, 0, 7),
  [161] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_record_repeat1, 2, 0, 0), SHIFT_REPEAT(65),
  [164] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_record_repeat1, 2, 0, 0),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [168] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [172] = {.entry = {.count = 1, .reusable = false}}, SHIFT(77),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [176] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [178] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 1, 0, 3),
  [184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [186] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [188] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [192] = {.entry = {.count = 1, .reusable = false}}, SHIFT(80),
  [194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_members, 3, 0, 8),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_property, 4, 0, 13),
  [200] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [202] = {.entry = {.count = 1, .reusable = false}}, SHIFT(107),
  [204] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [206] = {.entry = {.count = 1, .reusable = false}}, SHIFT(109),
  [208] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [210] = {.entry = {.count = 1, .reusable = false}}, SHIFT(105),
  [212] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [214] = {.entry = {.count = 1, .reusable = false}}, SHIFT(103),
  [216] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [218] = {.entry = {.count = 1, .reusable = false}}, SHIFT(111),
  [220] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [222] = {.entry = {.count = 1, .reusable = false}}, SHIFT(101),
  [224] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [226] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_annotation, 5, 0, 12),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_left, 2, 0, 0),
  [230] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_left, 2, 0, 0),
  [232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_bidirectional, 2, 0, 0),
  [234] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_right, 2, 0, 0),
  [236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_undirected, 2, 0, 0),
  [238] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_right, 2, 0, 0),
  [240] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_undirected, 2, 0, 0),
  [242] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_left, 2, 0, 0),
  [244] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_bidirectional, 2, 0, 0),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_right, 2, 0, 0),
  [248] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [260] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_bidirectional, 2, 0, 0),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [268] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_undirected, 2, 0, 0),
  [270] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [282] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [284] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_undirected, 5, 0, 14),
  [286] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_right, 5, 0, 14),
  [288] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_left, 5, 0, 14),
  [290] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_bidirectional, 5, 0, 14),
  [292] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_undirected, 5, 0, 14),
  [294] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_right, 5, 0, 14),
  [296] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_left, 5, 0, 14),
  [298] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_bidirectional, 5, 0, 14),
  [300] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_undirected, 5, 0, 14),
  [302] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_right, 5, 0, 14),
  [304] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_left, 5, 0, 14),
  [306] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_bidirectional, 5, 0, 14),
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
