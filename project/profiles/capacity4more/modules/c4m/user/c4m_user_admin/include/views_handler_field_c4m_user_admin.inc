<?php
/**
 * @file
 * Helper class for C4M User Admin views field handler.
 */

class views_handler_field_c4m_user_admin extends views_handler_field {

  /**
   * @inheritdoc
   *
   * Disable advanced rendering.
   */
  function allow_advanced_render() {
    return FALSE;
  }

  /**
   * @inheritdoc
   *
   * Disable query.
   */
  function query() {}

}
