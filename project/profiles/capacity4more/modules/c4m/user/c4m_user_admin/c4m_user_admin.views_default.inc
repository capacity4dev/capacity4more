<?php
/**
 * @file
 * c4m_user_admin.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function c4m_user_admin_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'c4m_admin_users';
  $view->description = 'List, add, and edit users.';
  $view->tag = 'admin';
  $view->base_table = 'users';
  $view->human_name = 'Admin: Users';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Users';
  $handler->display->display_options['css_class'] = 'admin-views-view';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'menu';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 50;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'uid' => 'uid',
    'name' => 'name',
    'mail' => 'name',
    'c4m_first_name' => 'c4m_first_name',
    'c4m_last_name' => 'c4m_last_name',
    'view_user' => 'view_user',
    'status' => 'status',
    'c4m_is_spammer' => 'c4m_is_spammer',
    'c4m_is_deleted' => 'c4m_is_deleted',
    'rid' => 'rid',
    'created' => 'created',
    'access' => 'access',
    'login' => 'login',
    'edit_node' => 'edit_node',
    'cancel_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'access';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br />',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'c4m_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'c4m_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_user' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'c4m_is_spammer' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'c4m_is_deleted' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'access' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'login' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '&emsp;',
      'empty_column' => 0,
    ),
    'cancel_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = FALSE;
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No users available.';
  /* Field: Bulk operations: User */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['skip_batching'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::c4m_user_admin_activate_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::c4m_user_resend_activation_email_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[c4m_first_name] [c4m_last_name]';
  $handler->display->display_options['fields']['name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = '';
  $handler->display->display_options['fields']['mail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mail']['alter']['text'] = '<a href="user/[uid]">[c4m_first_name] [c4m_last_name]</a>
[mail]';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: User: First Name */
  $handler->display->display_options['fields']['c4m_first_name']['id'] = 'c4m_first_name';
  $handler->display->display_options['fields']['c4m_first_name']['table'] = 'field_data_c4m_first_name';
  $handler->display->display_options['fields']['c4m_first_name']['field'] = 'c4m_first_name';
  $handler->display->display_options['fields']['c4m_first_name']['label'] = '';
  $handler->display->display_options['fields']['c4m_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['c4m_first_name']['element_label_colon'] = FALSE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['c4m_last_name']['id'] = 'c4m_last_name';
  $handler->display->display_options['fields']['c4m_last_name']['table'] = 'field_data_c4m_last_name';
  $handler->display->display_options['fields']['c4m_last_name']['field'] = 'c4m_last_name';
  $handler->display->display_options['fields']['c4m_last_name']['label'] = '';
  $handler->display->display_options['fields']['c4m_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['c4m_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['c4m_last_name']['alter']['text'] = '[c4m_first_name] [c4m_last_name]';
  $handler->display->display_options['fields']['c4m_last_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['c4m_last_name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['c4m_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_last_name']['empty'] = '<a href="user/[uid]">[name]</a>';
  /* Field: User: Link */
  $handler->display->display_options['fields']['view_user']['id'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['table'] = 'users';
  $handler->display->display_options['fields']['view_user']['field'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['label'] = 'Name';
  $handler->display->display_options['fields']['view_user']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_user']['alter']['text'] = '[c4m_last_name]<br>
[name]<br>
[mail]';
  /* Field: User: Is spammer */
  $handler->display->display_options['fields']['c4m_is_spammer']['id'] = 'c4m_is_spammer';
  $handler->display->display_options['fields']['c4m_is_spammer']['table'] = 'field_data_c4m_is_spammer';
  $handler->display->display_options['fields']['c4m_is_spammer']['field'] = 'c4m_is_spammer';
  $handler->display->display_options['fields']['c4m_is_spammer']['label'] = '';
  $handler->display->display_options['fields']['c4m_is_spammer']['exclude'] = TRUE;
  $handler->display->display_options['fields']['c4m_is_spammer']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['c4m_is_spammer']['alter']['text'] = 'Yes';
  $handler->display->display_options['fields']['c4m_is_spammer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_is_spammer']['empty'] = 'No';
  $handler->display->display_options['fields']['c4m_is_spammer']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['c4m_is_spammer']['type'] = 'list_key';
  $handler->display->display_options['fields']['c4m_is_spammer']['settings'] = array(
    'field_name' => '0',
  );
  /* Field: User: Is deleted */
  $handler->display->display_options['fields']['c4m_is_deleted']['id'] = 'c4m_is_deleted';
  $handler->display->display_options['fields']['c4m_is_deleted']['table'] = 'field_data_c4m_is_deleted';
  $handler->display->display_options['fields']['c4m_is_deleted']['field'] = 'c4m_is_deleted';
  $handler->display->display_options['fields']['c4m_is_deleted']['label'] = '';
  $handler->display->display_options['fields']['c4m_is_deleted']['exclude'] = TRUE;
  $handler->display->display_options['fields']['c4m_is_deleted']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['c4m_is_deleted']['alter']['text'] = 'Yes';
  $handler->display->display_options['fields']['c4m_is_deleted']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_is_deleted']['empty'] = 'No';
  $handler->display->display_options['fields']['c4m_is_deleted']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['c4m_is_deleted']['type'] = 'list_key';
  /* Field: User: Active */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['status']['alter']['text'] = 'Active : [status]<br>
Is Spammer : [c4m_is_spammer]<br>
Is Deleted : [c4m_is_deleted]<br>';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['separator'] = '<br>';
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'c4m_long_without_time';
  $handler->display->display_options['fields']['created']['reldate'] = '0';
  /* Field: User: Last access */
  $handler->display->display_options['fields']['access']['id'] = 'access';
  $handler->display->display_options['fields']['access']['table'] = 'users';
  $handler->display->display_options['fields']['access']['field'] = 'access';
  $handler->display->display_options['fields']['access']['label'] = '';
  $handler->display->display_options['fields']['access']['exclude'] = TRUE;
  $handler->display->display_options['fields']['access']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['access']['date_format'] = 'short';
  $handler->display->display_options['fields']['access']['second_date_format'] = 'c4m_long_without_time';
  $handler->display->display_options['fields']['access']['reldate'] = '0';
  /* Field: User: Last login */
  $handler->display->display_options['fields']['login']['id'] = 'login';
  $handler->display->display_options['fields']['login']['table'] = 'users';
  $handler->display->display_options['fields']['login']['field'] = 'login';
  $handler->display->display_options['fields']['login']['label'] = '';
  $handler->display->display_options['fields']['login']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['login']['alter']['text'] = 'Registration : [created]<br>
Last login : [login]<br>
Last access : [access]';
  $handler->display->display_options['fields']['login']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['login']['date_format'] = 'short';
  $handler->display->display_options['fields']['login']['second_date_format'] = 'c4m_long_without_time';
  $handler->display->display_options['fields']['login']['reldate'] = '0';
  /* Field: User: Cancel link */
  $handler->display->display_options['fields']['cancel_node']['id'] = 'cancel_node';
  $handler->display->display_options['fields']['cancel_node']['table'] = 'users';
  $handler->display->display_options['fields']['cancel_node']['field'] = 'cancel_node';
  $handler->display->display_options['fields']['cancel_node']['label'] = '';
  $handler->display->display_options['fields']['cancel_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['cancel_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['cancel_node']['hide_alter_empty'] = FALSE;
  /* Field: User: Activate user link */
  $handler->display->display_options['fields']['activate_user']['id'] = 'activate_user';
  $handler->display->display_options['fields']['activate_user']['table'] = 'users';
  $handler->display->display_options['fields']['activate_user']['field'] = 'activate_user';
  $handler->display->display_options['fields']['activate_user']['label'] = '';
  $handler->display->display_options['fields']['activate_user']['exclude'] = TRUE;
  $handler->display->display_options['fields']['activate_user']['element_label_colon'] = FALSE;
  /* Field: User: Resend activation email link */
  $handler->display->display_options['fields']['resend_activation_email']['id'] = 'resend_activation_email';
  $handler->display->display_options['fields']['resend_activation_email']['table'] = 'users';
  $handler->display->display_options['fields']['resend_activation_email']['field'] = 'resend_activation_email';
  $handler->display->display_options['fields']['resend_activation_email']['label'] = '';
  $handler->display->display_options['fields']['resend_activation_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['resend_activation_email']['element_label_colon'] = FALSE;
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[edit_node] [activate_user] [resend_activation_email] [cancel_node]';
  /* Sort criterion: User: First Name (c4m_first_name) */
  $handler->display->display_options['sorts']['c4m_first_name_value']['id'] = 'c4m_first_name_value';
  $handler->display->display_options['sorts']['c4m_first_name_value']['table'] = 'field_data_c4m_first_name';
  $handler->display->display_options['sorts']['c4m_first_name_value']['field'] = 'c4m_first_name_value';
  $handler->display->display_options['sorts']['c4m_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['c4m_first_name_value']['expose']['label'] = 'First Name';
  /* Sort criterion: User: Last Name (c4m_last_name) */
  $handler->display->display_options['sorts']['c4m_last_name_value']['id'] = 'c4m_last_name_value';
  $handler->display->display_options['sorts']['c4m_last_name_value']['table'] = 'field_data_c4m_last_name';
  $handler->display->display_options['sorts']['c4m_last_name_value']['field'] = 'c4m_last_name_value';
  $handler->display->display_options['sorts']['c4m_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['c4m_last_name_value']['expose']['label'] = 'Last Name';
  /* Sort criterion: User: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['name']['expose']['label'] = 'User Name';
  /* Sort criterion: User: E-mail */
  $handler->display->display_options['sorts']['mail']['id'] = 'mail';
  $handler->display->display_options['sorts']['mail']['table'] = 'users';
  $handler->display->display_options['sorts']['mail']['field'] = 'mail';
  $handler->display->display_options['sorts']['mail']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['mail']['expose']['label'] = 'E-mail';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Registration date';
  /* Sort criterion: User: Last access */
  $handler->display->display_options['sorts']['access']['id'] = 'access';
  $handler->display->display_options['sorts']['access']['table'] = 'users';
  $handler->display->display_options['sorts']['access']['field'] = 'access';
  $handler->display->display_options['sorts']['access']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['access']['expose']['label'] = 'Last access';
  /* Sort criterion: User: Last login */
  $handler->display->display_options['sorts']['login']['id'] = 'login';
  $handler->display->display_options['sorts']['login']['table'] = 'users';
  $handler->display->display_options['sorts']['login']['field'] = 'login';
  $handler->display->display_options['sorts']['login']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['login']['expose']['label'] = 'Last login';
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['operator'] = 'not in';
  $handler->display->display_options['filters']['uid']['value'] = array(
    0 => 0,
  );
  $handler->display->display_options['filters']['uid']['group'] = 1;
  /* Filter criterion: User: First Name (c4m_first_name) */
  $handler->display->display_options['filters']['c4m_first_name_value']['id'] = 'c4m_first_name_value';
  $handler->display->display_options['filters']['c4m_first_name_value']['table'] = 'field_data_c4m_first_name';
  $handler->display->display_options['filters']['c4m_first_name_value']['field'] = 'c4m_first_name_value';
  $handler->display->display_options['filters']['c4m_first_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['c4m_first_name_value']['group'] = 1;
  $handler->display->display_options['filters']['c4m_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['c4m_first_name_value']['expose']['operator_id'] = 'c4m_first_name_value_op';
  $handler->display->display_options['filters']['c4m_first_name_value']['expose']['label'] = 'First Name';
  $handler->display->display_options['filters']['c4m_first_name_value']['expose']['operator'] = 'c4m_first_name_value_op';
  $handler->display->display_options['filters']['c4m_first_name_value']['expose']['identifier'] = 'firstname';
  $handler->display->display_options['filters']['c4m_first_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: User: Last Name (c4m_last_name) */
  $handler->display->display_options['filters']['c4m_last_name_value']['id'] = 'c4m_last_name_value';
  $handler->display->display_options['filters']['c4m_last_name_value']['table'] = 'field_data_c4m_last_name';
  $handler->display->display_options['filters']['c4m_last_name_value']['field'] = 'c4m_last_name_value';
  $handler->display->display_options['filters']['c4m_last_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['c4m_last_name_value']['group'] = 1;
  $handler->display->display_options['filters']['c4m_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['c4m_last_name_value']['expose']['operator_id'] = 'c4m_last_name_value_op';
  $handler->display->display_options['filters']['c4m_last_name_value']['expose']['label'] = 'Last Name';
  $handler->display->display_options['filters']['c4m_last_name_value']['expose']['operator'] = 'c4m_last_name_value_op';
  $handler->display->display_options['filters']['c4m_last_name_value']['expose']['identifier'] = 'lastname';
  $handler->display->display_options['filters']['c4m_last_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: User: Name (raw) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Username';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'username';
  $handler->display->display_options['filters']['name']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['operator'] = 'contains';
  $handler->display->display_options['filters']['mail']['group'] = 1;
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'email';
  $handler->display->display_options['filters']['mail']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Active';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'active';
  $handler->display->display_options['filters']['status']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: User: Is spammer (c4m_is_spammer) */
  $handler->display->display_options['filters']['c4m_is_spammer_value']['id'] = 'c4m_is_spammer_value';
  $handler->display->display_options['filters']['c4m_is_spammer_value']['table'] = 'field_data_c4m_is_spammer';
  $handler->display->display_options['filters']['c4m_is_spammer_value']['field'] = 'c4m_is_spammer_value';
  $handler->display->display_options['filters']['c4m_is_spammer_value']['group'] = 1;
  $handler->display->display_options['filters']['c4m_is_spammer_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['c4m_is_spammer_value']['expose']['operator_id'] = 'c4m_is_spammer_value_op';
  $handler->display->display_options['filters']['c4m_is_spammer_value']['expose']['label'] = 'Spammer';
  $handler->display->display_options['filters']['c4m_is_spammer_value']['expose']['operator'] = 'c4m_is_spammer_value_op';
  $handler->display->display_options['filters']['c4m_is_spammer_value']['expose']['identifier'] = 'spammer';
  $handler->display->display_options['filters']['c4m_is_spammer_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: User: Is deleted (c4m_is_deleted) */
  $handler->display->display_options['filters']['c4m_is_deleted_value']['id'] = 'c4m_is_deleted_value';
  $handler->display->display_options['filters']['c4m_is_deleted_value']['table'] = 'field_data_c4m_is_deleted';
  $handler->display->display_options['filters']['c4m_is_deleted_value']['field'] = 'c4m_is_deleted_value';
  $handler->display->display_options['filters']['c4m_is_deleted_value']['group'] = 1;
  $handler->display->display_options['filters']['c4m_is_deleted_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['c4m_is_deleted_value']['expose']['operator_id'] = 'c4m_is_deleted_value_op';
  $handler->display->display_options['filters']['c4m_is_deleted_value']['expose']['label'] = 'Deleted';
  $handler->display->display_options['filters']['c4m_is_deleted_value']['expose']['operator'] = 'c4m_is_deleted_value_op';
  $handler->display->display_options['filters']['c4m_is_deleted_value']['expose']['identifier'] = 'deleted';
  $handler->display->display_options['filters']['c4m_is_deleted_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['group'] = 1;
  $handler->display->display_options['filters']['rid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['rid']['expose']['operator_id'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['label'] = 'Role';
  $handler->display->display_options['filters']['rid']['expose']['operator'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['identifier'] = 'roles';
  $handler->display->display_options['filters']['rid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['rid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: System */
  $handler = $view->new_display('system', 'System', 'system_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['hide_admin_links'] = TRUE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['path'] = 'admin/people';
  $export['c4m_admin_users'] = $view;

  return $export;
}
