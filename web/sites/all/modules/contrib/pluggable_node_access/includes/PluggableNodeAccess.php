<?php

/**
 * @file
 * Contains \PluggableNodeAccess.
 */


class PluggableNodeAccess extends Entity {

  public function __construct($values = array()) {
    parent::__construct($values, 'pluggable_node_access');
      $this->timestamp = time();
  }
}
