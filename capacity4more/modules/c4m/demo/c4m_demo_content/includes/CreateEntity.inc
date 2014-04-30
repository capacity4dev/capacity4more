<?php
/**
 * @file
 * Base class to create Entities.
 */

/**
 * Class C4mDemoContentCreateEntity
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
        $this->postConstruct($class_name);
        break;
    }
  }

  /**
   * Create the right mapping between destination and migration source.
   *
   * @param string $class_name
   *   Class name depending on the type of entity.
   */
  public function postConstruct($class_name) {
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
    // The migrated content isn't belonging to any one,
    // default to the admin user.
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
