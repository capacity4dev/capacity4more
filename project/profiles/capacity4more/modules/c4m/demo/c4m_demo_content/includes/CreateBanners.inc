<?php

/**
 * @file
 * Migrate class to create group banners.
 */

/**
 * Class C4mDemoContentCreateBanners.
 */
class C4mDemoContentCreateBanners extends C4mDemoContentCreateOgContent {
  public $bundle = 'banner';

  /**
   * CSV column mapping.
   *
   * @var array
   */
  public $csvColumns = array(
    array('id', 'ID'),
    array('title', 'Title'),
    array('image', 'Image'),
    array('uid', 'UID'),
  );

  /**
   * Class constructor.
   */
  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('c4m_banner', 'image');
    $this->addFieldMapping('c4m_banner:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('c4m_banner:source_dir')
      ->defaultValue(drupal_get_path('module', 'c4m_demo_content') . '/images');

  }

}
