<?php

/**
 * @file
 * c4m_field_banner.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function c4m_field_banner_image_default_styles() {
  $styles = array();

  // Exported image style: banner.
  $styles['banner'] = array(
    'label' => 'Banner',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 960,
          'height' => 306.383,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
