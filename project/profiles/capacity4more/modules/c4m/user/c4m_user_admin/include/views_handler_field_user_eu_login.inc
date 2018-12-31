<?php

/**
 * @file
 * Helper class for C4M User Admin views field handler.
 */

// @codingStandardsIgnoreFile

/**
 * Field handler to show if user used EU Login.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_user_eu_login extends views_handler_field_c4m_user_admin {

  /**
   * Render callback handler.
   *
   * Return the markup that will appear in the rendered field.
   */
  function render($values) {
    if (_ecas_is_ecas_user($values)) {
      return t('Yes');
    }
    else {
      return t('No');
    }
  }

}
