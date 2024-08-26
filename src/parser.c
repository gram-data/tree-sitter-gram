#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 114
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 76
#define ALIAS_COUNT 0
#define TOKEN_COUNT 38
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 9
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 15

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
  sym_greek = 17,
  sym_math_symbol = 18,
  sym_pictograph = 19,
  sym_integer = 20,
  sym_decimal = 21,
  sym_hexadecimal = 22,
  sym_octal = 23,
  sym_measurement = 24,
  sym_single_quoted_string = 25,
  sym_double_quoted_string = 26,
  sym_backticked_string = 27,
  sym_tagged_string = 28,
  anon_sym_DASH = 29,
  anon_sym_LT_DASH = 30,
  anon_sym_DASH_GT = 31,
  anon_sym_EQ = 32,
  anon_sym_LT_EQ = 33,
  anon_sym_EQ_GT = 34,
  anon_sym_TILDE = 35,
  anon_sym_LT_TILDE = 36,
  anon_sym_TILDE_GT = 37,
  sym_gram = 38,
  sym__description = 39,
  sym_pattern = 40,
  sym__patternComponent = 41,
  sym_subject = 42,
  sym_annotation = 43,
  sym__path = 44,
  sym_node = 45,
  sym_relationship = 46,
  sym_members = 47,
  sym__references = 48,
  sym__member = 49,
  sym__attributes = 50,
  sym__scalar = 51,
  sym_labels = 52,
  sym_record = 53,
  sym_property = 54,
  sym__numeric_literal = 55,
  sym__string_literal = 56,
  sym__relationship_value = 57,
  sym_single_undirected = 58,
  sym_single_bidirectional = 59,
  sym_single_right = 60,
  sym_single_left = 61,
  sym_double_undirected = 62,
  sym_double_bidirectional = 63,
  sym_double_right = 64,
  sym_double_left = 65,
  sym_squiggle_undirected = 66,
  sym_squiggle_bidirectional = 67,
  sym_squiggle_right = 68,
  sym_squiggle_left = 69,
  aux_sym_gram_repeat1 = 70,
  aux_sym_pattern_repeat1 = 71,
  aux_sym_pattern_repeat2 = 72,
  aux_sym_members_repeat1 = 73,
  aux_sym_labels_repeat1 = 74,
  aux_sym_record_repeat1 = 75,
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
  [sym_greek] = "greek",
  [sym_math_symbol] = "math_symbol",
  [sym_pictograph] = "pictograph",
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
  [sym__description] = "_description",
  [sym_pattern] = "pattern",
  [sym__patternComponent] = "_patternComponent",
  [sym_subject] = "subject",
  [sym_annotation] = "annotation",
  [sym__path] = "_path",
  [sym_node] = "node",
  [sym_relationship] = "relationship",
  [sym_members] = "members",
  [sym__references] = "_references",
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
  [aux_sym_pattern_repeat2] = "pattern_repeat2",
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
  [sym_greek] = sym_greek,
  [sym_math_symbol] = sym_math_symbol,
  [sym_pictograph] = sym_pictograph,
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
  [sym__description] = sym__description,
  [sym_pattern] = sym_pattern,
  [sym__patternComponent] = sym__patternComponent,
  [sym_subject] = sym_subject,
  [sym_annotation] = sym_annotation,
  [sym__path] = sym__path,
  [sym_node] = sym_node,
  [sym_relationship] = sym_relationship,
  [sym_members] = sym_members,
  [sym__references] = sym__references,
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
  [sym_greek] = {
    .visible = true,
    .named = true,
  },
  [sym_math_symbol] = {
    .visible = true,
    .named = true,
  },
  [sym_pictograph] = {
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
  [sym__description] = {
    .visible = false,
    .named = true,
  },
  [sym_pattern] = {
    .visible = true,
    .named = true,
  },
  [sym__patternComponent] = {
    .visible = false,
    .named = true,
  },
  [sym_subject] = {
    .visible = true,
    .named = true,
  },
  [sym_annotation] = {
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
  [sym_members] = {
    .visible = true,
    .named = true,
  },
  [sym__references] = {
    .visible = false,
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
  [4] = {.index = 3, .length = 1},
  [5] = {.index = 4, .length = 3},
  [6] = {.index = 7, .length = 2},
  [7] = {.index = 9, .length = 2},
  [8] = {.index = 11, .length = 2},
  [9] = {.index = 13, .length = 3},
  [10] = {.index = 16, .length = 3},
  [11] = {.index = 19, .length = 3},
  [12] = {.index = 22, .length = 2},
  [13] = {.index = 24, .length = 4},
  [14] = {.index = 28, .length = 3},
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
    {field_operator, 1},
    {field_value, 2},
  [22] =
    {field_key, 1},
    {field_value, 3},
  [24] =
    {field_cardinality, 3},
    {field_key, 0},
    {field_operator, 1},
    {field_value, 2},
  [28] =
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
  [113] = 113,
};

static TSCharacterRange sym_math_symbol_character_set_1[] = {
  {'^', '^'}, {0x3d0, 0x3d2}, {0x3d5, 0x3d5}, {0x3f0, 0x3f1}, {0x3f4, 0x3f5}, {0x2016, 0x2016}, {0x2032, 0x2034}, {0x2040, 0x2040},
  {0x2061, 0x2064}, {0x207d, 0x207e}, {0x208d, 0x208e}, {0x20d0, 0x20dc}, {0x20e1, 0x20e1}, {0x20e5, 0x20e6}, {0x20eb, 0x20ef}, {0x2102, 0x2102},
  {0x2107, 0x2107}, {0x210a, 0x2113}, {0x2115, 0x2115}, {0x2119, 0x211d}, {0x2124, 0x2124}, {0x2128, 0x2129}, {0x212c, 0x212d}, {0x212f, 0x2131},
  {0x2133, 0x2138}, {0x213c, 0x213f}, {0x2145, 0x2149}, {0x2195, 0x2199}, {0x219c, 0x219f}, {0x21a1, 0x21a2}, {0x21a4, 0x21a5}, {0x21a7, 0x21a7},
  {0x21a9, 0x21ad}, {0x21b0, 0x21b1}, {0x21b6, 0x21b7}, {0x21bc, 0x21cd}, {0x21d0, 0x21d1}, {0x21d3, 0x21d3}, {0x21d5, 0x21db}, {0x21dd, 0x21dd},
  {0x21e4, 0x21e5}, {0x2308, 0x230b}, {0x23b4, 0x23b5}, {0x23b7, 0x23b7}, {0x23d0, 0x23d0}, {0x23e2, 0x23e2}, {0x25a0, 0x25a1}, {0x25ae, 0x25b6},
  {0x25bc, 0x25c0}, {0x25c6, 0x25c7}, {0x25ca, 0x25cb}, {0x25cf, 0x25d3}, {0x25e2, 0x25e2}, {0x25e4, 0x25e4}, {0x25e7, 0x25ec}, {0x2605, 0x2606},
  {0x2640, 0x2640}, {0x2642, 0x2642}, {0x2660, 0x2663}, {0x266d, 0x266e}, {0x27c5, 0x27c6}, {0x27e6, 0x27ef}, {0x2983, 0x2998}, {0x29d8, 0x29db},
  {0x29fc, 0x29fd}, {0xfe61, 0xfe61}, {0xfe63, 0xfe63}, {0xfe68, 0xfe68}, {0xff3c, 0xff3c}, {0xff3e, 0xff3e}, {0x1d400, 0x1d454}, {0x1d456, 0x1d49c},
  {0x1d49e, 0x1d49f}, {0x1d4a2, 0x1d4a2}, {0x1d4a5, 0x1d4a6}, {0x1d4a9, 0x1d4ac}, {0x1d4ae, 0x1d4b9}, {0x1d4bb, 0x1d4bb}, {0x1d4bd, 0x1d4c3}, {0x1d4c5, 0x1d505},
  {0x1d507, 0x1d50a}, {0x1d50d, 0x1d514}, {0x1d516, 0x1d51c}, {0x1d51e, 0x1d539}, {0x1d53b, 0x1d53e}, {0x1d540, 0x1d544}, {0x1d546, 0x1d546}, {0x1d54a, 0x1d550},
  {0x1d552, 0x1d6a5}, {0x1d6a8, 0x1d6c0}, {0x1d6c2, 0x1d6da}, {0x1d6dc, 0x1d6fa}, {0x1d6fc, 0x1d714}, {0x1d716, 0x1d734}, {0x1d736, 0x1d74e}, {0x1d750, 0x1d76e},
  {0x1d770, 0x1d788}, {0x1d78a, 0x1d7a8}, {0x1d7aa, 0x1d7c2}, {0x1d7c4, 0x1d7cb}, {0x1d7ce, 0x1d7ff}, {0x1ee00, 0x1ee03}, {0x1ee05, 0x1ee1f}, {0x1ee21, 0x1ee22},
  {0x1ee24, 0x1ee24}, {0x1ee27, 0x1ee27}, {0x1ee29, 0x1ee32}, {0x1ee34, 0x1ee37}, {0x1ee39, 0x1ee39}, {0x1ee3b, 0x1ee3b}, {0x1ee42, 0x1ee42}, {0x1ee47, 0x1ee47},
  {0x1ee49, 0x1ee49}, {0x1ee4b, 0x1ee4b}, {0x1ee4d, 0x1ee4f}, {0x1ee51, 0x1ee52}, {0x1ee54, 0x1ee54}, {0x1ee57, 0x1ee57}, {0x1ee59, 0x1ee59}, {0x1ee5b, 0x1ee5b},
  {0x1ee5d, 0x1ee5d}, {0x1ee5f, 0x1ee5f}, {0x1ee61, 0x1ee62}, {0x1ee64, 0x1ee64}, {0x1ee67, 0x1ee6a}, {0x1ee6c, 0x1ee72}, {0x1ee74, 0x1ee77}, {0x1ee79, 0x1ee7c},
  {0x1ee7e, 0x1ee7e}, {0x1ee80, 0x1ee89}, {0x1ee8b, 0x1ee9b}, {0x1eea1, 0x1eea3}, {0x1eea5, 0x1eea9}, {0x1eeab, 0x1eebb},
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(19);
      ADVANCE_MAP(
        '!', 39,
        '"', 4,
        '\'', 6,
        '(', 24,
        ')', 25,
        '*', 41,
        '+', 42,
        ',', 20,
        '-', 64,
        '0', 48,
        ':', 32,
        '<', 8,
        '=', 69,
        '?', 40,
        '@', 23,
        '[', 21,
        ']', 22,
        '_', 44,
        '`', 12,
        '{', 33,
        '}', 34,
        '~', 73,
      );
      if ((0x2660 <= lookahead && lookahead <= 0x2663) ||
          lookahead == 0x266d ||
          lookahead == 0x266e) ADVANCE(46);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(49);
      if ((0x391 <= lookahead && lookahead <= 0x3a9) ||
          (0x3b1 <= lookahead && lookahead <= 0x3c9)) ADVANCE(45);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      if ((0x2650 <= lookahead && lookahead <= 0x26ff)) ADVANCE(47);
      if (set_contains(sym_math_symbol_character_set_1, 134, lookahead)) ADVANCE(46);
      END_STATE();
    case 1:
      if (lookahead == '!') ADVANCE(11);
      if (lookahead == ':') ADVANCE(36);
      if (lookahead == '=') ADVANCE(38);
      if (('<' <= lookahead && lookahead <= '>')) ADVANCE(37);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      END_STATE();
    case 2:
      ADVANCE_MAP(
        '"', 4,
        '\'', 6,
        '(', 24,
        ')', 25,
        '-', 9,
        '0', 48,
        ':', 32,
        '[', 21,
        '_', 44,
        '`', 12,
        '{', 33,
      );
      if ((0x2660 <= lookahead && lookahead <= 0x2663) ||
          lookahead == 0x266d ||
          lookahead == 0x266e) ADVANCE(46);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(49);
      if ((0x391 <= lookahead && lookahead <= 0x3a9) ||
          (0x3b1 <= lookahead && lookahead <= 0x3c9)) ADVANCE(45);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      if ((0x2650 <= lookahead && lookahead <= 0x26ff)) ADVANCE(47);
      if (set_contains(sym_math_symbol_character_set_1, 134, lookahead)) ADVANCE(46);
      END_STATE();
    case 3:
      ADVANCE_MAP(
        '"', 4,
        '\'', 6,
        '-', 27,
        '0', 48,
        ':', 32,
        '<', 10,
        ']', 22,
        '^', 29,
        '_', 44,
        '`', 12,
        '{', 33,
      );
      if ((0x2660 <= lookahead && lookahead <= 0x2663) ||
          lookahead == 0x266d ||
          lookahead == 0x266e) ADVANCE(46);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (lookahead == '%' ||
          lookahead == '*' ||
          lookahead == '+' ||
          lookahead == '/' ||
          lookahead == '=' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(29);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(49);
      if ((0x391 <= lookahead && lookahead <= 0x3a9) ||
          (0x3b1 <= lookahead && lookahead <= 0x3c9)) ADVANCE(45);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      if ((0x2650 <= lookahead && lookahead <= 0x26ff)) ADVANCE(47);
      if (set_contains(sym_math_symbol_character_set_1, 134, lookahead)) ADVANCE(46);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(59);
      if (lookahead == '\\') ADVANCE(5);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 5:
      if (lookahead == '"') ADVANCE(60);
      if (lookahead == '\\') ADVANCE(5);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 6:
      if (lookahead == '\'') ADVANCE(57);
      if (lookahead == '\\') ADVANCE(7);
      if (lookahead != 0) ADVANCE(6);
      END_STATE();
    case 7:
      if (lookahead == '\'') ADVANCE(58);
      if (lookahead == '\\') ADVANCE(7);
      if (lookahead != 0) ADVANCE(6);
      END_STATE();
    case 8:
      if (lookahead == '-') ADVANCE(66);
      if (lookahead == '=') ADVANCE(70);
      if (lookahead == '~') ADVANCE(74);
      END_STATE();
    case 9:
      if (lookahead == '0') ADVANCE(50);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(49);
      END_STATE();
    case 10:
      ADVANCE_MAP(
        '<', 15,
        '%', 29,
        '*', 29,
        '+', 29,
        '-', 29,
        '/', 29,
        '=', 29,
        '^', 29,
        '|', 29,
        '~', 29,
      );
      END_STATE();
    case 11:
      if (lookahead == '=') ADVANCE(38);
      END_STATE();
    case 12:
      if (lookahead == '\\') ADVANCE(13);
      if (lookahead == '`') ADVANCE(61);
      if (lookahead != 0) ADVANCE(12);
      END_STATE();
    case 13:
      if (lookahead == '\\') ADVANCE(13);
      if (lookahead == '`') ADVANCE(62);
      if (lookahead != 0) ADVANCE(12);
      END_STATE();
    case 14:
      if (lookahead == '`') ADVANCE(63);
      if (lookahead != 0) ADVANCE(14);
      END_STATE();
    case 15:
      ADVANCE_MAP(
        '%', 29,
        '*', 29,
        '+', 29,
        '-', 29,
        '/', 29,
        '=', 29,
        '^', 29,
        '|', 29,
        '~', 29,
      );
      END_STATE();
    case 16:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(51);
      END_STATE();
    case 17:
      if (eof) ADVANCE(19);
      ADVANCE_MAP(
        '(', 24,
        ')', 25,
        ':', 32,
        '<', 10,
        '@', 23,
        '[', 21,
        ']', 22,
        '{', 33,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(17);
      if (lookahead == '%' ||
          lookahead == '*' ||
          lookahead == '+' ||
          lookahead == '-' ||
          lookahead == '/' ||
          lookahead == '=' ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(29);
      END_STATE();
    case 18:
      if (eof) ADVANCE(19);
      ADVANCE_MAP(
        '(', 24,
        ',', 20,
        '-', 65,
        '<', 8,
        '=', 68,
        '@', 23,
        '[', 21,
        ']', 22,
        '{', 33,
        '~', 72,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(18);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym_operator);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym_operator);
      ADVANCE_MAP(
        '0', 50,
        '>', 31,
        '%', 30,
        '*', 30,
        '+', 30,
        '-', 30,
        '/', 30,
        '=', 30,
        '^', 30,
        '|', 30,
        '~', 30,
      );
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(49);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_operator);
      if (lookahead == '>') ADVANCE(31);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_operator);
      ADVANCE_MAP(
        '>', 31,
        '%', 30,
        '*', 30,
        '+', 30,
        '-', 30,
        '/', 30,
        '=', 30,
        '^', 30,
        '|', 30,
        '~', 30,
      );
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_operator);
      ADVANCE_MAP(
        '>', 31,
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
    case 31:
      ACCEPT_TOKEN(sym_operator);
      if (lookahead == '>') ADVANCE(26);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(aux_sym_property_token1);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(aux_sym_property_token1);
      if (lookahead == ':') ADVANCE(38);
      if (lookahead == '=' ||
          lookahead == '~') ADVANCE(35);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(aux_sym_property_token1);
      if (lookahead == '=') ADVANCE(35);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(aux_sym_property_token1);
      if (lookahead == '=' ||
          lookahead == '~') ADVANCE(35);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_QMARK);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '-') ADVANCE(44);
      if (lookahead == '`') ADVANCE(14);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(44);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_greek);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_math_symbol);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_pictograph);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(16);
      if (lookahead == 'x') ADVANCE(55);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(54);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(16);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(49);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(16);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_decimal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(51);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_hexadecimal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(53);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(52);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_hexadecimal);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(53);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_octal);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(54);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_measurement);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(53);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(52);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_measurement);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_single_quoted_string);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_single_quoted_string);
      if (lookahead == '\'') ADVANCE(57);
      if (lookahead == '\\') ADVANCE(7);
      if (lookahead != 0) ADVANCE(6);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_double_quoted_string);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_double_quoted_string);
      if (lookahead == '"') ADVANCE(59);
      if (lookahead == '\\') ADVANCE(5);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_backticked_string);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_backticked_string);
      if (lookahead == '\\') ADVANCE(13);
      if (lookahead == '`') ADVANCE(61);
      if (lookahead != 0) ADVANCE(12);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_tagged_string);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '0') ADVANCE(50);
      if (lookahead == '>') ADVANCE(67);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(49);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '>') ADVANCE(67);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_LT_DASH);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '>') ADVANCE(71);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_EQ_GT);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_TILDE);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_TILDE);
      if (lookahead == '>') ADVANCE(75);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_LT_TILDE);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_TILDE_GT);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 18},
  [3] = {.lex_state = 2},
  [4] = {.lex_state = 2},
  [5] = {.lex_state = 3},
  [6] = {.lex_state = 2},
  [7] = {.lex_state = 2},
  [8] = {.lex_state = 2},
  [9] = {.lex_state = 2},
  [10] = {.lex_state = 2},
  [11] = {.lex_state = 2},
  [12] = {.lex_state = 2},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 2},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 2},
  [17] = {.lex_state = 18},
  [18] = {.lex_state = 18},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 17},
  [21] = {.lex_state = 17},
  [22] = {.lex_state = 17},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 17},
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
  [35] = {.lex_state = 17},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 17},
  [39] = {.lex_state = 17},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 17},
  [42] = {.lex_state = 17},
  [43] = {.lex_state = 17},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 17},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 17},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 18},
  [55] = {.lex_state = 18},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 17},
  [61] = {.lex_state = 17},
  [62] = {.lex_state = 17},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 18},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 18},
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
  [96] = {.lex_state = 1},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 0},
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
  [113] = {.lex_state = 0},
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
    [sym_greek] = ACTIONS(1),
    [sym_math_symbol] = ACTIONS(1),
    [sym_pictograph] = ACTIONS(1),
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
    [sym_gram] = STATE(101),
    [sym__description] = STATE(15),
    [sym_pattern] = STATE(15),
    [sym__patternComponent] = STATE(30),
    [sym_subject] = STATE(30),
    [sym_annotation] = STATE(19),
    [sym__path] = STATE(30),
    [sym_node] = STATE(2),
    [sym_relationship] = STATE(30),
    [sym_record] = STATE(15),
    [aux_sym_gram_repeat1] = STATE(15),
    [aux_sym_pattern_repeat1] = STATE(19),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(5),
    [anon_sym_AT] = ACTIONS(7),
    [anon_sym_LPAREN] = ACTIONS(9),
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
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
    STATE(44), 13,
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
  [43] = 6,
    ACTIONS(5), 1,
      anon_sym_LBRACK,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_node,
    ACTIONS(27), 5,
      sym_symbol,
      sym_pictograph,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(29), 8,
      sym_greek,
      sym_math_symbol,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
    STATE(47), 9,
      sym__patternComponent,
      sym_subject,
      sym__path,
      sym_relationship,
      sym__references,
      sym__member,
      sym__scalar,
      sym__numeric_literal,
      sym__string_literal,
  [81] = 6,
    ACTIONS(5), 1,
      anon_sym_LBRACK,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_node,
    ACTIONS(31), 5,
      sym_symbol,
      sym_pictograph,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(33), 8,
      sym_greek,
      sym_math_symbol,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
    STATE(71), 9,
      sym__patternComponent,
      sym_subject,
      sym__path,
      sym_relationship,
      sym__references,
      sym__member,
      sym__scalar,
      sym__numeric_literal,
      sym__string_literal,
  [119] = 11,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(35), 1,
      anon_sym_RBRACK,
    ACTIONS(37), 1,
      sym_operator,
    ACTIONS(39), 1,
      anon_sym_COLON,
    STATE(42), 1,
      sym_labels,
    STATE(60), 1,
      sym_record,
    STATE(62), 1,
      sym__attributes,
    STATE(99), 1,
      sym_members,
    STATE(24), 3,
      sym__scalar,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(41), 6,
      sym_symbol,
      sym_math_symbol,
      sym_pictograph,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(43), 7,
      sym_greek,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [166] = 9,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(39), 1,
      anon_sym_COLON,
    ACTIONS(45), 1,
      anon_sym_RPAREN,
    STATE(42), 1,
      sym_labels,
    STATE(60), 1,
      sym_record,
    STATE(97), 1,
      sym__attributes,
    STATE(24), 3,
      sym__scalar,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(41), 5,
      sym_symbol,
      sym_pictograph,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(43), 8,
      sym_greek,
      sym_math_symbol,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [207] = 8,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(39), 1,
      anon_sym_COLON,
    STATE(42), 1,
      sym_labels,
    STATE(60), 1,
      sym_record,
    STATE(88), 1,
      sym__attributes,
    STATE(24), 3,
      sym__scalar,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(41), 5,
      sym_symbol,
      sym_pictograph,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(43), 8,
      sym_greek,
      sym_math_symbol,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [245] = 8,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(39), 1,
      anon_sym_COLON,
    STATE(42), 1,
      sym_labels,
    STATE(60), 1,
      sym_record,
    STATE(84), 1,
      sym__attributes,
    STATE(24), 3,
      sym__scalar,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(41), 5,
      sym_symbol,
      sym_pictograph,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(43), 8,
      sym_greek,
      sym_math_symbol,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [283] = 8,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(39), 1,
      anon_sym_COLON,
    STATE(42), 1,
      sym_labels,
    STATE(60), 1,
      sym_record,
    STATE(85), 1,
      sym__attributes,
    STATE(24), 3,
      sym__scalar,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(41), 5,
      sym_symbol,
      sym_pictograph,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(43), 8,
      sym_greek,
      sym_math_symbol,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [321] = 8,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(39), 1,
      anon_sym_COLON,
    STATE(42), 1,
      sym_labels,
    STATE(60), 1,
      sym_record,
    STATE(86), 1,
      sym__attributes,
    STATE(24), 3,
      sym__scalar,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(41), 5,
      sym_symbol,
      sym_pictograph,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(43), 8,
      sym_greek,
      sym_math_symbol,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [359] = 8,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(39), 1,
      anon_sym_COLON,
    STATE(42), 1,
      sym_labels,
    STATE(60), 1,
      sym_record,
    STATE(87), 1,
      sym__attributes,
    STATE(24), 3,
      sym__scalar,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(41), 5,
      sym_symbol,
      sym_pictograph,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(43), 8,
      sym_greek,
      sym_math_symbol,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [397] = 8,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(39), 1,
      anon_sym_COLON,
    STATE(42), 1,
      sym_labels,
    STATE(60), 1,
      sym_record,
    STATE(89), 1,
      sym__attributes,
    STATE(24), 3,
      sym__scalar,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(41), 5,
      sym_symbol,
      sym_pictograph,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(43), 8,
      sym_greek,
      sym_math_symbol,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [435] = 9,
    ACTIONS(47), 1,
      ts_builtin_sym_end,
    ACTIONS(49), 1,
      anon_sym_LBRACK,
    ACTIONS(52), 1,
      anon_sym_AT,
    ACTIONS(55), 1,
      anon_sym_LPAREN,
    ACTIONS(58), 1,
      anon_sym_LBRACE,
    STATE(2), 1,
      sym_node,
    STATE(19), 2,
      sym_annotation,
      aux_sym_pattern_repeat1,
    STATE(13), 4,
      sym__description,
      sym_pattern,
      sym_record,
      aux_sym_gram_repeat1,
    STATE(30), 4,
      sym__patternComponent,
      sym_subject,
      sym__path,
      sym_relationship,
  [470] = 3,
    STATE(37), 3,
      sym__scalar,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(61), 5,
      sym_symbol,
      sym_pictograph,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(63), 8,
      sym_greek,
      sym_math_symbol,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [493] = 9,
    ACTIONS(5), 1,
      anon_sym_LBRACK,
    ACTIONS(7), 1,
      anon_sym_AT,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(65), 1,
      ts_builtin_sym_end,
    STATE(2), 1,
      sym_node,
    STATE(19), 2,
      sym_annotation,
      aux_sym_pattern_repeat1,
    STATE(13), 4,
      sym__description,
      sym_pattern,
      sym_record,
      aux_sym_gram_repeat1,
    STATE(30), 4,
      sym__patternComponent,
      sym_subject,
      sym__path,
      sym_relationship,
  [528] = 3,
    STATE(79), 3,
      sym__scalar,
      sym__numeric_literal,
      sym__string_literal,
    ACTIONS(67), 5,
      sym_symbol,
      sym_pictograph,
      sym_integer,
      sym_hexadecimal,
      sym_measurement,
    ACTIONS(69), 8,
      sym_greek,
      sym_math_symbol,
      sym_decimal,
      sym_octal,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
      sym_tagged_string,
  [551] = 1,
    ACTIONS(71), 13,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
      anon_sym_DASH,
      anon_sym_LT_DASH,
      anon_sym_EQ,
      anon_sym_LT_EQ,
      anon_sym_TILDE,
      anon_sym_LT_TILDE,
  [567] = 1,
    ACTIONS(73), 13,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
      anon_sym_DASH,
      anon_sym_LT_DASH,
      anon_sym_EQ,
      anon_sym_LT_EQ,
      anon_sym_TILDE,
      anon_sym_LT_TILDE,
  [583] = 6,
    ACTIONS(5), 1,
      anon_sym_LBRACK,
    ACTIONS(7), 1,
      anon_sym_AT,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_node,
    STATE(40), 2,
      sym_annotation,
      aux_sym_pattern_repeat1,
    STATE(32), 4,
      sym__patternComponent,
      sym_subject,
      sym__path,
      sym_relationship,
  [606] = 1,
    ACTIONS(75), 8,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      sym_operator,
      anon_sym_LBRACE,
  [617] = 1,
    ACTIONS(77), 8,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      sym_operator,
      anon_sym_LBRACE,
  [628] = 1,
    ACTIONS(79), 8,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      sym_operator,
      anon_sym_LBRACE,
  [639] = 1,
    ACTIONS(81), 7,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
  [649] = 5,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(39), 1,
      anon_sym_COLON,
    STATE(41), 1,
      sym_labels,
    STATE(61), 1,
      sym_record,
    ACTIONS(83), 3,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_operator,
  [667] = 3,
    ACTIONS(87), 1,
      anon_sym_COMMA,
    STATE(29), 1,
      aux_sym_pattern_repeat2,
    ACTIONS(85), 5,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
  [681] = 4,
    ACTIONS(5), 1,
      anon_sym_LBRACK,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_node,
    STATE(36), 4,
      sym__patternComponent,
      sym_subject,
      sym__path,
      sym_relationship,
  [697] = 3,
    ACTIONS(87), 1,
      anon_sym_COMMA,
    STATE(29), 1,
      aux_sym_pattern_repeat2,
    ACTIONS(89), 5,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
  [711] = 1,
    ACTIONS(91), 7,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
  [721] = 3,
    ACTIONS(95), 1,
      anon_sym_COMMA,
    STATE(29), 1,
      aux_sym_pattern_repeat2,
    ACTIONS(93), 5,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
  [735] = 3,
    ACTIONS(87), 1,
      anon_sym_COMMA,
    STATE(27), 1,
      aux_sym_pattern_repeat2,
    ACTIONS(98), 5,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
  [749] = 1,
    ACTIONS(100), 7,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
  [759] = 3,
    ACTIONS(87), 1,
      anon_sym_COMMA,
    STATE(25), 1,
      aux_sym_pattern_repeat2,
    ACTIONS(89), 5,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
  [773] = 1,
    ACTIONS(102), 7,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
  [783] = 1,
    ACTIONS(104), 7,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
  [793] = 3,
    ACTIONS(108), 1,
      anon_sym_COLON,
    STATE(38), 1,
      aux_sym_labels_repeat1,
    ACTIONS(106), 4,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_operator,
      anon_sym_LBRACE,
  [806] = 1,
    ACTIONS(93), 6,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LBRACK,
      anon_sym_AT,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
  [815] = 2,
    ACTIONS(110), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
    ACTIONS(112), 4,
      anon_sym_BANG,
      anon_sym_QMARK,
      anon_sym_STAR,
      anon_sym_PLUS,
  [826] = 3,
    ACTIONS(116), 1,
      anon_sym_COLON,
    STATE(38), 1,
      aux_sym_labels_repeat1,
    ACTIONS(114), 4,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_operator,
      anon_sym_LBRACE,
  [839] = 3,
    ACTIONS(108), 1,
      anon_sym_COLON,
    STATE(35), 1,
      aux_sym_labels_repeat1,
    ACTIONS(119), 4,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_operator,
      anon_sym_LBRACE,
  [852] = 3,
    ACTIONS(123), 1,
      anon_sym_AT,
    ACTIONS(121), 2,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
    STATE(40), 2,
      sym_annotation,
      aux_sym_pattern_repeat1,
  [864] = 3,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    STATE(51), 1,
      sym_record,
    ACTIONS(126), 3,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_operator,
  [876] = 3,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    STATE(46), 1,
      sym_record,
    ACTIONS(128), 3,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_operator,
  [888] = 1,
    ACTIONS(114), 5,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_operator,
      anon_sym_COLON,
      anon_sym_LBRACE,
  [896] = 3,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_node,
    STATE(23), 2,
      sym__path,
      sym_relationship,
  [907] = 3,
    ACTIONS(130), 1,
      anon_sym_LBRACK,
    ACTIONS(132), 1,
      anon_sym_TILDE,
    ACTIONS(134), 1,
      anon_sym_TILDE_GT,
  [917] = 1,
    ACTIONS(136), 3,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_operator,
  [923] = 3,
    ACTIONS(138), 1,
      anon_sym_COMMA,
    ACTIONS(140), 1,
      anon_sym_RBRACK,
    STATE(63), 1,
      aux_sym_members_repeat1,
  [933] = 3,
    ACTIONS(142), 1,
      anon_sym_COMMA,
    ACTIONS(145), 1,
      anon_sym_RBRACK,
    STATE(48), 1,
      aux_sym_members_repeat1,
  [943] = 3,
    ACTIONS(147), 1,
      anon_sym_LBRACK,
    ACTIONS(149), 1,
      anon_sym_TILDE,
    ACTIONS(151), 1,
      anon_sym_TILDE_GT,
  [953] = 3,
    ACTIONS(153), 1,
      anon_sym_COMMA,
    ACTIONS(155), 1,
      anon_sym_RBRACE,
    STATE(58), 1,
      aux_sym_record_repeat1,
  [963] = 1,
    ACTIONS(157), 3,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_operator,
  [969] = 3,
    ACTIONS(159), 1,
      anon_sym_LBRACK,
    ACTIONS(161), 1,
      anon_sym_EQ,
    ACTIONS(163), 1,
      anon_sym_EQ_GT,
  [979] = 3,
    ACTIONS(165), 1,
      anon_sym_LBRACK,
    ACTIONS(167), 1,
      anon_sym_EQ,
    ACTIONS(169), 1,
      anon_sym_EQ_GT,
  [989] = 3,
    ACTIONS(171), 1,
      anon_sym_LBRACK,
    ACTIONS(173), 1,
      anon_sym_DASH,
    ACTIONS(175), 1,
      anon_sym_DASH_GT,
  [999] = 3,
    ACTIONS(177), 1,
      anon_sym_LBRACK,
    ACTIONS(179), 1,
      anon_sym_DASH,
    ACTIONS(181), 1,
      anon_sym_DASH_GT,
  [1009] = 3,
    ACTIONS(153), 1,
      anon_sym_COMMA,
    ACTIONS(183), 1,
      anon_sym_RBRACE,
    STATE(50), 1,
      aux_sym_record_repeat1,
  [1019] = 1,
    ACTIONS(185), 3,
      anon_sym_LBRACK,
      anon_sym_AT,
      anon_sym_LPAREN,
  [1025] = 3,
    ACTIONS(187), 1,
      anon_sym_COMMA,
    ACTIONS(190), 1,
      anon_sym_RBRACE,
    STATE(58), 1,
      aux_sym_record_repeat1,
  [1035] = 3,
    ACTIONS(192), 1,
      anon_sym_RBRACE,
    ACTIONS(194), 1,
      sym_symbol,
    STATE(56), 1,
      sym_property,
  [1045] = 1,
    ACTIONS(196), 3,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_operator,
  [1051] = 1,
    ACTIONS(198), 3,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_operator,
  [1057] = 3,
    ACTIONS(200), 1,
      anon_sym_RBRACK,
    ACTIONS(202), 1,
      sym_operator,
    STATE(95), 1,
      sym_members,
  [1067] = 3,
    ACTIONS(138), 1,
      anon_sym_COMMA,
    ACTIONS(204), 1,
      anon_sym_RBRACK,
    STATE(48), 1,
      aux_sym_members_repeat1,
  [1077] = 1,
    ACTIONS(206), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [1082] = 2,
    ACTIONS(208), 1,
      anon_sym_EQ,
    ACTIONS(210), 1,
      anon_sym_EQ_GT,
  [1089] = 2,
    ACTIONS(212), 1,
      anon_sym_EQ,
    ACTIONS(214), 1,
      anon_sym_EQ_GT,
  [1096] = 2,
    ACTIONS(216), 1,
      anon_sym_TILDE,
    ACTIONS(218), 1,
      anon_sym_TILDE_GT,
  [1103] = 1,
    ACTIONS(190), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [1108] = 2,
    ACTIONS(220), 1,
      anon_sym_TILDE,
    ACTIONS(222), 1,
      anon_sym_TILDE_GT,
  [1115] = 2,
    ACTIONS(224), 1,
      anon_sym_DASH,
    ACTIONS(226), 1,
      anon_sym_DASH_GT,
  [1122] = 1,
    ACTIONS(145), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1127] = 2,
    ACTIONS(228), 1,
      anon_sym_DASH,
    ACTIONS(230), 1,
      anon_sym_DASH_GT,
  [1134] = 2,
    ACTIONS(194), 1,
      sym_symbol,
    STATE(68), 1,
      sym_property,
  [1141] = 1,
    ACTIONS(232), 1,
      anon_sym_LPAREN,
  [1145] = 1,
    ACTIONS(234), 1,
      sym_symbol,
  [1149] = 1,
    ACTIONS(236), 1,
      anon_sym_LPAREN,
  [1153] = 1,
    ACTIONS(238), 1,
      anon_sym_LPAREN,
  [1157] = 1,
    ACTIONS(240), 1,
      anon_sym_LPAREN,
  [1161] = 1,
    ACTIONS(242), 1,
      anon_sym_RPAREN,
  [1165] = 1,
    ACTIONS(244), 1,
      anon_sym_LPAREN,
  [1169] = 1,
    ACTIONS(246), 1,
      anon_sym_LPAREN,
  [1173] = 1,
    ACTIONS(248), 1,
      anon_sym_LPAREN,
  [1177] = 1,
    ACTIONS(250), 1,
      anon_sym_LPAREN,
  [1181] = 1,
    ACTIONS(252), 1,
      anon_sym_RBRACK,
  [1185] = 1,
    ACTIONS(254), 1,
      anon_sym_RBRACK,
  [1189] = 1,
    ACTIONS(256), 1,
      anon_sym_RBRACK,
  [1193] = 1,
    ACTIONS(258), 1,
      anon_sym_RBRACK,
  [1197] = 1,
    ACTIONS(260), 1,
      anon_sym_RBRACK,
  [1201] = 1,
    ACTIONS(262), 1,
      anon_sym_RBRACK,
  [1205] = 1,
    ACTIONS(264), 1,
      anon_sym_LPAREN,
  [1209] = 1,
    ACTIONS(266), 1,
      anon_sym_LPAREN,
  [1213] = 1,
    ACTIONS(268), 1,
      anon_sym_LPAREN,
  [1217] = 1,
    ACTIONS(270), 1,
      anon_sym_LPAREN,
  [1221] = 1,
    ACTIONS(272), 1,
      sym_symbol,
  [1225] = 1,
    ACTIONS(274), 1,
      anon_sym_RBRACK,
  [1229] = 1,
    ACTIONS(276), 1,
      aux_sym_property_token1,
  [1233] = 1,
    ACTIONS(278), 1,
      anon_sym_RPAREN,
  [1237] = 1,
    ACTIONS(280), 1,
      anon_sym_LPAREN,
  [1241] = 1,
    ACTIONS(282), 1,
      anon_sym_RBRACK,
  [1245] = 1,
    ACTIONS(284), 1,
      sym_symbol,
  [1249] = 1,
    ACTIONS(286), 1,
      ts_builtin_sym_end,
  [1253] = 1,
    ACTIONS(288), 1,
      anon_sym_LPAREN,
  [1257] = 1,
    ACTIONS(290), 1,
      anon_sym_LPAREN,
  [1261] = 1,
    ACTIONS(292), 1,
      anon_sym_LPAREN,
  [1265] = 1,
    ACTIONS(294), 1,
      anon_sym_LPAREN,
  [1269] = 1,
    ACTIONS(296), 1,
      anon_sym_LPAREN,
  [1273] = 1,
    ACTIONS(298), 1,
      anon_sym_LPAREN,
  [1277] = 1,
    ACTIONS(300), 1,
      anon_sym_LPAREN,
  [1281] = 1,
    ACTIONS(302), 1,
      anon_sym_LPAREN,
  [1285] = 1,
    ACTIONS(304), 1,
      anon_sym_LPAREN,
  [1289] = 1,
    ACTIONS(306), 1,
      anon_sym_LPAREN,
  [1293] = 1,
    ACTIONS(308), 1,
      anon_sym_LPAREN,
  [1297] = 1,
    ACTIONS(310), 1,
      anon_sym_LPAREN,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 43,
  [SMALL_STATE(4)] = 81,
  [SMALL_STATE(5)] = 119,
  [SMALL_STATE(6)] = 166,
  [SMALL_STATE(7)] = 207,
  [SMALL_STATE(8)] = 245,
  [SMALL_STATE(9)] = 283,
  [SMALL_STATE(10)] = 321,
  [SMALL_STATE(11)] = 359,
  [SMALL_STATE(12)] = 397,
  [SMALL_STATE(13)] = 435,
  [SMALL_STATE(14)] = 470,
  [SMALL_STATE(15)] = 493,
  [SMALL_STATE(16)] = 528,
  [SMALL_STATE(17)] = 551,
  [SMALL_STATE(18)] = 567,
  [SMALL_STATE(19)] = 583,
  [SMALL_STATE(20)] = 606,
  [SMALL_STATE(21)] = 617,
  [SMALL_STATE(22)] = 628,
  [SMALL_STATE(23)] = 639,
  [SMALL_STATE(24)] = 649,
  [SMALL_STATE(25)] = 667,
  [SMALL_STATE(26)] = 681,
  [SMALL_STATE(27)] = 697,
  [SMALL_STATE(28)] = 711,
  [SMALL_STATE(29)] = 721,
  [SMALL_STATE(30)] = 735,
  [SMALL_STATE(31)] = 749,
  [SMALL_STATE(32)] = 759,
  [SMALL_STATE(33)] = 773,
  [SMALL_STATE(34)] = 783,
  [SMALL_STATE(35)] = 793,
  [SMALL_STATE(36)] = 806,
  [SMALL_STATE(37)] = 815,
  [SMALL_STATE(38)] = 826,
  [SMALL_STATE(39)] = 839,
  [SMALL_STATE(40)] = 852,
  [SMALL_STATE(41)] = 864,
  [SMALL_STATE(42)] = 876,
  [SMALL_STATE(43)] = 888,
  [SMALL_STATE(44)] = 896,
  [SMALL_STATE(45)] = 907,
  [SMALL_STATE(46)] = 917,
  [SMALL_STATE(47)] = 923,
  [SMALL_STATE(48)] = 933,
  [SMALL_STATE(49)] = 943,
  [SMALL_STATE(50)] = 953,
  [SMALL_STATE(51)] = 963,
  [SMALL_STATE(52)] = 969,
  [SMALL_STATE(53)] = 979,
  [SMALL_STATE(54)] = 989,
  [SMALL_STATE(55)] = 999,
  [SMALL_STATE(56)] = 1009,
  [SMALL_STATE(57)] = 1019,
  [SMALL_STATE(58)] = 1025,
  [SMALL_STATE(59)] = 1035,
  [SMALL_STATE(60)] = 1045,
  [SMALL_STATE(61)] = 1051,
  [SMALL_STATE(62)] = 1057,
  [SMALL_STATE(63)] = 1067,
  [SMALL_STATE(64)] = 1077,
  [SMALL_STATE(65)] = 1082,
  [SMALL_STATE(66)] = 1089,
  [SMALL_STATE(67)] = 1096,
  [SMALL_STATE(68)] = 1103,
  [SMALL_STATE(69)] = 1108,
  [SMALL_STATE(70)] = 1115,
  [SMALL_STATE(71)] = 1122,
  [SMALL_STATE(72)] = 1127,
  [SMALL_STATE(73)] = 1134,
  [SMALL_STATE(74)] = 1141,
  [SMALL_STATE(75)] = 1145,
  [SMALL_STATE(76)] = 1149,
  [SMALL_STATE(77)] = 1153,
  [SMALL_STATE(78)] = 1157,
  [SMALL_STATE(79)] = 1161,
  [SMALL_STATE(80)] = 1165,
  [SMALL_STATE(81)] = 1169,
  [SMALL_STATE(82)] = 1173,
  [SMALL_STATE(83)] = 1177,
  [SMALL_STATE(84)] = 1181,
  [SMALL_STATE(85)] = 1185,
  [SMALL_STATE(86)] = 1189,
  [SMALL_STATE(87)] = 1193,
  [SMALL_STATE(88)] = 1197,
  [SMALL_STATE(89)] = 1201,
  [SMALL_STATE(90)] = 1205,
  [SMALL_STATE(91)] = 1209,
  [SMALL_STATE(92)] = 1213,
  [SMALL_STATE(93)] = 1217,
  [SMALL_STATE(94)] = 1221,
  [SMALL_STATE(95)] = 1225,
  [SMALL_STATE(96)] = 1229,
  [SMALL_STATE(97)] = 1233,
  [SMALL_STATE(98)] = 1237,
  [SMALL_STATE(99)] = 1241,
  [SMALL_STATE(100)] = 1245,
  [SMALL_STATE(101)] = 1249,
  [SMALL_STATE(102)] = 1253,
  [SMALL_STATE(103)] = 1257,
  [SMALL_STATE(104)] = 1261,
  [SMALL_STATE(105)] = 1265,
  [SMALL_STATE(106)] = 1269,
  [SMALL_STATE(107)] = 1273,
  [SMALL_STATE(108)] = 1277,
  [SMALL_STATE(109)] = 1281,
  [SMALL_STATE(110)] = 1285,
  [SMALL_STATE(111)] = 1289,
  [SMALL_STATE(112)] = 1293,
  [SMALL_STATE(113)] = 1297,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_gram, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__path, 1, 0, 0),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(71),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [41] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2, 0, 0),
  [49] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [52] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2, 0, 0), SHIFT_REPEAT(94),
  [55] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2, 0, 0), SHIFT_REPEAT(6),
  [58] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_gram_repeat1, 2, 0, 0), SHIFT_REPEAT(59),
  [61] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_gram, 1, 0, 0),
  [67] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 3, 0, 5),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 2, 0, 0),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record, 4, 0, 0),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record, 2, 0, 0),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record, 3, 0, 0),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relationship, 3, 0, 9),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 1, 0, 1),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pattern, 3, 0, 0),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pattern, 2, 0, 0),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_subject, 2, 0, 0),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pattern_repeat2, 2, 0, 0),
  [95] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_pattern_repeat2, 2, 0, 0), SHIFT_REPEAT(26),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pattern, 1, 0, 0),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_subject, 4, 0, 5),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_subject, 3, 0, 0),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_subject, 3, 0, 5),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_labels, 3, 0, 0),
  [108] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_property, 3, 0, 11),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_labels_repeat1, 2, 0, 0),
  [116] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_labels_repeat1, 2, 0, 0), SHIFT_REPEAT(75),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_labels, 2, 0, 0),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pattern_repeat1, 2, 0, 0),
  [123] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_pattern_repeat1, 2, 0, 0), SHIFT_REPEAT(94),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 2, 0, 6),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 1, 0, 2),
  [130] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [132] = {.entry = {.count = 1, .reusable = false}}, SHIFT(78),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 2, 0, 8),
  [138] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_members, 2, 0, 4),
  [142] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_members_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_members_repeat1, 2, 0, 0),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [149] = {.entry = {.count = 1, .reusable = false}}, SHIFT(82),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 3, 0, 10),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [161] = {.entry = {.count = 1, .reusable = false}}, SHIFT(93),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [167] = {.entry = {.count = 1, .reusable = false}}, SHIFT(90),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [173] = {.entry = {.count = 1, .reusable = false}}, SHIFT(92),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [179] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_annotation, 5, 0, 12),
  [187] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_record_repeat1, 2, 0, 0), SHIFT_REPEAT(73),
  [190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_record_repeat1, 2, 0, 0),
  [192] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 1, 0, 3),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 2, 0, 7),
  [200] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [202] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_members, 3, 0, 4),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_property, 4, 0, 13),
  [208] = {.entry = {.count = 1, .reusable = false}}, SHIFT(108),
  [210] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [212] = {.entry = {.count = 1, .reusable = false}}, SHIFT(106),
  [214] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [216] = {.entry = {.count = 1, .reusable = false}}, SHIFT(110),
  [218] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [220] = {.entry = {.count = 1, .reusable = false}}, SHIFT(112),
  [222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [224] = {.entry = {.count = 1, .reusable = false}}, SHIFT(104),
  [226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [228] = {.entry = {.count = 1, .reusable = false}}, SHIFT(102),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_right, 2, 0, 0),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_bidirectional, 2, 0, 0),
  [238] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_bidirectional, 2, 0, 0),
  [240] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_undirected, 2, 0, 0),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [244] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_right, 2, 0, 0),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_undirected, 2, 0, 0),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_left, 2, 0, 0),
  [250] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_bidirectional, 2, 0, 0),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [260] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [264] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_undirected, 2, 0, 0),
  [266] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_right, 2, 0, 0),
  [268] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_left, 2, 0, 0),
  [270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_left, 2, 0, 0),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [286] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [288] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_undirected, 5, 0, 14),
  [290] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_right, 5, 0, 14),
  [292] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_left, 5, 0, 14),
  [294] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_bidirectional, 5, 0, 14),
  [296] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_undirected, 5, 0, 14),
  [298] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_right, 5, 0, 14),
  [300] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_left, 5, 0, 14),
  [302] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_bidirectional, 5, 0, 14),
  [304] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_undirected, 5, 0, 14),
  [306] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_right, 5, 0, 14),
  [308] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_left, 5, 0, 14),
  [310] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_bidirectional, 5, 0, 14),
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
