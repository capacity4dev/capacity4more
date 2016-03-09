<?php

/**
 * @file
 * Sample hooks demonstrating usage in Mefibs.
 */

/**
 * @defgroup mefibs_hooks Mefibs Module Hooks
 * @{
 * Mefibs's hooks enable other modules to intercept events within Mefibs, such
 * as the assembling the filters that will be fed into a view, or assembling
 * the form elements that should go into the additional filter block.
 */

/**
 * Add additional elements to the accitional exposed form.
 *
 * @param array $elements
 *   An array with names of form element that should be rendered in the
 *   additional filter block.
 * @param array $context
 *   An array with addional context information. Supported keys:
 *   'view': The full views object for the view to be rendered.
 *   'display_id': The id of the current display.
 *   'block_id': The id of the current block.
 *   'type': The context type, either 'hide_items' or 'expected_items'.
 *
 * @see mefibs_get_expected_items_for_additional_form()
 */
function hook_mefibs_elements_alter(&$elements, $context) {
  if (in_array('sort_by', $elements['sort'])) {
    $elements['sort'][] = 'sort_bef_combine';
  }
}

/**
 * Alter the filter values that will be passed to the view object.
 *
 * @param array $filters
 *   An array of filters as key-value pairs (coming from incoming GET or POST
 *   request) that should be passed on to the view.
 */
function hook_mefibs_filter_alter(&$filters) {
  // This is a dumb example that would effectively break the selection of items
  // per page. Only for illustration purposes.
  $filters['item_per_page'] = 10;
}
