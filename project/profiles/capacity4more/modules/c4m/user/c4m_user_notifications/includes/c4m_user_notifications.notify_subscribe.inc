<?php

/**
 * @file
 * Logic behind subscription notifications.
 */

/**
 * Sends mail notification to content comments subscribers on new comment.
 *
 * @param object $comment
 *   The drupal comment entity object.
 */
function _c4m_user_notifications_notify_subscribe_commenter_new_comment($comment) {
  global $user;
  $message = message_create('c4m_notify_content_followers_new_comment');

  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_notify_content_followers_new_comment($message);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_node->set($comment->nid);
  $wrapper->field_comment->set($comment->cid);
  $wrapper->field_executing_user->set($user->uid);

  $node = node_load($comment->nid);

  // Flag suffix that is used at unsubscribe mechanism.
  $flag_suffix = 'comment';
  $additional_flag_suffix = 'node';

  // Construct the context, with parameters that will be used by
  // c4m_user_notifications_message_subscribe_get_subscribers().
  // With current setting:
  // 'flag' - follow comment,
  // 'additional flag' - follow node,
  // 'intergroup_operation' - 'intersect',
  // only users that are marked with 'follow comment' AND also marked with
  // 'follow node' flags will be returned.
  $context = [
    'entity_type' => $flag_suffix,
    'entity_id' => $nid,
    'additional_flag_suffix' => $additional_flag_suffix,
    'intergroup_operation' => 'intersect',
  ];

  $subscribe_options = _c4m_user_notifications_get_skip_entity_access_options();

  // Message will be saved in message_subscribe_send_message().
  message_subscribe_send_message('node', $node, $wrapper->value(), [], $subscribe_options, $context);
}

/**
 * Sends mail notification to content subscribers on new comment.
 *
 * @param int $cid
 *   Comment id.
 * @param int $nid
 *   Node id.
 */
function _c4m_user_notifications_notify_subscribe_follower_new_comment($comment) {
  global $user;
  $message = message_create('c4m_notify_subscribers_new_comment');

  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_notify_subscribers_new_comment($message);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_node->set($comment->nid);
  $wrapper->field_comment->set($comment->cid);
  $wrapper->field_executing_user->set($user->uid);

  $node = node_load($comment->nid);

  // Flag suffix that is used at unsubscribe mechanism.
  $flag_suffix = 'comment';
  $additional_flag_suffix = 'node';

  // Construct the context, with parameters that will be used by
  // c4m_user_notifications_message_subscribe_get_subscribers().
  // With current setting:
  // 'flag' - follow comment,
  // 'additional flag' - follow node,
  // 'intergroup_operation' - 'diff',
  // only users that are marked with 'follow comment' AND NOT marked with
  // 'follow node' flags will be returned.
  $context = [
    'entity_type' => $flag_suffix,
    'entity_id' => $nid,
    'additional_flag_suffix' => $additional_flag_suffix,
    'intergroup_operation' => 'diff',
  ];

  $subscribe_options = _c4m_user_notifications_get_skip_entity_access_options();

  // Message will be saved in message_subscribe_send_message().
  message_subscribe_send_message('node', $node, $wrapper->value(), [], $subscribe_options, $context);
}

/**
 * Email notification to users 'subscribed' to content about new recommendation.
 *
 * @param int $nid
 *   Flagged node id.
 */
function _c4m_user_notifications_notify_subscribe_follower_new_recommend($nid) {
  global $user;
  $message = message_create('c4m_notify_content_recommendation');

  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_notify_content_recommendation($message);

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_node->set($nid);
  $wrapper->field_executing_user->set($user->uid);

  $node = node_load($nid);

  // Flag suffix that is used at unsubscribe mechanism.
  $flag_suffix = 'node';

  // Construct the context, with parameters that will be used by
  // c4m_user_notifications_message_subscribe_get_subscribers().
  $context = [
    'entity_type' => $flag_suffix,
    'entity_id' => $nid,
  ];

  $subscribe_options = _c4m_user_notifications_get_skip_entity_access_options();

  // Message will be saved in message_subscribe_send_message().
  message_subscribe_send_message('node', $node, $wrapper->value(), [], $subscribe_options, $context);
}

/**
 * Notify subscribers when group content is manipulated.
 *
 * Sends mail notification to group subscribers, when content is
 * added, updated or shared.
 *
 * @param object $node
 *   Content node that was added / updated.
 * @param string $action
 *   Use 'insert' when new content is added.
 *   Use 'update' when existing content is updated.
 *   Use 'share' when content is shared.
 * @param int $target_gid
 *   Group ID for which notification is issued. If not passed, it's set to
 *   gid of group node belong to.
 */
function _c4m_user_notifications_notify_subscribe_group_content($node, $action, $target_gid = NULL) {
  global $user;

  switch ($action) {
    case 'insert':
      $message_type = 'c4m_new_content_published';
      $event_action = 'added';
      break;

    case 'share':
      $message_type = 'c4m_new_content_share_published';
      $event_action = 'shared';
      break;

    case 'update':
      $message_type = 'c4m_group_content_updated';
      break;

    default:
      return;
  }

  $message = message_create($message_type);
  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_content_inserted_or_updated($message);

  if ($action == 'share') {
    // Extra tokens for shares.
    c4m_message_load_tokens__c4m_content_share_inserted_or_updated($message);
  }

  // Resolve comment body field, in teaser mode, and assign value to it's token.
  $body_teaser = field_view_field('node', $node, 'c4m_body', 'teaser');
  $message->arguments['@node_teaser_body'] = strip_tags(
    $body_teaser[0]['#markup']
  );
  if (isset($event_action)) {
    $message->arguments['@event_action'] = $event_action;
  }

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_node->set($node->nid);
  $node_wrapper = entity_metadata_wrapper('node', $node);
  $gid = !is_null($target_gid) ? $target_gid : $node_wrapper->{OG_AUDIENCE_FIELD}->value(['identifier' => TRUE]);
  $wrapper->field_group_node->set($gid);
  $wrapper->field_executing_user->set($user->uid);

  // Flag suffix that is used at unsubscribe mechanism.
  $flag_suffix = 'group';
  // Construct the context, with parameters that will be used by
  // c4m_user_notifications_message_subscribe_get_subscribers().
  $context = [
    'entity_type' => $flag_suffix,
    'entity_id' => $gid,
  ];

  $subscribe_options = [];
  // Skip access checks for new revisions of nodes as most people don't have
  // 'revision access' permission.
  if (isset($node->vid) && isset($node->original->vid) && $node->vid !== $node->original->vid) {
    $subscribe_options = _c4m_user_notifications_get_skip_entity_access_options();
  }
  // Message will be saved in message_subscribe_send_message().
  message_subscribe_send_message('node', $node, $wrapper->value(), [], $subscribe_options, $context);
}

/**
 * Send specific notifications on content updates.
 *
 * When content is updated, sends mail notification to two groups of users:
 * group subscribers & content author and editors.
 *
 * @param object $node
 *   Content node that was updated.
 * @param string $users_group
 *   Use 'group_followers' when notifying group followers about content update.
 *   Use 'content_editors' when notifying content editors about content update.
 */
function _c4m_user_notifications_notify_subscribe_content_revision($node, $users_group) {
  global $user;

  switch ($users_group) {
    case 'content_editors':
      $message_type = 'c4m_notify_editors_group_content_updated';
      $flag_suffix = 'node';
      break;

    case 'group_followers':
      $message_type = 'c4m_group_content_updated';
      $flag_suffix = 'group';
      break;

    default:
      return;
  }

  $message = message_create($message_type);
  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_content_inserted_or_updated($message);

  $message_wrapper = entity_metadata_wrapper('message', $message);
  $message_wrapper->field_node->set($node->nid);
  $node_wrapper = entity_metadata_wrapper('node', $node);
  $gid = $node_wrapper->{OG_AUDIENCE_FIELD}->value(['identifier' => TRUE]);
  $message_wrapper->field_group_node->set($gid);
  $message_wrapper->field_executing_user->set($user->uid);

  // Construct the context, with parameters that will be used by
  // c4m_user_notifications_message_subscribe_get_subscribers().
  $context = [
    'entity_type' => $flag_suffix,
  ];

  if ($users_group == 'group_followers') {
    // Resolve content node body field, in teaser mode, and assign value to
    // it's token.
    $body_teaser = field_view_field('node', $node, 'c4m_body', 'teaser');
    $message->arguments['@node_teaser_body'] = strip_tags($body_teaser[0]['#markup']);

    // Set additional context parameters.
    // This configuration will result in selecting subscribers that
    // follow content node group, and do not follow content node itself.
    $context['entity_id'] = $gid;
    $context['additional_entity_id'] = $node->nid;
    $context['additional_flag_suffix'] = 'node';
    $context['intergroup_operation'] = 'diff';
  }
  elseif ($users_group == 'content_editors') {
    $context['entity_id'] = $node->nid;
  }

  $subscribe_options = _c4m_user_notifications_get_skip_entity_access_options();

  // Message will be saved in message_subscribe_send_message().
  message_subscribe_send_message('node', $node, $message_wrapper->value(), [], $subscribe_options, $context);
}
