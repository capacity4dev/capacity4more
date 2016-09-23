<?php

/**
 * @file
 * Migrate class to create topics.
 */

/**
 * Class C4mDemoContentCreateTopics.
 */
class C4mDemoContentCreateTopics extends C4mDemoContentCreateEntity {
  public $entityType = 'node';
  public $bundle = 'topic';
  protected $textFormat = 'full_html';

  /**
   * CSV Column mapping.
   *
   * @var array
   */
  public $csvColumns
    = array(
      array('id', 'ID'),
      array('title', 'Title'),
      array('theme', 'Theme'),
      array('topic', 'Topic'),
      array('banner', 'Banner'),
      array('image', 'Image'),
      array('body', 'Body'),
      array('groups', 'Groups'),
      array('projects', 'Projects'),
      array('articles', 'Articles'),
      array('uid', 'UID'),
    );

  /**
   * Content creations that should run before this one.
   *
   * @var array
   */
  public $dependencies = array(
    'C4mDemoContentCreateUsers',
    'C4mDemoContentCreateTopicTerms',
    'C4mDemoContentCreateGroups',
    'C4mDemoContentCreateProjects',
    'C4mDemoContentCreateArticles',
  );

  /**
   * Configure the object during creation.
   */
  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('c4m_body', 'body');

    $this->addFieldMapping('c4m_vocab_theme', 'theme')
      ->sourceMigration('C4mDemoContentCreateThemes')
      ->arguments(array('source_type' => 'tid'));

    $this->addFieldMapping('c4m_vocab_topic_mapping', 'topic')
      ->sourceMigration('C4mDemoContentCreateTopicTerms')
      ->arguments(array('source_type' => 'tid'));

    $this->addFieldMapping('c4m_media', 'image');
    $this->addFieldMapping('c4m_media:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('c4m_media:source_dir')
      ->defaultValue(drupal_get_path('module', 'c4m_demo_content') . '/images');
    $this->addFieldMapping('c4m_media:destination_dir', 'destination');

    $this->addFieldMapping('c4m_banner', 'banner');
    $this->addFieldMapping('c4m_banner:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('c4m_banner:source_dir')
      ->defaultValue(drupal_get_path('module', 'c4m_demo_content') . '/images');

    $this->addFieldMapping('c4m_related_group_unlimited', 'groups_list');

    $this->addFieldMapping('c4m_related_projects_unlimited', 'projects_list');

    $this->addFieldMapping('c4m_related_articles_unlimited', 'articles_list');

    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('C4mDemoContentCreateUsers');
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    parent::prepareRow($row);

    $unfiltered_ids = $this->handleSourceMigration(
      'C4mDemoContentCreateGroups',
      explode('|', $row->groups),
      NULL,
      $this
    );
    $row->groups_list = $this->filterDestid2FromEntityReference(
      $unfiltered_ids
    );

    $unfiltered_ids = $this->handleSourceMigration(
      'C4mDemoContentCreateProjects',
      explode('|', $row->projects),
      NULL,
      $this
    );
    $row->projects_list = $this->filterDestid2FromEntityReference(
      $unfiltered_ids
    );

    $unfiltered_ids = $this->handleSourceMigration(
      'C4mDemoContentCreateArticles',
      explode('|', $row->articles),
      NULL,
      $this
    );
    $row->articles_list = $this->filterDestid2FromEntityReference(
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
