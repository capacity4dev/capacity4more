<?php
// @codingStandardsIgnoreFile

/**
 * @file
 *
 */

class c4m_admin_groups_views_handler_field_group_approve_link extends c4m_admin_groups_views_handler_field {

  /**
   * @inheritdoc
   */
  function render($values) {
    if ($group = $this->get_og_group_from_context($values)) {
      return l(t('approve'), 'node/' . $group->nid . '/approve-group', array('query' => drupal_get_destination()));
    }
  }

}
