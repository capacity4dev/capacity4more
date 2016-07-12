<?php

/**
 * @file
 * Migrate class to create Organizations.
 */

/**
 * Class C4mDemoContentCreateOrganisations.
 */
class C4mDemoContentCreateBookPages extends C4mDemoContentCreateEntity {
  public $entityType = 'node';
  public $bundle = 'book';

  /**
   * CSV column mapping.
   *
   * @var array
   */
  public $csvColumns = array(
    array('id', 'ID'),
    array('menu_name', 'Menu'),
    array('title', 'Title'),
    array('body', 'Body'),
    array('uid', 'UID'),
  );

  /**
   * Class constructor.
   */
  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('c4m_body', 'body');
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
    // Enable the menu.
    $menu = $entity->menu;
    $menu['link_title'] = $entity->title;
    $menu['menu_name'] = $row->menu_name;
    $menu['plid'] = 0;
    $menu['enabled'] = 1;
    $entity->menu = $menu;

    // Manually save the node.
    entity_save('node', $entity);
  }

}
