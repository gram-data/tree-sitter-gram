module.exports = grammar({
  name: 'gram',

  rules: {
    gram: $ => repeat($.pattern),

    pattern: $ => commaSep1($.part),

    // segment: $ => choice(
    //   $.node,
    //   seq($.node, $._relationship, $._node_pattern)
    // ),
    
    part: $ => ruleSep1($.node, $._relationship),

    node: $ => seq("(", optional($.attributes),")"),

    attributes: $ => choice(
      choice(field("identifier", $._identifier), field("labels", $.labels), field("record", $.record)), 
      seq(field("identifier", $._identifier), field("labels", $.labels))
    ),

    _identifier: $ => choice(
      $.symbol,
      $._string_literal
    ),

    labels: $ => seq(":", colonSep1($.symbol)),

    record: $ => seq("{", commaSep1($.pair), "}"),

    pair: $ => seq(
      field('key', $.symbol),
      ':',
      field('value', $._value),
    ),

    symbol: $ => {
      const alphanumeric = /[0-9a-zA-Z_@.]+/;      
      return token(alphanumeric);
    },

    _value: $ => choice(
      $._numeric_literal,
      $._string_literal,
    ),

    _numeric_literal: $ => choice(
      $.integer,
      $.decimal,
      $.hexadecimal,
      $.octal
    ),

    integer: $ => {
      const integer = /-?([1-9]\d*)/;      
      return token(integer);
    },

    decimal: $ => {
      const decimal = /-?(0|[1-9]\d*)\.\d+/;      
      return token(decimal);
    },

    hexadecimal: $ => {
      const hexadecimal = /0x[0-9a-fA-F]+/;      
      return token(hexadecimal);
    },

    octal: $ => {
      const octal = /[0o][0-7]+/;      
      return token(octal);
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