<?php

/**
 * @file
 * Node Gallery EntityReference behavior plugin.
 */

/**
 * Node Gallery behavior handler.
 */
class NodeGalleryBehaviorHandler extends EntityReference_BehaviorHandler_Abstract {

  public function access($field, $instance) {
    return $field['settings']['handler'] == 'node_gallery';
  }

  public function load($entity_type, $entities, $field, $instances, $langcode, &$items) {
    // Get the Node galleries.
    foreach ($entities as $entity) {
      $relationships = node_gallery_api_get_relationships(NULL, $entity->nid);
      foreach ($relationships as $relationship) {
        $items[$entity->nid][] = array(
          'target_id' => $relationship->ngid,
        );
      }
    }
  }

  public function insert($entity_type, $entity, $field, $instance, $langcode, &$items) {
    $this->NodeGalleryRelationshipCrud($entity_type, $entity, $field, $instance, $langcode, $items);

    // Don't store relationships in the entityreference field table.
    // Clear them here.
    $items = array();
  }

  public function update($entity_type, $entity, $field, $instance, $langcode, &$items) {
    $this->NodeGalleryRelationshipCrud($entity_type, $entity, $field, $instance, $langcode, $items);

    // Don't store relationships in the entityreference field table.
    // Clear them here.
    $items = array();
  }

  /**
   * Implements EntityReference_BehaviorHandler_Abstract::Delete().
   *
   * CRUD memberships from field, or if entity is marked for deleting,
   * delete all the Node Gallery relationships related to it.
   */
  public function delete($entity_type, $entity, $field, $instance, $langcode, &$items) {
    // Delete all relationships related to this item node.
    $items = array();
    $this->NodeGalleryRelationshipCrud($entity_type, $entity, $field, $instance, $langcode, $items);
  }

  /**
   * Create, update or delete Node Gallery relationships based on field values.
   */
  public function NodeGalleryRelationshipCrud($entity_type, $entity, $field, $instance, $langcode, &$items) {
    $diff = $this->galleriesGetDiff($entity_type, $entity, $field, $instance, $langcode, $items);
    if (!$diff) {
      return;
    }

    $diff += array('insert' => array(), 'delete' => array());

    // Delete first, so we don't trigger cardinality errors.
    if ($diff['delete']) {
      entity_delete_multiple('node_gallery_relationship', array_keys($diff['delete']));
      foreach (array_values($diff['delete']) as $ngid) {
        if (node_gallery_api_get_cover_nid($ngid) == $entity->nid) {
          node_gallery_api_reset_cover_item($ngid);
        }
        node_gallery_api_clear_gallery_caches($ngid);
        node_gallery_api_update_image_counts($ngid);
      }
    }

    if (!empty($diff['insert'])) {
      $relationship_type = node_gallery_api_get_relationship_type(NULL, $entity->type);
      if (!empty($relationship_type)) {
        foreach ($diff['insert'] as $ngid) {
          $r = new NodeGalleryRelationship();
          $r->relationship_type = $relationship_type->id;
          $r->nid = $entity->nid;
          $r->ngid = $ngid;
          $r->weight = NODE_GALLERY_DEFAULT_WEIGHT;
          $r->save();
        }
      }
    }
  }

  /**
   * Get the difference in group audience for a saved field.
   *
   * @return array
   *   Array with all the differences, or an empty array if none found.
   */
  public function galleriesGetDiff($entity_type, $entity, $field, $instance, $langcode, $items) {
    $return = FALSE;

    $current_relationships = node_gallery_api_get_relationships(NULL, $entity->nid);

    $new_relationships = array();
    foreach ($items as $item) {
      $new_relationships[$item['target_id']] = TRUE;
    }

    foreach ($current_relationships as $current_relationship) {
      $ngid = $current_relationship->ngid;
      if (empty($new_relationships[$ngid])) {
        // Relationship was deleted.
        $return['delete'][$current_relationship->id] = $current_relationship->ngid;
        unset($new_relationships[$ngid]);
      }
      else {
        // Existing membership.
        unset($new_relationships[$ngid]);
      }
    }
    if ($new_relationships) {
      // New memberships.
      $return['insert'] = array_keys($new_relationships);
    }

    return $return;
  }

  /**
   * Overrides views_data_alter().
   */
  public function views_data_alter(&$data, $field) {
    // We need to override the default EntityReference table settings when Node
    // Gallery behavior is being used.
    if (!empty($field['settings']['handler_settings']['behaviors']['node_gallery_behavior']['status'])) {
      $data['node_gallery_relationship'] = array(
        'table' => array(
          'join' => array(
            'node' => array(
              'left_field' => 'nid',
              'field' => 'nid',
            ),
          ),
        ),
        $field['field_name'] => $data['field_data_' . $field['field_name']][$field['field_name']],
        $field['field_name'] . '_target_id' => $data['field_data_' . $field['field_name']][$field['field_name'] . '_target_id'],
      );
      $data['node_gallery_relationship'][$field['field_name']]['field']['table'] = 'node_gallery_relationship';
      $data['node_gallery_relationship'][$field['field_name']]['field']['real field'] = 'ngid';
      unset($data['node_gallery_relationship'][$field['field_name']]['field']['additional fields']);

      foreach (array('filter', 'argument', 'sort') as $op) {
        $data['node_gallery_relationship'][$field['field_name'] . '_target_id'][$op]['field'] = 'ngid';
        $data['node_gallery_relationship'][$field['field_name'] . '_target_id'][$op]['table'] = 'node_gallery_relationship';
        unset($data['node_gallery_relationship'][$field['field_name'] . '_target_id'][$op]['additional fields']);
      }

      // Get rid of the original tables.
      unset($data['field_data_' . $field['field_name']]);
      unset($data['field_revision_' . $field['field_name']]);
    }
  }
}
