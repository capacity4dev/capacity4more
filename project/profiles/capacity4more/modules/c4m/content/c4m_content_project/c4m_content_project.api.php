<?php

/**
 * @file
 * Hooks provided by the c4m_content_project module.
 */

/**
 * Returns the white-listed blocks.
 *
 * @return array
 *   Array of block strings.
 */
function hook_c4m_content_project_blockreference_whitelist() {
  return array(
    'module:block_delta_1' => array(
      'label' => t('Name'),
    ),
    'module:block_delta_2' => array(
      'label' => t('Name'),
    ),
  );
}
