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
  $view->name = 'c4m_er_platform_users';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'ER: Platform Users';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: First Name */
  $handler->display->display_options['fields']['c4m_first_name']['id'] = 'c4m_first_name';
  $handler->display->display_options['fields']['c4m_first_name']['table'] = 'field_data_c4m_first_name';
  $handler->display->display_options['fields']['c4m_first_name']['field'] = 'c4m_first_name';
  $handler->display->display_options['fields']['c4m_first_name']['label'] = '';
  $handler->display->display_options['fields']['c4m_first_name']['element_label_colon'] = FALSE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['c4m_last_name']['id'] = 'c4m_last_name';
  $handler->display->display_options['fields']['c4m_last_name']['table'] = 'field_data_c4m_last_name';
  $handler->display->display_options['fields']['c4m_last_name']['field'] = 'c4m_last_name';
  $handler->display->display_options['fields']['c4m_last_name']['label'] = '';
  $handler->display->display_options['fields']['c4m_last_name']['element_label_colon'] = FALSE;
  /* Sort criterion: User: First Name (c4m_first_name) */
  $handler->display->display_options['sorts']['c4m_first_name_value']['id'] = 'c4m_first_name_value';
  $handler->display->display_options['sorts']['c4m_first_name_value']['table'] = 'field_data_c4m_first_name';
  $handler->display->display_options['sorts']['c4m_first_name_value']['field'] = 'c4m_first_name_value';
  /* Sort criterion: User: Last Name (c4m_last_name) */
  $handler->display->display_options['sorts']['c4m_last_name_value']['id'] = 'c4m_last_name_value';
  $handler->display->display_options['sorts']['c4m_last_name_value']['table'] = 'field_data_c4m_last_name';
  $handler->display->display_options['sorts']['c4m_last_name_value']['field'] = 'c4m_last_name_value';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Is deleted (c4m_is_deleted) */
  $handler->display->display_options['filters']['c4m_is_deleted_value']['id'] = 'c4m_is_deleted_value';
  $handler->display->display_options['filters']['c4m_is_deleted_value']['table'] = 'field_data_c4m_is_deleted';
  $handler->display->display_options['filters']['c4m_is_deleted_value']['field'] = 'c4m_is_deleted_value';
  $handler->display->display_options['filters']['c4m_is_deleted_value']['value'] = array(
    0 => '0',
  );
  /* Filter criterion: User: Is spammer (c4m_is_spammer) */
  $handler->display->display_options['filters']['c4m_is_spammer_value']['id'] = 'c4m_is_spammer_value';
  $handler->display->display_options['filters']['c4m_is_spammer_value']['table'] = 'field_data_c4m_is_spammer';
  $handler->display->display_options['filters']['c4m_is_spammer_value']['field'] = 'c4m_is_spammer_value';
  $handler->display->display_options['filters']['c4m_is_spammer_value']['value'] = array(
    0 => '0',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'name' => 'name',
    'c4m_first_name' => 'c4m_first_name',
    'c4m_last_name' => 'c4m_last_name',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['separator'] = '';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['c4m_er_platform_users'] = $view;

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
  $handler->display->display_options['css_class'] = 'view-items-with-dashed-separator';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['search_api_bypass_access'] = 0;
  $handler->display->display_options['query']['options']['entity_access'] = 0;
  $handler->display->display_options['query']['options']['parse_mode'] = 'direct';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '5';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 20, 50';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Header: Search: Spellcheck */
  $handler->display->display_options['header']['search_api_spellcheck']['id'] = 'search_api_spellcheck';
  $handler->display->display_options['header']['search_api_spellcheck']['table'] = 'search_api_index_c4m_search_users';
  $handler->display->display_options['header']['search_api_spellcheck']['field'] = 'search_api_spellcheck';
  $handler->display->display_options['header']['search_api_spellcheck']['empty'] = TRUE;
  /* Header: Sorts */
  $handler->display->display_options['header']['c4m_views_search_api_sorts']['id'] = 'c4m_views_search_api_sorts';
  $handler->display->display_options['header']['c4m_views_search_api_sorts']['table'] = 'views';
  $handler->display->display_options['header']['c4m_views_search_api_sorts']['field'] = 'c4m_views_search_api_sorts';
  $handler->display->display_options['header']['c4m_views_search_api_sorts']['ui_name'] = 'Sorts';
  /* Header: Global: Result summary (with optional classes) */
  $handler->display->display_options['header']['c4m_views_result']['id'] = 'c4m_views_result';
  $handler->display->display_options['header']['c4m_views_result']['table'] = 'views';
  $handler->display->display_options['header']['c4m_views_result']['field'] = 'c4m_views_result';
  $handler->display->display_options['header']['c4m_views_result']['content'] = '<span class="total-items">@total members</span>';
  /* Header: Items per page */
  $handler->display->display_options['header']['c4m_views_items_per_page']['id'] = 'c4m_views_items_per_page';
  $handler->display->display_options['header']['c4m_views_items_per_page']['table'] = 'views';
  $handler->display->display_options['header']['c4m_views_items_per_page']['field'] = 'c4m_views_items_per_page';
  $handler->display->display_options['header']['c4m_views_items_per_page']['ui_name'] = 'Items per page';
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
  $handler->display->display_options['filters']['c4m_is_deleted']['operator'] = '<>';
  $handler->display->display_options['filters']['c4m_is_deleted']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Indexed User: Is spammer */
  $handler->display->display_options['filters']['c4m_is_spammer']['id'] = 'c4m_is_spammer';
  $handler->display->display_options['filters']['c4m_is_spammer']['table'] = 'search_api_index_c4m_search_users';
  $handler->display->display_options['filters']['c4m_is_spammer']['field'] = 'c4m_is_spammer';
  $handler->display->display_options['filters']['c4m_is_spammer']['operator'] = '<>';
  $handler->display->display_options['filters']['c4m_is_spammer']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Indexed User: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_c4m_search_users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Indexed User: User ID */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'search_api_index_c4m_search_users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['operator'] = '<>';
  $handler->display->display_options['filters']['uid']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'people';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'People';
  $handler->display->display_options['menu']['weight'] = '7';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['c4m_overview_people'] = $view;

  return $export;
}
