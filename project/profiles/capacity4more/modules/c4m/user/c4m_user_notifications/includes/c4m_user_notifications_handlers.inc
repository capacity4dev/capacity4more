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
 * Email notification to admins about organic group status change to 'archived'.
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
  $message->arguments['@group_former_status'] = $group_former_status;

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_group_node->set($node->nid);
  $wrapper->field_executing_user->set($user->uid);

  // Message will be saved in message_notify_send_message().
  message_notify_send_message($wrapper->value());
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
function c4m_user_notifications_group_permissions_changed($node, $permissions) {
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
function c4m_user_notifications_notify_user_admin_demoted($gid, $uid) {
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
 */
function c4m_user_notifications_content_recommended($flag, $entity_id, $account, $flagging) {
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
 * Email notification to group requester, that group is waiting for review.
 */
function c4m_user_notifications_notify_new_group_pending($node) {
}

/**
 * Returns an array of subscribers to notify.
 *
 * Function message_subscribe_get_subscribers() implementation, which is invoked
 * by message_subscribe_send_message().
 * Uses designated context, thus disabling message_subscribe_get_subscribers()
 * of message_subscribe module.
 * Returns an array of structure [uid => notifier].
 *  uid - user that have flagged $entity_id, with $flag_name.
 *  notifier - [email].
 *
 * @param object $message
 *   The Message object.
 * @param array $subscribe_options
 *   The options array.
 * @param array $context
 *   Context array, that contains required parameters.
 *
 * @return array $uids
 *   Array of users that flagged the entity:
 *   $key - uid, $value - notifier type.
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
  if (isset($context['additional_flag_suffix'])) {
    // Filtering.
    $flag_name = 'subscribe_c4m_follow_' . $context['additional_flag_suffix'];
    $filtered_users = flag_get_entity_flags($flagged_entity_type, $entity_id, $flag_name);
    $filtered_users = array_intersect(array_keys($users), array_keys($filtered_users));
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
