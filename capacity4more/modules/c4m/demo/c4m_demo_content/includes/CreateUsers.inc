<?php
/**
 * @file
 * Migrate class to create dummy users.
 */

/**
 * Class C4mDemoContentCreateUsers
 */
class C4mDemoContentCreateUsers extends Migration {
  /**
   * Map the field and properties to the CSV header.
   */
  public $csvColumns = array(
    array('id', 'Unique ID'),
    array('name', 'Username'),
    array('pass', 'Password'),
    array('mail', 'Email'),
    array('c4m_first_name', 'First name'),
    array('c4m_last_name', 'Last name'),
    array('picture', 'Picture'),
    array('c4m_organisation', 'Organisation'),
    array('c4m_organisation_type', 'Organisation Type'),
    array('c4m_country', 'Country'),
    array('topic_interest', 'Topic Interest'),
    array('topic_expertise', 'Topic Expertise'),
    array('vocab_geo', 'Related geo'),
    array('role', 'Role'),
    array('groups_list', 'Group Memberships'),
  );

  public $entityType = 'user';

  /**
   * Configure the object during creation.
   */
  public function __construct() {
    parent::__construct(
      MigrateGroup::getInstance(C4M_DEMO_CONTENT_MIGRATION_GROUP)
    );

    $this->description = t('Import users from a CSV file.');

    $this->addSimpleMappings(array(
      'name',
      'pass',
      'mail',
      'c4m_first_name',
      'c4m_last_name',
      'c4m_organisation',
      'c4m_organisation_type',
      'c4m_country',
    ));

    $this->addFieldMapping('c4m_media', 'picture')
      ->separator(';');
    $this->addFieldMapping('c4m_media:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('c4m_media:source_dir')
      ->defaultValue(drupal_get_path('module', 'c4m_demo_content') . '/images');
    $this->addFieldMapping('c4m_media:destination_dir', 'destination');

    $this->addFieldMapping('roles')
      ->defaultValue(DRUPAL_AUTHENTICATED_RID);
    $this->addFieldMapping('status')
      ->defaultValue(TRUE);

    // Create a map object for tracking the relationships between source rows.
    $key = array(
      'id' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => TRUE,
      ),
    );
    $destination_handler = new MigrateDestinationUser();
    $this->map = new MigrateSQLMap(
      $this->machineName,
      $key,
      $destination_handler->getKeySchema()
    );

    // Create a MigrateSource object.
    $csv_path = drupal_get_path('module', 'c4m_demo_content') . '/csv';
    $this->source = new MigrateSourceCSV(
      $csv_path . '/' . $this->entityType . '/user.csv',
      $this->csvColumns,
      array('header_rows' => 1)
    );
    $this->destination = new MigrateDestinationUser();
  }

  /**
   * Granting a role to the user from the CSV.
   *
   * @param object $entity
   *   The entity to create.
   * @param object $row
   *   The data from the CSV file.
   */
  public function complete($entity, $row) {
    if (!$row->role) {
      return;
    }

    $role = user_role_load_by_name($row->role);
    $entity->roles[$role->rid] = $row->role;

    user_save($entity);
  }
}
