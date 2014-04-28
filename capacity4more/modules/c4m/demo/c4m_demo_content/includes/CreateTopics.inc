<?php
/**
 * @file
 * Migrate class to create topics.
 */

class C4mDemoContent_CreateTopics extends C4mDemoContent_CreateEntity {
  public $entityType = 'node';
  public $bundle = 'topic';

  public $csvColumns = array(
    array('id', 'ID'),
    array('title', 'Title'),
    array('body', 'Body'),
    array('image', 'Image'),
    array('uid', 'UID'),
  );
  public $dependencies = array(
    'C4mDemoContent_CreateUsers',
  );

  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('c4m_body', 'body');

    $this->addFieldMapping('c4m_media', 'image')
      ->separator(';');
    $this->addFieldMapping('c4m_media:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('c4m_media:source_dir')
      ->defaultValue(drupal_get_path('module', 'c4m_demo_content') . '/images');
    $this->addFieldMapping('c4m_media:destination_dir', 'destination');

    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('C4mDemoContent_CreateUsers');
  }
}