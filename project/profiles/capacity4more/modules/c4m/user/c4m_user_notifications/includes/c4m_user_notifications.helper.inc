<?php

/**
 * @file
 * Helper functionality to make life easier.
 */

/**
 * Retrieve the subscribers of a specific notification message being sent.
 *
 * Uses designated context, thus disabling message_subscribe_get_subscribers()
 * of message_subscribe module.
 * Returns an array of structure [uid => notifier].
 *  uid - user that have flagged $entity_id, with $flag_name.
 *  notifier - [email].
 *
 * @param \Message $message
 *   The message object.
 * @param array $context
 *   Array keyed with the entity type and array of entity IDs as the
 *   value. According to this context this function will retrieve the
 *   related subscribers.
 *
 * @return array
 *   List of users that should receive this message.
 */
function _c4m_user_notifications_message_subscribe_get_subscribers(Message $message, array $context) {
  // All entity types are nodes, besides 'term'.
  $entity_type = $context['entity_type'];
  $entity_id = $context['entity_id'];
  $flag_name = 'subscribe_c4m_follow_' . $entity_type;
  $flagged_entity_type = $entity_type == 'term' ? 'taxonomy_term' : 'node';

  // Starting point: all users subscribed to the entity (flagged).
  $flagged_users = flag_get_entity_flags($flagged_entity_type, $entity_id, $flag_name);

  _c4m_message_digest_get_subscribers_remove_unsubscribed($flagged_users);

  // When creating messages, we can indicate additional context(s) to either
  // exclude users (diff) or make it stricter (intersect).
  $filtered_users = _c4m_user_notifications_message_subscribe_filter_additional_flag_contexts($context, $flagged_users, $entity_id, $flagged_entity_type);

  $group = NULL;

  // If content belongs to a group, we load the group to make sure the user is
  // not banned at that group.
  if ($flagged_entity_type == 'node') {
    $group = _c4m_user_notifications_message_subscribe_get_subscribers_get_group($entity_id);
  }

  $wrapper = entity_metadata_wrapper('message', $message);

  if ($message->type === 'c4m_notify_subscribe_content_of_interest') {
    // Notifications for interests are "dynamic", meaning one message ID serves
    // different term ID's.
    $wrapper->field_taxonomy_term->set($entity_id);

    // If the original node belongs to a group, we will need to check access.
    $group = _c4m_user_notifications_message_subscribe_get_subscribers_get_group(
      $wrapper->field_node->get('nid')->value()
    );
  }

  // The first time recipients are loaded, no mid is available yet.
  // However, we need this to store/retrieve recipients for a message, to
  // prevent users getting one message twice (if they are subscribed to multiple
  // topics/regions of interest for example.
  if (empty($message->identifier())) {
    $message->save();
  }

  // Load the list of users that already received this message (same message id)
  // to prevent duplicates.
  $previous_recipients = _c4m_user_notifications_get_message_unique_recipients($message->identifier());

  // Remove executing user, he knows what he did.
  if (!empty($wrapper->field_executing_user)) {
    $executing_user = $wrapper->field_executing_user->get('uid')->value();
    if (array_key_exists($executing_user, $flagged_users)) {
      unset($flagged_users[$executing_user]);
    }
  }

  foreach ($previous_recipients as $recipient) {
    if (array_key_exists($recipient, $flagged_users)) {
      unset($flagged_users[$recipient]);
    }
  }

  // Filtering users and preparing final user list.
  $users = user_load_multiple(array_keys($flagged_users));

  // Iterate over all users and unset users based on properties, roles...
  foreach ($users as $key => &$user_object) {

    // Content has, is, or is related to, a group.
    if (!is_null($group)) {

      // Users who are banned should not receive a notification.
      if (c4m_user_og_get_role_in_group($user_object, $group) == 'blocked') {
        unset($users[$key]);
        continue;
      }

      if (!node_access('view', $group, $user_object)) {
        unset($users[$key]);
        continue;
      }
    }

    // If this is a share action, we have to check access to both source and
    // target node (+ group).
    if ($message->type === 'c4m_new_content_share_published') {
      $node = node_load($entity_id);
      $original_node_array = $message->field_node;
      $original_node = node_load($original_node_array[LANGUAGE_NONE][0]['target_id']);

      if (!node_access('view', $node, $user_object) || !node_access('view', $original_node, $user_object)) {
        unset($users[$key]);
        continue;
      }
    }

    // If user is found at filtering array, retrieve its notifier and set it.
    if (array_search($key, $filtered_users) !== FALSE) {
      $user_object = _c4m_user_notifications_get_preference($user_object, $flagged_users[$key]);
    }
    else {
      $user_object = NULL;
    }

    if (!$user_object) {
      unset($users[$key]);
      continue;
    }
  }

  ksort($users);

  _c4m_user_notifications_update_message_unique_recipients($message->identifier(), $previous_recipients, $users);

  return $users;
}

/**
 * Helper method to get a user's flagging preference and set the notifier.
 *
 * @param object $user
 *   Drupal user object to store notifier in.
 * @param object $flagged_user
 *   Flagging object.
 *
 * @return null|array
 *   If a preference was stored, return it as an array, otherwise null.
 */
function _c4m_user_notifications_get_preference($user, $flagged_user) {
  if (!module_exists('c4m_message_digest')) {
    $user_notifier = ['notifiers' => ['email' => 'email']];
  }
  else {
    $user_notifier = c4m_message_digest_get_notifier($flagged_user);
  }

  return $user_notifier;
}

/**
 * Check if an entity_id is either a group itself or group content.
 *
 * @param int $nid
 *   The node ID.
 *
 * @return object
 *   Group node object or NULL.
 */
function _c4m_user_notifications_message_subscribe_get_subscribers_get_group($nid) {
  $node = node_load($nid);

  if (empty($node)) {
    return NULL;
  }

  // Node is a group.
  if (og_is_group_type('node', $node->type)) {
    $group = $node;
  }
  // Node is group content.
  elseif (og_is_group_content_type('node', $node->type)) {
    $group = c4m_og_get_group_of_content($node);
  }
  // Site content which does not belong to a group. For example, 'article'.
  else {
    $group = NULL;
  }
  return $group;
}

/**
 * Process additional flag contexts to restrict subscriptions.
 *
 * @param array $context
 *   Array keyed with the entity type and array of entity IDs as the
 *   value. According to this context this function will retrieve the
 *   related subscribers.
 * @param array $users
 *   Array with all the flagged users.
 * @param int $entity_id
 *   Original flag's entity id. If no separate additional entity ID is passed,
 *   this will be used as a fallback.
 * @param string $flagged_entity_type
 *   Entity type the flag will apply to.
 *
 * @return array
 *   Array with all users filtered by the additional flag contexts.
 */
function _c4m_user_notifications_message_subscribe_filter_additional_flag_contexts(array $context, array $users, $entity_id, $flagged_entity_type) {
  $filtered_users = array_keys($users);

  if (!empty($context['additional_flag_context']) && is_array($context['additional_flag_context'])) {
    foreach ($context['additional_flag_context'] as $flag_context) {
      $flag_name = 'subscribe_c4m_follow_' . $flag_context['additional_flag_name'];
      $flag_entity_id = !empty($flag_context['additional_flag_entity_id']) ? $flag_context['additional_flag_entity_id'] : $entity_id;
      $flag_entity_type = !empty($flag_context['additional_flag_entity_type']) ? $flag_context['additional_flag_entity_type'] : $flagged_entity_type;

      $flagged_users = flag_get_entity_flags(
        $flag_entity_type,
        $flag_entity_id,
        $flag_name
      );

      // Operation can be 'intersect' or 'diff'.
      $function = 'array_' . $flag_context['additional_flag_operation'];

      // Function is either array_intersect() or array_diff().
      $filtered_users = $function(
        $filtered_users,
        array_keys($flagged_users)
      );
    }
  }
  return $filtered_users;
}

/**
 * Merge the previous recipients and new users to one array and store it.
 *
 * @param int $mid
 *   Message entity ID.
 * @param array $previous_recipients
 *   Array of user ID's of already-subscribed users.
 * @param array $users
 *   Array of users that were added/subscribed now.
 */
function _c4m_user_notifications_update_message_unique_recipients($mid, array $previous_recipients, array $users) {
  $all_subscribers = array_merge($previous_recipients, array_keys($users));

  // Only makes sense if there are any.
  if (count($all_subscribers) > 0) {
    $all_subscribers = array_values(array_unique($all_subscribers));
    _c4m_user_notifications_set_message_unique_recipients($mid, $all_subscribers);
  }
}

/**
 * Helper function to get UID's already subscribed for a specific notification.
 *
 * @param int $mid
 *   Message ID.
 *
 * @return array
 *   UID's that already received this message.
 */
function _c4m_user_notifications_get_message_unique_recipients($mid) {
  $recipients = db_query('SELECT recipients FROM {message_recipients_unique} WHERE mid = :mid', [':mid' => $mid])->fetchAssoc();

  if (empty($recipients['recipients'])) {
    return [];
  }

  return array_values(unserialize($recipients['recipients']));
}

/**
 * Helper function to set UID's subscribed for a specific notification.
 *
 * @param int $mid
 *   Message ID.
 * @param array $uids
 *   Array of UID's that will receive this notification.
 */
function _c4m_user_notifications_set_message_unique_recipients($mid, array $uids) {
  db_merge('message_recipients_unique')
    ->key(['mid' => $mid])
    ->fields([
      'recipients' => serialize($uids),
    ])
    ->execute();
}

/**
 * Options to allow receiving notification about new revision.
 *
 * Returns options which allow group members to receive email notification
 * about new content revisions.
 *
 * @return array
 *   Subscribe options, so that message_subscribe model will skip
 *   'entity access' check.
 */
function _c4m_user_notifications_get_skip_entity_access_options() {
  return [
    'entity access' => [],
  ];
}

/**
 * Resolves the permissions of group.
 *
 * @param array $access
 *   Group access.
 * @param bool $membership_open
 *   Is membership open (if not -> moderated).
 *
 * @return string
 *   Returns permissions.
 */
function _c4m_user_notifications_build_group_permissions(array $access, $membership_open) {
  if ($access['type'] == 'private') {
    return 'PRIVATE';
  }
  else {
    $membership_type = $membership_open ? 'OPEN' : 'MODERATED';

    return strtoupper($access['type']) . ', ' . $membership_type;
  }
}

/**
 * Check if the current membership has access to the triggering system.
 *
 * An og_membership should get access to the triggering system if it is not
 * within a migration process and its entity_type is "user".
 *
 * @param object $og_membership
 *   The og_membership object.
 *
 * @return bool
 *   TRUE if the the membership is valid for access.
 */
function _c4m_user_notifications_has_og_membership_trigger_access($og_membership) {
  if (_c4m_user_notifications_is_cli()) {
    return FALSE;
  }

  // If the membership type is not 'user'.
  if (!isset($og_membership->entity_type) || $og_membership->entity_type != 'user') {
    return FALSE;
  }

  return TRUE;
}

/**
 * Check if the environment is a command line interface.
 *
 * When the environment is a CLI, we don't want to send notifications for
 * example.
 *
 * @return bool
 *   TRUE in case the env is CLI.
 */
function _c4m_user_notifications_is_cli() {
  if (drupal_is_cli()) {
    return TRUE;
  }
  return FALSE;
}

/**
 * Return the group (wrapper)'s membership request type.
 *
 * @param object $wrapper
 *   Entity wrapper around the group.
 *
 * @return int
 *   Group membership request type.
 */
function _c4m_user_notifications_get_group_membership_request_type($wrapper) {
  if (!isset($wrapper->field_membership_open_request)) {
    return -1;
  }

  return $wrapper->field_membership_open_request->value();
}

/**
 * Check if the node author is anonymous.
 *
 * @param object $node
 *   Node entity object.
 *
 * @return bool
 *   TRUE is the author is anonymous (or not set).
 */
function _c4m_user_notifications_is_node_author_anonymous($node) {
  return _c4m_user_notifications_is_entity_author_anonymous($node);
}

/**
 * Check if the entity author is anonymous.
 *
 * @param object $entity
 *   Entity object.
 *
 * @return bool
 *   TRUE is the author is anonymous (or not set).
 */
function _c4m_user_notifications_is_entity_author_anonymous($entity) {
  if (!isset($entity->uid)) {
    return TRUE;
  }
  if ($entity->uid === 0) {
    return TRUE;
  }

  return FALSE;
}

/**
 * Check if the node is unpublished.
 *
 * @param object $node
 *   Node entity object.
 *
 * @return bool
 *   TRUE if the node is not published.
 */
function _c4m_user_notifications_is_node_unpublished($node) {
  if (!isset($node->status)) {
    return TRUE;
  }

  if ($node->status === NODE_NOT_PUBLISHED) {
    return TRUE;
  }

  return FALSE;
}

/**
 * Check if the entity has explicitly set a flag to skip notifications.
 *
 * @param object $entity
 *   The entity object.
 *
 * @return bool
 *   TRUE if the c4m_send_notification flag is set to FALSE.
 */
function _c4m_user_notifications_has_skip_notification($entity) {
  // The node has an explicit flag set to FALSE to prevent notifications.
  if (isset($entity->c4m_send_notification) && !$entity->c4m_send_notification) {
    return TRUE;
  }

  return FALSE;
}

/**
 * Check if a given role ID matches the group "administrator member" role.
 *
 * @param int $rid
 *   Role ID we want to check.
 */
function _c4m_user_notifications_is_og_admin_role($rid) {
  $group_admin_role = c4m_og_user_role_load_by_name('administrator member', 'group');

  // Check if the Group Administrator role is granted.
  // Don't send a notification for other roles (shouldn't happen).
  if ($group_admin_role->rid != $rid) {
    return FALSE;
  }

  return TRUE;
}
