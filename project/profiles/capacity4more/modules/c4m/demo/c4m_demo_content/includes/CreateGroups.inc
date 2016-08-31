<?php

/**
 * @file
 * Class to create the Group nodes.
 */

/**
 * Class C4mDemoContentCreateGroups.
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
    array('banner', 'Banner'),
    array('body', 'Body'),
    array('topics', 'Topics'),
    array('geo', 'Geo'),
    array('groups', 'Groups'),
    array('projects', 'Projects'),
    array('membership_open_request', 'Membership_Request'),
    array('group_access', 'Access'),
    array('restricted_organisations', 'Organisations'),
    array('group_status', 'Status'),
  );

  /**
   * {@inheritdoc}
   */
  public function __construct() {
    parent::__construct();

    $this->addFieldMapping(OG_ACCESS_FIELD, 'group_access')
      ->defaultValue(0);
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    return parent::prepareRow($row);
  }

  /**
   * The entity has been created but not yet saved.
   *
   * @param object $entity
   *   The entity object that was created.
   * @param object $row
   *   The CSV row we are manipulating.
   */
  public function complete($entity, $row) {
    if ($row->group_access == 1 && $row->restricted_organisations) {
      $this->savePluggableNodeAccess($entity, $row);
    }

    $modifier = array(
      'provider' => 'og_purl|node',
      'value'    => $row->purl,
      'id'       => $entity->nid,
    );
    purl_save($modifier);
  }

  /**
   * Create stub Topics (when creating users), who will be replaced afterwards.
   *
   * @param Migration $migration
   *   The migration that is being done to create this stub.
   * @param array $source_id
   *   Array of strings with the source id(s).
   *
   * @return array|bool
   *   Array with group node id if term created, else FALSE.
   */
  public function createStub(Migration $migration, array $source_id) {
    $node = new stdClass();
    $node->title = t('Stub for @id', array('@id' => $source_id[0]));
    $node->body[LANGUAGE_NONE][0] = t('Stub group');
    $node->type = $this->destination->getBundle();
    $node->uid = 1;
    $node->status = 0;
    node_save($node);
    if (isset($node->nid)) {
      return array($node->nid);
    }
    else {
      return FALSE;
    }
  }

}
