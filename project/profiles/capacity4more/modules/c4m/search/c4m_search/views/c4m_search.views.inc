<?php
/**
 * @file
 * c4m_search Views hooks.
 */

/**
 * Implements hook_views_data_alter().
 *
 * search_api_views already exposes each index as a data sources. This hook
 * gives us the oppotunity to refine the data specification by asking each
 * index's server if it supports search_api_spellcheck. For those that do we
 * attach a new area handler to display spelling suggestions.
 *
 * Because the field extends views_handler_area it can optionally be added to
 * views Headers and Footers.
 * It only displays if spelling suggestions are returned.
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

