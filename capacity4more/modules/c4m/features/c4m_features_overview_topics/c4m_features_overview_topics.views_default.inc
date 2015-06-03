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
  $view->name = 'c4m_overview_topic';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_c4m_search_nodes';
  $view->human_name = 'Topics Overview';
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
  $handler->display->display_options['style_options']['row_class'] = 'col-md-3 col-sm-3 col-xs-6';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Field: Indexed Node: Theme */
  $handler->display->display_options['fields']['c4m_vocab_theme']['id'] = 'c4m_vocab_theme';
  $handler->display->display_options['fields']['c4m_vocab_theme']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['fields']['c4m_vocab_theme']['field'] = 'c4m_vocab_theme';
  $handler->display->display_options['fields']['c4m_vocab_theme']['label'] = '';
  $handler->display->display_options['fields']['c4m_vocab_theme']['exclude'] = TRUE;
  $handler->display->display_options['fields']['c4m_vocab_theme']['element_class'] = 'col-sm-12';
  $handler->display->display_options['fields']['c4m_vocab_theme']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_vocab_theme']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['c4m_vocab_theme']['view_mode'] = 'full';
  $handler->display->display_options['fields']['c4m_vocab_theme']['bypass_access'] = 0;
  /* Field: Indexed Node: List Image */
  $handler->display->display_options['fields']['c4m_media']['id'] = 'c4m_media';
  $handler->display->display_options['fields']['c4m_media']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['fields']['c4m_media']['field'] = 'c4m_media';
  $handler->display->display_options['fields']['c4m_media']['label'] = '';
  $handler->display->display_options['fields']['c4m_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_media']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['c4m_media']['settings'] = array(
    'image_style' => 'c4m_image_medium',
    'image_link' => 'content',
  );
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Sort criterion: Indexed Node: Theme */
  $handler->display->display_options['sorts']['c4m_vocab_theme']['id'] = 'c4m_vocab_theme';
  $handler->display->display_options['sorts']['c4m_vocab_theme']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['sorts']['c4m_vocab_theme']['field'] = 'c4m_vocab_theme';
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_c4m_search_nodes';
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
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['c4m_overview_topic'] = $view;

  return $export;
}
