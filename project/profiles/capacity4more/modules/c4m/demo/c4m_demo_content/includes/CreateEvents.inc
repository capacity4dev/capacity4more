<?php
/**
 * @file
 * Migrate class to create group events.
 */

/**
 * Class C4mDemoContentCreateEvents.
 */
class C4mDemoContentCreateEvents extends C4mDemoContentCreateOgContent {
  public $bundle = 'event';
  protected $textFormat = 'default_html';

  /**
   * CSV column mapping.
   *
   * @var array
   */
  public $csvColumns = array(
    array('id', 'ID'),
    array('title', 'Title'),
    array('event_type', 'Type'),
    array('field_date', 'Date'),
    array('organizer', 'Organizer'),
    array('event_website', 'Event website'),
    array('facebook', 'Facebook page'),
    array('twitter', 'Twitter page'),
    array('body', 'Body'),
    array('location', 'Location'),
    array('document_agenda', 'Agenda & Information'),
    array('document_presentation', 'Presentations'),
    array('related_document', 'Additional'),
    array('categories', 'Categories'),
    array('topics', 'Topics'),
    array('geo', 'Geo'),
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

    $this->addFieldMapping('c4m_event_type', 'event_type');

    $this->addFieldMapping('field_date', 'field_date');

    $this->addFieldMapping('c4m_organised_by', 'organizer')
      ->separator(';');

    $this->addFieldMapping('c4m_link', 'event_website');

    $this->addFieldMapping('c4m_facebook', 'facebook');

    $this->addFieldMapping('c4m_twitter', 'twitter');

    $this->addFieldMapping('c4m_location', 'location');

    $this->addFieldMapping('c4m_document_agenda', 'agenda');

    $this->addFieldMapping('c4m_document_presentation', 'presentation');

    $this->addFieldMapping('c4m_related_document', 'additional');

    $this->addFieldMapping('c4m_vocab_geo', 'geo_entries')
      ->arguments(array('source_type' => 'tid'));

    // Can't abstract categories and tags since not all content types have them.
    $this->addFieldMapping('c4m_vocab_categories', 'categories')
      ->sourceMigration('C4mDemoContentCreateCategories')
      ->arguments(array('source_type' => 'tid'))
      ->separator('|');

    $this->addFieldMapping('c4m_vocab_topic', 'topics')
      ->sourceMigration('C4mDemoContentCreateTopicTerms')
      ->arguments(array('source_type' => 'tid'))
      ->separator('|');

    $this->addFieldMapping('c4m_vocab_tag', 'tags')
      ->sourceMigration('C4mDemoContentCreateTags')
      ->arguments(array('source_type' => 'tid'))
      ->separator('|');

    $this->addFieldMapping('c4m_vocab_language', 'lang_entries')
      ->arguments(array('source_type' => 'tid'));

    $this->addFieldMapping(
      'c4m_location_address',
      'c4m_location_address_country'
    );
    $this->addFieldMapping(
      'c4m_location_address:thoroughfare',
      'c4m_location_address_street'
    );
    $this->addFieldMapping(
      'c4m_location_address:premise',
      'c4m_location_address_additional'
    );
    $this->addFieldMapping(
      'c4m_location_address:postal_code',
      'c4m_location_address_postal'
    );
    $this->addFieldMapping(
      'c4m_location_address:locality',
      'c4m_location_address_city'
    );
    $this->addFieldMapping(
      'c4m_location_address:administrative_area',
      'c4m_location_address_state'
    );
    $this->addFieldMapping(
      'c4m_location_address:name_line',
      'c4m_location_address_name'
    );
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    parent::prepareRow($row);

    // Agenda DOCUMENT references.
    $unfiltered_ids = $this->handleSourceMigration(
      'C4mDemoContentCreateDocuments',
      explode('|', $row->document_agenda),
      NULL,
      $this
    );

    // By default $unfiltered_ids is an array of arrays, containing the
    // destid1 => destination_nid, but destid2 => NULL.
    // This NULL value is counted however and added to the query, resulting
    // in errors. Therefore we need to filter it out.
    $row->agenda = $this->filterDestid2FromEntityReference(
      $unfiltered_ids
    );

    $unfiltered_ids = NULL;

    // Presentation DOCUMENT references.
    $unfiltered_ids = $this->handleSourceMigration(
      'C4mDemoContentCreateDocuments',
      explode('|', $row->document_presentation),
      NULL,
      $this
    );

    // By default $unfiltered_ids is an array of arrays, containing the
    // destid1 => destination_nid, but destid2 => NULL.
    // This NULL value is counted however and added to the query, resulting
    // in errors. Therefore we need to filter it out.
    $row->presentation = $this->filterDestid2FromEntityReference(
      $unfiltered_ids
    );

    $unfiltered_ids = NULL;
    // Additional DOCUMENT references.
    $unfiltered_ids = $this->handleSourceMigration(
      'C4mDemoContentCreateDocuments',
      explode('|', $row->related_document),
      NULL,
      $this
    );

    // By default $unfiltered_ids is an array of arrays, containing the
    // destid1 => destination_nid, but destid2 => NULL.
    // This NULL value is counted however and added to the query, resulting
    // in errors. Therefore we need to filter it out.
    $row->additional = $this->filterDestid2FromEntityReference(
      $unfiltered_ids
    );

    $row->lang_entries = $this->mapTaxonomyVocab(
      $row->lang,
      'c4m_vocab_language'
    );
    $row->geo_entries = $this->mapTaxonomyVocabWithParent(
      $this->mapTaxonomyVocab($row->geo, 'c4m_vocab_geo')
    );

    $address = $this->explodeAddress($row);

    $row->c4m_location_address_country = $address['country'];
    $row->c4m_location_address_street = $address['street'];
    $row->c4m_location_address_additional = $address['additional'];
    $row->c4m_location_address_postal = $address['postal_code'];
    $row->c4m_location_address_city = $address['city'];
    $row->c4m_location_address_state = $address['province'];
    $row->c4m_location_address_name = $address['name'];

    return TRUE;
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

}
