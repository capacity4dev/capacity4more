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
    array('group_map', 'Group'),
    array('group_type', 'Group Type'),
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
   * Class constructor.
   */
  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('c4m_body', 'body');
    $this->addFieldMapping('field_date', 'field_date');

    $this->addFieldMapping('c4m_organised_by', 'organizer')
      ->separator(';');

    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('C4mDemoContentCreateUsers');

    $this->addFieldMapping('c4m_location', 'location');

    $this->addFieldMapping('c4m_vocab_categories', 'categories')
      ->sourceMigration('C4mDemoContentCreateCategories')
      ->arguments(array('source_type' => 'tid'))
      ->separator('|');

    $this->addFieldMapping('c4m_vocab_tag', 'tags')
      ->sourceMigration('C4mDemoContentCreateTags')
      ->arguments(array('source_type' => 'tid'))
      ->separator('|');

    $this->addFieldMapping(OG_AUDIENCE_FIELD, OG_AUDIENCE_FIELD);
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    switch ($row->group_type) {
      case 'group':
        $unfiltered_ids = $this->handleSourceMigration('C4mDemoContentCreateGroups', $row->group_map, NULL, $this);
        break;

      case 'project':
        $unfiltered_ids = $this->handleSourceMigration('C4mDemoContentCreateProjects', $row->group_map, NULL, $this);
        break;
    }
    $row->{OG_AUDIENCE_FIELD} = $this->filterDestid2FromEntityReference(
      $unfiltered_ids
    );
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
