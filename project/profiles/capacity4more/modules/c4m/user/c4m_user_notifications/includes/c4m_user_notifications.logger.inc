<?php

/**
 * @file
 * Using the message API for logging functionality.
 */

/**
 * Creates and stores log message when a group is approved.
 *
 * @param object $form
 *   Form array to populate.
 * @param object $form_state
 *   Form state array.
 */
function c4m_user_notifications_log_group_approved($form, $form_state) {
  $gid = $form_state['values']['gid'];
  $admin_comment = $form_state['values']['message_from_admin'];

  _c4m_user_notifications_log_group_state_change('pending', 'draft', $gid, $admin_comment);
}

/**
 * Creates and stores log message when a group is rejected.
 *
 * @param object $form
 *   Form array to populate.
 * @param object $form_state
 *   Form state array.
 */
function c4m_user_notifications_log_group_rejected($form, $form_state) {
  $gid = $form_state['values']['gid'];
  $admin_comment = $form_state['values']['message_from_admin'];

  _c4m_user_notifications_log_group_state_change('pending', 'deleted', $gid, $admin_comment);
}

/**
 * Helper function.
 *
 * Creates and stores log message, when group state changes.
 *
 * @param string $from_state
 *   Group previous state.
 * @param string $to_state
 *   Group current state.
 * @param int $gid
 *   Group ID.
 * @param string $admin_comment
 *   Comment made by executing administrator.
 */
function _c4m_user_notifications_log_group_state_change($from_state, $to_state, $gid, $admin_comment) {
  global $user;
  $message = message_create('c4m_log_group_state_change', ['uid' => $user->uid]);

  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_log_group_state_change($message);

  $message->arguments['@from_state'] = ucfirst($from_state);
  $message->arguments['@to_state'] = ucfirst($to_state);
  $message->arguments['@admin_comment'] = $admin_comment;

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($gid);
  $wrapper->field_executing_user->set($user->uid);

  c4m_message_resolve_tokens($message);

  // Save message.
  $wrapper->save();
}
