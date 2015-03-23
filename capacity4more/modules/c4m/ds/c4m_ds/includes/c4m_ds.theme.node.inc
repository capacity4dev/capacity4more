<?php
/**
 * @file
 *
 * Custom Display Suite function fields.
 */

/**
 * DS function field.
 *
 * Render "Submitted by" User first and last name on timestamp.
 * (extends default ds field with first + last name).
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
  $options = array('attributes' => array('class' => array('user-name')));

  $name = l($name, 'user/' . $user->uid, $options);

  $tag['element'] = array(
    '#tag'       => 'span',
    '#attributes' => array(
      'class' => array('creation-date'),
    ),
    '#value'     => c4m_helper_date_time_ago($entity->created, $field['formatter']),
  );

  return $name . theme_html_tag($tag);
}

/**
 * DS function field.
 *
 * Render node creation date according to time ago.
 *
 * If timestamp is within 24h of now: Indicate the time ago:
 *  - x seconds ago
 *  - x minutes ago
 *  - x hours ago
 * If timestamp is more then 1 day go: Show as a date (with or without time):
 * - 5 January 2015 (, 16:47)
 * - 28 August 2014 (, 9:05)
 *
 * @param $field
 *
 * @return string
 */
function theme_c4m_ds_creation_date($field) {
  if (empty($field['entity'])) {
    return;
  }

  $tag['element'] = array(
    '#tag'       => 'span',
    '#attributes' => array(
      'class' => array('creation-date'),
    ),
    '#value'     => c4m_helper_date_time_ago($field['entity']->created,
      $field['formatter']),
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
function theme_c4m_ds_content_type_icon($field) {
  if (empty($field['entity'])) {
    return;
  }
  $object = $field['entity'];

  $icon_name = $object->type;

  $object_wrapper = entity_metadata_wrapper('node', $object);
  $field_name = 'c4m_' . $icon_name . '_type';

  // Check if there is a type field.
  if (!empty($object_wrapper->$field_name)) {
    $icon_name .= '-' . $object_wrapper->$field_name->value();
  }

  $tag['element'] = array(
    '#tag'       => 'span',
    '#attributes' => array(
      'class' => array('node-icon', 'as-' . $icon_name),
    ),
    '#value'     => '',
  );

  return theme_html_tag($tag);
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
    '#tag'   => 'span',
    '#attributes' => array(
      'class' => array('posted-by'),
    ),
    '#value' => t('@entity_label', array('@entity_label' => ucfirst(c4m_helper_entity_get_entity_type_label($entity)))),
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
 * Render group members count
 *
 * @param $field
 *
 * @return string
 */
function theme_c4m_ds_group_members_count($field) {
  if (!isset($field['entity'])) {
    return NULL;
  }

  $members = c4m_og_get_members_count($field['entity']);

  $tag['element'] = array(
    '#tag'   => 'span',
    '#value' => format_plural($members, '1 member', '@count members', array('@count' => $members)),
  );

  return theme_html_tag($tag);
}

/**
 * DS function field.
 *
 * Render group posts count.
 *
 * @param $field
 *
 * @return string
 */
function theme_c4m_ds_group_posts_count($field) {
  if (!isset($field['entity'])) {
    return NULL;
  }

  $posts = c4m_og_get_posts_count($field['entity']);

  $tag['element'] = array(
    '#tag'   => 'span',
    '#value' => format_plural($posts, '1 post', '@count posts', array('@count' => $posts)),
  );

  return theme_html_tag($tag);
}

/**
 * DS function field.
 *
 * Render group type.
 *
 * @param $field
 *
 * @return string
 */
function theme_c4m_ds_group_type($field) {
  if (!isset($field['entity'])) {
    return NULL;
  }

  $group_type = c4m_og_get_access_type($field['entity']);

  $tag['element'] = array(
    '#tag'   => 'span',
    '#value' => $group_type['title'],
  );

  return theme_html_tag($tag);
}

/**
 * DS function field.
 *
 * Render group membership type.
 *
 * @param $field
 *
 * @return string
 */
function theme_c4m_ds_group_membership_type($field) {
  if (!isset($field['entity'])) {
    return NULL;
  }

  // Get membership type.
  global $user;
  $group = node_load($field['entity']->nid);
  $group_membership_type = c4m_user_og_get_role_in_group_human($user, $group);

  $tag['element'] = array(
    '#tag'   => 'span',
    '#value' => $group_membership_type,
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
