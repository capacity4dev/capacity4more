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
 * Render group manager info
 *
 * @param $field
 * @return string
 */
function theme_c4m_ds_group_manager($field) {
  $output = '';

  if (empty($field['entity'])) {
    return $output;
  }
  $entity = $field['entity'];
  $user= user_load($entity->uid);
  $wrapper = entity_metadata_wrapper('user', $user);

  // Name of group manager.
  $tag['element'] = array(
    '#tag' => 'span',
    '#value' => t('Group owner: '),
   );

  $name = theme_html_tag($tag) .
    l($wrapper->c4m_first_name->value() . ' ' .
      $wrapper->c4m_last_name->value(), 'user/' . $user->uid);

  // Profile image of the user as link to profile.
  $tag['element'] = array(
    '#tag' => 'div',
    'attributes' => array(
      'class' => array('group-manager'),
    ),
    '#value' => c4m_ds_node_author_image($user, $field['formatter']) . $name,
  );
  $output .= theme_html_tag($tag);

  return $output;
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
  $output = '';

  if (isset($field['entity'])) {
    $entity = $field['entity'];
    $wrapper = entity_metadata_wrapper('node', $entity);
  }
  else {
    return $output;
  }

  $group_access = $wrapper->group_access->value();

  if ($group_access) {
    $group_type = t('Private group');
  }
  elseif ($pluggable_node_access = $wrapper->pluggable_node_access->value()) {
    $group_type = t('Restricted group');
    //$allowed = c4m_og_get_group_allowed_organisations_domains($entity);
  }
  else {
    $group_type = t('Public group');
  }
  $tag['element'] = array(
    '#tag' => 'h4',
    '#value' => $group_type,
  );
  $output .= theme_html_tag($tag);

  return $output;
}

function theme_c4m_ds_group_role_members($field) {
  $output = '';

  if (empty($field['entity'])) {
    return $output;
  }
  $entity = $field['entity'];

  $members = c4m_og_get_users_by_roles($entity->nid, array($field['formatter']));
  //return '';
  foreach($members as $member) {
    $user = user_load($member->uid);
    $output .= ', ' . l(c4m_user_name($user), 'user/' . $uid);
  }
  return $output;
}

function c4m_user_name($user) {
  $wrapper = entity_metadata_wrapper('user', $user);

  return  $wrapper->c4m_first_name->value() . ' ' .
          $wrapper->c4m_last_name->value();
}
