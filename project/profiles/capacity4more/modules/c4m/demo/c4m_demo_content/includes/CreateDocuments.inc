<?php

/**
 * @file
 * Migrate class to create group documents.
 */

/**
 * Class C4mDemoContentCreateDocuments.
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

    $this->addFieldMapping('c4m_vocab_topic', 'topics')
      ->sourceMigration('C4mDemoContentCreateTopicTerms')
      ->arguments(array('source_type' => 'tid'))
      ->separator('|');

    $this->addFieldMapping('c4m_vocab_geo', 'geo_entries')
      ->arguments(array('source_type' => 'tid'));

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

    // Saves the file to the database.
    $file = $this->fileUriToObject(drupal_get_path('module', 'c4m_demo_content') . '/files/' . $row->file);

    // Change the migration file name to the file ID - since the migration is
    // expecting an entity reference.
    $row->file = $file->fid;

    $row->geo_entries = $this->mapTaxonomyVocabWithParent(
      $this->mapTaxonomyVocab($row->geo, 'c4m_vocab_geo')
    );

    $row->date_entries = $this->mapTaxonomyVocab($row->date, 'c4m_vocab_date');
    $row->lang_entries = $this->mapTaxonomyVocab($row->lang, 'c4m_vocab_language');
    $row->doc_entries = $this->mapTaxonomyVocab($row->doc_type, 'c4m_vocab_document_type');

    return TRUE;
  }

}
