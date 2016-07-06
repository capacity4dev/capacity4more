<?php

/**
 * @file
 * c4m_features_og_documents.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function c4m_features_og_documents_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_document_pattern';
  $strongarm->value = 'documents/[node:title]';
  $export['pathauto_node_document_pattern'] = $strongarm;

  return $export;
}
