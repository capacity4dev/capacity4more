<?php

/**
 * @file
 * Dates plugin for RestFul.
 */

$plugin = array(
  'label' => t('Dates'),
  'resource' => 'dates',
  'name' => 'dates__1_0',
  'entity_type' => 'taxonomy_term',
  'bundle' => 'c4m_vocab_date',
  'description' => t('Export the "Date vocabulary" taxonomy term.'),
  'class' => 'RestfulEntityTaxonomyTermDates',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
