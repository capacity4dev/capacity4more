<?php
/**
 * @file
 * Contains all settings for ds view modes.
 */

/**
 * Expose default view modes.
 *
 * This hook is called by CTools. For this hook to work, you need
 * hook_ctools_plugin_api(). The values of this hook can be overridden
 * and reverted through the UI.
 */
function c4m_ds_ds_view_modes_info() {
  $ds_view_modes = array();

  // Prevent using default preview view mode because certain modules
  // depend on it. We introduce a custom preview view mode.
  $ds_view_mode                 = new stdClass;
  $ds_view_mode->disabled       = FALSE; /* Edit this to true to make a default ds_view_mode disabled initially */
  $ds_view_mode->api_version    = 1;
  $ds_view_mode->view_mode      = 'c4m_preview';
  $ds_view_mode->label          = 'C4M preview';
  $ds_view_mode->entities       = array(
    'file' => 'file',
  );
  $ds_view_modes['c4m_preview'] = $ds_view_mode;

  $ds_view_mode                   = new stdClass;
  $ds_view_mode->disabled         = FALSE; /* Edit this to true to make a default ds_view_mode disabled initially */
  $ds_view_mode->api_version      = 1;
  $ds_view_mode->view_mode        = 'c4m_dashboard';
  $ds_view_mode->label            = 'Dashboard';
  $ds_view_mode->entities         = array(
    'node' => 'node',
  );
  $ds_view_modes['c4m_dashboard'] = $ds_view_mode;

  $ds_view_mode                   = new stdClass;
  $ds_view_mode->disabled         = FALSE; /* Edit this to true to make a default ds_view_mode disabled initially */
  $ds_view_mode->api_version      = 1;
  $ds_view_mode->view_mode        = 'c4m_teaser_table';
  $ds_view_mode->label            = 'Teaser table';
  $ds_view_mode->entities         = array(
    'node' => 'node',
  );
  $ds_view_modes['c4m_teaser_table'] = $ds_view_mode;


  return $ds_view_modes;
}
