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
    'c4m_is_deleted_anonymous' => 'c4m_is_deleted_anonymous',
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
    'c4m_is_deleted_anonymous' => array(
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
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_user';
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
    'action::c4m_user_admin_resend_activation_email_action' => array(
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
  /* Field: User: Is deleted anonymous */
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['id'] = 'c4m_is_deleted_anonymous';
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['table'] = 'field_data_c4m_is_deleted_anonymous';
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['field'] = 'c4m_is_deleted_anonymous';
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['label'] = '';
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['exclude'] = TRUE;
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['alter']['text'] = 'Yes';
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['empty'] = 'No';
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['type'] = 'list_key';
  /* Field: User: Active */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['status']['alter']['text'] = 'Active : [status]<br>
Is Spammer : [c4m_is_spammer]<br>
Is Deleted : [c4m_is_deleted]<br>
Is Deleted Anonymous : [c4m_is_deleted_anonymous]<br>';
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
  $handler->display->display_options['fields']['cancel_node']['text'] = 'Cancel account / Mark as spammer';
  /* Field: User: Activate user link */
  $handler->display->display_options['fields']['activate_user']['id'] = 'activate_user';
  $handler->display->display_options['fields']['activate_user']['table'] = 'users';
  $handler->display->display_options['fields']['activate_user']['field'] = 'activate_user';
  $handler->display->display_options['fields']['activate_user']['label'] = '';
  $handler->display->display_options['fields']['activate_user']['exclude'] = TRUE;
  $handler->display->display_options['fields']['activate_user']['element_label_colon'] = FALSE;
  /* Field: User: Reactivate user link */
  $handler->display->display_options['fields']['reactivate_user']['id'] = 'reactivate_user';
  $handler->display->display_options['fields']['reactivate_user']['table'] = 'users';
  $handler->display->display_options['fields']['reactivate_user']['field'] = 'reactivate_user';
  $handler->display->display_options['fields']['reactivate_user']['label'] = '';
  $handler->display->display_options['fields']['reactivate_user']['exclude'] = TRUE;
  $handler->display->display_options['fields']['reactivate_user']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[edit_node] [activate_user] [reactivate_user] [resend_activation_email] [cancel_node]';
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
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
  /* Filter criterion: User: Is deleted anonymous (c4m_is_deleted_anonymous) */
  $handler->display->display_options['filters']['c4m_is_deleted_anonymous_value']['id'] = 'c4m_is_deleted_anonymous_value';
  $handler->display->display_options['filters']['c4m_is_deleted_anonymous_value']['table'] = 'field_data_c4m_is_deleted_anonymous';
  $handler->display->display_options['filters']['c4m_is_deleted_anonymous_value']['field'] = 'c4m_is_deleted_anonymous_value';
  $handler->display->display_options['filters']['c4m_is_deleted_anonymous_value']['group'] = 1;
  $handler->display->display_options['filters']['c4m_is_deleted_anonymous_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['c4m_is_deleted_anonymous_value']['expose']['operator_id'] = 'c4m_is_deleted_anonymous_value_op';
  $handler->display->display_options['filters']['c4m_is_deleted_anonymous_value']['expose']['label'] = 'Deleted Anonymous';
  $handler->display->display_options['filters']['c4m_is_deleted_anonymous_value']['expose']['operator'] = 'c4m_is_deleted_anonymous_value_op';
  $handler->display->display_options['filters']['c4m_is_deleted_anonymous_value']['expose']['identifier'] = 'deleted_anonymous';
  $handler->display->display_options['filters']['c4m_is_deleted_anonymous_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: User */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_user';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
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
    'action::views_bulk_operations_user_cancel_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::c4m_user_contact_action' => array(
      'selected' => 1,
      'postpone_processing' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::c4m_user_admin_resend_activation_email_action' => array(
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
  /* Field: User: Country */
  $handler->display->display_options['fields']['c4m_country']['id'] = 'c4m_country';
  $handler->display->display_options['fields']['c4m_country']['table'] = 'field_data_c4m_country';
  $handler->display->display_options['fields']['c4m_country']['field'] = 'c4m_country';
  $handler->display->display_options['fields']['c4m_country']['label'] = '';
  $handler->display->display_options['fields']['c4m_country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['c4m_country']['element_label_colon'] = FALSE;
  /* Field: Name */
  $handler->display->display_options['fields']['view_user']['id'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['table'] = 'users';
  $handler->display->display_options['fields']['view_user']['field'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['ui_name'] = 'Name';
  $handler->display->display_options['fields']['view_user']['label'] = 'Name';
  $handler->display->display_options['fields']['view_user']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_user']['alter']['text'] = '[c4m_last_name]<br />
[name]<br />
[mail]<br />
[c4m_country]';
  /* Field: User: Organisation */
  $handler->display->display_options['fields']['c4m_organisation']['id'] = 'c4m_organisation';
  $handler->display->display_options['fields']['c4m_organisation']['table'] = 'field_data_c4m_organisation';
  $handler->display->display_options['fields']['c4m_organisation']['field'] = 'c4m_organisation';
  $handler->display->display_options['fields']['c4m_organisation']['label'] = '';
  $handler->display->display_options['fields']['c4m_organisation']['exclude'] = TRUE;
  $handler->display->display_options['fields']['c4m_organisation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_organisation']['element_default_classes'] = FALSE;
  /* Field: Organisation info */
  $handler->display->display_options['fields']['c4m_organisation_type']['id'] = 'c4m_organisation_type';
  $handler->display->display_options['fields']['c4m_organisation_type']['table'] = 'field_data_c4m_organisation_type';
  $handler->display->display_options['fields']['c4m_organisation_type']['field'] = 'c4m_organisation_type';
  $handler->display->display_options['fields']['c4m_organisation_type']['ui_name'] = 'Organisation info';
  $handler->display->display_options['fields']['c4m_organisation_type']['label'] = 'Organisation';
  $handler->display->display_options['fields']['c4m_organisation_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['c4m_organisation_type']['alter']['text'] = '[c4m_organisation]<br />
[c4m_organisation_type]';
  $handler->display->display_options['fields']['c4m_organisation_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_organisation_type']['element_default_classes'] = FALSE;
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
  /* Field: User: Is deleted anonymous */
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['id'] = 'c4m_is_deleted_anonymous';
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['table'] = 'field_data_c4m_is_deleted_anonymous';
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['field'] = 'c4m_is_deleted_anonymous';
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['label'] = '';
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['exclude'] = TRUE;
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['alter']['text'] = 'Yes';
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['empty'] = 'No';
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['type'] = 'list_key';
  /* Field: User: Is deleted by */
  $handler->display->display_options['fields']['c4m_is_deleted_by_uid']['id'] = 'c4m_is_deleted_by_uid';
  $handler->display->display_options['fields']['c4m_is_deleted_by_uid']['table'] = 'field_data_c4m_is_deleted_by_uid';
  $handler->display->display_options['fields']['c4m_is_deleted_by_uid']['field'] = 'c4m_is_deleted_by_uid';
  $handler->display->display_options['fields']['c4m_is_deleted_by_uid']['label'] = 'Deleted by';
  $handler->display->display_options['fields']['c4m_is_deleted_by_uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['c4m_is_deleted_by_uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['c4m_is_deleted_by_uid']['alter']['text'] = 'Deleted by: [c4m_is_deleted_by_uid]';
  $handler->display->display_options['fields']['c4m_is_deleted_by_uid']['settings'] = array(
    'link' => 1,
  );
  /* Field: User: Active */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['status']['alter']['text'] = 'Active : [status]<br>
Is Spammer : [c4m_is_spammer]<br>
Is Deleted : [c4m_is_deleted]<br>
Is Deleted Anonymous: [c4m_is_deleted_anonymous]<br>
[c4m_is_deleted_by_uid]<br>';
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
  $handler->display->display_options['fields']['cancel_node']['text'] = 'Cancel account / Mark as spammer';
  /* Field: User: Activate user link */
  $handler->display->display_options['fields']['activate_user']['id'] = 'activate_user';
  $handler->display->display_options['fields']['activate_user']['table'] = 'users';
  $handler->display->display_options['fields']['activate_user']['field'] = 'activate_user';
  $handler->display->display_options['fields']['activate_user']['label'] = '';
  $handler->display->display_options['fields']['activate_user']['exclude'] = TRUE;
  $handler->display->display_options['fields']['activate_user']['element_label_colon'] = FALSE;
  /* Field: User: Reactivate user link */
  $handler->display->display_options['fields']['reactivate_user']['id'] = 'reactivate_user';
  $handler->display->display_options['fields']['reactivate_user']['table'] = 'users';
  $handler->display->display_options['fields']['reactivate_user']['field'] = 'reactivate_user';
  $handler->display->display_options['fields']['reactivate_user']['label'] = '';
  $handler->display->display_options['fields']['reactivate_user']['exclude'] = TRUE;
  $handler->display->display_options['fields']['reactivate_user']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[edit_node] [activate_user] [reactivate_user] [resend_activation_email] [cancel_node]';
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  $handler->display->display_options['path'] = 'admin/people';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'users.csv';
  $handler->display->display_options['style_options']['permanent_file'] = 1;
  $handler->display->display_options['style_options']['file_path'] = 'private://export/users.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['separator'] = '|';
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'User ID';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['alter']['text'] = '<a href="user/[uid]">[c4m_first_name] [c4m_last_name]</a>
[mail]';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: User: First Name */
  $handler->display->display_options['fields']['c4m_first_name']['id'] = 'c4m_first_name';
  $handler->display->display_options['fields']['c4m_first_name']['table'] = 'field_data_c4m_first_name';
  $handler->display->display_options['fields']['c4m_first_name']['field'] = 'c4m_first_name';
  $handler->display->display_options['fields']['c4m_first_name']['label'] = 'First name';
  $handler->display->display_options['fields']['c4m_first_name']['element_label_colon'] = FALSE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['c4m_last_name']['id'] = 'c4m_last_name';
  $handler->display->display_options['fields']['c4m_last_name']['table'] = 'field_data_c4m_last_name';
  $handler->display->display_options['fields']['c4m_last_name']['field'] = 'c4m_last_name';
  $handler->display->display_options['fields']['c4m_last_name']['label'] = 'Last name';
  $handler->display->display_options['fields']['c4m_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_last_name']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['c4m_last_name']['hide_alter_empty'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Username';
  $handler->display->display_options['fields']['name']['alter']['text'] = '[c4m_first_name] [c4m_last_name]';
  $handler->display->display_options['fields']['name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: Active */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['alter']['text'] = 'Active : [status]<br>
Is Spammer : [c4m_is_spammer]<br>
Is Deleted : [c4m_is_deleted]<br>
Is Deleted Anonymous: [c4m_is_deleted_anonymous]<br>';
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: User: Is spammer */
  $handler->display->display_options['fields']['c4m_is_spammer']['id'] = 'c4m_is_spammer';
  $handler->display->display_options['fields']['c4m_is_spammer']['table'] = 'field_data_c4m_is_spammer';
  $handler->display->display_options['fields']['c4m_is_spammer']['field'] = 'c4m_is_spammer';
  $handler->display->display_options['fields']['c4m_is_spammer']['label'] = 'Spammer';
  $handler->display->display_options['fields']['c4m_is_spammer']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['c4m_is_spammer']['alter']['text'] = 'Yes';
  $handler->display->display_options['fields']['c4m_is_spammer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_is_spammer']['empty'] = 'No';
  $handler->display->display_options['fields']['c4m_is_spammer']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['c4m_is_spammer']['type'] = 'list_key';
  /* Field: User: Is deleted */
  $handler->display->display_options['fields']['c4m_is_deleted']['id'] = 'c4m_is_deleted';
  $handler->display->display_options['fields']['c4m_is_deleted']['table'] = 'field_data_c4m_is_deleted';
  $handler->display->display_options['fields']['c4m_is_deleted']['field'] = 'c4m_is_deleted';
  $handler->display->display_options['fields']['c4m_is_deleted']['label'] = 'Deleted';
  $handler->display->display_options['fields']['c4m_is_deleted']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['c4m_is_deleted']['alter']['text'] = 'Yes';
  $handler->display->display_options['fields']['c4m_is_deleted']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_is_deleted']['empty'] = 'No';
  $handler->display->display_options['fields']['c4m_is_deleted']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['c4m_is_deleted']['type'] = 'list_key';
  /* Field: User: Is deleted anonymous */
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['id'] = 'c4m_is_deleted_anonymous';
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['table'] = 'field_data_c4m_is_deleted_anonymous';
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['field'] = 'c4m_is_deleted_anonymous';
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['label'] = 'Deleted Anonymous';
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['alter']['text'] = 'Yes';
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['empty'] = 'No';
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['c4m_is_deleted_anonymous']['type'] = 'list_key';
  /* Field: User: Is deleted by */
  $handler->display->display_options['fields']['c4m_is_deleted_by_uid']['id'] = 'c4m_is_deleted_by_uid';
  $handler->display->display_options['fields']['c4m_is_deleted_by_uid']['table'] = 'field_data_c4m_is_deleted_by_uid';
  $handler->display->display_options['fields']['c4m_is_deleted_by_uid']['field'] = 'c4m_is_deleted_by_uid';
  $handler->display->display_options['fields']['c4m_is_deleted_by_uid']['label'] = 'Deleted by';
  $handler->display->display_options['fields']['c4m_is_deleted_by_uid']['settings'] = array(
    'link' => 1,
  );
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Registration date';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'c4m_long_without_time';
  $handler->display->display_options['fields']['created']['reldate'] = '0';
  /* Field: User: Last login */
  $handler->display->display_options['fields']['login']['id'] = 'login';
  $handler->display->display_options['fields']['login']['table'] = 'users';
  $handler->display->display_options['fields']['login']['field'] = 'login';
  $handler->display->display_options['fields']['login']['alter']['text'] = 'Registration : [created]<br>
Last login : [login]<br>
Last access : [access]';
  $handler->display->display_options['fields']['login']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['login']['date_format'] = 'short';
  $handler->display->display_options['fields']['login']['second_date_format'] = 'c4m_long_without_time';
  $handler->display->display_options['fields']['login']['reldate'] = '0';
  /* Field: Content: User metrics */
  $handler->display->display_options['fields']['user_metrics_11']['id'] = 'user_metrics_11';
  $handler->display->display_options['fields']['user_metrics_11']['table'] = 'users';
  $handler->display->display_options['fields']['user_metrics_11']['field'] = 'user_metrics';
  $handler->display->display_options['fields']['user_metrics_11']['label'] = 'Last activity';
  $handler->display->display_options['fields']['user_metrics_11']['c4m_user_admin_user_metric'] = 'user::last_activity';
  /* Field: User: Organisation */
  $handler->display->display_options['fields']['c4m_organisation']['id'] = 'c4m_organisation';
  $handler->display->display_options['fields']['c4m_organisation']['table'] = 'field_data_c4m_organisation';
  $handler->display->display_options['fields']['c4m_organisation']['field'] = 'c4m_organisation';
  $handler->display->display_options['fields']['c4m_organisation']['label'] = 'Organisation name';
  /* Field: Field: Organisation type */
  $handler->display->display_options['fields']['c4m_organisation_type']['id'] = 'c4m_organisation_type';
  $handler->display->display_options['fields']['c4m_organisation_type']['table'] = 'field_data_c4m_organisation_type';
  $handler->display->display_options['fields']['c4m_organisation_type']['field'] = 'c4m_organisation_type';
  /* Field: User: Country */
  $handler->display->display_options['fields']['c4m_country']['id'] = 'c4m_country';
  $handler->display->display_options['fields']['c4m_country']['table'] = 'field_data_c4m_country';
  $handler->display->display_options['fields']['c4m_country']['field'] = 'c4m_country';
  /* Field: Content: User metrics */
  $handler->display->display_options['fields']['user_metrics']['id'] = 'user_metrics';
  $handler->display->display_options['fields']['user_metrics']['table'] = 'users';
  $handler->display->display_options['fields']['user_metrics']['field'] = 'user_metrics';
  $handler->display->display_options['fields']['user_metrics']['label'] = 'Organisations';
  $handler->display->display_options['fields']['user_metrics']['c4m_user_admin_user_metric'] = 'user::organisations';
  /* Field: User: Topics of Expertise */
  $handler->display->display_options['fields']['c4m_vocab_topic_expertise']['id'] = 'c4m_vocab_topic_expertise';
  $handler->display->display_options['fields']['c4m_vocab_topic_expertise']['table'] = 'field_data_c4m_vocab_topic_expertise';
  $handler->display->display_options['fields']['c4m_vocab_topic_expertise']['field'] = 'c4m_vocab_topic_expertise';
  $handler->display->display_options['fields']['c4m_vocab_topic_expertise']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_vocab_topic_expertise']['type'] = 'term_reference_checked_inline_tree_for_views';
  $handler->display->display_options['fields']['c4m_vocab_topic_expertise']['settings'] = array(
    'link' => 0,
    'separator' => ' > ',
    'glue' => ' - ',
  );
  $handler->display->display_options['fields']['c4m_vocab_topic_expertise']['delta_offset'] = '0';
  /* Field: Content: User metrics */
  $handler->display->display_options['fields']['user_metrics_2']['id'] = 'user_metrics_2';
  $handler->display->display_options['fields']['user_metrics_2']['table'] = 'users';
  $handler->display->display_options['fields']['user_metrics_2']['field'] = 'user_metrics';
  $handler->display->display_options['fields']['user_metrics_2']['label'] = 'Comments';
  $handler->display->display_options['fields']['user_metrics_2']['c4m_user_admin_user_metric'] = 'user::comments';
  /* Field: Content: User metrics */
  $handler->display->display_options['fields']['user_metrics_3']['id'] = 'user_metrics_3';
  $handler->display->display_options['fields']['user_metrics_3']['table'] = 'users';
  $handler->display->display_options['fields']['user_metrics_3']['field'] = 'user_metrics';
  $handler->display->display_options['fields']['user_metrics_3']['label'] = 'Discussions';
  $handler->display->display_options['fields']['user_metrics_3']['c4m_user_admin_user_metric'] = 'user::discussions';
  /* Field: Content: User metrics */
  $handler->display->display_options['fields']['user_metrics_4']['id'] = 'user_metrics_4';
  $handler->display->display_options['fields']['user_metrics_4']['table'] = 'users';
  $handler->display->display_options['fields']['user_metrics_4']['field'] = 'user_metrics';
  $handler->display->display_options['fields']['user_metrics_4']['label'] = 'Documents';
  $handler->display->display_options['fields']['user_metrics_4']['c4m_user_admin_user_metric'] = 'user::documents';
  /* Field: Content: User metrics */
  $handler->display->display_options['fields']['user_metrics_5']['id'] = 'user_metrics_5';
  $handler->display->display_options['fields']['user_metrics_5']['table'] = 'users';
  $handler->display->display_options['fields']['user_metrics_5']['field'] = 'user_metrics';
  $handler->display->display_options['fields']['user_metrics_5']['label'] = 'Events';
  $handler->display->display_options['fields']['user_metrics_5']['c4m_user_admin_user_metric'] = 'user::events';
  /* Field: Content: User metrics */
  $handler->display->display_options['fields']['user_metrics_6']['id'] = 'user_metrics_6';
  $handler->display->display_options['fields']['user_metrics_6']['table'] = 'users';
  $handler->display->display_options['fields']['user_metrics_6']['field'] = 'user_metrics';
  $handler->display->display_options['fields']['user_metrics_6']['label'] = 'Group memberships';
  $handler->display->display_options['fields']['user_metrics_6']['c4m_user_admin_user_metric'] = 'user::group_memberships';
  /* Field: Content: User metrics */
  $handler->display->display_options['fields']['user_metrics_7']['id'] = 'user_metrics_7';
  $handler->display->display_options['fields']['user_metrics_7']['table'] = 'users';
  $handler->display->display_options['fields']['user_metrics_7']['field'] = 'user_metrics';
  $handler->display->display_options['fields']['user_metrics_7']['label'] = 'Group pending memberships';
  $handler->display->display_options['fields']['user_metrics_7']['c4m_user_admin_user_metric'] = 'user::group_pending_memberships';
  /* Field: Content: User metrics */
  $handler->display->display_options['fields']['user_metrics_8']['id'] = 'user_metrics_8';
  $handler->display->display_options['fields']['user_metrics_8']['table'] = 'users';
  $handler->display->display_options['fields']['user_metrics_8']['field'] = 'user_metrics';
  $handler->display->display_options['fields']['user_metrics_8']['label'] = 'Groups owned';
  $handler->display->display_options['fields']['user_metrics_8']['c4m_user_admin_user_metric'] = 'user::groups';
  /* Field: Content: User metrics */
  $handler->display->display_options['fields']['user_metrics_9']['id'] = 'user_metrics_9';
  $handler->display->display_options['fields']['user_metrics_9']['table'] = 'users';
  $handler->display->display_options['fields']['user_metrics_9']['field'] = 'user_metrics';
  $handler->display->display_options['fields']['user_metrics_9']['label'] = 'Administered groups';
  $handler->display->display_options['fields']['user_metrics_9']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['user_metrics_9']['c4m_user_admin_user_metric'] = 'user::groups_administered';
  /* Field: Content: User metrics */
  $handler->display->display_options['fields']['user_metrics_13']['id'] = 'user_metrics_13';
  $handler->display->display_options['fields']['user_metrics_13']['table'] = 'users';
  $handler->display->display_options['fields']['user_metrics_13']['field'] = 'user_metrics';
  $handler->display->display_options['fields']['user_metrics_13']['label'] = 'Projects pending membership';
  $handler->display->display_options['fields']['user_metrics_13']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['user_metrics_13']['c4m_user_admin_user_metric'] = 'user::projects_pending';
  /* Field: Content: User metrics */
  $handler->display->display_options['fields']['user_metrics_1']['id'] = 'user_metrics_1';
  $handler->display->display_options['fields']['user_metrics_1']['table'] = 'users';
  $handler->display->display_options['fields']['user_metrics_1']['field'] = 'user_metrics';
  $handler->display->display_options['fields']['user_metrics_1']['label'] = 'Projects ownded';
  $handler->display->display_options['fields']['user_metrics_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['user_metrics_1']['c4m_user_admin_user_metric'] = 'user::projects';
  /* Field: Content: User metrics */
  $handler->display->display_options['fields']['user_metrics_10']['id'] = 'user_metrics_10';
  $handler->display->display_options['fields']['user_metrics_10']['table'] = 'users';
  $handler->display->display_options['fields']['user_metrics_10']['field'] = 'user_metrics';
  $handler->display->display_options['fields']['user_metrics_10']['label'] = 'Administered projects';
  $handler->display->display_options['fields']['user_metrics_10']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['user_metrics_10']['c4m_user_admin_user_metric'] = 'user::projects_administered';
  /* Field: Content: User metrics */
  $handler->display->display_options['fields']['user_metrics_14']['id'] = 'user_metrics_14';
  $handler->display->display_options['fields']['user_metrics_14']['table'] = 'users';
  $handler->display->display_options['fields']['user_metrics_14']['field'] = 'user_metrics';
  $handler->display->display_options['fields']['user_metrics_14']['label'] = 'Programmes pending membership';
  $handler->display->display_options['fields']['user_metrics_14']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['user_metrics_14']['c4m_user_admin_user_metric'] = 'user::programmes_pending';
  /* Field: Content: User metrics */
  $handler->display->display_options['fields']['user_metrics_15']['id'] = 'user_metrics_15';
  $handler->display->display_options['fields']['user_metrics_15']['table'] = 'users';
  $handler->display->display_options['fields']['user_metrics_15']['field'] = 'user_metrics';
  $handler->display->display_options['fields']['user_metrics_15']['label'] = 'Programmes owned';
  $handler->display->display_options['fields']['user_metrics_15']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['user_metrics_15']['c4m_user_admin_user_metric'] = 'user::programmes';
  /* Field: Content: User metrics */
  $handler->display->display_options['fields']['user_metrics_12']['id'] = 'user_metrics_12';
  $handler->display->display_options['fields']['user_metrics_12']['table'] = 'users';
  $handler->display->display_options['fields']['user_metrics_12']['field'] = 'user_metrics';
  $handler->display->display_options['fields']['user_metrics_12']['label'] = 'Administered programmes';
  $handler->display->display_options['fields']['user_metrics_12']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['user_metrics_12']['c4m_user_admin_user_metric'] = 'user::programmes_administered';
  /* Field: User: Eu Login validated */
  $handler->display->display_options['fields']['eu_login']['id'] = 'eu_login';
  $handler->display->display_options['fields']['eu_login']['table'] = 'users';
  $handler->display->display_options['fields']['eu_login']['field'] = 'eu_login';
  $handler->display->display_options['path'] = 'admin/people/export/file';
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'admin/people/export';
  $handler->display->display_options['segment_size'] = '50';
  $export['c4m_admin_users'] = $view;

  return $export;
}
