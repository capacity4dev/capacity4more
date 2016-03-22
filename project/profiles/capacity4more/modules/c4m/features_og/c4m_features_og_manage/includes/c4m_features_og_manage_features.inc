<?php
/**
 * @file
 * Code for the manage group features page.
 */

/**
 * Menu callback for path manage/features.
 */
function c4m_features_og_manage_features() {
  module_load_include('inc', 'variable_realm', 'variable_realm.form');
  $gid = c4m_og_current_group_id();
  return drupal_get_form('variable_realm_edit_variables_form', 'og', 'node' . '_' . $gid);
}
