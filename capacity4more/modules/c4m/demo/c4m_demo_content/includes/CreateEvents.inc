<?php
/**
 * @file
 * Migrate class to create group events.
 */

/**
 * Class C4mDemoContentCreateEvents
 */
class C4mDemoContentCreateEvents extends C4mDemoContentCreateOgContent {
  public $bundle = 'event';

  /**
   * CSV column mapping.
   *
   * @var array
   */
  public $csvColumns = array(
    array('id', 'ID'),
    array('title', 'Title'),
    array('field_date', 'Date'),
    array('organizer', 'Organizer'),
    array('body', 'Body'),
    array('location', 'Location'),
    array('categories', 'Categories'),
    array('topics', 'Topics'),
    array('tags', 'Tags'),
    array('group_map', 'Group'),
    array('group_type', 'Group Type'),
    array('lang', 'Language'),
    array('uid', 'UID'),
  );

  /**
   * Class constructor.
   */
  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('c4m_body', 'body');
    $this->addFieldMapping('field_date', 'field_date');

    $this->addFieldMapping('c4m_organised_by', 'organizer')
         ->separator(';');

    $this->addFieldMapping('c4m_location', 'location');

    // Can't abstract categories and tags since not all content types have them.
    $this->addFieldMapping('c4m_vocab_categories', 'categories')
         ->sourceMigration('C4mDemoContentCreateCategories')
         ->arguments(array('source_type' => 'tid'))
         ->separator('|');

    $this->addFieldMapping('c4m_related_topic', 'topics_list');

    $this->addFieldMapping('c4m_vocab_tag', 'tags')
         ->sourceMigration('C4mDemoContentCreateTags')
         ->arguments(array('source_type' => 'tid'))
         ->separator('|');

    $this->addFieldMapping('c4m_vocab_language', 'lang_entries')
         ->arguments(array('source_type' => 'tid'));
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    parent::prepareRow($row);

    $row->lang_entries = $this->mapTaxonomyVocab($row->lang, 'c4m_vocab_language');
    // TOPIC references.
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
  }

  /**
   * The entity has been created (not saved yet, so no nid created).
   *
   * @param object $entity
   *   The entity object that was created.
   * @param object $row
   *   The CSV row we are manipulating.
   */
  public function prepare($entity, $row) {
    $this->extractDateTimeEnd($entity, $row, 'field_date');

    $this->assignTags($entity, $row);
  }

  /**
   * The entity has been created and saved.
   *
   * @param object $entity
   *   The entity object that was created.
   * @param object $row
   *   The CSV row we are manipulating.
   */
  public function complete($entity, $row) {
    $this->extractAddress($entity, $row);
  }
}
