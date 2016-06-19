<?php
// @codingStandardsIgnoreFile

/**
 * @file
 * Group Domains views field handler.
 */

class c4m_admin_groups_views_handler_field_group_domains extends c4m_admin_groups_views_handler_field {

  /**
   * @inheritdoc
   */
  function render($values) {
    if ($group = $this->get_og_group_from_context($values)) {
      $domains = c4m_og_get_email_domains($group);
      return implode(', ', $domains);
    }
  }

}
