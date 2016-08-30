<?php

/**
 * @file
 * Class to create the Project nodes.
 */

/**
 * Class C4mDemoContentCreateProjects.
 */
class C4mDemoContentCreateProjects extends C4mDemoContentCreateOgGroups {
  public $entityType = 'node';
  public $bundle = 'project';

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
    array('duration', 'Duration'),
    array('budget_amount', 'Budget'),
    array('budget_currency', 'Currency'),
    array('funding', 'Funding'),
    array('partner', 'Partner'),
    array('implementation', 'Implementation'),
    array('cris_decision', 'CRIS Decision'),
    array('cris_contract', 'CRIS Contract'),
    array('body', 'Body'),
    array('topics', 'Topics'),
    array('geo', 'Geo'),
    array('groups', 'Groups'),
    array('projects', 'Projects'),
    array('is_template', 'Template'),
  );

  /**
   * Configure the migration class during creation.
   */
  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('c4m_source_of_funding', 'funding')
      ->separator(';');

    $this->addFieldMapping('c4m_partner', 'partner')
      ->separator(';');

    $this->addFieldMapping('c4m_implemented_by', 'implementation')
      ->separator(';');

    $this->addFieldMapping('c4m_cris_decision_number', 'cris_decision')
      ->separator(';');

    $this->addFieldMapping('c4m_cris_contract_number', 'cris_contract')
      ->separator(';');

    $this->addFieldMapping('c4m_project_type')
      ->defaultValue('project');

    $this->addFieldMapping('c4m_is_template', 'is_template')
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
  public function prepare($entity, $row) {
    $this->extractDateEnd($entity, $row, 'duration');

    $this->extractBudget($entity, $row, 'budget_amount', 'budget_currency');
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
    $modifier = array(
      'provider' => 'og_purl|node',
      'value' => $row->purl,
      'id' => $entity->nid,
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
   *   Array with project node id if term created, else FALSE.
   */
  public function createStub(Migration $migration, array $source_id) {
    $node = new stdClass();
    $node->title = t('Stub for @id', array('@id' => $source_id[0]));
    $node->body[LANGUAGE_NONE][0] = t('Stub project');
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
