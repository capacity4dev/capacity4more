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
  $flag_suffix = 'node';

  // Construct the context, with parameters that will be used by
  // c4m_user_notifications_message_subscribe_get_subscribers().
  // With current setting:
  // 'flag' - follow content;
  // 'additional flag' - follow node;
  // 'intergroup_operation' - 'intersect'.
  // Only users that are marked with 'follow content' AND also marked with
  // 'follow node' flags will be returned.
  $context = [
    'entity_type' => $flag_suffix,
    'entity_id' => $comment->nid,
  ];

  $subscribe_options = _c4m_user_notifications_get_skip_entity_access_options();

  // Message will be saved in message_subscribe_send_message().
  _c4m_user_notifications_subscribe_send_message('node', $node, $wrapper->value(), [], $subscribe_options, $context);
}

/**
 * Takes parameters message_subscribe expects and creates a queue task for it.
 *
 * @param string $entity_type
 *   The entity type.
 * @param object $entity
 *   The entity object.
 * @param object $message
 *   The Message object.
 * @param array $notify_options
 *   Optional; Array of options to pass to message_notify_send_message()
 *   keyed by the notifier name.
 * @param array $subscribe_options
 *   Optional; Array with the following optional values:
 *   - "save message": Determine if the Message should be saved. Defaults
 *     to TRUE.
 *   - "skip context": Determine if extracting basic context should be
 *     skipped in message_subscribe_get_subscribers(). Defaults to FALSE.
 *   - "last uid": The last user ID to query.
 *   - "uids": Array of user IDs to be processed. Setting this, will cause
 *     skipping message_subscribe_get_subscribers() to get the subscribed
 *     users. For example:
 *     $subscribe_options['uids'] = array(
 *       1 => array(
 *        'notifiers' => array('email'),
 *       ),
 *     );
 *   - "range": The number of items to fetch in the query.
 *   - "end time": The timestamp of the time limit for the function to
 *     execute. Defaults to FALSE, meaning there is no time limitation.
 *   - "use queue": Determine if queue API should be used to
 *   - "queue": Set to TRUE to indicate the processing is done via a queue
 *     worker. see message_subscribe_queue_worker().
 *   - "entity access": Determine if access to view the entity should be applied
 *     when getting the list of subscribed users. Defaults to TRUE.
 *   - "notify blocked users": Determine whether blocked users
 *      should be notified. Typically this should be used in conjunction with
 *      "entity access" to ensure that blocked users don't receive notifications
 *      about entities which they used to have access to
 *      before they were blocked. Defaults to FALSE.
 *   - "notify message owner": Determines if the user that created the entity
 *      gets notified of their own action. If TRUE the author will get notified.
 *      Defaults to FALSE.
 * @param array $context
 *   Optional; Array keyed with the entity type and array of entity IDs as
 *   the value. For example, if the event is related to a node
 *   entity, the implementing module might pass along with the node
 *   itself, the node author and related taxonomy terms.
 */
function _c4m_user_notifications_subscribe_send_message($entity_type, $entity, $message, array $notify_options, array $subscribe_options, array $context) {
  $queue = DrupalQueue::get('c4m_user_notifications');

  $task = [
    'entity_type' => $entity_type,
    'entity' => $entity,
    'message' => $message,
    'notify_options' => $notify_options,
    'subscribe_options' => $subscribe_options,
    'context' => $context,
  ];

  $queue->createItem($task);
}

/**
 * Sends mail notification to content subscribers on new comment.
 *
 * @param object $comment
 *   The drupal comment entity object.
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
  $flag_suffix = 'content';

  // Construct the context, with parameters that will be used by
  // c4m_user_notifications_message_subscribe_get_subscribers().
  // With current setting:
  // 'flag' - follow content;
  // 'additional flag' - follow node;
  // 'intergroup_operation' - 'diff'.
  // Only users that are marked with 'follow content' AND NOT marked with
  // 'follow node' flags will be returned.
  $context = [
    'entity_type' => $flag_suffix,
    'entity_id' => $comment->nid,
    'additional_flag_context' => [
      [
        'additional_flag_name' => 'node',
        'additional_flag_operation' => 'diff',
      ],
    ],
  ];

  $subscribe_options = _c4m_user_notifications_get_skip_entity_access_options();

  // Message will be saved in message_subscribe_send_message().
  _c4m_user_notifications_subscribe_send_message('node', $node, $wrapper->value(), [], $subscribe_options, $context);
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
  _c4m_user_notifications_subscribe_send_message('node', $node, $wrapper->value(), [], $subscribe_options, $context);
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
  c4m_message_load_tokens__c4m_group_content_inserted_or_updated($message);

  if ($action === 'share') {
    // Extra tokens for shares.
    c4m_message_load_tokens__c4m_content_share_inserted_or_updated($message);
  }

  // Resolve comment body field, in teaser mode, and assign value to it's token.
  $body_teaser = field_view_field('node', $node, 'c4m_body', 'teaser');
  if (!empty($body_teaser)) {
    $message->arguments['@node_teaser_body'] = strip_tags(
      $body_teaser[0]['#markup']
    );
  }
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

  if ($action === 'update') {
    $context['additional_flag_context'] = [
      [
        'additional_flag_name' => 'node',
        'additional_flag_operation' => 'diff',
        'additional_flag_entity_id' => $node->nid,
        'additional_flag_entity_type' => 'node',
      ],
      [
        'additional_flag_name' => 'content',
        'additional_flag_operation' => 'diff',
        'additional_flag_entity_id' => $node->nid,
        'additional_flag_entity_type' => 'node',
      ],
    ];
  }
  elseif ($action === 'insert') {
    $context['additional_flag_context'] = [
      [
        'additional_flag_name' => 'node',
        'additional_flag_operation' => 'diff',
        'additional_flag_entity_id' => $node->nid,
        'additional_flag_entity_type' => 'node',
      ],
    ];
  }

  $subscribe_options = [];
  // Skip access checks for new revisions of nodes as most people don't have
  // 'revision access' permission.
  if (isset($node->vid) && isset($node->original->vid) && $node->vid !== $node->original->vid) {
    $subscribe_options = _c4m_user_notifications_get_skip_entity_access_options();
  }
  // Message will be saved in message_subscribe_send_message().
  _c4m_user_notifications_subscribe_send_message('node', $node, $wrapper->value(), [], $subscribe_options, $context);
}

/**
 * Notify subscribers when content is updated.
 *
 * Sends mail notification to follow content subscribers.
 *
 * @param object $node
 *   Content node that was added / updated.
 */
function _c4m_user_notifications_notify_subscribe_content($node) {
  global $user;

  $message = message_create('c4m_content_updated');
  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_content_inserted_or_updated($message);

  // Resolve body field, in teaser mode, and assign value to it's token.
  if ($node->type === 'article') {
    $body_teaser = field_view_field('node', $node, 'c4m_intro_text', 'teaser');
  }
  else {
    $body_teaser = field_view_field('node', $node, 'c4m_body', 'teaser');
  }
  $message->arguments['@node_teaser_body'] = strip_tags(
    $body_teaser[0]['#markup']
  );
  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_node->set($node->nid);
  $wrapper->field_executing_user->set($user->uid);

  // Flag suffix that is used at unsubscribe mechanism.
  $flag_suffix = 'content';
  // Construct the context, with parameters that will be used by
  // c4m_user_notifications_message_subscribe_get_subscribers().
  $context = [
    'entity_type' => $flag_suffix,
    'entity_id' => $node->nid,
  ];

  $subscribe_options = [];
  // Skip access checks for new revisions of nodes as most people don't have
  // 'revision access' permission.
  if (isset($node->vid) && isset($node->original->vid) && $node->vid !== $node->original->vid) {
    $subscribe_options = _c4m_user_notifications_get_skip_entity_access_options();
  }
  // Message will be saved in message_subscribe_send_message().
  _c4m_user_notifications_subscribe_send_message('node', $node, $wrapper->value(), [], $subscribe_options, $context);
}

/**
 * Notify subscribers when content is published with topics/regions of interest.
 *
 * Sends mail notification to topic subscribers, when content is add that
 * matches one of their topics of interest or regions/countries of interest.
 *
 * @param object $node
 *   Content node that was added / published.
 */
function _c4m_user_notifications_notify_subscribe_content_of_interest($node, $action = 'publish') {
  global $user;

  $message = message_create('c4m_notify_subscribe_content_of_interest');
  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_content_of_interest($message);

  if ($node->type === 'article') {
    $body_teaser = field_view_field('node', $node, 'c4m_intro_text', 'teaser');
  }
  else {
    // Resolve body field, in teaser mode, and assign value to it's token.
    $body_teaser = field_view_field('node', $node, 'c4m_body', 'teaser');
  }

  if (!empty($body_teaser)) {
    $message->arguments['@node_teaser_body'] = strip_tags($body_teaser[0]['#markup']);
  }

  $info = [];
  switch ($action) {
    case 'highlight':
      $message->arguments['@event_action'] = t('highlighted');
      break;

    case 'publish':
    default:
      $message->arguments['@event_action'] = t('published');
      if (!og_is_group('node', $node)) {
        // We don't need extra filtering when publishing a group / project.
        $info['no_follow_group'] = TRUE;
        $info['no_follow_node'] = TRUE;
      }
      break;
  }

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_node->set($node->nid);
  $wrapper->field_executing_user->set($user->uid);
  $wrapper->save();

  // Iterate over all tagged topic terms.
  _c4m_user_notifications_notify_subscribe_content_of_interest_for_vocabulary($info, $node, 'c4m_vocab_topic', $wrapper);

  // Iterate over all tagged geo terms terms.
  _c4m_user_notifications_notify_subscribe_content_of_interest_for_vocabulary($info, $node, 'c4m_vocab_geo', $wrapper);
}

/**
 * Take a vocabulary name and schedule a message for all subscribers.
 *
 * @param array $info
 *   Array of flags.
 * @param object $node
 *   Drupal node entity object.
 * @param string $vocabulary
 *   Name of the vocabulary.
 * @param object $wrapper
 *   Drupal message entity object.
 *
 * @throws \Exception
 */
function _c4m_user_notifications_notify_subscribe_content_of_interest_for_vocabulary(array $info, $node, $vocabulary, $wrapper) {
  $node_wrapper = entity_metadata_wrapper('node', $node);
  $vocab_terms = $node_wrapper->get($vocabulary)->value();
  foreach ($vocab_terms as $term_key => $term) {
    $wrapper->field_taxonomy_term->set($term->tid);

    // Construct the context, with parameters that will be used by
    // c4m_user_notifications_message_subscribe_get_subscribers().
    $context = [
      'entity_type' => 'term',
      'entity_id' => $term->tid,
    ];

    // Additional flag context needed to prevent duplicates.
    if (!empty($info['no_follow_node'])) {
      $context['additional_flag_context'][] = [
        'additional_flag_name' => 'node',
        'additional_flag_operation' => 'diff',
        'additional_flag_entity_id' => $node->nid,
        'additional_flag_entity_type' => 'node',
      ];
    }

    // If Group content, additional flag context needed to prevent duplicates.
    if (isset($node_wrapper->{OG_AUDIENCE_FIELD}) && !empty($info['no_follow_group'])) {
      $context['additional_flag_context'][] = [
        'additional_flag_name' => 'group',
        'additional_flag_operation' => 'diff',
        'additional_flag_entity_id' => $node_wrapper->{OG_AUDIENCE_FIELD}->get('nid')
          ->value(),
        'additional_flag_entity_type' => 'node',
      ];
    }
    $subscribe_options = [];
    // Skip access checks for new revisions of nodes as most people don't have
    // 'revision access' permission.
    if (isset($node->vid) && isset($node->original->vid) && $node->vid !== $node->original->vid) {
      $subscribe_options = _c4m_user_notifications_get_skip_entity_access_options();
    }
    // Message will be saved in message_subscribe_send_message().
    _c4m_user_notifications_subscribe_send_message('taxonomy_term', $term, $wrapper->value(), [], $subscribe_options, $context);
  }
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
 *   Use 'content_followers' when notifying content followers about content
 *   update.
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

    case 'content_followers':
      $message_type = 'c4m_group_content_updated';
      $flag_suffix = 'content';
      break;

    default:
      return;
  }

  $message = message_create($message_type);
  // Define functions with which to resolve email template tokens.
  c4m_message_load_tokens__c4m_group_content_inserted_or_updated($message);

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

  if ('group_followers' === $users_group) {
    // Resolve content node body field, in teaser mode, and assign value to
    // it's token.
    $body_teaser = field_view_field('node', $node, 'c4m_body', 'teaser');
    if (!empty($body_teaser)) {
      $message->arguments['@node_teaser_body'] = strip_tags($body_teaser[0]['#markup']);
    }

    // Set additional context parameters.
    // This configuration will result in selecting subscribers that
    // follow content node group, and do not follow content node itself.
    $context['entity_id'] = $gid;

    $context['additional_flag_context'] = [
      [
        'additional_flag_name' => 'node',
        'additional_flag_operation' => 'diff',
        'additional_flag_entity_id' => $node->nid,
      ],
      [
        'additional_flag_name' => 'content',
        'additional_flag_operation' => 'diff',
        'additional_flag_entity_id' => $node->nid,
      ],
    ];
  }
  else {
    $context['entity_id'] = $node->nid;
  }

  $subscribe_options = _c4m_user_notifications_get_skip_entity_access_options();

  // Message will be saved in message_subscribe_send_message().
  _c4m_user_notifications_subscribe_send_message('node', $node, $message_wrapper->value(), [], $subscribe_options, $context);
}
