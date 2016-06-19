<?php
// @codingStandardsIgnoreFile

/**
 * @file
 * Group Moderators views field handler.
 */

class c4m_admin_groups_views_handler_field_group_moderators extends c4m_admin_groups_views_handler_field {

  /**
   * @inheritdoc
   */
  function render($values) {
    if ($group = $this->get_og_group_from_context($values)) {
      $admins = c4m_og_get_group_admins($group->nid);

      if (count($admins)) {
        foreach ($admins as $uid => $user) {
          $output[] = c4m_user_name($user) . ' (' . $user->mail . ')';
        }
        return implode(', ', $output);
      }

      return t('none');
    }
  }

}
