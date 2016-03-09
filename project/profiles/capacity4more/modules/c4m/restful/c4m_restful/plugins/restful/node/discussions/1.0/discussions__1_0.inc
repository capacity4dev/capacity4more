<?php
/**
 * @file
 * Discussions plugin for RestFul.
 */

$plugin = array(
  'label' => t('Discussions'),
  'resource' => 'discussions',
  'name' => 'discussions__1_0',
  'entity_type' => 'node',
  'bundle' => 'discussion',
  'description' => t('Expose the "Discussion" resource.'),
  'class' => 'C4mRestfulDiscussionsResource',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
