<?php
/**
 * @file
 * Class to create the Project nodes.
 */

/**
 * Class C4mDemoContentCreateProjects
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
  );

  /**
   * Configure the migration class during creation.
   */
  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('c4m_banner', 'banner')
      ->separator(';');
    $this->addFieldMapping('c4m_banner:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('c4m_banner:source_dir')
      ->defaultValue(drupal_get_path('module', 'c4m_demo_content') . '/images');

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

    $this->addFieldMapping('c4m_related_projects', 'projects_list');
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

    $unfiltered_ids = $this->handleSourceMigration(
      'C4mDemoContentCreateProjects',
      explode('|', $row->projects),
      NULL,
      $this
    );
    $row->projects_list = $this->filterDestid2FromEntityReference(
      $unfiltered_ids
    );

    return TRUE;
  }

  /**
   * {@inheritdoc}
   */
  public function prepare($entity, $row) {
    $this->extractDateEnd($entity, $row, 'duration');

    $this->extractBudget($entity, $row, 'budget_amount', 'budget_currency');
  }
}
