<?php
/**
 * @file
 * Migrate class to create comments for blog posts.
 */

/**
 * Class C4mDemoContentCreateBlogComments
 */
class C4mDemoContentCreateBlogComments extends C4mDemoContentCreateComments {
  public $bundle = 'comment_node_blog';

  /**
   * Configure the migration class during creation.
   */
  public function __construct() {
    parent::__construct();

    $this->addDependency('C4mDemoContentCreateBlogs');

    $this->addFieldMapping('nid', 'nid');

    $this->addFieldMapping('pid', 'pid')
      ->sourceMigration('C4mDemoContentCreateBlogComments');
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
      'C4mDemoContentCreateBlogs',
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
