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
  $view->tag = 'C4M Admin';
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
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Merge';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'Merge';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'node/[nid]/merge';
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = TRUE;
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
  $handler->display->display_options['path'] = 'admin/c4m/groups/overview';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Overview';
  $handler->display->display_options['menu']['description'] = 'Administration interface to manage groups & their status.';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['c4m_admin_groups'] = $view;

  $view = new view();
  $view->name = 'c4m_admin_groups_export';
  $view->description = '';
  $view->tag = 'C4M Admin';
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
  /* Relationship: Flags: subscribe_c4m_follow_group counter */
  $handler->display->display_options['relationships']['flag_count_rel']['id'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_count_rel']['field'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['label'] = 'follow_group';
  $handler->display->display_options['relationships']['flag_count_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_count_rel']['flag'] = 'subscribe_c4m_follow_group';
  /* Relationship: Flags: c4m_og_content_recommend counter */
  $handler->display->display_options['relationships']['flag_count_rel_1']['id'] = 'flag_count_rel_1';
  $handler->display->display_options['relationships']['flag_count_rel_1']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_count_rel_1']['field'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel_1']['label'] = 'flag_recommendation_counter';
  $handler->display->display_options['relationships']['flag_count_rel_1']['required'] = 0;
  $handler->display->display_options['relationships']['flag_count_rel_1']['flag'] = 'c4m_og_content_recommend';
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
  $handler->display->display_options['fields']['title']['label'] = 'Group Title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: PURL path */
  $handler->display->display_options['fields']['group_purl']['id'] = 'group_purl';
  $handler->display->display_options['fields']['group_purl']['table'] = 'node';
  $handler->display->display_options['fields']['group_purl']['field'] = 'group_purl';
  $handler->display->display_options['fields']['group_purl']['label'] = 'URL';
  $handler->display->display_options['fields']['group_purl']['element_label_colon'] = FALSE;
  /* Field: Content: Group visibility */
  $handler->display->display_options['fields']['group_visibility']['id'] = 'group_visibility';
  $handler->display->display_options['fields']['group_visibility']['table'] = 'node';
  $handler->display->display_options['fields']['group_visibility']['field'] = 'group_visibility';
  $handler->display->display_options['fields']['group_visibility']['element_label_colon'] = FALSE;
  /* Field: Content: Group domains */
  $handler->display->display_options['fields']['group_domains']['id'] = 'group_domains';
  $handler->display->display_options['fields']['group_domains']['table'] = 'node';
  $handler->display->display_options['fields']['group_domains']['field'] = 'group_domains';
  $handler->display->display_options['fields']['group_domains']['element_label_colon'] = FALSE;
  /* Field: Content: Group organisations */
  $handler->display->display_options['fields']['group_organisations']['id'] = 'group_organisations';
  $handler->display->display_options['fields']['group_organisations']['table'] = 'node';
  $handler->display->display_options['fields']['group_organisations']['field'] = 'group_organisations';
  $handler->display->display_options['fields']['group_organisations']['element_label_colon'] = FALSE;
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
  /* Field: Content: Group metrics */
  $handler->display->display_options['fields']['group_metrics_12']['id'] = 'group_metrics_12';
  $handler->display->display_options['fields']['group_metrics_12']['table'] = 'node';
  $handler->display->display_options['fields']['group_metrics_12']['field'] = 'group_metrics';
  $handler->display->display_options['fields']['group_metrics_12']['label'] = 'Date of latest activity';
  $handler->display->display_options['fields']['group_metrics_12']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_metrics_12']['c4m_admin_groups_group_metric'] = 'group::latest_activity';
  /* Field: Content: Group admin */
  $handler->display->display_options['fields']['group_admin']['id'] = 'group_admin';
  $handler->display->display_options['fields']['group_admin']['table'] = 'node';
  $handler->display->display_options['fields']['group_admin']['field'] = 'group_admin';
  $handler->display->display_options['fields']['group_admin']['label'] = 'Group owner';
  $handler->display->display_options['fields']['group_admin']['element_label_colon'] = FALSE;
  /* Field: Content: Group moderators */
  $handler->display->display_options['fields']['group_moderators']['id'] = 'group_moderators';
  $handler->display->display_options['fields']['group_moderators']['table'] = 'node';
  $handler->display->display_options['fields']['group_moderators']['field'] = 'group_moderators';
  $handler->display->display_options['fields']['group_moderators']['label'] = 'Group moderator(s)';
  $handler->display->display_options['fields']['group_moderators']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_moderators']['c4m_admin_groups_group_type'] = 'group';
  /* Field: Content: Group metrics */
  $handler->display->display_options['fields']['group_metrics']['id'] = 'group_metrics';
  $handler->display->display_options['fields']['group_metrics']['table'] = 'node';
  $handler->display->display_options['fields']['group_metrics']['field'] = 'group_metrics';
  $handler->display->display_options['fields']['group_metrics']['label'] = 'Members';
  $handler->display->display_options['fields']['group_metrics']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_metrics']['c4m_admin_groups_group_metric'] = 'group::users';
  /* Field: Content: Group metrics */
  $handler->display->display_options['fields']['group_metrics_10']['id'] = 'group_metrics_10';
  $handler->display->display_options['fields']['group_metrics_10']['table'] = 'node';
  $handler->display->display_options['fields']['group_metrics_10']['field'] = 'group_metrics';
  $handler->display->display_options['fields']['group_metrics_10']['label'] = 'Pending members';
  $handler->display->display_options['fields']['group_metrics_10']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_metrics_10']['c4m_admin_groups_group_metric'] = 'group::pending_members';
  /* Field: Content: Group metrics */
  $handler->display->display_options['fields']['group_metrics_1']['id'] = 'group_metrics_1';
  $handler->display->display_options['fields']['group_metrics_1']['table'] = 'node';
  $handler->display->display_options['fields']['group_metrics_1']['field'] = 'group_metrics';
  $handler->display->display_options['fields']['group_metrics_1']['label'] = 'Pages';
  $handler->display->display_options['fields']['group_metrics_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_metrics_1']['c4m_admin_groups_group_metric'] = 'group::wiki_page';
  /* Field: Content: Group metrics */
  $handler->display->display_options['fields']['group_metrics_2']['id'] = 'group_metrics_2';
  $handler->display->display_options['fields']['group_metrics_2']['table'] = 'node';
  $handler->display->display_options['fields']['group_metrics_2']['field'] = 'group_metrics';
  $handler->display->display_options['fields']['group_metrics_2']['label'] = 'Documents';
  $handler->display->display_options['fields']['group_metrics_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_metrics_2']['c4m_admin_groups_group_metric'] = 'group::document';
  /* Field: Content: Group metrics */
  $handler->display->display_options['fields']['group_metrics_3']['id'] = 'group_metrics_3';
  $handler->display->display_options['fields']['group_metrics_3']['table'] = 'node';
  $handler->display->display_options['fields']['group_metrics_3']['field'] = 'group_metrics';
  $handler->display->display_options['fields']['group_metrics_3']['label'] = 'Discussions';
  $handler->display->display_options['fields']['group_metrics_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_metrics_3']['c4m_admin_groups_group_metric'] = 'group::discussion';
  /* Field: Content: Group metrics */
  $handler->display->display_options['fields']['group_metrics_4']['id'] = 'group_metrics_4';
  $handler->display->display_options['fields']['group_metrics_4']['table'] = 'node';
  $handler->display->display_options['fields']['group_metrics_4']['field'] = 'group_metrics';
  $handler->display->display_options['fields']['group_metrics_4']['label'] = 'Events';
  $handler->display->display_options['fields']['group_metrics_4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_metrics_4']['c4m_admin_groups_group_metric'] = 'group::event';
  /* Field: Content: Group metrics */
  $handler->display->display_options['fields']['group_metrics_6']['id'] = 'group_metrics_6';
  $handler->display->display_options['fields']['group_metrics_6']['table'] = 'node';
  $handler->display->display_options['fields']['group_metrics_6']['field'] = 'group_metrics';
  $handler->display->display_options['fields']['group_metrics_6']['label'] = 'Photo albums';
  $handler->display->display_options['fields']['group_metrics_6']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_metrics_6']['c4m_admin_groups_group_metric'] = 'group::photoalbum';
  /* Field: Content: Group metrics */
  $handler->display->display_options['fields']['group_metrics_7']['id'] = 'group_metrics_7';
  $handler->display->display_options['fields']['group_metrics_7']['table'] = 'node';
  $handler->display->display_options['fields']['group_metrics_7']['field'] = 'group_metrics';
  $handler->display->display_options['fields']['group_metrics_7']['label'] = 'Photos';
  $handler->display->display_options['fields']['group_metrics_7']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_metrics_7']['c4m_admin_groups_group_metric'] = 'group::photo';
  /* Field: Content: Group metrics */
  $handler->display->display_options['fields']['group_metrics_8']['id'] = 'group_metrics_8';
  $handler->display->display_options['fields']['group_metrics_8']['table'] = 'node';
  $handler->display->display_options['fields']['group_metrics_8']['field'] = 'group_metrics';
  $handler->display->display_options['fields']['group_metrics_8']['label'] = 'Document downloads';
  $handler->display->display_options['fields']['group_metrics_8']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_metrics_8']['c4m_admin_groups_group_metric'] = 'group::document_download';
  /* Field: Content: Group metrics */
  $handler->display->display_options['fields']['group_metrics_14']['id'] = 'group_metrics_14';
  $handler->display->display_options['fields']['group_metrics_14']['table'] = 'node';
  $handler->display->display_options['fields']['group_metrics_14']['field'] = 'group_metrics';
  $handler->display->display_options['fields']['group_metrics_14']['label'] = 'Shared content';
  $handler->display->display_options['fields']['group_metrics_14']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_metrics_14']['c4m_admin_groups_group_metric'] = 'group::shared_content';
  /* Field: Content: Group metrics */
  $handler->display->display_options['fields']['group_metrics_5']['id'] = 'group_metrics_5';
  $handler->display->display_options['fields']['group_metrics_5']['table'] = 'node';
  $handler->display->display_options['fields']['group_metrics_5']['field'] = 'group_metrics';
  $handler->display->display_options['fields']['group_metrics_5']['label'] = 'Comments';
  $handler->display->display_options['fields']['group_metrics_5']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_metrics_5']['c4m_admin_groups_group_metric'] = 'group::comment';
  /* Field: Content: Group metrics */
  $handler->display->display_options['fields']['group_metrics_9']['id'] = 'group_metrics_9';
  $handler->display->display_options['fields']['group_metrics_9']['table'] = 'node';
  $handler->display->display_options['fields']['group_metrics_9']['field'] = 'group_metrics';
  $handler->display->display_options['fields']['group_metrics_9']['label'] = 'Contributors';
  $handler->display->display_options['fields']['group_metrics_9']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_metrics_9']['c4m_admin_groups_group_metric'] = 'group::contributors';
  /* Field: Flags: Flag counter */
  $handler->display->display_options['fields']['count']['id'] = 'count';
  $handler->display->display_options['fields']['count']['table'] = 'flag_counts';
  $handler->display->display_options['fields']['count']['field'] = 'count';
  $handler->display->display_options['fields']['count']['relationship'] = 'flag_count_rel';
  $handler->display->display_options['fields']['count']['label'] = 'Group Notification Subscriptions';
  $handler->display->display_options['fields']['count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['count']['separator'] = '';
  /* Field: Flags: Flag counter */
  $handler->display->display_options['fields']['count_1']['id'] = 'count_1';
  $handler->display->display_options['fields']['count_1']['table'] = 'flag_counts';
  $handler->display->display_options['fields']['count_1']['field'] = 'count';
  $handler->display->display_options['fields']['count_1']['relationship'] = 'flag_count_rel_1';
  $handler->display->display_options['fields']['count_1']['label'] = 'Group Recommendations';
  $handler->display->display_options['fields']['count_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['count_1']['separator'] = '';
  /* Field: Content: Group metrics */
  $handler->display->display_options['fields']['group_metrics_11']['id'] = 'group_metrics_11';
  $handler->display->display_options['fields']['group_metrics_11']['table'] = 'node';
  $handler->display->display_options['fields']['group_metrics_11']['field'] = 'group_metrics';
  $handler->display->display_options['fields']['group_metrics_11']['label'] = 'Content follows';
  $handler->display->display_options['fields']['group_metrics_11']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_metrics_11']['c4m_admin_groups_group_metric'] = 'group::content_follows';
  /* Field: Content: Group metrics */
  $handler->display->display_options['fields']['group_metrics_13']['id'] = 'group_metrics_13';
  $handler->display->display_options['fields']['group_metrics_13']['table'] = 'node';
  $handler->display->display_options['fields']['group_metrics_13']['field'] = 'group_metrics';
  $handler->display->display_options['fields']['group_metrics_13']['label'] = 'Content Recommendations';
  $handler->display->display_options['fields']['group_metrics_13']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_metrics_13']['c4m_admin_groups_group_metric'] = 'group::content_recommendations';
  /* Field: Field: Topics */
  $handler->display->display_options['fields']['c4m_vocab_topic']['id'] = 'c4m_vocab_topic';
  $handler->display->display_options['fields']['c4m_vocab_topic']['table'] = 'field_data_c4m_vocab_topic';
  $handler->display->display_options['fields']['c4m_vocab_topic']['field'] = 'c4m_vocab_topic';
  $handler->display->display_options['fields']['c4m_vocab_topic']['label'] = 'Related Topics';
  $handler->display->display_options['fields']['c4m_vocab_topic']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_vocab_topic']['type'] = 'term_reference_checked_inline_tree_for_views';
  $handler->display->display_options['fields']['c4m_vocab_topic']['settings'] = array(
    'link' => 0,
    'separator' => ' > ',
    'glue' => ' - ',
  );
  $handler->display->display_options['fields']['c4m_vocab_topic']['delta_offset'] = '0';
  /* Field: Field: Regions & Countries */
  $handler->display->display_options['fields']['c4m_vocab_geo']['id'] = 'c4m_vocab_geo';
  $handler->display->display_options['fields']['c4m_vocab_geo']['table'] = 'field_data_c4m_vocab_geo';
  $handler->display->display_options['fields']['c4m_vocab_geo']['field'] = 'c4m_vocab_geo';
  $handler->display->display_options['fields']['c4m_vocab_geo']['label'] = 'Related Regions / Countries';
  $handler->display->display_options['fields']['c4m_vocab_geo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_vocab_geo']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['c4m_vocab_geo']['type'] = 'term_reference_checked_inline_tree_for_views';
  $handler->display->display_options['fields']['c4m_vocab_geo']['settings'] = array(
    'link' => 0,
    'separator' => ' > ',
    'glue' => ' - ',
  );
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
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['permanent_file'] = 1;
  $handler->display->display_options['style_options']['file_path'] = 'private://export/groups.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['separator'] = '|';
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['path'] = 'admin/c4m/groups/export/file';
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'admin/c4m/groups/export';
  $handler->display->display_options['segment_size'] = '100';
  $export['c4m_admin_groups_export'] = $view;

  $view = new view();
  $view->name = 'c4m_admin_groups_pending';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Admin : Groups - Pending';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Pending';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer nodes';
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
    'title' => 'title',
    'group_visibility' => 'group_visibility',
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
    'group_visibility' => array(
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
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No pending groups';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no groups pending for approval.';
  $handler->display->display_options['empty']['area']['format'] = 'mail';
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
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Group visibility */
  $handler->display->display_options['fields']['group_visibility']['id'] = 'group_visibility';
  $handler->display->display_options['fields']['group_visibility']['table'] = 'node';
  $handler->display->display_options['fields']['group_visibility']['field'] = 'group_visibility';
  $handler->display->display_options['fields']['group_visibility']['label'] = 'Visibility';
  $handler->display->display_options['fields']['group_visibility']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Owner';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'c4m_long_without_time';
  $handler->display->display_options['fields']['created']['reldate'] = '0';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Group approve link */
  $handler->display->display_options['fields']['group_approve']['id'] = 'group_approve';
  $handler->display->display_options['fields']['group_approve']['table'] = 'node';
  $handler->display->display_options['fields']['group_approve']['field'] = 'group_approve';
  $handler->display->display_options['fields']['group_approve']['label'] = '';
  $handler->display->display_options['fields']['group_approve']['exclude'] = TRUE;
  $handler->display->display_options['fields']['group_approve']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Actions';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[group_approve] or [edit_node]';
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'group' => 'group',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Status (c4m_og_status) */
  $handler->display->display_options['filters']['c4m_og_status_value']['id'] = 'c4m_og_status_value';
  $handler->display->display_options['filters']['c4m_og_status_value']['table'] = 'field_data_c4m_og_status';
  $handler->display->display_options['filters']['c4m_og_status_value']['field'] = 'c4m_og_status_value';
  $handler->display->display_options['filters']['c4m_og_status_value']['value'] = array(
    'pending' => 'pending',
  );
  $handler->display->display_options['filters']['c4m_og_status_value']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/c4m/groups/pending';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Pending';
  $handler->display->display_options['menu']['description'] = 'Administration interface to manage pending groups.';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['c4m_admin_groups_pending'] = $view;

  return $export;
}
