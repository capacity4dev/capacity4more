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

    if ('minimal' != $field['formatter']) {
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
      $options = array(
        'attributes' => array(
          'class' => array('username'),
        )
      );
      $name_link = l($name, 'user/' . $entity->uid, $options);
      switch($field['formatter']) {
        case 'document_upload':
          $name_and_date .= t('Document uploaded by');
          break;
        case 'default':
        case 'information_post':
          $name_and_date .= t('information posted by');
          break;
      }
      if ('default' == $field['formatter']) {

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

/**
 * Copy of theme_file_entity_download_link() for linking to the file download
 * URL, but customized for C4M.
 *
 * @see theme_file_entity_download_link()
 */
function theme_c4m_ds_formatter_link_and_size($variables) {
  $output = '';
  if ('file' != $variables['entity_type'] ||
    empty($variables['entity']->fid)) {
    return $output;
  }
  else {
    $file = $variables['entity'];
  }

  $uri = file_entity_download_uri($file);

  // Set options as per anchor format described at
  // http://microformats.org/wiki/file-format-examples
  $uri['options']['attributes']['type'] = $file->filemime . '; length=' .
    $file->filesize;

  // Provide the default link text.
  if (!isset($variables['text'])) {
    $variables['text'] = t('Download');
  }

  // Perform unsanitized token replacement if $uri['options']['html'] is empty
  // since then l() will escape the link text.
  $variables['text'] = token_replace($variables['text'], array('file' => $file),
    array('clear' => TRUE, 'sanitize' => !empty($uri['options']['html'])));

  // Download link
  $tag['element'] = array(
    '#tag' => 'p',
    '#attributes' => array(
      'class' => "download-link",
    ),
    '#value' => l($variables['text'], $uri['path'], $uri['options']),
  );
  $inner = theme_html_tag($tag);

  // Filesize
  $tag['element'] = array(
    '#tag' => 'p',
    '#attributes' => array(
      'class' => "file-size",
    ),
    '#value' => t('Filesize') . ': ' . format_size($file->filesize),
  );
  $inner .= theme_html_tag($tag);

  $tag['element'] = array(
    '#tag' => 'div',
    '#value' => $inner,
  );
  $output .= theme_html_tag($tag);

  return $output;
}

/**
 * DS function field.
 *
 * Render preview of document
 *
 * @param $field
 * @return string
 */
function theme_c4m_ds_document_preview($field) {
  $output = '';

  if (isset($field['entity'])) {
    $entity = $field['entity'];

    $tag['element'] = array(
      '#tag' => 'i',
      '#value' => 'To be replaced by document preview.',
    );
    $output .= theme_html_tag($tag);
  }
  return $output;
}

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
function theme_c4m_ds_group_access_info($field) {
  $output = '';

  if (isset($field['entity'])) {
    $entity = $field['entity'];
    $wrapper = entity_metadata_wrapper('node', $entity);
  }
  else {
    return $output;
  }



  $group_access = $wrapper->group_access->value();

  return $output;
}
