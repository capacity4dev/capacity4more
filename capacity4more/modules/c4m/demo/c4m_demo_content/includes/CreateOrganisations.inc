<?php
/**
 * @file
 * Migrate class to create Organizations.
 */

/**
 * Class C4mDemoContentCreateOrganisations.
 */
class C4mDemoContentCreateOrganisations extends C4mDemoContentCreateOgContent {
  public $bundle = 'organisation';

  /**
   * CSV column mapping.
   *
   * @var array
   */
  public $csvColumns = array(
    array('id', 'ID'),
    array('title', 'Title'),
    array('body', 'Body'),
    array('image', 'Icon'),
    array('domain', 'Domain'),
  );

  /**
   * Class constructor.
   */
  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('c4m_body', 'body');
    $this->addFieldMapping('c4m_link', 'link');
    $this->addFieldMapping('c4m_domain', 'domain')
      ->separator(',');
    $this->addFieldMapping('c4m_icon', 'image');
    $this->addFieldMapping('c4m_icon:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('c4m_icon:source_dir')
      ->defaultValue(drupal_get_path('module', 'c4m_demo_content') . '/images');
    $this->addFieldMapping('c4m_icon:destination_dir', 'destination');
  }

}
