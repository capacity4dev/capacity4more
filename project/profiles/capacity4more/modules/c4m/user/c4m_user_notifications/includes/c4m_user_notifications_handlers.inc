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
 * Email notification on membership request to moderated group, to group admins.
 */
function c4m_user_notifications_moderated_group_new_membership_request($membership) {
  $group_admins_ids = c4m_og_get_group_admins_ids($membership->gid, TRUE);

  foreach ($group_admins_ids as $admin_id) {
    _c4m_user_notifications_moderated_group_admin_new_membership_request($membership, $admin_id);
  }
}

/**
 * Helper function.
 *
 * Email notification on membership request to moderated group, to group admin
 * / owner.
 */
function _c4m_user_notifications_moderated_group_admin_new_membership_request($membership, $admin_id) {
  if (!($message = message_create('c4m_new_membership_request', array('uid' => $admin_id)))) {
    // If message was not created properly, return early.
    return;
  }
  c4m_message_load_tokens__c4m_new_membership_request($message);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($membership->gid);
  $wrapper->field_related_user->set($membership->etid);
  $wrapper->field_group_membership->set($membership->id);
  message_notify_send_message($wrapper->value());
}

/**
 * Email notification to user about acceptance to group (moderated and open).
 */
function c4m_user_notifications_notify_user_membership_accepted($membership) {
  $message = message_create('c4m_welcome_to_group', array('uid' => $membership->etid));
  // Define functions with which to resolve email template tokens.
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
  $group_admins_ids = c4m_og_get_group_admins_ids($membership->gid, TRUE);

  foreach ($group_admins_ids as $admin_id) {
    _c4m_user_notifications_moderated_group_notify_admins_membership_accepted($membership, $admin_id);
  }
}

/**
 * Helper function.
 *
 * Sends mail notification to group admins,admin about new member
 * that was approved.
 *
 * @param Entity $membership
 *   Membership entity.
 * @param int $admin_id
 *   Addressee admin uid.
 */
function _c4m_user_notifications_moderated_group_notify_admins_membership_accepted(Entity $membership, $admin_id) {
  global $user;
  if (!($message = message_create('c4m_notify_admins_membership_approved', array('uid' => $admin_id)))) {
    // If message was not created properly, return early.
    return;
  }
  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_notify_admins_membership_accepted($message);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($membership->gid);
  $wrapper->field_related_user->set($membership->etid);
  $wrapper->field_executing_user->set($user->uid);

  // Message will be saved in message_notify_send_message().
  message_notify_send_message($wrapper->value());
}

/**
 * Email notification to group admins about new member at open group.
 */
function c4m_user_notifications_open_group_notify_admins_membership_accepted($membership) {
  // Create an ids array of group owner and admins.
  $group_admins_ids = c4m_og_get_group_admins_ids($membership->gid, TRUE);

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
  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_new_member_joined($message);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($membership->gid);
  $wrapper->field_related_user->set($membership->etid);
  $wrapper->field_group_membership->set($membership->id);

  // Message will be saved inside message_notify_send_message().
  message_notify_send_message($wrapper->value());
}

/**
 * Email notification to user about rejection of membership request.
 */
function c4m_user_notifications_moderated_group_notify_user_membership_rejected(&$form, &$form_state) {
  global $user;
  $membership = $form_state['membership'];
  if (!($message = message_create('c4m_membership_request_rejected', array('uid' => $membership->etid)))) {
    // Return early, if message was not created properly.
    return;
  }
  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_membership_request_rejected($message);
  $message->arguments['@membership_reject_reason'] = $form_state['values']['reject_membership_request_message'];

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($membership->gid);
  $wrapper->field_executing_user->set($user->uid);

  // Message will be saved inside message_notify_send_message().
  message_notify_send_message($wrapper->value());
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
 * Email notification about organic group that was 'published'.
 *
 * Status changed from 'draft' to 'published'.
 */
function c4m_user_notifications_group_status_set_published($node) {
  $group_admins_ids = c4m_og_get_group_admins_ids($node->nid, TRUE);

  foreach ($group_admins_ids as $admin_id) {
    _c4m_user_notifications_to_admin_group_status_set_published($node, $admin_id);
  }
}

/**
 * Helper function.
 *
 * Email notification to organic group admin / owner, about status change
 * from 'archived' to 'published'.
 */
function _c4m_user_notifications_to_admin_group_status_set_published($node, $admin_id) {
  global $user;
  $message = message_create('c4m_group_published', array('uid' => $admin_id));
  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_group_published($message);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($node->nid);
  $wrapper->field_executing_user->set($user->uid);

  // Message will be saved in message_notify_send_message().
  message_notify_send_message($wrapper->value());
}

/**
 * Email notification about organic group status change to 'republished'.
 */
function c4m_user_notifications_group_status_set_republished($node, $group_former_status) {
  $group_admins_ids = c4m_og_get_group_admins_ids($node->nid, TRUE);

  foreach ($group_admins_ids as $admin_id) {
    _c4m_user_notifications_to_admin_group_status_set_republished($node, $admin_id, $group_former_status);
  }
}

/**
 * Helper function.
 *
 * Email notification to organic group admin / owner, about status change
 * from 'archived' to 'published'.
 */
function _c4m_user_notifications_to_admin_group_status_set_republished($node, $admin_id, $group_former_status) {
  global $user;
  $message = message_create('c4m_group_republished', array('uid' => $admin_id));
  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_group_republished($message);
  $message->arguments['@group_former_status'] = ucfirst($group_former_status);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($node->nid);
  $wrapper->field_executing_user->set($user->uid);

  // Message will be saved in message_notify_send_message().
  message_notify_send_message($wrapper->value());
}

/**
 * Email notification about organic group status change to 'unpublished'.
 */
function c4m_user_notifications_group_status_set_unpublished($node, $group_former_status) {
  $group_admins_ids = c4m_og_get_group_admins_ids($node->nid, TRUE);

  foreach ($group_admins_ids as $admin_id) {
    _c4m_user_notifications_to_admin_group_status_set_unpublished($node, $admin_id, $group_former_status);
  }
}

/**
 * Helper function.
 *
 * Email notification to organic group admin / owner, about status change
 * from 'published' to 'draft'.
 */
function _c4m_user_notifications_to_admin_group_status_set_unpublished($node, $admin_id, $group_former_status) {
  global $user;
  $message = message_create('c4m_group_unpublished', array('uid' => $admin_id));
  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_group_unpublished($message);
  // Set 'group former status' token to input value.
  $message->arguments['@group_former_status'] = ucfirst($group_former_status);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($node->nid);
  $wrapper->field_executing_user->set($user->uid);

  // Message will be saved in message_notify_send_message().
  message_notify_send_message($wrapper->value());
}

/**
 * Email notification about organic group status change to 'archived'.
 */
function c4m_user_notifications_group_status_set_archived($node, $group_former_status) {
  $group_admins_ids = c4m_og_get_group_admins_ids($node->nid, TRUE);

  foreach ($group_admins_ids as $admin_id) {
    _c4m_user_notifications_to_admin_group_status_set_archived($node, $admin_id, $group_former_status);
  }
}

/**
 * Helper function.
 *
 * Email notification to organic group admin / owner, about status change
 * to 'archived'.
 */
function _c4m_user_notifications_to_admin_group_status_set_archived($node, $admin_id, $group_former_status) {
  global $user;
  $message = message_create('c4m_group_archived', array('uid' => $admin_id));
  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_group_archived($message);
  $message->arguments['@group_former_status'] = ucfirst($group_former_status);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($node->nid);
  $wrapper->field_executing_user->set($user->uid);

  // Message will be saved in message_notify_send_message().
  message_notify_send_message($wrapper->value());
}

/**
 * Email notification about organic group status change to 'softdelete'.
 *
 * @param object $node
 *   Node of type OG group.
 * @param string $group_former_status
 *   Status of OG group, before it was changed to Deleted.
 */
function c4m_user_notifications_group_status_set_softdeleted($node, $group_former_status) {
  $admins_ids = c4m_admin_get_admins_ids();

  foreach ($admins_ids as $admin_id) {
    _c4m_user_notifications_to_site_admin_group_soft_deleted($node, $admin_id, $group_former_status);
  }
}

/**
 * Helper function.
 *
 * Email notification to site admin, about group being soft deleted.
 */
function _c4m_user_notifications_to_site_admin_group_soft_deleted($node, $admin_id, $group_former_status) {
  global $user;
  $message = message_create('c4m_group_soft_deleted', array('uid' => $admin_id));
  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_group_soft_deleted($message);
  $message->arguments['@group_former_status'] = ucfirst($group_former_status);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($node->nid);
  $wrapper->field_executing_user->set($user->uid);

  // Message will be saved in message_notify_send_message().
  message_notify_send_message($wrapper->value());
}

/**
 * Email notification to admins about organic group deletion.
 *
 * @param object $node
 *   Node of type OG group.
 * @param string $group_former_status
 *   Status of OG group, before it was updated.
 */
function c4m_user_notifications_group_hard_deleted($node, $group_former_status) {
  $group_admins_ids = c4m_og_get_group_admins_ids($node->nid, TRUE);

  foreach ($group_admins_ids as $admin_id) {
    _c4m_user_notifications_to_admin_group_hard_deleted($node, $admin_id, $group_former_status);
  }
}

/**
 * Helper function.
 *
 * Email notification to organic group admin / owner, about group being
 * permanently deleted.
 */
function _c4m_user_notifications_to_admin_group_hard_deleted($node, $admin_id, $group_former_status) {
  global $user;
  $message = message_create('c4m_group_hard_deleted', array('uid' => $admin_id));
  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_group_hard_deleted($message);
  $message->arguments['@group_former_status'] = $group_former_status;

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($node->nid);
  $wrapper->field_executing_user->set($user->uid);

  // Message will be saved in message_notify_send_message().
  message_notify_send_message($wrapper->value());
}

/**
 * Email notification about organic group access change.
 */
function c4m_user_notifications_group_permissions_changed($node, $permissions) {
  global $user;

  $group_admins_ids = c4m_og_get_group_admins_ids($node->nid, TRUE);
  // Make sure admin that made the change does not get a notification.
  if (($key = array_search($user->uid, $group_admins_ids)) !== FALSE) {
    unset($group_admins_ids[$key]);
  }

  foreach ($group_admins_ids as $admin_id) {
    _c4m_user_notifications_to_admin_group_permissions_changed($node, $admin_id, $permissions);
  }
}

/**
 * Helper function.
 *
 * Email notification to organic group admin / owner, about group permissions
 * change.
 */
function _c4m_user_notifications_to_admin_group_permissions_changed($node, $admin_id, $permissions) {
  global $user;
  $message = message_create('c4m_group_access_change', array('uid' => $admin_id));
  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_group_access_change($message);
  // Set 'group permissions' token to input value.
  $message->arguments['@group_permissions'] = $permissions;

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($node->nid);
  $wrapper->field_executing_user->set($user->uid);

  // Message will be saved in message_notify_send_message().
  message_notify_send_message($wrapper->value());
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
  _c4m_user_notifications_notify_content_followers_of_comment($comment->cid, $comment->nid);
}

/**
 * Helper function.
 *
 * Sends mail notification to content comments subscribers, on new comment.
 *
 * @param int $cid
 *   Comment id.
 * @param int $nid
 *   Node id.
 */
function _c4m_user_notifications_notify_content_followers_of_comment($cid, $nid) {
  global $user;
  $message = message_create('c4m_notify_content_followers_new_comment');
  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_notify_content_followers_new_comment($message);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_node->set($nid);
  $wrapper->field_comment->set($cid);
  $wrapper->field_executing_user->set($user->uid);

  $node = node_load($nid);
  // Flag suffix that is used at unsubscribe mechanism.
  $flag_suffix = 'comment';
  $additional_flag_suffix = 'node';
  // Construct the context, with parameters that will be used by
  // c4m_user_notifications_message_subscribe_get_subscribers().
  // With current setting:
  // 'flag' - follow comment,
  // 'additional flag' - follow node,
  // 'flags_operation' - 'intersect',
  // only users that are marked with 'follow comment' AND also marked with
  // 'follow node' flags will be returned.
  $context = array(
    'entity_type' => $flag_suffix,
    'entity_id' => $nid,
    'additional_flag_suffix' => $additional_flag_suffix,
    'flags_operation' => 'intersect',
  );

  // Message will be saved in message_subscribe_send_message().
  message_subscribe_send_message('node', $node, $wrapper->value(), array(), array(), $context);
}

/**
 * Email notification about user invitation to group, sent by admin.
 */
function c4m_user_notifications_notify_user_invited_by_admin($form, $form_state) {
  // Apply only to SAs.
  $site_admin_role = user_role_load_by_name('administrator');
  if (!user_has_role($site_admin_role->rid)) {
    return;
  }

  // Send a welcome email if the option is checked in the form.
  if ($form_state['input']['notification']) {
    c4m_user_notifications_notify_user_membership_accepted($form_state['og_membership']);
  }
}

/**
 * Email notification to user about him becoming group admin.
 */
function c4m_user_notifications_notify_user_admin_granted($gid, $uid) {
  global $user;
  $message = message_create('c4m_notify_promoted_member', array('uid' => $uid));
  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_notify_promoted_member($message);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($gid);
  $wrapper->field_executing_user->set($user->uid);

  // Message will be saved in message_notify_send_message().
  message_notify_send_message($wrapper->value());
}

/**
 * Email notification to group admins about user becoming group admin.
 */
function c4m_user_notifications_notify_admins_admin_granted($gid, $uid) {
}

/**
 * Sends mail notification, when group admin is demoted to regular member.
 *
 * @param int $gid
 *   Group id.
 * @param int $uid
 *   User id.
 */
function c4m_user_notifications_notify_user_admin_demoted($gid, $uid) {
  global $user;
  $message = message_create('c4m_group_admin_demoted', array('uid' => $uid));
  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_group_admin_demoted($message);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($gid);
  $wrapper->field_executing_user->set($user->uid);

  // Message will be saved in message_notify_send_message().
  message_notify_send_message($wrapper->value());
}

/**
 * Email notification to group admins about user being revoked admin status.
 */
function c4m_user_notifications_notify_admins_admin_demoted($gid, $uid) {
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
 * Email notification to users 'subscribed' to content about new recommendation.
 *
 * @param int $nid
 *   Node id.
 */
function c4m_user_notifications_content_recommended($flag, $entity_id, $account, $flagging) {
  global $user;
  $message = message_create('c4m_notify_content_recommendation');
  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_notify_content_recommendation($message);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_node->set($entity_id);
  $wrapper->field_executing_user->set($user->uid);

  $node = node_load($entity_id);
  // Flag suffix that is used at unsubscribe mechanism.
  $flag_suffix = 'node';
  // Construct the context, with parameters that will be used by
  // c4m_user_notifications_message_subscribe_get_subscribers().
  $context = array(
    'entity_type' => $flag_suffix,
    'entity_id' => $entity_id,
  );

  // Message will be saved in message_subscribe_send_message().
  message_subscribe_send_message('node', $node, $wrapper->value(), array(), array(), $context);
}

/**
 * Email notification about new content at organic group.
 */
function c4m_user_notifications_new_group_content_published($node) {
  _c4m_user_notifications_new_content_published($node);
}

/**
 * Helper function.
 *
 * Sends mail notification to group subscribers, when new content is added.
 *
 * @param object $node
 *   Content node that was added.
 */
function _c4m_user_notifications_new_content_published($node) {
  global $user;
  $message = message_create('c4m_new_content_published');
  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_new_content_published($message);
  // Resolve comment body field, in teaser mode, and assign value to it's token.
  $body_teaser = field_view_field('node', $node, 'c4m_body', 'teaser');
  $message->arguments['@node_teaser_body'] = strip_tags($body_teaser[0]['#markup']);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_node->set($node->nid);
  $node_wrapper = entity_metadata_wrapper('node', $node);
  $gid = $node_wrapper->{OG_AUDIENCE_FIELD}->value(array('identifier' => TRUE));
  $wrapper->field_group_node->set($gid);
  $wrapper->field_executing_user->set($user->uid);

  // Flag suffix that is used at unsubscribe mechanism.
  $flag_suffix = 'group';
  // Construct the context, with parameters that will be used by
  // c4m_user_notifications_message_subscribe_get_subscribers().
  $context = array(
    'entity_type' => $flag_suffix,
    'entity_id' => $gid,
  );

  // Message will be saved in message_subscribe_send_message().
  message_subscribe_send_message('node', $node, $wrapper->value(), array(), array(), $context);
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
  _c4m_user_notifications_comment_on_content($comment->cid, $comment->nid);
}

/**
 * Helper function.
 *
 * Sends mail notification to content comments subscribers, on new comment.
 *
 * @param int $cid
 *   Comment id.
 * @param int $nid
 *   Node id.
 */
function _c4m_user_notifications_comment_on_content($cid, $nid) {
  global $user;
  $message = message_create('c4m_notify_subscribers_new_comment');
  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_notify_subscribers_new_comment($message);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_node->set($nid);
  $wrapper->field_comment->set($cid);
  $wrapper->field_executing_user->set($user->uid);

  $node = node_load($nid);
  // Flag suffix that is used at unsubscribe mechanism.
  $flag_suffix = 'comment';
  $additional_flag_suffix = 'node';
  // Construct the context, with parameters that will be used by
  // c4m_user_notifications_message_subscribe_get_subscribers().
  // With current setting:
  // 'flag' - follow comment,
  // 'additional flag' - follow node,
  // 'flags_operation' - 'diff',
  // only users that are marked with 'follow comment' AND NOT marked with
  // 'follow node' flags will be returned.
  $context = array(
    'entity_type' => $flag_suffix,
    'entity_id' => $nid,
    'additional_flag_suffix' => $additional_flag_suffix,
    'flags_operation' => 'diff',
  );

  // Message will be saved in message_subscribe_send_message().
  message_subscribe_send_message('node', $node, $wrapper->value(), array(), array(), $context);
}

/**
 * Email notification to group requester, that group is waiting for review.
 */
function c4m_user_notifications_notify_new_group_pending($node) {
  $message = message_create('c4m_group_requested', array('uid' => $node->uid));
  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_group_requested($message);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($node->nid);

  // Message will be saved in message_notify_send_message().
  message_notify_send_message($wrapper->value());
}

/**
 * Email notification to site admins, about new group request.
 */
function c4m_user_notifications_notify_admins_group_requested($node) {
  $admins_ids = c4m_admin_get_admins_ids();

  foreach ($admins_ids as $admin_id) {
    _c4m_user_notifications_notify_admin_group_requested($node, $admin_id);
  }
}

/**
 * Helper function.
 *
 * Email notification to site admin, about new group request.
 */
function _c4m_user_notifications_notify_admin_group_requested($node, $admin_id) {
  global $user;
  $message = message_create('c4m_group_request_submitted', array('uid' => $admin_id));
  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_group_request_submitted($message);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($node->nid);
  $wrapper->field_executing_user->set($user->uid);

  // Message will be saved in message_notify_send_message().
  message_notify_send_message($wrapper->value());
}

/**
 * Implements hook_message_subscribe_get_subscribers().
 *
 * Uses designated context, thus disabling message_subscribe_get_subscribers()
 * of message_subscribe module.
 * Returns an array of structure [uid => notifier].
 *  uid - user that have flagged $entity_id, with $flag_name.
 *  notifier - [email].
 */
function c4m_user_notifications_message_subscribe_get_subscribers($message, $subscribe_options, $context) {
  // All entity types are nodes, besides 'term'.
  $entity_type = $context['entity_type'];
  $entity_id = $context['entity_id'];
  $flag_name = 'subscribe_c4m_follow_' . $entity_type;
  $flagged_entity_type = $entity_type == 'term' ? 'taxonomy_term' : 'node';

  $users = flag_get_entity_flags($flagged_entity_type, $entity_id, $flag_name);
  // Set filtered users to full list of $users - if no filtering required,
  // this wil insure that noting gets filtered.
  $filtered_users = array_keys($users);

  // If we need to filter users according to additional flag.
  if (isset($context['additional_flag_suffix']) && isset($context['flags_operation'])) {
    // When 'additional flag' is provided, users will be filtered using
    // operation defined at 'flags_operation'.
    // When 'flags_operation' is set to 'intersect', only users marked by flag
    // AND additional flag are returned.
    // When 'flags_operation' is set to 'diff', only users marked by flag and
    // AND NOT marked by additional flag are returned.
    $flag_name = 'subscribe_c4m_follow_' . $context['additional_flag_suffix'];
    $filtered_users = flag_get_entity_flags($flagged_entity_type, $entity_id, $flag_name);
    // Flag operations can be 'intersect' or 'diff'.
    $function = 'array_' . $context['flags_operation'];
    // Function is either array_intersect() or array_diff().
    $filtered_users = $function(array_keys($users), array_keys($filtered_users));
  }

  // Set notifiers to mail, for users that remain after filtering.
  foreach ($users as $key => &$value) {
    if (array_search($key, $filtered_users) !== FALSE) {
      // If user is found at filtering array, keep it.
      $value = array('notifiers' => array('email' => 'email'));
    }
    else {
      // If not found, unset user from array.
      unset($users[$key]);
    }
  }

  return $users;
}
