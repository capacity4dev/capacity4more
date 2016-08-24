<?php
/**
 * @file
 * c4m_features_og_media.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function c4m_features_og_media_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'file_default_scheme';
  $strongarm->value = 'public';
  $export['file_default_scheme'] = $strongarm;

  return $export;
}
