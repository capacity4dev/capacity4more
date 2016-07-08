<?php
// @codingStandardsIgnoreFile

/**
 * @file
 * Group Visibility views field handler.
 */

class c4m_admin_groups_views_handler_field_group_visibility extends c4m_admin_groups_views_handler_field {

  /**
   * @inheritdoc
   */
  function render($values) {
    if ($group = $this->get_og_group_from_context($values)) {
      $wrapper = entity_metadata_wrapper('node', $group);
      if (isset($wrapper->pluggable_node_access)) {
        $pluggable_node_accesses = $wrapper->pluggable_node_access->value();

        if (!empty($pluggable_node_accesses)) {
          // Group is restricted.
          return t('Restricted');
        }

        if (isset($wrapper->group_access)
          && $group_visibility = $wrapper->group_access->value()) {
          return t('Private');
        }
      }

      return t('Public');
    }
  }

}
