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
    $this->extractDate($entity, $row);
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    $tids = array();

    if (!empty($row->c4m_vocab_categories) && is_array($row->c4m_vocab_categories)) {
      foreach ($row->c4m_vocab_categories as $id => $tid) {
        $tids[] = $tid;
      }
    }

    if (!empty($row->c4m_vocab_tags) && is_array($row->c4m_vocab_tags)) {
      foreach ($row->c4m_vocab_tags as $id => $tid) {
        $tids[] = $tid;
      }
    }

    $row->{OG_VOCAB_FIELD} = $tids;
  }

  /**
   * Prepare the date from a CSV file to the Drupal field.
   *
   * @param object $entity
   *   The prepared entity that will be inserted in our Drupal 7.
   * @param object $row
   *   The mapped CSV row.
   */
  public function extractDate($entity, $row) {
    // Fix start/end dates.
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
