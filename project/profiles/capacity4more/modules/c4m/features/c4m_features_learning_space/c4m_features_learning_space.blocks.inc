<?php

/**
 * @file
 * Learning Space blocks.
 */

/**
 * Block to render the video button.
 *
 * @return mixed
 *   The block array.
 */
function _c4m_features_learning_space_learning_intro_view() {
  // Banner image (if set).
  $intro_image_fid = variable_get('learning_image', '');
  $intro_image_processed = '';
  if ($intro_image_fid) {
    $intro_image_file = file_load($intro_image_fid);
    $intro_image_processed = theme(
      'image_style',
      array(
        'style_name' => 'banner',
        'path' => $intro_image_file->uri,
        'getsize' => FALSE,
      )
    );
  }

  // Introduction text (if set).
  $intro_text = variable_get('learning_intro', '');
  $intro_text_processed = !empty($intro_text) ? check_markup(
    $intro_text['value'],
    $intro_text['format']
  ) : '';

  $content = theme(
    'c4m_features_learning_space_learning_intro',
    array(
      'image' => $intro_image_processed,
      'text' => $intro_text_processed,
    )
  );

  // Return the block.
  $block = array(
    'subject' => NULL,
    'content' => $content,
  );

  return $block;
}
