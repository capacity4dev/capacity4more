<?php
/**
 * @file
 * c4m_admin_groups.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function c4m_admin_groups_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'c4m_admin_groups';
  $view->description = 'Administration interface to manage groups & their status.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Admin : Groups';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Groups';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer nodes';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '5';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'c4m_og_status' => 'c4m_og_status',
    'name' => 'name',
    'created' => 'created',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'c4m_og_status' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Status */
  $handler->display->display_options['fields']['c4m_og_status']['id'] = 'c4m_og_status';
  $handler->display->display_options['fields']['c4m_og_status']['table'] = 'field_data_c4m_og_status';
  $handler->display->display_options['fields']['c4m_og_status']['field'] = 'c4m_og_status';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Owner';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'c4m_long_without_time';
  $handler->display->display_options['fields']['created']['reldate'] = '0';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
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
    'group' => 'group',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Status (c4m_og_status) */
  $handler->display->display_options['filters']['c4m_og_status_value']['id'] = 'c4m_og_status_value';
  $handler->display->display_options['filters']['c4m_og_status_value']['table'] = 'field_data_c4m_og_status';
  $handler->display->display_options['filters']['c4m_og_status_value']['field'] = 'c4m_og_status_value';
  $handler->display->display_options['filters']['c4m_og_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['c4m_og_status_value']['expose']['operator_id'] = 'c4m_og_status_value_op';
  $handler->display->display_options['filters']['c4m_og_status_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['c4m_og_status_value']['expose']['operator'] = 'c4m_og_status_value_op';
  $handler->display->display_options['filters']['c4m_og_status_value']['expose']['identifier'] = 'c4m_og_status_value';
  $handler->display->display_options['filters']['c4m_og_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/c4m/groups';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Groups';
  $handler->display->display_options['menu']['description'] = 'Administration interface to manage groups & their status.';
  $handler->display->display_options['menu']['weight'] = '6';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['c4m_admin_groups'] = $view;

  $view = new view();
  $view->name = 'c4m_admin_groups_export';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Admin : Groups - Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer nodes';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['group_pages']['id'] = 'group_pages';
  $handler->display->display_options['fields']['group_pages']['table'] = 'node';
  $handler->display->display_options['fields']['group_pages']['field'] = 'group_pages';
  $handler->display->display_options['fields']['group_pages']['label'] = 'Group pages';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Node ID';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'URL';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Group visibility */
  $handler->display->display_options['fields']['group_access']['id'] = 'group_access';
  $handler->display->display_options['fields']['group_access']['table'] = 'field_data_group_access';
  $handler->display->display_options['fields']['group_access']['field'] = 'group_access';
  $handler->display->display_options['fields']['group_access']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_access']['settings'] = array(
    'field_name' => '0',
  );
  /* Field: Content: Status */
  $handler->display->display_options['fields']['c4m_og_status']['id'] = 'c4m_og_status';
  $handler->display->display_options['fields']['c4m_og_status']['table'] = 'field_data_c4m_og_status';
  $handler->display->display_options['fields']['c4m_og_status']['field'] = 'c4m_og_status';
  $handler->display->display_options['fields']['c4m_og_status']['label'] = 'Group Status';
  $handler->display->display_options['fields']['c4m_og_status']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Creation date';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m/Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'c4m_long_without_time';
  $handler->display->display_options['fields']['created']['reldate'] = '0';
  /* Field: Content: Group admin */
  $handler->display->display_options['fields']['group_admin']['id'] = 'group_admin';
  $handler->display->display_options['fields']['group_admin']['table'] = 'node';
  $handler->display->display_options['fields']['group_admin']['field'] = 'group_admin';
  $handler->display->display_options['fields']['group_admin']['element_label_colon'] = FALSE;
  /* Field: Content: Group moderators */
  $handler->display->display_options['fields']['group_moderators']['id'] = 'group_moderators';
  $handler->display->display_options['fields']['group_moderators']['table'] = 'node';
  $handler->display->display_options['fields']['group_moderators']['field'] = 'group_moderators';
  $handler->display->display_options['fields']['group_moderators']['label'] = '';
  $handler->display->display_options['fields']['group_moderators']['element_label_colon'] = FALSE;
  /* Field: Content: Related Topics */
  $handler->display->display_options['fields']['c4m_related_topic']['id'] = 'c4m_related_topic';
  $handler->display->display_options['fields']['c4m_related_topic']['table'] = 'field_data_c4m_related_topic';
  $handler->display->display_options['fields']['c4m_related_topic']['field'] = 'c4m_related_topic';
  $handler->display->display_options['fields']['c4m_related_topic']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_related_topic']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['c4m_related_topic']['delta_offset'] = '0';
  /* Field: Field: Regions & Countries */
  $handler->display->display_options['fields']['c4m_vocab_geo']['id'] = 'c4m_vocab_geo';
  $handler->display->display_options['fields']['c4m_vocab_geo']['table'] = 'field_data_c4m_vocab_geo';
  $handler->display->display_options['fields']['c4m_vocab_geo']['field'] = 'c4m_vocab_geo';
  $handler->display->display_options['fields']['c4m_vocab_geo']['label'] = 'Related Regions / Countries';
  $handler->display->display_options['fields']['c4m_vocab_geo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_vocab_geo']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'group' => 'group',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'groups_export');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['path'] = 'admin/c4m/groups/export';
  $export['c4m_admin_groups_export'] = $view;

  return $export;
}
