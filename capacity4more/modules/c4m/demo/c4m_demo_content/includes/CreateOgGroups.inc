<?php
/**
 * @file
 * Base to create Og Classes
 */

/**
 * Class C4mDemoContentCreateOgGroups
 */
abstract class C4mDemoContentCreateOgGroups extends C4mDemoContentCreateEntity {
  /**
   * Creation classes that should run before this one.
   *
   * @var array
   */
  public $dependencies = array(
    'C4mDemoContentCreateUsers',
    'C4mDemoContentCreateTopics',
    'C4mDemoContentCreateRegionTerms',
    'C4mDemoContentCreateRegionNodes',
  );

  /**
   * Configure the migration class during creation.
   */
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
      ->sourceMigration('C4mDemoContentCreateRegionTerms')
      ->arguments(array('source_type' => 'tid'))
      ->separator('|');

    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('C4mDemoContentCreateUsers');
  }

  /**
   * Prepare the row data loaded from the CSV.
   *
   * @param object $row
   *   The data from the CSV file.
   *
   * @return bool
   *   Success.
   */
  public function prepareRow($row) {
    parent::prepareRow($row);
    $unfiltered_ids = $this->handleSourceMigration(
      'C4mDemoContentCreateTopics',
      explode('|', $row->topics),
      NULL,
      $this
    );

    // By default $unfiltered_ids is an array of arrays, containing the
    // destid1 => destination_nid, but destid2 => NULL.
    // This NULL value is counted however and added to the query, resulting
    // in errors. Therefore we need to filter it out.
    $row->topics_list = $this->filterDestid2FromEntityReference(
      $unfiltered_ids
    );

    return TRUE;
  }
}
