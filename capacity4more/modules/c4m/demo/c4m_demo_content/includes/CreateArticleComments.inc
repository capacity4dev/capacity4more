<?php
/**
 * @file
 * Migrate class to create comments for articles.
 */

/**
 * Class C4mDemoContentCreateArticleComments.
 */
class C4mDemoContentCreateArticleComments extends C4mDemoContentCreateComments {
  public $bundle = 'comment_node_article';
  protected $textFormat = 'filtered_html';

  /**
   * Configure the migration class during creation.
   */
  public function __construct() {
    parent::__construct();

    $this->addDependency('C4mDemoContentCreateArticles');

    $this->addFieldMapping('nid', 'nid');

    $this->addFieldMapping('pid', 'pid')
      ->sourceMigration('C4mDemoContentCreateArticleComments');
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
      'C4mDemoContentCreateArticles',
      $row->node_id,
      NULL,
      $this
    );

    $row->nid = $this->filterDestid2FromEntityReference(
      $unfiltered_ids
    );

    return TRUE;
  }

}
