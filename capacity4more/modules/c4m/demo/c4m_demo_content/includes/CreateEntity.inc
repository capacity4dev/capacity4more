<?php
/**
 * @file
 * Base class to create Entities.
 */

abstract class C4mDemoContentCreateEntity extends Migration {
  /**
   * If the entity-type is "taxonomy_term", determine of the term should
   * be assigned to a vocabulary owned by OG-vocab.
   */
  public $ogVocab = FALSE;

  /**
   * Supported entity types
   *
   * @var array
   */
  protected $supportedEntityTypes = array(
    'node',
    'taxonomy_term',
    'og_vocab',
  );


  /**
   * Class constructor.
   */
  public function __construct() {
    parent::__construct(
      MigrateGroup::getInstance(C4M_DEMO_CONTENT_MIGRATION_GROUP)
    );

    // Make sure we can use it for node and term only.
    if (!$this->isEntityTypeSupported($this->entityType)) {
      throw new Exception(format_string(
        'C4mDemoContentCreateEntity does not support @type',
        array('@type' => $this->entityType))
      );
    }

    $this->description = t(
      'Import @type - @bundle from CSV file.',
      array('@type' => $this->entityType, '@bundle' => $this->bundle)
    );

    // Settings based on the entity type.
    switch ($this->entityType) {
      case 'node':
        $this->addFieldMapping('title', 'title');
        $this->addFieldMapping('created', 'created');
        $class_name = 'MigrateDestinationNode';
        break;

      case 'taxonomy_term':
        $class_name = 'MigrateDestinationTerm';

        $csv_columns = array(
          array('id', 'ID'),
          array('parent', 'Parent'),
          array('name', 'Name'),
          array('description', 'Description'),
        );
        $this->addFieldMapping('parent_name', 'parent');
        $this->addFieldMapping('name', 'name');
        $this->addFieldMapping('description', 'description');

        if ($this->ogVocab) {
          $this->addFieldMapping(OG_AUDIENCE_FIELD, OG_AUDIENCE_FIELD);
          $this->addFieldMapping(
            'vocabulary_machine_name',
            'vocabulary_machine_name'
          );
          $csv_columns[] = array(OG_AUDIENCE_FIELD, 'Site');
        }
        $this->csvColumns = $csv_columns;
        break;

      case 'og_vocab':
        $class_name = 'MigrateDestinationEntityAPI';
        break;
    }

    // Create a map object for tracking the relationships between source rows.
    $key = array(
      'id' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => TRUE,
      ),
    );
    $this->map = new MigrateSQLMap(
      $this->machineName,
      $key,
      MigrateDestinationEntityAPI::getKeySchema($this->entityType)
    );

    // Create a MigrateSource object.
    $csv_path = drupal_get_path('module', 'c4m_demo_content') . '/csv';
    $this->source = new MigrateSourceCSV(
      $csv_path . '/' . $this->entityType . '/' . $this->bundle . '.csv',
      $this->csvColumns,
      array('header_rows' => 1)
    );
    $this->destination = new $class_name(
      $this->bundle,
      array('text_format' => 'filtered_html')
    );
  }

  /**
   * Prepare rows before passing the data to the entity creation.
   *
   * @param object $row
   *   The row data.
   *
   * @return bool
   *   Success.
   */
  public function prepareRow($row) {
    // The migrate content isn't belong to any one, the default will be the
    // admin user.
    if (!$row->uid) {
      $row->uid = 1;
    }

    if ($this->entityType == 'taxonomy_term' && $this->ogVocab) {
      $this->prepareRowTaxonomyTerm($row);
    }

    if ($this->entityType == 'node') {
      // Create a random timestamp from the last year.
      $year_ago = time() - 3600 * 24 * 365;
      $row->created = rand($year_ago, time());
    }

    return TRUE;
  }

  /**
   * Prepare the entity.
   *
   * @param object $entity
   *   The newly created entity.
   * @param object $row
   *   The row data.
   */
  public function prepare($entity, $row) {
    if ($this->entityType == 'taxonomy_term' && $this->ogVocab) {
      $this->prepareTaxonomyTerm($entity, $row);
    }
  }

  /**
   * Prepare a taxonomy term for storage within groups.
   *
   * Add the group identifier to the vocabulary name, and set OG-vocab
   * relation to the newly created vocabulary.
   *
   * @param object $row
   *   The term data that will be stored.
   */
  private function prepareRowTaxonomyTerm(&$row) {
    $name = $this->bundle . '_' . $row->{OG_AUDIENCE_FIELD};
    if (!$vocabulary = taxonomy_vocabulary_machine_name_load($name)) {
      // Create a vocabulary for the bundle in the VSite.
      $vocabulary = (object) array(
        'machine_name' => $name,
        'name' => $this->bundle,
        'description' => '',
        'help' => '',
      );
      taxonomy_vocabulary_save($vocabulary);

      // Create an OG-vocab entity for all group-content bundles
      // @todo: Move to "OG-Vocab" migrate.
      // We can't save OG vocab for all bundles, as it fails in Travis.
      foreach (array_keys(os_get_bundles()) as $bundle) {
        $og_vocab = og_vocab_create_og_vocab($vocabulary->vid, 'node', $bundle);
        $og_vocab->save();
      }
    }

    $row->vocabulary_machine_name = $name;
  }

  /**
   * Set relation of the vocabulary to the group.
   *
   * @param object $entity
   *   The term entity.
   * @param object $row
   *   The term data used to create the entity.
   */
  private function prepareTaxonomyTerm($entity, $row) {
    $vocabulary = taxonomy_vocabulary_machine_name_load(
      $entity->vocabulary_machine_name
    );
    $gid = $entity->og_group_ref['destid1'];

    og_vocab_relation_save($vocabulary->vid, 'node', $gid);
  }

  /**
   * Filter the destiny field ID.
   *
   * @param array $dest_field
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
        $filtered_ids[$key] = array('destid1' => $dest['destid1']);
        if (!empty($dest['destid2'])) {
          $filtered_ids[$key]['destid2'] = $dest['destid2'];
        }
      }
    }

    return $filtered_ids;
  }

  /**
   * Check if the given entity type is supported.
   *
   * @param string $type
   *   The entity type to check.
   *
   * @return bool
   *   True if supported.
   */
  protected function isEntityTypeSupported($type) {
    return in_array($type, $this->supportedEntityTypes);
  }
}
