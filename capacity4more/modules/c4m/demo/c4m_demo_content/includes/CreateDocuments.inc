<?php
/**
 * @file
 * Migrate class to create group documents.
 */

/**
 * Class C4mDemoContentCreateDocuments
 */
class C4mDemoContentCreateDocuments extends C4mDemoContentCreateOgContent {
  public $bundle = 'document';

  /**
   * CSV column mapping.
   *
   * @var array
   */
  public $csvColumns = array(
    array('id', 'ID'),
    array('title', 'Title'),
    array('body', 'Body'),
    array('file', 'File'),
    array('categories', 'Categories'),
    array('tags', 'Tags'),
    array('group_map', 'Group'),
    array('group_type', 'Group Type'),
    array('doc_type', 'Document Type'),
    array('topics', 'Topics'),
    array('geo', 'Geo'),
    array('date', 'Date'),
    array('lang', 'Language'),
    array('uid', 'UID'),
    array('promote', 'promote'),
  );

  /**
   * Class constructor.
   */
  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('c4m_body', 'body');

    $this->addFieldMapping('c4m_document', 'file')
      ->separator(';');
    $this->addFieldMapping('c4m_document:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('c4m_document:source_dir')
      ->defaultValue(drupal_get_path('module', 'c4m_demo_content') . '/files');

    // Can't abstract categories and tags since not all content types have them.
    $this->addFieldMapping('c4m_vocab_categories', 'categories')
      ->sourceMigration('C4mDemoContentCreateCategories')
      ->arguments(array('source_type' => 'tid'))
      ->separator('|');

    $this->addFieldMapping('c4m_vocab_tag', 'tags')
      ->sourceMigration('C4mDemoContentCreateTags')
      ->arguments(array('source_type' => 'tid'))
      ->separator('|');

    $this->addFieldMapping('c4m_related_topic', 'topics_list');

    $this->addFieldMapping('c4m_vocab_geo', 'geo')
      ->sourceMigration('C4mDemoContentCreateRegionTerms')
      ->arguments(array('source_type' => 'tid'))
      ->separator('|');

    $this->addFieldMapping('c4m_vocab_date', 'date_entries')
         ->arguments(array('source_type' => 'tid'));

    $this->addFieldMapping('c4m_vocab_language', 'lang_entries')
         ->arguments(array('source_type' => 'tid'));

    $this->addFieldMapping('c4m_vocab_document_type', 'doc_entries')
         ->arguments(array('source_type' => 'tid'));
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
    $this->assignTags($entity, $row);
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

    $row->date_entries = $this->mapTaxonomyVocab($row->date, 'c4m_vocab_date');

    $row->lang_entries = $this->mapTaxonomyVocab($row->lang, 'c4m_vocab_language');

    $row->doc_entries = $this->mapTaxonomyVocab($row->doc_type, 'c4m_vocab_document_type');
  }
}
