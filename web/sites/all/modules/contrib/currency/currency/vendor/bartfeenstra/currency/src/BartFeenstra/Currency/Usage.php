<?php

/**
 * @file
 * Contains class \BartFeenstra\Currency\Currency.
 */

namespace BartFeenstra\Currency;

/**
 * Describes a currency's usage in a country.
 */
class Usage  {

  /**
   * The ISO 8601 datetime of the moment this usage started.
   *
   * @var string
   */
  public $ISO8601From = NULL;

  /**
   * The ISO 8601 datetime of the moment this usage ended.
   *
   * @var string
   */
  public $ISO8601To = NULL;

  /**
   * An ISO 3166-1 alpha-1 country code.
   *
   * @todo With minimal effort we can also support ISO 3166-3 codes.
   *
   * @var string
   */
  public $ISO3166Code = NULL;
}
