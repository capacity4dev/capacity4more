<?php

/**
 * @file
 * Group Organisations views field handler.
 */

class c4m_admin_groups_views_handler_field_group_organisations extends c4m_admin_groups_views_handler_field {

  /**
   * @inheritdoc
   */
  function render($values) {
    if ($group = $this->get_og_group_from_context($values)) {
      // Get the organisation IDs of the group node.
      $organisation_ids = c4m_og_get_organisations($group);
      // Only keep the organisations info of the organisations we need.
      $organisations_info = array_intersect_key(c4m_og_organisations_info(), array_flip($organisation_ids));

      $organisations = array();
      foreach ($organisations_info as $key => $info) {
        $organisations[] = $info['title'];
      }

      return implode(', ', $organisations);
    }
  }

}
