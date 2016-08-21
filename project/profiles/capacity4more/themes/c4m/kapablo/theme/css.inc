<?php

/**
 * @file
 * All CSS related manipulations to the theme.
 */

/**
 * Implements hook_css_alter().
 *
 * Add CSS.
 *
 * @see hook_css_alter()
 */
function kapablo_css_alter(&$css) {
  $css['fontAwesome'] = array(
    'data'       => libraries_get_path('font_awesome') . '/css/font-awesome.min.css',
    'type'       => 'file',
    'every_page' => TRUE,
    'media'      => 'all',
    'preprocess' => FALSE,
    'group'      => CSS_THEME,
    'browsers'   => array('!IE' => TRUE, 'IE' => TRUE),
    'weight'     => 4,
  );

  $exclude = array();

  foreach ($exclude as $path) {
    if (isset($css[$path])) {
      unset($css[$path]);
    }
  }
}
