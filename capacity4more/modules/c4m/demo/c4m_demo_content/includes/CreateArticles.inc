<?php
/**
 * @file
 * Migrate class to create articles.
 */

/**
 * Class C4mDemoContentCreateArticles.
 */
class C4mDemoContentCreateArticles extends C4mDemoContentCreateEntity {
  public $entityType = 'node';
  public $bundle = 'article';

  /**
   * CSV column mapping.
   *
   * @var array
   */
  public $csvColumns = array(
    array('id', 'ID'),
    array('title', 'Title'),
    array('body', 'Body'),
    array('image', 'Image'),
    array('video', 'Video'),
    array('topics', 'Topics'),
    array('geo', 'Geo'),
    array('intro', 'Intro text'),
    array('banner', 'Banner'),
    array('uid', 'UID'),
  );

  /**
   * Creation classes that should run before this one.
   *
   * @var array
   */
  public $dependencies = array(
    'C4mDemoContentCreateUsers',
    'C4mDemoContentCreateTopics',
    'C4mDemoContentCreateRegionNodes',
  );

  /**
   * Configure the migration class during creation.
   */
  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('c4m_media', 'image')
      ->separator(';');
    $this->addFieldMapping('c4m_media:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('c4m_media:source_dir')
      ->defaultValue(drupal_get_path('module', 'c4m_demo_content') . '/images');

    $this->addFieldMapping('c4m_body', 'body')
      ->arguments(array('format' => 'full_html'));

    $this->addFieldMapping('c4m_has_video', 'video');

    $this->addFieldMapping('c4m_related_topic', 'topics_list');

    $this->addFieldMapping('c4m_vocab_geo', 'geo_entries')
      ->arguments(array('source_type' => 'tid'));

    $this->addFieldMapping('c4m_intro_text', 'intro');

    $this->addFieldMapping('c4m_banner', 'banner');
    $this->addFieldMapping('c4m_banner:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('c4m_banner:source_dir')
      ->defaultValue(drupal_get_path('module', 'c4m_demo_content') . '/images');

    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('C4mDemoContentCreateUsers');
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
      'C4mDemoContentCreateTopics',
      explode('|', $row->topics),
      NULL,
      $this
    );

    // By default $unfiltered_ids is an array of arrays, containing the
    // destid1 => destination_nid, but destid2 => NULL.
    // This NULL value is counted however and added to the query, resulting
    // in errors. Therefore we need to filter it out.
    $row->topics_list = $this->filterDestid2FromEntityReference(
      $unfiltered_ids
    );

    $row->geo_entries = $this->mapTaxonomyVocabWithParent(
      $this->mapTaxonomyVocab($row->geo, 'c4m_vocab_geo')
    );

    return TRUE;
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
    $query = new EntityFieldQuery();
    $result = $query
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
    if (!module_exists('c4m_message')) {
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
