<?php

/**
 * @file
 * Topics plugin for RestFul.
 */

$plugin = array(
  'label' => t('Topics'),
  'resource' => 'topics',
  'name' => 'topics__1_0',
  'entity_type' => 'taxonomy_term',
  'bundle' => 'c4m_vocab_topic',
  'description' => t('Export the "Topics" taxonomy term.'),
  'class' => 'RestfulEntityTaxonomyTermTopics',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
