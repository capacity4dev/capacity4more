<?php

/**
 * @file
 * c4m_content_photoalbum.file_default_displays.inc
 */

/**
 * Implements hook_file_default_displays().
 */
function c4m_content_photoalbum_file_default_displays() {
  $export = array();

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__node_gallery_api_admin_thumbnail__file_image';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'node_gallery_api_admin_thumbnail',
  );
  $export['image__node_gallery_api_admin_thumbnail__file_image'] = $file_display;

  return $export;
}
