module.exports = grammar({
  name: 'gram',

  rules: {

    gram: $ => seq(
      field('root', optional($.record)), 
      repeat($.pattern)
    ),

    // delimiters and other structural characters 
    _open_bracket: $ => "[",
    _close_bracket: $ => "]", 
    _open_parens: $ => "(",
    _close_parens: $ => ")",
    _open_brace: $ => "{",
    _close_brace: $ => "}",

    _binder: $ => /::?/,

    pattern: $ => commaSep1($.pattern_element),

    pattern_element: $ => seq(
      field("annotations", optional(repeat($.annotation))), 
      field("element", choice(
        $.subject,
        $._path,
        $._reference
      ))
    ),

    // ABKNOTE -- consider the naming of the two parts of a subject
    // attributes & association
    // information & association

    subject: $ => seq($._open_bracket, field("attributes", optional($._attributes)), field("association", optional($._association)), $._close_bracket),

    annotation: $ => seq(
      "@",
      field('key', $.symbol),
      $._open_parens,
      field('value', $._value),
      $._close_parens
    ),
    
    _path: $ => choice(
      $.relationship,
      $.node
    ),


    node: $ => seq($._open_parens, field("attributes", optional($._attributes)), $._close_parens),

    relationship: $ => seq(field("left", $.node), field("kind", $._relationship_kind), field("right", $._path)),
    
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
      prec(2, $.tagged_string),
      prec(1, $.symbol),
      $.string_literal
    ),

    labels: $ => repeat1($._label),

    _label: $ => seq($._binder, $.symbol),

    record: $ => seq($._open_brace, commaSep($.property), $._close_brace),

    _key: $ => choice(
      $.symbol,
      $.string_literal
    ),

    property: $ => seq(
      field('key', $._key),
      $._binder,
      field('value', $._value)
    ),

    symbol: $ => token(/[a-zA-Z_][0-9a-zA-Z_.\-@]*/),

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

    string_literal: $ => choice(
      $._single_quoted_string,
      $._double_quoted_string,
      $._backticked_string,
      $._fenced_string
    ),

    _single_quoted_string: $ => {
      const quoted = /'(\\['bfnrt/\\]|[^'\n])*'/;      
      return token(quoted);
    },

    _double_quoted_string: $ => {
      const quoted = /"(\\["bfnrt/\\]|[^"\n])*"/;      
      return token(quoted);
    },

    _backticked_string: $ => {
      const quoted = /`(\\[`bfnrt/\\]|[^`\n])*`/;      
      return token(quoted);
    },

    _fenced_string: $ => {
      const fenced = /```(\\[`bfnrt/\\]|[^`])*```/;      
      return token(fenced);
    },

    tagged_string: $ => seq(
      field("tag", $.symbol),
      field("string", alias($._backticked_string, $.string_literal))
    ),

    _relationship_kind: $ => choice(
      $.undirected_arrow,
      $.left_arrow,
      $.right_arrow,
      $.bidirectional_arrow
    ),
    
    undirected_arrow: $ => choice(
      seq("-", optional(seq("[", $._attributes, "]")), "-"),
      seq("=", optional(seq("[", $._attributes, "]")), "="),
      seq("~", optional(seq("[", $._attributes, "]")), "~") 
    ),

    right_arrow: $ => choice(
      seq("-", optional(seq("[", $._attributes, "]")), "->"),
      seq("=", optional(seq("[", $._attributes, "]")), "=>"),
      seq("~", optional(seq("[", $._attributes, "]")), "~>"),
    ),

    left_arrow: $ => choice(
      seq("<-", optional(seq("[", $._attributes, "]")), "-"),
      seq("<=", optional(seq("[", $._attributes, "]")), "="),
      seq("<~", optional(seq("[", $._attributes, "]")), "~"),
    ),

    bidirectional_arrow: $ => choice(
      seq("<-", optional(seq("[", $._attributes, "]")), "->"),
      seq("<=", optional(seq("[", $._attributes, "]")), "=>"),
      seq("<~", optional(seq("[", $._attributes, "]")), "~>"),
    )
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