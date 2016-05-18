<?php
/**
 * @file
 * c4m_features_learning_space.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function c4m_features_learning_space_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'c4m_learning_content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Learning Content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Learning Content';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Show more';
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'no-border';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'block_list';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Date -  start date (c4m_datetime_end) */
  $handler->display->display_options['sorts']['c4m_datetime_end_value']['id'] = 'c4m_datetime_end_value';
  $handler->display->display_options['sorts']['c4m_datetime_end_value']['table'] = 'field_data_c4m_datetime_end';
  $handler->display->display_options['sorts']['c4m_datetime_end_value']['field'] = 'c4m_datetime_end_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Events Block */
  $handler = $view->new_display('block', 'Events Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming Events';
  $handler->display->display_options['link_url'] = 'learning/events';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date -  start date (c4m_datetime_end) */
  $handler->display->display_options['sorts']['c4m_datetime_end_value']['id'] = 'c4m_datetime_end_value';
  $handler->display->display_options['sorts']['c4m_datetime_end_value']['table'] = 'field_data_c4m_datetime_end';
  $handler->display->display_options['sorts']['c4m_datetime_end_value']['field'] = 'c4m_datetime_end_value';
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
    'event' => 'event',
  );
  /* Filter criterion: Content: Date - end date (c4m_datetime_end:value2) */
  $handler->display->display_options['filters']['c4m_datetime_end_value2']['id'] = 'c4m_datetime_end_value2';
  $handler->display->display_options['filters']['c4m_datetime_end_value2']['table'] = 'field_data_c4m_datetime_end';
  $handler->display->display_options['filters']['c4m_datetime_end_value2']['field'] = 'c4m_datetime_end_value2';
  $handler->display->display_options['filters']['c4m_datetime_end_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['c4m_datetime_end_value2']['granularity'] = 'minute';
  $handler->display->display_options['filters']['c4m_datetime_end_value2']['default_date'] = 'now';
  $handler->display->display_options['filters']['c4m_datetime_end_value2']['year_range'] = '-0:+0';
  /* Filter criterion: Content: Type of Event (c4m_event_type) */
  $handler->display->display_options['filters']['c4m_event_type_value']['id'] = 'c4m_event_type_value';
  $handler->display->display_options['filters']['c4m_event_type_value']['table'] = 'field_data_c4m_event_type';
  $handler->display->display_options['filters']['c4m_event_type_value']['field'] = 'c4m_event_type_value';
  $handler->display->display_options['filters']['c4m_event_type_value']['value'] = array(
    'learning' => 'learning',
  );

  /* Display: Documents Block */
  $handler = $view->new_display('block', 'Documents Block', 'block_1');
  $handler->display->display_options['link_url'] = 'learning/documents';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type of Document (c4m_vocab_document_type) */
  $handler->display->display_options['filters']['c4m_vocab_document_type_tid']['id'] = 'c4m_vocab_document_type_tid';
  $handler->display->display_options['filters']['c4m_vocab_document_type_tid']['table'] = 'field_data_c4m_vocab_document_type';
  $handler->display->display_options['filters']['c4m_vocab_document_type_tid']['field'] = 'c4m_vocab_document_type_tid';
  $handler->display->display_options['filters']['c4m_vocab_document_type_tid']['value'] = array(
    311 => '311',
    313 => '313',
    310 => '310',
  );
  $handler->display->display_options['filters']['c4m_vocab_document_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['c4m_vocab_document_type_tid']['vocabulary'] = 'c4m_vocab_document_type';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'document' => 'document',
  );
  $export['c4m_learning_content'] = $view;

  return $export;
}
