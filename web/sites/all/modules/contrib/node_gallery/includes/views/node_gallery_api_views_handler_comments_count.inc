<?php

/**
 * @file
 * Creates an comments count handler that totals all comments made on a
 * gallery and all images within it
 */

class node_gallery_api_views_handler_comments_count extends views_handler_field_numeric {
  function query() {
    $this->ensure_my_table();
    $sql = "SELECT COUNT(*) FROM {comments} c
      LEFT JOIN {node_gallery_relationship} ngi on c.nid = ngi.nid
      LEFT JOIN {node} n on c.nid = n.nid
      WHERE (ngi.ngid = node.nid or n.nid = node.nid) AND n.status = 1";
    $this->field_alias = $this->query->add_field(NULL, "($sql)", 'comments_count');
  }
}
