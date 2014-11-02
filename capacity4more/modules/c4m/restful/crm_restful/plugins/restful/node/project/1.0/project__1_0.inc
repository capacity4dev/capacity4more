<?php

$plugin = array(
  'label' => t('Projects'),
  'resource' => 'projects',
  'name' => 'project__1_0',
  'entity_type' => 'node',
  'bundle' => 'project',
  'description' => t('Expose the project content type.'),
  'class' => 'C4MRestfulProjectsResource',
  'authentication_types' => TRUE,
);
