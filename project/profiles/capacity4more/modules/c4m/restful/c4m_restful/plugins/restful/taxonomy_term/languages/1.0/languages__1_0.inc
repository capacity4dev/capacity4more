<?php

/**
 * @file
 * Regions & Countries plugin for RestFul.
 */

$plugin = array(
  'label' => t('Languages'),
  'resource' => 'languages',
  'name' => 'languages__1_0',
  'entity_type' => 'taxonomy_term',
  'bundle' => 'c4m_vocab_language',
  'description' => t('Export the "Language Vocabulary" taxonomy term.'),
  'class' => 'RestfulEntityTaxonomyTermLanguages',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
