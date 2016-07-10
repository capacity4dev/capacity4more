<?php

/**
 * @file
 * Migrate class to create dummy memberships.
 */

/**
 * Class C4mDemoContentCreateOgUsers.
 */
class C4mDemoContentCreateOgUsers extends Migration {
  /**
   * Map the field and properties to the CSV header.
   */
  public $csvColumns = array(
    array('id', 'ID'),
    array('gid', 'GID'),
    array('type', 'Type'),
    array('etid', 'UID'),
    array('is_admin', 'Admin'),
    array('state', 'State'),
  );

  /**
   * Content creations need to be run before this one.
   *
   * @var array
   */
  public $dependencies = array(
    'C4mDemoContentCreateUsers',
    'C4mDemoContentCreateGroups',
    'C4mDemoContentCreateProjects',
  );

  /**
   * The entity type used in this migration.
   *
   * @var string
   */
  public $entityType = 'user';

  /**
   * Constructor.
   */
  public function __construct() {
    parent::__construct(
      MigrateGroup::getInstance(C4M_DEMO_CONTENT_MIGRATION_GROUP)
    );

    $this->description = t(
      'Create memberships between users and groups/projects.'
    );

    $this->addFieldMapping('state', 'state');
    $this->addFieldMapping('is_admin', 'is_admin');

    $this->addFieldMapping('group_type', NULL)->defaultValue('node');
    $this->addFieldMapping('gid', 'gid');

    $this->addFieldMapping('entity_type', NULL)->defaultValue('user');
    $this->addFieldMapping('etid', 'etid')
      ->sourceMigration('C4mDemoContentCreateUsers');

    // Create a map object for tracking the relationships between source rows.
    $key = array(
      'id' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => TRUE,
      ),
    );
    $destination_handler = new MigrateDestinationOGMembership();
    $this->map = new MigrateSQLMap(
      $this->machineName,
      $key,
      $destination_handler->getKeySchema()
    );

    // Create a MigrateSource object.
    $csv_path = drupal_get_path('module', 'c4m_demo_content') . '/csv';
    $this->source = new MigrateSourceCSV(
      $csv_path . '/' . $this->entityType . '/og_user.csv',
      $this->csvColumns,
      array('header_rows' => 1)
    );
    $this->destination = new MigrateDestinationOGMembership();
  }

  /**
   * Prepare a row.
   *
   * @param object $row
   *   The source data.
   *
   * @return bool
   *   Success.
   */
  public function prepareRow($row) {
    switch ($row->type) {
      // Dynamic sourcemigration instead of creating a migration per OG type.
      case 'Group':
        $gid = $this->handleSourceMigration(
          'C4mDemoContentCreateGroups',
          $row->gid,
          NULL,
          $this
        );
        break;

      case 'Project':
        $gid = $this->handleSourceMigration(
          'C4mDemoContentCreateProjects',
          $row->gid,
          NULL,
          $this
        );
        break;
    }

    $row->gid = $this->filterDestid2FromEntityReference($gid);

    return parent::prepareRow($row);
  }

  /**
   * Filter the destiny field ID.
   *
   * @param mixed $dest_field
   *   The destiny field settings.
   *
   * @return array
   *   The filtered array.
   */
  protected function filterDestid2FromEntityReference($dest_field) {
    $filtered_ids = array();

    if (!empty($dest_field['destid1'])) {
      $filtered_ids = array('destid1' => $dest_field['destid1']);
      if (!empty($dest_field['destid2'])) {
        $filtered_ids = array(
          'destid1' => $dest_field['destid1'],
          'destid2' => $dest_field['destid2'],
        );
      }
      else {
        return $dest_field['destid1'];
      }
    }
    elseif (is_array($dest_field)) {
      foreach ($dest_field as $key => $dest) {
        if (!empty($dest['destid1'])) {
          $filtered_ids[$key] = array('destid1' => $dest['destid1']);
        }

        // Stubs generate array('<value_1>', '<value_2>') without keys.
        else {
          $filtered_ids[$key] = array('destid1' => $dest);
        }
        if (!empty($dest['destid2'])) {
          $filtered_ids[$key]['destid2'] = $dest['destid2'];
        }
      }
    }

    return $filtered_ids;
  }

}
