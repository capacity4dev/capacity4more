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

  return c4m_user_image($user, $field['formatter']);
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
    $name = c4m_user_profile_name($user);

    if ('author_link' == $field['formatter']) {
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
  $name   = c4m_user_profile_name($user);
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
    $output .= ', ' . l(c4m_user_profile_name($user), 'user/' . $member->uid);
  }

  return ltrim($output, ', ');
}
