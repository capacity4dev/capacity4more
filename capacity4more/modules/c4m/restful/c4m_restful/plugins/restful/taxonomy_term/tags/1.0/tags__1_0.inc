<?php
/**
 * @file
 * Tags plugin for RestFul.
 */

$plugin = array(
  'label' => t('Tags'),
  'resource' => 'tags',
  'name' => 'tags__1_0',
  'entity_type' => 'taxonomy_term',
  // Bundle will be set on the fly by the a query parameter in request.
  'bundle' => FALSE,
  'description' => t('Export the "Tags" taxonomy term. The "group" parameter must be in the request, with the group ID as value.'),
  'class' => 'RestfulEntityTaxonomyTermTags',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
