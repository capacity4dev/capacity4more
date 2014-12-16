<?php
/**
 * @file
 *
 * Custom Display Suite function fields.
 */


/**
 * DS function field.
 *
 * Render Author profile image
 *
 * @param $field
 * @return string
 */
function theme_c4m_ds_node_author_image($field) {
  if (empty($field['entity'])) {
    return;
  }

  $entity = $field['entity'];
  $user = user_load($entity->uid);
  return c4m_ds_node_author_image($user, $field['formatter']);
}

/**
 * Helper function to render C4M user image based on a user entity.
 *
 * @param $user
 * @return string
 */
function c4m_ds_node_author_image($user, $style = NULL) {
  $output = '';
  $wrapper = entity_metadata_wrapper('user', $user);
  $file = $wrapper->c4m_media->value();
  if (!empty($file)) {
    $file['style_name'] = empty($style) ? 'media_thumbnail' : $style;
    $file['path'] = $file['uri'];
    $file['attributes'] = array('class' => 'user-image');
    $img = theme_image_style($file);
    $output = l($img, 'user/' . $user->uid, array('html' => 'TRUE'));
  }
  return $output;
}

/**
 * DS function field.
 *
 * Render Author first and last name.
 *
 * @param $field
 * @return string
 */
function theme_c4m_ds_author_first_and_last_name($field) {
  if (empty($field['entity'])) {
    return;
  }
  $entity = $field['entity'];
  $user= user_load($entity->uid);
  $name = c4m_user_name($user);
  if ('author_link' == $field['formatter']) {
    $name = l($name, 'user/' . $user->uid);
  }

  $tag['element'] = array(
    '#tag' => 'span',
    'attributes' => array(
      'class' => array('username'),
    ),
    '#value' => $name,
  );

  return theme_html_tag($tag);
}

/**
 * DS function field.
 *
 * Render Author first and last name.
 *
 * @param $field
 * @return string
 */
function theme_c4m_ds_content_type_icon($field) {
  if (empty($field['entity'])) {
    return;
  }
  $object = $field['entity'];

  $icon_name = $object->type;

  if ($icon_name == 'discussion') {
    $object_wrapper = entity_metadata_wrapper('node', $object);
    // Icon image file name is the discussion type of the discussion node.
    $icon_name = 'discussion-' . $object_wrapper->c4m_discussion_type->value();
  }

  $variables['icon'] = $icon_name;

  return '<span class="node-icon as-' . $icon_name . '"> </span>';
}

/**
 * DS function field.
 *
 * Render group type info
 *
 * @param $field
 * @return string
 */
function theme_c4m_ds_group_access_info($field) {
  if (!isset($field['entity'])) {
    return NULL;
  }

  $group_access = c4m_og_get_access_type($field['entity']);
  $tag['element'] = array(
    '#tag' => 'h4',
    '#value' => $group_access['title'],
  );
  return theme_html_tag($tag);
}

/**
 * DS function field.
 *
 * Render members of a group with particular role.
 *
 * @param $field
 * @return string
 */
function theme_c4m_ds_group_role_members($field) {
  $output = '';

  if (empty($field['entity'])) {
    return $output;
  }
  $entity = $field['entity'];

  $members = c4m_og_get_users_by_roles($entity->nid, array($field['formatter']));

  foreach ($members as $member) {
    $user = user_load($member->uid);
    $output .= ', ' . l(c4m_user_name($user), 'user/' . $member->uid);
  }
  return ltrim($output, ', ');
}

/**
 * Helper function to render user first and last name in one string using the
 * user entity.
 *
 * @param $user
 * @return string
 */
function c4m_user_name($user) {
  $wrapper = entity_metadata_wrapper('user', $user);

  return  $wrapper->c4m_first_name->value() . ' ' .
          $wrapper->c4m_last_name->value();
}
