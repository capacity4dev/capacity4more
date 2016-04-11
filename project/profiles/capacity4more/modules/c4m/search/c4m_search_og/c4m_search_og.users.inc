<?php
/**
 * @file
 * Support between groups, their members and search.
 */

/******************************************************************************
 * Track changes on the group roles.
 ******************************************************************************/

/**
 * Helper to check if the role_grant needs to re-index the user.
 *
 * @param string $entity_type
 *   The entity type of the group in which a role has been granted.
 * @param int $uid
 *   The user id of the user to whom a role has been granted.
 */
function c4m_search_og_og_role_track_change($entity_type, $uid) {
  if ($entity_type !== 'node') {
    return;
  }

  c4m_user_track_change($uid);
}

/**
 * Implements hook_og_role_grant().
 *
 * Mark a user to be re-indexed when a role has been granted.
 */
function c4m_search_og_og_role_grant($entity_type, $gid, $uid, $rid) {
  c4m_search_og_og_role_track_change($entity_type, $uid);
}

/**
 * Implements hook_og_role_revoke().
 *
 * Mark a user to be re-indexed when a role has been revoked.
 */
function c4m_search_og_og_role_revoke($entity_type, $gid, $uid, $rid) {
  c4m_search_og_og_role_track_change($entity_type, $uid);
}

/******************************************************************************
 * Track changes on the group memberships.
 ******************************************************************************/

/**
 * Helper to check if the membership change needs a re-index of the user.
 *
 * @param OgMembership $og_membership
 *   The OG membership that is being changed.
 */
function c4m_search_og_og_membership_track_change(OgMembership $og_membership) {
  if ($og_membership->entity_type !== 'user') {
    return;
  }

  c4m_user_track_change($og_membership->etid);
}

/**
 * Implements hook_og_membership_insert().
 *
 * Mark a user to be re-indexed when he joins a group.
 */
function c4m_search_og_og_membership_insert(OgMembership $og_membership) {
  c4m_search_og_og_membership_track_change($og_membership);
}

/**
 * Implements hook_og_membership_update().
 *
 * Mark a user to be re-indexed when his membership changes.
 */
function c4m_search_og_og_membership_update(OgMembership $og_membership) {
  c4m_search_og_og_membership_track_change($og_membership);
}

/**
 * Implements hook_og_membership_delete().
 *
 * Mark a user to be re-indexed when his membership is deleted.
 */
function c4m_search_og_og_membership_delete(OgMembership $og_membership) {
  c4m_search_og_og_membership_track_change($og_membership);
}
