<?php
/**
 * @file
 * Migrate class to create group photoalbums.
 */

/**
 * Class C4mDemoContentCreatePageElements
 */
class C4mDemoContentCreatePageElements extends C4mDemoContentCreateOgContent {
  public $bundle = 'page_element';

  /**
   * CSV column mapping.
   *
   * @var array
   */
  public $csvColumns = array(
    array('id', 'ID'),
    array('title', 'Title'),
    array('body', 'Body'),
    array('field_page', 'Page'),
    array('field_position', 'Position'),
  );

  /**
   * Class constructor.
   */
  public function __construct() {
    parent::__construct();

    $fields = array(
      'title',
      'field_page',
      'field_position'
    );

    $this->addSimpleMappings($fields);

    $this->addFieldMapping('c4m_body', 'body');
  }
}
