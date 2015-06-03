<?php
/**
 * @file
 * c4m_features_inthe_picture.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function c4m_features_inthe_picture_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'c4m_overview_inthe_picture';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Overview : In the Picture';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'node|created';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'teaser';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'inthe_picture' => 'inthe_picture',
  );
  $export['c4m_overview_inthe_picture'] = $view;

  $view = new view();
  $view->name = 'c4m_overview_inthe_picture_blocks';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'In the Picture';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'teaser';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'inthe_picture' => 'inthe_picture',
  );
  /* Filter criterion: Content: Overview page (c4m_overview_page) */
  $handler->display->display_options['filters']['c4m_overview_page_value']['id'] = 'c4m_overview_page_value';
  $handler->display->display_options['filters']['c4m_overview_page_value']['table'] = 'field_data_c4m_overview_page';
  $handler->display->display_options['filters']['c4m_overview_page_value']['field'] = 'c4m_overview_page_value';
  $handler->display->display_options['filters']['c4m_overview_page_value']['value'] = array(
    'Groups' => 'Groups',
  );

  /* Display: Voices & Views */
  $handler = $view->new_display('block', 'Voices & Views', 'block');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'inthe_picture' => 'inthe_picture',
  );
  /* Filter criterion: Content: Overview page (c4m_overview_page) */
  $handler->display->display_options['filters']['c4m_overview_page_value']['id'] = 'c4m_overview_page_value';
  $handler->display->display_options['filters']['c4m_overview_page_value']['table'] = 'field_data_c4m_overview_page';
  $handler->display->display_options['filters']['c4m_overview_page_value']['field'] = 'c4m_overview_page_value';
  $handler->display->display_options['filters']['c4m_overview_page_value']['value'] = array(
    'Voices & Views' => 'Voices & Views',
  );

  /* Display: Groups */
  $handler = $view->new_display('block', 'Groups', 'block_1');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'inthe_picture' => 'inthe_picture',
  );
  /* Filter criterion: Content: Overview page (c4m_overview_page) */
  $handler->display->display_options['filters']['c4m_overview_page_value']['id'] = 'c4m_overview_page_value';
  $handler->display->display_options['filters']['c4m_overview_page_value']['table'] = 'field_data_c4m_overview_page';
  $handler->display->display_options['filters']['c4m_overview_page_value']['field'] = 'c4m_overview_page_value';
  $handler->display->display_options['filters']['c4m_overview_page_value']['value'] = array(
    'Groups' => 'Groups',
  );

  /* Display: Projects */
  $handler = $view->new_display('block', 'Projects', 'block_2');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'inthe_picture' => 'inthe_picture',
  );
  /* Filter criterion: Content: Overview page (c4m_overview_page) */
  $handler->display->display_options['filters']['c4m_overview_page_value']['id'] = 'c4m_overview_page_value';
  $handler->display->display_options['filters']['c4m_overview_page_value']['table'] = 'field_data_c4m_overview_page';
  $handler->display->display_options['filters']['c4m_overview_page_value']['field'] = 'c4m_overview_page_value';
  $handler->display->display_options['filters']['c4m_overview_page_value']['value'] = array(
    'Projects' => 'Projects',
  );

  /* Display: Events */
  $handler = $view->new_display('block', 'Events', 'block_3');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'inthe_picture' => 'inthe_picture',
  );
  /* Filter criterion: Content: Overview page (c4m_overview_page) */
  $handler->display->display_options['filters']['c4m_overview_page_value']['id'] = 'c4m_overview_page_value';
  $handler->display->display_options['filters']['c4m_overview_page_value']['table'] = 'field_data_c4m_overview_page';
  $handler->display->display_options['filters']['c4m_overview_page_value']['field'] = 'c4m_overview_page_value';
  $handler->display->display_options['filters']['c4m_overview_page_value']['value'] = array(
    'Events' => 'Events',
  );

  /* Display: People */
  $handler = $view->new_display('block', 'People', 'block_4');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'inthe_picture' => 'inthe_picture',
  );
  /* Filter criterion: Content: Overview page (c4m_overview_page) */
  $handler->display->display_options['filters']['c4m_overview_page_value']['id'] = 'c4m_overview_page_value';
  $handler->display->display_options['filters']['c4m_overview_page_value']['table'] = 'field_data_c4m_overview_page';
  $handler->display->display_options['filters']['c4m_overview_page_value']['field'] = 'c4m_overview_page_value';
  $handler->display->display_options['filters']['c4m_overview_page_value']['value'] = array(
    'People' => 'People',
  );
  $export['c4m_overview_inthe_picture_blocks'] = $view;

  return $export;
}
