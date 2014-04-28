<?php
/**
 * @file
 * Class to create the Group nodes.
 */

class C4mDemoContent_CreateGroups extends C4mDemoContent_CreateEntity {
  public $entityType = 'node';
  public $bundle = 'group';

  public $csvColumns = array(
    array('id', 'ID'),
    array('title', 'Title'),
    array('purl', 'PURL'),
    array('image', 'Image'),
    array('body', 'Body'),
    array('topics', 'Topics'),
    array('geo', 'Geo'),
    array('groups', 'Groups'),
    array('uid', 'UID'),
  );

  public $dependencies = array(
    'C4mDemoContent_CreateUsers',
    'C4mDemoContent_CreateTopics',
    'C4mDemoContent_CreateRegionTerms',
    'C4mDemoContent_CreateRegionNodes',
  );

  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('og_purl', 'purl');

    $this->addFieldMapping('c4m_media', 'image')
      ->separator(';');
    $this->addFieldMapping('c4m_media:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('c4m_media:source_dir')
      ->defaultValue(drupal_get_path('module', 'c4m_demo_content') . '/images');

    $this->addFieldMapping('c4m_body', 'body');

    $this->addFieldMapping('c4m_related_topic', 'topics_list');

    $this->addFieldMapping('c4m_vocab_geo', 'geo')
      ->sourceMigration('C4mDemoContent_CreateRegionTerms')
      ->arguments(array('source_type' => 'tid'))
      ->separator('|');

    $this->addFieldMapping('c4m_related_group', 'groups_list');

    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('C4mDemoContent_CreateUsers');
  }

  public function prepareRow($row) {
    parent::prepareRow($row);
    $unfiltered_ids = $this->handleSourceMigration('C4mDemoContent_CreateTopics', explode('|', $row->topics), NULL, $this);

    // By default $unfiltered_ids is an array of arrays, containing the destid1 => destination_nid, but destid2 => NULL.
    // This NULL value is counted however and added to the query, resulting in errors.
    // Therefore we need to filter it out.
    $row->topics_list = $this->_filter_destid2_from_entity_reference($unfiltered_ids);

    $unfiltered_ids = $this->handleSourceMigration('C4mDemoContent_CreateGroups', explode('|', $row->groups), NULL, $this);
    $row->groups_list = $this->_filter_destid2_from_entity_reference($unfiltered_ids);
  }
}