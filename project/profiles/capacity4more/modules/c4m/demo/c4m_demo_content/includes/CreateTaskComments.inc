<?php
/**
 * @file
 * Migrate class to create comments for tasks.
 */

/**
 * Class C4mDemoContentCreateTaskComments.
 */
class C4mDemoContentCreateTaskComments extends C4mDemoContentCreateComments {
  public $bundle = 'comment_node_task';

  /**
   * Configure the migration class during creation.
   */
  public function __construct() {
    parent::__construct();

    $this->addDependency('C4mDemoContentCreateTasks');

    $this->addFieldMapping('nid', 'nid');

    $this->addFieldMapping('pid', 'pid')
      ->sourceMigration('C4mDemoContentCreateTaskComments');
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
      'C4mDemoContentCreateTasks',
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
