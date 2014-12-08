<?php
/**
 * @file
 * All code to generate wiki (master) pages for all new group types.
 */

/**
 * Create top-level book for wikis.
 */
function c4m_content_wiki_create_root_wiki($node) {
  if (!og_is_group_type('node', $node->type)) {
    return FALSE;
  }

  // The user who created the group will also be the author of the master page.
  $user = user_load($node->uid);

  // Node data.
  $wiki         = new stdClass();
  $wiki->type   = "wiki";
  $wiki->status = 1;
  $wiki->uid    = $user->uid;
  $wiki->name   = $user->name;

  $wiki->language = LANGUAGE_NONE;

  $wiki_type = c4m_og_get_group_type_name($node);

  $wiki->title = $node->title . ' ' . $wiki_type . " page";

  $wiki->book = array(
    'pick-book'          => 'Change book (update list of parents)',
    'bid'                => 'new',
    'has_children'       => 0,
    'options'            => array(),
    'module'             => 'book',
    'original_bid'       => 0,
    'parent_depth_limit' => 8,
    'weight'             => '0',
  );

  $wiki->created = $node->created;
  $wiki->changed = $node->changed;
  $wiki->revision = FALSE;

  if ($wiki = node_submit($wiki)) {
    node_save($wiki);
  }

  // Attach the new node to the group.
  $values = array(
    'entity_type' => 'node',
    'entity'      => $wiki,
    'state'       => OG_STATE_ACTIVE,
  );

  og_group('node', $node->nid, $values);

  db_update('node')->fields(array('created' => $node->changed))
    ->condition('nid', $wiki->nid, '=')
    ->execute();
  db_update('node')->fields(array('changed' => $node->changed))
    ->condition('nid', $wiki->nid, '=')
    ->execute();
  db_update('node_revision')->fields(array('timestamp' => $node->changed))
    ->condition('nid', $wiki->nid, '=')
    ->condition('vid', $wiki->vid, '=')
    ->execute();

  return $wiki;
}
