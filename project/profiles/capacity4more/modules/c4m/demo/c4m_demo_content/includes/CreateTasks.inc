<?php
/**
 * @file
 * Migrate class to create group tasks and assign them to a tasklist.
 */

/**
 * Class C4mDemoContentCreateTasks.
 */
class C4mDemoContentCreateTasks extends C4mDemoContentCreateOgContent {
  public $bundle = 'task';

  /**
   * CSV column mapping.
   *
   * @var array
   */
  public $csvColumns = array(
    array('id', 'ID'),
    array('tasklist', 'Tasklist'),
    array('title', 'Title'),
    array('status', 'Status'),
    array('priority', 'Priority'),
    array('assigned_to', 'Assign To'),
    array('field_date', 'Deadline'),
    array('body', 'Body'),
    array('related_docs', 'Documents'),
    array('group_map', 'Group'),
    array('group_type', 'Group Type'),
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
    $this->dependencies[] = 'C4mDemoContentCreateTasklists';

    $this->addFieldMapping('c4m_related_tasklist', 'tasklist')
         ->sourceMigration('C4mDemoContentCreateTasklists');

    $this->addFieldMapping('c4m_task_status', 'status');

    $this->addFieldMapping('c4m_task_priority', 'priority');

    $this->addFieldMapping('c4m_task_assigned_to', 'assigned_to')
         ->sourceMigration('C4mDemoContentCreateUsers');

    $this->addFieldMapping('c4m_body', 'body');

    $this->addFieldMapping('c4m_tasklist_status', 'status');

    $this->addFieldMapping('c4m_related_document', 'documents');

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
    $this->extractDate($entity, $row, 'field_date');
  }

}
