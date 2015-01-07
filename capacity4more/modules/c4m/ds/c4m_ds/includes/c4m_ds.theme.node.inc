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
 *
 * @return string
 */
function theme_c4m_ds_node_author_image($field) {
  if (empty($field['entity'])) {
    return;
  }

  $entity = $field['entity'];
  $user   = user_load($entity->uid);

  return c4m_ds_node_author_image($user, $field['formatter']);
}

/**
 * Helper function to render C4M user image based on a user entity.
 *
 * @param $user
 *
 * @return string
 */
function c4m_ds_node_author_image($user, $style = NULL) {
  $output  = '';
  $wrapper = entity_metadata_wrapper('user', $user);
  $file    = $wrapper->c4m_media->value();
  if (!empty($file)) {
    $file['style_name'] = empty($style) ? 'media_thumbnail' : $style;
    $file['path']       = $file['uri'];
    $file['attributes'] = array('class' => 'user-image');
    $img                = theme_image_style($file);
    $output             = l($img, 'user/' . $user->uid, array('html' => 'TRUE'));
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
function theme_c4m_ds_author_first_and_last_name($field) {
  if (empty($field['entity'])) {
    return;
  }
  $tag = array();
  $entity = $field['entity'];

  if ($entity->uid != 0) {
    $user = user_load($entity->uid);
    $name = c4m_user_name($user);

    if (!trim($name)) {
      $name = $user->name;
    }

    if ('author_link' == $field['formatter']) {
      $name = l($name, 'user/' . $user->uid);
    }

    $tag['element'] = array(
      '#tag'       => 'span',
      'attributes' => array(
        'class' => array('username'),
      ),
      '#value'     => $name,
    );
  }
  else {
    if (!empty($entity->name)) {
      $tag['element'] = array(
        '#tag'       => 'span',
        'attributes' => array(
          'class' => array('username', 'anonymous'),
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
 * Render "Submitted by" Author first and last name on timestamp. (extends default ds field with first + last name).
 *
 * @param $field
 *
 * @return string
 */
function theme_c4m_ds_submitted_by_and_on($field) {
  if (empty($field['entity'])) {
    return;
  }

  $entity = $field['entity'];
  $user   = user_load($entity->uid);
  $name   = c4m_user_name($user);

  if (!trim($name)) {
    $name = $user->name;
  }

  $name = l($name, 'user/' . $user->uid);

  switch ($field['formatter']) {
    case 'ds_time_ago':
      $interval = REQUEST_TIME - $field['entity']->created;

      return t('Submitted !interval ago by !user.', array('!interval' => format_interval($interval), '!user' => $name));
    default:
      $date_format = str_replace('ds_post_date_', '', $field['formatter']);

      return t('Submitted by !user on !date.', array(
        '!user' => $name,
        '!date' => format_date($field['entity']->created, $date_format)
      ));
  }
}

/**
 * DS function field.
 *
 * Render a span with the relevant content type icon.
 *
 * @param $field
 *
 * @return string
 */
function theme_c4m_ds_content_type_icon($field) {
  if (empty($field['entity'])) {
    return;
  }
  $object = $field['entity'];

  $icon_name = $object->type;

  $object_wrapper = entity_metadata_wrapper('node', $object);
  $field_name = 'c4m_' . $icon_name . '_type';

  if (!empty($object_wrapper->$field_name)) {
    $icon_name .= '-' . $object_wrapper->$field_name->value();
  }

  $variables['icon'] = $icon_name;

  return '<span class="node-icon as-' . $icon_name . '"> </span>';
}

/**
 * DS function field.
 *
 * Render <content type> posted by
 *
 * @param $field
 *
 * @return string
 */
function theme_c4m_ds_type_posted_by($field) {
  $output = '';

  if (empty($field['entity'])) {
    return $output;
  }
  $entity = $field['entity'];

  $tag['element'] = array(
    '#tag'   => 'div',
    '#value' => t('@entity_label posted by', array('@entity_label' => ucwords(c4m_helper_entity_get_entity_type_label($entity)))),
  );

  return theme_html_tag($tag);
}

/**
 * DS function field.
 *
 * Render a span with the relevant content type icon.
 *
 * @param $field
 *
 * @return string
 */
function theme_c4m_ds_content_footer_stats($field) {
  // HOOK CALLBACK????

  $entity = $field['entity'];

  $statistic         = statistics_get($entity->nid);
  $items['comments'] = theme('c4m_message_entity_comments', array('count' => $entity->comment_count));

  if (empty($statistic['totalcount'])) {
    $statistic['totalcount'] = 0;
  }
  $items['views'] = theme('c4m_message_entity_views', array('count' => $statistic['totalcount']));

  return implode($items);
}

/**
 * DS function field.
 *
 * Render group type info
 *
 * @param $field
 *
 * @return string
 */
function theme_c4m_ds_group_access_info($field) {
  if (!isset($field['entity'])) {
    return NULL;
  }

  $group_access   = c4m_og_get_access_type($field['entity']);
  $tag['element'] = array(
    '#tag'   => 'h4',
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
 *
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
 *
 * @return string
 */
function c4m_user_name($user) {
  $wrapper = entity_metadata_wrapper('user', $user);

  return $wrapper->c4m_first_name->value() . ' ' .
  $wrapper->c4m_last_name->value();
}