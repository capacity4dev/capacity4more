<?php
/**
 * @file
 * c4m_features_overview_people.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function c4m_features_overview_people_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'c4m_overview_people';
  $view->description = 'List all members of a group';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_c4m_search_users';
  $view->human_name = 'Overview - People';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'People';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'c4m_user_teaser_list_global';
  /* Header: Sorts */
  $handler->display->display_options['header']['c4m_views_search_api_sorts']['id'] = 'c4m_views_search_api_sorts';
  $handler->display->display_options['header']['c4m_views_search_api_sorts']['table'] = 'views';
  $handler->display->display_options['header']['c4m_views_search_api_sorts']['field'] = 'c4m_views_search_api_sorts';
  $handler->display->display_options['header']['c4m_views_search_api_sorts']['ui_name'] = 'Sorts';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '@total items';
  /* Header: Add link to list */
  $handler->display->display_options['header']['c4m_views_switch_page_1']['id'] = 'c4m_views_switch_page_1';
  $handler->display->display_options['header']['c4m_views_switch_page_1']['table'] = 'views';
  $handler->display->display_options['header']['c4m_views_switch_page_1']['field'] = 'c4m_views_switch_page';
  $handler->display->display_options['header']['c4m_views_switch_page_1']['ui_name'] = 'Add link to list';
  $handler->display->display_options['header']['c4m_views_switch_page_1']['link_path'] = 'people';
  $handler->display->display_options['header']['c4m_views_switch_page_1']['link_text'] = 'List view';
  $handler->display->display_options['header']['c4m_views_switch_page_1']['link_class'] = 'list-teaser-view';
  $handler->display->display_options['header']['c4m_views_switch_page_1']['link_icon'] = 'fa-list';
  /* Header: Add link to table */
  $handler->display->display_options['header']['c4m_views_switch_page']['id'] = 'c4m_views_switch_page';
  $handler->display->display_options['header']['c4m_views_switch_page']['table'] = 'views';
  $handler->display->display_options['header']['c4m_views_switch_page']['field'] = 'c4m_views_switch_page';
  $handler->display->display_options['header']['c4m_views_switch_page']['ui_name'] = 'Add link to table';
  $handler->display->display_options['header']['c4m_views_switch_page']['empty'] = TRUE;
  $handler->display->display_options['header']['c4m_views_switch_page']['link_path'] = 'people/table';
  $handler->display->display_options['header']['c4m_views_switch_page']['link_text'] = 'Table view';
  $handler->display->display_options['header']['c4m_views_switch_page']['link_class'] = 'table-teaser-view';
  $handler->display->display_options['header']['c4m_views_switch_page']['link_icon'] = 'fa-table';
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
  /* Filter criterion: Search form */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_c4m_search_users';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['ui_name'] = 'Search form';
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
  /* Filter criterion: Indexed User: Is deleted */
  $handler->display->display_options['filters']['c4m_is_deleted']['id'] = 'c4m_is_deleted';
  $handler->display->display_options['filters']['c4m_is_deleted']['table'] = 'search_api_index_c4m_search_users';
  $handler->display->display_options['filters']['c4m_is_deleted']['field'] = 'c4m_is_deleted';
  $handler->display->display_options['filters']['c4m_is_deleted']['value'] = array(
    0 => '0',
  );
  /* Filter criterion: Indexed User: Is spammer */
  $handler->display->display_options['filters']['c4m_is_spammer']['id'] = 'c4m_is_spammer';
  $handler->display->display_options['filters']['c4m_is_spammer']['table'] = 'search_api_index_c4m_search_users';
  $handler->display->display_options['filters']['c4m_is_spammer']['field'] = 'c4m_is_spammer';
  $handler->display->display_options['filters']['c4m_is_spammer']['value'] = array(
    0 => '0',
  );
  /* Filter criterion: Indexed User: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_c4m_search_users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '5';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'people';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'People';
  $handler->display->display_options['menu']['weight'] = '7';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '5';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'rendered_entity' => 'rendered_entity',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rendered_entity' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Rendered User */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_user';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'c4m_user_teaser_table_global';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['path'] = 'people/table';
  $export['c4m_overview_people'] = $view;

  return $export;
}
