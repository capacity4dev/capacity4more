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
  protected $textFormat = 'full_html';

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
    'C4mDemoContentCreateTopics',
    'C4mDemoContentCreateArticles',
    'C4mDemoContentCreateGroups',
  );

  /**
   * Configure the migration class during creation.
   */
  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('c4m_body', 'body');

    $this->addFieldMapping('c4m_related_topic', 'topics');
    $this->addFieldMapping('c4m_related_articles_unlimited', 'articles');
    $this->addFieldMapping('c4m_related_group_unlimited', 'groups');

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

    $row->topics = $this->filterDestid2FromEntityReference(
      $this->handleSourceMigration(
        'C4mDemoContentCreateTopics',
        explode('|', $row->topics),
        NULL,
        $this
      )
    );
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
