<?php
/**
 * @file
 * c4m_admin_projects.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function c4m_admin_projects_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'c4m_admin_projects_export';
  $view->description = '';
  $view->tag = 'C4M Admin';
  $view->base_table = 'node';
  $view->human_name = 'Admin : Projects - Export';
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
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'URL';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
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
  /* Field: Content: Duration */
  $handler->display->display_options['fields']['c4m_date_end']['id'] = 'c4m_date_end';
  $handler->display->display_options['fields']['c4m_date_end']['table'] = 'field_data_c4m_date_end';
  $handler->display->display_options['fields']['c4m_date_end']['field'] = 'c4m_date_end';
  $handler->display->display_options['fields']['c4m_date_end']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_date_end']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Total budget */
  $handler->display->display_options['fields']['c4m_money']['id'] = 'c4m_money';
  $handler->display->display_options['fields']['c4m_money']['table'] = 'field_data_c4m_money';
  $handler->display->display_options['fields']['c4m_money']['field'] = 'c4m_money';
  $handler->display->display_options['fields']['c4m_money']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_money']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['c4m_money']['type'] = 'c4m_formatter_ec_money';
  /* Field: Content: Source of funding */
  $handler->display->display_options['fields']['c4m_source_of_funding']['id'] = 'c4m_source_of_funding';
  $handler->display->display_options['fields']['c4m_source_of_funding']['table'] = 'field_data_c4m_source_of_funding';
  $handler->display->display_options['fields']['c4m_source_of_funding']['field'] = 'c4m_source_of_funding';
  $handler->display->display_options['fields']['c4m_source_of_funding']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_source_of_funding']['delta_offset'] = '0';
  /* Field: Content: Partners */
  $handler->display->display_options['fields']['c4m_partner']['id'] = 'c4m_partner';
  $handler->display->display_options['fields']['c4m_partner']['table'] = 'field_data_c4m_partner';
  $handler->display->display_options['fields']['c4m_partner']['field'] = 'c4m_partner';
  $handler->display->display_options['fields']['c4m_partner']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_partner']['delta_offset'] = '0';
  /* Field: Content: Implemented by */
  $handler->display->display_options['fields']['c4m_implemented_by']['id'] = 'c4m_implemented_by';
  $handler->display->display_options['fields']['c4m_implemented_by']['table'] = 'field_data_c4m_implemented_by';
  $handler->display->display_options['fields']['c4m_implemented_by']['field'] = 'c4m_implemented_by';
  $handler->display->display_options['fields']['c4m_implemented_by']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_implemented_by']['delta_offset'] = '0';
  /* Field: Content: CRIS Decision number */
  $handler->display->display_options['fields']['c4m_cris_decision_number']['id'] = 'c4m_cris_decision_number';
  $handler->display->display_options['fields']['c4m_cris_decision_number']['table'] = 'field_data_c4m_cris_decision_number';
  $handler->display->display_options['fields']['c4m_cris_decision_number']['field'] = 'c4m_cris_decision_number';
  $handler->display->display_options['fields']['c4m_cris_decision_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_cris_decision_number']['delta_offset'] = '0';
  /* Field: Content: CRIS Contract Number */
  $handler->display->display_options['fields']['c4m_cris_contract_number']['id'] = 'c4m_cris_contract_number';
  $handler->display->display_options['fields']['c4m_cris_contract_number']['table'] = 'field_data_c4m_cris_contract_number';
  $handler->display->display_options['fields']['c4m_cris_contract_number']['field'] = 'c4m_cris_contract_number';
  $handler->display->display_options['fields']['c4m_cris_contract_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_cris_contract_number']['delta_offset'] = '0';
  /* Field: Field: Topics */
  $handler->display->display_options['fields']['c4m_vocab_topic']['id'] = 'c4m_vocab_topic';
  $handler->display->display_options['fields']['c4m_vocab_topic']['table'] = 'field_data_c4m_vocab_topic';
  $handler->display->display_options['fields']['c4m_vocab_topic']['field'] = 'c4m_vocab_topic';
  $handler->display->display_options['fields']['c4m_vocab_topic']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_vocab_topic']['type'] = 'term_reference_checked_inline_tree';
  $handler->display->display_options['fields']['c4m_vocab_topic']['settings'] = array(
    'link' => 0,
    'separator' => ' > ',
    'glue' => ', ',
  );
  $handler->display->display_options['fields']['c4m_vocab_topic']['delta_offset'] = '0';
  /* Field: Field: Regions & Countries */
  $handler->display->display_options['fields']['c4m_vocab_geo']['id'] = 'c4m_vocab_geo';
  $handler->display->display_options['fields']['c4m_vocab_geo']['table'] = 'field_data_c4m_vocab_geo';
  $handler->display->display_options['fields']['c4m_vocab_geo']['field'] = 'c4m_vocab_geo';
  $handler->display->display_options['fields']['c4m_vocab_geo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_vocab_geo']['type'] = 'term_reference_checked_inline_tree';
  $handler->display->display_options['fields']['c4m_vocab_geo']['settings'] = array(
    'link' => 0,
    'separator' => ' > ',
    'glue' => ', ',
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
    'project' => 'project',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'projects_export');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['permanent_file'] = 1;
  $handler->display->display_options['style_options']['file_path'] = 'private://export/projects.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['separator'] = '|';
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['path'] = 'admin/c4m/projects/export/file';
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'admin/c4m/projects/export';
  $handler->display->display_options['segment_size'] = '100';
  $export['c4m_admin_projects_export'] = $view;

  $view = new view();
  $view->name = 'c4m_admin_projects_pending';
  $view->description = '';
  $view->tag = 'C4M Admin';
  $view->base_table = 'node';
  $view->human_name = 'Admin : Projects - Pending';
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
  $handler->display->display_options['empty']['area']['label'] = 'No pending projects';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no projects pending for approval.';
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
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '0';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Status (c4m_og_status) */
  $handler->display->display_options['filters']['c4m_og_status_value']['id'] = 'c4m_og_status_value';
  $handler->display->display_options['filters']['c4m_og_status_value']['table'] = 'field_data_c4m_og_status';
  $handler->display->display_options['filters']['c4m_og_status_value']['field'] = 'c4m_og_status_value';
  $handler->display->display_options['filters']['c4m_og_status_value']['value'] = array(
    'requested' => 'requested',
  );
  $handler->display->display_options['filters']['c4m_og_status_value']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/c4m/projects/pending';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Pending';
  $handler->display->display_options['menu']['description'] = 'Administration interface to manage pending projects.';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['c4m_admin_projects_pending'] = $view;

  return $export;
}
