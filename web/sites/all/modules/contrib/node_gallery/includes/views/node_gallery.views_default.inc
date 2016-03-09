<?php

/**
 * @file
 * Default views for Node Gallery.
 */

/**
 * Implements hook_views_default_views().
 */
function node_gallery_views_default_views() {

  $view = new view();
  $view->name = 'node_gallery_gallery_item_views';
  $view->description = 'Views of items meant to be attached to a gallery parent view.';
  $view->tag = 'node_gallery_items';
  $view->base_table = 'node';
  $view->human_name = 'Node Gallery: Gallery Item Views';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '24';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['relationship'] = 'nid';
  $handler->display->display_options['row_options']['view_mode'] = 'node_gallery_node_thumbnail';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Relationship: Node Gallery Relationship: Node Gallery Relationship from Gallery */
  $handler->display->display_options['relationships']['node_gallery_relationship_ngid']['id'] = 'node_gallery_relationship_ngid';
  $handler->display->display_options['relationships']['node_gallery_relationship_ngid']['table'] = 'node';
  $handler->display->display_options['relationships']['node_gallery_relationship_ngid']['field'] = 'node_gallery_relationship_ngid';
  $handler->display->display_options['relationships']['node_gallery_relationship_ngid']['required'] = TRUE;
  /* Relationship: Node Gallery Relationship: Gallery Item */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node_gallery_relationship';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['relationship'] = 'node_gallery_relationship_ngid';
  $handler->display->display_options['relationships']['nid']['label'] = 'Gallery Item';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '20';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Gallery Media  */
  $handler->display->display_options['fields']['node_gallery_media']['id'] = 'node_gallery_media';
  $handler->display->display_options['fields']['node_gallery_media']['table'] = 'field_data_node_gallery_media';
  $handler->display->display_options['fields']['node_gallery_media']['field'] = 'node_gallery_media';
  $handler->display->display_options['fields']['node_gallery_media']['relationship'] = 'nid';
  $handler->display->display_options['fields']['node_gallery_media']['label'] = '';
  $handler->display->display_options['fields']['node_gallery_media']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['node_gallery_media']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['node_gallery_media']['element_label_colon'] = FALSE;
  /* Sort criterion: Node Gallery Relationship: Item Weight (Sort Order) */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'node_gallery_relationship';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'node_gallery_relationship_ngid';
  /* Sort criterion: Content: Nid */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'nid';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Image Thumbnail Grid */
  $handler = $view->new_display('embed', 'Image Thumbnail Grid', 'embed_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

  /* Display: Image Thumbnail Strip */
  $handler = $view->new_display('embed', 'Image Thumbnail Strip', 'embed_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';

  /* Display: Image Thumbnail Strip with AJAX Pager */
  $handler = $view->new_display('embed', 'Image Thumbnail Strip with AJAX Pager', 'embed_3');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';

  /* Display: Image Strip without Pager */
  $handler = $view->new_display('embed', 'Image Strip without Pager', 'embed_6');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';

  /* Display: Cover Image Thumbnail */
  $handler = $view->new_display('embed', 'Cover Image Thumbnail', 'embed_4');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['relationship'] = 'cover_item';
  $handler->display->display_options['row_options']['view_mode'] = 'node_gallery_node_thumbnail';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Node Gallery: Gallery Cover Item */
  $handler->display->display_options['relationships']['cover_item']['id'] = 'cover_item';
  $handler->display->display_options['relationships']['cover_item']['table'] = 'node_gallery_galleries';
  $handler->display->display_options['relationships']['cover_item']['field'] = 'cover_item';
  $handler->display->display_options['relationships']['cover_item']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'cover_item';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'cover_item';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '20';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Nid */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'cover_item';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Image Sort */
  $handler = $view->new_display('embed', 'Image Sort', 'embed_5');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $translatables['node_gallery_gallery_item_views'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Node Gallery Relationship'),
    t('Gallery Item'),
    t('All'),
    t('Image Thumbnail Grid'),
    t('Image Thumbnail Strip'),
    t('Image Thumbnail Strip with AJAX Pager'),
    t('Image Strip without Pager'),
    t('Cover Image Thumbnail'),
    t('Gallery Cover Item'),
    t('Image Sort'),
  );

  $views[$view->name] = $view;


  $view = new view();
  $view->name = 'node_gallery_gallery_summaries';
  $view->description = '';
  $view->tag = 'node_gallery_galleries';
  $view->base_table = 'node';
  $view->human_name = 'Node Gallery: Gallery Summaries';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Galleries';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Node Gallery: Is Gallery */
  $handler->display->display_options['filters']['ngid']['id'] = 'ngid';
  $handler->display->display_options['filters']['ngid']['table'] = 'node_gallery_galleries';
  $handler->display->display_options['filters']['ngid']['field'] = 'ngid';
  $handler->display->display_options['filters']['ngid']['value'] = '1';

  /* Display: Gallery Teasers */
  $handler = $view->new_display('page', 'Gallery Teasers', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'galleries';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Galleries';

  /* Display: Gallery Covers Grid */
  $handler = $view->new_display('page', 'Gallery Covers Grid', 'page_1');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'pub_item_count' => 'pub_item_count',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Node Gallery: Gallery Cover Item */
  $handler->display->display_options['relationships']['cover_item']['id'] = 'cover_item';
  $handler->display->display_options['relationships']['cover_item']['table'] = 'node_gallery_galleries';
  $handler->display->display_options['relationships']['cover_item']['field'] = 'cover_item';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '20';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Node Gallery: Published Item Count */
  $handler->display->display_options['fields']['pub_item_count']['id'] = 'pub_item_count';
  $handler->display->display_options['fields']['pub_item_count']['table'] = 'node_gallery_galleries';
  $handler->display->display_options['fields']['pub_item_count']['field'] = 'pub_item_count';
  $handler->display->display_options['fields']['pub_item_count']['label'] = '';
  $handler->display->display_options['fields']['pub_item_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['pub_item_count']['prefix'] = '(';
  $handler->display->display_options['fields']['pub_item_count']['suffix'] = ' items)';
  /* Field: Content: Gallery Media  */
  $handler->display->display_options['fields']['node_gallery_media']['id'] = 'node_gallery_media';
  $handler->display->display_options['fields']['node_gallery_media']['table'] = 'field_data_node_gallery_media';
  $handler->display->display_options['fields']['node_gallery_media']['field'] = 'node_gallery_media';
  $handler->display->display_options['fields']['node_gallery_media']['relationship'] = 'cover_item';
  $handler->display->display_options['fields']['node_gallery_media']['label'] = '';
  $handler->display->display_options['fields']['node_gallery_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['node_gallery_media']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['node_gallery_media']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['node_gallery_media']['settings'] = array(
    'file_view_mode' => 'node_gallery_file_cover',
  );
  $handler->display->display_options['path'] = 'galleries';

  $views[$view->name] = $view;

  return $views;
}
