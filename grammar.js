module.exports = grammar({
  name: 'gram',

  rules: {
    source_file: $ => repeat($.pattern),

    pattern: $ => commaSep1($.part),

    // segment: $ => choice(
    //   $.node,
    //   seq($.node, $._relationship, $._node_pattern)
    // ),
    
    part: $ => ruleSep1($.node, $._relationship),

    node: $ => seq("(", optional($.attributes),")"),

    attributes: $ => choice(
      choice(field("identifier", $._identifier), field("labels", $.labels)), 
      seq(field("identifier", $._identifier), field("labels", $.labels))
    ),

    _identifier: $ => choice(
      $.symbol,
      $._string_literal
    ),

    labels: $ => seq(":", colonSep1($.symbol)),

    symbol: $ => {
      const alphanumeric = /[0-9a-zA-Z_@.]+/;      
      return token(alphanumeric);
    },

    _string_literal: $ => choice(
      $.single_quoted_string,
      $.double_quoted_string,
      $.backticked_string
    ),

    single_quoted_string: $ => {
      const backticked = /'(\\['bfnrt/\\]|[^'])*'/;      
      return token(backticked);
    },

    double_quoted_string: $ => {
      const backticked = /"(\\["bfnrt/\\]|[^"])*"/;      
      return token(backticked);
    },

    backticked_string: $ => {
      const backticked = /`(\\[`bfnrt/\\]|[^`])*`/;      
      return token(backticked);
    },

    _relationship: $ => choice(
      $.undirected_single,
      $.single_arrow_right,
      $.single_arrow_left,
      $.undirected_double_arrow,
      $.double_arrow_right,
      $.double_arrow_left,
      $.undirected_squiggle,
      $.squiggle_arrow_right,
      $.squiggle_arrow_left,
    ),
      
    undirected_single: $ => seq("-", optional(seq("[", $.attributes, "]")), "-"),

    single_arrow_right: $ => seq("-", optional(seq("[", $.attributes, "]")), "->"),

    single_arrow_left: $ => seq("<-", optional(seq("[", $.attributes, "]")), "-"),
      
    undirected_double_arrow: $ => seq("=", optional(seq("[", $.attributes, "]")), "="),

    double_arrow_right: $ => seq("=", optional(seq("[", $.attributes, "]")), token(/>?=>/)),

    double_arrow_left: $ => seq(token(/<=<?/), optional(seq("[", $.attributes, "]")), "="),
      
    undirected_squiggle: $ => seq("~", optional(seq("[", $.attributes, "]")), "~"),

    squiggle_arrow_right: $ => seq("~", optional(seq("[", $.attributes, "]")), "~>"),

    squiggle_arrow_left: $ => seq("<~", optional(seq("[", $.attributes, "]")), "~"),

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


/**
 * Creates a rule to match one or more of the rules separated by a colon
 *
 * @param {RuleOrLiteral} rule
 *
 * @return {SeqRule}
 *
 */
function colonSep1(rule) {
  return seq(rule, repeat(seq(':', rule)));
}


/**
 * Creates a rule to match one or more of the rules separated by another rule
 *
 * @param {RuleOrLiteral} rule
 *
 * @return {SeqRule}
 *
 */
function ruleSep1(rule, separator) {
  return seq(rule, repeat(seq(separator, rule)));
}