<?php
/**
 * @file
 *
 * Custom Display Suite function fields.
 */
/**
 * DS function field.
 *
 * Render ...
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

  if (!c4m_features_og_members_access_group('manage members')) {
    return;
  }

  $entity = $field['entity'];
  $user = user_load($entity->uid);

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
      $links[] = l($hook_info['title'], $callback);
    }
  }

  // Theme!
  return implode('<br/>', $links);
}

