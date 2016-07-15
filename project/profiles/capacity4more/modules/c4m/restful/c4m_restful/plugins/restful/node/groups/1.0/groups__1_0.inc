<?php

/**
 * @file
 * Groups plugin for RestFul.
 */

$plugin = array(
  'label' => t('Groups'),
  'resource' => 'groups',
  'name' => 'groups__1_0',
  'entity_type' => 'node',
  'bundle' => 'group',
  'description' => t('Expose the "Group" resource.'),
  'class' => 'C4mRestfulGroupsResource',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
