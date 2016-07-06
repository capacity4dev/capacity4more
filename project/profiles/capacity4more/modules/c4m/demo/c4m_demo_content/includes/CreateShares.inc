<?php

/**
 * @file
 * Migrate class to create shared content.
 */

/**
 * Class C4mDemoContentCreateShares.
 */
class C4mDemoContentCreateShares extends C4mDemoContentCreateOgContent {
  public $entityType = 'node';
  public $bundle = 'share';

  /**
   * CSV Column mapping.
   *
   * @var array
   */
  public $csvColumns
    = array(
      array('id', 'ID'),
      array('title', 'Title'),
      array('body', 'Description'),
      array('group_map', 'Group'),
      array('group_type', 'Group Type'),
      array('source_entity', 'Source Entity'),
      array('source_entity_migration', 'Source Migration'),
      array('uid', 'UID'),
    );

  /**
   * Content creations that should run before this one.
   *
   * @var array
   */
  public $dependencies = array(
    'C4mDemoContentCreateUsers',
    'C4mDemoContentCreateGroups',
    'C4mDemoContentCreateProjects',
    'C4mDemoContentCreateEvents',
    'C4mDemoContentCreateDiscussions',
    'C4mDemoContentCreateDocuments',
    'C4mDemoContentCreateWikiPages',
    'C4mDemoContentCreatePhotoalbums',
    'C4mDemoContentCreatePhotos',
  );

  /**
   * Configure the object during creation.
   */
  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('c4m_body', 'body');

    $this->addFieldMapping('source_entity', 'source_entity');
    $this->addFieldMapping('source_entity_migration', 'source_entity_migration');

    $this->addFieldMapping('c4m_source_entity', 'source_entities');
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    parent::prepareRow($row);

    $unfiltered_ids = $this->handleSourceMigration(
      $row->source_entity_migration,
      $row->source_entity,
      NULL,
      $this
    );
    $row->source_entities = $this->filterDestid2FromEntityReference(
      $unfiltered_ids
    );
  }

  /**
   * Create stub Topics (when creating users), who will be replaced afterwards.
   *
   * @param Migration $migration
   *   The migration that is being done to create this stub.
   * @param array $source_id
   *   Array of strings with the source id(s).
   *
   * @return array|bool
   *   Array with topic node id if term created, else FALSE.
   */
  public function createStub(Migration $migration, array $source_id) {
    $node = new stdClass();
    $node->title = t('Stub for @id', array('@id' => $source_id[0]));
    $node->body[LANGUAGE_NONE][0] = t('Stub topic');
    $node->type = $this->destination->getBundle();
    $node->uid = 1;
    $node->status = 0;
    node_save($node);
    if (isset($node->nid)) {
      return array($node->nid);
    }
    else {
      return FALSE;
    }
  }

}
