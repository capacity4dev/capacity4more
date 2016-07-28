<?php

/**
 * @file
 * Base to create Og Content Classes.
 */

/**
 * Class C4mDemoContentCreateOgContent.
 */
abstract class C4mDemoContentCreateOgContent extends C4mDemoContentCreateEntity {
  public $entityType = 'node';
  protected $textFormat = 'default_html';

  /**
   * Content creations need to be run before this one.
   *
   * @var array
   */
  public $dependencies = array(
    'C4mDemoContentCreateUsers',
    'C4mDemoContentCreateGroups',
    'C4mDemoContentCreateCategories',
    'C4mDemoContentCreateTags',
  );

  /**
   * Configure the migration class during creation.
   */
  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('uid', 'uid')
         ->sourceMigration('C4mDemoContentCreateUsers');

    $this->addFieldMapping(OG_AUDIENCE_FIELD, OG_AUDIENCE_FIELD);

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

    switch ($row->group_type) {
      case 'group':
        $unfiltered_ids = $this->handleSourceMigration(
          'C4mDemoContentCreateGroups',
          $row->group_map,
          NULL,
          $this
        );
        break;

      case 'project':
        $unfiltered_ids = $this->handleSourceMigration(
          'C4mDemoContentCreateProjects',
          $row->group_map,
          NULL,
          $this
        );
        break;
    }

    $row->{OG_AUDIENCE_FIELD} = $this->filterDestid2FromEntityReference(
      $unfiltered_ids
    );

    return TRUE;
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

    // Make sure the update message also exists.
    $this->messageUpdateSave($entity, $row);
  }

  /**
   * Reset the $message->timestamp of any related insert message (if any).
   *
   * @param object $node
   *   Node object we want to set the message timestamp for.
   * @param object $row
   *   The source data of the migrated entity.
   */
  public function messageInsertSave($node, $row) {
    if (!module_exists('c4m_message')) {
      return;
    }

    // Load the message(s).
    $message_type = 'c4m_insert__node__' . $node->type;
    $query        = new EntityFieldQuery();
    $result       = $query
      ->entityCondition('entity_type', 'message')
      ->propertyCondition('type', $message_type)
      ->fieldCondition('field_node', 'target_id', $node->nid)
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

  /**
   * Create optional update messages.
   *
   * @param object $node
   *   Node object we want to set the message timestamp for.
   * @param object $row
   *   The source data of the migrated entity.
   */
  public function messageUpdateSave($node, $row) {
    if (!module_exists('c4m_message') || empty($node->_skip_message)) {
      return;
    }

    if ($row->changed <= $row->created) {
      return;
    }

    $account = user_load($node->uid);

    $message = c4m_message__update__node($node, $account);

    $message->timestamp = $row->changed;
    message_save($message);
  }

}
