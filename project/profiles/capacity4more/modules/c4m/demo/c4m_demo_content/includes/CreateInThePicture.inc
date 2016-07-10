<?php

/**
 * @file
 * Migrate class to create in the picture content type.
 */

/**
 * Class C4mDemoContentCreateInThePicture.
 */
class C4mDemoContentCreateInThePicture extends C4mDemoContentCreateOgContent {
  public $bundle = 'inthe_picture';
  protected $textFormat = 'full_html';

  /**
   * CSV column mapping.
   *
   * @var array
   */
  public $csvColumns = array(
    array('id', 'ID'),
    array('title', 'Title'),
    array('heading', 'Heading'),
    array('body', 'Description'),
    array('image', 'Image'),
    array('link', 'Link'),
    array('page', 'Page'),
    array('uid', 'UID'),
  );

  /**
   * Creation classes that should run before this one.
   *
   * @var array
   */
  public $dependencies = array(
    'C4mDemoContentCreateUsers',
  );

  /**
   * Class constructor.
   */
  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('c4m_body', 'body');
    $this->addFieldMapping('c4m_heading', 'heading');

    $this->addFieldMapping('c4m_media', 'image');
    $this->addFieldMapping('c4m_media:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('c4m_media:source_dir')
      ->defaultValue(drupal_get_path('module', 'c4m_demo_content') . '/images');

    $this->addFieldMapping('c4m_link', 'link');

    $this->addFieldMapping('c4m_overview_page', 'page');
  }

}
