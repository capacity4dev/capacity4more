<?php
/**
 * @file
 * Custom fields and formatters.
 */


/**
 * Implements hook_field_formatter_info().
 *
 * Adds extra formatters to allow the rendering of linked fields that respect
 * PURL paths.
 */
function c4m_og_field_formatter_info() {
  return array(
    'link_purl' => array(
      'label' => t('Link with PURL'),
      'field types' => array('title'),
    ),
    'link_purl_disabled' => array(
      'label' => t('Link without PURL'),
      'field types' => array('title'),
    ),
  );
}
