<?php

/**
 * @file
 * C4M Admin Groups administration pages functionality.
 */

/**
 * Page callback for /admin/c4m/groups/export.
 */
function c4m_admin_groups_groups_export_page() {
  $output = '';

  // Get views view settings.
  $view = views_get_view('c4m_admin_groups_export');
  $view_display = $view->display['groups_export'];
  $view_display_options = $view_display->display_options;

  // Permanent file path (if the file can be found).
  $permanent_file_path = $view_display_options['style_options']['file_path'];
  if (file_exists($permanent_file_path)) {
    $permanent_file_path = file_create_url($permanent_file_path);
    $output .= l(t('Download existing CSV export'), $permanent_file_path, array('attributes' => array('class' => array('button'))));
  }

  // New export path.
  $output .= l(t('Export groups to CSV'), $view_display_options['path'], array('attributes' => array('class' => array('button'))));

  return $output;
}
