<?php

/**
 * @file
 * Views field handler that displays the image navigator
 */

/**
 * Field handler to display the item navigator in a view
 */
class node_gallery_api_views_handler_item_navigator extends views_handler_field {

  function query() {
    $this->ensure_my_table();
    $this->field_alias = $this->query->add_field($this->table_alias, 'id');
  }

  function render($values) {
    $relationships = entity_load('node_gallery_relationship', array($values->{$this->field_alias}));
    if (!empty($relationships)) {
      $relationship = array_shift($relationships);
      $node = node_load($relationship->nid);
      return theme('node_gallery_api_item_navigator',
        array(
          'navigator' => node_gallery_api_get_item_navigator($relationship->ngid, $node->nid), 'item' => $node)
        );
    }
    return NULL;
  }

}
