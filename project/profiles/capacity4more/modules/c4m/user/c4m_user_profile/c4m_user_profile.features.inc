<?php

/**
 * @file
 * c4m_user_profile.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_user_profile_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function c4m_user_profile_image_default_styles() {
  $styles = array();

  // Exported image style: c4m_user_author_thumb_image.
  $styles['c4m_user_author_thumb_image'] = array(
    'label' => 'Author Thumbnail Image',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 75,
          'height' => 75,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
