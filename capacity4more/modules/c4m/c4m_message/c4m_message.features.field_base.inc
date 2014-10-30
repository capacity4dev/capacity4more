<?php
/**
 * @file
 * c4m_message.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function c4m_message_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_comment'
  $field_bases['field_comment'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_comment',
    'foreign keys' => array(
      'comment' => array(
        'columns' => array(
          'target_id' => 'cid',
        ),
        'table' => 'comment',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'comment_node_article' => 'comment_node_article',
          'comment_node_blog' => 'comment_node_blog',
          'comment_node_book' => 'comment_node_book',
          'comment_node_document' => 'comment_node_document',
          'comment_node_event' => 'comment_node_event',
          'comment_node_group' => 'comment_node_group',
          'comment_node_minisite' => 'comment_node_minisite',
          'comment_node_page' => 'comment_node_page',
          'comment_node_photo' => 'comment_node_photo',
          'comment_node_photoalbum' => 'comment_node_photoalbum',
          'comment_node_project' => 'comment_node_project',
          'comment_node_region' => 'comment_node_region',
          'comment_node_task' => 'comment_node_task',
          'comment_node_tasklist' => 'comment_node_tasklist',
          'comment_node_topic' => 'comment_node_topic',
        ),
      ),
      'target_type' => 'comment',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_group'
  $field_bases['field_group'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_group',
    'foreign keys' => array(
      'node' => array(
        'columns' => array(
          'target_id' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'group' => 'group',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_node'
  $field_bases['field_node'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_node',
    'foreign keys' => array(
      'node' => array(
        'columns' => array(
          'target_id' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'article' => 'article',
          'blog' => 'blog',
          'book' => 'book',
          'document' => 'document',
          'event' => 'event',
          'group' => 'group',
          'minisite' => 'minisite',
          'page' => 'page',
          'photo' => 'photo',
          'photoalbum' => 'photoalbum',
          'project' => 'project',
          'region' => 'region',
          'task' => 'task',
          'tasklist' => 'tasklist',
          'topic' => 'topic',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}
