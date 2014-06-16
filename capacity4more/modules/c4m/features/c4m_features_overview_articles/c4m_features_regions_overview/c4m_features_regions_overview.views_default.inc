<?php
/**
 * @file
 * c4m_features_regions_overview.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function c4m_features_regions_overview_views_default_views() {
  $export = array();

  $view              = new view();
  $view->name        = 'c4m_regions_countries';
  $view->description = 'Overview table of region content.';
  $view->tag         = 'default';
  $view->base_table  = 'taxonomy_term_data';
  $view->human_name  = 'Overview - Regions & Countries';
  $view->core        = 7;
  $view->api_version = '3.0';
  $view->disabled    = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler                                                        = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title']                     = 'Regions & Countries';
  $handler->display->display_options['use_more_always']           = FALSE;
  $handler->display->display_options['group_by']                  = TRUE;
  $handler->display->display_options['access']['type']            = 'perm';
  $handler->display->display_options['cache']['type']             = 'none';
  $handler->display->display_options['query']['type']             = 'views_query';
  $handler->display->display_options['exposed_form']['type']      = 'basic';
  $handler->display->display_options['pager']['type']             = 'none';
  $handler->display->display_options['style_plugin']              = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field'          => 'name_1',
      'rendered'       => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns']  = array(
    'name'   => 'name',
    'name_1' => 'name_1',
  );
  $handler->display->display_options['style_options']['default']  = 'name';
  $handler->display->display_options['style_options']['info']     = array(
    'name'   => array(
      'sortable'           => 1,
      'default_sort_order' => 'asc',
      'align'              => '',
      'separator'          => '',
      'empty_column'       => 0,
    ),
    'name_1' => array(
      'sortable'           => 1,
      'default_sort_order' => 'asc',
      'align'              => '',
      'separator'          => '',
      'empty_column'       => 0,
    ),
  );
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id']    = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id']                     = 'name';
  $handler->display->display_options['fields']['name']['table']                  = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field']                  = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis']      = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy']       = TRUE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_1']['id']               = 'name_1';
  $handler->display->display_options['fields']['name_1']['table']            = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_1']['field']            = 'name';
  $handler->display->display_options['fields']['name_1']['relationship']     = 'parent';
  $handler->display->display_options['fields']['name_1']['label']            = 'Parent';
  $handler->display->display_options['fields']['name_1']['link_to_taxonomy'] = TRUE;
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id']           = 'name';
  $handler->display->display_options['sorts']['name']['table']        = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field']        = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'parent';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id']    = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id']    = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'c4m_vocab_geo' => 'c4m_vocab_geo',
  );
  /* Filter criterion: Taxonomy term: Parent term */
  $handler->display->display_options['filters']['parent']['id']           = 'parent';
  $handler->display->display_options['filters']['parent']['table']        = 'taxonomy_term_hierarchy';
  $handler->display->display_options['filters']['parent']['field']        = 'parent';
  $handler->display->display_options['filters']['parent']['relationship'] = 'parent';
  $handler->display->display_options['filters']['parent']['operator']     = 'not empty';

  /* Display: Page */
  $handler                                                          = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path']                        = 'regions-countries';
  $handler->display->display_options['menu']['type']                = 'normal';
  $handler->display->display_options['menu']['title']               = 'Regions & Countries';
  $handler->display->display_options['menu']['weight']              = '3';
  $handler->display->display_options['menu']['name']                = 'main-menu';
  $handler->display->display_options['menu']['context']             = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['c4m_regions_countries']                                  = $view;

  return $export;
}
