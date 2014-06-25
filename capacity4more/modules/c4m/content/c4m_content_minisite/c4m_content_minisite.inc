<?php
/**
 * @file
 * All code to generate minisite (master) pages for all new group types.
 */

/**
 * Create top-level book for minisites.
 */
function c4m_content_minisite_create_root_minisite($node) {
  if (!og_is_group_type('node', $node->type)) {
    return FALSE;
  }

  // The user who created the group will also be the author of the master page.
  $user = user_load($node->uid);

  // Node data.
  $minisite         = new stdClass();
  $minisite->type   = "minisite";
  $minisite->status = 1;
  $minisite->uid    = $user->uid;
  $minisite->name   = $user->name;

  $minisite->language = LANGUAGE_NONE;

  $minisite_type = c4m_og_get_group_type_name($node);

  $minisite->title = $node->title . ' ' . $minisite_type . " page";

  $minisite->book = array(
    'pick-book'          => 'Change book (update list of parents)',
    'bid'                => 'new',
    'has_children'       => 0,
    'options'            => array(),
    'module'             => 'book',
    'original_bid'       => 0,
    'parent_depth_limit' => 8,
    'weight'             => '0',
  );

  if ($minisite = node_submit($minisite)) {
    node_save($minisite);
  }

  db_update('node')->fields(array('changed' => $node->changed))
  ->condition('nid', $minisite->nid, '=')
  ->execute();
  db_update('node_revision')->fields(array('timestamp' => $node->changed))
  ->condition('nid', $minisite->nid, '=')
  ->condition('vid', $minisite->vid, '=')
  ->execute();

  // Attach the new node to the group.
  $values = array(
    'entity_type' => 'node',
    'entity'      => $minisite,
    'state'       => OG_STATE_ACTIVE,
  );

  og_group('node', $node->nid, $values);

  return $minisite;
}
