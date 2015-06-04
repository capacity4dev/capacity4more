<?php
/**
 * @file
 * Migrate class to create group tasklists.
 */

/**
 * Class C4mDemoContentCreateTasklists.
 */
class C4mDemoContentCreateTasklists extends C4mDemoContentCreateOgContent {
  public $bundle = 'tasklist';

  /**
   * CSV column mapping.
   *
   * @var array
   */
  public $csvColumns = array(
    array('id', 'ID'),
    array('title', 'Title'),
    array('status', 'Status'),
    array('body', 'Body'),
    array('managers', 'Managers'),
    array('related_docs', 'Documents'),
    array('categories', 'Categories'),
    array('tags', 'Tags'),
    array('group_map', 'Group'),
    array('group_type', 'Group Type'),
    array('topics', 'Topics'),
    array('date', 'Date'),
    array('lang', 'Language'),
    array('uid', 'UID'),
  );

  /**
   * Class constructor.
   */
  public function __construct() {
    parent::__construct();

    $this->dependencies[] = 'C4mDemoContentCreateDocuments';

    $this->addFieldMapping('c4m_body', 'body');

    $this->addFieldMapping('c4m_related_user', 'managers')
         ->sourceMigration('C4mDemoContentCreateUsers')
         ->separator('|');

    $this->addFieldMapping('c4m_tasklist_status', 'status');

    $this->addFieldMapping('c4m_related_document', 'documents');

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

    $this->addFieldMapping('c4m_vocab_date', 'date_entries')
         ->arguments(array('source_type' => 'tid'));

    $this->addFieldMapping('c4m_vocab_language', 'lang_entries')
         ->arguments(array('source_type' => 'tid'));
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
    $unfiltered_ids = $this->handleSourceMigration(
                           'C4mDemoContentCreateDocuments',
                             explode('|', $row->related_docs),
                             NULL,
                             $this
    );

    // By default $unfiltered_ids is an array of arrays, containing the
    // destid1 => destination_nid, but destid2 => NULL.
    // This NULL value is counted however and added to the query, resulting
    // in errors. Therefore we need to filter it out.
    $row->documents = $this->filterDestid2FromEntityReference(
                           $unfiltered_ids
    );

    $row->date_entries = $this->mapTaxonomyVocab($row->date, 'c4m_vocab_date');

    $row->lang_entries = $this->mapTaxonomyVocab($row->lang, 'c4m_vocab_language');

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
    $this->assignTags($entity, $row);
  }

}
