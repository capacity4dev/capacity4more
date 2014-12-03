<?php
/**
 * @file
 * c4m_features_og_overview_members.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function c4m_features_og_overview_members_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'c4m_overview_og_members';
  $view->description = 'Table list of all members of a group.';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Overview - OG - Members';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Overview - Members';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'c4m_media' => 'c4m_media',
    'c4m_first_name' => 'c4m_first_name',
    'c4m_last_name' => 'c4m_last_name',
    'rid' => 'rid',
    'created_1' => 'created_1',
    'og_roles' => 'og_roles',
  );
  $handler->display->display_options['style_options']['default'] = 'created_1';
  $handler->display->display_options['style_options']['info'] = array(
    'c4m_media' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'c4m_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'c4m_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'og_roles' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No Members found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
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
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['c4m_last_name']['id'] = 'c4m_last_name';
  $handler->display->display_options['fields']['c4m_last_name']['table'] = 'field_data_c4m_last_name';
  $handler->display->display_options['fields']['c4m_last_name']['field'] = 'c4m_last_name';
  $handler->display->display_options['fields']['c4m_last_name']['alter']['text'] = '[c4m_first_name] [c4m_last_name]';
  $handler->display->display_options['fields']['c4m_last_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['c4m_last_name']['alter']['path'] = 'user/[uid]';
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  /* Field: OG membership: Created */
  $handler->display->display_options['fields']['created_1']['id'] = 'created_1';
  $handler->display->display_options['fields']['created_1']['table'] = 'og_membership';
  $handler->display->display_options['fields']['created_1']['field'] = 'created';
  $handler->display->display_options['fields']['created_1']['label'] = 'Joined';
  $handler->display->display_options['fields']['created_1']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['created_1']['reldate'] = 'reldate';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
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
  $handler->display->display_options['path'] = 'members';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Members';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['name'] = 'c4m-og-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['c4m_overview_og_members'] = $view;

  return $export;
}
