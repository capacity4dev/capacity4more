<?php
/**
 * @file
 * Theme functions for c4m_search module.
 */

/**
 * Returns HTML for a link group.
 *
 * @param array $variables
 *   An associative array containing the keys 'text', 'path', 'options', and
 *   'count'. See the l() and theme_facetapi_count() functions for information
 *   about these variables.
 *
 * @return string
 *   The rendered link group title.
 *
 * @ingroup themeable
 */
function theme_c4m_search_facetapi_link_group(array $variables) {
  // Sanitizes the link text if necessary.
  $sanitize = empty($variables['options']['html']);
  $text = ($sanitize)
    ? check_plain($variables['text'])
    : $variables['text'];

  return '<h3 class="facetapi-links-group">' . $text . '</h3>';
}
