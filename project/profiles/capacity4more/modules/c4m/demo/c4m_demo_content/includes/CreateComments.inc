<?php
/**
 * @file
 * Migrate class to create dummy comments.
 */

/**
 * Class C4mDemoContentCreateComments.
 */
abstract class C4mDemoContentCreateComments extends Migration {
  /**
   * Map the field and properties to the CSV header.
   */
  public $csvColumns = array(
    array('id', 'ID'),
    array('pid', 'Parent'),
    array('status', 'Status'),
    array('node_id', 'NID'),
    array('uid', 'UID'),
    array('comment_body', 'Body'),
  );

  public $entityType = 'comment';

  /**
   * The text format to use for body fields.
   *
   * @var string
   */
  protected $textFormat = 'default_html';

  /**
   * Creation classes that should run before this one.
   *
   * @var array
   */
  public $dependencies = array(
    'C4mDemoContentCreateUsers',
  );

  /**
   * Configure the object during creation.
   */
  public function __construct() {
    parent::__construct(
      MigrateGroup::getInstance(C4M_DEMO_CONTENT_MIGRATION_GROUP)
    );

    $this->description = t(
      'Import comments for @bundle from CSV file.',
      array('@type' => $this->entityType, '@bundle' => $this->bundle)
    );

    $this->addSimpleMappings(array('created', 'changed'));

    $this->addFieldMapping('status', 'status')
      ->defaultValue(COMMENT_PUBLISHED);

    $this->addFieldMapping('comment_body', 'comment_body');

    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('C4mDemoContentCreateUsers');

    // Create a map object for tracking the relationships between source rows.
    $key = array(
      'id' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => TRUE,
      ),
    );
    $destination_handler = new MigrateDestinationComment($this->bundle);
    $this->map = new MigrateSQLMap(
      $this->machineName,
      $key,
      $destination_handler->getKeySchema()
    );

    // Create a MigrateSource object.
    $csv_path = drupal_get_path('module', 'c4m_demo_content') . '/csv';
    $this->source = new MigrateSourceCSV(
      $csv_path . '/' . $this->entityType . '/' . $this->bundle . '.csv',
      $this->csvColumns,
      array('header_rows' => 1)
    );
    $this->destination = new MigrateDestinationComment(
      $this->bundle,
      array('text_format' => $this->textFormat)
    );
  }

  /**
   * Prepare rows before passing the data to the entity creation.
   *
   * @param object $row
   *   The row data.
   *
   * @return bool
   *   Success.
   */
  public function prepareRow($row) {
    parent::prepareRow($row);

    // The migrated content isn't belonging to any one,
    // default to the admin user.
    if (!$row->uid) {
      $row->uid = 1;
    }

    if (!$row->created) {
      // Create a random timestamp from the last year.
      $year_ago = time() - 3600 * 24 * 365;
      $row->created = rand($year_ago, time());
      $row->changed = $row->created;
    }

    return TRUE;
  }

  /**
   * Add a dependency to the Migration class (if not added earlier).
   *
   * @param string $dependency
   *   Add a new dependency.
   */
  public function addDependency($dependency) {
    if (!array_search($dependency, $this->dependencies)) {
      $this->dependencies[] = $dependency;
    }
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
      if (!empty($dest_field['destid2'])) {
        $filtered_ids = array('destid1' => $dest_field['destid1']);
        $filtered_ids['destid2'] = $dest_field['destid2'];
      }
      else {
        return $dest_field['destid1'];
      }
    }
    elseif (is_array($dest_field)) {
      foreach ($dest_field as $key => $dest) {
        $filtered_ids[$key] = array('destid1' => $dest['destid1']);
        if (!empty($dest['destid2'])) {
          $filtered_ids[$key]['destid2'] = $dest['destid2'];
        }
      }
    }

    return $filtered_ids;
  }

  /**
   * Actions after the data is saved in the database.
   *
   * @param object $entity
   *   The entity that is saved into the platform.
   * @param object $row
   *   The data row we are importing.
   */
  public function complete($entity, $row) {
    // Make sure the messages have the proper timestamp.
    $this->messageInsertSave($entity, $row);
  }

  /**
   * Reset the $message->timestamp of any related insert message (if any).
   *
   * @param object $comment
   *   Comment object we want to set the message timestamp for.
   * @param object $row
   *   The source data of the migrated entity.
   */
  public function messageInsertSave($comment, $row) {
    if (!module_exists('c4m_message')) {
      return;
    }

    // Load the message(s).
    $message_type = 'c4m_insert__comment';
    $query = new EntityFieldQuery();
    $result = $query
      ->entityCondition('entity_type', 'message')
      ->propertyCondition('type', $message_type)
      ->fieldCondition('field_node', 'target_id', $comment->nid)
      ->fieldCondition('field_comment', 'target_id', $comment->cid)
      ->execute();

    if (empty($result['message'])) {
      return;
    }

    // Update the timestamp.
    $message_ids = array_keys($result['message']);
    foreach ($message_ids as $message_id) {
      $message = message_load($message_id);
      if (!$message) {
        continue;
      }

      $message->timestamp = $row->created;
      message_save($message);
    }
  }

}
