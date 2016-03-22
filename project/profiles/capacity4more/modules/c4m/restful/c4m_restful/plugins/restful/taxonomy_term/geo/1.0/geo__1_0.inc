<?php
/**
 * @file
 * Regions & Countries plugin for RestFul.
 */

$plugin = array(
  'label' => t('Geo'),
  'resource' => 'geo',
  'name' => 'geo__1_0',
  'entity_type' => 'taxonomy_term',
  'bundle' => 'c4m_vocab_geo',
  'description' => t('Export the "Regions & Countries" taxonomy term.'),
  'class' => 'RestfulEntityTaxonomyTermGeo',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
