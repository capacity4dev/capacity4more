<?php

/**
 * @file
 * c4m_features_og_discussions.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function c4m_features_og_discussions_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'c4m_overview_og_discussions';
  $view->description = 'Search API powered overview of all discussions in the current group context.';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_c4m_search_nodes';
  $view->human_name = 'Overview - OG - Discussions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Discussions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'c4m_og_access_og_context';
  $handler->display->display_options['access']['feature'] = 'c4m_features_og_discussions';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['search_api_bypass_access'] = 0;
  $handler->display->display_options['query']['options']['entity_access'] = 0;
  $handler->display->display_options['query']['options']['parse_mode'] = 'direct';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '5';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 20, 50';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser_group';
  /* Header: Search: Spellcheck */
  $handler->display->display_options['header']['search_api_spellcheck']['id'] = 'search_api_spellcheck';
  $handler->display->display_options['header']['search_api_spellcheck']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['header']['search_api_spellcheck']['field'] = 'search_api_spellcheck';
  $handler->display->display_options['header']['search_api_spellcheck']['empty'] = TRUE;
  /* Header: Add Discussion link */
  $handler->display->display_options['header']['c4m_views_node_add']['id'] = 'c4m_views_node_add';
  $handler->display->display_options['header']['c4m_views_node_add']['table'] = 'views';
  $handler->display->display_options['header']['c4m_views_node_add']['field'] = 'c4m_views_node_add';
  $handler->display->display_options['header']['c4m_views_node_add']['ui_name'] = 'Add Discussion link';
  $handler->display->display_options['header']['c4m_views_node_add']['empty'] = TRUE;
  $handler->display->display_options['header']['c4m_views_node_add']['node_type'] = 'discussion';
  $handler->display->display_options['header']['c4m_views_node_add']['link_text'] = 'Add a new Discussion';
  $handler->display->display_options['header']['c4m_views_node_add']['icon'] = 'fa-pencil';
  /* Header: Sort results */
  $handler->display->display_options['header']['c4m_views_search_api_sorts']['id'] = 'c4m_views_search_api_sorts';
  $handler->display->display_options['header']['c4m_views_search_api_sorts']['table'] = 'views';
  $handler->display->display_options['header']['c4m_views_search_api_sorts']['field'] = 'c4m_views_search_api_sorts';
  $handler->display->display_options['header']['c4m_views_search_api_sorts']['ui_name'] = 'Sort results';
  $handler->display->display_options['header']['c4m_views_search_api_sorts']['empty'] = TRUE;
  /* Header: Number of items */
  $handler->display->display_options['header']['c4m_views_result']['id'] = 'c4m_views_result';
  $handler->display->display_options['header']['c4m_views_result']['table'] = 'views';
  $handler->display->display_options['header']['c4m_views_result']['field'] = 'c4m_views_result';
  $handler->display->display_options['header']['c4m_views_result']['ui_name'] = 'Number of items';
  $handler->display->display_options['header']['c4m_views_result']['empty'] = TRUE;
  $handler->display->display_options['header']['c4m_views_result']['content'] = '<span class="total-items">@total items</span>';
  /* Header: Items per page */
  $handler->display->display_options['header']['c4m_views_items_per_page']['id'] = 'c4m_views_items_per_page';
  $handler->display->display_options['header']['c4m_views_items_per_page']['table'] = 'views';
  $handler->display->display_options['header']['c4m_views_items_per_page']['field'] = 'c4m_views_items_per_page';
  $handler->display->display_options['header']['c4m_views_items_per_page']['ui_name'] = 'Items per page';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Contextual filter: Only nodes in current OG Context */
  $handler->display->display_options['arguments']['og_group_ref']['id'] = 'og_group_ref';
  $handler->display->display_options['arguments']['og_group_ref']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['arguments']['og_group_ref']['field'] = 'og_group_ref';
  $handler->display->display_options['arguments']['og_group_ref']['ui_name'] = 'Only nodes in current OG Context';
  $handler->display->display_options['arguments']['og_group_ref']['default_action'] = 'default';
  $handler->display->display_options['arguments']['og_group_ref']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['og_group_ref']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['og_group_ref']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['og_group_ref']['not'] = 0;
  /* Filter criterion: Node is published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['ui_name'] = 'Node is published';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Only Discussion nodes */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['ui_name'] = 'Only Discussion nodes';
  $handler->display->display_options['filters']['type']['value'] = array(
    'discussion' => 'discussion',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Search form */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['ui_name'] = 'Search form';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'text';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'discussions';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Discussions';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['name'] = 'c4m-og-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['c4m_overview_og_discussions'] = $view;

  return $export;
}
