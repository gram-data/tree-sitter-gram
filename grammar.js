module.exports = grammar({
  name: 'pop',

  rules: {
    source_file: $ => repeat($.pattern),

    pattern: $ => commaSep1($.node_pattern),

    node_pattern: $ => choice(
      $.node,
      seq($.node, $.relationship, $.node_pattern)
    ),
    
    node: $ => seq("(", optional($.identifier),")"),

    identifier: $ => choice(
      $.symbol,
      $.string_value
    ),

    symbol: $ => {
      const alphanumeric = /[0-9a-zA-Z_@.]+/;      
      return token(repeat1(alphanumeric));
    },

    string_value: $ => {
      const backticked = /`[^`]+`/;      
      return token(backticked);
    },

    relationship: $ => choice(
      $.undirected_relationship,
      $.right_relationship,
      $.left_relationship,
    ),
      
    undirected_relationship: $ => seq("-", optional(seq("[", $.identifier, "]")), "-"),

    right_relationship: $ => seq("-", optional(seq("[", $.identifier, "]")), "->"),

    left_relationship: $ => seq("<-", optional(seq("[", $.identifier, "]")), "-"),

  }
});

/**
 * Creates a rule to match one or more of the rules separated by a comma
 *
 * @param {RuleOrLiteral} rule
 *
 * @return {SeqRule}
 *
 */
function commaSep1(rule) {
  return seq(rule, repeat(seq(',', rule)));
}

/**
 * Creates a rule to optionally match one or more of the rules separated by a comma
 *
 * @param {RuleOrLiteral} rule
 *
 * @return {ChoiceRule}
 *
 */
function commaSep(rule) {
  return optional(commaSep1(rule));
}