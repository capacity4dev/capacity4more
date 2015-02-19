<?php

$plugin = array(
  'label' => t('Activity stream'),
  'resource' => 'activity_stream',
  'name' => 'activity_stream__1_1',
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
  'class' => 'C4mRestfulActivityStreamResource__1_1',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
  'major_version' => 1,
  'minor_version' => 1,
  'data_provider_options' => array(
    'table_name' => 'message',
    'id_column' => 'mid',
  ),
);
