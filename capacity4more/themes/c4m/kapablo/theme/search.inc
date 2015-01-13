<?php
/**
 * @file
 * Theme functions related to the search functionality.
 */

/**
 * Theme a list of sort options.
 *
 * @param array $variables
 *   An associative array containing:
 *   - items: The sort options
 *   - options: Various options to pass
 */
function kapablo_search_api_sorts_list(array $variables) {
  $items_array = $variables['items'];

  if (!module_exists('c4m_search')) {
    $items   = array_map('render', $items_array);
    $options = $variables['options'];

    return $items ? theme('item_list', array('items' => $items) + $options) : '';
  }

  $active_item = NULL;

  foreach ($items_array as $key => $item) {
    if ($item['#active'] === TRUE &&
        isset($items_array[$key]['#order_options'])) {
      $active_item = $item;

      // Remove default class, we need the opposite
      array_pop($items_array[$key]['#order_options']['attributes']['class']);
      $items_array[$key]['#order_options']['attributes']['class'][] = 'sort-' . $item['#order_options']['query']['order'];
      $items_array[$key]['#order_options']['attributes']['title']   = t('Sort by @name (@order)', array(
        '@name'  => $item['#name'],
        '@order' => $item['#order_options']['query']['order'] == 'asc' ? t('Ascending') : t('Descending')
      ));
    }
    else {
      $items_array[$key]['#options']['attributes']['class'][] = 'sort-' . $item['#options']['query']['order'];
      $items_array[$key]['#options']['attributes']['title']   = t('Sort by @name (@order)', array(
        '@name'  => $item['#name'],
        '@order' => $item['#options']['query']['order'] == 'asc' ? t('Ascending') : t('Descending')
      ));
    }
  }

  $items = array_map('render', $items_array);

  $options = $variables['options'];

  $options['attributes']['class'][] = 'dropdown-menu';

  return $items ? theme('c4m_search_dropdown_sort_filters', array(
    'list'   => theme('item_list', array('items' => $items) + $options),
    'active' => $active_item
  )) : '';
}