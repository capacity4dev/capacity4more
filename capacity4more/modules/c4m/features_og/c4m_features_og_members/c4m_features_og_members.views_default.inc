<?php
/**
 * @file
 * c4m_features_og_members.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function c4m_features_og_members_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'c4m_overview_og_members';
  $view->description = 'List all members of a group';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_c4m_search_users';
  $view->human_name = 'Overview - OG - Members';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'c4m_og_access_og_context';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'c4m_user_teaser_list';
  /* Header: Add link to list */
  $handler->display->display_options['header']['c4m_views_switch_page_1']['id'] = 'c4m_views_switch_page_1';
  $handler->display->display_options['header']['c4m_views_switch_page_1']['table'] = 'views';
  $handler->display->display_options['header']['c4m_views_switch_page_1']['field'] = 'c4m_views_switch_page';
  $handler->display->display_options['header']['c4m_views_switch_page_1']['ui_name'] = 'Add link to list';
  $handler->display->display_options['header']['c4m_views_switch_page_1']['link_path'] = 'members';
  $handler->display->display_options['header']['c4m_views_switch_page_1']['link_text'] = 'List';
  $handler->display->display_options['header']['c4m_views_switch_page_1']['link_class'] = 'list';
  /* Header: Add link to table */
  $handler->display->display_options['header']['c4m_views_switch_page']['id'] = 'c4m_views_switch_page';
  $handler->display->display_options['header']['c4m_views_switch_page']['table'] = 'views';
  $handler->display->display_options['header']['c4m_views_switch_page']['field'] = 'c4m_views_switch_page';
  $handler->display->display_options['header']['c4m_views_switch_page']['ui_name'] = 'Add link to table';
  $handler->display->display_options['header']['c4m_views_switch_page']['empty'] = TRUE;
  $handler->display->display_options['header']['c4m_views_switch_page']['link_path'] = 'members/table';
  $handler->display->display_options['header']['c4m_views_switch_page']['link_text'] = 'Table';
  $handler->display->display_options['header']['c4m_views_switch_page']['link_class'] = 'table';
  /* Field: User: Rendered User */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_user';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'c4m_user_teaser_table';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Contextual filter: Indexed User: User ID */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'search_api_index_c4m_search_users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'c4m_features_og_members_plugin_argument_default';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['uid']['not'] = 0;
  /* Filter criterion: Search form */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_c4m_search_users';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['ui_name'] = 'Search form';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Fulltext search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'members';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Members';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'c4m-og-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'c4m_user_picture';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed User: User ID */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'search_api_index_c4m_search_users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_entity'] = 0;
  /* Field: Indexed User: Picture */
  $handler->display->display_options['fields']['c4m_media']['id'] = 'c4m_media';
  $handler->display->display_options['fields']['c4m_media']['table'] = 'search_api_index_c4m_search_users';
  $handler->display->display_options['fields']['c4m_media']['field'] = 'c4m_media';
  $handler->display->display_options['fields']['c4m_media']['label'] = '';
  $handler->display->display_options['fields']['c4m_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_media']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['c4m_media']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'members/table';
  $export['c4m_overview_og_members'] = $view;

  return $export;
}
