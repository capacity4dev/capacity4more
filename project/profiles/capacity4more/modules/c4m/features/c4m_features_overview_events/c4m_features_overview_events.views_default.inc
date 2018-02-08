<?php

/**
 * @file
 * c4m_features_overview_events.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function c4m_features_overview_events_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'c4m_events_calendar';
  $view->description = '';
  $view->tag = 'Calendar';
  $view->base_table = 'node';
  $view->human_name = 'Events calendar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_1';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['c4m_datetime_end']['id'] = 'c4m_datetime_end';
  $handler->display->display_options['fields']['c4m_datetime_end']['table'] = 'field_data_c4m_datetime_end';
  $handler->display->display_options['fields']['c4m_datetime_end']['field'] = 'c4m_datetime_end';
  $handler->display->display_options['fields']['c4m_datetime_end']['label'] = '';
  $handler->display->display_options['fields']['c4m_datetime_end']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_datetime_end']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['c4m_datetime_end']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['c4m_datetime_end']['settings'] = array(
    'format_type' => 'custom',
    'custom_date_format' => 'g:ia',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['fields']['c4m_datetime_end']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['c4m_datetime_end']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<span>[title]</span>';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alt'] = '[title]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Date -  start date (c4m_datetime_end) */
  $handler->display->display_options['sorts']['c4m_datetime_end_value']['id'] = 'c4m_datetime_end_value';
  $handler->display->display_options['sorts']['c4m_datetime_end_value']['table'] = 'field_data_c4m_datetime_end';
  $handler->display->display_options['sorts']['c4m_datetime_end_value']['field'] = 'c4m_datetime_end_value';

  /* Display: Month */
  $handler = $view->new_display('page', 'Month', 'month');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['pager']['options']['pager_position'] = 'both';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['pager']['options']['skip_empty_pages'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'c4m_event_row';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['row_options']['colors']['legend'] = 'c4m_event_type';
  $handler->display->display_options['row_options']['colors']['calendar_colors_type'] = array(
    'article' => '#ffffff',
    'banner' => '#ffffff',
    'book' => '#ffffff',
    'discussion' => '#ffffff',
    'document' => '#ffffff',
    'event' => '#c74d4d',
    'featured' => '#ffffff',
    'feed' => '#ffffff',
    'group' => '#ffffff',
    'inthe_picture' => '#ffffff',
    'news' => '#ffffff',
    'organisation' => '#ffffff',
    'page_element' => '#ffffff',
    'photo' => '#ffffff',
    'photoalbum' => '#ffffff',
    'project' => '#ffffff',
    'share' => '#ffffff',
    'topic' => '#ffffff',
    'wiki_page' => '#ffffff',
  );
  $handler->display->display_options['row_options']['colors']['calendar_colors_group'] = array(
    24 => '#ffffff',
    25 => '#ffffff',
    30 => '#ffffff',
    31 => '#ffffff',
    36 => '#ffffff',
    37 => '#ffffff',
    38 => '#ffffff',
    40 => '#ffffff',
  );
  $handler->display->display_options['row_options']['colors']['c4m_event_type'] = array(
    'event' => '#347C98',
    'learning' => '#B0C35A',
    'meeting' => '#EE6A32',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_c4m_datetime_end.c4m_datetime_end_value' => 'field_data_c4m_datetime_end.c4m_datetime_end_value',
  );
  $handler->display->display_options['path'] = 'events/calendar';
  $handler->display->display_options['menu']['weight'] = '-1';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Calendar';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Day */
  $handler = $view->new_display('page', 'Day', 'page_3');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'day';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'day';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'day';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_c4m_datetime_end.c4m_datetime_end_value' => 'field_data_c4m_datetime_end.c4m_datetime_end_value',
  );
  $handler->display->display_options['path'] = 'calendar-node-c4m-datetime-end/day';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Day';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Year */
  $handler = $view->new_display('page', 'Year', 'page');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'year';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'year';
  $handler->display->display_options['style_options']['name_size'] = '1';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['c4m_datetime_end']['id'] = 'c4m_datetime_end';
  $handler->display->display_options['fields']['c4m_datetime_end']['table'] = 'field_data_c4m_datetime_end';
  $handler->display->display_options['fields']['c4m_datetime_end']['field'] = 'c4m_datetime_end';
  $handler->display->display_options['fields']['c4m_datetime_end']['label'] = '';
  $handler->display->display_options['fields']['c4m_datetime_end']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_datetime_end']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['c4m_datetime_end']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => '',
  );
  $handler->display->display_options['fields']['c4m_datetime_end']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['c4m_datetime_end']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'year';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_c4m_datetime_end.c4m_datetime_end_value' => 'field_data_c4m_datetime_end.c4m_datetime_end_value',
  );
  $handler->display->display_options['path'] = 'calendar-node-c4m-datetime-end/year';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Year';
  $handler->display->display_options['menu']['weight'] = '4';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'mini';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '1';
  $handler->display->display_options['style_options']['mini'] = '1';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_c4m_datetime_end.c4m_datetime_end_value' => 'field_data_c4m_datetime_end.c4m_datetime_end_value',
  );

  /* Display: Upcoming */
  $handler = $view->new_display('block', 'Upcoming', 'block_2');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['display_description'] = 'Upcoming events block';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['add_delta'] = 'yes';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_c4m_datetime_end.c4m_datetime_end_value' => 'field_data_c4m_datetime_end.c4m_datetime_end_value',
  );

  /* Display: Week */
  $handler = $view->new_display('page', 'Week', 'week');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'week';
  $handler->display->display_options['pager']['options']['pager_position'] = 'both';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['pager']['options']['skip_empty_pages'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'week';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['style_options']['groupby_times'] = 'half';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'c4m_event_row';
  $handler->display->display_options['row_options']['colors']['legend'] = 'c4m_event_type';
  $handler->display->display_options['row_options']['colors']['calendar_colors_type'] = array(
    'article' => '#ffffff',
    'banner' => '#ffffff',
    'book' => '#ffffff',
    'discussion' => '#ffffff',
    'document' => '#ffffff',
    'event' => '#c74d4d',
    'featured' => '#ffffff',
    'feed' => '#ffffff',
    'group' => '#ffffff',
    'inthe_picture' => '#ffffff',
    'news' => '#ffffff',
    'organisation' => '#ffffff',
    'page_element' => '#ffffff',
    'photo' => '#ffffff',
    'photoalbum' => '#ffffff',
    'project' => '#ffffff',
    'share' => '#ffffff',
    'topic' => '#ffffff',
    'wiki_page' => '#ffffff',
  );
  $handler->display->display_options['row_options']['colors']['calendar_colors_group'] = array(
    24 => '#ffffff',
    25 => '#ffffff',
    30 => '#ffffff',
    31 => '#ffffff',
    36 => '#ffffff',
    37 => '#ffffff',
    38 => '#ffffff',
    40 => '#ffffff',
  );
  $handler->display->display_options['row_options']['colors']['c4m_event_type'] = array(
    'event' => '#347C98',
    'learning' => '#B0C35A',
    'meeting' => '#EE6A32',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<span>[title]</span>';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alt'] = '[title]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'week';
  $handler->display->display_options['arguments']['date_argument']['granularity_reset'] = 0;
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_c4m_datetime_end.c4m_datetime_end_value' => 'field_data_c4m_datetime_end.c4m_datetime_end_value',
  );
  $handler->display->display_options['path'] = 'events/calendar/week';
  $handler->display->display_options['menu']['title'] = 'Week';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Calendar';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Group - Month */
  $handler = $view->new_display('page', 'Group - Month', 'og_month');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'c4m_og_access_og_context';
  $handler->display->display_options['access']['feature'] = 'c4m_features_og_events';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['pager']['options']['pager_position'] = 'both';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['pager']['options']['skip_empty_pages'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'c4m_event_row';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['row_options']['colors']['legend'] = 'c4m_event_type';
  $handler->display->display_options['row_options']['colors']['calendar_colors_type'] = array(
    'article' => '#ffffff',
    'banner' => '#ffffff',
    'book' => '#ffffff',
    'discussion' => '#ffffff',
    'document' => '#ffffff',
    'event' => '#c74d4d',
    'featured' => '#ffffff',
    'feed' => '#ffffff',
    'group' => '#ffffff',
    'inthe_picture' => '#ffffff',
    'news' => '#ffffff',
    'organisation' => '#ffffff',
    'page_element' => '#ffffff',
    'photo' => '#ffffff',
    'photoalbum' => '#ffffff',
    'project' => '#ffffff',
    'share' => '#ffffff',
    'topic' => '#ffffff',
    'wiki_page' => '#ffffff',
  );
  $handler->display->display_options['row_options']['colors']['calendar_colors_group'] = array(
    24 => '#ffffff',
    25 => '#ffffff',
    30 => '#ffffff',
    31 => '#ffffff',
    36 => '#ffffff',
    37 => '#ffffff',
    38 => '#ffffff',
    40 => '#ffffff',
  );
  $handler->display->display_options['row_options']['colors']['c4m_event_type'] = array(
    'event' => '#347C98',
    'learning' => '#B0C35A',
    'meeting' => '#EE6A32',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Groups (og_group_ref) */
  $handler->display->display_options['arguments']['og_group_ref_target_id']['id'] = 'og_group_ref_target_id';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['field'] = 'og_group_ref_target_id';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_c4m_datetime_end.c4m_datetime_end_value' => 'field_data_c4m_datetime_end.c4m_datetime_end_value',
  );
  $handler->display->display_options['path'] = 'calendar/month';
  $handler->display->display_options['menu']['weight'] = '-1';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Calendar';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Group - Week */
  $handler = $view->new_display('page', 'Group - Week', 'og_week');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'c4m_og_access_og_context';
  $handler->display->display_options['access']['feature'] = 'c4m_features_og_events';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['pager']['options']['pager_position'] = 'both';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['pager']['options']['skip_empty_pages'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'week';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['style_options']['groupby_times'] = 'half';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'c4m_event_row';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['row_options']['colors']['legend'] = 'c4m_event_type';
  $handler->display->display_options['row_options']['colors']['calendar_colors_type'] = array(
    'article' => '#ffffff',
    'banner' => '#ffffff',
    'book' => '#ffffff',
    'discussion' => '#ffffff',
    'document' => '#ffffff',
    'event' => '#c74d4d',
    'featured' => '#ffffff',
    'feed' => '#ffffff',
    'group' => '#ffffff',
    'inthe_picture' => '#ffffff',
    'news' => '#ffffff',
    'organisation' => '#ffffff',
    'page_element' => '#ffffff',
    'photo' => '#ffffff',
    'photoalbum' => '#ffffff',
    'project' => '#ffffff',
    'share' => '#ffffff',
    'topic' => '#ffffff',
    'wiki_page' => '#ffffff',
  );
  $handler->display->display_options['row_options']['colors']['calendar_colors_group'] = array(
    24 => '#ffffff',
    25 => '#ffffff',
    30 => '#ffffff',
    31 => '#ffffff',
    36 => '#ffffff',
    37 => '#ffffff',
    38 => '#ffffff',
    40 => '#ffffff',
  );
  $handler->display->display_options['row_options']['colors']['c4m_event_type'] = array(
    'event' => '#347C98',
    'learning' => '#B0C35A',
    'meeting' => '#EE6A32',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<span>[title]</span>';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alt'] = '[title]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Groups (og_group_ref) */
  $handler->display->display_options['arguments']['og_group_ref_target_id']['id'] = 'og_group_ref_target_id';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['field'] = 'og_group_ref_target_id';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'week';
  $handler->display->display_options['arguments']['date_argument']['granularity_reset'] = 0;
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_c4m_datetime_end.c4m_datetime_end_value' => 'field_data_c4m_datetime_end.c4m_datetime_end_value',
  );
  $handler->display->display_options['path'] = 'calendar/week';
  $handler->display->display_options['menu']['weight'] = '-1';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Calendar';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['c4m_events_calendar'] = $view;

  $view = new view();
  $view->name = 'c4m_overview_events';
  $view->description = 'Search API powered overview of all events in the current group context.';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_c4m_search_nodes';
  $view->human_name = 'Overview - Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Past events';
  $handler->display->display_options['css_class'] = 'view-items-with-dashed-separator';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
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
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 20, 50';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
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
  /* Header: Number of items */
  $handler->display->display_options['header']['c4m_views_result']['id'] = 'c4m_views_result';
  $handler->display->display_options['header']['c4m_views_result']['table'] = 'views';
  $handler->display->display_options['header']['c4m_views_result']['field'] = 'c4m_views_result';
  $handler->display->display_options['header']['c4m_views_result']['ui_name'] = 'Number of items';
  $handler->display->display_options['header']['c4m_views_result']['empty'] = TRUE;
  $handler->display->display_options['header']['c4m_views_result']['content'] = '<span class="total-items">Events (@total in total, @start - @end shown)</span>';
  /* Header: Items per page */
  $handler->display->display_options['header']['c4m_views_items_per_page']['id'] = 'c4m_views_items_per_page';
  $handler->display->display_options['header']['c4m_views_items_per_page']['table'] = 'views';
  $handler->display->display_options['header']['c4m_views_items_per_page']['field'] = 'c4m_views_items_per_page';
  $handler->display->display_options['header']['c4m_views_items_per_page']['ui_name'] = 'Items per page';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Filter criterion: Node is published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['ui_name'] = 'Node is published';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Only Event nodes */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['ui_name'] = 'Only Event nodes';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Node: Group type */
  $handler->display->display_options['filters']['c4m_og_group_type']['id'] = 'c4m_og_group_type';
  $handler->display->display_options['filters']['c4m_og_group_type']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['filters']['c4m_og_group_type']['field'] = 'c4m_og_group_type';
  $handler->display->display_options['filters']['c4m_og_group_type']['operator'] = '<>';
  $handler->display->display_options['filters']['c4m_og_group_type']['value'] = 'project';
  $handler->display->display_options['filters']['c4m_og_group_type']['group'] = 1;
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
  /* Filter criterion: Date: Start date (indexed) */
  $handler->display->display_options['filters']['c4m_datetime_end_value']['id'] = 'c4m_datetime_end_value';
  $handler->display->display_options['filters']['c4m_datetime_end_value']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['filters']['c4m_datetime_end_value']['field'] = 'c4m_datetime_end_value';
  $handler->display->display_options['filters']['c4m_datetime_end_value']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming events';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Node is published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['ui_name'] = 'Node is published';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Only Event nodes */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['ui_name'] = 'Only Event nodes';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
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
  /* Filter criterion: Date: End date (indexed) */
  $handler->display->display_options['filters']['c4m_datetime_end_value2']['id'] = 'c4m_datetime_end_value2';
  $handler->display->display_options['filters']['c4m_datetime_end_value2']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['filters']['c4m_datetime_end_value2']['field'] = 'c4m_datetime_end_value2';
  $handler->display->display_options['filters']['c4m_datetime_end_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['c4m_datetime_end_value2']['value'] = 'now';
  $handler->display->display_options['filters']['c4m_datetime_end_value2']['group'] = 1;
  /* Filter criterion: Indexed Node: Source Content */
  $handler->display->display_options['filters']['c4m_source_entity']['id'] = 'c4m_source_entity';
  $handler->display->display_options['filters']['c4m_source_entity']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['filters']['c4m_source_entity']['field'] = 'c4m_source_entity';
  $handler->display->display_options['filters']['c4m_source_entity']['operator'] = 'empty';
  $handler->display->display_options['path'] = 'events/upcoming';
  $handler->display->display_options['menu']['title'] = 'Events';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['name'] = 'c4m-og-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Node is published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['ui_name'] = 'Node is published';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Only Event nodes */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['ui_name'] = 'Only Event nodes';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
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
  /* Filter criterion: Date: End date (indexed) */
  $handler->display->display_options['filters']['c4m_datetime_end_value2']['id'] = 'c4m_datetime_end_value2';
  $handler->display->display_options['filters']['c4m_datetime_end_value2']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['filters']['c4m_datetime_end_value2']['field'] = 'c4m_datetime_end_value2';
  $handler->display->display_options['filters']['c4m_datetime_end_value2']['operator'] = '<';
  $handler->display->display_options['filters']['c4m_datetime_end_value2']['value'] = 'now';
  $handler->display->display_options['filters']['c4m_datetime_end_value2']['group'] = 1;
  /* Filter criterion: Indexed Node: Source Content */
  $handler->display->display_options['filters']['c4m_source_entity']['id'] = 'c4m_source_entity';
  $handler->display->display_options['filters']['c4m_source_entity']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['filters']['c4m_source_entity']['field'] = 'c4m_source_entity';
  $handler->display->display_options['filters']['c4m_source_entity']['operator'] = 'empty';
  $handler->display->display_options['path'] = 'events/past';
  $handler->display->display_options['menu']['title'] = 'Events';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['name'] = 'c4m-og-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['c4m_overview_events'] = $view;

  $view = new view();
  $view->name = 'c4m_overview_events_landing';
  $view->description = 'Search API powered overview of all events in the current group context.';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_c4m_search_nodes';
  $view->human_name = 'Overview - Events landing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Past Events';
  $handler->display->display_options['css_class'] = 'view-items-with-dashed-separator';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'All upcoming events';
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['search_api_bypass_access'] = 0;
  $handler->display->display_options['query']['options']['entity_access'] = 0;
  $handler->display->display_options['query']['options']['parse_mode'] = 'direct';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2><i class="fa fa-history"></i> Past events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Sort criterion: Date: Start date (indexed) */
  $handler->display->display_options['sorts']['c4m_datetime_end_value']['id'] = 'c4m_datetime_end_value';
  $handler->display->display_options['sorts']['c4m_datetime_end_value']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['sorts']['c4m_datetime_end_value']['field'] = 'c4m_datetime_end_value';
  /* Filter criterion: Node is published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['ui_name'] = 'Node is published';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Only Event nodes */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['ui_name'] = 'Only Event nodes';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
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
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: Date: End date (indexed) */
  $handler->display->display_options['filters']['c4m_datetime_end_value2']['id'] = 'c4m_datetime_end_value2';
  $handler->display->display_options['filters']['c4m_datetime_end_value2']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['filters']['c4m_datetime_end_value2']['field'] = 'c4m_datetime_end_value2';
  $handler->display->display_options['filters']['c4m_datetime_end_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['c4m_datetime_end_value2']['value'] = 'now';
  /* Filter criterion: Indexed Node: Source Content */
  $handler->display->display_options['filters']['c4m_source_entity']['id'] = 'c4m_source_entity';
  $handler->display->display_options['filters']['c4m_source_entity']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['filters']['c4m_source_entity']['field'] = 'c4m_source_entity';
  $handler->display->display_options['filters']['c4m_source_entity']['operator'] = 'empty';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2><i class="fa fa-clock-o"></i> Upcoming events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['path'] = 'events';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Events';
  $handler->display->display_options['menu']['weight'] = '6';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Date: End date (indexed) */
  $handler->display->display_options['sorts']['c4m_datetime_end_value2']['id'] = 'c4m_datetime_end_value2';
  $handler->display->display_options['sorts']['c4m_datetime_end_value2']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['sorts']['c4m_datetime_end_value2']['field'] = 'c4m_datetime_end_value2';
  $handler->display->display_options['sorts']['c4m_datetime_end_value2']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Node is published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['ui_name'] = 'Node is published';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Only Event nodes */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['ui_name'] = 'Only Event nodes';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
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
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: Date: End date (indexed) */
  $handler->display->display_options['filters']['c4m_datetime_end_value2']['id'] = 'c4m_datetime_end_value2';
  $handler->display->display_options['filters']['c4m_datetime_end_value2']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['filters']['c4m_datetime_end_value2']['field'] = 'c4m_datetime_end_value2';
  $handler->display->display_options['filters']['c4m_datetime_end_value2']['operator'] = '<';
  $handler->display->display_options['filters']['c4m_datetime_end_value2']['value'] = 'now';
  /* Filter criterion: Indexed Node: Source Content */
  $handler->display->display_options['filters']['c4m_source_entity']['id'] = 'c4m_source_entity';
  $handler->display->display_options['filters']['c4m_source_entity']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['filters']['c4m_source_entity']['field'] = 'c4m_source_entity';
  $handler->display->display_options['filters']['c4m_source_entity']['operator'] = 'empty';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $handler->display->display_options['inherit_exposed_filters'] = TRUE;
  $export['c4m_overview_events_landing'] = $view;

  return $export;
}
