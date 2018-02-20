<?php

/**
 * @file
 * Business logic to dispatch and trigger the proper notifications.
 */

module_load_include('inc', 'c4m_user_notifications', 'includes/c4m_user_notifications.notify');
module_load_include('inc', 'c4m_user_notifications', 'includes/c4m_user_notifications.notify_subscribe');

/**
 * Dispatch notifications when a new membership is added to a group.
 *
 * Triggers email notification on new membership request for moderated groups,
 * and 'new member joined' notification to user and group owner and admins for
 * open group.
 *
 * @param object $og_membership
 *   Membership entity.
 *
 * @Sends MT13 - Simple notification
 * @Sends MT14 - Simple notification
 * @Sends MT15 - Simple notification
 * @Sends MT48 - Simple notification
 */
function _c4m_user_notifications_og_membership_insert($og_membership) {
  if (!_c4m_user_notifications_has_og_membership_trigger_access($og_membership)) {
    return;
  }

  // Load the group (wrapper) for this membership.
  $wrapper = entity_metadata_wrapper('node', $og_membership->gid);
  try {
    $group = $wrapper->value();
  }
  catch (EntityMetadataWrapperException $e) {
    watchdog('c4m_user_notifications', 'EntityMetadataWrapperException when getting group value', [], WATCHDOG_ERROR);
    return;
  }

  // Return early if group membership type is not set, or if added membership
  // is for group owner (happens only when group is created).
  if (!isset($wrapper->field_membership_open_request) || $og_membership->etid == $group->uid) {
    return;
  }

  $group_membership_request_type = _c4m_user_notifications_get_group_membership_request_type($wrapper);

  // Moderated group with state Pending. Check if it's an invitation or a
  // membership request.
  if ($group_membership_request_type == C4M_OG_MODERATED_GROUP && $og_membership->state == OG_STATE_PENDING) {
    // If not an invitation, the {og_membership} entity
    // {og_membership_invitation} field is not set.
    if (isset($og_membership->og_membership_invitation)) {
      // It's an invitation to join a moderated group.
      // The {og_invite} module added the membership request and sent a message
      // to the user for approval. No need to notify the group admins on this.
      return;
    }

    // Send MT15 - Notify GO/GA about new membership request.
    _c4m_user_notifications_notify_og_group_membership_request($og_membership);
    // Send MT48 - Inform user that it's membership request is sent for
    // approval.
    _c4m_user_notifications_notify_user_og_group_membership_pending($og_membership);
  }
  // Open group with state Active - new member added.
  // Membership acceptance notification to user, for open and moderated
  // group is the same (template MT13).
  elseif ($group_membership_request_type == C4M_OG_OPEN_GROUP && $og_membership->state == OG_STATE_ACTIVE) {
    // Send MT14 - Notify GO/GA about newly joined (or accepted) member.
    _c4m_user_notifications_notify_og_group_membership_joined($og_membership);
    // Send MT13 - Welcome user to the group.
    _c4m_user_notifications_notify_user_og_group_membership_accepted($og_membership);
  }
}

/**
 * Dispatch notifications when group membership are updated (approved/accepted).
 *
 * Notified states:
 *   Pending -> Accepted.
 *   Pending -> Rejected.
 *
 * @param object $og_membership
 *   Membership entity.
 *
 * @Sends MT13 - Simple notification
 * @Sends MT14 - Simple notification
 * @Sends MT40 - Simple notification
 */
function _c4m_user_notifications_dispatch_og_membership_update($og_membership) {
  if (!_c4m_user_notifications_has_og_membership_trigger_access($og_membership)) {
    return;
  }

  // Must have original state, as we're performing update.
  if (empty($og_membership->original)) {
    return;
  }

  // Only trigger notifications when coming from Pending.
  if ($og_membership->original->state != OG_STATE_PENDING) {
    return;
  }

  // Loading group/project to resolve it's membership type - moderated/open.
  $wrapper = entity_metadata_wrapper('node', $og_membership->gid);
  if (!isset($wrapper->field_membership_open_request)) {
    return;
  }

  $group_membership_request_type = _c4m_user_notifications_get_group_membership_request_type($wrapper);

  // Membership acceptance notification to user, for an open or a moderated
  // group is the same.
  if ($og_membership->state == OG_STATE_ACTIVE) {
    // Send MT13 - Welcome user to the group.
    _c4m_user_notifications_notify_user_og_group_membership_accepted($og_membership);

    // When a user was invited and approves the request through the link he
    // received by mail, there is no need to notify admins about new member.
    $invited_member = in_array($og_membership->etid, c4m_og_get_invited_memberships_ids());
    if ($invited_member) {
      return;
    }

    // Notify admins about new user.
    if ($group_membership_request_type == C4M_OG_MODERATED_GROUP) {
      // Send MT40 - Notify GO/GA about accepted member (and who accepted him).
      _c4m_user_notifications_notify_og_group_membership_approved($og_membership);
    }
    elseif ($group_membership_request_type == C4M_OG_OPEN_GROUP) {
      // Send MT14 - Notify GO/GA about newly joined member.
      _c4m_user_notifications_notify_og_group_membership_joined($og_membership);
    }
  }
}

/**
 * Triggers email notification when recommendation flag is set.
 *
 * @param object $flag
 *   The drupal flag entity.
 * @param int $entity_id
 *   Entity id of the content being flagged.
 *
 * @Send MT26 - Subscription notification
 */
function _c4m_user_notifications_flag_flag($flag, $entity_id) {
  if (_c4m_user_notifications_is_cli()) {
    return;
  }

  // If not recommendation flag, return early.
  if ($flag->name != 'c4m_og_content_recommend') {
    return;
  }

  // If anonymous user, return early - no notifications.
  if (user_is_anonymous()) {
    return;
  }

  $node = node_load($entity_id);

  // Not all content types will trigger notifications.
  $notification_types = c4m_og_get_extended_content_notification_types();

  if (!in_array($node->type, $notification_types)) {
    return;
  }

  // Send MT23 - Inform subscribed users of the node that this content was
  // recommended by a non-anonymous user.
  _c4m_user_notifications_notify_subscribe_follower_new_recommend($entity_id);
}

/**
 * Dispatch email notification when user is promoted to administrator.
 *
 * @param int $gid
 *   Group ID the user got a role granted in.
 * @param int $uid
 *   User ID that got granted a role.
 * @param int $rid
 *   Role ID that is granted.
 *
 * @Send MT35 - Simple notification
 */
function _c4m_user_notifications_og_role_grant($gid, $uid, $rid) {
  if (_c4m_user_notifications_is_cli()) {
    return;
  }

  if (!_c4m_user_notifications_is_og_admin_role($rid)) {
    return;
  }

  // Send MT35 - Inform user he became a group admin for this group.
  _c4m_user_notifications_notify_og_role_grant($gid, $uid);
}

/**
 * Dispatch email notification when user is revoked his administrator role.
 *
 * @param int $gid
 *   Group ID the user got a role granted in.
 * @param int $uid
 *   User ID that got granted a role.
 * @param int $rid
 *   Role ID that is granted.
 *
 * @Send MT36 - Simple notification
 */
function _c4m_user_notifications_og_role_revoke($gid, $uid, $rid) {
  if (_c4m_user_notifications_is_cli()) {
    return;
  }

  if (!_c4m_user_notifications_is_og_admin_role($rid)) {
    return;
  }

  $path = explode('/', current_path());
  // Match '<purl>/group/node/<nid>/admin/owner' path.
  $transfer_path = ['group', 'node', 'admin', 'owner'];

  // Check (via the path) if we just transferred the group ownership.
  // If so, we don't send notifications to the admin who "lost" his admin role:
  // He will now be the new group owner.
  if (count(array_intersect($path, $transfer_path)) == count($transfer_path)) {
    return;
  }

  // Send MT36 - Inform user he is no longer group administrator.
  _c4m_user_notifications_notify_og_role_revoke($gid, $uid);
}

/**
 * Dispatch email notification for new nodes in published groups.
 *
 * @param object $node
 *   Drupal node entity object.
 */
function _c4m_user_notifications_node_insert($node) {
  if (_c4m_user_notifications_is_cli()) {
    return;
  }

  if (_c4m_user_notifications_is_node_author_anonymous($node)) {
    return;
  }

  if (_c4m_user_notifications_is_node_unpublished($node)) {
    return;
  }

  if (_c4m_user_notifications_has_skip_notification($node)) {
    return;
  }

  _c4m_user_notifications_dispatch_new_group_request($node);
  _c4m_user_notifications_dispatch_content_action($node, 'insert');
}

/**
 * Dispatch email notifications when organic group is inserted.
 *
 * Notifies group requester and site administrators about the newly requested
 * group that is waiting for a review.
 *
 * @param object $node
 *   Drupal node entity object.
 *
 * @Send MT10 - Simple notification
 * @Send MT49 - Simple notification
 */
function _c4m_user_notifications_dispatch_new_group_request($node) {
  // Return early if node is not group.
  if (!og_is_group('node', $node)) {
    return;
  }

  // Send MT49 - Notify the GO that his group needs review by a Site Admin.
  _c4m_user_notifications_notify_user_og_group_status_requested($node);
  // Send MT10 - Inform Site Administrators a new group was requested they need
  // to review and accept or reject.
  _c4m_user_notifications_notify_og_group_status_requested($node);
}

/**
 * Dispatch different email notifications when organic group content is touched.
 *
 * @param object $node
 *   Node entity object.
 * @param string $action
 *   Insert of update action string.
 *
 * @Send MT24 - Subscription notification
 * @Send MT25 - Subscription notification
 * @Send MT51 - Subscription notification
 * @Send MT53 - Subscription notification
 */
function _c4m_user_notifications_dispatch_content_action($node, $action) {
  $action_values = ['insert' => 'insert', 'update' => 'update'];

  // Check if the action string is valid.
  if (!array_key_exists($action, $action_values)) {
    return;
  }

  // Not all content types will trigger notifications.
  $allowed_og_content_types = c4m_og_get_group_content_notification_types();

  // For content shares from group A to group B we need a different template and
  // tokens.
  if ($node->type === 'share') {
    // Check if the source node type is a content type that triggers a
    // notification.
    if (!empty($node->source_bundle) && in_array($node->source_bundle, $allowed_og_content_types)) {
      $target_gid = $node->notification_data['target_gid'];
      $source_node = node_load($node->notification_data['source_nid']);

      // Send MT53 - Inform subscribed group followers about the new share.
      _c4m_user_notifications_dispatch_group_content_share($source_node, $target_gid);

      // No need to continue with the other checks. Shares only trigger one kind
      // of notifications.
      return;
    }
  }

  // 'Send Notification' checkbox on content form was set, but not checked.
  if (_c4m_user_notifications_has_skip_notification($node)) {
    return;
  }
  // Load current node wrapper.
  $wrapper = entity_metadata_wrapper('node', $node);

  $allowed_global_content_types = c4m_og_get_extended_content_notification_types();

  if (!in_array($node->type, $allowed_global_content_types)) {
    return;
  }

  // Global content logic.
  if ('insert' === $action || 'update' === $action && $node->original->status != NODE_PUBLISHED) {
    // Send MT24 - Subscribed topic followers are informed about new content
    // tagged with a common topic of interest.
    _c4m_user_notifications_notify_subscribe_content_of_interest($node);
  }

  if (!in_array($node->type, $allowed_og_content_types)) {
    // Send c4m_content_udpated for articles.
    _c4m_user_notifications_dispatch_content_update($node);
    return;
  }

  // Check if the node's group reference has a status field.
  if (!isset($wrapper->{OG_AUDIENCE_FIELD}->c4m_og_status)) {
    return;
  }

  // Check if the node's group reference's status is published so we don't
  // trigger notifications in draft/pending/... groups.
  if ($wrapper->{OG_AUDIENCE_FIELD}->c4m_og_status->value() !== 'published') {
    return;
  }
  if ('insert' === $action || $node->original->status != NODE_PUBLISHED) {
    // Send MT25 - Subscribed group followers are informed about new content in
    // the group.
    _c4m_user_notifications_notify_subscribe_group_content($node, 'insert');
  }
  elseif ($node->promote && !$node->original->promote) {
    // If content is highlighted, dispatch MT24.
    _c4m_user_notifications_notify_subscribe_content_of_interest($node, 'highlight');
  }
  else {
    // Send MT51 - Subscribed node followers are informed about updates
    // to the content.
    // Send MT25 - Subscribed group followers are informed about updated
    // content in the group (with exclusions to prevent duplicate
    // notification).
    // ------------------------------------------------------------------
    // Send MT25 - Subscribed group followers are informed about updated
    // content in the group.
    _c4m_user_notifications_dispatch_group_content_update($node);
  }
}

/**
 * Dispatch email notification when a node is updated.
 *
 * @param object $node
 *   Drupal node entity object.
 */
function _c4m_user_notifications_node_update($node) {
  if (_c4m_user_notifications_is_cli()) {
    return;
  }

  if (_c4m_user_notifications_is_node_author_anonymous($node)) {
    return;
  }

  if (_c4m_user_notifications_is_node_unpublished($node)) {
    return;
  }

  if (_c4m_user_notifications_has_skip_notification($node)) {
    return;
  }

  _c4m_user_notifications_dispatch_og_update($node);
  _c4m_user_notifications_dispatch_content_action($node, 'update');
}

/**
 * Dispatch different email notifications when a group (status) is updated.
 *
 * Inform owner and admins about:
 *   Status - group status changes (published/draft/etc...).
 *   Access - group access changes.
 *   Owner - group owner changes.
 */
function _c4m_user_notifications_dispatch_og_update($node) {
  if (!og_is_group('node', $node)) {
    // Return early, if node type is not group/project.
    return;
  }

  // On node update, there must be $node->original to compare data with.
  if (empty($node->original)) {
    return;
  }

  $wrapper = entity_metadata_wrapper('node', $node);
  $wrapper_original = entity_metadata_wrapper('node', $node->original);

  _c4m_user_notifications_dispatch_og_group_status_update($node, $wrapper, $wrapper_original);

  _c4m_user_notifications_dispatch_og_group_access_update($node, $wrapper, $wrapper_original);
}

/**
 * Dispatch notifications when the group access type changed.
 *
 * @param object $node
 *   Drupal node entity object.
 * @param object $wrapper
 *   Drupal entity metadata wrapper object of the new group node revision.
 * @param object $wrapper_original
 *   Drupal entity metadata wrapper object of the old group node revision.
 *
 * @Send MT34 - Simple notification
 */
function _c4m_user_notifications_dispatch_og_group_access_update($node, $wrapper, $wrapper_original) {
  if (!isset($wrapper->group_access) || !isset($wrapper_original->group_access)) {
    return;
  }

  try {
    $group_access = c4m_og_get_access_type($wrapper->value());
  }
  catch (EntityMetadataWrapperException $e) {
    watchdog('c4m_user_notifications', 'EntityMetadataWrapperException when getting group value', [], WATCHDOG_ERROR);
    return;
  }

  try {
    $group_former_access = c4m_og_get_access_type($wrapper_original->value());
  }
  catch (EntityMetadataWrapperException $e) {
    watchdog('c4m_user_notifications', 'EntityMetadataWrapperException when getting group value', [], WATCHDOG_ERROR);
    return;
  }

  $group_membership_request_type = _c4m_user_notifications_get_group_membership_request_type($wrapper);

  // Check if the group access type change.
  if ($group_access['type'] != $group_former_access['type']) {
    $permissions = _c4m_user_notifications_build_group_permissions($group_access, $group_membership_request_type);
    // Send MT34 - Inform group admins the access level changed.
    _c4m_user_notifications_notify_og_group_access_update($node, $permissions);
  }
  else {
    // Check if 'membership open' state was changed.
    $prev_membership_open = $wrapper_original->field_membership_open_request->value();

    if ($group_membership_request_type != $prev_membership_open) {
      $permissions = _c4m_user_notifications_build_group_permissions($group_access, $group_membership_request_type);
      // Send MT34 - Inform group admins the access level changed.
      _c4m_user_notifications_notify_og_group_access_update($node, $permissions);
    }
  }
}

/**
 * Dispatch notifications when the group (publication) status was changed.
 *
 * @param object $node
 *   Drupal node entity object.
 * @param object $wrapper
 *   Drupal entity metadata wrapper object of the new group node revision.
 * @param object $wrapper_original
 *   Drupal entity metadata wrapper object of the old group node revision.
 *
 * @Send MT12 - Simple notification
 * @Send MT24 - Subscription notification
 * @Send MT28 - Simple notification
 * @Send MT29 - Simple notification
 * @Send MT30 - Simple notification
 * @Send MT31 - Simple notification
 * @Send MT32 - Simple notification
 */
function _c4m_user_notifications_dispatch_og_group_status_update($node, $wrapper, $wrapper_original) {
  if (!isset($wrapper->c4m_og_status) || !isset($wrapper_original->c4m_og_status)) {
    return;
  }

  $group_status_new = $wrapper->c4m_og_status->value();
  $group_status_old = $wrapper_original->c4m_og_status->value();

  // Check if the group changed its publication status.
  if ($group_status_new !== $group_status_old) {
    switch ($group_status_new) {
      case 'published':
        // Publishing a group from unpublished status.
        if ($group_status_old === 'draft') {
          // Send MT28 - Inform group admins the group was published.
          _c4m_user_notifications_notify_og_group_status_published($node);

          // Send MT24 - Inform topic subscribers a new group is published.
          _c4m_user_notifications_notify_subscribe_content_of_interest($node);
        }
        // Republishing a group after it got archived in the past.
        elseif ($group_status_old === 'archived') {
          // Send MT31 - Inform group admins the group was published.
          _c4m_user_notifications_notify_og_group_status_republished($node, $group_status_old);
        }
        break;

      case 'draft':
        // Group is unpublished.
        if ($group_status_old === 'published') {
          // Send MT29 - Inform group admins the group was unpublished.
          _c4m_user_notifications_notify_og_group_status_unpublished($node, $group_status_old);
        }
        // Group is approved after requesting a new group.
        elseif ($group_status_old === 'pending' && empty($node->abort_group_approved_notification)) {
          // Send MT12 - Inform group owner the group was approved.
          _c4m_user_notifications_notify_og_group_status_approved($node->nid);
        }
        break;

      // Doesn't matter what the previous status was. Archiving group.
      case 'archived':
        // Send MT30 - Inform group admins the group was archived.
        _c4m_user_notifications_notify_og_group_status_archived($node, $group_status_old);
        break;

      // Doesn't matter what the previous status was. Doing a soft delete.
      case 'deleted':
        // Send MT32 - Inform group admins the group was soft-deleted.
        _c4m_user_notifications_notify_og_group_status_softdeleted($node, $group_status_old);
        break;
    }
  }
}

/**
 * Triggers email notifications for comment insert.
 *
 * @param object $comment
 *   Drupal comment entity object.
 *
 * @Send MT22 - Subscription notification
 * @Send MT26 - Subscription notification
 */
function _c4m_user_notifications_comment_insert($comment) {
  if (_c4m_user_notifications_is_cli()) {
    return;
  }

  if (_c4m_user_notifications_has_skip_notification($comment)) {
    return;
  }

  $node = node_load($comment->nid);

  if (_c4m_user_notifications_is_node_unpublished($node)) {
    return;
  }

  // Not all content types will trigger notifications.
  $comment_notification_types = c4m_og_get_extended_content_notification_types();
  if (!$node->type || !in_array($node->type, $comment_notification_types)) {
    return;
  }

  $wrapper = entity_metadata_wrapper('node', $node);

  // Do not notify if it's group content and it's group state is not published.
  if (!empty($wrapper->{OG_AUDIENCE_FIELD}) && $wrapper->{OG_AUDIENCE_FIELD}->c4m_og_status->value() != 'published') {
    return;
  }

  // Send MT26 - Users subscribed to comments on this node will receive a
  // notification when they are ALSO subscribed to the node and a new comment
  // is added.
  _c4m_user_notifications_notify_subscribe_commenter_new_comment($comment);

  // Send MT22 - Users subscribed to comments on this node will receive a
  // notification when they are NOT ALSO subscribed to the node and a new
  // comment is added. This notification complements MT26 above.
  _c4m_user_notifications_notify_subscribe_follower_new_comment($comment);
}

/**
 * Email notification about content being shared between groups.
 *
 * @param object $source_node
 *   Drupal node entity being shared.
 * @param int $target_gid
 *   Group Node ID being shared to.
 */
function _c4m_user_notifications_dispatch_group_content_share($source_node, $target_gid) {
  _c4m_user_notifications_notify_subscribe_group_content($source_node, 'share', $target_gid);
}

/**
 * Email notification about existing content update at organic group.
 *
 * @param object $node
 *   Drupal node entity being updated.
 */
function _c4m_user_notifications_dispatch_group_content_update($node) {
  if ($node->vid !== $node->original->vid) {
    // New revision of content was published => notify content editors, content
    // followers and  group followers.
    _c4m_user_notifications_notify_subscribe_content_revision($node, 'content_followers');
    _c4m_user_notifications_notify_subscribe_content_revision($node, 'content_editors');
    _c4m_user_notifications_notify_subscribe_content_revision($node, 'group_followers');
  }
  else {
    // No revision update => notify only group followers.
    _c4m_user_notifications_notify_subscribe_group_content($node, 'update');
  }
}

/**
 * Email notification about existing content update outside of an og.
 *
 * @param object $node
 *   Drupal node entity being updated.
 */
function _c4m_user_notifications_dispatch_content_update($node) {
  _c4m_user_notifications_notify_subscribe_content($node);
}
