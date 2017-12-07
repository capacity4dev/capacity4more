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

  $users = flag_get_entity_flags($flagged_entity_type, $entity_id, $flag_name);

  // Set filtered users to full list of $users - if no filtering required,
  // this wil insure that noting gets filtered.
  $filtered_users = array_keys($users);

  // If we need to filter users according to additional flag.
  if (isset($context['additional_flag_suffix']) && isset($context['intergroup_operation'])) {
    // When 'additional flag' is provided, users will be filtered using
    // operation defined at 'intergroup_operation'.
    // When 'intergroup_operation' is set to 'intersect', only users that got
    // 'entity_id' marked by flag AND 'additional_entity_id' marked by
    // additional flag are returned.
    // When 'intergroup_operation' is set to 'diff', only users that got
    // 'entity_id' marked by flag AND NOT got 'additional_entity_id' marked by
    // additional flag are returned.
    // If 'additional_entity_id' is not provided, it's set to 'entity_id' =>
    // both flags are set on same entity.
    $flag_name = 'subscribe_c4m_follow_' . $context['additional_flag_suffix'];
    $additional_entity_id = isset($context['additional_entity_id']) ? $context['additional_entity_id'] : $entity_id;
    $filtered_users = flag_get_entity_flags(
      $flagged_entity_type,
      $additional_entity_id,
      $flag_name
    );
    // Intergroup operations can be 'intersect' or 'diff'.
    $function = 'array_' . $context['intergroup_operation'];
    // Function is either array_intersect() or array_diff().
    $filtered_users = $function(
      array_keys($users),
      array_keys($filtered_users)
    );
  }

  // Need to load the group to which content belongs, take sure user is not
  // banned at that group.
  if ($flagged_entity_type == 'node') {
    $node = node_load($entity_id);

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
  }
  // In this case, entity is a term, and it's notification is not supported
  // for current MVP.
  else {
    return [];
  }

  // Filtering users and preparing final user list.
  $users = user_load_multiple(array_keys($users));
  foreach ($users as $key => &$value) {
    // When node is group or group content, filter banned users.
    if (!is_null($group) && c4m_user_og_get_role_in_group($value, $group) == 'blocked') {
      unset($users[$key]);
      continue;
    }

    if (array_search($key, $filtered_users) !== FALSE) {
      // If user is found at filtering array, set it's notifier to mail.
      $value = ['notifiers' => ['email' => 'email']];
    }
    else {
      // If not found, filter the user.
      unset($users[$key]);
    }
  }

  // If this is a share action, we have to filter users that don't have access.
  if ($message->type === 'c4m_new_content_share_published') {
    $original_node_array = $message->field_node;
    $original_node = node_load($original_node_array[LANGUAGE_NONE][0]['target_id']);

    foreach ($users as $key => $user_value) {
      $user = user_load($key);

      // Check if the user has access to:
      // - The original node (being shared).
      // - The group we share the node to.
      if (!node_access('view', $node, $user) || !node_access('view', $original_node, $user)) {
        unset($users[$key]);
      }
    }
  }

  return $users;
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
 * Check if the entity has explicitly set a flag to skip messages.
 *
 * @param object $entity
 *   The drupal entity object.
 *
 * @return bool
 *   TRUE if a _skip_message flag is set.
 */
function _c4m_user_notifications_has_skip_message($entity) {
  // The current node was explicitly set to not send a message.
  if (!empty($entity->_skip_message)) {
    return TRUE;
  }

  return FALSE;
}

/**
 * Check if the entity has explicitly set a flag to skip notifications.
 *
 * @param object $node
 *   The drupal node object.
 *
 * @return bool
 *   TRUE if a _skip_message flag is set.
 */
function _c4m_user_notifications_has_skip_notification($node) {
  // The node has an explicit flag to prevent notifications.
  if (isset($node->c4m_send_notification) && !$node->c4m_send_notification) {
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
