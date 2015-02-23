<?php
/**
 * @file
 * Condition callbacks for the member administer links.
 */

/**
 *  Condition callback. Is user active member of the group?
 *
 * @param $account
 * @param $group
 *
 * @return bool
 */
function _c4m_features_og_members_condition_user_active_member($account, $group) {
  $membership = og_get_membership('node', $group->nid, 'user', $account->uid);
  if (!$membership) {
    return FALSE;
  }
  if ($membership->state == OG_STATE_ACTIVE) {
    return TRUE;
  }
  return FALSE;
}

/**
 *  Condition callback. Is user blocked from the group?
 *
 * @param $account
 * @param $group
 *
 * @return bool
 */
function _c4m_features_og_members_condition_user_blocked_member($account, $group) {
  $membership = og_get_membership('node', $group->nid, 'user', $account->uid);
  if (!$membership) {
    return FALSE;
  }
  if ($membership->state == OG_STATE_BLOCKED) {
    return TRUE;
  }
  return FALSE;
}

/**
 *  Condition callback. Is user pending member of the group?
 *
 * @param $account
 * @param $group
 *
 * @return bool
 */
function _c4m_features_og_members_condition_user_pending_member($account, $group) {
  $membership = og_get_membership('node', $group->nid, 'user', $account->uid);
  if (!$membership) {
    return FALSE;
  }
  if ($membership->state == OG_STATE_PENDING) {
    return TRUE;
  }
  return FALSE;
}

/**
 *  Condition callback. Is user NOT an admin already?
 *
 * @param $account
 * @param $group
 *
 * @return bool
 */
function _c4m_features_og_members_condition_user_not_admin($account, $group) {
  return !_c4m_features_og_members_condition_user_admin($account, $group);
}

/**
 *  Condition callback. Is user administrative member of the group?
 *
 * @param $account
 * @param $group
 *
 * @return bool
 */
function _c4m_features_og_members_condition_user_admin($account, $group) {
  $admin_role = _c4m_features_og_members_get_admin_role($group);

  if (!$admin_role) {
    return FALSE;
  }

  $user_roles = og_get_user_roles('node', $group->nid, $account->uid);

  if (array_search(C4M_ADMINISTRATOR_ROLE_NAME, $user_roles)) {
    return TRUE;
  }

  return FALSE;
}

/**
 *  Condition callback. Is user the owner of the group?
 *
 * @param $account
 * @param $group
 *
 * @return bool
 */
function _c4m_features_og_members_condition_user_owner($account, $group) {
  return $account->uid == $group->uid;
}

/**
 *  Condition callback. Is user NOT the owner of the group?
 *
 * @param $account
 * @param $group
 *
 * @return bool
 */
function _c4m_features_og_members_condition_user_not_owner($account, $group) {
  return !_c4m_features_og_members_condition_user_owner($account, $group);
}
