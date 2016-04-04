<?php
/**
 * @file
 * Activity stream Plugin for RestFul.
 */

$plugin = array(
  'label' => t('Activity stream'),
  'resource' => 'activity_stream',
  'name' => 'activity_stream__1_0',
  'entity_type' => 'message',
  'bundles' => array(
    'c4m_insert__comment' => 'activity_group',
    'c4m_insert__node__article' => 'activity_global',
    'c4m_insert__node__discussion' => 'activity_group',
    'c4m_insert__node__document' => 'activity_group',
    'c4m_insert__node__event' => 'activity_group',
    'c4m_insert__node__photo' => 'activity_group',
    'c4m_insert__node__wiki_page' => 'activity_group',
  ),
  'description' => t('Expose the "Activity stream" resource.'),
  'class' => 'C4mRestfulActivityStreamResource',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
  'data_provider_options' => array(
    'table_name' => 'message',
    'id_column' => 'mid',
  ),
);
