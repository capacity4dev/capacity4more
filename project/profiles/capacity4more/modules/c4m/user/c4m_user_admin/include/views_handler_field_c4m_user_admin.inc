<?php
/**
 * @file
 * Helper class for C4M User Admin views field handler.
 */

// @codingStandardsIgnoreFile

/**
 * Field handler to present a link to activate user.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_c4m_user_admin extends views_handler_field {

  /**
   * Disable advanced rendering.
   */
  public function allow_advanced_render() {
    return FALSE;
  }

  /**
   * Disable query.
   */
  public function query() {}

}
