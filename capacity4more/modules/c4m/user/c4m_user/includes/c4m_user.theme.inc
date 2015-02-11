<?php
/**
 * @file
 *
 * Custom Display Suite function fields.
 */

/**
 * DS function field.
 *
 * Render ...
 *
 * @param $field
 *
 * @return string
 */
function theme_c4m_user_picture($field) {
  if (empty($field['entity']->uid)) {
    return;
  }

  // Check if image needs to be linked to user profile.
  if (FALSE !== strpos($field['formatter'], 'linked_', 0)) {
    $linked = TRUE;
    $style = substr($field['formatter'], 7);
  }
  else {
    $linked = FALSE;
    $style = $field['formatter'];
  }

  // Check if this is a user or node entity.
  $user = 'user' === $field['entity_type'] ? $field['entity'] :
    user_load($field['entity']->uid);

  // Check if we have an image.
  $wrapper = entity_metadata_wrapper('user', $user);
  $file = $wrapper->c4m_media->value();

  if (empty($file)) {
    // If there is no image, we render initials.
    $output = c4m_user_initials_themed($user, $linked);
  }
  else {
    $file['style_name'] = empty($style) ? 'media_thumbnail' : $style;
    $file['path']       = $file['uri'];
    $file['attributes'] = array('class' => 'user-image');
    $output             = l(theme_image_style($file), 'user/' . $user->uid,
      array('html' => 'TRUE'));
  }

  return $output;
}

/**
 * DS function field.
 *
 * Render Author first and last name.
 *
 * @param $field
 *
 * @return string
 */
function theme_c4m_user_first_and_last_name($field) {
  if (empty($field['entity'])) {
    return;
  }
  $tag = array();
  $entity = $field['entity'];

  if ($entity->uid != 0) {
    $user = user_load($entity->uid);
    $name = c4m_user_name($user);

    if ('linked_user' == $field['formatter']) {
      $name = l($name, 'user/' . $user->uid);
    }

    $tag['element'] = array(
      '#tag'       => 'span',
      '#attributes' => array(
        'class' => array('user-name'),
      ),
      '#value'     => $name,
    );
  }
  else {
    if (!empty($entity->name)) {
      $tag['element'] = array(
        '#tag'       => 'span',
        '#attributes' => array(
          'class' => array('user-name', 'anonymous'),
        ),
        '#value'     => $entity->name,
      );
    }
  }

  return theme_html_tag($tag);
}

/**
 * DS function field.
 *
 * Render ...
 *
 * @param $field
 *
 * @return string
 */
function theme_c4m_user_og_membership_type($field) {
  if (empty($field['entity'])) {
    return;
  }

  $entity = $field['entity'];
  $user   = user_load($entity->uid);

  return '';
}

