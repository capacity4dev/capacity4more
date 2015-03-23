<?php
/**
 * @file
 * Document types plugin for RestFul.
 */

$plugin = array(
  'label' => t('Document types'),
  'resource' => 'document_types',
  'name' => 'document_types__1_0',
  'entity_type' => 'taxonomy_term',
  'bundle' => 'c4m_vocab_document_type',
  'description' => t('Export the "Type of Document" taxonomy term.'),
  'class' => 'RestfulEntityTaxonomyTermDocumentTypes',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
