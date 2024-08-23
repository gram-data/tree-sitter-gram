#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 105
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 69
#define ALIAS_COUNT 0
#define TOKEN_COUNT 35
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 9
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 14

enum ts_symbol_identifiers {
  anon_sym_COMMA = 1,
  anon_sym_LBRACK = 2,
  anon_sym_RBRACK = 3,
  anon_sym_AT = 4,
  anon_sym_LPAREN = 5,
  anon_sym_RPAREN = 6,
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
  sym__anySubject = 37,
  sym_subject = 38,
  sym__path_segment = 39,
  sym_node = 40,
  sym_relationship = 41,
  sym_members = 42,
  sym__member = 43,
  sym__attributes = 44,
  sym__scalar = 45,
  sym_labels = 46,
  sym_record = 47,
  sym_property = 48,
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
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_AT] = "@",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
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
  [sym__anySubject] = "_anySubject",
  [sym_subject] = "subject",
  [sym__path_segment] = "_path_segment",
  [sym_node] = "node",
  [sym_relationship] = "relationship",
  [sym_members] = "members",
  [sym__member] = "_member",
  [sym__attributes] = "_attributes",
  [sym__scalar] = "_scalar",
  [sym_labels] = "labels",
  [sym_record] = "record",
  [sym_property] = "property",
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
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_AT] = anon_sym_AT,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
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
  [sym__anySubject] = sym__anySubject,
  [sym_subject] = sym_subject,
  [sym__path_segment] = sym__path_segment,
  [sym_node] = sym_node,
  [sym_relationship] = sym_relationship,
  [sym_members] = sym_members,
  [sym__member] = sym__member,
  [sym__attributes] = sym__attributes,
  [sym__scalar] = sym__scalar,
  [sym_labels] = sym_labels,
  [sym_record] = sym_record,
  [sym_property] = sym_property,
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
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
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
  [sym__anySubject] = {
    .visible = false,
    .named = true,
  },
  [sym_subject] = {
    .visible = true,
    .named = true,
  },
  [sym__path_segment] = {
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
  [sym__scalar] = {
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
  [4] = {.index = 3, .length = 1},
  [5] = {.index = 4, .length = 3},
  [6] = {.index = 7, .length = 2},
  [7] = {.index = 9, .length = 2},
  [8] = {.index = 11, .length = 2},
  [9] = {.index = 13, .length = 3},
  [10] = {.index = 16, .length = 3},
  [11] = {.index = 19, .length = 2},
  [12] = {.index = 21, .length = 3},
  [13] = {.index = 24, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_identifier, 0},
  [1] =
    {field_labels, 0},
  [2] =
    {field_record, 0},
  [3] =
    {field_operator, 0},
  [4] =
    {field_identifier, 1, .inherited = true},
    {field_labels, 1, .inherited = true},
    {field_record, 1, .inherited = true},
  [7] =
    {field_identifier, 0},
    {field_labels, 1},
  [9] =
    {field_identifier, 0},
    {field_record, 1},
  [11] =
    {field_labels, 0},
    {field_record, 1},
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
    {field_cardinality, 3},
    {field_key, 0},
    {field_value, 2},
  [24] =
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(17);
      ADVANCE_MAP(
        '!', 37,
        '"', 3,
        '\'', 5,
        '(', 22,
        ')', 23,
        '*', 39,
        '+', 40,
        ',', 18,
        '-', 59,
        '0', 43,
        ':', 30,
        '<', 7,
        '=', 64,
        '?', 38,
        '@', 21,
        '[', 19,
        ']', 20,
        '_', 42,
        '`', 10,
        '{', 31,
        '}', 32,
        '~', 68,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(44);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(41);
      END_STATE();
    case 1:
      if (lookahead == '!') ADVANCE(9);
      if (lookahead == ':') ADVANCE(34);
      if (lookahead == '=') ADVANCE(36);
      if (('<' <= lookahead && lookahead <= '>')) ADVANCE(35);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      END_STATE();
    case 2:
      ADVANCE_MAP(
        '"', 3,
        '\'', 5,
        '(', 22,
        ')', 23,
        '-', 25,
        '0', 43,
        ':', 30,
        '<', 8,
        '[', 19,
        ']', 20,
        '_', 42,
        '`', 10,
        '{', 31,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (lookahead == '%' ||
          lookahead == '*' ||
          lookahead == '+' ||
          lookahead == '/' ||
          lookahead == '=' ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(27);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(44);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(41);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(54);
      if (lookahead == '\\') ADVANCE(4);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(55);
      if (lookahead == '\\') ADVANCE(4);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 5:
      if (lookahead == '\'') ADVANCE(52);
      if (lookahead == '\\') ADVANCE(6);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 6:
      if (lookahead == '\'') ADVANCE(53);
      if (lookahead == '\\') ADVANCE(6);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 7:
      if (lookahead == '-') ADVANCE(61);
      if (lookahead == '=') ADVANCE(65);
      if (lookahead == '~') ADVANCE(69);
      END_STATE();
    case 8:
      ADVANCE_MAP(
        '<', 13,
        '%', 27,
        '*', 27,
        '+', 27,
        '-', 27,
        '/', 27,
        '=', 27,
        '^', 27,
        '|', 27,
        '~', 27,
      );
      END_STATE();
    case 9:
      if (lookahead == '=') ADVANCE(36);
      END_STATE();
    case 10:
      if (lookahead == '\\') ADVANCE(11);
      if (lookahead == '`') ADVANCE(56);
      if (lookahead != 0) ADVANCE(10);
      END_STATE();
    case 11:
      if (lookahead == '\\') ADVANCE(11);
      if (lookahead == '`') ADVANCE(57);
      if (lookahead != 0) ADVANCE(10);
      END_STATE();
    case 12:
      if (lookahead == '`') ADVANCE(58);
      if (lookahead != 0) ADVANCE(12);
      END_STATE();
    case 13:
      ADVANCE_MAP(
        '%', 27,
        '*', 27,
        '+', 27,
        '-', 27,
        '/', 27,
        '=', 27,
        '^', 27,
        '|', 27,
        '~', 27,
      );
      END_STATE();
    case 14:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(46);
      END_STATE();
    case 15:
      if (eof) ADVANCE(17);
      if (lookahead == '(') ADVANCE(22);
      if (lookahead == ')') ADVANCE(23);
      if (lookahead == ':') ADVANCE(30);
      if (lookahead == '<') ADVANCE(8);
      if (lookahead == '[') ADVANCE(19);
      if (lookahead == ']') ADVANCE(20);
      if (lookahead == '{') ADVANCE(31);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(15);
      if (lookahead == '%' ||
          lookahead == '*' ||
          lookahead == '+' ||
          lookahead == '-' ||
          lookahead == '/' ||
          lookahead == '=' ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(27);
      END_STATE();
    case 16:
      if (eof) ADVANCE(17);
      ADVANCE_MAP(
        '(', 22,
        ',', 18,
        '-', 60,
        '<', 7,
        '=', 63,
        '[', 19,
        ']', 20,
        '{', 31,
        '~', 67,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(16);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_operator);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym_operator);
      ADVANCE_MAP(
        '0', 45,
        '>', 29,
        '%', 28,
        '*', 28,
        '+', 28,
        '-', 28,
        '/', 28,
        '=', 28,
        '^', 28,
        '|', 28,
        '~', 28,
      );
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(44);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym_operator);
      if (lookahead == '>') ADVANCE(29);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym_operator);
      ADVANCE_MAP(
        '>', 29,
        '%', 28,
        '*', 28,
        '+', 28,
        '-', 28,
        '/', 28,
        '=', 28,
        '^', 28,
        '|', 28,
        '~', 28,
      );
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_operator);
      ADVANCE_MAP(
        '>', 29,
        '%', 26,
        '*', 26,
        '+', 26,
        '-', 26,
        '/', 26,
        '=', 26,
        '^', 26,
        '|', 26,
        '~', 26,
      );
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_operator);
      if (lookahead == '>') ADVANCE(24);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(aux_sym_property_token1);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(aux_sym_property_token1);
      if (lookahead == ':') ADVANCE(36);
      if (lookahead == '=' ||
          lookahead == '~') ADVANCE(33);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(aux_sym_property_token1);
      if (lookahead == '=') ADVANCE(33);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(aux_sym_property_token1);
      if (lookahead == '=' ||
          lookahead == '~') ADVANCE(33);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_QMARK);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '-') ADVANCE(42);
      if (lookahead == '`') ADVANCE(12);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(41);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(14);
      if (lookahead == 'x') ADVANCE(50);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(49);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(44);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(14);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_decimal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(46);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_hexadecimal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(48);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(47);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_hexadecimal);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_octal);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(49);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_measurement);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(48);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(47);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_measurement);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_single_quoted_string);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_single_quoted_string);
      if (lookahead == '\'') ADVANCE(52);
      if (lookahead == '\\') ADVANCE(6);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_double_quoted_string);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_double_quoted_string);
      if (lookahead == '"') ADVANCE(54);
      if (lookahead == '\\') ADVANCE(4);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_backticked_string);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_backticked_string);
      if (lookahead == '\\') ADVANCE(11);
      if (lookahead == '`') ADVANCE(56);
      if (lookahead != 0) ADVANCE(10);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_tagged_string);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '0') ADVANCE(45);
      if (lookahead == '>') ADVANCE(62);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(44);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '>') ADVANCE(62);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_LT_DASH);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '>') ADVANCE(66);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_EQ_GT);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_TILDE);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_TILDE);
      if (lookahead == '>') ADVANCE(70);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_LT_TILDE);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_TILDE_GT);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 16},
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
  [13] = {.lex_state = 2},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 16},
  [17] = {.lex_state = 16},
  [18] = {.lex_state = 15},
  [19] = {.lex_state = 15},
  [20] = {.lex_state = 15},
  [21] = {.lex_state = 15},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 15},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 15},
  [34] = {.lex_state = 15},
  [35] = {.lex_state = 15},
  [36] = {.lex_state = 15},
  [37] = {.lex_state = 15},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 16},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 15},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 16},
  [49] = {.lex_state = 15},
  [50] = {.lex_state = 15},
  [51] = {.lex_state = 15},
  [52] = {.lex_state = 15},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 16},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 16},
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
  [89] = {.lex_state = 1},
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
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_AT] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
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
    [sym_gram] = STATE(86),
    [sym_pattern] = STATE(14),
    [sym__anySubject] = STATE(28),
    [sym_subject] = STATE(28),
    [sym__path_segment] = STATE(28),
    [sym_node] = STATE(2),
    [sym_relationship] = STATE(28),
    [sym_record] = STATE(14),
    [aux_sym_gram_repeat1] = STATE(14),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(5),
    [anon_sym_LPAREN] = ACTIONS(7),
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
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
    STATE(39), 13,
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
  [42] = 6,
    ACTIONS(5), 1,
      anon_sym_LBRACK,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_node,
    ACTIONS(25), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(27), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
    STATE(41), 8,
      sym__anySubject,
      sym_subject,
      sym__path_segment,
      sym_relationship,
      sym__member,
      sym__scalar,
      sym__numeric_literal,
      sym__string_literal,
  [76] = 6,
    ACTIONS(5), 1,
      anon_sym_LBRACK,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_node,
    ACTIONS(29), 4,
      sym_symbol,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(31), 6,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
    STATE(65), 8,
      sym__anySubject,
      sym_subject,
      sym__path_segment,
      sym_relationship,
      sym__member,
      sym__scalar,
      sym__numeric_literal,
      sym__string_literal,
  [110] = 11,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(33), 1,
      anon_sym_RBRACK,
    ACTIONS(35), 1,
      sym_operator,
    ACTIONS(37), 1,
      anon_sym_COLON,
    STATE(37), 1,
      sym_labels,
    STATE(50), 1,
      sym_record,
    STATE(51), 1,
      sym__attributes,
    STATE(91), 1,
      sym_members,
    STATE(19), 3,
      sym__scalar,
      sym__numeric_literal,
      sym__string_literal,
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
  [154] = 9,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(37), 1,
      anon_sym_COLON,
    ACTIONS(43), 1,
      anon_sym_RPAREN,
    STATE(37), 1,
      sym_labels,
    STATE(50), 1,
      sym_record,
    STATE(90), 1,
      sym__attributes,
    STATE(19), 3,
      sym__scalar,
      sym__numeric_literal,
      sym__string_literal,
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
  [192] = 8,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(37), 1,
      anon_sym_COLON,
    STATE(37), 1,
      sym_labels,
    STATE(50), 1,
      sym_record,
    STATE(81), 1,
      sym__attributes,
    STATE(19), 3,
      sym__scalar,
      sym__numeric_literal,
      sym__string_literal,
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
  [227] = 8,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(37), 1,
      anon_sym_COLON,
    STATE(37), 1,
      sym_labels,
    STATE(50), 1,
      sym_record,
    STATE(80), 1,
      sym__attributes,
    STATE(19), 3,
      sym__scalar,
      sym__numeric_literal,
      sym__string_literal,
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
  [262] = 8,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(37), 1,
      anon_sym_COLON,
    STATE(37), 1,
      sym_labels,
    STATE(50), 1,
      sym_record,
    STATE(79), 1,
      sym__attributes,
    STATE(19), 3,
      sym__scalar,
      sym__numeric_literal,
      sym__string_literal,
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
  [297] = 8,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(37), 1,
      anon_sym_COLON,
    STATE(37), 1,
      sym_labels,
    STATE(50), 1,
      sym_record,
    STATE(78), 1,
      sym__attributes,
    STATE(19), 3,
      sym__scalar,
      sym__numeric_literal,
      sym__string_literal,
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
  [332] = 8,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(37), 1,
      anon_sym_COLON,
    STATE(37), 1,
      sym_labels,
    STATE(50), 1,
      sym_record,
    STATE(77), 1,
      sym__attributes,
    STATE(19), 3,
      sym__scalar,
      sym__numeric_literal,
      sym__string_literal,
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
  [367] = 8,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(37), 1,
      anon_sym_COLON,
    STATE(37), 1,
      sym_labels,
    STATE(50), 1,
      sym_record,
    STATE(76), 1,
      sym__attributes,
    STATE(19), 3,
      sym__scalar,
      sym__numeric_literal,
      sym__string_literal,
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
  [402] = 3,
    STATE(25), 3,
      sym__scalar,
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
  [422] = 7,
    ACTIONS(5), 1,
      anon_sym_LBRACK,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(49), 1,
      ts_builtin_sym_end,
    STATE(2), 1,
      sym_node,
    STATE(15), 3,
      sym_pattern,
      sym_record,
      aux_sym_gram_repeat1,
    STATE(28), 4,
      sym__anySubject,
      sym_subject,
      sym__path_segment,
      sym_relationship,
  [449] = 7,
    ACTIONS(51), 1,
      ts_builtin_sym_end,
    ACTIONS(53), 1,
      anon_sym_LBRACK,
    ACTIONS(56), 1,
      anon_sym_LPAREN,
    ACTIONS(59), 1,
      anon_sym_LBRACE,
    STATE(2), 1,
      sym_node,
    STATE(15), 3,
      sym_pattern,
      sym_record,
      aux_sym_gram_repeat1,
    STATE(28), 4,
      sym__anySubject,
      sym_subject,
      sym__path_segment,
      sym_relationship,
  [476] = 1,
    ACTIONS(62), 12,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
      anon_sym_DASH,
      anon_sym_LT_DASH,
      anon_sym_EQ,
      anon_sym_LT_EQ,
      anon_sym_TILDE,
      anon_sym_LT_TILDE,
  [491] = 1,
    ACTIONS(64), 12,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
      anon_sym_DASH,
      anon_sym_LT_DASH,
      anon_sym_EQ,
      anon_sym_LT_EQ,
      anon_sym_TILDE,
      anon_sym_LT_TILDE,
  [506] = 1,
    ACTIONS(66), 7,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      sym_operator,
      anon_sym_LBRACE,
  [516] = 5,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(37), 1,
      anon_sym_COLON,
    STATE(36), 1,
      sym_labels,
    STATE(52), 1,
      sym_record,
    ACTIONS(68), 3,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_operator,
  [534] = 1,
    ACTIONS(70), 7,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      sym_operator,
      anon_sym_LBRACE,
  [544] = 1,
    ACTIONS(72), 7,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      sym_operator,
      anon_sym_LBRACE,
  [554] = 4,
    ACTIONS(5), 1,
      anon_sym_LBRACK,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_node,
    STATE(38), 4,
      sym__anySubject,
      sym_subject,
      sym__path_segment,
      sym_relationship,
  [570] = 1,
    ACTIONS(74), 6,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
  [579] = 3,
    ACTIONS(78), 1,
      anon_sym_COMMA,
    STATE(24), 1,
      aux_sym_pattern_repeat1,
    ACTIONS(76), 4,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
  [592] = 2,
    ACTIONS(81), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
    ACTIONS(83), 4,
      anon_sym_BANG,
      anon_sym_QMARK,
      anon_sym_STAR,
      anon_sym_PLUS,
  [603] = 1,
    ACTIONS(85), 6,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
  [612] = 3,
    ACTIONS(89), 1,
      anon_sym_COLON,
    STATE(34), 1,
      aux_sym_labels_repeat1,
    ACTIONS(87), 4,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_operator,
      anon_sym_LBRACE,
  [625] = 3,
    ACTIONS(93), 1,
      anon_sym_COMMA,
    STATE(31), 1,
      aux_sym_pattern_repeat1,
    ACTIONS(91), 4,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
  [638] = 1,
    ACTIONS(95), 6,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
  [647] = 1,
    ACTIONS(97), 6,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
  [656] = 3,
    ACTIONS(93), 1,
      anon_sym_COMMA,
    STATE(24), 1,
      aux_sym_pattern_repeat1,
    ACTIONS(99), 4,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
  [669] = 1,
    ACTIONS(101), 6,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
  [678] = 3,
    ACTIONS(89), 1,
      anon_sym_COLON,
    STATE(27), 1,
      aux_sym_labels_repeat1,
    ACTIONS(103), 4,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_operator,
      anon_sym_LBRACE,
  [691] = 3,
    ACTIONS(107), 1,
      anon_sym_COLON,
    STATE(34), 1,
      aux_sym_labels_repeat1,
    ACTIONS(105), 4,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_operator,
      anon_sym_LBRACE,
  [704] = 1,
    ACTIONS(105), 5,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_operator,
      anon_sym_COLON,
      anon_sym_LBRACE,
  [712] = 3,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    STATE(49), 1,
      sym_record,
    ACTIONS(110), 3,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_operator,
  [724] = 3,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    STATE(42), 1,
      sym_record,
    ACTIONS(112), 3,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_operator,
  [736] = 1,
    ACTIONS(76), 5,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
  [744] = 3,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_node,
    STATE(29), 2,
      sym__path_segment,
      sym_relationship,
  [755] = 3,
    ACTIONS(114), 1,
      anon_sym_LBRACK,
    ACTIONS(116), 1,
      anon_sym_DASH,
    ACTIONS(118), 1,
      anon_sym_DASH_GT,
  [765] = 3,
    ACTIONS(120), 1,
      anon_sym_COMMA,
    ACTIONS(122), 1,
      anon_sym_RBRACK,
    STATE(57), 1,
      aux_sym_members_repeat1,
  [775] = 1,
    ACTIONS(124), 3,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_operator,
  [781] = 3,
    ACTIONS(126), 1,
      anon_sym_RBRACE,
    ACTIONS(128), 1,
      sym_symbol,
    STATE(44), 1,
      sym_property,
  [791] = 3,
    ACTIONS(130), 1,
      anon_sym_COMMA,
    ACTIONS(132), 1,
      anon_sym_RBRACE,
    STATE(47), 1,
      aux_sym_record_repeat1,
  [801] = 3,
    ACTIONS(134), 1,
      anon_sym_COMMA,
    ACTIONS(137), 1,
      anon_sym_RBRACK,
    STATE(45), 1,
      aux_sym_members_repeat1,
  [811] = 3,
    ACTIONS(139), 1,
      anon_sym_COMMA,
    ACTIONS(142), 1,
      anon_sym_RBRACE,
    STATE(46), 1,
      aux_sym_record_repeat1,
  [821] = 3,
    ACTIONS(130), 1,
      anon_sym_COMMA,
    ACTIONS(144), 1,
      anon_sym_RBRACE,
    STATE(46), 1,
      aux_sym_record_repeat1,
  [831] = 3,
    ACTIONS(146), 1,
      anon_sym_LBRACK,
    ACTIONS(148), 1,
      anon_sym_DASH,
    ACTIONS(150), 1,
      anon_sym_DASH_GT,
  [841] = 1,
    ACTIONS(152), 3,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_operator,
  [847] = 1,
    ACTIONS(154), 3,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_operator,
  [853] = 3,
    ACTIONS(156), 1,
      anon_sym_RBRACK,
    ACTIONS(158), 1,
      sym_operator,
    STATE(88), 1,
      sym_members,
  [863] = 1,
    ACTIONS(160), 3,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_operator,
  [869] = 3,
    ACTIONS(162), 1,
      anon_sym_LBRACK,
    ACTIONS(164), 1,
      anon_sym_EQ,
    ACTIONS(166), 1,
      anon_sym_EQ_GT,
  [879] = 3,
    ACTIONS(168), 1,
      anon_sym_LBRACK,
    ACTIONS(170), 1,
      anon_sym_TILDE,
    ACTIONS(172), 1,
      anon_sym_TILDE_GT,
  [889] = 3,
    ACTIONS(174), 1,
      anon_sym_LBRACK,
    ACTIONS(176), 1,
      anon_sym_TILDE,
    ACTIONS(178), 1,
      anon_sym_TILDE_GT,
  [899] = 3,
    ACTIONS(180), 1,
      anon_sym_LBRACK,
    ACTIONS(182), 1,
      anon_sym_EQ,
    ACTIONS(184), 1,
      anon_sym_EQ_GT,
  [909] = 3,
    ACTIONS(120), 1,
      anon_sym_COMMA,
    ACTIONS(186), 1,
      anon_sym_RBRACK,
    STATE(45), 1,
      aux_sym_members_repeat1,
  [919] = 2,
    ACTIONS(188), 1,
      anon_sym_TILDE,
    ACTIONS(190), 1,
      anon_sym_TILDE_GT,
  [926] = 2,
    ACTIONS(192), 1,
      anon_sym_EQ,
    ACTIONS(194), 1,
      anon_sym_EQ_GT,
  [933] = 1,
    ACTIONS(196), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [938] = 2,
    ACTIONS(198), 1,
      anon_sym_EQ,
    ACTIONS(200), 1,
      anon_sym_EQ_GT,
  [945] = 1,
    ACTIONS(142), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [950] = 2,
    ACTIONS(202), 1,
      anon_sym_TILDE,
    ACTIONS(204), 1,
      anon_sym_TILDE_GT,
  [957] = 2,
    ACTIONS(206), 1,
      anon_sym_DASH,
    ACTIONS(208), 1,
      anon_sym_DASH_GT,
  [964] = 1,
    ACTIONS(137), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [969] = 2,
    ACTIONS(128), 1,
      sym_symbol,
    STATE(62), 1,
      sym_property,
  [976] = 2,
    ACTIONS(210), 1,
      anon_sym_DASH,
    ACTIONS(212), 1,
      anon_sym_DASH_GT,
  [983] = 1,
    ACTIONS(214), 1,
      anon_sym_LPAREN,
  [987] = 1,
    ACTIONS(216), 1,
      anon_sym_LPAREN,
  [991] = 1,
    ACTIONS(218), 1,
      anon_sym_LPAREN,
  [995] = 1,
    ACTIONS(220), 1,
      anon_sym_LPAREN,
  [999] = 1,
    ACTIONS(222), 1,
      anon_sym_LPAREN,
  [1003] = 1,
    ACTIONS(224), 1,
      anon_sym_LPAREN,
  [1007] = 1,
    ACTIONS(226), 1,
      anon_sym_LPAREN,
  [1011] = 1,
    ACTIONS(228), 1,
      anon_sym_LPAREN,
  [1015] = 1,
    ACTIONS(230), 1,
      anon_sym_RBRACK,
  [1019] = 1,
    ACTIONS(232), 1,
      anon_sym_RBRACK,
  [1023] = 1,
    ACTIONS(234), 1,
      anon_sym_RBRACK,
  [1027] = 1,
    ACTIONS(236), 1,
      anon_sym_RBRACK,
  [1031] = 1,
    ACTIONS(238), 1,
      anon_sym_RBRACK,
  [1035] = 1,
    ACTIONS(240), 1,
      anon_sym_RBRACK,
  [1039] = 1,
    ACTIONS(242), 1,
      anon_sym_LPAREN,
  [1043] = 1,
    ACTIONS(244), 1,
      anon_sym_LPAREN,
  [1047] = 1,
    ACTIONS(246), 1,
      anon_sym_LPAREN,
  [1051] = 1,
    ACTIONS(248), 1,
      sym_symbol,
  [1055] = 1,
    ACTIONS(250), 1,
      ts_builtin_sym_end,
  [1059] = 1,
    ACTIONS(252), 1,
      anon_sym_LPAREN,
  [1063] = 1,
    ACTIONS(254), 1,
      anon_sym_RBRACK,
  [1067] = 1,
    ACTIONS(256), 1,
      aux_sym_property_token1,
  [1071] = 1,
    ACTIONS(258), 1,
      anon_sym_RPAREN,
  [1075] = 1,
    ACTIONS(260), 1,
      anon_sym_RBRACK,
  [1079] = 1,
    ACTIONS(262), 1,
      sym_symbol,
  [1083] = 1,
    ACTIONS(264), 1,
      anon_sym_LPAREN,
  [1087] = 1,
    ACTIONS(266), 1,
      anon_sym_LPAREN,
  [1091] = 1,
    ACTIONS(268), 1,
      anon_sym_LPAREN,
  [1095] = 1,
    ACTIONS(270), 1,
      anon_sym_LPAREN,
  [1099] = 1,
    ACTIONS(272), 1,
      anon_sym_LPAREN,
  [1103] = 1,
    ACTIONS(274), 1,
      anon_sym_LPAREN,
  [1107] = 1,
    ACTIONS(276), 1,
      anon_sym_LPAREN,
  [1111] = 1,
    ACTIONS(278), 1,
      anon_sym_LPAREN,
  [1115] = 1,
    ACTIONS(280), 1,
      anon_sym_LPAREN,
  [1119] = 1,
    ACTIONS(282), 1,
      anon_sym_LPAREN,
  [1123] = 1,
    ACTIONS(284), 1,
      anon_sym_LPAREN,
  [1127] = 1,
    ACTIONS(286), 1,
      anon_sym_LPAREN,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 42,
  [SMALL_STATE(4)] = 76,
  [SMALL_STATE(5)] = 110,
  [SMALL_STATE(6)] = 154,
  [SMALL_STATE(7)] = 192,
  [SMALL_STATE(8)] = 227,
  [SMALL_STATE(9)] = 262,
  [SMALL_STATE(10)] = 297,
  [SMALL_STATE(11)] = 332,
  [SMALL_STATE(12)] = 367,
  [SMALL_STATE(13)] = 402,
  [SMALL_STATE(14)] = 422,
  [SMALL_STATE(15)] = 449,
  [SMALL_STATE(16)] = 476,
  [SMALL_STATE(17)] = 491,
  [SMALL_STATE(18)] = 506,
  [SMALL_STATE(19)] = 516,
  [SMALL_STATE(20)] = 534,
  [SMALL_STATE(21)] = 544,
  [SMALL_STATE(22)] = 554,
  [SMALL_STATE(23)] = 570,
  [SMALL_STATE(24)] = 579,
  [SMALL_STATE(25)] = 592,
  [SMALL_STATE(26)] = 603,
  [SMALL_STATE(27)] = 612,
  [SMALL_STATE(28)] = 625,
  [SMALL_STATE(29)] = 638,
  [SMALL_STATE(30)] = 647,
  [SMALL_STATE(31)] = 656,
  [SMALL_STATE(32)] = 669,
  [SMALL_STATE(33)] = 678,
  [SMALL_STATE(34)] = 691,
  [SMALL_STATE(35)] = 704,
  [SMALL_STATE(36)] = 712,
  [SMALL_STATE(37)] = 724,
  [SMALL_STATE(38)] = 736,
  [SMALL_STATE(39)] = 744,
  [SMALL_STATE(40)] = 755,
  [SMALL_STATE(41)] = 765,
  [SMALL_STATE(42)] = 775,
  [SMALL_STATE(43)] = 781,
  [SMALL_STATE(44)] = 791,
  [SMALL_STATE(45)] = 801,
  [SMALL_STATE(46)] = 811,
  [SMALL_STATE(47)] = 821,
  [SMALL_STATE(48)] = 831,
  [SMALL_STATE(49)] = 841,
  [SMALL_STATE(50)] = 847,
  [SMALL_STATE(51)] = 853,
  [SMALL_STATE(52)] = 863,
  [SMALL_STATE(53)] = 869,
  [SMALL_STATE(54)] = 879,
  [SMALL_STATE(55)] = 889,
  [SMALL_STATE(56)] = 899,
  [SMALL_STATE(57)] = 909,
  [SMALL_STATE(58)] = 919,
  [SMALL_STATE(59)] = 926,
  [SMALL_STATE(60)] = 933,
  [SMALL_STATE(61)] = 938,
  [SMALL_STATE(62)] = 945,
  [SMALL_STATE(63)] = 950,
  [SMALL_STATE(64)] = 957,
  [SMALL_STATE(65)] = 964,
  [SMALL_STATE(66)] = 969,
  [SMALL_STATE(67)] = 976,
  [SMALL_STATE(68)] = 983,
  [SMALL_STATE(69)] = 987,
  [SMALL_STATE(70)] = 991,
  [SMALL_STATE(71)] = 995,
  [SMALL_STATE(72)] = 999,
  [SMALL_STATE(73)] = 1003,
  [SMALL_STATE(74)] = 1007,
  [SMALL_STATE(75)] = 1011,
  [SMALL_STATE(76)] = 1015,
  [SMALL_STATE(77)] = 1019,
  [SMALL_STATE(78)] = 1023,
  [SMALL_STATE(79)] = 1027,
  [SMALL_STATE(80)] = 1031,
  [SMALL_STATE(81)] = 1035,
  [SMALL_STATE(82)] = 1039,
  [SMALL_STATE(83)] = 1043,
  [SMALL_STATE(84)] = 1047,
  [SMALL_STATE(85)] = 1051,
  [SMALL_STATE(86)] = 1055,
  [SMALL_STATE(87)] = 1059,
  [SMALL_STATE(88)] = 1063,
  [SMALL_STATE(89)] = 1067,
  [SMALL_STATE(90)] = 1071,
  [SMALL_STATE(91)] = 1075,
  [SMALL_STATE(92)] = 1079,
  [SMALL_STATE(93)] = 1083,
  [SMALL_STATE(94)] = 1087,
  [SMALL_STATE(95)] = 1091,
  [SMALL_STATE(96)] = 1095,
  [SMALL_STATE(97)] = 1099,
  [SMALL_STATE(98)] = 1103,
  [SMALL_STATE(99)] = 1107,
  [SMALL_STATE(100)] = 1111,
  [SMALL_STATE(101)] = 1115,
  [SMALL_STATE(102)] = 1119,
  [SMALL_STATE(103)] = 1123,
  [SMALL_STATE(104)] = 1127,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_gram, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__path_segment, 1, 0, 0),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_gram, 1, 0, 0),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2, 0, 0),
  [53] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [56] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2, 0, 0), SHIFT_REPEAT(6),
  [59] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2, 0, 0), SHIFT_REPEAT(43),
  [62] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 2, 0, 0),
  [64] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 3, 0, 5),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record, 4, 0, 0),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 1, 0, 1),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record, 3, 0, 0),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record, 2, 0, 0),
  [74] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_subject, 3, 0, 0),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pattern_repeat1, 2, 0, 0),
  [78] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_pattern_repeat1, 2, 0, 0), SHIFT_REPEAT(22),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_property, 3, 0, 11),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_subject, 4, 0, 5),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_labels, 3, 0, 0),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pattern, 1, 0, 0),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relationship, 3, 0, 9),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_subject, 2, 0, 0),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pattern, 2, 0, 0),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_subject, 3, 0, 5),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_labels, 2, 0, 0),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_labels_repeat1, 2, 0, 0),
  [107] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_labels_repeat1, 2, 0, 0), SHIFT_REPEAT(85),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 2, 0, 6),
  [112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 1, 0, 2),
  [114] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [116] = {.entry = {.count = 1, .reusable = false}}, SHIFT(68),
  [118] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [120] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_members, 2, 0, 4),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 2, 0, 8),
  [126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [130] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [134] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_members_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_members_repeat1, 2, 0, 0),
  [139] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_record_repeat1, 2, 0, 0), SHIFT_REPEAT(66),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_record_repeat1, 2, 0, 0),
  [144] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [146] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [148] = {.entry = {.count = 1, .reusable = false}}, SHIFT(87),
  [150] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 3, 0, 10),
  [154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 1, 0, 3),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [158] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 2, 0, 7),
  [162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [164] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [168] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [170] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [172] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [176] = {.entry = {.count = 1, .reusable = false}}, SHIFT(71),
  [178] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [182] = {.entry = {.count = 1, .reusable = false}}, SHIFT(84),
  [184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [186] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_members, 3, 0, 4),
  [188] = {.entry = {.count = 1, .reusable = false}}, SHIFT(101),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [192] = {.entry = {.count = 1, .reusable = false}}, SHIFT(99),
  [194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_property, 4, 0, 12),
  [198] = {.entry = {.count = 1, .reusable = false}}, SHIFT(97),
  [200] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [202] = {.entry = {.count = 1, .reusable = false}}, SHIFT(103),
  [204] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [206] = {.entry = {.count = 1, .reusable = false}}, SHIFT(95),
  [208] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [210] = {.entry = {.count = 1, .reusable = false}}, SHIFT(93),
  [212] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [214] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_left, 2, 0, 0),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_bidirectional, 2, 0, 0),
  [218] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_right, 2, 0, 0),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_undirected, 2, 0, 0),
  [222] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_right, 2, 0, 0),
  [224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_undirected, 2, 0, 0),
  [226] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_left, 2, 0, 0),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_bidirectional, 2, 0, 0),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [236] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [242] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_right, 2, 0, 0),
  [244] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_bidirectional, 2, 0, 0),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_left, 2, 0, 0),
  [248] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [250] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [252] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_undirected, 2, 0, 0),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [260] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [264] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_undirected, 5, 0, 13),
  [266] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_right, 5, 0, 13),
  [268] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_left, 5, 0, 13),
  [270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_bidirectional, 5, 0, 13),
  [272] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_undirected, 5, 0, 13),
  [274] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_right, 5, 0, 13),
  [276] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_left, 5, 0, 13),
  [278] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_bidirectional, 5, 0, 13),
  [280] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_undirected, 5, 0, 13),
  [282] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_right, 5, 0, 13),
  [284] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_left, 5, 0, 13),
  [286] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_bidirectional, 5, 0, 13),
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
