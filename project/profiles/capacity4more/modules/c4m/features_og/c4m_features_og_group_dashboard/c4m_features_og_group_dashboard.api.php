<?php

/**
 * @file
 * Hooks provided by the c4m_features_og_group_dashboard module.
 */

/**
 * Defines action links for group dashboard.
 *
 * @return array
 *   Renderable array.
 */
function hook_c4m_cta_block() {
  $items['create-group'] = array(
    '#markup' => l(t('Create group'), '/node/add/group'),
  );

  return $items;
}

/**
 * Defines links for group dashboard.
 *
 * @return array
 *   Renderable array.
 */
function hook_c4m_group_dashboard_links() {
  $items['create-group'] = array(
    '#markup' => l(t('Create group'), '/node/add/group'),
  );

  return $items;
}
