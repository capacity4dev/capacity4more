<?php

/**
 * @file
 * c4m_features_og_documents.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function c4m_features_og_documents_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'c4m_overview_og_documents';
  $view->description = 'Search API powered overview of all documents and photo albums in the current group context.';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_c4m_search_nodes';
  $view->human_name = 'Overview - OG - Documents';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Library';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'c4m_og_access_og_context';
  $handler->display->display_options['access']['feature'] = 'c4m_features_og_documents';
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
  $handler->display->display_options['pager']['options']['tags']['first'] = '«';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹';
  $handler->display->display_options['pager']['options']['tags']['next'] = '›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '»';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser_group';
  /* Header: Search: Spellcheck */
  $handler->display->display_options['header']['search_api_spellcheck']['id'] = 'search_api_spellcheck';
  $handler->display->display_options['header']['search_api_spellcheck']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['header']['search_api_spellcheck']['field'] = 'search_api_spellcheck';
  $handler->display->display_options['header']['search_api_spellcheck']['empty'] = TRUE;
  /* Header: Add document link */
  $handler->display->display_options['header']['c4m_views_node_add_1']['id'] = 'c4m_views_node_add_1';
  $handler->display->display_options['header']['c4m_views_node_add_1']['table'] = 'views';
  $handler->display->display_options['header']['c4m_views_node_add_1']['field'] = 'c4m_views_node_add';
  $handler->display->display_options['header']['c4m_views_node_add_1']['ui_name'] = 'Add document link';
  $handler->display->display_options['header']['c4m_views_node_add_1']['node_type'] = 'document';
  $handler->display->display_options['header']['c4m_views_node_add_1']['link_text'] = 'Upload a document';
  $handler->display->display_options['header']['c4m_views_node_add_1']['icon'] = 'fa-file-text';
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
  $handler->display->display_options['arguments']['og_group_ref']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['og_group_ref']['validate']['type'] = 'numeric';
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
  /* Filter criterion: Only Document nodes */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['ui_name'] = 'Only Document nodes';
  $handler->display->display_options['filters']['type']['value'] = array(
    'document' => 'document',
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
  /* Filter criterion: Indexed Node: Add to library */
  $handler->display->display_options['filters']['c4m_document_add_to_library']['id'] = 'c4m_document_add_to_library';
  $handler->display->display_options['filters']['c4m_document_add_to_library']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['filters']['c4m_document_add_to_library']['field'] = 'c4m_document_add_to_library';
  $handler->display->display_options['filters']['c4m_document_add_to_library']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['c4m_document_add_to_library']['expose']['operator_id'] = 'c4m_document_add_to_library_op';
  $handler->display->display_options['filters']['c4m_document_add_to_library']['expose']['label'] = 'Add to library';
  $handler->display->display_options['filters']['c4m_document_add_to_library']['expose']['operator'] = 'c4m_document_add_to_library_op';
  $handler->display->display_options['filters']['c4m_document_add_to_library']['expose']['identifier'] = 'c4m_document_add_to_library';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'documents';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Library';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['name'] = 'c4m-og-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page 2 */
  $handler = $view->new_display('page', 'Page 2', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'library';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Search: Spellcheck */
  $handler->display->display_options['header']['search_api_spellcheck']['id'] = 'search_api_spellcheck';
  $handler->display->display_options['header']['search_api_spellcheck']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['header']['search_api_spellcheck']['field'] = 'search_api_spellcheck';
  $handler->display->display_options['header']['search_api_spellcheck']['empty'] = TRUE;
  /* Header: Sort results */
  $handler->display->display_options['header']['c4m_views_search_api_sorts']['id'] = 'c4m_views_search_api_sorts';
  $handler->display->display_options['header']['c4m_views_search_api_sorts']['table'] = 'views';
  $handler->display->display_options['header']['c4m_views_search_api_sorts']['field'] = 'c4m_views_search_api_sorts';
  $handler->display->display_options['header']['c4m_views_search_api_sorts']['ui_name'] = 'Sort results';
  $handler->display->display_options['header']['c4m_views_search_api_sorts']['empty'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Header: Number of items */
  $handler->display->display_options['header']['c4m_views_result']['id'] = 'c4m_views_result';
  $handler->display->display_options['header']['c4m_views_result']['table'] = 'views';
  $handler->display->display_options['header']['c4m_views_result']['field'] = 'c4m_views_result';
  $handler->display->display_options['header']['c4m_views_result']['ui_name'] = 'Number of items';
  $handler->display->display_options['header']['c4m_views_result']['empty'] = TRUE;
  $handler->display->display_options['header']['c4m_views_result']['content'] = '<span class="total-items">@total items</span>';
  /* Filter criterion: Node is published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['ui_name'] = 'Node is published';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Only Document nodes */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['ui_name'] = 'Only Document nodes';
  $handler->display->display_options['filters']['type']['value'] = array(
    'document' => 'document',
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
  /* Filter criterion: Indexed Node: Add to library */
  $handler->display->display_options['filters']['c4m_document_add_to_library']['id'] = 'c4m_document_add_to_library';
  $handler->display->display_options['filters']['c4m_document_add_to_library']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['filters']['c4m_document_add_to_library']['field'] = 'c4m_document_add_to_library';
  $handler->display->display_options['filters']['c4m_document_add_to_library']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'overlay/documents';
  $export['c4m_overview_og_documents'] = $view;

  return $export;
}
