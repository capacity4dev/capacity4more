<?php
/**
 * @file
 * c4m_content_page_element.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function c4m_content_page_element_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'intro_block';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Intro block';
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  /* Field: Field: Description */
  $handler->display->display_options['fields']['c4m_body']['id'] = 'c4m_body';
  $handler->display->display_options['fields']['c4m_body']['table'] = 'field_data_c4m_body';
  $handler->display->display_options['fields']['c4m_body']['field'] = 'c4m_body';
  $handler->display->display_options['fields']['c4m_body']['label'] = '';
  $handler->display->display_options['fields']['c4m_body']['element_label_colon'] = FALSE;
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
    'page_element' => 'page_element',
  );
  /* Filter criterion: Content: Page (c4m_page) */
  $handler->display->display_options['filters']['c4m_page_value']['id'] = 'c4m_page_value';
  $handler->display->display_options['filters']['c4m_page_value']['table'] = 'field_data_c4m_page';
  $handler->display->display_options['filters']['c4m_page_value']['field'] = 'c4m_page_value';
  $handler->display->display_options['filters']['c4m_page_value']['value'] = 'homepage';
  /* Filter criterion: Content: Position (c4m_position) */
  $handler->display->display_options['filters']['c4m_position_value']['id'] = 'c4m_position_value';
  $handler->display->display_options['filters']['c4m_position_value']['table'] = 'field_data_c4m_position';
  $handler->display->display_options['filters']['c4m_position_value']['field'] = 'c4m_position_value';
  $handler->display->display_options['filters']['c4m_position_value']['value'] = 'top';

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $export['intro_block'] = $view;

  return $export;
}
