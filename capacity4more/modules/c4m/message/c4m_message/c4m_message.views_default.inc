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
  $view->name = 'group_activity_stream';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'message';
  $view->human_name = 'Group activity stream';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'activity_group';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_node_target_id']['id'] = 'field_node_target_id';
  $handler->display->display_options['relationships']['field_node_target_id']['table'] = 'field_data_field_node';
  $handler->display->display_options['relationships']['field_node_target_id']['field'] = 'field_node_target_id';
  /* Field: Message: Message ID */
  $handler->display->display_options['fields']['mid']['id'] = 'mid';
  $handler->display->display_options['fields']['mid']['table'] = 'message';
  $handler->display->display_options['fields']['mid']['field'] = 'mid';
  $handler->display->display_options['fields']['mid']['exclude'] = TRUE;
  /* Field: Message: Render message (Get text) */
  $handler->display->display_options['fields']['message_render']['id'] = 'message_render';
  $handler->display->display_options['fields']['message_render']['table'] = 'message';
  $handler->display->display_options['fields']['message_render']['field'] = 'message_render';
  $handler->display->display_options['fields']['message_render']['label'] = '';
  $handler->display->display_options['fields']['message_render']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['message_render']['partials'] = 0;
  $handler->display->display_options['fields']['message_render']['partials_delta'] = '0';
  /* Sort criterion: Message: Timestamp */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'message';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Contextual filter: Message: Group node (field_group_node) */
  $handler->display->display_options['arguments']['field_group_node_target_id']['id'] = 'field_group_node_target_id';
  $handler->display->display_options['arguments']['field_group_node_target_id']['table'] = 'field_data_field_group_node';
  $handler->display->display_options['arguments']['field_group_node_target_id']['field'] = 'field_group_node_target_id';
  $handler->display->display_options['arguments']['field_group_node_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_group_node_target_id']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['field_group_node_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_group_node_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_group_node_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_group_node_target_id']['validate']['type'] = 'node';
  /* Filter criterion: Message: Entity Published (field_entity_published) */
  $handler->display->display_options['filters']['field_entity_published_value']['id'] = 'field_entity_published_value';
  $handler->display->display_options['filters']['field_entity_published_value']['table'] = 'field_data_field_entity_published';
  $handler->display->display_options['filters']['field_entity_published_value']['field'] = 'field_entity_published_value';
  $handler->display->display_options['filters']['field_entity_published_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_entity_published_value']['expose']['operator_id'] = 'field_entity_published_value_op';
  $handler->display->display_options['filters']['field_entity_published_value']['expose']['label'] = 'Entity Published (field_entity_published)';
  $handler->display->display_options['filters']['field_entity_published_value']['expose']['operator'] = 'field_entity_published_value_op';
  $handler->display->display_options['filters']['field_entity_published_value']['expose']['identifier'] = 'field_entity_published_value';
  /* Filter criterion: Content access: Access */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node_access';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['relationship'] = 'field_node_target_id';

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'field_group_node_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Message: Group node (field_group_node)',
    ),
  );
  $export['group_activity_stream'] = $view;

  return $export;
}
