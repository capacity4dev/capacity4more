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
  protected $textFormat = 'full_html';

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
    array('topics', 'Topics'),
    array('geo', 'Geo'),
    array('intro', 'Intro text'),
    array('banner', 'Banner'),
    array('uid', 'UID'),
    array('groups', 'Groups'),
    array('articles', 'Articles'),
    array('related_users', 'Contributors'),
    array('contributors', 'External Contributors'),
  );

  /**
   * Creation classes that should run before this one.
   *
   * @var array
   */
  public $dependencies = array(
    'C4mDemoContentCreateUsers',
    'C4mDemoContentCreateGroups',
    'C4mDemoContentCreateProjects',
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

    $this->addFieldMapping('c4m_body', 'body');

    $this->addFieldMapping('c4m_vocab_topic', 'topics')
      ->sourceMigration('C4mDemoContentCreateTopicTerms')
      ->arguments(array('source_type' => 'tid'))
      ->separator('|');

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

    $this->addFieldMapping('c4m_related_group', 'groups_list');

    $this->addFieldMapping('c4m_related_articles', 'articles_list');

    $this->addFieldMapping('c4m_related_user', 'related_users')
      ->sourceMigration('C4mDemoContentCreateUsers')
      ->separator('|');

    $this->addFieldMapping('c4m_link_multiple', 'contributors_url');
    $this->addFieldMapping('c4m_link_multiple:title', 'contributors_name');
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

    $row->geo_entries = $this->mapTaxonomyVocabWithParent(
      $this->mapTaxonomyVocab($row->geo, 'c4m_vocab_geo')
    );

    $unfiltered_ids = $this->handleSourceMigration(
      'C4mDemoContentCreateGroups',
      explode('|', $row->groups),
      NULL,
      $this
    );
    $row->groups_list = $this->filterDestid2FromEntityReference(
      $unfiltered_ids
    );

    $unfiltered_ids = $this->handleSourceMigration(
      'C4mDemoContentCreateArticles',
      explode('|', $row->articles),
      NULL,
      $this
    );
    $row->articles_list = $this->filterDestid2FromEntityReference(
      $unfiltered_ids
    );

    if (!empty($row->contributors)) {
      $split_contributors = explode(';', $row->contributors);
      $row->contributors_url = $split_contributors[0];
      $row->contributors_name = $split_contributors[1];
    }

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

  /**
   * Create stub Articles (when possible as related articles).
   *
   * @param Migration $migration
   *   The migration that is being done to create this stub.
   * @param array $source_id
   *   Array of strings with the source id(s).
   *
   * @return array|bool
   *   Array with node id if article created, else FALSE.
   */
  public function createStub(Migration $migration, array $source_id) {
    $node = new stdClass();
    $node->title = t('Stub for @id', array('@id' => $source_id[0]));
    $node->body[LANGUAGE_NONE][0] = t('Stub article');
    $node->type = $this->destination->getBundle();
    $node->uid = 1;
    $node->status = 0;
    node_save($node);
    if (isset($node->nid)) {
      return array($node->nid);
    }
    else {
      return FALSE;
    }
  }

}
