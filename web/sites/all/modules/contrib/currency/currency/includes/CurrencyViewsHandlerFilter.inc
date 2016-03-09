<?php

/**
 * @file
 * Contains class CurrencyViewsHandlerFilter.
 */

/**
 * A Views filter handler for fields that contain ISO 4217 currency codes.
 */
class CurrencyViewsHandlerFilter extends views_handler_filter_in_operator {

  /**
   * Overrides parent::get_value_options().
   */
  function get_value_options() {
    $this->value_options = currency_options();
  }
}
