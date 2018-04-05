<?php

/**
 * @file
 * c4m_content_share.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function c4m_content_share_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'c4m_content_share_overview';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Content share overview';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Shared to';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['query']['options']['query_tags'] = array(
    0 => 'node_access',
  );
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'no-border';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Groups */
  $handler->display->display_options['fields']['og_group_ref']['id'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['table'] = 'og_membership';
  $handler->display->display_options['fields']['og_group_ref']['field'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['label'] = '';
  $handler->display->display_options['fields']['og_group_ref']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['og_group_ref']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['og_group_ref']['settings'] = array(
    'view_mode' => 'token',
    'links' => 0,
  );
  /* Sort criterion: Content: Groups (og_group_ref) */
  $handler->display->display_options['sorts']['og_group_ref_target_id']['id'] = 'og_group_ref_target_id';
  $handler->display->display_options['sorts']['og_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['sorts']['og_group_ref_target_id']['field'] = 'og_group_ref_target_id';
  /* Contextual filter: Content: Source Content (c4m_source_entity) */
  $handler->display->display_options['arguments']['c4m_source_entity_target_id']['id'] = 'c4m_source_entity_target_id';
  $handler->display->display_options['arguments']['c4m_source_entity_target_id']['table'] = 'field_data_c4m_source_entity';
  $handler->display->display_options['arguments']['c4m_source_entity_target_id']['field'] = 'c4m_source_entity_target_id';
  $handler->display->display_options['arguments']['c4m_source_entity_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['c4m_source_entity_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['c4m_source_entity_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['c4m_source_entity_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['c4m_source_entity_target_id']['summary_options']['items_per_page'] = '25';
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
    'share' => 'share',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_caching'] = '-1';
  $export['c4m_content_share_overview'] = $view;

  return $export;
}
