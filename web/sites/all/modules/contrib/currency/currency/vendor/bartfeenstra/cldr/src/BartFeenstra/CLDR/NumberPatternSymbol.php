<?php

/**
 * @file
 * Contains class \BartFeenstra\CLDR\NumberPatternSymbol.
 */

namespace BartFeenstra\CLDR;

/**
 * Describes a character from a number pattern .
 */
class NumberPatternSymbol {

  /**
   * Whether the symbol is escaped or not.
   *
   * @var boolean
   */
  public $escaped = FALSE;

  /**
   * Whether this symbol escapes another or not.
   *
   * @var boolean
   */
  public $escapes_other_symbol = FALSE;

  /**
   * The symbol's position in the original pattern.
   *
   * @var integer
   */
  public $position = NULL;

  /**
   * The symbol's replacement value.
   *
   * @var string
   */
  public $replacement = NULL;

  /**
   * The symbol.
   *
   * @var string
   */
  public $symbol = NULL;

  /**
   * Implements __construct().
   */
  function __construct($symbol, $position = NULL, $escaped = FALSE) {
    $this->symbol = $symbol;
    $this->position = $position;
    $this->escaped = $escaped;
  }
}