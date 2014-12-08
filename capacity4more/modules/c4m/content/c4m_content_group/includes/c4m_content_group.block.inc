<?php
/**
 * @file
 * Code for group blocks.
 */

/**
 * The group name.
 */
function _c4m_content_group_block_header_name_banner() {
  $markup = '';
  $content['group-header'] = array(
    '#type' => 'section',
    '#attributes' => array(
      'class' => array('group-header'),
    ),
  );

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

  $content['group-header']['content']['#markup'] = $markup;

  return array(
    'subject' => '',
    'content' => $content,
  );
}
