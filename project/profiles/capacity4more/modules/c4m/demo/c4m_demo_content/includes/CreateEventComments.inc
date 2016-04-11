<?php
/**
 * @file
 * Migrate class to create comments for events.
 */

/**
 * Class C4mDemoContentCreateEventComments.
 */
class C4mDemoContentCreateEventComments extends C4mDemoContentCreateComments {
  public $bundle = 'comment_node_event';

  /**
   * Configure the migration class during creation.
   */
  public function __construct() {
    parent::__construct();

    $this->addDependency('C4mDemoContentCreateEvents');

    $this->addFieldMapping('nid', 'nid');

    $this->addFieldMapping('pid', 'pid')
      ->sourceMigration('C4mDemoContentCreateEventComments');
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
      'C4mDemoContentCreateEvents',
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
