module.exports = grammar({
  name: 'gram',

  rules: {

    gram: $ => repeat($._description),

    _description: $ => choice(
      $.pattern,
      $.record
    ),

    pattern: $ => seq(optional(repeat($.annotation)), commaSep1($._patternComponent)),

    _patternComponent: $ => choice(
      $.subject,
      $._path
    ),


    subject: $ => seq("[", optional($._attributes), optional($.members),"]"),

    annotation: $ => prec(9999,seq(
      "@", 
      field('key', $.symbol),
      "(",
      field('value', $._scalar),
      ")"
    )),
    
    _path: $ => choice(
      $.relationship,
      $.node
    ),

    node: $ => seq("(", optional($._attributes),")"),

    relationship: $ => seq(field("left", $.node), field("value", $._relationship_value), field("right", $._path)),

    members: $ => seq(field("operator", $.operator), commaSep1($._member)),

    operator: $ => token(/<{0,2}[-=~\/\|+*%^]{1,3}>{0,2}/),

    _references: $ => $._scalar,

    _member: $ => choice(
      $._references,
      $._patternComponent
    ),

    _attributes: $ => choice(
      choice(field("identifier", $._scalar), field("labels", $.labels), field("record", $.record)), 
      seq(field("identifier", $._scalar), field("labels", $.labels)),
      seq(field("identifier", $._scalar), field("record", $.record)),
      seq(field("labels", $.labels), field("record", $.record)),
      seq(field("identifier", $._scalar), field("labels", $.labels), field("record", $.record))
    ),

    _scalar: $ => choice(
      $.symbol,
      $._numeric_literal,
      $._string_literal,
      $.math_symbol,
      $.greek,
      $.pictograph
    ),

    labels: $ => seq(":", colonSep1($.symbol)),

    record: $ => seq("{", commaSep($.property), "}"),

    property: $ => seq(
      field('key', $.symbol),
      field('operator', token(/:{1,2}[=~]?|!?=[=~]?|[><]=?/)),
      field('value', $._scalar),
      optional(field('cardinality', choice('!', '?', '*', '+')))
    ),

    symbol: $ => token(/[a-zA-Z_][0-9a-zA-Z_@.\-]*/),

    greek: $ => token(/[\u03B1-\u03C9\u0391-\u03A9]/),
    math_symbol: $ => token(/\p{Other_Math}/),
    pictograph: $ => token(/[\u2650-\u26FF]/),

    _numeric_literal: $ => choice(
      $.integer,
      $.decimal,
      $.hexadecimal,
      $.octal,
      $.measurement
    ),

    integer: $ => {
      const integer = /-?(0|[1-9]\d*)/;      
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
      const octal = /0[0-7]+/;      
      return token(octal);
    },

    measurement: $ => {
      // /-?(?:[0-9]|[1-9][0-9]+)(?:\.[0-9]+)?[a-zA-Z]+\b(?!@)/
      const measurement = /-?(0|[1-9]\d*)([a-zA-Z]+)/;      
      return token(measurement);
    },

    _string_literal: $ => choice(
      $.single_quoted_string,
      $.double_quoted_string,
      $.backticked_string,
      $.tagged_string
    ),

    single_quoted_string: $ => {
      const quoted = /'(\\['bfnrt/\\]|[^'])*'/;      
      return token(quoted);
    },

    double_quoted_string: $ => {
      const quoted = /"(\\["bfnrt/\\]|[^"])*"/;      
      return token(quoted);
    },

    backticked_string: $ => {
      const quoted = /`(\\[`bfnrt/\\]|[^`])*`/;      
      return token(quoted);
    },

    tagged_string: $ => {
      const tagged = /[a-zA-Z][0-9a-zA-Z_.@]*`[^`]*`/;      
      return token(tagged);
    },

    _relationship_value: $ => choice(
      $.single_undirected,
      $.single_bidirectional,
      $.single_right,
      $.single_left,
      $.double_undirected,
      $.double_bidirectional,
      $.double_right,
      $.double_left,
      $.squiggle_undirected,
      $.squiggle_bidirectional,
      $.squiggle_right,
      $.squiggle_left,
    ),
      
    single_undirected: $ => seq("-", optional(seq("[", $._attributes, "]")), "-"),
    single_bidirectional: $ => seq("<-", optional(seq("[", $._attributes, "]")), "->"),
    single_right: $ => seq("-", optional(seq("[", $._attributes, "]")), "->"),
    single_left: $ => seq("<-", optional(seq("[", $._attributes, "]")), "-"),

    double_undirected: $ => seq("=", optional(seq("[", $._attributes, "]")), "="),
    double_bidirectional: $ => seq("<=", optional(seq("[", $._attributes, "]")), "=>"),
    double_right: $ => seq("=", optional(seq("[", $._attributes, "]")), "=>"),
    double_left: $ => seq("<=", optional(seq("[", $._attributes, "]")), "="),

    squiggle_undirected: $ => seq("~", optional(seq("[", $._attributes, "]")), "~"),
    squiggle_bidirectional: $ => seq("<~", optional(seq("[", $._attributes, "]")), "~>"),
    squiggle_right: $ => seq("~", optional(seq("[", $._attributes, "]")), "~>"),
    squiggle_left: $ => seq("<~", optional(seq("[", $._attributes, "]")), "~"),
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