<?php
/**
 * @file
 * Base to create Og Classes.
 */

/**
 * Class C4mDemoContentCreateOgGroups.
 */
abstract class C4mDemoContentCreateOgGroups extends C4mDemoContentCreateEntity {
  protected $textFormat = 'default_html';

  /**
   * Creation classes that should run before this one.
   *
   * @var array
   */
  public $dependencies = array(
    'C4mDemoContentCreateUsers',
    'C4mDemoContentCreateOrganisations',
  );

  /**
   * Configure the migration class during creation.
   */
  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('c4m_media', 'image')
      ->separator(';');
    $this->addFieldMapping('c4m_media:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('c4m_media:source_dir')
      ->defaultValue(drupal_get_path('module', 'c4m_demo_content') . '/images');
    $this->addFieldMapping('c4m_banner', 'banner')
      ->separator(';');
    $this->addFieldMapping('c4m_banner:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('c4m_banner:source_dir')
      ->defaultValue(drupal_get_path('module', 'c4m_demo_content') . '/images');

    $this->addFieldMapping('c4m_body', 'body');

    $this->addFieldMapping('c4m_vocab_topic', 'topics')
      ->sourceMigration('C4mDemoContentCreateTopicTerms')
      ->arguments(array('source_type' => 'tid'))
      ->separator('|');

    $this->addFieldMapping('c4m_vocab_geo', 'geo_entries')
      ->arguments(array('source_type' => 'tid'));

    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('C4mDemoContentCreateUsers');

    $this->addFieldMapping('c4m_related_group', 'groups_list');

    $this->addFieldMapping('c4m_related_projects', 'projects_list');

    $this->addFieldMapping(
      'field_membership_open_request',
      'membership_open_request'
    )->defaultValue(OG_STATE_ACTIVE);

    $this->addFieldMapping(OG_ACCESS_FIELD, 'group_access')
      ->defaultValue(0);

    $this->addFieldMapping('c4m_og_status', 'group_status')
      ->defaultValue('published');
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
      'C4mDemoContentCreateGroups',
      explode('|', $row->groups),
      NULL,
      $this
    );
    $row->groups_list = $this->filterDestid2FromEntityReference(
      $unfiltered_ids
    );

    $unfiltered_ids = $this->handleSourceMigration(
      'C4mDemoContentCreateProjects',
      explode('|', $row->projects),
      NULL,
      $this
    );
    $row->projects_list = $this->filterDestid2FromEntityReference(
      $unfiltered_ids
    );

    $row->geo_entries = $this->mapTaxonomyVocabWithParent(
      $this->mapTaxonomyVocab($row->geo, 'c4m_vocab_geo')
    );

    return TRUE;
  }

  /**
   * Helper to create a pluggable node access record based on og_spaces_type.
   *
   * @param object $group
   *    Entity object (formed by Drupal).
   * @param object $row
   *    Row object.
   */
  public function savePluggableNodeAccess(&$group, $row) {
    $row->_pluggable_node_access = NULL;

    $unfiltered_ids = $this->handleSourceMigration(
      'C4mDemoContentCreateOrganisations',
      explode('|', $row->restricted_organisations),
      NULL,
      $this
    );
    $organisation_ids_destid1 = $this->filterDestid2FromEntityReference(
      $unfiltered_ids
    );

    $organisation_ids = array();
    if (count($organisation_ids_destid1) > 1
      && empty($organisation_ids_destid1['destid1'])
    ) {
      foreach ($organisation_ids_destid1 as $destid) {
        $organisation_ids[] = $destid['destid1'];
      }
    }
    elseif (!empty($organisation_ids_destid1['destid1'])) {
      $organisation_ids[] = $organisation_ids_destid1['destid1'];
    }

    if (!isset($organisation_ids)) {
      return;
    }

    // Create the pluggable node access record.
    $pluggable_node_access = c4m_og_save_pluggable_node_access_restricted(
      $group,
      $organisation_ids
    );

    if ($pluggable_node_access) {
      $group->group_access = array(
        LANGUAGE_NONE => array(
          0 => array(
            'value' => 1,
          ),
        ),
      );

      $group->pluggable_node_access = array(LANGUAGE_NONE => array());
      foreach ($pluggable_node_access as $na) {
        $group->pluggable_node_access[LANGUAGE_NONE][] = array(
          'target_id' => $na->id,
        );
      }

      $group->revision = FALSE;

      entity_save('node', $group);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function postImport() {
    parent::postImport();

    // Pluggable node access requires a node access rebuild.
    node_access_rebuild();

    c4m_og_reset_restricted_info();
  }

}
