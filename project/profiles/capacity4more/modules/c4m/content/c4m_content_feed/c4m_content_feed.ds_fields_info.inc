<?php

/**
 * @file
 * Display Suite extras fields.
 */

/**
 * Implements hook_ds_fields_info().
 */
function c4m_content_feed_ds_fields_info($entity_type) {
  $path = drupal_get_path('module', 'c4m_content_feed');

  $fields = array();
  $fields['node']['c4m_content_feed_url'] = array(
    'title'      => t('Feed URL'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'ui_limit'   => array('feed|*'),
    'file'       => $path . '/includes/c4m_content_feed.ds_fields.inc',
    'function'   => 'c4m_content_feed_url',
    'properties' => array(
      'formatters' => array(
        'default' => t('Default'),
      ),
    ),
  );
  return $fields;
}
