<?php
// @codingStandardsIgnoreFile

/**
 * @file
 *
 */

class c4m_admin_groups_views_handler_field_group_reject_link extends c4m_admin_groups_views_handler_field {

  /**
   * @inheritdoc
   */
  function render($values) {
    if ($group = $this->get_og_group_from_context($values)) {
      return l(t('reject'), 'node/' . $group->nid . '/reject-group', array('query' => drupal_get_destination()));
    }
  }

}
