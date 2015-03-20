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
 *   - items: The sort options.
 *   - options: Various options to pass.
 *
 * @return string
 *   The themed sort list.
 */
function kapablo_search_api_sorts_list(array $variables) {
  $items_array = $variables['items'];

  if (!module_exists('c4m_search')) {
    $items   = array_map('render', $items_array);
    $options = $variables['options'];

    return $items
      ? theme('item_list', array('items' => $items) + $options)
      : '';
  }

  $active_item = NULL;
  foreach ($items_array as $key => $item) {
    if ($item['#active'] === TRUE &&
        isset($items_array[$key]['#order_options'])
    ) {
      $options_key = '#order_options';
      $active_item = $item;

      // Remove default class, we need the opposite.
      array_pop($items_array[$key][$options_key]['attributes']['class']);
    }
    else {
      $options_key = '#options';
    }

    // Get the order.
    $order = $item[$options_key]['query']['order'];
    $order_human = ($order == 'asc')
      ? t('Ascending')
      : t('Descending');

    $items_array[$key][$options_key]['attributes']['class'][] = 'sort-' . $order;
    $items_array[$key][$options_key]['attributes']['title'] = t(
      'Sort by @name (@order)',
      array(
        '@name'  => $item['#name'],
        '@order' => $order_human,
      )
    );
  }

  $items = array_map('render', $items_array);

  $options = $variables['options'];
  $options['attributes']['class'][] = 'dropdown-menu';

  $output = '';
  if ($items) {
    $output = theme(
      'c4m_search_dropdown_sort_filters',
      array(
        'list'   => theme('item_list', array('items' => $items) + $options),
        'active' => $active_item,
      )
    );
  }

  return $output;
}
