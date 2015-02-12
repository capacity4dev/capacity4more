<?php
/**
 * @file
 *
 * Custom Display Suite function fields.
 */

/**
 * Render administrator actions on OG members list.
 *
 * @param $field
 *
 * @return string
 */
function theme_c4m_features_og_members_admin_actions($field) {
  if (empty($field['entity'])) {
    return;
  }

  $group = c4m_og_current_group();
  if (empty($group)) {
    return;
  }

  $entity = $field['entity'];
  $user = user_load($entity->uid);

  if ('membership_level' == $field['formatter']) {
    $membership_level = c4m_features_og_members_get_membership_level($user, $group);
  }
  else {
    $membership_level = NULL;
  }

  if (!c4m_features_og_members_access_group('manage members')) {
    return theme('c4m_administer_member_level', array(
        'membership_level' => $membership_level,
      )
    );
  }

  $links = array();

  // Retrieve all possible action links info.
  $info = c4m_features_og_members_get_administer_links($user, $group);
  usort($info, '_c4m_features_og_members_sort_weight');

  foreach ($info as $type => $hook_info) {
    $access = TRUE;
    // Check conditions
    foreach ($hook_info['conditions'] as $condition) {
      if (!$condition($user, $group)) {
        $access = FALSE;
        break;
      }
    }

    if ($access) {
      $callback = str_replace('[user_uid]', $user->uid, $hook_info['callback']);
      $title = str_replace(
        '[group_type]', ucfirst($group->type), $hook_info['title']
      );
      $options = array(
        'attributes' => array(
          'class' =>
            !empty($hook_info['class']) ? $hook_info['class'] : array(),
        ),
      );
      $links[] = '<li>' . l($title, $callback, $options) . '</li>';
    }
  }

  // There are no links (group owner).
  if (empty($links)) {
    return theme('c4m_administer_member_level', array(
        'membership_level' => $membership_level,
      )
    );
  }

  return theme('c4m_administer_member_links', array(
      'membership_level' => $membership_level,
      'links' => $links,
      'user_id' => $user->uid
    )
  );
}