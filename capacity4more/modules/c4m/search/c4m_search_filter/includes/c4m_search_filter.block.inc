<?php
/**
 * @file
 * All blocks for the c4m_search_filter module.
 */

/**
 * A block with filters for search views.
 *
 * Displays both groups & interests filter.
 *
 * @return array
 *   Either an empty array or an array containing the search filter form.
 */
function _c4m_search_filter_block_search_filter() {
  // Get the filter form.
  module_load_include('inc', 'c4m_search_filter', 'includes/c4m_search_filter.form');
  $form = drupal_get_form('c4m_search_filter_search_filter_form');

  return array(
    'subject' => NULL,
    'content' => $form,
  );
}

/**
 * A block with filters for search views.
 *
 * Displays the groups filter only.
 *
 * @return array
 *   Either an empty array or an array containing the search filter form.
 */
function _c4m_search_filter_block_search_filter_groups() {
  // Get the filter form.
  module_load_include('inc', 'c4m_search_filter', 'includes/c4m_search_filter.form');
  $form = drupal_get_form('c4m_search_filter_search_filter_form', 'groups');

  return array(
    'subject' => NULL,
    'content' => $form,
  );
}

/**
 * A block with filters for search views.
 *
 * Displays the interests filter only.
 *
 * @return array
 *   Either an empty array or an array containing the search filter form.
 */
function _c4m_search_filter_block_search_filter_interests() {
  // Get the filter form.
  module_load_include('inc', 'c4m_search_filter', 'includes/c4m_search_filter.form');
  $form = drupal_get_form('c4m_search_filter_search_filter_form', 'interests');

  return array(
    'subject' => NULL,
    'content' => $form,
  );
}
