<?php

/**
 * @file
 * Code for the C4M notification triggers handlers.
 */

/**
 * Email notification when user is deleted.
 */
function c4m_user_notifications_notify_admins_user_deleted($account) {
}

/**
 * Email notification on membership request to moderated group.
 */
function c4m_user_notifications_moderated_group_new_membership_request($entity) {
}

/**
 * Email notification to user about acceptance to group (moderated and open).
 */
function c4m_user_notifications_notify_user_membership_accepted($membership) {
  // Send activation message to member.
  $message = message_create('c4m_welcome_to_group', array('uid' => $membership->etid));
  c4m_message_load_tokens__c4m_welcome_to_group($message);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($membership->gid);
  // Message will be saved in message_notify_send_message().
  message_notify_send_message($wrapper->value());
}

/**
 * Email notification to group admins about new member at moderated group.
 */
function c4m_user_notifications_moderated_group_notify_admins_membership_accepted($membership) {
}

/**
 * Email notification to group admins about new member at open group.
 */
function c4m_user_notifications_open_group_notify_admins_membership_accepted($membership) {
  // Create an ids array of group owner and admins.
  $group_admins_ids = _c4m_user_notifications_get_admins_and_owner_ids($membership->gid);

  foreach ($group_admins_ids as $admin_id) {
    _c4m_user_notifications_open_group_notify_admin_membership_accepted($membership, $admin_id);
  }
}

/**
 * Helper function.
 *
 * Email notification to group admin/owner about new member at open group.
 */
function _c4m_user_notifications_open_group_notify_admin_membership_accepted($membership, $admin_id) {
  if (!($message = message_create('c4m_new_member_joined', array('uid' => $admin_id)))) {
    // Return early, if message was not created properly.
    return;
  }
  c4m_message_load_tokens__c4m_new_member_joined($message);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($membership->gid);
  $wrapper->field_new_member->set($membership->etid);
  $wrapper->field_group_membership->set($membership->id);
  message_notify_send_message($wrapper->value());
}

/**
 * Email notification to user about rejection of membership request.
 */
function c4m_user_notifications_moderated_group_notify_user_membership_rejected($membership) {
}

/**
 * Email notification to group admins about membership cancelation.
 */
function c4m_user_notifications_notify_admins_membership_canceled($entity) {
}

/**
 * Email notification to user about his membership cancelation.
 */
function c4m_user_notifications_notify_user_membership_canceled($entity) {
}

/**
 * Email notification about organic group status change to 'published'.
 */
function c4m_user_notifications_group_status_set_published($node) {
}

/**
 * Email notification about organic group status change to 'republished'.
 */
function c4m_user_notifications_group_status_set_republished($node, $group_former_status) {
}

/**
 * Email notification about organic group status change to 'unpublished'.
 */
function c4m_user_notifications_group_status_set_unpublished($node, $group_former_status) {
}

/**
 * Email notification about organic group status change to 'archived'.
 */
function c4m_user_notifications_group_status_set_archived($node, $group_former_status) {
}

/**
 * Email notification about organic group status change to 'softdelete'.
 */
function c4m_user_notifications_group_status_set_softdeleted($node, $group_former_status) {
}

/**
 * Email notification about organic group deletion.
 */
function c4m_user_notifications_group_hard_deleted($node) {
}

/**
 * Email notification about organic group access change.
 */
function c4m_user_notifications_group_access_changed($node) {
}

/**
 * Email notification to previous owner about group organic owner change.
 */
function c4m_user_notifications_notify_prev_owner_owner_update($node) {
}

/**
 * Email notification to new owner about organic group owner change.
 */
function c4m_user_notifications_notify_new_owner_owner_update($node) {
}

/**
 * Email notification to group admins about organic group owner change.
 */
function c4m_user_notifications_notify_admins_owner_update($node) {
}

/**
 * Email notification about user adding a comment.
 */
function c4m_user_notifications_notify_user_commented($comment) {
}

/**
 * Email notification about user invitation to group, sent by admin.
 */
function c4m_user_notifications_notify_user_invited_by_admin($form, $form_state) {
}

/**
 * Email notification to user about user him becoming group admin.
 */
function c4m_user_notifications_notify_user_admin_granted($gid, $uid) {
}

/**
 * Email notification to group admins about user becoming group admin.
 */
function c4m_user_notifications_notify_admins_admin_granted($gid, $uid) {
}

/**
 * Email notification to user about user him being revoked admin status.
 */
function c4m_user_notifications_notify_user_admin_revoked($gid, $uid) {
}

/**
 * Email notification to group admins about user being revoked admin status.
 */
function c4m_user_notifications_notify_admins_admin_revoked($gid, $uid) {
}

/**
 * Email notification about new organic group publish.
 */
function c4m_user_notifications_new_node_published($node) {
}

/**
 * Email notification about existing organic group update.
 */
function c4m_user_notifications_existing_node_updated($node) {
}

/**
 * Email notification to content author about recommendation on his content.
 */
function c4m_user_notifications_notify_author_content_recommended($flag, $entity_id, $account, $flagging) {
}

/**
 * Email notification to subscribed editor about recommendation on content.
 */
function c4m_user_notifications_notify_subscribed_editor_content_recommended($flag, $entity_id, $account, $flagging) {
}

/**
 * Email notification about new content at organic group.
 */
function c4m_user_notifications_new_group_content_published($node) {
}

/**
 * Email notification about existing content update at organic group.
 */
function c4m_user_notifications_existing_group_content_updated($node) {
}

/**
 * Email notification to inactive users.
 *
 * Function is invoked once an hour by cron.
 * It loads all inactive users, and for each one of them:
 *   Calculates number of hours that have passed since users creation.
 *   Calculates number of hours that have passed since previous notification,
 *   assuming we're not within first interval.
 *   In case notification full interval has passed (indication: modulo result
 *   is 0), notifies user.
 *
 * Notification interval (in days), is set to value of variable
 * 'c4m_inactive_users_reminder_days_interval', or default of 7.
 */
function c4m_user_notifications_notify_inactive_users() {
  // Inactive users notification interval, in days.
  $days_interval = variable_get('c4m_inactive_users_reminder_days_interval', 7);
  foreach (c4m_user_get_inactive_users() as $account) {
    // Calculate how many hours have passed since user was created.
    $hours_from_creation = (REQUEST_TIME - $account->created) / 3600;
    // Calculates how many hours have passed since previous notification.
    $hours_since_previous_notification = $hours_from_creation % ($days_interval * 24);

    if (!($hours_from_creation > 0)) {
      // User was created less than an hour ago - no need to notify.
      continue;
    }

    if ($hours_since_previous_notification !== 0) {
      // Modulo result is not round - no need to notify.
      continue;
    }

    // Notify user.
  }
}

/**
 * Email notification to all commenters, about comment on group content.
 */
function c4m_user_notifications_notify_comment_on_content($comment) {
}

/**
 * Helper function.
 *
 * Returns an array of ids for all group admins and group owner.
 */
function _c4m_user_notifications_get_admins_and_owner_ids($gid) {
  // Get an array of ids for group admins.
  $group_admins_ids = c4m_og_get_group_admins_ids($gid);
  // Load group.
  $group = node_load($gid);
  // If group owner is not defined as group admin, add it to admins list.
  if (!in_array($group->uid, $group_admins_ids)) {
    $group_admins_ids[] = $group->uid;
  }

  return $group_admins_ids;
}
