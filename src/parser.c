#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 68
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 41
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
  sym__node_pattern = 22,
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
  aux_sym_labels_repeat1 = 40,
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
  [sym__node_pattern] = "_node_pattern",
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
  [sym__node_pattern] = sym__node_pattern,
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
  [sym__node_pattern] = {
    .visible = false,
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
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 10},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 10},
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
  [33] = {.lex_state = 10},
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
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 10},
  [57] = {.lex_state = 0},
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
    [sym_source_file] = STATE(40),
    [sym_pattern] = STATE(12),
    [sym__node_pattern] = STATE(14),
    [sym_node] = STATE(2),
    [aux_sym_source_file_repeat1] = STATE(12),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 8,
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
    ACTIONS(7), 3,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
    STATE(24), 10,
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
  [36] = 6,
    ACTIONS(21), 1,
      anon_sym_RPAREN,
    ACTIONS(23), 1,
      anon_sym_COLON,
    STATE(35), 1,
      sym_labels,
    STATE(51), 1,
      sym_attributes,
    STATE(17), 2,
      sym__identifier,
      sym__string_literal,
    ACTIONS(25), 4,
      sym_symbol,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
  [59] = 5,
    ACTIONS(23), 1,
      anon_sym_COLON,
    STATE(35), 1,
      sym_labels,
    STATE(47), 1,
      sym_attributes,
    STATE(17), 2,
      sym__identifier,
      sym__string_literal,
    ACTIONS(25), 4,
      sym_symbol,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
  [79] = 1,
    ACTIONS(27), 9,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_LT_DASH,
      anon_sym_EQ,
      aux_sym_double_arrow_left_token1,
      anon_sym_TILDE,
      anon_sym_LT_TILDE,
  [91] = 5,
    ACTIONS(23), 1,
      anon_sym_COLON,
    STATE(35), 1,
      sym_labels,
    STATE(50), 1,
      sym_attributes,
    STATE(17), 2,
      sym__identifier,
      sym__string_literal,
    ACTIONS(25), 4,
      sym_symbol,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
  [111] = 5,
    ACTIONS(23), 1,
      anon_sym_COLON,
    STATE(35), 1,
      sym_labels,
    STATE(49), 1,
      sym_attributes,
    STATE(17), 2,
      sym__identifier,
      sym__string_literal,
    ACTIONS(25), 4,
      sym_symbol,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
  [131] = 5,
    ACTIONS(23), 1,
      anon_sym_COLON,
    STATE(35), 1,
      sym_labels,
    STATE(48), 1,
      sym_attributes,
    STATE(17), 2,
      sym__identifier,
      sym__string_literal,
    ACTIONS(25), 4,
      sym_symbol,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
  [151] = 5,
    ACTIONS(23), 1,
      anon_sym_COLON,
    STATE(35), 1,
      sym_labels,
    STATE(46), 1,
      sym_attributes,
    STATE(17), 2,
      sym__identifier,
      sym__string_literal,
    ACTIONS(25), 4,
      sym_symbol,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
  [171] = 5,
    ACTIONS(23), 1,
      anon_sym_COLON,
    STATE(35), 1,
      sym_labels,
    STATE(45), 1,
      sym_attributes,
    STATE(17), 2,
      sym__identifier,
      sym__string_literal,
    ACTIONS(25), 4,
      sym_symbol,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_backticked_string,
  [191] = 1,
    ACTIONS(29), 9,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_LT_DASH,
      anon_sym_EQ,
      aux_sym_double_arrow_left_token1,
      anon_sym_TILDE,
      anon_sym_LT_TILDE,
  [203] = 5,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      ts_builtin_sym_end,
    STATE(2), 1,
      sym_node,
    STATE(14), 1,
      sym__node_pattern,
    STATE(13), 2,
      sym_pattern,
      aux_sym_source_file_repeat1,
  [220] = 5,
    ACTIONS(33), 1,
      ts_builtin_sym_end,
    ACTIONS(35), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_node,
    STATE(14), 1,
      sym__node_pattern,
    STATE(13), 2,
      sym_pattern,
      aux_sym_source_file_repeat1,
  [237] = 3,
    ACTIONS(40), 1,
      anon_sym_COMMA,
    STATE(18), 1,
      aux_sym_pattern_repeat1,
    ACTIONS(38), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [248] = 3,
    ACTIONS(44), 1,
      anon_sym_COLON,
    STATE(15), 1,
      aux_sym_labels_repeat1,
    ACTIONS(42), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [259] = 3,
    ACTIONS(49), 1,
      anon_sym_COLON,
    STATE(15), 1,
      aux_sym_labels_repeat1,
    ACTIONS(47), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [270] = 3,
    ACTIONS(23), 1,
      anon_sym_COLON,
    STATE(32), 1,
      sym_labels,
    ACTIONS(51), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [281] = 3,
    ACTIONS(40), 1,
      anon_sym_COMMA,
    STATE(20), 1,
      aux_sym_pattern_repeat1,
    ACTIONS(53), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [292] = 3,
    ACTIONS(49), 1,
      anon_sym_COLON,
    STATE(16), 1,
      aux_sym_labels_repeat1,
    ACTIONS(55), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [303] = 3,
    ACTIONS(59), 1,
      anon_sym_COMMA,
    STATE(20), 1,
      aux_sym_pattern_repeat1,
    ACTIONS(57), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [314] = 1,
    ACTIONS(42), 3,
      anon_sym_RPAREN,
      anon_sym_COLON,
      anon_sym_RBRACK,
  [320] = 3,
    ACTIONS(62), 1,
      anon_sym_DASH,
    ACTIONS(64), 1,
      anon_sym_LBRACK,
    ACTIONS(66), 1,
      anon_sym_DASH_GT,
  [330] = 3,
    ACTIONS(68), 1,
      anon_sym_LBRACK,
    ACTIONS(70), 1,
      anon_sym_TILDE,
    ACTIONS(72), 1,
      anon_sym_TILDE_GT,
  [340] = 3,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_node,
    STATE(25), 1,
      sym__node_pattern,
  [350] = 1,
    ACTIONS(74), 3,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
  [356] = 1,
    ACTIONS(57), 3,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
  [362] = 3,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_node,
    STATE(26), 1,
      sym__node_pattern,
  [372] = 3,
    ACTIONS(76), 1,
      anon_sym_LBRACK,
    ACTIONS(78), 1,
      anon_sym_EQ,
    ACTIONS(80), 1,
      aux_sym_double_arrow_right_token1,
  [382] = 2,
    ACTIONS(82), 1,
      anon_sym_EQ,
    ACTIONS(84), 1,
      aux_sym_double_arrow_right_token1,
  [389] = 2,
    ACTIONS(86), 1,
      anon_sym_LBRACK,
    ACTIONS(88), 1,
      anon_sym_TILDE,
  [396] = 2,
    ACTIONS(90), 1,
      anon_sym_TILDE,
    ACTIONS(92), 1,
      anon_sym_TILDE_GT,
  [403] = 1,
    ACTIONS(94), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [408] = 2,
    ACTIONS(96), 1,
      anon_sym_LBRACK,
    ACTIONS(98), 1,
      anon_sym_EQ,
  [415] = 2,
    ACTIONS(100), 1,
      anon_sym_DASH,
    ACTIONS(102), 1,
      anon_sym_DASH_GT,
  [422] = 1,
    ACTIONS(104), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [427] = 2,
    ACTIONS(106), 1,
      anon_sym_DASH,
    ACTIONS(108), 1,
      anon_sym_LBRACK,
  [434] = 1,
    ACTIONS(110), 1,
      anon_sym_LPAREN,
  [438] = 1,
    ACTIONS(112), 1,
      sym_symbol,
  [442] = 1,
    ACTIONS(114), 1,
      anon_sym_LPAREN,
  [446] = 1,
    ACTIONS(116), 1,
      ts_builtin_sym_end,
  [450] = 1,
    ACTIONS(118), 1,
      anon_sym_LPAREN,
  [454] = 1,
    ACTIONS(120), 1,
      anon_sym_LPAREN,
  [458] = 1,
    ACTIONS(122), 1,
      sym_symbol,
  [462] = 1,
    ACTIONS(124), 1,
      anon_sym_LPAREN,
  [466] = 1,
    ACTIONS(126), 1,
      anon_sym_RBRACK,
  [470] = 1,
    ACTIONS(128), 1,
      anon_sym_RBRACK,
  [474] = 1,
    ACTIONS(130), 1,
      anon_sym_RBRACK,
  [478] = 1,
    ACTIONS(132), 1,
      anon_sym_RBRACK,
  [482] = 1,
    ACTIONS(134), 1,
      anon_sym_RBRACK,
  [486] = 1,
    ACTIONS(136), 1,
      anon_sym_RBRACK,
  [490] = 1,
    ACTIONS(138), 1,
      anon_sym_RPAREN,
  [494] = 1,
    ACTIONS(140), 1,
      anon_sym_LPAREN,
  [498] = 1,
    ACTIONS(142), 1,
      anon_sym_LPAREN,
  [502] = 1,
    ACTIONS(144), 1,
      anon_sym_DASH,
  [506] = 1,
    ACTIONS(146), 1,
      anon_sym_LPAREN,
  [510] = 1,
    ACTIONS(148), 1,
      anon_sym_EQ,
  [514] = 1,
    ACTIONS(150), 1,
      anon_sym_LPAREN,
  [518] = 1,
    ACTIONS(152), 1,
      anon_sym_TILDE,
  [522] = 1,
    ACTIONS(154), 1,
      anon_sym_LPAREN,
  [526] = 1,
    ACTIONS(156), 1,
      anon_sym_LPAREN,
  [530] = 1,
    ACTIONS(158), 1,
      anon_sym_LPAREN,
  [534] = 1,
    ACTIONS(160), 1,
      anon_sym_LPAREN,
  [538] = 1,
    ACTIONS(162), 1,
      anon_sym_LPAREN,
  [542] = 1,
    ACTIONS(164), 1,
      anon_sym_LPAREN,
  [546] = 1,
    ACTIONS(166), 1,
      anon_sym_LPAREN,
  [550] = 1,
    ACTIONS(168), 1,
      anon_sym_LPAREN,
  [554] = 1,
    ACTIONS(170), 1,
      anon_sym_LPAREN,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 36,
  [SMALL_STATE(4)] = 59,
  [SMALL_STATE(5)] = 79,
  [SMALL_STATE(6)] = 91,
  [SMALL_STATE(7)] = 111,
  [SMALL_STATE(8)] = 131,
  [SMALL_STATE(9)] = 151,
  [SMALL_STATE(10)] = 171,
  [SMALL_STATE(11)] = 191,
  [SMALL_STATE(12)] = 203,
  [SMALL_STATE(13)] = 220,
  [SMALL_STATE(14)] = 237,
  [SMALL_STATE(15)] = 248,
  [SMALL_STATE(16)] = 259,
  [SMALL_STATE(17)] = 270,
  [SMALL_STATE(18)] = 281,
  [SMALL_STATE(19)] = 292,
  [SMALL_STATE(20)] = 303,
  [SMALL_STATE(21)] = 314,
  [SMALL_STATE(22)] = 320,
  [SMALL_STATE(23)] = 330,
  [SMALL_STATE(24)] = 340,
  [SMALL_STATE(25)] = 350,
  [SMALL_STATE(26)] = 356,
  [SMALL_STATE(27)] = 362,
  [SMALL_STATE(28)] = 372,
  [SMALL_STATE(29)] = 382,
  [SMALL_STATE(30)] = 389,
  [SMALL_STATE(31)] = 396,
  [SMALL_STATE(32)] = 403,
  [SMALL_STATE(33)] = 408,
  [SMALL_STATE(34)] = 415,
  [SMALL_STATE(35)] = 422,
  [SMALL_STATE(36)] = 427,
  [SMALL_STATE(37)] = 434,
  [SMALL_STATE(38)] = 438,
  [SMALL_STATE(39)] = 442,
  [SMALL_STATE(40)] = 446,
  [SMALL_STATE(41)] = 450,
  [SMALL_STATE(42)] = 454,
  [SMALL_STATE(43)] = 458,
  [SMALL_STATE(44)] = 462,
  [SMALL_STATE(45)] = 466,
  [SMALL_STATE(46)] = 470,
  [SMALL_STATE(47)] = 474,
  [SMALL_STATE(48)] = 478,
  [SMALL_STATE(49)] = 482,
  [SMALL_STATE(50)] = 486,
  [SMALL_STATE(51)] = 490,
  [SMALL_STATE(52)] = 494,
  [SMALL_STATE(53)] = 498,
  [SMALL_STATE(54)] = 502,
  [SMALL_STATE(55)] = 506,
  [SMALL_STATE(56)] = 510,
  [SMALL_STATE(57)] = 514,
  [SMALL_STATE(58)] = 518,
  [SMALL_STATE(59)] = 522,
  [SMALL_STATE(60)] = 526,
  [SMALL_STATE(61)] = 530,
  [SMALL_STATE(62)] = 534,
  [SMALL_STATE(63)] = 538,
  [SMALL_STATE(64)] = 542,
  [SMALL_STATE(65)] = 546,
  [SMALL_STATE(66)] = 550,
  [SMALL_STATE(67)] = 554,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__node_pattern, 1),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 2),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 3),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [35] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(3),
  [38] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pattern, 1),
  [40] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [42] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_labels_repeat1, 2),
  [44] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_labels_repeat1, 2), SHIFT_REPEAT(43),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_labels, 3),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attributes, 1, .production_id = 1),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pattern, 2),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_labels, 2),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pattern_repeat1, 2),
  [59] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_pattern_repeat1, 2), SHIFT_REPEAT(27),
  [62] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [70] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [74] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__node_pattern, 3),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [78] = {.entry = {.count = 1, .reusable = false}}, SHIFT(55),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [82] = {.entry = {.count = 1, .reusable = false}}, SHIFT(62),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [86] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [88] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [90] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [92] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attributes, 2, .production_id = 3),
  [96] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [98] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [100] = {.entry = {.count = 1, .reusable = false}}, SHIFT(59),
  [102] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attributes, 1, .production_id = 2),
  [106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [108] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_arrow_right, 2),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_squiggle, 2),
  [116] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_arrow_left, 2),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_single, 2),
  [122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_arrow_right, 2),
  [126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [130] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [138] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_arrow_left, 2),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_arrow_right, 2),
  [144] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [146] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_double_arrow, 2),
  [148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_arrow_left, 2),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_single, 5),
  [156] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_arrow_right, 5),
  [158] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_arrow_left, 5),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_double_arrow, 5),
  [162] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_arrow_right, 5),
  [164] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_arrow_left, 5),
  [166] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_squiggle, 5),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_arrow_right, 5),
  [170] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_squiggle_arrow_left, 5),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_pop(void) {
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
