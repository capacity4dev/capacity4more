<?php


/**
 * OG selection handler.
 */
class C4MOgSelectionHandler extends OgSelectionHandler {

  /**
   * Implements EntityReferenceHandler::getInstance().
   */
  public static function getInstance($field, $instance = NULL, $entity_type = NULL, $entity = NULL) {
   // $instance['field_mode'] = 'default';
    return new C4MOgSelectionHandler($field, $instance, $entity_type, $entity);
  }

  public function validateReferencableEntities(array $ids) {
    // Remove empty ids
    foreach ($ids as $key => $value) {
      if ($value === NULL) {
        unset($ids[$key]);
      }
    }
    return parent::validateReferencableEntities($ids);
  }
}
