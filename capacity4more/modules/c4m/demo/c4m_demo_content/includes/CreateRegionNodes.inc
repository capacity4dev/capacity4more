<?php
/**
 * @file
 * Class to create the Region Nodes.
 */

class C4mDemoContent_CreateRegionNodes extends C4mDemoContent_CreateEntity {
  public $entityType = 'node';
  public $bundle = 'region';

  public $csvColumns = array(
    array('id', 'ID'),
    array('title', 'Title'),
    array('body', 'Body'),
    array('image', 'Image'),
    array('geo', 'Geo'),
    array('uid', 'UID'),
  );

  public $dependencies = array(
    'C4mDemoContent_CreateUsers',
    'C4mDemoContent_CreateRegionTerms',
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

    $this->addFieldMapping('c4m_vocab_geo', 'geo')
      ->sourceMigration('C4mDemoContent_CreateRegionTerms')
      ->arguments(array('source_type' => 'tid'));

    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('C4mDemoContent_CreateUsers');
  }
}