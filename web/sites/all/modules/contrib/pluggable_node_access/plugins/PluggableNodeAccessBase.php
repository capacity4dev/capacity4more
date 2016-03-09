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
  public function getReferenceFields($entity) {
    // Get the entity reference fields.
    $return = array();
    $bundle = $entity->type;
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

  /**
   * Gets access entities that are related to the current entity.
   *
   * @param $entity_type
   *  Entity type.
   * @param $entity
   *  (optional) Entity object.
   * @param $pluggable_node_access_type
   *  (optional) Pluggable node access type.
   *
   * @return array
   *  Returns array of node access entities.
   */
  protected function getAccessEntities($entity_type = 'node', $entity = NULL, $pluggable_node_access_type = NULL) {
    if (empty($entity)) {
      $entity = $this->getNode();
    }

    $entities = $this->getAccessEntitiesFromEntity('node', $entity, $pluggable_node_access_type);
    return array_merge_recursive($entities, $this->getAccessEntitiesFromGroupContent());
  }


  /**
   * Gets pluggable node access entities that are related to the current entity.
   *
   * @param $entity_type
   *  Entity type.
   * @param $entity
   *  (optional) Entity object.
   * @param $pluggable_node_access_type
   *  (optional) Pluggable node access type.
   *
   * @return array
   *  Returns array of pluggable node access entities.
   */
  protected function getAccessEntitiesFromEntity($entity_type = 'node', $entity = NULL, $pluggable_node_access_type = NULL) {

    if (empty($entity)) {
      $entity = $this->getNode();
    }

    if (empty($pluggable_node_access_type)) {
      // Set the default pluggable node access type to email_domain.
      $pluggable_node_access_type = $this->plugin['name'];
    }

    if (!$field_names = $this->getReferenceFields($entity)) {
      // No reference fields to Pluggable node access entities.
      return array();
    }

    $wrapper = entity_metadata_wrapper($entity_type, $entity);
    $result = array();

    foreach ($field_names as $field_name) {
      $entities = $wrapper->{$field_name}->value();
      $entities = is_null($entities) ? array() : $entities;
      $entities = is_array($entities) ? $entities : array($entities);

      foreach ($entities as $key => $pluggable_entity) {
        // Remove the ones that are not of the requested type.
        if ($pluggable_entity->type != $pluggable_node_access_type) {
          unset($entities[$key]);
        }
      }
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
