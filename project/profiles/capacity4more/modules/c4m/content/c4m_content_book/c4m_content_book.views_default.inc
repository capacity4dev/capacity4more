<?php

/**
 * @file
 * c4m_content_book.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function c4m_content_book_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'c4m_rearrange_help_guidance';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Help and Guidance';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Reorder Help pages';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Draggableviews: Content */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['handler'] = 'draggableviews_handler_book';
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['hierarchy_handler'] = 'draggableviews_hierarchy_handler_book';
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['element_type'] = 'textfield';
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = 'Delete';
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'c4m_wiki:wiki_rearrange_page';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
  /* Contextual filter: Book: All sub nodes of this book page. */
  $handler->display->display_options['arguments']['book']['id'] = 'book';
  $handler->display->display_options['arguments']['book']['table'] = 'draggableviews_book_structure';
  $handler->display->display_options['arguments']['book']['field'] = 'book';
  $handler->display->display_options['arguments']['book']['default_action'] = 'default';
  $handler->display->display_options['arguments']['book']['default_argument_type'] = 'c4m_content_book_plugin_argument_default';
  $handler->display->display_options['arguments']['book']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['book']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['book']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'book' => 'book',
  );

  /* Display: Rearrange */
  $handler = $view->new_display('page', 'Rearrange', 'help_rearrange_page');
  $handler->display->display_options['path'] = 'help-guidance/rearrange';
  $handler->display->display_options['menu']['title'] = 'Order Outline';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['c4m_rearrange_help_guidance'] = $view;

  return $export;
}
