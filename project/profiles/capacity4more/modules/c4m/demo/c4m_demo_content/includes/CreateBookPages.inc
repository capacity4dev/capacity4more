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
    array('parent', 'PID'),
    array('weight', 'Weight'),
    array('menu_name', 'Menu'),
    array('menu_weight', 'Menu Weight'),
    array('title', 'Title'),
    array('body', 'Body'),
    array('uid', 'UID'),
  );

  /**
   * Content creations need to be run before this one.
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


    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('C4mDemoContentCreateUsers');
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

    if (!empty($row->parent)) {
      $unfiltered_ids = $this->handleSourceMigration(
        'C4mDemoContentCreateBookPages',
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

    return TRUE;

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
    // Take care of import --update.
    // Now there's an Integrity constraint violation
    // Duplicate entry for key nid.
    $update = FALSE;
    if (!empty($entity->book) && !empty($entity->book['nid'])) {
      if ($entity->book['nid'] !== 'new' || intval($entity->book['nid']) != 0) {
        $update = TRUE;
      }
    }

    if (!empty($row->pid)) {
      $parent_node = node_load($row->pid['destid1']);
    }

    if (!$parent_node) {
      $book = array(
        'pick-book' => 'Change book (update list of parents)',
        'bid' => 'new',
        'has_children' => 0,
        'options' => array(),
        'module' => 'book',
        'original_bid' => 0,
        'parent_depth_limit' => C4M_CONTENT_WIKI_PAGE_MAX_DEPTH,
        'weight' => '0',
      );
    }
    else {
      $book = $parent_node->book;

      $book['plid'] = $book['mlid'];
      $book['nid'] = $entity->nid;

      if ($update) {
        $book['mlid'] = c4m_content_wiki_page_get_mlid_by_nid($entity->nid);
      }
      else {
        unset($book['mlid']);
      }
    }

    $book['weight'] = $row->weight;

    $entity->book = $book;

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
    // Create proper nested url aliases.
    pathauto_entity_path_delete_all('node', $entity);
    pathauto_node_update_alias($entity, 'insert');

    if (!empty($row->menu_name)) {
      // Enable the menu.
      $menu = $entity->menu;
      $menu['link_title'] = $entity->title;
      $menu['menu_name'] = $row->menu_name;
      $menu['plid'] = 0;
      $menu['enabled'] = 1;
      $menu['weight'] = isset($row->menu_weight) ? $row->menu_weight : 0;
      $entity->menu = $menu;
      // Manually save the node.
      entity_save('node', $entity);
    }
  }

}
