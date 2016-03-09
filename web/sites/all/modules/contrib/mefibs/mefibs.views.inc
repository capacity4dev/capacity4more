<?php

/**
 * @file
 * Implementations of views hooks.
 */

/**
 * Implements hook_views_plugins().
 */
function mefibs_views_plugins() {
  $plugins = array();
  $plugins['display_extender']['mefibs_blocks'] = array(
    'title' => t('More exposed forms in blocks'),
    'help' => t('Allow use of multiple blocks that contain different form elements, as filters or sort.'),
    'handler' => 'mefibs_display_extender_plugin_blocks',
    'uses options' => TRUE,
    'type' => 'normal',
    'enabled' => TRUE,
  );
  return $plugins;
}
