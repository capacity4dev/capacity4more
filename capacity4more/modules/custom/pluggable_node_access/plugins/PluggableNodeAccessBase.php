<?php

/**
 * @file
 * Contains \PluggableNodeAccess.
 */

abstract class PluggableNodeAccessBase implements PluggableNodeAccessInterface {


  /**
   * The plugin definition.
   *
   * @var array
   */
  protected $plugin;

  /**
   * The entity object.
   *
   * @var stdClass
   */
  protected $node;

  /**
   * @param \stdClass $entity
   */
  public function setNode($entity) {
    $this->node = $entity;
  }

  /**
   * @return \stdClass
   */
  public function getNode() {
    return $this->node;
  }

  /**
   *
   * @param array $plugin
   *   The plugin definition.
   * @param $node
   *   The node object.
   */
  public function __construct(array $plugin, $node) {
    $this->plugin = $plugin;
    $this->setNode($node);
  }

  /**
   * Determine if handler has access.
   *
   * @param $entity_type
   * @param $entity
   *
   * @return bool|mixed
   */
  public static function access($entity_type, $entity, $op) {
    return og_is_group($entity_type, $entity) || og_get_entity_groups($entity_type, $entity);
  }

  /**
   * @todo: Allow adding reference field on the group content.
   */
  protected function getReferenceFields() {
    // Get the entity reference fields.
    $return = array();
    $bundle = $this->getNode()->type;
    foreach (field_info_instances('node', $bundle) as $field_name => $instance) {
      $field = field_info_field($field_name);
      if ($field['type'] != 'entityreference') {
        // Not an entity reference field.
        continue;
      }

      if ($field['settings']['target_type'] != 'pluggable_node_access') {
        // Does not reference the Pluggable node access entity.
        continue;
      }

      if (!empty($field['settings']['target_bundles']) && !in_array($this->plugin['name'], $field['settings']['target_bundles'])) {
        // Field doesn't reference the bundle associated with the plugin.
        continue;
      }
      $return[] = $field_name;
    }

    return $return;
  }

  protected function getAccessEntities() {
    $node = $this->getNode();

    $entities = $this->getAccessEntitiesFromEntity('node', $node);
    return array_merge_recursive($entities, $this->getAccessEntitiesFromGroupContent());
  }

  protected function getAccessEntitiesFromEntity($entity_type = 'node', $entity = NULL) {

    if (empty($entity)) {
      $entity = $this->getNode();
    }

    if (!$field_names = $this->getReferenceFields()) {
      // No reference fields to Pluggable node access entities.
      return array();
    }

    $wrapper = entity_metadata_wrapper($entity_type, $entity);
    $result = array();

    foreach ($field_names as $field_name) {
      $entities = $wrapper->{$field_name}->value();
      $entities = is_array($entities) ? $entities : array($entities);
      $result = array_merge_recursive($result, $entities);
    }
    return $result;
  }

  protected function getAccessEntitiesFromGroupContent() {
    if (!module_exists('og')) {
      return array();
    }

    if (!$groups = og_get_entity_groups('node', $this->getNode())) {
      return array();
    }

    $result = array();
    foreach ($groups as $entity_type => $ids) {
      $entities = entity_load($entity_type, $ids);
      foreach ($entities as $entity) {
        $entities = $this->getAccessEntitiesFromEntity($entity_type, $entity);
        $result = array_merge_recursive($result, $entities);
      }
    }

    return $result;
  }
}
