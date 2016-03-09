<?php

/**
 * @file
 * Node Gallery EntityReference selection plugin.
 */

/**
 * Node Gallery API selection handler.
 */
class NodeGallerySelectionHandler extends EntityReference_SelectionHandler_Generic_node {

  /**
   * Implements EntityReferenceHandler::getInstance().
   */
  public static function getInstance($field, $instance = NULL, $entity_type = NULL, $entity = NULL) {
    return new NodeGallerySelectionHandler($field, $instance, $entity_type, $entity);
  }

  /**
   * Override settings form().
   */
  public static function settingsForm($field, $instance) {
    $form = parent::settingsForm($field, $instance);
    $entity_type = $field['settings']['target_type'];
    entity_get_info($entity_type);
    $relationship_types = node_gallery_api_get_relationship_type();
    $rt_options = array();
    foreach ($relationship_types as $rt) {
      $rt_options[$rt->id] = $rt->label;
    }
    $form['node_gallery_relationship_type'] = array(
      '#title' => t('Relationship Type'),
      '#type' => 'select',
      '#options' => $rt_options,
      '#default_value' => isset($field['settings']['handler_settings']['node_gallery_relationship_type']) ? $field['settings']['handler_settings']['node_gallery_relationship_type'] : NULL,
    );
    $form['target_bundles'] = array(
      '#type' => 'value',
      '#value' => array(),
    );

    return $form;
  }

  /**
   * Build an EntityFieldQuery to get referencable entities.
   */
  protected function buildEntityFieldQuery($match = NULL, $match_operator = 'CONTAINS') {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', $this->field['settings']['target_type']);
    // Get target bundles from relationship type.
    $relationship_type = node_gallery_api_get_relationship_type(NULL, NULL, $this->field['settings']['handler_settings']['node_gallery_relationship_type']);
    $this->field['settings']['handler_settings']['target_bundles'] = $relationship_type->gallery_types;
    if (!empty($this->field['settings']['handler_settings']['target_bundles'])) {
      $query->entityCondition('bundle', $this->field['settings']['handler_settings']['target_bundles'], 'IN');
    }
    if (isset($match)) {
      $entity_info = entity_get_info($this->field['settings']['target_type']);
      if (isset($entity_info['entity keys']['label'])) {
        $query->propertyCondition($entity_info['entity keys']['label'], $match, $match_operator);
      }
    }

    // Add a generic entity access tag to the query.
    $query->addTag($this->field['settings']['target_type'] . '_access');
    $query->addMetaData('op', 'update');
    $query->addTag('entityreference');
    $query->addMetaData('field', $this->field);
    $query->addMetaData('entityreference_selection_handler', $this);

    // Add the sort option.
    if (!empty($this->field['settings']['handler_settings']['sort'])) {
      $sort_settings = $this->field['settings']['handler_settings']['sort'];
      if ($sort_settings['type'] == 'property') {
        $query->propertyOrderBy($sort_settings['property'], $sort_settings['direction']);
      }
      elseif ($sort_settings['type'] == 'field') {
        list($field, $column) = explode(':', $sort_settings['field'], 2);
        $query->fieldOrderBy($field, $column, $sort_settings['direction']);
      }
    }
    return $query;
  }

}