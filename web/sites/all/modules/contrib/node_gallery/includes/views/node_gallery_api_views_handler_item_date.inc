<?php

/**
 * @file
 * Creates an image date handler for galleries.
 */

class node_gallery_api_views_handler_item_date extends views_handler_field_date {

  function query() {
    $this->ensure_my_table();
    $sql = "SELECT n.changed FROM {node_gallery_relationship} ng
      LEFT JOIN {node} n on ng.nid = n.nid
      WHERE n.status = 1 AND ng.ngid = node.nid
      ORDER BY changed DESC LIMIT 1";
    $this->field_alias = $this->query->add_field(NULL, "($sql)", 'item_date');
  }

}
