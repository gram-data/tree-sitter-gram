module.exports = grammar({
  name: "gram",

  extras: ($) => [
    /\s/,
    $.comment,
  ],

  rules: {
    // top-level rule, forming an outer pattern shaped like `[ record | sequence-of-top-level-elements ]`
    gram: ($) => seq(field("root", optional($.record)), repeat($.annotated_pattern)),

    // top-level elements are annotated patterns shaped like `[annotation-record | pattern-elements]`
    annotated_pattern: ($) =>
      seq(
        field("annotations", optional($.annotations)),
        field("elements", commaSep1($._annotated_pattern_element)),
      ),
    _annotated_pattern_element: ($) => choice($.subject_pattern, $._path_pattern),

    subject_pattern: ($) =>
      seq(
        "[",
        field("subject", optional($._subject)),
        field("elements", optional(seq("|", $.subject_pattern_elements))),
        "]",
      ),

    subject_pattern_elements: ($) => commaSep1($._subject_pattern_element),

    _subject_pattern_element: ($) => choice($.subject_pattern, $._path_pattern, $.pattern_reference),

    annotations: ($) => repeat1($.annotation),

    annotation: ($) =>
      seq("@", field("key", $.symbol), "(", field("value", $._value), ")"),

    _path_pattern: ($) => choice($.relationship_pattern, $.node_pattern),

    node_pattern: ($) =>
      seq(
        "(",
        field("subject", optional($._subject)),
        ")",
      ),

    relationship_pattern: ($) =>
      seq(
        field("left", $.node_pattern),
        field("kind", $._relationship_kind),
        field("right", $._path_pattern),
      ),

    pattern_reference: ($) => field("identifier", $._identifier),

    _identifier: ($) => choice($.symbol, $.string_literal, $.integer),

    _subject: ($) =>
      choice(
        choice(
          field("identifier", $._identifier),
          field("labels", $.labels),
          field("record", $.record),
        ),
        seq(field("identifier", $._identifier), field("labels", $.labels)),
        seq(field("identifier", $._identifier), field("record", $.record)),
        seq(field("labels", $.labels), field("record", $.record)),
        seq(
          field("identifier", $._identifier),
          field("labels", $.labels),
          field("record", $.record),
        ),
      ),

    _value: ($) =>
      choice(
        prec.right(2, $.range),
        prec.right(1, $._numeric_literal),
        prec(3, $.boolean_literal),
        prec(2, $.tagged_string),
        prec(1, $.symbol),
        $.string_literal,
        $.array,
        $.map,
      ),

    _scalar_value: ($) =>
      choice(
        prec.right(2, $.range),
        prec.right(1, $._numeric_literal),
        prec(3, $.boolean_literal),
        prec(2, $.tagged_string),
        prec(1, $.symbol),
        $.string_literal,
      ),

    array: ($) => seq("[", commaSep1($._scalar_value), "]"),

    labels: ($) => repeat1($._label),

    _label: ($) => seq(choice(":", "::"), $.symbol),

    record: ($) => seq("{", commaSep($.record_property), "}"),

    record_property: ($) =>
      seq(
        field("key", $._identifier),
        choice(":", "::"),
        field("value", $._value),
      ),

    map: ($) => seq("{", commaSep($.map_entry), "}"),

    map_entry: ($) =>
      seq(field("key", $._identifier), ":", field("value", $._scalar_value)),

    symbol: ($) => token(/[a-zA-Z_][0-9a-zA-Z_.\-@]*/),

    range: ($) =>
      choice(
        seq(
          field("lower", $._numeric_literal),
          "..",
          field("upper", $._numeric_literal),
        ),
        seq(field("lower", $._numeric_literal), "..."),
        seq("...", field("upper", $._numeric_literal)),
      ),

    boolean_literal: ($) => choice("true", "false"),

    _numeric_literal: ($) =>
      choice($.integer, $.decimal, $.hexadecimal, $.octal, $.measurement),

    integer: ($) => {
      const integer = /-?(0|[1-9]\d*)/;
      return token(integer);
    },

    decimal: ($) => {
      const decimal = /-?(0|[1-9]\d*)\.\d+/;
      return token(decimal);
    },

    hexadecimal: ($) => {
      const hexadecimal = /0x[0-9a-fA-F]+/;
      return token(hexadecimal);
    },

    octal: ($) => {
      const octal = /0[0-7]+/;
      return token(octal);
    },

    measurement: ($) => {
      // /-?(?:[0-9]|[1-9][0-9]+)(?:\.[0-9]+)?[a-zA-Z]+\b(?!@)/
      const measurement = /-?(0|[1-9]\d*)([a-zA-Z]+)/;
      return token(measurement);
    },

    string_literal: ($) =>
      choice(
        $._single_quoted_string,
        $._double_quoted_string,
        $._backticked_string,
        $._fenced_string,
      ),

    _single_quoted_string: ($) =>
      delimit_string(alias($._single_quoted_text, $.string_content), "'"),

    _single_quoted_text: ($) => token.immediate(/(\\['bfnrt/\\]|[^'\\\n])*/),

    _double_quoted_string: ($) =>
      delimit_string(alias($._double_quoted_text, $.string_content), '"'),

    _double_quoted_text: ($) => token.immediate(/(\\["bfnrt/\\]|[^"\\\n])*/),

    _backticked_string: ($) =>
      delimit_string(alias($._backticked_text, $.string_content), "`"),

    _backticked_text: ($) => token.immediate(/(\\[`bfnrt/\\]|[^`\\\n])*/),

    _fenced_string: ($) => seq("```", $._fenced_string_body),

    _fenced_string_body: ($) =>
      seq(
        "\n",
        field(
          "content",
          optional(alias($._fenced_string_content, $.string_content)),
        ),
        "```",
      ),

    _fenced_string_content: ($) => token.immediate(/([^`]|`[^`]|``[^`])+/),

    tagged_string: ($) =>
      choice(
        seq(
          field("tag", $.symbol),
          "`",
          field("content", alias($._backticked_text, $.string_content)),
          "`",
        ),
        seq(
          "```",
          field("tag", $.symbol),
          "\n",
          field(
            "content",
            optional(alias($._fenced_string_content, $.string_content)),
          ),
          "```",
        ),
      ),

    _relationship_kind: ($) =>
      choice(
        $.undirected_arrow,
        $.left_arrow,
        $.right_arrow,
        $.bidirectional_arrow,
      ),

    undirected_arrow: ($) =>
      choice(
        seq(
          "-",
          optional(
            seq(
              "[",
              field("subject", optional($._subject)),
              "]",
            ),
          ),
          "-",
        ),
        seq(
          "=",
          optional(
            seq(
              "[",
              field("subject", optional($._subject)),
              "]",
            ),
          ),
          "=",
        ),
        seq(
          "~",
          optional(
            seq(
              "[",
              field("subject", optional($._subject)),
              "]",
            ),
          ),
          "~",
        ),
      ),

    right_arrow: ($) =>
      choice(
        seq(
          "-",
          optional(
            seq(
              "[",
              field("subject", optional($._subject)),
              "]",
            ),
          ),
          "->",
        ),
        seq(
          "=",
          optional(
            seq(
              "[",
              field("subject", optional($._subject)),
              "]",
            ),
          ),
          "=>",
        ),
        seq(
          "~",
          optional(
            seq(
              "[",
              field("subject", optional($._subject)),
              "]",
            ),
          ),
          "~>",
        ),
      ),

    left_arrow: ($) =>
      choice(
        seq(
          "<-",
          optional(
            seq(
              "[",
              field("subject", optional($._subject)),
              "]",
            ),
          ),
          "-",
        ),
        seq(
          "<=",
          optional(
            seq(
              "[",
              field("subject", optional($._subject)),
              "]",
            ),
          ),
          "=",
        ),
        seq(
          "<~",
          optional(
            seq(
              "[",
              field("subject", optional($._subject)),
              "]",
            ),
          ),
          "~",
        ),
      ),

    bidirectional_arrow: ($) =>
      choice(
        seq(
          "<-",
          optional(
            seq(
              "[",
              field("subject", optional($._subject)),
              "]",
            ),
          ),
          "->",
        ),
        seq(
          "<=",
          optional(
            seq(
              "[",
              field("subject", optional($._subject)),
              "]",
            ),
          ),
          "=>",
        ),
        seq(
          "<~",
          optional(
            seq(
              "[",
              field("subject", optional($._subject)),
              "]",
            ),
          ),
          "~>",
        ),
      ),

    comment: ($) => token(seq("//", /.*/)),
  },
});

function delimit_string(rule, delimiter) {
  return seq(delimiter, field("content", rule), delimiter);
}
/**
 * Creates a rule to match one or more of the rules separated by a comma
 *
 * @param {RuleOrLiteral} rule
 *
 * @return {SeqRule}
 *
 */
function commaSep1(rule) {
  return seq(rule, repeat(seq(",", rule)));
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
  return seq(rule, repeat(seq(":", rule)));
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
