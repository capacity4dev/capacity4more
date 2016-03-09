<?php

/**
 * @file
 * Node Gallery API function
 */

/**
 * Get Node Gallery Relationships.
 *
 * @param int $gallery_nid
 *   Gallery NID
 * @param int $item_nid
 *   Item NID
 * @param int $id
 *   Relationship entity ID
 * @param bool $ids_only
 *   If true, skip loading the entities.
 *
 * @return array
 *   Array of Node Gallery relationships matching parameters.
 */
function node_gallery_api_get_relationships($gallery_nid = NULL, $item_nid = NULL, $id = NULL, $ids_only = FALSE) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node_gallery_relationship');
  if (!empty($item_nid)) {
    $query->propertyCondition('nid', $item_nid);
  }
  if (!empty($gallery_nid)) {
    $query->propertyCondition('ngid', $gallery_nid);
  }
  if (!empty($id)) {
    $query->propertyCondition('id', (int) $id);
  }
  $relationships = $query->execute();
  if (!empty($relationships['node_gallery_relationship'])) {
    $relationships = array_keys($relationships['node_gallery_relationship']);
    if ($ids_only) {
      return $relationships;
    }
    return entity_load('node_gallery_relationship', $relationships);
  }
  return array();
}

/**
 * Convenience wrapper for getting all relationships.
 *
 * @return array
 *   An associative array of relationship arrays.
 */
function node_gallery_api_get_all_relationship_types() {
  return node_gallery_api_get_relationship_type(NULL, NULL);
}

/**
 * Fetches a gallery-to-image relationship from the database.
 *
 * If one of either $gallery_type or $item_type are supplied, this function
 * returns a single relationship.  If neither are specified, it returns all
 * relationships, keyed by the gallery content type.  If both are supplied,
 * $item_type will be ignored.
 *
 * @param string $gallery_type
 *   (optional) The content type of the gallery in the relationship.  If
 *   this is an int, we'll use that as the rid.
 *   Defaults to NULL.
 * @param string $item_type
 *   (optional) The content type of the image in the relationship.
 *   Defaults to NULL.
 *
 * @return array
 *   An associative array containing:
 *   - rid: An integer representing the rid column in the database.
 *   - gallery_type: A string that is the content type of the gallery.
 *   - item_type: A string that is the content type of the image.
 *   - filefield_name: The name of the imagefield for the image.
 *   - settings: An associative array of settings for the relationship.
 */
function node_gallery_api_get_relationship_type($gallery_type = NULL, $item_type = NULL, $id = NULL, $reset = FALSE) {
  $relationship_types = &drupal_static(__FUNCTION__);

  if (!isset($relationship_types) || $reset) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node_gallery_relationship_type');
    $entities = $query->execute();
    if (!empty($entities['node_gallery_relationship_type'])) {
      $relationship_types = entity_load('node_gallery_relationship_type', array_keys($entities['node_gallery_relationship_type']));
    }
  }

  if (empty($relationship_types)) {
    return NULL;
  }
  elseif (empty($gallery_type) && empty($item_type) && empty($id)) {
    return $relationship_types;
  }

  $filtered_types = $relationship_types;
  foreach ($filtered_types as $i => $type) {
    if (!empty($id) && $i != $id) {
      unset($filtered_types[$i]);
    }
    if (!empty($gallery_type) && !in_array($gallery_type, $type->settings['relationship_type']['gallery_types'])) {
      unset($filtered_types[$i]);
    }
    if (!empty($item_type) && !in_array($item_type, $type->settings['relationship_type']['item_types'])) {
      unset($filtered_types[$i]);
    }
  }

  if (empty($filtered_types)) {
    return NULL;
  }
  else {
    return array_shift($filtered_types);
  }
}

/**
 * Is this NID a for a gallery node.
 *
 * @param int $nid
 *   NID to check.
 *
 * @return bool
 *   Whether this is a gallery.
 */
function node_gallery_api_is_gallery($nid) {
  return (bool) db_select('node_gallery_galleries', 'ngg')
                  ->fields('ngg', array('ngid'))
                  ->condition('ngid', $nid)
                  ->execute()
                  ->fetchField();
}

/**
 * Gets the count of published images within a gallery.
 *
 * @param int $ngid
 *   The nid of the gallery to query.
 * @param bool $reset
 *   (optional) If TRUE, clears the cache, defaults to FALSE.
 *
 * @return int
 *   A count of all images in the gallery.
 */
function node_gallery_api_get_item_count($ngid, $reset = FALSE) {
  return count(node_gallery_api_get_item_list($ngid, $reset));
}

/**
 * Returns a list of all possible content types of galleries, images, or both.
 *
 * @param string $type
 *   (optional) 'gallery', 'image' or 'all'.
 *
 * @return array
 *   An array containing the list of content types.
 */
function node_gallery_api_get_types($type = 'gallery', $reset = FALSE) {
  $ng_types = &drupal_static(__FUNCTION__);

  if (empty($ng_types) || $reset) {
    $ng_types['gallery'] = array();
    $ng_types['item'] = array();

    $ng_rels = node_gallery_api_get_all_relationship_types();
    if (is_array($ng_rels)) {
      foreach ($ng_rels as $relationship_type) {
        foreach ($relationship_type->gallery_types as $gallery_type) {
          $ng_types['gallery'][] = $gallery_type;
        }
        foreach ($relationship_type->item_types as $item_type) {
          $ng_types['item'][] = $item_type;
        }
      }
    }
  }
  if ($type == 'all') {
    return array_merge($ng_types['gallery'], $ng_types['item']);
  }
  else {
    return $ng_types[$type];
  }
}

/**
 * Retrieves image properties sorted by the image sort view in a
 * gallery, the returned objects are NOT complete nodes.
 *
 * @param object $gallery
 *   The node object of the gallery.
 * @param boolean $sorted
 *   Whether to keep the order as effective in the UI. Defaults to true.
 * @param boolean $filtered
 *   Whether to filter down the resulting images by publish status.
 *
 * @return array
 *   An array of image objects with the basic properties nid,
 *   title, status, created, changed, filepath and weight.
 */
function node_gallery_api_get_items($gallery, $sorted = TRUE, $filtered = TRUE, $reset = FALSE) {
  $items = &drupal_static(__FUNCTION__, array(), $reset);
  $cache_keys[] = 'node_gallery';
  $cache_keys[] = $gallery->nid;
  $cache_keys[] = 'items';
  $cache_keys[] = $sorted ? 'sort-true' : 'sort-false';
  $cache_keys[] = $filtered ? 'filtered-true' : 'filtered-false';
  $cache_key = implode(':', $cache_keys);
  if (!isset($images[$cache_key]) || $reset) {
    if (!$reset && ($cache = cache_get($cache_key)) && !empty($cache->data)) {
      return $cache->data;
    }
    else {
      $items[$cache_key] = array();
      // Get the order currently in effect; the criteria is unknown
      // here because the user can change the view.
      $item_nids = node_gallery_api_get_item_nids($gallery->nid, $sorted, $filtered);
      if (count($item_nids) == 0) {
        cache_set($cache_key, $items[$cache_key], 'cache', CACHE_TEMPORARY);
        return $items[$cache_key];
      }
      // Get CCK information for retrieving the filepath.
      $relationship_type = node_gallery_api_get_relationship_type($gallery->type);
      $field = field_info_field($relationship_type->filefield_name);

      foreach ($item_nids as $nid) {
        $item = node_load($nid);
        if (!empty($relationship_type->filefield_name)) {
          $files = field_get_items('node', $item, $relationship_type->filefield_name);
          if (!empty($files)) {
            $item->node_gallery['item_file'] = $files[0];
            $item->node_gallery['item_file_url'] = file_create_url($files[0]['uri']);
          }
        }
        $items[$cache_key][] = $item;
      }
      cache_set($cache_key, $items[$cache_key], 'cache', CACHE_TEMPORARY);
    }
  }
  return $items[$cache_key];
}

/**
 * Clears all the caches for a specific gallery.
 *
 * @param int $ngid
 *   The nid of the gallery to clear caches on.
 */
function node_gallery_api_clear_gallery_caches($ngid) {
  cache_clear_all('node_gallery:' . $ngid, 'cache', TRUE);
}


/**
 * Batch API sorting callback.
 */
function node_gallery_api_batch_sorting_callback($images, &$context) {
  if (empty($context['sandbox'])) {
    $context['sandbox']['iterator'] = 0;
    $context['sandbox']['count'] = count($images);
    $context['results']['ngid'] = $images[0]['ngid'];
  }
  $context['results'][] = drupal_write_record('node_gallery_relationship', $images[$context['sandbox']['iterator']], 'nid');
  $context['sandbox']['iterator']++;
  if ($context['sandbox']['iterator'] < $context['sandbox']['count']) {
    $context['finished'] = $context['sandbox']['iterator'] / (float) $context['sandbox']['count'];
  }
  else {
    $context['finished'] = 1;
  }
}

/**
 * Batch API sorting finished callback.
 */
function node_gallery_api_batch_sorting_finished($success, $results, $operation) {
  if ($success) {
    // $results contains ['ngid'] as well as the actual results,
    // so we subtract one here.
    $message = format_plural(count($results) - 1, 'One image processed.', '@count images processed.');
  }
  else {
    $message = t('Finished with an error.');
  }
  node_gallery_api_clear_gallery_caches($results['ngid']);
  drupal_set_message($message);
}

/**
 * Get item files from NIDs.
 *
 * @param array $nids
 *   Array of node NIDs.
 * @param string $fieldname
 *   File field name
 *
 * @return array
 *   Files
 */
function node_gallery_api_get_item_file($nids, $fieldname) {
  $fields = &drupal_static(__FUNCTION__, array());
  static $fields = array();

  if ($fieldname == 'node_gallery_none') {
    return array();
  }

  if (!isset($fields[$fieldname])) {
    $field_info = field_info_field($fieldname);
    $fields[$fieldname]['db_info'] = array_shift(array_values($field_info['storage']['details']['sql'][FIELD_LOAD_CURRENT]));
    $fields[$fieldname]['db_info'] += array('table' => array_shift(array_keys($field_info['storage']['details']['sql'][FIELD_LOAD_CURRENT])));
  }
  $query = db_select($fields[$fieldname]['db_info']['table'], 'field_table');
  $query->fields('field_table', array($fields[$fieldname]['db_info']['fid'], 'entity_id'));
  $query->condition('field_table.entity_type', 'node', '=');
  if (!is_array($nids)) {
    $query->condition('field_table.entity_id', $nids, '=');
  }
  else {
    $query->condition('field_table.entity_id', $nids, 'IN');
  }
  $results = $query->execute();
  $files = array();
  foreach ($results as $record) {
    if (!empty($record->{$fields[$fieldname]['db_info']['fid']})) {
      $files[$record->entity_id] = file_load($record->{$fields[$fieldname]['db_info']['fid']});
    }
  }
  // TODO: Get rid of this inconsistency of use.
  if (count($nids) == 1) {
    $files = array_shift($files);
  }
  return $files;
}

/**
 * Batch API save callback.
 */
function node_gallery_api_batch_node_save($nodes, &$context) {
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = count($nodes);
  }
  if (!isset($context['sandbox']['nodes'])) {
    if (is_array($nodes)) {
      $context['sandbox']['nodes'] = $nodes;
    }
    else {
      $context['sandbox']['nodes'] = array($nodes);
    }
  }
  $count = 0;
  while (!empty($context['sandbox']['nodes']) && $count <= NODE_GALLERY_BATCH_CHUNK_SIZE) {
    $count++;
    $node = array_shift($context['sandbox']['nodes']);
    $node = (object) array_merge((array) node_load($node->nid), (array) $node);
    watchdog('batch_save', print_r($node, TRUE));
    node_save_action($node);
    watchdog('batch_save', print_r($node, TRUE));
    $context['sandbox']['progress']++;
  }
  // Let the batch engine know how close we are to completion.
  if ($context['sandbox']['progress'] == $context['sandbox']['max']) {
    // Done!
    $context['finished'] = 1;
  }
  else {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

/**
 * Get the gallery ref field name for a set of types.
 *
 * @param string $gallery_type
 *   Gallery type
 * @param string $item_type
 *   Item type
 * @param int $relationship_type_id
 *   Relationship ID
 *
 * @return bool|string
 *   Name of the ref field, or FALSE is there is not one.
 */
function node_gallery_api_get_item_field_name($gallery_type = NULL, $item_type = NULL, $relationship_type_id = NULL) {
  if (empty($relationship_type_id)) {
    $relationship_type = node_gallery_api_get_relationship_type($gallery_type, $item_type);
    $relationship_id = $relationship_type->id;
  }
  if (!empty($relationship_type_id)) {
    return NODE_GALLERY_REF_FIELD . '_' . $relationship_type_id;
  }
  return FALSE;
}

/**
 * Deletes batches of images for batch API.
 *
 * @param array $imagenids
 *   Array of nids to delete.
 * @param array $context
 *   Array provided by batch API.
 */
function node_gallery_api_batch_node_delete($imagenids, &$context) {
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = count($imagenids);
  }
  if (!isset($context['sandbox']['imagenids'])) {
    if (is_array($imagenids)) {
      $context['sandbox']['imagenids'] = $imagenids;
    }
    else {
      $context['sandbox']['imagenids'] = array($imagenids);
    }
  }
  $count = 0;
  while (!empty($context['sandbox']['imagenids']) && $count <= NODE_GALLERY_BATCH_CHUNK_SIZE) {
    $count++;
    $nid = array_shift($context['sandbox']['imagenids']);
    node_delete($nid);
    $context['sandbox']['progress']++;
  }
  // Let the batch engine know how close we are to completion.
  if ($context['sandbox']['progress'] == $context['sandbox']['max']) {
    // Done!
    $context['finished'] = 1;
  }
  else {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

/**
 * Batch API rotate callback.
 */
function node_gallery_api_batch_rotate($fid, $degrees, &$context) {
  $result = 0;

  $file = file_load($fid);
  $filepath_new = preg_replace_callback(
    '~(?:_r([0-9]+))?(?=(?:\.[^./]*)?$)~',
    create_function('$matches', 'return "_r".(!empty($matches[1]) ? $matches[1]+1 : 1);'),
    $file->uri, 1);
  $new_file = file_move($file, $filepath_new);
  $image = image_load($new_file->uri);
  global $conf;
  $conf['image_jpeg_quality'] = 100;
  if ($image !== FALSE) {
    if ($image->toolkit == 'imagemagick') {
      $result = image_rotate($image, $degrees, 0x000000);
    }
    else {
      $result = image_rotate($image, $degrees);
    }

    image_save($image);
    $new_file->image_dimensions['width'] = $image->width;
    $new_file->image_dimensions['height'] = $image->height;
    file_save($new_file);
    image_path_flush($image->source);
  }
  else {
    watchdog('node_gallery', 'Could not open image for rotation');
  }
  $context['results'][] = $result;
}

/**
 * Used as a finished callback for batch API deletion of images.
 *
 * @param int $success
 *   Scalar provided by batch API.
 * @param array $results
 *   Array provided by batch API.
 * @param array $operations
 *   Array provided by batch API.
 */
function node_gallery_api_batch_item_process_finished($success, $results, $operations) {
  if ($success) {
    drupal_set_message(t('Item modifications complete.'));
    cache_clear_all('node_gallery', 'cache', TRUE);
    cache_clear_all();
  }
  else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    $operation = array_shift($error_operation);
    $arguments = array_shift($error_operation);
    $arguments_as_string = implode(', ', $arguments);
    watchdog('node_gallery', "Error when calling operation '%s'('%s')", array($operation, $arguments_as_string));
    drupal_set_message(t('An error occurred and has been recorded in the system log.'), 'error');
  }
}

/**
 * Default values for relationship types.
 */
function node_gallery_api_relationship_type_settings_defaults() {
  $settings = array(
    'relationship' => array(
      'name' => 'Node Gallery Default',
    ),
    'item_view' => array(
      'display_navigator' => 1,
      'view_navigator_item_display' => 'node_gallery_gallery_image_views:page_7',
      'page_fragment' => 0,
    ),
    'manage_items' => array(
      'items_fields' => array('title' => 'title'),
      'items_per_page' => 20,
      'enable_rotation' => TRUE,
      'rotation_radios' => TRUE,
      'rotation_modal' => TRUE,
    ),
    'og' => array(
      'sync_items' => TRUE,
    ),
  );

  drupal_alter('node_gallery_relationship_default_settings', $settings);
  return $settings;
}

/**
 * Get view mode info for nodes.
 *
 * @return array
 *   All view modes for nodes
 */
function node_gallery_api_get_view_modes() {
  $entity_info = entity_get_info('node');
  $view_modes = array();
  foreach ($entity_info['view modes'] as $name => $info) {
    $view_modes[$name] = $info['label'];
  }
  return $view_modes;
}


/**
 * Gets a sorted list of images nids within a gallery.
 *
 * @param int $ngid
 *   The nid of the gallery to query.
 * @param bool $reset
 *   (optional) If TRUE, clears the cache, defaults to FALSE.
 *
 * @return array
 *   An array of sorted image nids with a status of published.
 */
function node_gallery_api_get_item_list($ngid, $reset = FALSE) {
  $item_list = drupal_static(__FUNCTION__, array(), $reset);

  if (!isset($item_list[$ngid]) || $reset) {
    if (!$reset && ($cache = cache_get('node_gallery:' . $ngid . ':item_list'))) {
      $item_list[$ngid] = $cache->data;
    }
    else {
      _node_gallery_api_cache_sorted_item_nids($ngid);
      $cache = cache_get('node_gallery:' . $ngid . ':item_list');
      $item_list[$ngid] = $cache->data;
    }
  }
  return $item_list[$ngid];
}

/**
 * Builds the caches for a gallery and saves them to the db.
 *
 * There are two caches stored for each gallery.  One is a sorted array of nids
 * that represents the items in proper search order.
 * The second is an associative array where the key is the nid of the image
 * and the value is that nid's respective position in the list (1-based).
 *
 * @param int $ngid
 *   The nid of the gallery to build caches for.
 */
function _node_gallery_api_cache_sorted_item_nids($ngid) {
  $item_list = node_gallery_api_get_item_nids($ngid, TRUE, TRUE);
  $item_position = array();
  $position = 1;
  foreach ($item_list as $nid) {
    $item_position[$nid] = $position;
    $position++;
  }
  cache_set('node_gallery:' . $ngid . ':item_position', $item_position, 'cache', CACHE_TEMPORARY);
  cache_set('node_gallery:' . $ngid . ':item_list', $item_list, 'cache', CACHE_TEMPORARY);
}

/**
 * Gets the first image nid within a gallery.
 *
 * @param int $ngid
 *   The nid of the gallery to query.
 * @param bool $reset
 *   (optional) If TRUE, clears the cache, defaults to FALSE.
 *
 * @return int
 *   The nid of the first image in the gallery.
 */
function node_gallery_api_get_first_item($ngid, $reset = FALSE) {
  $item_list = node_gallery_api_get_item_list($ngid, $reset);
  return $item_list[0];
}

/**
 * Gets the last image nid within a gallery.
 *
 * @param int $ngid
 *   The nid of the gallery to query.
 * @param bool $reset
 *   (optional) If TRUE, clears the cache, defaults to FALSE.
 *
 * @return int
 *   The nid of the last image in the gallery.
 */
function node_gallery_api_get_last_item($ngid, $reset = FALSE) {
  $item_list = node_gallery_api_get_item_list($ngid, $reset);
  return $item_list[count($item_list) - 1];
}

/**
 * Gets the next image in the gallery.
 *
 * @param int $ngid
 *   The nid of the gallery node.
 * @param int $nid
 *   The nid of the image node.
 * @param bool $reset
 *   (optional)  If TRUE, the caches are cleared.
 *
 * @return int
 *   The nid of the next image in the gallery.
 */
function node_gallery_api_get_next_item($ngid, $nid, $reset = FALSE) {
  return node_gallery_api_seek_from_current_item($ngid, $nid, 1, $reset);
}

/**
 * Gets the previous image in the gallery.
 *
 * @param int $ngid
 *   The nid of the gallery node.
 * @param int $nid
 *   The nid of the image node.
 * @param bool $reset
 *   (optional)  If TRUE, the caches are cleared.
 *
 * @return int
 *   The nid of the previous image in the gallery.
 */
function node_gallery_api_get_prev_item($ngid, $nid, $reset = FALSE) {
  return node_gallery_api_seek_from_current_item($ngid, $nid, -1, $reset);
}

/**
 * Returns the nid of the image +/-N steps away from the current image node.
 *
 * @param int $ngid
 *   The nid of the gallery to query.
 * @param int $nid
 *   The nid of the current image.
 * @param int $seek
 *   The postive or negative number of slots to seek to.
 * @param bool $reset
 *   (optional) If TRUE, clears the caches.  Defaults to FALSE.
 */
function node_gallery_api_seek_from_current_item($ngid, $nid, $seek, $reset) {
  $item_list = node_gallery_api_get_item_list($ngid, $reset);
  $current_position = node_gallery_api_get_item_position($ngid, $nid, $reset);
  $current_index = $current_position - 1;
  $seek_index = $current_index + $seek;

  return isset($item_list[$seek_index]) ? $item_list[$seek_index] : NULL;
}

/**
 * Publishes the child image nodes when publishing a gallery.
 *
 * When publishing a gallery, we publish the image nodes within that gallery.
 * We use batch api to provide for galleries with a large amount of images.
 *
 * @param object $node
 *   A reference to a gallery node object
 * @param int $status
 *   The new publish status to set on the node
 */
function _node_gallery_api_set_publish(&$node, $status) {
  $ngid = $node->nid;
  $imagenids = node_gallery_api_get_item_nids($ngid, FALSE, FALSE);
  // Split our operations into NODE_GALLERY_BATCH_CHUNK_SIZE a time.
  $node_updates = array_chunk($imagenids, NODE_GALLERY_BATCH_CHUNK_SIZE);
  array_walk_recursive($node_updates,
            create_function('&$v,$k,$status', '$v = (object)array(\'nid\' => $v, \'status\' => $status);'), $status);
  foreach ($node_updates as $node_update) {
    $operations[] = array('node_gallery_api_batch_node_save', array($node_update));
  }
  if (!empty($operations)) {
    $batch = array(
      'operations' => $operations,
      'finished' => 'node_gallery_api_item_process_finished',
      'title' => t('Processing gallery publish status update.'),
      'init_message' => t('Gallery publish status is cascading to images.'),
      'progress_message' => t('Processing publishing of images.'),
      'error_message' => t('Image publish status change has encountered an error.'),
    );
    batch_set($batch);
    node_gallery_api_clear_gallery_caches($ngid);
  }
}

/**
 * Get all item NIDs for a Gallery
 */
function node_gallery_api_get_item_nids($ngid, $sorted = TRUE, $filtered = TRUE, $fallback = FALSE, $reset = FALSE) {
  static $nids = array();
  $cache_keys[] = 'node_gallery';
  $cache_keys[] = $ngid;
  $cache_keys[] = 'item_nids';
  $cache_keys[] = $sorted ? 'sort-true' : 'sort-false';
  $cache_keys[] = $filtered ? 'filtered-true' : 'filtered-false';
  $cache_keys[] = $fallback ? 'fallback-true' : 'fallback-false';
  $cache_key = implode(':', $cache_keys);
  if (!isset($nids[$cache_key]) || $reset) {
    if (!$reset && ($cache = cache_get($cache_key)) && !empty($cache->data)) {
      $nids[$cache_key] = $cache->data;
    }
    else {
      if (!$fallback) {
        $gallery = node_load($ngid);
        $relationship_type = node_gallery_api_get_relationship_type($gallery->type);
        $view_name = '';
        $view_display = '';
        if (!empty($relationship_type->settings['item_view']['view_navigator_item_display'])) {
          list($view_name, $view_display) = explode(':', $relationship_type->settings['item_view']['view_navigator_item_display']);
        }

        if (isset($view_name)) {
          $view = views_get_view($view_name);
          if (isset($view->display[$view_display])) {
            $view->set_display($view_display);
            $view->set_arguments(array($gallery->nid));
            if (!$sorted) {
              $sorts = $view->get_items('sort', $view_display);
              foreach ($sorts as $sort) {
                $view->set_item($view_display, 'sort', $sort['id'], NULL);
              }
            }
            if (!$filtered) {
              $filters = $view->get_items('filter', $view_display);
              foreach ($filters as $filter) {
                $view->set_item($view_display, 'filter', $filter['id'], NULL);
              }
            }
            $view->build();
            if (isset($view->field['nid'])) {
              $query = $view->build_info['query'];
              $query_field_name = $view->field['nid']->field_alias;
            }
            else {
              $message = t("Found the image sort view, but the 'Node: Nid' field wasn't found.", array());
            }
          }
        }
      }
      if (isset($message) || $fallback || !isset($query)) {
        $query_field_name = 'nid';
        $query = db_select('node_gallery_relationship', 'ng')->fields('ng', array('nid'));
        $query->join('node', 'n', 'ng.nid = n.nid');
        // Use our default sql.
        if (isset($message)) {
          if (user_access('administer node gallery')) {
            drupal_set_message($message, 'warning');
          }
          watchdog('node_gallery', $message, NULL, WATCHDOG_WARNING);
        }
        if ($filtered) {
          $query->condition('n.status', 1);
        }
        if ($sorted) {
          $query->orderBy('ng.weight', 'ASC');
          $query->orderBy('n.nid', 'ASC');
        }
        $query->condition('ng.ngid', $ngid);
      }
      $result = $query->execute();
      $nids[$cache_key] = array();
      foreach ($result as $r) {
        $nids[$cache_key][] = $r->{$query_field_name};
      }
      cache_set($cache_key, $nids[$cache_key], 'cache', CACHE_TEMPORARY);
    }
  }
  return $nids[$cache_key];
}

/**
 * Returns the position (starting at one) of the image in the gallery list.
 *
 * @param int $ngid
 *   The nid of the gallery to use.
 * @param int $nid
 *   The nid of the image to return the position of.
 *
 * @return int
 *   The position of the image in the list of published images in the gallery.
 */
function node_gallery_api_get_item_position($ngid, $nid, $reset = FALSE) {
  static $item_position = array();

  if (!isset($item_position[$ngid]) || $reset) {
    if (!$reset && ($cache = cache_get('node_gallery:' . $ngid . ':item_position')) && !empty($cache->data)) {
      $item_position[$ngid] = $cache->data;
    }
    else {
      _node_gallery_api_cache_sorted_item_nids($ngid);
      $cache = cache_get('node_gallery:' . $ngid . ':item_position');
      $item_position[$ngid] = $cache->data;
    }
  }
  return $item_position[$ngid][$nid];
}

/**
 * Given a gallery, returns it's cover image.
 *
 * @param int $ngid
 *   A populated node object.
 *
 * @return int
 *   The nid of the cover image.
 */
function node_gallery_api_get_cover_nid($ngid) {
  return db_query("SELECT cover_item FROM {node_gallery_galleries} WHERE ngid = :ngid", array(':ngid' => $ngid))->fetchField();
}

/**
 * Sets the cover image in the DB if necessary.
 *
 * @param int $item_nid
 *   A reference to the node object of a node gallery image.
 */
function node_gallery_api_set_gallery_cover_item($item_nid, $ngid = NULL) {
  if (empty($ngid)) {
    $relationships = node_gallery_api_get_relationships(NULL, $item_nid);
    if (!empty($relationships)) {
      $relationship = array_shift($relationships);
      $ngid = $relationships->ngid;
    }
    if (empty($ngid)) {
      return FALSE;
    }
  }
  db_update('node_gallery_galleries')
    ->fields(array('cover_item' => $item_nid))
      ->condition('ngid', $ngid)
      ->execute();

  return TRUE;
}

/**
 * Reset Gallery cover.
 *
 * @param int $ngid
 *   Gallery NID
 */
function node_gallery_api_reset_cover_item($ngid) {
  $new_cover = db_query('SELECT nid FROM {node_gallery_relationship} WHERE ngid = :ngid LIMIT 1',
                array(':ngid' => $ngid))->fetchField();
  if ($new_cover !== FALSE) {
    $result = db_update('node_gallery_galleries')
      ->fields(array('cover_item' => $new_cover))
      ->condition('ngid', $ngid)
      ->execute();
  }
  else {
    // Gallery is now empty, set cover to NULL.
    db_update('node_gallery_galleries')
      ->fields(array('cover_item' => NULL))
      ->condition('ngid', $ngid)
      ->execute();
  }
}

/**
 * Get all entity reference fields with Node Gallery behavior.
 *
 * @return array
 *   EntityReference fields
 */
function node_gallery_api_get_gallery_ref_fields() {
  $gallery_ref_fields = &drupal_static(__FUNCTION__);

  if (!isset($gallery_ref_fields)) {
    $gallery_ref_fields = array();
    $fields = field_info_fields();
    foreach ($fields as $field_name => $field_info) {
      if ($field_info['type'] == 'entityreference' && !empty($field_info['settings']['handler_settings']['behaviors']['node_gallery_behavior']['status'])) {
        $gallery_ref_fields[$field_name] = $field_info;
      }
    }
  }
  return $gallery_ref_fields;
}

/**
 * Check if we need to update this image.
 */
function node_gallery_api_items_check_update($old_image, $_new_image, $compare_fields) {
  // a list of node attributes that are flattened one level by node_save
  $flattened_attributes = array('options');

  $new_image = clone $_new_image;
  $new_image = node_submit($new_image);

  if ($extra = node_invoke($new_image, 'presave')) {
    foreach ($extra as $key => $value) {
      $new_image->$key = $value;
    }
  }
  if ($extra = module_invoke_all('node_presave', $new_image)) {
    foreach ($extra as $key => $value) {
      $new_image->$key = $value;
    }
  }
  if ($extra = node_invoke($old_image, 'presave')) {
    foreach ($extra as $key => $value) {
      $old_image->$key = $value;
    }
  }
  if ($extra = module_invoke_all('node_presave', $old_image)) {
    foreach ($extra as $key => $value) {
      $old_image->$key = $value;
    }
  }

  foreach ($compare_fields as $f) {
    if (in_array($f, $flattened_attributes)) {
      // We make the old node look like the new one,
      // ie $old_node->options['status'] = $old_node->status
      foreach (array_keys($new_image->{$f}) as $option) {
        $old_image->{$f}[$option] = $old_image->$option;
      }
    }
    //a hack for cck field validate;
    if (is_array($new_image->{$f})) {
      foreach ($new_image->{$f} as &$ff) {
        if (is_array($ff)) {
          unset($ff['_error_element']);
        }
      }
    }
    if ($new_image->{$f} != $old_image->{$f}) {
      return TRUE;
    }
  }
  return FALSE;
}


/**
 * Update image counts related to the Node Gallery node.
 *
 * @param int $ngid
 *   a gallery or an image node object
 */
function node_gallery_api_update_image_counts($ngid) {
  $res = db_query("SELECT n.status AS status, COUNT(*) AS num
     FROM {node_gallery_relationship} ngi
     INNER JOIN {node} n ON ngi.nid = n.nid
     WHERE ngi.ngid = :ngid GROUP BY n.status", array(':ngid' => $ngid));
  $counts = array(
    0 => 0,
    1 => 0,
  );
  foreach ($res as $row) {
    $counts[(int) $row->status] = (int) $row->num;
  }
  db_update('node_gallery_galleries')
  ->fields(array(
    'item_count' => $counts[0] + $counts[1],
    'pub_item_count' => $counts[1],
  ))
  ->condition('ngid', $ngid)
  ->execute();
}

/**
 * Returns an array of galleries, suitable for use in a form select.
 *
 * @param string $type
 *   The content type of the galleries to be queried.
 * @param int $uid
 *   (optional) if specified, the list returned will only contain
 *   galleries the user can modify.
 *
 * @return array
 *   Associative array where the keys are the nid, and the value
 *   is the node title.
 */
function node_gallery_api_get_gallery_list($type, $uid = NULL) {
  $query = db_select('node', 'n')->fields('n', array('nid', 'title'))->condition('type', $type);
  $items = array();
  if ($uid) {
    $query->condition('uid', $uid);
  }
  $result = $query->execute();
  foreach ($result as $r) {
    $items[$r->nid] = $r->title;
  }
  return $items;
}


/**
 * Helper function to sort items by Datetime
 *
 * @param object $oa
 *   The left term of the sorting-comparison. Must have an original_DateTime
 *   member.
 * @param object $ob
 *   Idem as $oa, being the right term.
 *
 * @return int
 *   Return 0 if the original_DateTime member of each given objects are equal
 *   -1 if oa's original_DateTime is smaller
 *   +1 else
 */
function node_gallery_api_original_datetime_chronological_sort($oa, $ob) {
  $a = $oa->original_DateTime;
  $b = $ob->original_DateTime;
  if ($a == $b) {
    return 0;
  }
  return $a < $b ? -1 : 1;
}

/**
 * Returns the original date and time creation of associated item_file from EXIF data
 *
 * @param object $file
 *
 * @return DateTime
 *   Or NULL
 */

function node_gallery_api_original_datetime_from_exif($item) {
  if (!empty($item->node_gallery['item_file']['uri']) && !empty($item->node_gallery['item_file']['type']) && $item->node_gallery['item_file']['type'] == 'image') {
    $exif = exif_read_data(drupal_realpath($item->node_gallery['item_file']['uri']));
    if (!empty($exif['DateTimeOriginal'])) {
      return new DateTime($exif['DateTimeOriginal']);
    }
  }
  return NULL;
}

/**
 * Metadata Controller for Node Gallery Relationships
 */
class NodeGalleryRelationshipMetadataController extends EntityDefaultMetadataController {

  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    $properties['nid']['type'] = 'node';
    $properties['nid']['label'] = t('Gallery Item');
    $properties['nid']['description'] = t('The Gallery Item associated with the Node Gallery relationship');
    $properties['ngid']['type'] = 'node';
    $properties['ngid']['label'] = t('Gallery');
    $properties['ngid']['description'] = t('The Gallery associated with the Node Gallery relationship');
    $properties['relationship_type']['type'] = 'node_gallery_relationship_type';
    $properties['relationship_type']['label'] = t('Relationship Type');
    $properties['relationship_type']['description'] = t('The Relationship Type of the Node Gallery relationship.');
    $properties['weight']['label'] = t('Item Weight (Sort Order)');
    $properties['weight']['description'] = t('The Item Weight (sort order) of the Node Gallery relationship.');

    return $info;
  }
}

/**
 * Metadata Controller for Node Gallery Relationship Types
 */
class NodeGalleryRelationshipTypeMetadataController extends EntityDefaultMetadataController {

  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    $properties['filefield_name']['label'] = t('File Field Name');
    $properties['filefield_name']['description'] = t('The name of the file field for this Node Gallery relationship type.');

    return $info;
  }

}