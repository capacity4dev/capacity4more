<?php

$plugin = array(
  'label' => t('Activity stream'),
  'resource' => 'activity_stream',
  'name' => 'activity_stream__1_0',
  'entity_type' => 'node',
  'bundle' => array(
    'discussion',
    'document',
    'event',
  ),
  'description' => t('Expose the "Activity stream" resource.'),
  'class' => 'C4mRestfulActivityStreamResource',
);
