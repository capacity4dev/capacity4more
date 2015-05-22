<?php
/**
 * @file
 * Hooks provided by the capacity4more Search module.
 */

/**
 * @addtogroup hooks
 * @{
 */


/**
 * Define the available search pages.
 *
 * You need to implement the hook_c4m_search_page_info() hook to define
 * what search pages should be made available.
 *
 * @return array
 *   An array of pages and their settings. The keys are used to identify
 *   the available search pages.
 *   Each search page has the following data:
 *   - name : The name of the search page.
 *   - description : The description of the search page.
 *   - machine_name : The machine name of the search page.
 *   - path : The path of the search page.
 *   - weight : The weight used to sort the search page in dropdown.
 *   - default : The default search page in dropdown.
 *   - access : Optional access callback to show search page in dropdown.
 *   - purl : Indicates if the path should be rendered inside a group.
 *   - group : Optional group that the search page belongs to.
 */
function hook_c4m_search_page_info() {
  return array(
    'c4m_search_nodes' => array(
      'name' => t('Search Site'),
      'description' => t('Search in all the site content.'),
      'machine_name' => 'c4m_search_nodes',
      'path' => 'search',
      'weight' => 0,
      'default' => TRUE,
      'access' => NULL,
      'purl' => FALSE,
      'group' => t('Search in all site content'),
    ),
  );
}


/**
 * @} End of "addtogroup hooks".
 */
