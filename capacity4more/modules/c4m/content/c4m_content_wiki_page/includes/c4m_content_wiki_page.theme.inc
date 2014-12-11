<?php
/**
 * @file
 *
 * Custom Display Suite function fields.
 */

/**
 * DS function field.
 *
 * Render WIKI Page navigation
 *
 * @param $field
 * @return string
 */
function theme_c4m_content_wiki_page_navigation($field) {
  if (empty($field['entity'])) {
    return;
  }
  $output = 'nav';
  $entity = $field['entity'];

  return $output;
}