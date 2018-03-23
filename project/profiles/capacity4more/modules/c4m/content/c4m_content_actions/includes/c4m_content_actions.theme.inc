<?php

/**
 * @file
 * Theme functions for the c4m_content_action module.
 */

/**
 * DS function field.
 *
 * Render content actions.
 *
 * @param array $field
 *   Array containing the information about the field.
 *
 * @return string
 *   Rendered output from all modules, who implement
 *   hook_c4m_content_actions_info.
 */
function _c4m_content_actions_ds_field(array $field) {
  $output = c4m_content_action_get_actions();

  return $output;
}
