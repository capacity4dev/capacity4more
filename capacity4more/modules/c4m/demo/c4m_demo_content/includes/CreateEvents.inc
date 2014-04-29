<?php
/**
 * @file
 * Migrate class to create group events.
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

  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('c4m_body', 'body');
    $this->addFieldMapping('field_date', 'field_date');
    $this->addFieldMapping(OG_AUDIENCE_FIELD, OG_AUDIENCE_FIELD)
      ->sourceMigration(array('C4mDemoContentCreateGroups'));
//    $this->addFieldMapping(OG_VOCAB_FIELD, OG_VOCAB_FIELD)
//      ->sourceMigration(array('OsMigrateAuthorsTaxonomyTerm'))
//      ->separator('|');

    $this->addFieldMapping('c4m_organised_by', 'organizer')
      ->separator(';');

    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('C4mDemoContentCreateUsers');
  }

  public function prepare($entity, $row) {
    $date = explode(';', $row->field_date);

    if ($date[0] == 'now') {
      $date[0] = date('Y-m-d H:i', time());
    }

    $entity->c4m_datetime_end[LANGUAGE_NONE][0] = array(
      'value' => $date[0],
      'date_type' => 'datetime',
    );

    // Adding the end date of the event.
    if (isset($date[1])) {
      if ($date[1] == 'now') {
        $date[1] = date('Y-m-d H:i', time());
      }

      $entity->c4m_datetime_end[LANGUAGE_NONE][0]['value2'] = $date[1];
    }
  }
}
