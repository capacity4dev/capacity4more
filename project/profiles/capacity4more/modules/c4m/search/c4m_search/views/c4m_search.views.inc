<?php

/**
 * @file
 * Views hooks for the c4m_search module.
 */

/**
 * Implements hook_views_data_alter().
 */
function c4m_search_views_data_alter(&$data) {
  if (!isset($data['search_api_index'])) {
    return;
  }
  foreach (search_api_index_load_multiple(FALSE) as $index) {
    $key = 'search_api_index_' . $index->machine_name;

    // Provide a views bulk operations checkbox to search api index views.
    // See https://www.drupal.org/node/1123454#comment-9554163
    $data[$key]['views_bulk_operations'] = array(
      'title' => t('Bulk operations'),
      'help' => t('Provide a checkbox to select the row for bulk operations.'),
      'real field' => 'id',
      'field' => array(
        'handler' => 'c4m_search_vbo_handler_field_operations',
        'item_type' => $index->item_type,
        'click sortable' => FALSE,
      ),
    );

    $data[$key]['c4m_search'] = array(
      'title' => t('Keywords'),
      'group' => t('Search'),
      'help' => t('Display keywords searched for.'),
      'area' => array(
        'handler' => 'c4m_search_views_handler_area_display_keywords',
      ),
    );
  }
}
