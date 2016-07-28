<?php

/**
 * @file
 * c4m_features_learning_space.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function c4m_features_learning_space_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'the_learning_space';
  $path_breadcrumb->name = 'The Learning Space';
  $path_breadcrumb->path = 'node/%nodeidnumber';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%nodeidnumber:title',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(
      'nodeidnumber' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        1 => array(
          'name' => 'og_is_node_group_content',
          'settings' => NULL,
          'context' => 'nodeidnumber',
          'not' => TRUE,
        ),
        2 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'book' => 'book',
            ),
          ),
          'context' => 'nodeidnumber',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -93;
  $export['the_learning_space'] = $path_breadcrumb;

  return $export;
}
