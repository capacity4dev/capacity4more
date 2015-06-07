<?php
/**
 * @file
 * Migrate class to create dummy users.
 */

/**
 * Class C4mDemoContentCreateUsers.
 */
class C4mDemoContentCreateUsers extends Migration {
  /**
   * Map the field and properties to the CSV header.
   */
  public $csvColumns = array(
    array('id', 'ID'),
    array('name', 'Username'),
    array('pass', 'Password'),
    array('mail', 'Email'),
    array('c4m_first_name', 'First name'),
    array('c4m_last_name', 'Last name'),
    array('description', 'Description'),
    array('picture', 'Picture'),
    array('c4m_organisation', 'Organisation'),
    array('c4m_organisation_type', 'Organisation Type'),
    array('c4m_country', 'Country'),
    array('topics_interest', 'Topic Interest'),
    array('topics_expertise', 'Topic Expertise'),
    array('geo', 'Related geo'),
    array('role', 'Role'),
    array('groups_list', 'Groups'),
    array('projects_list', 'Projects'),
  );

  public $entityType = 'user';

  /**
   * Configure the object during creation.
   */
  public function __construct() {
    parent::__construct(
          MigrateGroup::getInstance(C4M_DEMO_CONTENT_MIGRATION_GROUP)
    );

    $this->description = t('Import users from a CSV file.');

    $this->addSimpleMappings(array(
      'name',
      'pass',
      'mail',
      'c4m_first_name',
      'c4m_last_name',
      'c4m_organisation',
      'c4m_organisation_type',
      'c4m_country',
    ));

    $this->addFieldMapping('c4m_body', 'description');

    $this->addFieldMapping('c4m_media', 'picture')
         ->separator(';');
    $this->addFieldMapping('c4m_media:file_replace')
         ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('c4m_media:source_dir')
         ->defaultValue(drupal_get_path('module', 'c4m_demo_content') . '/images');
    $this->addFieldMapping('c4m_media:destination_dir', 'destination');

    $this->addFieldMapping('roles')
         ->defaultValue(DRUPAL_AUTHENTICATED_RID);
    $this->addFieldMapping('status')
         ->defaultValue(TRUE);

    $this->addFieldMapping('c4m_vocab_topic', 'topics_interest')
      ->sourceMigration('C4mDemoContentCreateTopicTerms')
      ->arguments(array('source_type' => 'tid'))
      ->separator('|');

    $this->addFieldMapping('c4m_vocab_topic_expertise', 'topics_expertise')
      ->sourceMigration('C4mDemoContentCreateTopicTerms')
      ->arguments(array('source_type' => 'tid'))
      ->separator('|');

    $this->addFieldMapping('c4m_vocab_geo', 'geo_entries')
      ->arguments(array('source_type' => 'tid'));

    $this->addFieldMapping('og_user_node', 'og_user_node');

    // Create a map object for tracking the relationships between source rows.
    $key                 = array(
      'id' => array(
        'type'     => 'varchar',
        'length'   => 255,
        'not null' => TRUE,
      ),
    );
    $destination_handler = new MigrateDestinationUser();
    $this->map           = new MigrateSQLMap(
      $this->machineName,
      $key,
      $destination_handler->getKeySchema()
    );

    // Create a MigrateSource object.
    $csv_path          = drupal_get_path('module', 'c4m_demo_content') . '/csv';
    $this->source      = new MigrateSourceCSV(
      $csv_path . '/' . $this->entityType . '/user.csv',
      $this->csvColumns,
      array('header_rows' => 1)
    );
    $this->destination = new MigrateDestinationUser();
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
                             explode('|', $row->groups_list),
                             NULL,
                             $this
    );

    $groups = $this->filterDestid2FromEntityReference(
                   $unfiltered_ids
    );

    $unfiltered_ids = $this->handleSourceMigration(
                           'C4mDemoContentCreateProjects',
                             explode('|', $row->projects_list),
                             NULL,
                             $this
    );

    $projects = $this->filterDestid2FromEntityReference(
      $unfiltered_ids
    );

    $gids = array();
    foreach ($groups as $group) {
      if (!empty($group['destid1'])) {
        $gids[] = $group['destid1'];
      }
      else {
        $gids[] = $group;
      }
    }
    foreach ($projects as $project) {
      if (!empty($project['destid1'])) {
        $gids[] = $project['destid1'];
      }
      else {
        $gids[] = $project;
      }
    }

    // @TODO: ADD ROLES
    $row->og_user_node = $gids;

    $row->geo_entries = $this->mapTaxonomyVocabWithParent(
      $this->mapTaxonomyVocab($row->geo, 'c4m_vocab_geo')
    );

    return TRUE;
  }

  /**
   * Granting a role to the user from the CSV.
   *
   * @param object $entity
   *   The entity to create.
   * @param object $row
   *   The data from the CSV file.
   */
  public function complete($entity, $row) {
    if (!$row->role) {
      return;
    }

    $role                      = user_role_load_by_name($row->role);
    $entity->roles[$role->rid] = $row->role;

    user_save($entity);
  }

  /**
   * Filter the destiny field ID.
   *
   * @param mixed $dest_field
   *   The destiny field settings.
   *
   * @return array
   *   The filtered array.
   */
  protected function filterDestid2FromEntityReference($dest_field) {
    $filtered_ids = array();

    if (!empty($dest_field['destid1'])) {
      $filtered_ids = array('destid1' => $dest_field['destid1']);
      if (!empty($dest_field['destid2'])) {
        $filtered_ids['destid2'] = $dest_field['destid2'];
      }
    }
    elseif (is_array($dest_field)) {
      foreach ($dest_field as $key => $dest) {
        if (!empty($dest['destid1'])) {
          $filtered_ids[$key] = array('destid1' => $dest['destid1']);
        }
        // Stubs generate array('<value_1>', '<value_2>') without keys.
        else {
          $filtered_ids[$key] = array('destid1' => $dest);
        }
        if (!empty($dest['destid2'])) {
          $filtered_ids[$key]['destid2'] = $dest['destid2'];
        }
      }
    }

    return $filtered_ids;
  }

  /**
   * Map terms to the existing terms in the database for a specified taxonomy.
   *
   * @param string $sourcefield
   *   Source field name.
   * @param string $vocabname
   *   The name of the vocabulary to load the terms from.
   *
   * @return array
   *   The term id's.
   */
  public function mapTaxonomyVocab($sourcefield, $vocabname) {
    $vocab = taxonomy_vocabulary_machine_name_load($vocabname);

    if (!empty($vocab)) {
      $terms = explode('|', $sourcefield);
      if (!empty($terms)) {
        $tids = array();
        foreach ($terms as $term_name) {
          $term = taxonomy_get_term_by_name($term_name, $vocabname);
          if (!empty($term)) {
            reset($term);
            $tid = key($term);
            $tids[] = $tid;
          };
        }

        return $tids;
      }
    }

    return array();
  }

  /**
   * Load all the terms, including parents, based on a list of term id's.
   *
   * @param array $tids
   *   Array of term ids content is tagged with.
   *
   * @return array
   *   Array of term ids, including every term's parents.
   */
  public function mapTaxonomyVocabWithParent(array $tids) {
    $all_tids = array();
    foreach ($tids as $tid) {
      $parents = taxonomy_get_parents_all($tid);
      $parent_tids = array_map(create_function('$term', 'return $term->tid;'), $parents);
      // $tid is included in $parent_tids array.
      $all_tids = array_merge($all_tids, $parent_tids);
    }

    $unique = array_unique($all_tids);

    return $unique;
  }

}
