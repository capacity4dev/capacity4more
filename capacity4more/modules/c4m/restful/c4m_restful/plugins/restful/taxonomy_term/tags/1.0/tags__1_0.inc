<?php

$plugin = array(
  'label' => t('Tags'),
  'resource' => 'tags',
  'name' => 'tags__1_0',
  'entity_type' => 'taxonomy_term',
  // Bundle will be set on the fly by the a query parameter in request.
  'bundle' => FALSE,
  'description' => t('Export the "Tags" taxonomy term per group.'),
  'class' => 'RestfulEntityTaxonomyTermTags',
  'authentication_types' => TRUE,
);
