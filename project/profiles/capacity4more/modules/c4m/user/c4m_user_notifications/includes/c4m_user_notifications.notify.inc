<?php

/**
 * @file
 * Logic behind simple notifications (sent immediately, no subscriptions).
 */

/**
 * Email notification about group that was 'published'.
 *
 * Status changed from 'draft' to 'published'.
 *
 * @param object $node
 *   Drupal node entity object.
 */
function _c4m_user_notifications_notify_og_group_status_published($node) {
  $group_admins_ids = c4m_og_get_group_admins_and_owner_ids_for_notification($node->nid);

  foreach ($group_admins_ids as $admin_id) {
    _c4m_user_notifications_notify_group_admins_og_group_status_published($node, $admin_id);
  }
}

/**
 * Email notification to group owner/admins about group that was 'published'.
 *
 * @param object $node
 *   Drupal node entity object.
 * @param int $admin_id
 *   User ID of the admin to notify.
 */
function _c4m_user_notifications_notify_group_admins_og_group_status_published($node, $admin_id) {
  global $user;
  $message = message_create('c4m_group_published', ['uid' => $admin_id]);

  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_group_published($message);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($node->nid);
  $wrapper->field_executing_user->set($user->uid);

  c4m_message_resolve_tokens($message);

  // Message will be saved in message_notify_send_message().
  message_notify_send_message($wrapper->value());
}

/**
 * Email notification about group that was 'republished' from a former state.
 *
 * @param object $node
 *   Drupal node entity object.
 * @param string $group_former_status
 *   Former group status.
 */
function _c4m_user_notifications_notify_og_group_status_republished($node, $group_former_status) {
  $group_admins_ids = c4m_og_get_group_admins_and_owner_ids_for_notification($node->nid);

  foreach ($group_admins_ids as $admin_id) {
    _c4m_user_notifications_notify_group_admins_og_group_status_republished($node, $admin_id, $group_former_status);
  }
}

/**
 * Email notification to group owner/admins about group that was 'republished'.
 *
 * @param object $node
 *   Drupal node entity object.
 * @param int $admin_id
 *   User ID of the admin to notify.
 * @param string $group_former_status
 *   Former group status.
 */
function _c4m_user_notifications_notify_group_admins_og_group_status_republished($node, $admin_id, $group_former_status) {
  global $user;
  $message = message_create('c4m_group_republished', ['uid' => $admin_id]);

  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_group_republished($message);
  $message->arguments['@group_former_status'] = ucfirst($group_former_status);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($node->nid);
  $wrapper->field_executing_user->set($user->uid);

  c4m_message_resolve_tokens($message);

  // Message will be saved in message_notify_send_message().
  message_notify_send_message($wrapper->value());
}

/**
 * Email notification about group that was 'unpublished' from a former state.
 *
 * @param object $node
 *   Drupal node entity object.
 * @param string $group_former_status
 *   Former group status.
 */
function _c4m_user_notifications_notify_og_group_status_unpublished($node, $group_former_status) {
  $group_admins_ids = c4m_og_get_group_admins_and_owner_ids_for_notification($node->nid);

  foreach ($group_admins_ids as $admin_id) {
    _c4m_user_notifications_notify_group_admins_og_group_status_unpublished($node, $admin_id, $group_former_status);
  }
}

/**
 * Email notification to group owner/admins about group that was 'unpublished'.
 *
 * @param object $node
 *   Drupal node entity object.
 * @param int $admin_id
 *   User ID of the admin to notify.
 * @param string $group_former_status
 *   Former group status.
 */
function _c4m_user_notifications_notify_group_admins_og_group_status_unpublished($node, $admin_id, $group_former_status) {
  global $user;
  $message = message_create('c4m_group_unpublished', ['uid' => $admin_id]);

  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_group_unpublished($message);

  // Set 'group former status' token to input value.
  $message->arguments['@group_former_status'] = ucfirst($group_former_status);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($node->nid);
  $wrapper->field_executing_user->set($user->uid);

  c4m_message_resolve_tokens($message);

  // Message will be saved in message_notify_send_message().
  message_notify_send_message($wrapper->value());
}

/**
 * Email notification about group that was 'archived' from a former state.
 *
 * @param object $node
 *   Drupal node entity object.
 * @param string $group_former_status
 *   Former group status.
 */
function _c4m_user_notifications_notify_og_group_status_archived($node, $group_former_status) {
  $group_admins_ids = c4m_og_get_group_admins_and_owner_ids_for_notification($node->nid);

  foreach ($group_admins_ids as $admin_id) {
    _c4m_user_notifications_notify_group_admins_og_group_status_archived($node, $admin_id, $group_former_status);
  }
}

/**
 * Email notification to group owner/admins about group that was 'archived'.
 *
 * @param object $node
 *   Drupal node entity object.
 * @param int $admin_id
 *   User ID of the admin to notify.
 * @param string $group_former_status
 *   Former group status.
 */
function _c4m_user_notifications_notify_group_admins_og_group_status_archived($node, $admin_id, $group_former_status) {
  global $user;
  $message = message_create('c4m_group_archived', ['uid' => $admin_id]);

  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_group_archived($message);

  // Set 'group former status' token to input value.
  $message->arguments['@group_former_status'] = ucfirst($group_former_status);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($node->nid);
  $wrapper->field_executing_user->set($user->uid);

  c4m_message_resolve_tokens($message);

  // Message will be saved in message_notify_send_message().
  message_notify_send_message($wrapper->value());
}

/**
 * Email notification about group that was 'soft-deleted' from a former state.
 *
 * @param object $node
 *   Drupal node entity object.
 * @param string $group_former_status
 *   Former group status.
 */
function _c4m_user_notifications_notify_og_group_status_softdeleted($node, $group_former_status) {
  $admins_ids = c4m_admin_get_admins_ids_for_notification();

  foreach ($admins_ids as $admin_id) {
    _c4m_user_notifications_notify_group_admins_og_group_status_softdeleted($node, $admin_id, $group_former_status);
  }
}

/**
 * Email notification to group owner/admins about group that was 'soft-deleted'.
 *
 * @param object $node
 *   Drupal node entity object.
 * @param int $admin_id
 *   User ID of the admin to notify.
 * @param string $group_former_status
 *   Former group status.
 */
function _c4m_user_notifications_notify_group_admins_og_group_status_softdeleted($node, $admin_id, $group_former_status) {
  global $user;
  $message = message_create('c4m_group_soft_deleted', ['uid' => $admin_id]);

  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_group_soft_deleted($message);

  // Set 'group former status' token to input value.
  $message->arguments['@group_former_status'] = ucfirst($group_former_status);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($node->nid);
  $wrapper->field_executing_user->set($user->uid);

  c4m_message_resolve_tokens($message);

  // Message will be saved in message_notify_send_message().
  message_notify_send_message($wrapper->value());
}

/**
 * Email notification to group owner about group that was 'approved'.
 *
 * @param int $gid
 *   Group ID that was approved.
 * @param string $admin_comment
 *   Optional remark the site admin added to the approval.
 */
function _c4m_user_notifications_notify_og_group_status_approved($gid, $admin_comment = '') {
  $group = node_load($gid);

  $message = message_create('c4m_group_request_approved', ['uid' => $group->uid]);
  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_group_request_approved($message);

  // Set 'admin comment' token to input value.
  $message->arguments['@admin_comment'] = $admin_comment;

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($gid);

  c4m_message_resolve_tokens($message);

  // Message will be saved inside message_notify_send_message().
  message_notify_send_message($wrapper->value());
}

/**
 * Email notification to group admins about new group request.
 *
 * @param object $node
 *   Drupal node entity object.
 */
function _c4m_user_notifications_notify_og_group_status_requested($node) {
  $admins_ids = c4m_admin_get_admins_ids_for_notification();

  foreach ($admins_ids as $admin_id) {
    _c4m_user_notifications_notify_group_admin_og_group_status_requested($node, $admin_id);
  }
}

/**
 * Email notification to group admins about new group request.
 *
 * @param object $node
 *   Drupal node entity object.
 * @param int $admin_id
 *   User ID of the admin to notify.
 */
function _c4m_user_notifications_notify_group_admin_og_group_status_requested($node, $admin_id) {
  global $user;
  $message = message_create('c4m_group_request_submitted', ['uid' => $admin_id]);

  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_group_request_submitted($message);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($node->nid);
  $wrapper->field_executing_user->set($user->uid);

  c4m_message_resolve_tokens($message);

  // Message will be saved in message_notify_send_message().
  message_notify_send_message($wrapper->value());
}

/**
 * Email notification to group requester that group is waiting for review.
 *
 * @param object $node
 *   Drupal node entity object.
 */
function _c4m_user_notifications_notify_user_og_group_status_requested($node) {
  $message = message_create('c4m_group_requested', ['uid' => $node->uid]);

  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_group_requested($message);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($node->nid);

  c4m_message_resolve_tokens($message);

  // Message will be saved in message_notify_send_message().
  message_notify_send_message($wrapper->value());
}

/**
 * Email notification to group admins about group access that changed.
 *
 * @param object $node
 *   Drupal node entity object.
 * @param string $permissions
 *   Updated permission level.
 */
function _c4m_user_notifications_notify_og_group_access_update($node, $permissions) {
  $group_admins_ids = c4m_og_get_group_admins_and_owner_ids_for_notification($node->nid);

  foreach ($group_admins_ids as $admin_id) {
    _c4m_user_notifications_notify_group_admins_og_group_access_update($node, $admin_id, $permissions);
  }
}

/**
 * Email notification to group admins about group access that changed.
 *
 * @param object $node
 *   Drupal node entity object.
 * @param int $admin_id
 *   User ID of the admin to notify.
 * @param string $permissions
 *   Updated permission level.
 */
function _c4m_user_notifications_notify_group_admins_og_group_access_update($node, $admin_id, $permissions) {
  global $user;
  $message = message_create('c4m_group_access_change', ['uid' => $admin_id]);

  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_group_access_change($message);

  // Set 'group permissions' token to input value.
  $message->arguments['@group_permissions'] = $permissions;

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($node->nid);
  $wrapper->field_executing_user->set($user->uid);

  c4m_message_resolve_tokens($message);

  // Message will be saved in message_notify_send_message().
  message_notify_send_message($wrapper->value());
}

/**
 * Email notification on membership request to moderated group.
 *
 * @param object $membership
 *   Membership entity object.
 */
function _c4m_user_notifications_notify_og_group_membership_request($membership) {
  $group_admins_ids = c4m_og_get_group_admins_and_owner_ids_for_notification($membership->gid);

  foreach ($group_admins_ids as $admin_id) {
    _c4m_user_notifications_notify_group_admins_og_group_membership_request($membership, $admin_id);
  }
}

/**
 * Email notification to group admins on membership request to moderated group.
 *
 * @param object $membership
 *   Membership entity object.
 * @param int $admin_id
 *   User ID of the admin to notify.
 */
function _c4m_user_notifications_notify_group_admins_og_group_membership_request($membership, $admin_id) {
  $message = message_create('c4m_new_membership_request', ['uid' => $admin_id]);

  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_new_membership_request($message);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($membership->gid);
  $wrapper->field_related_user->set($membership->etid);
  $wrapper->field_group_membership->set($membership->id);

  c4m_message_resolve_tokens($message);

  // Message will be saved in message_notify_send_message().
  message_notify_send_message($wrapper->value());
}

/**
 * Email notification to user that his membership request awaits approval.
 *
 * @param object $membership
 *   Membership entity object.
 */
function _c4m_user_notifications_notify_user_og_group_membership_pending($membership) {
  $message = message_create('c4m_notify_user_membership_pending', ['uid' => $membership->etid]);

  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_notify_user_membership_pending($message);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($membership->gid);

  c4m_message_resolve_tokens($message);
  message_notify_send_message($wrapper->value());
}

/**
 * Email notification to user about acceptance to group (moderated and open).
 *
 * @param object $membership
 *   Membership entity object.
 */
function _c4m_user_notifications_notify_user_og_group_membership_accepted($membership) {
  $message = message_create('c4m_welcome_to_group', ['uid' => $membership->etid]);

  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_welcome_to_group($message);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($membership->gid);

  c4m_message_resolve_tokens($message);

  // Message will be saved in message_notify_send_message().
  message_notify_send_message($wrapper->value());
}

/**
 * Email notification about a new member at moderated group.
 *
 * @param object $membership
 *   Membership entity object.
 */
function _c4m_user_notifications_notify_og_group_membership_approved($membership) {
  $group_admins_ids = c4m_og_get_group_admins_and_owner_ids_for_notification($membership->gid);

  foreach ($group_admins_ids as $admin_id) {
    _c4m_user_notifications_notify_group_admins_og_group_membership_approved($membership, $admin_id);
  }
}

/**
 * Sends mail notification to group admins about new member that was approved.
 *
 * @param object $membership
 *   Membership entity.
 * @param int $admin_id
 *   User ID of the admin to notify.
 */
function _c4m_user_notifications_notify_group_admins_og_group_membership_approved($membership, $admin_id) {
  global $user;
  $message = message_create('c4m_notify_admins_membership_approved', ['uid' => $admin_id]);

  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_notify_admins_membership_accepted($message);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($membership->gid);
  $wrapper->field_related_user->set($membership->etid);
  $wrapper->field_executing_user->set($user->uid);

  c4m_message_resolve_tokens($message);

  // Message will be saved in message_notify_send_message().
  message_notify_send_message($wrapper->value());
}

/**
 * Email notification to group admins about new member at open group.
 *
 * @param object $membership
 *   Membership entity.
 */
function _c4m_user_notifications_notify_og_group_membership_joined($membership) {
  $group_admins_ids = c4m_og_get_group_admins_and_owner_ids_for_notification($membership->gid);

  foreach ($group_admins_ids as $admin_id) {
    _c4m_user_notifications_notify_group_admins_og_group_membership_joined($membership, $admin_id);
  }
}

/**
 * Email notification to group admins about new member at open group.
 *
 * @param object $membership
 *   Membership entity.
 * @param int $admin_id
 *   User ID of the admin to notify.
 */
function _c4m_user_notifications_notify_group_admins_og_group_membership_joined($membership, $admin_id) {
  $message = message_create('c4m_new_member_joined', ['uid' => $admin_id]);

  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_new_member_joined($message);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($membership->gid);
  $wrapper->field_related_user->set($membership->etid);
  $wrapper->field_group_membership->set($membership->id);

  c4m_message_resolve_tokens($message);

  // Message will be saved inside message_notify_send_message().
  message_notify_send_message($wrapper->value());
}

/**
 * Email notification to user about him becoming group admin.
 */
function _c4m_user_notifications_notify_og_role_grant($gid, $uid) {
  global $user;
  $message = message_create('c4m_notify_promoted_member', ['uid' => $uid]);

  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_notify_promoted_member($message);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($gid);
  $wrapper->field_executing_user->set($user->uid);

  c4m_message_resolve_tokens($message);

  // Message will be saved in message_notify_send_message().
  message_notify_send_message($wrapper->value());
}

/**
 * Sends mail notification when group admin is demoted to regular member.
 *
 * @param int $gid
 *   Group id.
 * @param int $uid
 *   User id.
 */
function _c4m_user_notifications_notify_og_role_revoke($gid, $uid) {
  global $user;

  // When admin demotes himself, don't notify him, he already knows!
  if ($uid == $user->uid) {
    return;
  }

  $message = message_create('c4m_group_admin_demoted', ['uid' => $uid]);
  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_group_admin_demoted($message);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($gid);
  $wrapper->field_executing_user->set($user->uid);

  c4m_message_resolve_tokens($message);

  // Message will be saved in message_notify_send_message().
  message_notify_send_message($wrapper->value());
}

/**
 * Email notification to user about rejection of membership request.
 *
 * Form submit handler of "c4m_og_reject_membership_request".
 *
 * @param array $form
 *   Drupal form array.
 * @param array $form_state
 *   Drupal form_state array.
 */
function _c4m_user_notifications_notify_user_og_group_membership_rejected(array &$form, array &$form_state) {
  global $user;

  $membership = $form_state['membership'];
  $message = message_create('c4m_membership_request_rejected', ['uid' => $membership->etid]);

  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_membership_request_rejected($message);
  $message->arguments['@membership_reject_reason'] = $form_state['values']['reject_membership_request_message'];

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($membership->gid);
  $wrapper->field_executing_user->set($user->uid);

  c4m_message_resolve_tokens($message);

  // Message will be saved inside message_notify_send_message().
  message_notify_send_message($wrapper->value());
}

/**
 * Email notification about user added to a group by site admin.
 *
 * Form submit handler of "og_ui_add_users".
 *
 * @param array $form
 *   Drupal form array.
 * @param array $form_state
 *   Drupal form_state array.
 */
function _c4m_user_notifications_notify_user_og_group_membership_added_by_admin(array &$form, array &$form_state) {
  // Apply only to SAs.
  $site_admin_role = user_role_load_by_name('administrator');

  if (!user_has_role($site_admin_role->rid)) {
    return;
  }

  // Send a welcome email if the option is checked in the form.
  if ($form_state['input']['notification']) {
    _c4m_user_notifications_notify_user_og_group_membership_accepted($form_state['og_membership']);
  }
}
