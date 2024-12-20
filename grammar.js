module.exports = grammar({
  name: 'gram',

  rules: {

    gram: $ => seq(
      field('root', optional($.record)), 
      repeat($.pattern)
    ),

    pattern: $ => commaSep1($.pattern_element),

    pattern_element: $ => seq(
      optional(repeat($.annotation)), 
      choice(
        $.subject,
        $._path,
        $._reference
      )
    ),

    // ABKNOTE -- consider the naming of the two parts of a subject
    // attributes & association
    // information & association
    subject: $ => seq("[", optional(field("attributes", $._attributes)), optional(field("association", $._association)),"]"),

    annotation: $ => seq(
      "@",
      field('key', $.symbol),
      "(",
      field('value', $._value),
      ")"
    ),
    
    _path: $ => choice(
      $.relationship,
      $.node
    ),

    node: $ => seq(token("("), optional($._attributes), token(")")),

    relationship: $ => seq(field("left", $.node), field("value", $._relationship_value), field("right", $._path)),
    
    _association: $ => seq(
      token("|"),
      $.pattern
    ),

    _reference: $ => $._value,

    _attributes: $ => choice(
      choice(field("identifier", $._value), field("labels", $.labels), field("record", $.record)), 
      seq(field("identifier", $._value), field("labels", $.labels)),
      seq(field("identifier", $._value), field("record", $.record)),
      seq(field("labels", $.labels), field("record", $.record)),
      seq(field("identifier", $._value), field("labels", $.labels), field("record", $.record))
    ),

    _value: $ => choice(
      prec.right(2, $.range),
      prec.right(1, $._numeric_literal),
      $.symbol,
      $._string_literal,
      $.math_symbol,
      $.greek,
      $.pictograph
    ),

    labels: $ => repeat1($.label),

    label: $ => seq(field("binder", $.binder), $.symbol),

    binder: $ => choice(token(":"), token("::")),

    record: $ => seq("{", commaSep($.property), "}"),

    property: $ => seq(
      field('key', $._key),
      field('binder', $.binder),
      field('value', $._value),
      optional(field('cardinality', choice('!', '?', '*', '+')))
    ),


    _key: $ => choice(
      $.symbol,
      $._string_literal
    ),

    symbol: $ => token(/[a-zA-Z_][0-9a-zA-Z_.\-@]*/),


    greek: $ => token(/[\u03B1-\u03C9\u0391-\u03A9]/),
    math_symbol: $ => token(/\p{Other_Math}/),
    pictograph: $ => token(/[\u2650-\u26FF]/),

    range: $ => choice(
      seq(field("lower", $._numeric_literal), "..", field("upper", $._numeric_literal)),
      seq(field("lower", $._numeric_literal), "..."),
      seq("...", field("upper", $._numeric_literal))
    ),

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
      $.tagged_string,
      $.fenced_string
    ),

    single_quoted_string: $ => {
      const quoted = /'(\\['bfnrt/\\]|[^'\n])*'/;      
      return token(quoted);
    },

    double_quoted_string: $ => {
      const quoted = /"(\\["bfnrt/\\]|[^"\n])*"/;      
      return token(quoted);
    },

    backticked_string: $ => {
      const quoted = /`(\\[`bfnrt/\\]|[^`\n])*`/;      
      return token(quoted);
    },

    tagged_string: $ => {
      const tagged = /[a-zA-Z@][0-9a-zA-Z_.@]*`[^`\n]*`/;      
      return token(tagged);
    },

    fenced_string: $ => {
      const fenced = /```(\\[`bfnrt/\\]|[^`])*```/;      
      return token(fenced);
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