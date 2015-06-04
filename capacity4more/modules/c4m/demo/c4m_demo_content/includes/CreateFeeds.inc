<?php
/**
 * @file
 * Migrate class to create feeds.
 */

/**
 * Class C4mDemoContentCreateFeeds.
 */
class C4mDemoContentCreateFeeds extends C4mDemoContentCreateEntity {
  public $entityType = 'node';
  public $bundle = 'feed';

  /**
   * CSV column mapping.
   *
   * @var array
   */
  public $csvColumns = array(
    array('id', 'ID'),
    array('title', 'Title'),
    array('body', 'Body'),
    array('topics', 'Topics'),
    array('articles', 'Articles'),
    array('groups', 'Groups'),
    array('uid', 'UID'),
  );

  /**
   * Creation classes that should run before this one.
   *
   * @var array
   */
  public $dependencies = array(
    'C4mDemoContentCreateUsers',
    'C4mDemoContentCreateArticles',
    'C4mDemoContentCreateGroups',
  );

  /**
   * Configure the migration class during creation.
   */
  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('c4m_body', 'body')
      ->arguments(array('format' => 'full_html'));

    $this->addFieldMapping('c4m_vocab_topic', 'topics')
      ->sourceMigration('C4mDemoContentCreateTopicTerms')
      ->arguments(array('source_type' => 'tid'))
      ->separator('|');

    $this->addFieldMapping('c4m_related_articles', 'articles');
    $this->addFieldMapping('c4m_related_group', 'groups');

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

    $row->articles = $this->filterDestid2FromEntityReference(
      $this->handleSourceMigration(
        'C4mDemoContentCreateArticles',
        explode('|', $row->articles),
        NULL,
        $this
      )
    );
    $row->groups = $this->filterDestid2FromEntityReference(
      $this->handleSourceMigration(
        'C4mDemoContentCreateGroups',
        explode('|', $row->groups),
        NULL,
        $this
      )
    );

    return TRUE;
  }
}
