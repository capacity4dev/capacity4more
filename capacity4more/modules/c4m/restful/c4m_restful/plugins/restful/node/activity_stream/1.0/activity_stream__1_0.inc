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
    'c4m_insert__comment' => 'activity_stream',
    'c4m_insert__node__article' => 'activity_stream',
    'c4m_insert__node__discussion' => 'activity_stream',
    'c4m_insert__node__document' => 'activity_stream',
    'c4m_insert__node__event' => 'activity_stream',
    'c4m_insert__node__photo' => 'activity_stream',
    'c4m_insert__node__photoalbum' => 'activity_stream',
    'c4m_insert__node__wiki_page' => 'activity_stream',
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
