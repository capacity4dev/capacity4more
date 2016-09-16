<?php

/**
 * @file
 * OG Selection handler.
 */

/**
 * OG selection handler.
 */
class C4MSelectionHandler extends C4MOgSelectionHandler {

  /**
   * {@inheritdoc}
   */
  public static function getInstance(
    $field,
    $instance = NULL,
    $entity_type = NULL,
    $entity = NULL
  ) {
    return new C4MSelectionHandler($field, $instance, $entity_type, $entity);
  }

  /**
   * {@inheritdoc}
   */
  public function validateReferencableEntities(array $ids) {
    return parent::validateReferencableEntities($ids);
  }

  /**
   * {@inheritdoc}
   */
  public function buildEntityFieldQuery(
    $match = NULL,
    $match_operator = 'CONTAINS'
  ) {
    return parent::buildEntityFieldQuery($match, $match_operator);
  }

}
