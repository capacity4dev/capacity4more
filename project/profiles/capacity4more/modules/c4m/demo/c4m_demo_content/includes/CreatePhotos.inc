<?php
/**
 * @file
 * Migrate class to create group photos and attach them to an album.
 */

/**
 * Class C4mDemoContentCreatePhotos.
 */
class C4mDemoContentCreatePhotos extends C4mDemoContentCreateOgContent {
  public $bundle = 'photo';

  /**
   * CSV column mapping.
   *
   * @var array
   */
  public $csvColumns = array(
    array('id', 'ID'),
    array('gallery', 'Album'),
    array('title', 'Title'),
    array('body', 'Body'),
    array('image', 'Image'),
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

    $this->dependencies[] = 'C4mDemoContentCreatePhotoalbums';

    $this->addFieldMapping('c4m_body', 'body');

    $this->addFieldMapping('node_gallery_ref_1', 'gallery')
      ->sourceMigration('C4mDemoContentCreatePhotoalbums');

    $this->addFieldMapping('c4m_media', 'image')
      ->separator(';');
    $this->addFieldMapping('c4m_media:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('c4m_media:source_dir')
      ->defaultValue(drupal_get_path('module', 'c4m_demo_content') . '/images');
    $this->addFieldMapping('c4m_media:destination_dir', 'destination');

    $this->addFieldMapping('c4m_vocab_date', 'date_entries')
         ->arguments(array('source_type' => 'tid'));

    $this->addFieldMapping('c4m_vocab_language', 'lang_entries')
         ->arguments(array('source_type' => 'tid'));
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
   * The entity has been created but not yet saved.
   *
   * @param object $entity
   *   The entity object that was created.
   * @param object $row
   *   The CSV row we are manipulating.
   */
  public function prepare($entity, $row) {
    $entity->_skip_message = TRUE;
  }

}
