<?php

/**
 * @file
 * Views-related functions for Node Gallery API.
 */

/**
 * Node Gallery Relationship entity Views definitions.
 */
class NodeGalleryRelationshipViewsController extends EntityDefaultViewsController {

}

/**
 * Node Gallery Relationship entity Views definitions.
 */
class NodeGalleryRelationshipTypeViewsController extends EntityDefaultViewsController {

}

/**
 * Implements hook_views_data().
 */
function node_gallery_api_views_data() {
  $data = array();

  $data['node_gallery_relationship']['item_navigator'] = array(
    'title' => t('Gallery Item Navigator'),
    'help' => t('Navigator bar for moving between gallery items.'),
    'real field' => 'id',
    'field' => array(
      'handler' => 'node_gallery_api_views_handler_item_navigator',
      'click sortable' => FALSE,
    ),
  );

  $data['node_gallery_galleries']['table']['group'] = t('Node Gallery');
  $data['node_gallery_galleries']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'ngid',
    ),
  );
  $data['node_gallery_galleries']['ngid'] = array(
    'title' => t('Is Gallery'),
    'help' => t('Whether or not the content is a gallery.'),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Is Gallery'),
      'type' => 'yes-no',
      'use equal' => FALSE,
      'accept null' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['node_gallery_galleries']['cover_item'] = array(
    'title' => t('Gallery Cover Item'),
    'help' => t('Relationship to link the cover item for the gallery.'),
    'relationship' => array(
      'label' => t('Gallery Cover Item'),
      'base' => 'node',
      'base field' => 'nid',
    ),
  );
  $data['node_gallery_galleries']['pub_item_count'] = array(
    'title' => t('Published Item Count'),
    'help' => t('The number of published items in the gallery.'),
    'real field' => 'pub_item_count',
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'numeric' => TRUE,
      'validate type' => 'numeric',
    ),
  );
  $data['node_gallery_galleries']['item_count'] = array(
    'title' => t('Item Count'),
    'help' => t('The total number of published and unpublished items in the gallery.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'numeric' => TRUE,
      'validate type' => 'numeric',
    ),
  );
  $data['node_gallery_galleries']['comments_count'] = array(
    'title' => t('Total comments'),
    'help' => t('The total number of comments on the gallery and all its images.'),
    'field' => array(
      'handler' => 'node_gallery_api_views_handler_comments_count',
      'click sortable' => TRUE,
      'notafield' => TRUE,
    ),
  );
  $data['node_gallery_galleries']['item_date'] = array(
    'title' => t('Item Updated Date'),
    'help' => t('The last changed date of an item in the gallery.'),
    'field' => array(
      'handler' => 'node_gallery_views_handler_item_date',
      'click sortable' => TRUE,
      'notafield' => TRUE,
    ),
  );

  return $data;
}

  /**
   * Implements hook_views_data_alter().
   */
function node_gallery_api_views_data_alter(&$data) {
  $data['node']['node_gallery_relationship']['group'] = t('Node Gallery Relationship');
  $data['node']['node_gallery_relationship']['title'] = t('Node Gallery Relationship from Gallery Item');
  $data['node']['node_gallery_relationship']['help'] = t('The Node Gallery Relationship associated with the Gallery Item.');
  $data['node']['node_gallery_relationship_ngid']['group'] = t('Node Gallery Relationship');
  $data['node']['node_gallery_relationship_ngid']['title'] = t('Node Gallery Relationship from Gallery');
  $data['node']['node_gallery_relationship_ngid']['help'] = t('The Node Gallery Relationship associated with the Gallery.');
}


/**
 * Implements hook_views_handlers().
 */
function node_gallery_api_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'node_gallery_api') . '/includes/views',
    ),
    'handlers' => array(
      'node_gallery_api_views_handler_comments_count' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'node_gallery_api_views_handler_item_date' => array(
        'parent' => 'views_handler_field_date',
      ),
      'node_gallery_api_views_handler_item_navigator' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}
