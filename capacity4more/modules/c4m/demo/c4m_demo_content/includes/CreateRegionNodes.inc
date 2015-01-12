<?php
/**
 * @file
 * Class to create the Region Nodes.
 */

/**
 * Class C4mDemoContentCreateRegionNodes
 */
class C4mDemoContentCreateRegionNodes extends C4mDemoContentCreateEntity {
  public $entityType = 'node';
  public $bundle = 'region';

  /**
   * CSV column mapping.
   *
   * @var array
   */
  public $csvColumns
    = array(
      array('id', 'ID'),
      array('title', 'Title'),
      array('body', 'Body'),
      array('image', 'Image'),
      array('geo', 'Geo'),
      array('uid', 'UID'),
    );

  /**
   * Content creations need to be run before this one.
   *
   * @var array
   */
  public $dependencies
    = array(
      'C4mDemoContentCreateUsers',
    );

  /**
   * Configure the mapping during object creation.
   */
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

    $this->addFieldMapping('c4m_vocab_geo', 'geo_entries')
      ->arguments(array('source_type' => 'tid'));

    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('C4mDemoContentCreateUsers');
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    parent::prepareRow($row);

    $row->geo_entries = $this->mapTaxonomyVocabWithParent(
      $this->mapTaxonomyVocab($row->geo, 'c4m_vocab_geo')
    );

    return TRUE;
  }
}
