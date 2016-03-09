<?php

/**
 * @file
 * Rules module integration.
 */

/**
 * Implements hook_rules_action_info().
 */
function node_gallery_api_rules_action_info() {
  $items = array();

  $items['node_gallery_api_gallery_get_items'] = array(
    'label' => t('Get gallery items from a gallery'),
    'group' => t('Node Gallery'),
    'parameter' => array(
      'gallery' => array(
        'type' => 'node',
        'label' => t('Gallery'),
        'description' => t('The gallery for which to fetch items.'),
        'wrapped' => TRUE,
      ),
    ),
    'provides' => array(
      'gallery_items' => array('type' => 'list<node>', 'label' => t('Gallery items')),
    ),
    'base' => 'node_gallery_api_rules_gallery_get_items',
  );

  $items['node_gallery_api_item_get_galleries'] = array(
    'label' => t('Get galleries from a gallery item'),
    'group' => t('Node Gallery'),
    'parameter' => array(
      'item' => array(
        'type' => 'node',
        'label' => t('Gallery Item'),
        'description' => t('The gallery item for which to fetch galleries.'),
        'wrapped' => TRUE,
      ),
    ),
    'provides' => array(
      'galleries' => array('type' => 'list<node>', 'label' => t('Item Galleries')),
    ),
    'base' => 'node_gallery_api_rules_item_get_galleries',
  );

  $items['node_gallery_api_item_add'] = array(
    'label' => t('Add item to gallery'),
    'group' => t('Node Gallery'),
    'parameter' => array(
      'item' => array(
        'type' => 'node',
        'label' => t('Gallery Item'),
        'description' => t('The gallery item which is to be added to a gallery.'),
        'wrapped' => TRUE,
        'save' => TRUE,
      ),
      'gallery' => array(
        'type' => 'node',
        'label' => t('Gallery'),
        'wrapped' => TRUE,
      ),
    ),
    'base' => 'node_gallery_api_rules_item_add',
  );

  $items['node_gallery_api_item_remove'] = array(
    'label' => t('Remove item from gallery'),
    'group' => t('Node Gallery'),
    'parameter' => array(
      'item' => array(
        'type' => 'node',
        'label' => t('Gallery Item'),
        'description' => t('The gallery item which is to be removed from a gallery.'),
        'wrapped' => TRUE,
        'save' => TRUE,
      ),
      'gallery' => array(
        'type' => 'node',
        'label' => t('Gallery'),
        'wrapped' => TRUE,
      ),
    ),
    'base' => 'node_gallery_api_rules_item_remove',
  );

  $items['node_gallery_api_gallery_set_cover'] = array(
    'label' => t('Set cover item of a gallery'),
    'group' => t('Node Gallery'),
    'parameter' => array(
      'item' => array(
        'type' => 'node',
        'label' => t('Gallery Item'),
        'description' => t('The gallery item which is to be the cover item.'),
        'wrapped' => TRUE,
        'save' => TRUE,
      ),
      'gallery' => array(
        'type' => 'node',
        'label' => t('Gallery'),
        'description' => t('The gallery to set the cover on. Leaving this empty will set the cover item for all galleries the item is in.'),
        'wrapped' => TRUE,
        'optional' => TRUE,
      ),
    ),
    'base' => 'node_gallery_api_rules_gallery_set_cover',
  );

  $items['node_gallery_api_item_set_weight'] = array(
    'label' => t('Set weight (sort order) of an item in a gallery'),
    'group' => t('Node Gallery'),
    'parameter' => array(
      'item' => array(
        'type' => 'node',
        'label' => t('Gallery Item'),
        'description' => t('The gallery item which is to be updated.'),
        'wrapped' => TRUE,
        'save' => TRUE,
      ),
      'weight' => array(
        'type' => 'integer',
        'label' => t('Weight'),
        'description' => t('The weight for the gallery item.'),
        'save' => TRUE,
      ),
      'gallery' => array(
        'type' => 'node',
        'label' => t('Gallery'),
        'description' => t('The gallery to set the item weight on. Leaving this empty will set the item weight for all galleries the item is in.'),
        'wrapped' => TRUE,
        'optional' => TRUE,
      ),
    ),
    'base' => 'node_gallery_api_rules_item_set_weight',
  );

  return $items;
}

/**
 * Rules action for adding a gallery item to a gallery.
 *
 * @param object $item_wrapper
 *   Gallery Item
 * @param object $gallery_wrapper
 *   Gallery
 */
function node_gallery_api_rules_item_add($item_wrapper, $gallery_wrapper) {
  $relationship_type = node_gallery_api_get_relationship_type($gallery_wrapper->type->value(), $item_wrapper->type->value());
  if (!empty($relationship_type)) {
    $field_name = node_gallery_api_get_item_field_name(NULL, NULL, $relationship_type->id);
    $galleries = $item_wrapper->{$field_name}->value();
    if (!is_array($galleries)) {
      // If cardinality == 1, entity wrapper gives us an object.
      // In this case, replace existing gallery.
      $galleries = $gallery_wrapper->value();
    }
    else {
      $galleries[] = $gallery_wrapper->value();
    }
    $item_wrapper->{$field_name}->set($galleries);
  }
}

/**
 * Rules action for removing a gallery item from a gallery.
 *
 * @param object $item_wrapper
 *   Gallery Item
 * @param object $gallery_wrapper
 *   Gallery
 */
function node_gallery_api_rules_item_remove($item_wrapper, $gallery_wrapper) {
  $relationships = node_gallery_api_get_relationships($gallery_wrapper->nid->value(), $item_wrapper->nid->value());
  if (!empty($relationships)) {
    foreach ($relationships as $relationship) {
      $field_name = node_gallery_api_get_item_field_name(NULL, NULL, $relationship->relationship_type);
      $galleries = $item_wrapper->{$field_name}->value();
      if (!is_array($galleries)) {
        // If cardinality == 1, entity wrapper gives us an object.
        if ($galleries->nid == $gallery_wrapper->nid->value()) {
          $item_wrapper->{$field_name}->set(NULL);
        }
      }
      else {
        foreach ($galleries as $i => $g) {
          if ($g->nid == $gallery_wrapper->nid->value()) {
            $item_wrapper->{$field_name}->offsetUnset($i);
          }
        }
      }
    }
  }
}

/**
 * Rules action for setting the cover item of a gallery.
 *
 * @param object $item_wrapper
 *   Gallery Item
 * @param object $gallery_wrapper
 *   Gallery, if null, will set cover for all galleries
 */
function node_gallery_api_rules_gallery_set_cover($item_wrapper, $gallery_wrapper = NULL) {
  if (in_array($item_wrapper->type->value(), node_gallery_api_get_types('item'))) {
    $gallery_nid = !empty($gallery_wrapper) ? $gallery_wrapper->nid->value() : NULL;
    $relationships = node_gallery_api_get_relationships($gallery_nid, $item_wrapper->nid->value());
    foreach ($relationships as $relationship) {
      if ($item_wrapper->nid->value() != node_gallery_api_get_cover_nid($relationship->ngid)) {
        node_gallery_api_set_gallery_cover_item($item_wrapper->nid->value(), $relationship->ngid);
      }
    }
  }
}

/**
 * Rules action for setting the weight of a gallery item in a gallery.
 *
 * @param object $item_wrapper
 *   Gallery Item
 * @param int $weight
 *   New item weight.
 * @param object $gallery_wrapper
 *   Gallery, if null, will set weight for all galleries
 */
function node_gallery_api_rules_item_set_weight($item_wrapper, $weight, $gallery_wrapper = NULL) {
  if (in_array($item_wrapper->type->value(), node_gallery_api_get_types('item'))) {
    $gallery_nid = !empty($gallery_wrapper) ? $gallery_wrapper->nid->value() : NULL;
    $relationships = node_gallery_api_get_relationships($gallery_nid, $item_wrapper->nid->value());
    foreach ($relationships as $relationship) {
      if ($weight != $relationship->weight) {
        $relationship->weight = $weight;
        $relationship->save();
      }
    }
  }
}

/**
 * Rules action retrieving all gallery items from a gallery.
 *
 * @param object $gallery_wrapper
 *   Gallery
 * @return array
 *   Array of Gallery Items
 */
function node_gallery_api_rules_gallery_get_items($gallery_wrapper) {
  $items = array();
  if (!empty($gallery_wrapper)) {
    $relationships = node_gallery_api_get_relationships($gallery_wrapper->nid->value());
    foreach ($relationships as $relationship) {
      $items[] = node_load($relationship->nid);
    }
  }
  return array('gallery_items' => $items);
}

/**
 * Rules action retrieving all galleries from a gallery item.
 *
 * @param object $item_wrapper
 *   Gallery Item
 *
 * @return array
 *   Array of Galleries
 */
function node_gallery_api_rules_item_get_galleries($item_wrapper) {
  $galleries = array();
  if (!empty($item_wrapper)) {
    $relationships = node_gallery_api_get_relationships(NULL, $item_wrapper->nid->value());
    foreach ($relationships as $relationship) {
      $galleries[] = node_load($relationship->nid);
    }
  }
  return array('galleries' => $galleries);
}

/**
 * Implements hook_rules_condition_info().
 */
function node_gallery_api_rules_condition_info() {
  $items = array();
  $items['node_gallery_item_in_gallery'] = array(
    'label' => t('Item is in gallery'),
    'group' => t('Node Gallery'),
    'parameter' => array(
      'item' => array(
        'type' => 'node',
        'label' => t('Gallery item'),
        'description' => t('The gallery item which will be checked.'),
        'wrapped' => TRUE,
      ),
      'gallery_nid' => array(
        'type' => 'integer',
        'label' => t('Gallery Node NID'),
        'description' => t('The gallery NID which will be checked. If left empty, will check for any gallery.'),
        'optional' => TRUE,
      ),
    ),
    'base' => 'node_gallery_api_rules_condition_item_in_gallery',
  );
  $items['node_gallery_is_gallery_type'] = array(
    'label' => t('Node is gallery type'),
    'group' => t('Node Gallery'),
    'parameter' => array(
      'gallery' => array(
        'type' => 'node',
        'label' => t('Gallery'),
        'wrapped' => TRUE,
      ),
    ),
    'base' => 'node_gallery_api_rules_condition_is_gallery_type',
  );
  $items['node_gallery_is_item_type'] = array(
    'label' => t('Node is gallery item type'),
    'group' => t('Node Gallery'),
    'parameter' => array(
      'item' => array(
        'type' => 'node',
        'label' => t('Gallery Item'),
        'wrapped' => TRUE,
      ),
    ),
    'base' => 'node_gallery_api_rules_condition_is_item_type',
  );
  return $items;
}

/**
 * Rules condition for checking if a node is a gallery type.
 *
 * @param object $gallery_wrapper
 *   the node to check
 *
 * @return bool
 *   is gallery type
 */
function node_gallery_api_rules_condition_is_gallery_type($gallery_wrapper) {
  return in_array($gallery_wrapper->type->value(), node_gallery_api_get_types('gallery'));
}

/**
 * Rules condition for checking if a node is a gallery item type.
 *
 * @param object $item_wrapper
 *   the node to check
 *
 * @return bool
 *   Is a gallery item type
 */
function node_gallery_api_rules_condition_is_item_type($item_wrapper) {
  return in_array($item_wrapper->type->value(), node_gallery_api_get_types('item'));
}

/**
 * Rules condition for checking if a gallery item is in a gallery.
 *
 * @param object $item_wrapper
 *   Gallery Item
 * @param int $gallery_nid
 *   Gallery NID. if null, will check if item is in any gallery.
 *
 * @return bool
 *   Item is in gallery
 */
function node_gallery_api_rules_condition_item_in_gallery($item_wrapper, $gallery_nid = NULL) {
  $relationships = node_gallery_api_get_relationships($gallery_nid, $item_wrapper->nid->value());
  return !empty($relationships);
}
