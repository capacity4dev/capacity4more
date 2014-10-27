<?php
/**
 * @file
 * activity_stream.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function activity_stream_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'active_stream';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'message';
  $view->human_name = 'Active stream';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Active stream';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Message: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'message';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['c4m_activity_node_target_id']['id'] = 'c4m_activity_node_target_id';
  $handler->display->display_options['relationships']['c4m_activity_node_target_id']['table'] = 'field_data_c4m_activity_node';
  $handler->display->display_options['relationships']['c4m_activity_node_target_id']['field'] = 'c4m_activity_node_target_id';
  $handler->display->display_options['relationships']['c4m_activity_node_target_id']['required'] = TRUE;
  /* Field: User: Link */
  $handler->display->display_options['fields']['view_user']['id'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['table'] = 'users';
  $handler->display->display_options['fields']['view_user']['field'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['relationship'] = 'user';
  $handler->display->display_options['fields']['view_user']['label'] = '';
  $handler->display->display_options['fields']['view_user']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_user']['element_label_colon'] = FALSE;
  /* Field: Message: Message ID */
  $handler->display->display_options['fields']['mid']['id'] = 'mid';
  $handler->display->display_options['fields']['mid']['table'] = 'message';
  $handler->display->display_options['fields']['mid']['field'] = 'mid';
  /* Field: User: First Name */
  $handler->display->display_options['fields']['c4m_first_name']['id'] = 'c4m_first_name';
  $handler->display->display_options['fields']['c4m_first_name']['table'] = 'field_data_c4m_first_name';
  $handler->display->display_options['fields']['c4m_first_name']['field'] = 'c4m_first_name';
  $handler->display->display_options['fields']['c4m_first_name']['relationship'] = 'user';
  $handler->display->display_options['fields']['c4m_first_name']['label'] = '';
  $handler->display->display_options['fields']['c4m_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['c4m_first_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['c4m_first_name']['alter']['path'] = '[view_user]';
  $handler->display->display_options['fields']['c4m_first_name']['element_label_colon'] = FALSE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['c4m_last_name']['id'] = 'c4m_last_name';
  $handler->display->display_options['fields']['c4m_last_name']['table'] = 'field_data_c4m_last_name';
  $handler->display->display_options['fields']['c4m_last_name']['field'] = 'c4m_last_name';
  $handler->display->display_options['fields']['c4m_last_name']['relationship'] = 'user';
  $handler->display->display_options['fields']['c4m_last_name']['label'] = '';
  $handler->display->display_options['fields']['c4m_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['c4m_last_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['c4m_last_name']['alter']['path'] = '[view_user]';
  $handler->display->display_options['fields']['c4m_last_name']['element_label_colon'] = FALSE;
  /* Field: Content: Discussion type */
  $handler->display->display_options['fields']['field_discussion_type']['id'] = 'field_discussion_type';
  $handler->display->display_options['fields']['field_discussion_type']['table'] = 'field_data_field_discussion_type';
  $handler->display->display_options['fields']['field_discussion_type']['field'] = 'field_discussion_type';
  $handler->display->display_options['fields']['field_discussion_type']['relationship'] = 'c4m_activity_node_target_id';
  $handler->display->display_options['fields']['field_discussion_type']['label'] = '';
  $handler->display->display_options['fields']['field_discussion_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_discussion_type']['element_label_colon'] = FALSE;
  /* Field: Message: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'message';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['exclude'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'custom';
  $handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'j F, H:i';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'day';
  $handler->display->display_options['fields']['timestamp']['reldate'] = '0';
  /* Field: Field: Image */
  $handler->display->display_options['fields']['c4m_media']['id'] = 'c4m_media';
  $handler->display->display_options['fields']['c4m_media']['table'] = 'field_data_c4m_media';
  $handler->display->display_options['fields']['c4m_media']['field'] = 'c4m_media';
  $handler->display->display_options['fields']['c4m_media']['relationship'] = 'user';
  $handler->display->display_options['fields']['c4m_media']['label'] = '';
  $handler->display->display_options['fields']['c4m_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_media']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['c4m_media']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[c4m_first_name] [c4m_last_name]  posted [field_discussion_type] | [timestamp]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'user';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'thumbnail';
  /* Contextual filter: Message: Group (c4m_activity_group) */
  $handler->display->display_options['arguments']['c4m_activity_group_target_id']['id'] = 'c4m_activity_group_target_id';
  $handler->display->display_options['arguments']['c4m_activity_group_target_id']['table'] = 'field_data_c4m_activity_group';
  $handler->display->display_options['arguments']['c4m_activity_group_target_id']['field'] = 'c4m_activity_group_target_id';
  $handler->display->display_options['arguments']['c4m_activity_group_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['c4m_activity_group_target_id']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['c4m_activity_group_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['c4m_activity_group_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['c4m_activity_group_target_id']['summary_options']['items_per_page'] = '25';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'active-stream';
  $export['active_stream'] = $view;

  return $export;
}
