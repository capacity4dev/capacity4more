<?php
/**
 * @file
 *
 * Custom Display Suite function fields.
 */
/**
 * DS function field.
 *
 * Render node meta data
 * - Author profile image
 * - Author name
 * - Post date
 *
 * @param $field
 * @return string
 */
function theme_c4m_ds_node_meta($field) {
  $output = '';

  if (isset($field['entity'])) {
    $entity = $field['entity'];
    $user = user_load($entity->uid);
    $wrapper = entity_metadata_wrapper('user', $user);

    if ('default' == $field['formatter']) {
      // Retrieve the user profile image.
      $file = $wrapper->c4m_media->value();
      if (!empty($file)) {
        // Check if a particular formatter is chosen, other than default.
        // (Currently not possible as no formatter is defined yet.)
        $file['style_name'] = 'media_thumbnail';
        $file['path'] = $file['uri'];
        $img = theme_image_style($file);
        $output .= l($img, 'user/' . $entity->uid, array('html' => 'TRUE'));
      }
    }

    $name_and_date = '';
    // Retrieve user first and last name.
    $name = $wrapper->c4m_first_name->value() . ' ' .
      $wrapper->c4m_last_name->value();

    if (!empty($name)) {
      $name_link = l($name, 'user/' . $entity->uid);
      if ('default' == $field['formatter']) {
        $name_and_date .= t('information posted by');
      }
      $name_and_date .= $name_link;
    }
    // Retrieve post date.
    $tag['element'] = array(
      '#tag' => 'span',
      '#value' => format_date($entity->changed, 'short'),
    );
    $name_and_date .= theme_html_tag($tag);

    $tag['element'] = array(
      '#tag' => 'div',
      '#value' => $name_and_date,
    );
    $output .= theme_html_tag($tag);
  }
  return $output;
}