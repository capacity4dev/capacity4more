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
    $items = array_map('render', $items_array);
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
        '@name' => $item['#name'],
        '@order' => $order_human,
      )
    );
  }

  $items = array_map('render', $items_array);

  $options = $variables['options'];
  $options['attributes']['class'][] = 'dropdown-menu';
  $options['hide_wrapper'] = TRUE;

  $output = '';
  if ($items) {
    // Current order is the reverse of the active item link order.
    $order = $active_item['#order_options']['query']['order'] == 'asc' ? 'desc' : 'asc';
    $output = theme(
      'c4m_search_dropdown_sort_filters',
      array(
        'list' => theme('item_list', array('items' => $items) + $options),
        'active' => $active_item,
        'order' => $order,
      )
    );
  }

  return $output;
}

/**
 * Implements theme_facetapi_deactivate_widget().
 */
function kapablo_facetapi_deactivate_widget($variables) {
  return '<span class="facetapi-deactivate"></span>';
}

/**
 * Implements theme_facetapi_link_active__current_search_links().
 *
 * @see kapablo_facetapi_link_active()
 */
function kapablo_facetapi_link_active__current_search_links($variables) {
  // Sanitizes the link text if necessary.
  $sanitize = empty($variables['options']['html']);
  $link_text = ($sanitize) ? check_plain(
    $variables['text']
  ) : $variables['text'];

  // Theme function variables for accessible markup.
  // @see http://drupal.org/node/1316580
  $accessible_vars = array(
    'text' => $variables['text'],
    'active' => TRUE,
  );

  // Builds link, passes through t() which gives us the ability to change the
  // position of the widget on a per-language basis.
  $replacements = array(
    '!facetapi_deactivate_widget' => '<i class="fa fa-times" title="Remove"></i>',
    '!facetapi_accessible_markup' => theme(
      'facetapi_accessible_markup',
      $accessible_vars
    ),
  );
  $variables['text'] = t(
      '!facetapi_deactivate_widget !facetapi_accessible_markup',
      $replacements
    ) . $link_text;
  $variables['options']['html'] = TRUE;
  return theme_link($variables);
}

/**
 * Implements theme_facetapi_link_active().
 */
function kapablo_facetapi_link_active($variables) {

  // Sanitizes the link text if necessary.
  $sanitize = empty($variables['options']['html']);
  $link_text = ($sanitize) ? check_plain(
    $variables['text']
  ) : $variables['text'];

  // Theme function variables fro accessible markup.
  // @see http://drupal.org/node/1316580
  $accessible_vars = array(
    'text' => $variables['text'],
    'active' => TRUE,
  );

  // Builds link, passes through t() which gives us the ability to change the
  // position of the widget on a per-language basis.
  $replacements = array(
    '!facetapi_deactivate_widget' => theme(
      'facetapi_deactivate_widget',
      $variables
    ),
    '!facetapi_accessible_markup' => theme(
      'facetapi_accessible_markup',
      $accessible_vars
    ),
  );
  $variables['text'] = $link_text . t(
      '!facetapi_deactivate_widget !facetapi_accessible_markup',
      $replacements
    );
  $variables['options']['html'] = TRUE;
  return theme_link($variables);
}

/**
 * Theme a single sort item.
 *
 * @param array $variables
 *   An associative array containing:
 *   - name: The name to display for the item.
 *   - path: The destination path when the sort link is clicked.
 *   - options: An array of options to pass to l().
 *   - active: A boolean telling whether this sort filter is active or not.
 *   - order_options: If active, a set of options to reverse the order.
 *
 * @return string
 *   Sort options in HTML format.
 */
function kapablo_search_api_sorts_sort(array $variables) {
  $name = $variables['name'];
  $path = $variables['path'];
  $options = $variables['options'] + array('attributes' => array());
  $options['attributes'] += array('class' => array());

  $order_options = $variables['order_options'] + array(
    'query' => array(),
    'attributes' => array(),
    'html' => TRUE,
  );
  $order_options['attributes'] += array('class' => array());

  if ($variables['active']) {
    $return_html = l(
      $name . theme(
        'tablesort_indicator',
        array(
          'style' =>
          ($order_options['query']['order'] == 'asc') ? 'desc' : 'asc',
        )
      ),
      $path,
      $order_options
    );
  }
  else {
    $return_html = l($name, $path, $options);
  }

  return $return_html;
}

/**
 * Implements theme_facetapi_count().
 */
function kapablo_facetapi_count($variables) {
  return '(' . c4m_content_ec_number_format((int) $variables['count']) . ')';
}
