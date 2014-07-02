<?php
/**
 * @file
 * c4m_pages.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_pages_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function c4m_pages_image_default_styles() {
  $styles = array();

  // Exported image style: group_banner.
  $styles['group_banner'] = array(
    'name' => 'group_banner',
    'label' => 'Group banner',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 940,
          'height' => 268,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
