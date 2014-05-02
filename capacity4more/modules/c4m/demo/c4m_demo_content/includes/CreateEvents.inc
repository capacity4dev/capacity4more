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
    array('tags', 'Tags'),
    array('group_map', 'Group'),
    array('group_type', 'Group Type'),
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

    $this->addFieldMapping('c4m_vocab_tag', 'tags')
      ->sourceMigration('C4mDemoContentCreateTags')
      ->arguments(array('source_type' => 'tid'))
      ->separator('|');
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    parent::prepareRow($row);
  }

  /**
   * {@inheritdoc}
   */
  public function prepare($entity, $row) {
    $this->extractDateTimeEnd($entity, $row, 'field_date');

    $this->assignTags($entity, $row);
  }

  /**
   * {@inheritdoc}
   */
  public function complete($entity, $row) {
    $this->extractAddress($entity, $row);
  }
}
