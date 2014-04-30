<?php
/**
 * @file
 * Migrate class to create group events.
 */

/**
 * Class C4mDemoContentCreateEvents
 */
class C4mDemoContentCreateEvents extends C4mDemoContentCreateEntity {
  public $entityType = 'node';
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
    array(OG_AUDIENCE_FIELD, 'Group'),
    array('uid', 'UID'),
  );

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
   * Holds the og_vocabulary taxonomies.
   *
   * @var array
   */
  public $taxonomyFields = array();

  /**
   * Class constructor.
   */
  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('c4m_body', 'body');
    $this->addFieldMapping('field_date', 'field_date');
    $this->addFieldMapping(OG_AUDIENCE_FIELD, OG_AUDIENCE_FIELD)
      ->sourceMigration(array('C4mDemoContentCreateGroups'));

    $this->addFieldMapping('c4m_organised_by', 'organizer')
      ->separator(';');

    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('C4mDemoContentCreateUsers');

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
  public function prepare($entity, $row) {
    $this->extractDateTimeEnd($entity, $row);

    $this->assignTags($entity, $row);
  }
}
