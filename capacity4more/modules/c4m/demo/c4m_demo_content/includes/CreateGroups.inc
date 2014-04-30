<?php
/**
 * @file
 * Class to create the Group nodes.
 */

/**
 * Class C4mDemoContentCreateGroups
 */
class C4mDemoContentCreateGroups extends C4mDemoContentCreateOgGroups {
  public $entityType = 'node';
  public $bundle = 'group';

  /**
   * CSV column mapping.
   *
   * @var array
   */
  public $csvColumns = array(
    array('id', 'ID'),
    array('uid', 'UID'),
    array('title', 'Title'),
    array('purl', 'PURL'),
    array('image', 'Image'),
    array('body', 'Body'),
    array('topics', 'Topics'),
    array('geo', 'Geo'),
    array('groups', 'Groups'),
  );

  /**
   * Configure the migration class during creation.
   */
  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('c4m_related_group', 'groups_list');
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
      'C4mDemoContentCreateGroups',
      explode('|', $row->groups),
      NULL,
      $this
    );
    $row->groups_list = $this->filterDestid2FromEntityReference(
      $unfiltered_ids
    );

    return TRUE;
  }
}
