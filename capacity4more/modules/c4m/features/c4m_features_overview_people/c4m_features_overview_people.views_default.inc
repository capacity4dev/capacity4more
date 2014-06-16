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
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Overview - People';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Overview - People';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Field: Image */
  $handler->display->display_options['fields']['c4m_media']['id'] = 'c4m_media';
  $handler->display->display_options['fields']['c4m_media']['table'] = 'field_data_c4m_media';
  $handler->display->display_options['fields']['c4m_media']['field'] = 'c4m_media';
  $handler->display->display_options['fields']['c4m_media']['label'] = '';
  $handler->display->display_options['fields']['c4m_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_media']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['c4m_media']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: User: First Name */
  $handler->display->display_options['fields']['c4m_first_name']['id'] = 'c4m_first_name';
  $handler->display->display_options['fields']['c4m_first_name']['table'] = 'field_data_c4m_first_name';
  $handler->display->display_options['fields']['c4m_first_name']['field'] = 'c4m_first_name';
  $handler->display->display_options['fields']['c4m_first_name']['exclude'] = TRUE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['c4m_last_name']['id'] = 'c4m_last_name';
  $handler->display->display_options['fields']['c4m_last_name']['table'] = 'field_data_c4m_last_name';
  $handler->display->display_options['fields']['c4m_last_name']['field'] = 'c4m_last_name';
  $handler->display->display_options['fields']['c4m_last_name']['label'] = 'Name';
  $handler->display->display_options['fields']['c4m_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['c4m_last_name']['alter']['text'] = '[c4m_first_name] [c4m_last_name]';
  /* Field: User: Type of Organisation */
  $handler->display->display_options['fields']['c4m_organisation_type']['id'] = 'c4m_organisation_type';
  $handler->display->display_options['fields']['c4m_organisation_type']['table'] = 'field_data_c4m_organisation_type';
  $handler->display->display_options['fields']['c4m_organisation_type']['field'] = 'c4m_organisation_type';
  /* Field: User: Organisation */
  $handler->display->display_options['fields']['c4m_organisation']['id'] = 'c4m_organisation';
  $handler->display->display_options['fields']['c4m_organisation']['table'] = 'field_data_c4m_organisation';
  $handler->display->display_options['fields']['c4m_organisation']['field'] = 'c4m_organisation';
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Joined';
  $handler->display->display_options['fields']['created']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['created']['reldate'] = 'reldate';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Active';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
    7 => 0,
  );
  /* Filter criterion: User: First Name (c4m_first_name) */
  $handler->display->display_options['filters']['c4m_first_name_value']['id'] = 'c4m_first_name_value';
  $handler->display->display_options['filters']['c4m_first_name_value']['table'] = 'field_data_c4m_first_name';
  $handler->display->display_options['filters']['c4m_first_name_value']['field'] = 'c4m_first_name_value';
  $handler->display->display_options['filters']['c4m_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['c4m_first_name_value']['expose']['operator_id'] = 'c4m_first_name_value_op';
  $handler->display->display_options['filters']['c4m_first_name_value']['expose']['label'] = 'First Name';
  $handler->display->display_options['filters']['c4m_first_name_value']['expose']['operator'] = 'c4m_first_name_value_op';
  $handler->display->display_options['filters']['c4m_first_name_value']['expose']['identifier'] = 'c4m_first_name_value';
  $handler->display->display_options['filters']['c4m_first_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
    7 => 0,
  );
  /* Filter criterion: User: Last Name (c4m_last_name) */
  $handler->display->display_options['filters']['c4m_last_name_value']['id'] = 'c4m_last_name_value';
  $handler->display->display_options['filters']['c4m_last_name_value']['table'] = 'field_data_c4m_last_name';
  $handler->display->display_options['filters']['c4m_last_name_value']['field'] = 'c4m_last_name_value';
  $handler->display->display_options['filters']['c4m_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['c4m_last_name_value']['expose']['operator_id'] = 'c4m_last_name_value_op';
  $handler->display->display_options['filters']['c4m_last_name_value']['expose']['label'] = 'Last Name';
  $handler->display->display_options['filters']['c4m_last_name_value']['expose']['operator'] = 'c4m_last_name_value_op';
  $handler->display->display_options['filters']['c4m_last_name_value']['expose']['identifier'] = 'c4m_last_name_value';
  $handler->display->display_options['filters']['c4m_last_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
    7 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
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
