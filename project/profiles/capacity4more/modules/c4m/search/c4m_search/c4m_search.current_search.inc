<?php

/**
 * @file
 * Current Search default hooks.
 */

/**
 * Implements hook_current_search_default_items().
 */
function c4m_search_current_search_default_items() {
  $items = [];

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->name = 'c4m_current_search_nodes';
  $item->label = 'Standard nodes';
  $item->settings = [
    'items' => [
      'active_links' => [
        'id' => 'active_links',
        'label' => 'Active links',
        'pattern' => '[facetapi_active:active-value]',
        'keys' => 1,
        'keys_whole' => 1,
        'hide_facets' => 0,
        'css' => 1,
        'classes' => 'list-unstyled,list-inline',
        'nofollow' => 1,
        'arguments' => '',
        'search_param' => 'text',
        'weight' => '0',
      ],
      'clear_all' => [
        'id' => 'clear_all_filters',
        'label' => 'Clear all',
        'text' => 'Clear all',
        'plural' => 0,
        'text_plural' => '',
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 0,
        'element' => '0',
        'css' => 0,
        'classes' => '',
        'weight' => '0',
      ],
    ],
    'advanced' => [
      'empty_searches' => '3',
    ],
    'searcher' => 'search_api@c4m_search_nodes',
  ];
  $items[$item->name] = $item;

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->name = 'c4m_current_search_comments';
  $item->label = 'Standard comments';
  $item->settings = [
    'items' => [
      'active_links' => [
        'id' => 'active_links',
        'label' => 'Active links',
        'pattern' => '[facetapi_active:active-value]',
        'keys' => 1,
        'keys_whole' => 1,
        'hide_facets' => 0,
        'css' => 1,
        'classes' => 'list-unstyled,list-inline',
        'nofollow' => 1,
        'arguments' => '',
        'search_param' => 'text',
        'weight' => '0',
      ],
      'clear_all' => [
        'id' => 'clear_all_filters',
        'label' => 'Clear all',
        'text' => 'Clear all',
        'plural' => 0,
        'text_plural' => '',
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 0,
        'element' => '0',
        'css' => 0,
        'classes' => '',
        'weight' => '0',
      ],
    ],
    'advanced' => [
      'empty_searches' => '3',
    ],
    'searcher' => 'search_api@c4m_search_comments',
  ];
  $items[$item->name] = $item;

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->name = 'c4m_current_search_users';
  $item->label = 'Standard users';
  $item->settings = [
    'items' => [
      'active_links' => [
        'id' => 'active_links',
        'label' => 'Active links',
        'pattern' => '[facetapi_active:active-value]',
        'keys' => 1,
        'keys_whole' => 1,
        'hide_facets' => 0,
        'css' => 1,
        'classes' => 'list-unstyled,list-inline',
        'nofollow' => 1,
        'arguments' => '',
        'search_param' => 'text',
        'weight' => '0',
      ],
      'clear_all' => [
        'id' => 'clear_all_filters',
        'label' => 'Clear all',
        'text' => 'Clear all',
        'plural' => 0,
        'text_plural' => '',
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 0,
        'element' => '0',
        'css' => 0,
        'classes' => '',
        'weight' => '0',
      ],
    ],
    'advanced' => [
      'empty_searches' => '3',
    ],
    'searcher' => 'search_api@c4m_search_users',
  ];
  $items[$item->name] = $item;

  return $items;
}
