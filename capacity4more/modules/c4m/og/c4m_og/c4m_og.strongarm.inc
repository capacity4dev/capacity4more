<?php
/**
 * @file
 * c4m_og.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function c4m_og_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_context_negotiation_group_context';
  $strongarm->value = array(
    'og_purl' => array(),
    'url' => array(),
    'node' => array(),
  );
  $export['og_context_negotiation_group_context'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_context_providers_weight_group_context';
  $strongarm->value = array(
    'og_purl' => '-10',
    'url' => '-9',
    'node' => '-8',
    'comment' => '-7',
    'user-view' => '-6',
    'user-edit' => '-5',
  );
  $export['og_context_providers_weight_group_context'] = $strongarm;

  return $export;
}
