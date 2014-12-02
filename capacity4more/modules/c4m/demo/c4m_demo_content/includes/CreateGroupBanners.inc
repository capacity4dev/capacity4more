<?php
/**
 * @file
 * Migrate class to create group banners.
 */

/**
 * Class C4mDemoContentCreateGroupBanners
 */
class C4mDemoContentCreateGroupBanners extends C4mDemoContentCreateOgContent {
  public $bundle = 'group_banner';

  /**
   * CSV column mapping.
   *
   * @var array
   */
  public $csvColumns = array(
    array('id', 'ID'),
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

    $this->addFieldMapping('c4m_banner', 'image');
    $this->addFieldMapping('c4m_banner:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('c4m_banner:source_dir')
      ->defaultValue(drupal_get_path('module', 'c4m_demo_content') . '/images');

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
}
