<?php
/**
 * @file Migrate classes
 */

/**
 * Class C4mMigrateUsers
 */
class C4mMigrateUsers extends Migration {
  /**
   * Map the field and properties to the CSV header.
   */
  public $csvColumns = array(
    array('id', 'Unique ID'),
    array('name', 'Username'),
    array('pass', 'Password'),
    array('mail', 'Email'),
    array('first_name', 'First name'),
    array('last_name', 'Last name'),
    array('role', 'Role'),
  );

  public $entityType = 'user';

  public function __construct() {
    parent::__construct();
    $this->description = t('Import users from a CSV file.');

    $this->addFieldMapping('name', 'name');
    $this->addFieldMapping('pass', 'pass');
    $this->addFieldMapping('mail', 'mail');
    $this->addFieldMapping('field_first_name', 'first_name');
    $this->addFieldMapping('field_last_name', 'last_name');
    $this->addFieldMapping('roles')
      ->defaultValue(DRUPAL_AUTHENTICATED_RID);
    $this->addFieldMapping('status')
      ->defaultValue(TRUE);

    // Create a map object for tracking the relationships between source rows
    $key = array(
      'id' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => TRUE,
      ),
    );
    $destination_handler = new MigrateDestinationUser();
    $this->map = new MigrateSQLMap($this->machineName, $key, $destination_handler->getKeySchema());

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'c4m_demo_content') . '/csv/' . $this->entityType . '/user.csv', $this->csvColumns, array('header_rows' => 1));
    $this->destination = new MigrateDestinationUser();
  }

  /**
   * Granting a role to the user from the CSV.
   */
  function complete($entity, $row) {
    if (!$row->role) {
      return;
    }

    $role = user_role_load_by_name($row->role);
    $entity->roles[$role->rid] = $row->role;

    user_save($entity);
  }
}

/**
 * Class C4mMigrateTopics
 */
class C4mMigrateTopics extends C4mMigrate {
  public $entityType = 'node';
  public $bundle = 'topic';

  public $csvColumns = array(
    array('id', 'ID'),
    array('title', 'Title'),
    array('body', 'Body'),
    array('image', 'Image'),
    array('uid', 'UID'),
  );
  public $dependencies = array(
    'C4mMigrateUsers',
  );

  public function __construct() {
    parent::__construct();

     $this->addFieldMapping('c4m_body', 'body');

    $this->addFieldMapping('c4m_media', 'image')
      ->separator(';');
    $this->addFieldMapping('c4m_media:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('c4m_media:source_dir')
      ->defaultValue(drupal_get_path('module', 'c4m_demo_content') . '/images');
    $this->addFieldMapping('c4m_media:destination_dir', 'destination');

    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('C4mMigrateUsers');
  }
}

/**
 * Migrate "Regions" terms (hierarchically).
 */
class C4mMigrateRegionsVocab extends C4mMigrate {
  public $entityType = 'taxonomy_term';
  public $bundle = 'c4m_vocab_geo';
}

/**
 * Class C4mMigrateTopics
 */
class C4mMigrateRegionsNodes extends C4mMigrate {
  public $entityType = 'node';
  public $bundle = 'region';

  public $csvColumns = array(
    array('id', 'ID'),
    array('title', 'Title'),
    array('body', 'Body'),
    array('image', 'Image'),
    array('geo', 'Geo'),
    array('uid', 'UID'),
  );

  public $dependencies = array(
    'C4mMigrateUsers',
    'C4mMigrateRegionsVocab',
  );

  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('c4m_body', 'body');

    $this->addFieldMapping('c4m_media', 'image')
      ->separator(';');
    $this->addFieldMapping('c4m_media:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('c4m_media:source_dir')
      ->defaultValue(drupal_get_path('module', 'c4m_demo_content') . '/images');
    $this->addFieldMapping('c4m_media:destination_dir', 'destination');

    $this->addFieldMapping('c4m_vocab_geo', 'geo')
      ->sourceMigration('C4mMigrateRegionsVocab')
      ->arguments(array('source_type' => 'tid'));

    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('C4mMigrateUsers');
  }
}
