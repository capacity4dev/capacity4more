<?php
/**
 * @file
 * Migrate class to create group photoalbums.
 */

/**
 * Class C4mDemoContentCreatePhotoalbums.
 */
class C4mDemoContentCreatePhotoalbums extends C4mDemoContentCreateOgContent {
  public $bundle = 'photoalbum';

  /**
   * CSV column mapping.
   *
   * @var array
   */
  public $csvColumns = array(
    array('id', 'ID'),
    array('title', 'Title'),
    array('body', 'Body'),
    array('categories', 'Categories'),
    array('tags', 'Tags'),
    array('group_map', 'Group'),
    array('group_type', 'Group Type'),
    array('date', 'Date'),
    array('lang', 'Language'),
    array('uid', 'UID'),
    array('topics', 'Topics'),
    array('promote', 'Promote'),
  );

  /**
   * Class constructor.
   */
  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('c4m_body', 'body');

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

    $this->addFieldMapping('c4m_vocab_topic', 'topics')
      ->sourceMigration('C4mDemoContentCreateTopicTerms')
      ->arguments(array('source_type' => 'tid'))
      ->separator('|');
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    parent::prepareRow($row);

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

}
