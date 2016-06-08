<?php

/**
 * @file
 * Code for the C4M notification triggers handlers.
 */

/**
 * Email notification when user is deleted.
 */
function c4m_user_notifications_notify_admins_user_deleted($account) {
  return;
}

/**
 * Email notification on membership request to moderated group.
 */
function c4m_user_notifications_moderated_group_new_membership_request($entity) {
  return;
}

/**
 * Email notification to user about acceptance to moderated group.
 */
function c4m_user_notifications_moderated_group_notify_user_membership_accepted($membership) {
  // Send activation message to member.
  $message = message_create('c4m_welcome_to_group', array('uid' => $membership->etid));
  c4m_message_load__c4m_welcome_to_group($message);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($membership->gid);
  // Message will be saved in message_notify_send_message().
  message_notify_send_message($wrapper->value());

  return;
}

/**
 * Email notification to group admins about new member at moderated group.
 */
function c4m_user_notifications_moderated_group_notify_admins_membership_accepted($membership) {
  return;
}

/**
 * Email notification to user about acceptance to open group.
 */
function c4m_user_notifications_open_group_notify_user_membership_accepted($membership) {
  return;
}

/**
 * Email notification to group admins about new member at open group.
 */
function c4m_user_notifications_open_group_notify_admins_membership_accepted($membership) {
  return;
}

/**
 * Email notification to user about rejection of membership request to moderated group.
 */
function c4m_user_notifications_moderated_group_notify_user_membership_rejected($membership) {
  return;
}

/**
 * Email notification to group admins about membership cancelation.
 */
function c4m_user_notifications_notify_admins_membership_canceled($entity) {
  return;
}

/**
 * Email notification to user about his membership cancelation.
 */
function c4m_user_notifications_notify_user_membership_canceled($entity) {
  return;
}

/**
 * Email notification about organic group status change to 'published'.
 */
function c4m_user_notifications_group_status_set_published($node) {
  return;
}

/**
 * Email notification about organic group status change to 'republished'.
 */
function c4m_user_notifications_group_status_set_republished($node) {
  return;
}

/**
 * Email notification about organic group status change to 'unpublished'.
 */
function c4m_user_notifications_group_status_set_unpublished($node) {
  return;
}

/**
 * Email notification about organic group status change to 'archived'.
 */
function c4m_user_notifications_group_status_set_archived($node) {
  return;
}

/**
 * Email notification about organic group status change to 'softdelete'.
 */
function c4m_user_notifications_group_status_set_softdeleted($node) {
  return;
}

/**
 * Email notification about organic group deletion.
 */
function c4m_user_notifications_group_hard_deleted($node) {
  return;
}

/**
 * Email notification about organic group access change.
 */
function c4m_user_notifications_group_access_changed($node) {
  return;
}

/**
 * Email notification to previous owner about group organic owner change.
 */
function c4m_user_notifications_notify_prev_owner_owner_update($node) {
  return;
}

/**
 * Email notification to new owner about organic group owner change.
 */
function c4m_user_notifications_notify_new_owner_owner_update($node) {
  return;
}

/**
 * Email notification to group admins about organic group owner change.
 */
function c4m_user_notifications_notify_admins_owner_update($node) {
  return;
}

/**
 * Email notification about user adding a comment.
 */
function c4m_user_notifications_notify_user_commented($comment) {
  return;
}

/**
 * Email notification about user invitation to group, sent by admin.
 */
function c4m_user_notifications_notify_user_invited_by_admin(&$form, &$form_state) {
  return;
}

/**
 * Email notification to user about user him becoming group admin.
 */
function c4m_user_notifications_notify_user_admin_granted($gid, $uid) {
  return;
}

/**
 * Email notification to group admins about user becoming group admin.
 */
function c4m_user_notifications_notify_admins_admin_granted($gid, $uid) {
  return;
}

/**
 * Email notification to user about user him being revoked admin status.
 */
function c4m_user_notifications_notify_user_admin_revoked($gid, $uid) {
  return;
}

/**
 * Email notification to group admins about user being revoked admin status.
 */
function c4m_user_notifications_notify_admins_admin_revoked($gid, $uid) {
  return;
}

/**
 * Email notification about new organic group publish.
 */
function c4m_user_notifications_new_node_published($node) {
  return;
}

/**
 * Email notification about existing organic group update.
 */
function c4m_user_notifications_existing_node_updated($node) {
  return;
}

/**
 * Email notification to content author about recommendation on his content.
 */
function c4m_user_notifications_notify_author_content_recommended($flag, $entity_id, $account, $flagging) {
  return;
}

/**
 * Email notification to subscribed editor about recommendation on content.
 */
function c4m_user_notifications_notify_subscribed_editor_content_recommended($flag, $entity_id, $account, $flagging) {
  return;
}

/**
 * Email notification about new content at organic group.
 */
function c4m_user_notifications_new_group_content_published($node) {
  return;
}

/**
 * Email notification about existing content update at organic group.
 */
function c4m_user_notifications_existing_group_content_updated($node) {
  return;
}
