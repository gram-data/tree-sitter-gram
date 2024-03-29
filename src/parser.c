#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 33
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 22
#define ALIAS_COUNT 0
#define TOKEN_COUNT 11
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  anon_sym_COMMA = 1,
  anon_sym_LPAREN = 2,
  anon_sym_RPAREN = 3,
  sym_symbol = 4,
  sym_string_value = 5,
  anon_sym_DASH = 6,
  anon_sym_LBRACK = 7,
  anon_sym_RBRACK = 8,
  anon_sym_DASH_GT = 9,
  anon_sym_LT_DASH = 10,
  sym_source_file = 11,
  sym_pattern = 12,
  sym_node_pattern = 13,
  sym_node = 14,
  sym_identifier = 15,
  sym_relationship = 16,
  sym_undirected_relationship = 17,
  sym_right_relationship = 18,
  sym_left_relationship = 19,
  aux_sym_source_file_repeat1 = 20,
  aux_sym_pattern_repeat1 = 21,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_COMMA] = ",",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [sym_symbol] = "symbol",
  [sym_string_value] = "string_value",
  [anon_sym_DASH] = "-",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_DASH_GT] = "->",
  [anon_sym_LT_DASH] = "<-",
  [sym_source_file] = "source_file",
  [sym_pattern] = "pattern",
  [sym_node_pattern] = "node_pattern",
  [sym_node] = "node",
  [sym_identifier] = "identifier",
  [sym_relationship] = "relationship",
  [sym_undirected_relationship] = "undirected_relationship",
  [sym_right_relationship] = "right_relationship",
  [sym_left_relationship] = "left_relationship",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_pattern_repeat1] = "pattern_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [sym_symbol] = sym_symbol,
  [sym_string_value] = sym_string_value,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [anon_sym_LT_DASH] = anon_sym_LT_DASH,
  [sym_source_file] = sym_source_file,
  [sym_pattern] = sym_pattern,
  [sym_node_pattern] = sym_node_pattern,
  [sym_node] = sym_node,
  [sym_identifier] = sym_identifier,
  [sym_relationship] = sym_relationship,
  [sym_undirected_relationship] = sym_undirected_relationship,
  [sym_right_relationship] = sym_right_relationship,
  [sym_left_relationship] = sym_left_relationship,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_pattern_repeat1] = aux_sym_pattern_repeat1,
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
  [sym_symbol] = {
    .visible = true,
    .named = true,
  },
  [sym_string_value] = {
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
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_pattern] = {
    .visible = true,
    .named = true,
  },
  [sym_node_pattern] = {
    .visible = true,
    .named = true,
  },
  [sym_node] = {
    .visible = true,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_relationship] = {
    .visible = true,
    .named = true,
  },
  [sym_undirected_relationship] = {
    .visible = true,
    .named = true,
  },
  [sym_right_relationship] = {
    .visible = true,
    .named = true,
  },
  [sym_left_relationship] = {
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(4);
      if (lookahead == '(') ADVANCE(6);
      if (lookahead == ')') ADVANCE(7);
      if (lookahead == ',') ADVANCE(5);
      if (lookahead == '-') ADVANCE(10);
      if (lookahead == '<') ADVANCE(1);
      if (lookahead == '[') ADVANCE(11);
      if (lookahead == ']') ADVANCE(12);
      if (lookahead == '`') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(8);
      END_STATE();
    case 1:
      if (lookahead == '-') ADVANCE(14);
      END_STATE();
    case 2:
      if (lookahead == '`') ADVANCE(9);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(2);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(8);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(sym_string_value);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '>') ADVANCE(13);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_LT_DASH);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
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
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [sym_symbol] = ACTIONS(1),
    [sym_string_value] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [anon_sym_LT_DASH] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(28),
    [sym_pattern] = STATE(3),
    [sym_node_pattern] = STATE(9),
    [sym_node] = STATE(2),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(9), 1,
      anon_sym_DASH,
    ACTIONS(11), 1,
      anon_sym_LT_DASH,
    STATE(13), 1,
      sym_relationship,
    ACTIONS(7), 3,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
    STATE(22), 3,
      sym_undirected_relationship,
      sym_right_relationship,
      sym_left_relationship,
  [20] = 5,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    ACTIONS(13), 1,
      ts_builtin_sym_end,
    STATE(2), 1,
      sym_node,
    STATE(9), 1,
      sym_node_pattern,
    STATE(4), 2,
      sym_pattern,
      aux_sym_source_file_repeat1,
  [37] = 5,
    ACTIONS(15), 1,
      ts_builtin_sym_end,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_node,
    STATE(9), 1,
      sym_node_pattern,
    STATE(4), 2,
      sym_pattern,
      aux_sym_source_file_repeat1,
  [54] = 1,
    ACTIONS(20), 5,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_LT_DASH,
  [62] = 1,
    ACTIONS(22), 5,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_LT_DASH,
  [70] = 3,
    ACTIONS(26), 1,
      anon_sym_COMMA,
    STATE(10), 1,
      aux_sym_pattern_repeat1,
    ACTIONS(24), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [81] = 3,
    ACTIONS(28), 1,
      anon_sym_RPAREN,
    STATE(25), 1,
      sym_identifier,
    ACTIONS(30), 2,
      sym_symbol,
      sym_string_value,
  [92] = 3,
    ACTIONS(26), 1,
      anon_sym_COMMA,
    STATE(7), 1,
      aux_sym_pattern_repeat1,
    ACTIONS(32), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [103] = 3,
    ACTIONS(36), 1,
      anon_sym_COMMA,
    STATE(10), 1,
      aux_sym_pattern_repeat1,
    ACTIONS(34), 2,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
  [114] = 2,
    STATE(27), 1,
      sym_identifier,
    ACTIONS(30), 2,
      sym_symbol,
      sym_string_value,
  [122] = 2,
    STATE(26), 1,
      sym_identifier,
    ACTIONS(30), 2,
      sym_symbol,
      sym_string_value,
  [130] = 3,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_node,
    STATE(14), 1,
      sym_node_pattern,
  [140] = 1,
    ACTIONS(39), 3,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
  [146] = 3,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_node,
    STATE(16), 1,
      sym_node_pattern,
  [156] = 1,
    ACTIONS(34), 3,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_LPAREN,
  [162] = 3,
    ACTIONS(41), 1,
      anon_sym_DASH,
    ACTIONS(43), 1,
      anon_sym_LBRACK,
    ACTIONS(45), 1,
      anon_sym_DASH_GT,
  [172] = 2,
    ACTIONS(47), 1,
      anon_sym_DASH,
    ACTIONS(49), 1,
      anon_sym_LBRACK,
  [179] = 2,
    ACTIONS(51), 1,
      anon_sym_DASH,
    ACTIONS(53), 1,
      anon_sym_DASH_GT,
  [186] = 1,
    ACTIONS(55), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [191] = 1,
    ACTIONS(57), 1,
      anon_sym_LPAREN,
  [195] = 1,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
  [199] = 1,
    ACTIONS(61), 1,
      anon_sym_LPAREN,
  [203] = 1,
    ACTIONS(63), 1,
      anon_sym_LPAREN,
  [207] = 1,
    ACTIONS(65), 1,
      anon_sym_RPAREN,
  [211] = 1,
    ACTIONS(67), 1,
      anon_sym_RBRACK,
  [215] = 1,
    ACTIONS(69), 1,
      anon_sym_RBRACK,
  [219] = 1,
    ACTIONS(71), 1,
      ts_builtin_sym_end,
  [223] = 1,
    ACTIONS(73), 1,
      anon_sym_DASH,
  [227] = 1,
    ACTIONS(75), 1,
      anon_sym_LPAREN,
  [231] = 1,
    ACTIONS(77), 1,
      anon_sym_LPAREN,
  [235] = 1,
    ACTIONS(79), 1,
      anon_sym_LPAREN,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 20,
  [SMALL_STATE(4)] = 37,
  [SMALL_STATE(5)] = 54,
  [SMALL_STATE(6)] = 62,
  [SMALL_STATE(7)] = 70,
  [SMALL_STATE(8)] = 81,
  [SMALL_STATE(9)] = 92,
  [SMALL_STATE(10)] = 103,
  [SMALL_STATE(11)] = 114,
  [SMALL_STATE(12)] = 122,
  [SMALL_STATE(13)] = 130,
  [SMALL_STATE(14)] = 140,
  [SMALL_STATE(15)] = 146,
  [SMALL_STATE(16)] = 156,
  [SMALL_STATE(17)] = 162,
  [SMALL_STATE(18)] = 172,
  [SMALL_STATE(19)] = 179,
  [SMALL_STATE(20)] = 186,
  [SMALL_STATE(21)] = 191,
  [SMALL_STATE(22)] = 195,
  [SMALL_STATE(23)] = 199,
  [SMALL_STATE(24)] = 203,
  [SMALL_STATE(25)] = 207,
  [SMALL_STATE(26)] = 211,
  [SMALL_STATE(27)] = 215,
  [SMALL_STATE(28)] = 219,
  [SMALL_STATE(29)] = 223,
  [SMALL_STATE(30)] = 227,
  [SMALL_STATE(31)] = 231,
  [SMALL_STATE(32)] = 235,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node_pattern, 1),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [17] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(8),
  [20] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 2),
  [22] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 3),
  [24] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pattern, 2),
  [26] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [28] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [30] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [32] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pattern, 1),
  [34] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pattern_repeat1, 2),
  [36] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_pattern_repeat1, 2), SHIFT_REPEAT(15),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node_pattern, 3),
  [41] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [51] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier, 1),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_right_relationship, 2),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relationship, 1),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_left_relationship, 2),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_relationship, 2),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [71] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_undirected_relationship, 5),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_right_relationship, 5),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_left_relationship, 5),
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
