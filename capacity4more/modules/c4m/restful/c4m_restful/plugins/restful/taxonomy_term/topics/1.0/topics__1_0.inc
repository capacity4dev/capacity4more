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
  // Bundle will be set on the fly by the a query parameter in request.
  'bundle' => FALSE,
  'description' => t('Export the "Topics" taxonomy term. The "group" parameter must be in the request, with the group ID as value.'),
  'class' => 'RestfulEntityTaxonomyTermTopics',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
