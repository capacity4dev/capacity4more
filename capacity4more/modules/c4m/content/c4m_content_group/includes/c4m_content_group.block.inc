<?php
/**
 * @file
 * Code for group blocks.
 */
/**
 * Function to preprocess a block.
 *
 * We set classes here to avoid another wrapper div within the block.
 *
 * @param $variables
 */
function _c4m_content_group_preprocess_header_name_banner(&$variables) {
  // First establish the current group.
  $group = c4m_og_current_group();
  $wrapper = entity_metadata_wrapper('node', $group);

  // Retrieve group access info.
  $group_access = c4m_og_access_info_by_group($group);

  if (!empty($group_access['type'])) {
    $variables['classes_array'][] = drupal_html_class($group_access['type'] .
      '-group');
  }
}
/**
 * The group name.
 */
function _c4m_content_group_block_header_name_banner() {
  $markup = '';

  // First establish the current group.
  $group = c4m_og_current_group();
  $wrapper = entity_metadata_wrapper('node', $group);

  $title = $wrapper->title->value();
  $tag['element'] = array(
    '#tag' => 'h1',
    '#attributes' => array(
      'class' => array('group-title'),
    ),
    '#value' => $title,
  );

  $markup = theme_html_tag($tag);

  if (drupal_is_front_page()) {
    // Add group image
    $file = $wrapper->c4m_banner->value();
    if (!empty($file)) {
      $file['style_name'] = 'banner';
      $file['path'] = $file['uri'];
      $file['attributes'] = array('class' => 'group-banner');
      $markup .= theme_image_style($file);
    }
  }

  return array(
    'subject' => '',
    'content' => $markup,
  );
}
