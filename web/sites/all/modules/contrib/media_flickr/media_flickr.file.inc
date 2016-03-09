<?php

/**
 * @file
 * File hooks implemented by the Media: Flickr module.
 */

/**
 * Implements hook_file_operations().
 */
function media_flickr_file_operations() {
  $operations = array(
    'media_flickr_refresh' => array(
      'label' => t('Refresh Flickr information from source'),
      'callback' => 'media_flickr_cache_clear',
    ),
  );

  return $operations;
}

/**
 * Clear the cached Flickr content for the selected files.
 */
function media_flickr_cache_clear($fids) {
  $fids = array_keys($fids);

  $query = new EntityFieldQuery();
  $results = $query
    ->entityCondition('entity_type', 'file')
    ->propertyCondition('uri', 'flickr:', 'STARTS_WITH')
    ->propertyCondition('fid', $fids)
    ->execute();

  $files = file_load_multiple(array_keys($results['file']));

  foreach ($files as $file) {
    $wrapper = file_stream_wrapper_get_instance_by_uri($file->uri);
    $local_path = $wrapper->getLocalThumbnailPath();
    file_unmanaged_delete($local_path);
  }
}
