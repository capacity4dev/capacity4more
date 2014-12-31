<?php
/**
 * @file
 * c4m_user_profile.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function c4m_user_profile_image_default_styles() {
  $styles = array();

  // Exported image style: c4m_user_author_thumb_image.
  $styles['c4m_user_author_thumb_image'] = array(
    'name' => 'c4m_user_author_thumb_image',
    'label' => 'Author Thumbnail Image',
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
          'width' => 75,
          'height' => 75,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
