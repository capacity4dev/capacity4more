<?php

/**
 * @file
 * Code for the user blocks.
 */

/**
 * Menu callback.
 *
 * Business logic on registering/logging in and immediately joining groups.
 *
 * @param object $group
 *   The group object.
 */
function c4m_user_og_unified_workflow($group) {
  // Unset the destination, otherwise the drupal goto will use it as the
  // preferred url.
  unset($_GET['destination']);

  // Different flow for logged in users.
  c4m_user_og_unified_workflow_logged_in_users($group);

  // Set group to join in session variable and redirect to user/register.
  $_SESSION['c4m_unified_workflow_gid_join'] = $group->nid;
  drupal_goto('user/register');
}

/**
 * Associate the user to the group if already logged in.
 *
 * @param object $group
 *   The object of the group.
 */
function c4m_user_og_unified_workflow_logged_in_users($group) {
  if (user_is_anonymous()) {
    return;
  }

  global $user;

  if (og_get_membership('node', $group->nid, 'user', $user->uid)) {
    // Current user is already a member of this group.
    return;
  }

  c4m_user_og_group_unified_workflow($group, $user);

  // Redirect back to the group page.
  drupal_goto(drupal_get_path_alias('node/' . $group->nid));
}
