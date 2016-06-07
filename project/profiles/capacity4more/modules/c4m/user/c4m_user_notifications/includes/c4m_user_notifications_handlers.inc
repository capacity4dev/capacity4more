<?php

/**
 * @file
 * Code for the C4M notifications handler.
 */

function c4m_user_notifications_moderated_group_new_membership_request($entity) {
  return;
}

/*
 * Handlers implementation for c4m_user_notifications_entity_update.
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

function c4m_user_notifications_moderated_group_notify_admins_membership_accepted($membership) {
  return;
}

function c4m_user_notifications_open_group_notify_user_membership_accepted($membership) {
  return;
}

function c4m_user_notifications_open_group_notify_admins_membership_accepted($membership) {
  return;
}

function c4m_user_notifications_moderated_group_notify_user_membership_rejected($membership) {
  return;
}

function c4m_user_notifications_notify_admins_membership_canceled($entity) {
  return;
}

function c4m_user_notifications_notify_user_membership_canceled($entity) {
  return;
}

/*
 * Handlers implementation for c4m_user_notifications_node_update.
 */

function c4m_user_notifications_group_status_set_published($node) {
  return;
}

function c4m_user_notifications_group_status_set_republished($node) {
  return;
}

function c4m_user_notifications_group_status_set_unpublished($node) {
  return;
}

function c4m_user_notifications_group_status_set_archived($node) {
  return;
}

function c4m_user_notifications_group_status_set_softdeleted($node) {
  return;
}

function c4m_user_notifications_group_hard_deleted($node) {
  return;
}

function c4m_user_notifications_group_access_changed($node) {
  return;
}

function c4m_user_notifications_notify_prev_owner_owner_update($node) {
  return;
}

function c4m_user_notifications_notify_new_owner_owner_update($node) {
  return;
}

function c4m_user_notifications_notify_admins_owner_update($node) {
  return;
}

function c4m_user_notifications_notify_user_commented($comment) {
  return;
}

function c4m_user_notifications_notify_user_invited_by_admin(&$form, &$form_state) {
  return;
}

function c4m_user_notifications_notify_user_admin_granted($gid, $uid) {
  return;
}

function c4m_user_notifications_notify_admins_admin_granted($gid, $uid) {
  return;
}

function c4m_user_notifications_notify_user_admin_revoked($gid, $uid) {
  return;
}

function c4m_user_notifications_notify_admins_admin_revoked($gid, $uid) {
  return;
}
