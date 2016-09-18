<?php

/**
 * @file
 * Views argument plugin.
 */

/**
 * The help pages argument default handler.
 */
class c4m_content_book_plugin_argument_default extends views_plugin_argument_default {

  /**
   * Return the node ID of the help pages book.
   *
   * @return int
   *   Return the node ID of the help pages book.
   */
  public function get_argument() {
    // Get the node ID of the Help & Guidance book.
    $help_book_title = variable_get('help_book', 'Help & Guidance');
    $query = new EntityFieldQuery();
    $entities = $query->entityCondition('entity_type', 'node')
      ->propertyCondition('type', 'book')
      ->propertyCondition('title', $help_book_title)
      ->propertyCondition('status', 1)
      ->propertyOrderBy('nid')
      ->range(0, 1)
      ->execute();
    $entity = array_keys($entities['node']);

    return array_shift($entity);
  }

}
