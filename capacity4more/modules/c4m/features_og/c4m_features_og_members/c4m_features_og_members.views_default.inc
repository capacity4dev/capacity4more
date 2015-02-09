<?php
/**
 * @file
 * c4m_features_og_members.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function c4m_features_og_members_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'c4m_overview_og_members';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_c4m_search_users';
  $view->human_name = 'Overview - OG - Members';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Overview - OG - Members';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  /* Field: Indexed User: User ID */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'search_api_index_c4m_search_users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['c4m_overview_og_members'] = $view;

  return $export;
}
