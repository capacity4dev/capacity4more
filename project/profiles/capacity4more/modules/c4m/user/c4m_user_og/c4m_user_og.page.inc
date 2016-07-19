<?php

/**
 * @file
 * Code for the user blocks.
 */

/**
 * Menu callback with business logic on registering/logging in and immediately
 * joining groups.
 *
 * @param object $group
 *   The group object.
 * @param string optional action
 */
function c4m_user_og_unified_workflow($group, $action = NULL) {
  if (!og_context('node', $group)) {
    drupal_access_denied();
  }

  // Set group to join in session variable and redirect to /user/register.
  $_SESSION['c4m_unified_workflow_gid_join'] = $group->nid;
  // Unset the destination, otherwise the drupal goto will use it as the
  // preferred url.
  unset($_GET['destination']);

  drupal_goto('/user/register');
}
