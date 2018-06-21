<?php
/**
 * @file
 * c4m_features_overview_topics.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function c4m_features_overview_topics_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'c4m_overview_topics';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Overview Topics';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Topics';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'c4m_vocab_theme',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'col-md-4 col-sm-4 col-xs-6 no-border';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'c4m_media' => 'c4m_media',
    'title' => 'title',
  );
  /* Field: Content: Theme */
  $handler->display->display_options['fields']['c4m_vocab_theme']['id'] = 'c4m_vocab_theme';
  $handler->display->display_options['fields']['c4m_vocab_theme']['table'] = 'field_data_c4m_vocab_theme';
  $handler->display->display_options['fields']['c4m_vocab_theme']['field'] = 'c4m_vocab_theme';
  $handler->display->display_options['fields']['c4m_vocab_theme']['label'] = '';
  $handler->display->display_options['fields']['c4m_vocab_theme']['exclude'] = TRUE;
  $handler->display->display_options['fields']['c4m_vocab_theme']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_vocab_theme']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Rendered Node */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'teaser';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Sort criterion: Content: Theme (c4m_vocab_theme) */
  $handler->display->display_options['sorts']['c4m_vocab_theme_tid']['id'] = 'c4m_vocab_theme_tid';
  $handler->display->display_options['sorts']['c4m_vocab_theme_tid']['table'] = 'field_data_c4m_vocab_theme';
  $handler->display->display_options['sorts']['c4m_vocab_theme_tid']['field'] = 'c4m_vocab_theme_tid';
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
    'topic' => 'topic',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'topics';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Topics';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $export['c4m_overview_topics'] = $view;

  return $export;
}
