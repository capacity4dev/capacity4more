<?php

/**
 * @file
 * Topics plugin for RestFul.
 */

$plugin = array(
  'label' => t('Topics'),
  'resource' => 'topics',
  'name' => 'topics__1_0',
  'entity_type' => 'node',
  'bundle' => 'topic',
  'description' => t('Expose the "Topics" resource.'),
  'class' => 'C4mRestfulTopicsResource',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
