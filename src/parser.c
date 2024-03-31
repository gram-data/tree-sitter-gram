#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 70
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 42
#define ALIAS_COUNT 0
#define TOKEN_COUNT 20
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 4

enum ts_symbol_identifiers {
  anon_sym_COMMA = 1,
  anon_sym_LPAREN = 2,
  anon_sym_RPAREN = 3,
  anon_sym_COLON = 4,
  sym_symbol = 5,
  sym_single_quoted_string = 6,
  sym_double_quoted_string = 7,
  sym_backticked_string = 8,
  anon_sym_DASH = 9,
  anon_sym_LBRACK = 10,
  anon_sym_RBRACK = 11,
  anon_sym_DASH_GT = 12,
  anon_sym_LT_DASH = 13,
  anon_sym_EQ = 14,
  aux_sym_double_arrow_right_token1 = 15,
  aux_sym_double_arrow_left_token1 = 16,
  anon_sym_TILDE = 17,
  anon_sym_TILDE_GT = 18,
  anon_sym_LT_TILDE = 19,
  sym_source_file = 20,
  sym_pattern = 21,
  sym_part = 22,
  sym_node = 23,
  sym_attributes = 24,
  sym__identifier = 25,
  sym_labels = 26,
  sym__string_literal = 27,
  sym__relationship = 28,
  sym_undirected_single = 29,
  sym_single_arrow_right = 30,
  sym_single_arrow_left = 31,
  sym_undirected_double_arrow = 32,
  sym_double_arrow_right = 33,
  sym_double_arrow_left = 34,
  sym_undirected_squiggle = 35,
  sym_squiggle_arrow_right = 36,
  sym_squiggle_arrow_left = 37,
  aux_sym_source_file_repeat1 = 38,
  aux_sym_pattern_repeat1 = 39,
  aux_sym_part_repeat1 = 40,
  aux_sym_labels_repeat1 = 41,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_COMMA] = ",",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_COLON] = ":",
  [sym_symbol] = "symbol",
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
  [sym_source_file] = "source_file",
  [sym_pattern] = "pattern",
  [sym_part] = "part",
  [sym_node] = "node",
  [sym_attributes] = "attributes",
  [sym__identifier] = "_identifier",
  [sym_labels] = "labels",
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
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_pattern_repeat1] = "pattern_repeat1",
  [aux_sym_part_repeat1] = "part_repeat1",
  [aux_sym_labels_repeat1] = "labels_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_COLON] = anon_sym_COLON,
  [sym_symbol] = sym_symbol,
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
  [sym_source_file] = sym_source_file,
  [sym_pattern] = sym_pattern,
  [sym_part] = sym_part,
  [sym_node] = sym_node,
  [sym_attributes] = sym_attributes,
  [sym__identifier] = sym__identifier,
  [sym_labels] = sym_labels,
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
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_pattern_repeat1] = aux_sym_pattern_repeat1,
  [aux_sym_part_repeat1] = aux_sym_part_repeat1,
  [aux_sym_labels_repeat1] = aux_sym_labels_repeat1,
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
  [sym_symbol] = {
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
  [sym_source_file] = {
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
  [aux_sym_source_file_repeat1] = {
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
};

enum ts_field_identifiers {
  field_identifier = 1,
  field_labels = 2,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_identifier] = "identifier",
  [field_labels] = "labels",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_identifier, 0},
  [1] =
    {field_labels, 0},
  [2] =
    {field_identifier, 0},
    {field_labels, 1},
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(11);
      if (lookahead == '"') ADVANCE(1);
      if (lookahead == '\'') ADVANCE(3);
      if (lookahead == '(') ADVANCE(13);
      if (lookahead == ')') ADVANCE(14);
      if (lookahead == ',') ADVANCE(12);
      if (lookahead == '-') ADVANCE(24);
      if (lookahead == ':') ADVANCE(15);
      if (lookahead == '<') ADVANCE(5);
      if (lookahead == '=') ADVANCE(30);
      if (lookahead == '>') ADVANCE(6);
      if (lookahead == '[') ADVANCE(25);
      if (lookahead == ']') ADVANCE(26);
      if (lookahead == '`') ADVANCE(8);
      if (lookahead == '~') ADVANCE(35);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(19);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(20);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 3:
      if (lookahead == '\'') ADVANCE(17);
      if (lookahead == '\\') ADVANCE(4);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 4:
      if (lookahead == '\'') ADVANCE(18);
      if (lookahead == '\\') ADVANCE(4);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 5:
      if (lookahead == '-') ADVANCE(28);
      if (lookahead == '=') ADVANCE(33);
      if (lookahead == '~') ADVANCE(37);
      END_STATE();
    case 6:
      if (lookahead == '=') ADVANCE(7);
      END_STATE();
    case 7:
      if (lookahead == '>') ADVANCE(31);
      END_STATE();
    case 8:
      if (lookahead == '\\') ADVANCE(9);
      if (lookahead == '`') ADVANCE(21);
      if (lookahead != 0) ADVANCE(8);
      END_STATE();
    case 9:
      if (lookahead == '\\') ADVANCE(9);
      if (lookahead == '`') ADVANCE(22);
      if (lookahead != 0) ADVANCE(8);
      END_STATE();
    case 10:
      if (eof) ADVANCE(11);
      if (lookahead == '(') ADVANCE(13);
      if (lookahead == ',') ADVANCE(12);
      if (lookahead == '-') ADVANCE(23);
      if (lookahead == '<') ADVANCE(5);
      if (lookahead == '=') ADVANCE(29);
      if (lookahead == '[') ADVANCE(25);
      if (lookahead == '~') ADVANCE(34);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(10)
      END_STATE();
    case 11:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(sym_single_quoted_string);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(sym_single_quoted_string);
      if (lookahead == '\'') ADVANCE(17);
      if (lookahead == '\\') ADVANCE(4);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(sym_double_quoted_string);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym_double_quoted_string);
      if (lookahead == '"') ADVANCE(19);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym_backticked_string);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym_backticked_string);
      if (lookahead == '\\') ADVANCE(9);
      if (lookahead == '`') ADVANCE(21);
      if (lookahead != 0) ADVANCE(8);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '>') ADVANCE(27);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_LT_DASH);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '>') ADVANCE(31);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(aux_sym_double_arrow_right_token1);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(aux_sym_double_arrow_left_token1);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(aux_sym_double_arrow_left_token1);
      if (lookahead == '<') ADVANCE(32);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_TILDE);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_TILDE);
      if (lookahead == '>') ADVANCE(36);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_TILDE_GT);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_LT_TILDE);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 10},
  [3] = {.lex_state = 10},
  [4] = {.lex_state = 10},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 10},
  [8] = {.lex_state = 10},
  [9] = {.lex_state = 10},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
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
  [34] = {.lex_state = 10},
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
  [58] = {.lex_state = 10},
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
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [sym_symbol] = ACTIONS(1),
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
    [sym_source_file] = STATE(53),
    [sym_pattern] = STATE(15),
    [sym_part] = STATE(18),
    [sym_node] = STATE(4),
    [aux_sym_source_file_repeat1] = STATE(15),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 9,
    ACTIONS(9), 1,
      anon_sym_DASH,
    ACTIONS(12), 1,
      anon_sym_LT_DASH,
    ACTIONS(15), 1,
      anon_sym_EQ,
    ACTIONS(18), 1,
      aux_sym_double_arrow_left_token1,
    ACTIONS(21), 1,
      anon_sym_TILDE,
    ACTIONS(24), 1,
      anon_sym_LT_TILDE,
    STATE(2), 1,
      aux_sym_part_repeat1,
    ACTIONS(7), 3,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
    STATE(32), 10,
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
    ACTIONS(29), 1,
      anon_sym_DASH,
    ACTIONS(31), 1,
      anon_sym_LT_DASH,
    ACTIONS(33), 1,
      anon_sym_EQ,
    ACTIONS(35), 1,
      aux_sym_double_arrow_left_token1,
    ACTIONS(37), 1,
      anon_sym_TILDE,
    ACTIONS(39), 1,
      anon_sym_LT_TILDE,
    STATE(2), 1,
      aux_sym_part_repeat1,
    ACTIONS(27), 3,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
    STATE(32), 10,
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
    ACTIONS(29), 1,
      anon_sym_DASH,
    ACTIONS(31), 1,
      anon_sym_LT_DASH,
    ACTIONS(33), 1,
      anon_sym_EQ,
    ACTIONS(35), 1,
      aux_sym_double_arrow_left_token1,
    ACTIONS(37), 1,
      anon_sym_TILDE,
    ACTIONS(39), 1,
      anon_sym_LT_TILDE,
    STATE(3), 1,
      aux_sym_part_repeat1,
    ACTIONS(41), 3,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
    STATE(32), 10,
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
  [117] = 6,
    ACTIONS(43), 1,
      anon_sym_RPAREN,
    ACTIONS(45), 1,
      anon_sym_COLON,
    STATE(36), 1,
      sym_labels,
    STATE(57), 1,
      sym_attributes,
    STATE(22), 2,
      sym__identifier,
      sym__string_literal,
    ACTIONS(47), 4,
      sym_symbol,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
  [140] = 5,
    ACTIONS(45), 1,
      anon_sym_COLON,
    STATE(36), 1,
      sym_labels,
    STATE(48), 1,
      sym_attributes,
    STATE(22), 2,
      sym__identifier,
      sym__string_literal,
    ACTIONS(47), 4,
      sym_symbol,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
  [160] = 1,
    ACTIONS(49), 9,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_LT_DASH,
      anon_sym_EQ,
      aux_sym_double_arrow_left_token1,
      anon_sym_TILDE,
      anon_sym_LT_TILDE,
  [172] = 1,
    ACTIONS(51), 9,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_LT_DASH,
      anon_sym_EQ,
      aux_sym_double_arrow_left_token1,
      anon_sym_TILDE,
      anon_sym_LT_TILDE,
  [184] = 1,
    ACTIONS(7), 9,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_LT_DASH,
      anon_sym_EQ,
      aux_sym_double_arrow_left_token1,
      anon_sym_TILDE,
      anon_sym_LT_TILDE,
  [196] = 5,
    ACTIONS(45), 1,
      anon_sym_COLON,
    STATE(36), 1,
      sym_labels,
    STATE(52), 1,
      sym_attributes,
    STATE(22), 2,
      sym__identifier,
      sym__string_literal,
    ACTIONS(47), 4,
      sym_symbol,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
  [216] = 5,
    ACTIONS(45), 1,
      anon_sym_COLON,
    STATE(36), 1,
      sym_labels,
    STATE(47), 1,
      sym_attributes,
    STATE(22), 2,
      sym__identifier,
      sym__string_literal,
    ACTIONS(47), 4,
      sym_symbol,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
  [236] = 5,
    ACTIONS(45), 1,
      anon_sym_COLON,
    STATE(36), 1,
      sym_labels,
    STATE(51), 1,
      sym_attributes,
    STATE(22), 2,
      sym__identifier,
      sym__string_literal,
    ACTIONS(47), 4,
      sym_symbol,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
  [256] = 5,
    ACTIONS(45), 1,
      anon_sym_COLON,
    STATE(36), 1,
      sym_labels,
    STATE(50), 1,
      sym_attributes,
    STATE(22), 2,
      sym__identifier,
      sym__string_literal,
    ACTIONS(47), 4,
      sym_symbol,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
  [276] = 5,
    ACTIONS(45), 1,
      anon_sym_COLON,
    STATE(36), 1,
      sym_labels,
    STATE(49), 1,
      sym_attributes,
    STATE(22), 2,
      sym__identifier,
      sym__string_literal,
    ACTIONS(47), 4,
      sym_symbol,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
  [296] = 5,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    ACTIONS(53), 1,
      ts_builtin_sym_end,
    STATE(4), 1,
      sym_node,
    STATE(18), 1,
      sym_part,
    STATE(16), 2,
      sym_pattern,
      aux_sym_source_file_repeat1,
  [313] = 5,
    ACTIONS(55), 1,
      ts_builtin_sym_end,
    ACTIONS(57), 1,
      anon_sym_LPAREN,
    STATE(4), 1,
      sym_node,
    STATE(18), 1,
      sym_part,
    STATE(16), 2,
      sym_pattern,
      aux_sym_source_file_repeat1,
  [330] = 3,
    ACTIONS(62), 1,
      anon_sym_COMMA,
    STATE(21), 1,
      aux_sym_pattern_repeat1,
    ACTIONS(60), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [341] = 3,
    ACTIONS(62), 1,
      anon_sym_COMMA,
    STATE(17), 1,
      aux_sym_pattern_repeat1,
    ACTIONS(64), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [352] = 3,
    ACTIONS(68), 1,
      anon_sym_COLON,
    STATE(20), 1,
      aux_sym_labels_repeat1,
    ACTIONS(66), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [363] = 3,
    ACTIONS(72), 1,
      anon_sym_COLON,
    STATE(20), 1,
      aux_sym_labels_repeat1,
    ACTIONS(70), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [374] = 3,
    ACTIONS(77), 1,
      anon_sym_COMMA,
    STATE(21), 1,
      aux_sym_pattern_repeat1,
    ACTIONS(75), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [385] = 3,
    ACTIONS(45), 1,
      anon_sym_COLON,
    STATE(30), 1,
      sym_labels,
    ACTIONS(80), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [396] = 3,
    ACTIONS(68), 1,
      anon_sym_COLON,
    STATE(19), 1,
      aux_sym_labels_repeat1,
    ACTIONS(82), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [407] = 3,
    ACTIONS(84), 1,
      anon_sym_LBRACK,
    ACTIONS(86), 1,
      anon_sym_TILDE,
    ACTIONS(88), 1,
      anon_sym_TILDE_GT,
  [417] = 1,
    ACTIONS(75), 3,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
  [423] = 1,
    ACTIONS(70), 3,
      anon_sym_RPAREN,
      anon_sym_COLON,
      anon_sym_RBRACK,
  [429] = 3,
    ACTIONS(90), 1,
      anon_sym_LBRACK,
    ACTIONS(92), 1,
      anon_sym_EQ,
    ACTIONS(94), 1,
      aux_sym_double_arrow_right_token1,
  [439] = 3,
    ACTIONS(96), 1,
      anon_sym_DASH,
    ACTIONS(98), 1,
      anon_sym_LBRACK,
    ACTIONS(100), 1,
      anon_sym_DASH_GT,
  [449] = 3,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    STATE(4), 1,
      sym_node,
    STATE(25), 1,
      sym_part,
  [459] = 1,
    ACTIONS(102), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [464] = 2,
    ACTIONS(104), 1,
      anon_sym_TILDE,
    ACTIONS(106), 1,
      anon_sym_TILDE_GT,
  [471] = 2,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    STATE(9), 1,
      sym_node,
  [478] = 2,
    ACTIONS(108), 1,
      anon_sym_LBRACK,
    ACTIONS(110), 1,
      anon_sym_TILDE,
  [485] = 2,
    ACTIONS(112), 1,
      anon_sym_LBRACK,
    ACTIONS(114), 1,
      anon_sym_EQ,
  [492] = 2,
    ACTIONS(116), 1,
      anon_sym_DASH,
    ACTIONS(118), 1,
      anon_sym_LBRACK,
  [499] = 1,
    ACTIONS(120), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [504] = 2,
    ACTIONS(122), 1,
      anon_sym_DASH,
    ACTIONS(124), 1,
      anon_sym_DASH_GT,
  [511] = 2,
    ACTIONS(126), 1,
      anon_sym_EQ,
    ACTIONS(128), 1,
      aux_sym_double_arrow_right_token1,
  [518] = 1,
    ACTIONS(130), 1,
      anon_sym_LPAREN,
  [522] = 1,
    ACTIONS(132), 1,
      anon_sym_LPAREN,
  [526] = 1,
    ACTIONS(134), 1,
      anon_sym_LPAREN,
  [530] = 1,
    ACTIONS(136), 1,
      anon_sym_LPAREN,
  [534] = 1,
    ACTIONS(138), 1,
      anon_sym_LPAREN,
  [538] = 1,
    ACTIONS(140), 1,
      anon_sym_LPAREN,
  [542] = 1,
    ACTIONS(142), 1,
      sym_symbol,
  [546] = 1,
    ACTIONS(144), 1,
      anon_sym_LPAREN,
  [550] = 1,
    ACTIONS(146), 1,
      anon_sym_RBRACK,
  [554] = 1,
    ACTIONS(148), 1,
      anon_sym_RBRACK,
  [558] = 1,
    ACTIONS(150), 1,
      anon_sym_RBRACK,
  [562] = 1,
    ACTIONS(152), 1,
      anon_sym_RBRACK,
  [566] = 1,
    ACTIONS(154), 1,
      anon_sym_RBRACK,
  [570] = 1,
    ACTIONS(156), 1,
      anon_sym_RBRACK,
  [574] = 1,
    ACTIONS(158), 1,
      ts_builtin_sym_end,
  [578] = 1,
    ACTIONS(160), 1,
      anon_sym_LPAREN,
  [582] = 1,
    ACTIONS(162), 1,
      anon_sym_LPAREN,
  [586] = 1,
    ACTIONS(164), 1,
      anon_sym_DASH,
  [590] = 1,
    ACTIONS(166), 1,
      anon_sym_RPAREN,
  [594] = 1,
    ACTIONS(168), 1,
      anon_sym_EQ,
  [598] = 1,
    ACTIONS(170), 1,
      sym_symbol,
  [602] = 1,
    ACTIONS(172), 1,
      anon_sym_TILDE,
  [606] = 1,
    ACTIONS(174), 1,
      anon_sym_LPAREN,
  [610] = 1,
    ACTIONS(176), 1,
      anon_sym_LPAREN,
  [614] = 1,
    ACTIONS(178), 1,
      anon_sym_LPAREN,
  [618] = 1,
    ACTIONS(180), 1,
      anon_sym_LPAREN,
  [622] = 1,
    ACTIONS(182), 1,
      anon_sym_LPAREN,
  [626] = 1,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
  [630] = 1,
    ACTIONS(186), 1,
      anon_sym_LPAREN,
  [634] = 1,
    ACTIONS(188), 1,
      anon_sym_LPAREN,
  [638] = 1,
    ACTIONS(190), 1,
      anon_sym_LPAREN,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 39,
  [SMALL_STATE(4)] = 78,
  [SMALL_STATE(5)] = 117,
  [SMALL_STATE(6)] = 140,
  [SMALL_STATE(7)] = 160,
  [SMALL_STATE(8)] = 172,
  [SMALL_STATE(9)] = 184,
  [SMALL_STATE(10)] = 196,
  [SMALL_STATE(11)] = 216,
  [SMALL_STATE(12)] = 236,
  [SMALL_STATE(13)] = 256,
  [SMALL_STATE(14)] = 276,
  [SMALL_STATE(15)] = 296,
  [SMALL_STATE(16)] = 313,
  [SMALL_STATE(17)] = 330,
  [SMALL_STATE(18)] = 341,
  [SMALL_STATE(19)] = 352,
  [SMALL_STATE(20)] = 363,
  [SMALL_STATE(21)] = 374,
  [SMALL_STATE(22)] = 385,
  [SMALL_STATE(23)] = 396,
  [SMALL_STATE(24)] = 407,
  [SMALL_STATE(25)] = 417,
  [SMALL_STATE(26)] = 423,
  [SMALL_STATE(27)] = 429,
  [SMALL_STATE(28)] = 439,
  [SMALL_STATE(29)] = 449,
  [SMALL_STATE(30)] = 459,
  [SMALL_STATE(31)] = 464,
  [SMALL_STATE(32)] = 471,
  [SMALL_STATE(33)] = 478,
  [SMALL_STATE(34)] = 485,
  [SMALL_STATE(35)] = 492,
  [SMALL_STATE(36)] = 499,
  [SMALL_STATE(37)] = 504,
  [SMALL_STATE(38)] = 511,
  [SMALL_STATE(39)] = 518,
  [SMALL_STATE(40)] = 522,
  [SMALL_STATE(41)] = 526,
  [SMALL_STATE(42)] = 530,
  [SMALL_STATE(43)] = 534,
  [SMALL_STATE(44)] = 538,
  [SMALL_STATE(45)] = 542,
  [SMALL_STATE(46)] = 546,
  [SMALL_STATE(47)] = 550,
  [SMALL_STATE(48)] = 554,
  [SMALL_STATE(49)] = 558,
  [SMALL_STATE(50)] = 562,
  [SMALL_STATE(51)] = 566,
  [SMALL_STATE(52)] = 570,
  [SMALL_STATE(53)] = 574,
  [SMALL_STATE(54)] = 578,
  [SMALL_STATE(55)] = 582,
  [SMALL_STATE(56)] = 586,
  [SMALL_STATE(57)] = 590,
  [SMALL_STATE(58)] = 594,
  [SMALL_STATE(59)] = 598,
  [SMALL_STATE(60)] = 602,
  [SMALL_STATE(61)] = 606,
  [SMALL_STATE(62)] = 610,
  [SMALL_STATE(63)] = 614,
  [SMALL_STATE(64)] = 618,
  [SMALL_STATE(65)] = 622,
  [SMALL_STATE(66)] = 626,
  [SMALL_STATE(67)] = 630,
  [SMALL_STATE(68)] = 634,
  [SMALL_STATE(69)] = 638,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_part_repeat1, 2),
  [9] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_part_repeat1, 2), SHIFT_REPEAT(28),
  [12] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_part_repeat1, 2), SHIFT_REPEAT(35),
  [15] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_part_repeat1, 2), SHIFT_REPEAT(27),
  [18] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_part_repeat1, 2), SHIFT_REPEAT(34),
  [21] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_part_repeat1, 2), SHIFT_REPEAT(24),
  [24] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_part_repeat1, 2), SHIFT_REPEAT(33),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_part, 2),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_part, 1),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 3),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 2),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [57] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(5),
  [60] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pattern, 2),
  [62] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [64] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pattern, 1),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_labels, 3),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_labels_repeat1, 2),
  [72] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_labels_repeat1, 2), SHIFT_REPEAT(45),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pattern_repeat1, 2),
  [77] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_pattern_repeat1, 2), SHIFT_REPEAT(29),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attributes, 1, .production_id = 1),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_labels, 2),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [86] = {.entry = {.count = 1, .reusable = false}}, SHIFT(46),
  [88] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [90] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [92] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [94] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [96] = {.entry = {.count = 1, .reusable = false}}, SHIFT(55),
  [98] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [100] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attributes, 2, .production_id = 3),
  [104] = {.entry = {.count = 1, .reusable = false}}, SHIFT(67),
  [106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [108] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [110] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [114] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [116] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [118] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attributes, 1, .production_id = 2),
  [122] = {.entry = {.count = 1, .reusable = false}}, SHIFT(61),
  [124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [126] = {.entry = {.count = 1, .reusable = false}}, SHIFT(64),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_double_arrow, 2),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_arrow_right, 2),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_arrow_left, 2),
  [136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_arrow_left, 2),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_arrow_left, 2),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_arrow_right, 2),
  [142] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [144] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_squiggle, 2),
  [146] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [150] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [158] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_arrow_right, 2),
  [162] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_single, 2),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [168] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [172] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [174] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_single, 5),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_arrow_right, 5),
  [178] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_arrow_left, 5),
  [180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_double_arrow, 5),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_arrow_right, 5),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_arrow_left, 5),
  [186] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_squiggle, 5),
  [188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_arrow_right, 5),
  [190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_arrow_left, 5),
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
