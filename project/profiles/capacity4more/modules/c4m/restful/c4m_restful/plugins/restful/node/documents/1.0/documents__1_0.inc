<?php
/**
 * @file
 * Documents plugin for RestFul.
 */

$plugin = array(
  'label' => t('Documents'),
  'resource' => 'documents',
  'name' => 'documents__1_0',
  'entity_type' => 'node',
  'bundle' => 'document',
  'description' => t('Expose the "Document" resource.'),
  'class' => 'C4mRestfulDocumentsResource',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
