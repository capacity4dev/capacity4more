<?php
/**
 * @file
 * c4m_message.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function c4m_message_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'activity_stream';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'message';
  $view->human_name = 'Activity stream';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'group';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'activity_stream';
  /* Field: Message: Message ID */
  $handler->display->display_options['fields']['mid']['id'] = 'mid';
  $handler->display->display_options['fields']['mid']['table'] = 'message';
  $handler->display->display_options['fields']['mid']['field'] = 'mid';
  /* Sort criterion: Message: Timestamp */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'message';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Contextual filter: Message: Group (field_group) */
  $handler->display->display_options['arguments']['field_group_target_id']['id'] = 'field_group_target_id';
  $handler->display->display_options['arguments']['field_group_target_id']['table'] = 'field_data_field_group';
  $handler->display->display_options['arguments']['field_group_target_id']['field'] = 'field_group_target_id';
  $handler->display->display_options['arguments']['field_group_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_group_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_group_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_group_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_group_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Message: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'message';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'comment_added' => 'comment_added',
    'node_added' => 'node_added',
    'node_edited' => 'node_edited',
    'user_added' => 'user_added',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'activity';

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_activity_stream');
  $handler->display->display_options['argument_input'] = array(
    'field_group_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Message: Group (field_group)',
    ),
  );
  $export['activity_stream'] = $view;

  return $export;
}
