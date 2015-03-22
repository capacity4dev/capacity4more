<?php
// @codingStandardsIgnoreFile

/**
 * @file
 * Views plugin to add field operations.
 */

/**
 * Class c4m_search_vbo_handler_field_operations.
 *
 * See https://www.drupal.org/node/1123454#comment-9554163
 */
class c4m_search_vbo_handler_field_operations extends views_bulk_operations_handler_field_operations {
  /**
   * Override their get entity type since the base table name won't match at
   * all.
   */
  public function get_entity_type() {
    return $this->definition['item_type'];
  }

  /**
   * Overridden to try to fish out the id.
   */
  public function get_value($values, $field = NULL) {
    // I'm not sure this is the best source for this but the name seemed
    // consistent.
    return $values->_entity_properties['search_api_item_id'];
  }

}
