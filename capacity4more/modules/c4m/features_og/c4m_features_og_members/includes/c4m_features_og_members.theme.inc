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
  $membership_level = NULL;

  if ('membership_level' == $field['formatter']) {
    $membership_level = c4m_user_og_get_role_in_group_human($user, $group);
  }

  if (!c4m_user_og_has_group_permission('manage members')) {
    return $membership_level;
  }

  $links = c4m_features_og_members_get_administer_links_for_user_in_group(
    $user, $group
  );

  // There are no links (group owner).
  if (empty($links)) {
    return $membership_level;
  }

  return theme('c4m_administer_member_links', array(
      'membership_level' => $membership_level,
      'links' => $links,
      'user_id' => $user->uid
    )
  );
}

/**
 * Render the role within the group.
 *
 * @param $field
 *
 * @return string
 */
function theme_c4m_features_og_members_role($field) {
  if (empty($field['entity'])) {
    return;
  }

  $group = c4m_og_current_group();
  if (empty($group)) {
    return;
  }

  $entity = $field['entity'];
  $user = user_load($entity->uid);
  return c4m_user_og_get_role_in_group_human($user, $group);
}

/**
 * Render date on which user became group member.
 *
 * @param $field
 *
 * @return string
 */
function theme_c4m_features_og_members_since($field) {
  if (empty($field['entity'])) {
    return;
  }

  $group = c4m_og_current_group();
  if (empty($group)) {
    return;
  }

  $membership = og_get_membership('node', $group->nid, 'user',
    $field['entity']->uid);
  if (!$membership) {
    return;
  }
  $tag['element'] = array(
    '#tag'       => 'span',
    '#attributes' => array(
      'class' => array('member-since'),
    ),
    '#value'     => format_date($membership->created, 'c4m_long_without_time'),
  );
  return theme_html_tag($tag);
}

/**
 * Render user activity summary within group.
 *
 * @param $field
 *
 * @return string
 */
function theme_c4m_features_og_members_activity_summary($field) {
  if (empty($field['entity'])) {
    return;
  }

  $group = c4m_og_current_group();
  if (empty($group)) {
    return;
  }
  $user = $field['entity'];

  $membership = og_get_membership('node', $group->nid, 'user', $user->uid);
  if (!$membership) {
    return;
  }

  // Count published posts of user in this group.
  $nr_of_nodes = c4m_user_og_count_nodes_in_group($user->uid, $group->nid);

  // Count published comments of user in this group.
  $nr_of_comments = c4m_user_og_count_comments_in_group($user->uid, $group->nid);

  return t('Posted') . ' ' .
    format_plural($nr_of_nodes, '1 Item', '@count Items') . ' ' .
    t('and') . ' ' .
    format_plural($nr_of_comments, '1 Comment', '@count Comments');
}
