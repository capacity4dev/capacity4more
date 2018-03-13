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
  $view->name = 'global_activity_stream_no_js_fallback';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'message';
  $view->human_name = 'Global activity stream no-js fallback';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Global activity stream no-js fallback';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_tags'] = array(
    0 => 'global_activity_stream_no_js_fallback',
  );
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'activity_global';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_node_target_id']['id'] = 'field_node_target_id';
  $handler->display->display_options['relationships']['field_node_target_id']['table'] = 'field_data_field_node';
  $handler->display->display_options['relationships']['field_node_target_id']['field'] = 'field_node_target_id';
  $handler->display->display_options['relationships']['field_node_target_id']['required'] = TRUE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['c4m_media']['id'] = 'c4m_media';
  $handler->display->display_options['fields']['c4m_media']['table'] = 'field_data_c4m_media';
  $handler->display->display_options['fields']['c4m_media']['field'] = 'c4m_media';
  $handler->display->display_options['fields']['c4m_media']['relationship'] = 'field_node_target_id';
  $handler->display->display_options['fields']['c4m_media']['label'] = '';
  $handler->display->display_options['fields']['c4m_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_media']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['c4m_media']['settings'] = array(
    'image_style' => 'media_thumbnail',
    'image_link' => 'content',
  );
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
  /* Contextual filter: Field: Topics (c4m_vocab_topic) */
  $handler->display->display_options['arguments']['c4m_vocab_topic_tid']['id'] = 'c4m_vocab_topic_tid';
  $handler->display->display_options['arguments']['c4m_vocab_topic_tid']['table'] = 'field_data_c4m_vocab_topic';
  $handler->display->display_options['arguments']['c4m_vocab_topic_tid']['field'] = 'c4m_vocab_topic_tid';
  $handler->display->display_options['arguments']['c4m_vocab_topic_tid']['relationship'] = 'field_node_target_id';
  $handler->display->display_options['arguments']['c4m_vocab_topic_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['c4m_vocab_topic_tid']['default_argument_type'] = 'c4m_message_user_interests';
  $handler->display->display_options['arguments']['c4m_vocab_topic_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['c4m_vocab_topic_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['c4m_vocab_topic_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['c4m_vocab_topic_tid']['break_phrase'] = TRUE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Message: Entity Published (field_entity_published) */
  $handler->display->display_options['filters']['field_entity_published_value']['id'] = 'field_entity_published_value';
  $handler->display->display_options['filters']['field_entity_published_value']['table'] = 'field_data_field_entity_published';
  $handler->display->display_options['filters']['field_entity_published_value']['field'] = 'field_entity_published_value';
  $handler->display->display_options['filters']['field_entity_published_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_entity_published_value']['group'] = 1;
  /* Filter criterion: Message: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'message';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'c4m_insert__comment' => 'c4m_insert__comment',
    'c4m_insert__node__article' => 'c4m_insert__node__article',
    'c4m_insert__node__discussion' => 'c4m_insert__node__discussion',
    'c4m_insert__node__document' => 'c4m_insert__node__document',
    'c4m_insert__node__event' => 'c4m_insert__node__event',
    'c4m_insert__node__news' => 'c4m_insert__node__news',
    'c4m_insert__node__photo' => 'c4m_insert__node__photo',
    'c4m_insert__node__share' => 'c4m_insert__node__share',
    'c4m_insert__node__wiki_page' => 'c4m_insert__node__wiki_page',
    'c4m_insert__node__photoalbum' => 'c4m_insert__node__photoalbum',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'filter';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: Node access */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node_access';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['relationship'] = 'field_node_target_id';
  $handler->display->display_options['filters']['nid']['ui_name'] = 'Node access';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  /* Filter criterion: Message: Group node (field_group_node) */
  $handler->display->display_options['filters']['field_group_node_target_id']['id'] = 'field_group_node_target_id';
  $handler->display->display_options['filters']['field_group_node_target_id']['table'] = 'field_data_field_group_node';
  $handler->display->display_options['filters']['field_group_node_target_id']['field'] = 'field_group_node_target_id';
  $handler->display->display_options['filters']['field_group_node_target_id']['value']['value'] = '%1';
  $handler->display->display_options['filters']['field_group_node_target_id']['group'] = 2;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Global activity stream no JS fallback block';
  $export['global_activity_stream_no_js_fallback'] = $view;

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
