<?php

/**
 * @file
 * Group Admin views field handler.
 */

class c4m_admin_groups_views_handler_field_group_admin extends c4m_admin_groups_views_handler_field {

  /**
   * @inheritdoc
   */
  function render($values) {
    if ($group = $this->get_og_group_from_context($values)) {
      // Load the user.
      if ($user = user_load($group->uid)) {
        return c4m_user_name($user) . ' (' . $user->mail . ')';
      }

      return t('none');
    }
  }

}
