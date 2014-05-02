<?php
/**
 * @file
 * Class to create the Group nodes.
 */

/**
 * Class C4mDemoContentCreateGroups
 */
class C4mDemoContentCreateGroups extends C4mDemoContentCreateOgGroups {
  public $entityType = 'node';
  public $bundle = 'group';

  /**
   * CSV column mapping.
   *
   * First columns are necessary and used in the parent (super) class:
   * ID, UID, TITLE, PURL, IMAGE, BODY, TOPICS, GEO. Groups is related groups.
   *
   * @var array
   */
  public $csvColumns = array(
    array('id', 'ID'),
    array('uid', 'UID'),
    array('title', 'Title'),
    array('purl', 'PURL'),
    array('image', 'Image'),
    array('body', 'Body'),
    array('topics', 'Topics'),
    array('geo', 'Geo'),
    array('groups', 'Groups'),
    array('projects', 'Projects'),
  );


  public function __construct(){
    parent::__construct();
  }

  public function prepareRow($row){
    parent::prepareRow($row);
  }
}
