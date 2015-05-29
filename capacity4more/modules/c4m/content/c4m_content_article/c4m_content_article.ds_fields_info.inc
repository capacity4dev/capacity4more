<?php

/**
 * @file
 * Display Suite extras fields.
 */

/**
 * Implements hook_ds_fields_info().
 */
function c4m_content_article_ds_fields_info($entity_type) {
  $path = drupal_get_path('module', 'c4m_content_article');

  $fields = array();

  $fields['node']['c4m_content_article_disclaimer'] = array(
    'title'      => t('Article Disclaimer'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'ui_limit'   => array('article|*'),
    'file'       => $path . '/includes/c4m_content_article.ds_fields.inc',
    'function'   => 'c4m_content_article_disclaimer',
    'properties' => array(
      'formatters' => array(
        'default' => t('Default'),
      ),
    ),
  );

  return $fields;
}
