<?php
/**
 * @file
 * Migrate class to create group wiki pages.
 */

/**
 * Class C4mDemoContentCreatePages
 */
class C4mDemoContentCreatePages extends C4mDemoContentCreateOgContent {
  public $bundle = 'page';

  /**
   * CSV column mapping.
   *
   * @var array
   */
  public $csvColumns = array(
    array('id', 'ID'),
    array('parent', 'PID'),
    array('weight', 'Weight'),
    array('title', 'Title'),
    array('body', 'Body'),
    array('related_docs', 'Documents'),
    array('categories', 'Categories'),
    array('tags', 'Tags'),
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
    $this->dependencies[] = 'C4mDemoContentCreateGroups';
    $this->dependencies[] = 'C4mDemoContentCreateProjects';

    $this->addFieldMapping('c4m_body', 'body');

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

    if (!empty($row->parent)) {
      $unfiltered_ids = $this->handleSourceMigration(
                             'C4mDemoContentCreatePages',
                               $row->parent,
                               NULL,
                               $this
      );

      $row->pid = $this->filterDestid2FromEntityReference(
                       $unfiltered_ids
      );
    }
    else {
      $row->pid = NULL;
    }

    $row->date_entries = $this->mapTaxonomyVocab($row->date, 'c4m_vocab_date');

    $row->lang_entries = $this->mapTaxonomyVocab($row->lang, 'c4m_vocab_language');
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
   * Method executed after the entity is saved (nid available).
   *
   * @param object $entity
   *   The entity object that was created (after node_submit()).
   * @param object $row
   *   The CSV row we are manipulating.
   */
  public function complete($entity, $row) {
    // Take care of import --update.
    // Now there's an Integrity constraint violation
    // Duplicate entry for key nid.
    $update = FALSE;
    if (!empty($entity->book) && !empty($entity->book['nid'])) {
      if ($entity->book['nid'] !== 'new' || intval($entity->book['nid']) != 0) {
        $update = TRUE;
      }
    }

    $og_id = $row->{OG_AUDIENCE_FIELD}['destid1'];

    if (!empty($row->pid)) {
      $parent_node = node_load($row->pid['destid1']);
    }
    else {
      // Retrieve root book node (master page) if no parent was given.
      $parent_node = c4m_content_wiki_get_book_by_gid($og_id);
    }

    if (!$parent_node) {
      return;
    }

    $book = $parent_node->book;

    $book['plid'] = $book['mlid'];
    $book['nid']  = $entity->nid;

    if ($update) {
      $book['mlid'] = c4m_content_wiki_get_mlid_by_nid($entity->nid);
    }
    else {
      unset($book['mlid']);
    }

    $book['weight'] = $row->weight;

    $entity->book = $book;
    _book_update_outline($entity);

    // Manually save the node.
    entity_save('node', $entity);
  }
}
