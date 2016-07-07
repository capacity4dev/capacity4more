<?php

/**
 * @file
 * Events plugin for RestFul.
 */

$plugin = array(
  'label' => t('Events'),
  'resource' => 'events',
  'name' => 'events__1_0',
  'entity_type' => 'node',
  'bundle' => 'event',
  'description' => t('Expose the "Event" resource.'),
  'class' => 'C4mRestfulEventsResource',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
