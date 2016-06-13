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
      return c4m_og_get_organisations($group);
    }
  }

}
