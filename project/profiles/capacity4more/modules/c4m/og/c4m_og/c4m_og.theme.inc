<?php

/**
 * @file
 * Theming functions for c4m_og module.
 */

/**
 * Returns HTML for a group status.
 *
 * @ingroup theme_functions
 */
function theme_c4m_og_group_status($variables) {
  $status = $variables['status'];
  $output = '';
  if ($status !== 'published') {
    $output = '<span class="top-buffer indication label label-default group-status">' . $status . '</span>';
  }
  return $output;
}

/**
 * Returns HTML for a group type.
 *
 * @ingroup theme_functions
 */
function theme_c4m_og_group_type($variables) {
  $type = $variables['type'];
  $output = '<span class="top-buffer indication label label-default group-type">' . $type . '</span>';
  return $output;
}
