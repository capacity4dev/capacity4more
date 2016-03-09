<?php
/**
 * @file
 * Migrate class to create comments for discussions.
 */

/**
 * Class C4mDemoContentCreateDiscussionComments.
 */
class C4mDemoContentCreateDiscussionComments extends C4mDemoContentCreateComments {
  public $bundle = 'comment_node_discussion';

  /**
   * Configure the migration class during creation.
   */
  public function __construct() {
    parent::__construct();

    $this->addDependency('C4mDemoContentCreateDiscussions');

    $this->addFieldMapping('nid', 'nid');

    $this->addFieldMapping('pid', 'pid')
      ->sourceMigration('C4mDemoContentCreateDiscussionComments');
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
      'C4mDemoContentCreateDiscussions',
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
