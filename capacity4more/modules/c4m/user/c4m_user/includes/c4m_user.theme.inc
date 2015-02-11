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
  $linked = ('linked' == $field['formatter']) ? TRUE : FALSE;
  return c4m_user_initials_themed($field['entity']->uid, $linked);
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

