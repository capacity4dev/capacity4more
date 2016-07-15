<?php

/**
 * @file
 * Migrate class to create group photoalbums.
 */

/**
 * Class C4mDemoContentCreatePageElements.
 */
class C4mDemoContentCreatePageElements extends C4mDemoContentCreateOgContent {
  public $bundle = 'page_element';
  protected $textFormat = 'default_html';

  /**
   * CSV column mapping.
   *
   * @var array
   */
  public $csvColumns = array(
    array('id', 'ID'),
    array('title', 'Title'),
    array('body', 'Body'),
    array('page', 'Page'),
    array('position', 'Position'),
  );

  /**
   * Class constructor.
   */
  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('c4m_body', 'body');
    $this->addFieldMapping('c4m_page', 'page');
    $this->addFieldMapping('c4m_position', 'position');
  }

}
