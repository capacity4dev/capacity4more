<?php
/**
 * @file
 * Base class to create Entities.
 */

/**
 * Class C4mDemoContentCreateEntity.
 */
abstract class C4mDemoContentCreateEntity extends Migration {
  /**
   * The OG vocabulary to use.
   *
   * If the entity-type is "taxonomy_term", determine of the term should
   * be assigned to a vocabulary owned by OG-vocab.
   */
  public $ogVocab = FALSE;

  /**
   * Supported entity types.
   *
   * @var array
   */
  protected $supportedEntityTypes = array(
    'node',
    'taxonomy_term',
    'og_vocab',
  );

  /**
   * The text format to use for body fields.
   *
   * @var string
   */
  protected $textFormat = 'filtered_html';

  /**
   * Class constructor.
   */
  public function __construct() {
    parent::__construct(
      MigrateGroup::getInstance(C4M_DEMO_CONTENT_MIGRATION_GROUP)
    );

    // Make sure we can use it for node and term only.
    if (!$this->isEntityTypeSupported($this->entityType)) {
      throw new Exception(
        format_string(
          'C4mDemoContentCreateEntity does not support @type',
          array('@type' => $this->entityType)
        )
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
        $this->addFieldMapping('status', 'status')->defaultValue(1);
        $this->addFieldMapping('changed', 'changed');
        $this->addFieldMapping('promote', 'promote');
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
      array('text_format' => $this->textFormat)
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
    parent::prepareRow($row);
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

      // Give some content some updates.
      if (rand(0, 1)) {
        // Random update between creation time and current time.
        $row->changed = rand($row->created + 1, time());
      }
      else {
        $row->changed = $row->created;
      }
    }

    return TRUE;
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

    if (!$dest_field) {
      return array();
    }

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

  /**
   * Helper method to extract categories and tags into og_vocabulary.
   *
   * Take the categories and tags from a row and combine/manipulate them
   * into the right format to be stored in the og_vocabulary field.
   *
   * @param object $entity
   *   The entity being created by Migrate.
   * @param object $row
   *   The row being processed.
   */
  protected function assignTags($entity, $row) {
    // Retrieve and map the categories.
    $mapped_cat = $this->handleSourceMigration(
      'C4mDemoContentCreateCategories',
      explode('|', $row->categories),
      NULL,
      $this
    );

    if (!is_array($mapped_cat) && !empty($mapped_cat)) {
      $mapped_cat = array($mapped_cat);
    }

    // Retrieve and map the tags.
    $mapped_tag = $this->handleSourceMigration(
      'C4mDemoContentCreateTags',
      explode('|', $row->tags),
      NULL,
      $this
    );

    if (!is_array($mapped_tag) && !empty($mapped_tag)) {
      $mapped_tag = array($mapped_tag);
    }

    if (is_array($mapped_cat) && is_array($mapped_tag)) {
      $terms = array_merge($mapped_cat, $mapped_tag);
    }
    elseif (empty($mapped_cat)) {
      $terms = $mapped_tag;
    }
    elseif (empty($mapped_tag)) {
      $terms = $mapped_cat;
    }
    else {
      $terms = array();
    }

    if (!empty($terms)) {
      foreach ($terms as $key => $term) {
        $terms[$key] = array('target_id' => $term);
      }
      $entity->og_vocabulary[LANGUAGE_NONE] = $terms;
    }
  }

  /**
   * Prepare the date from a CSV file to the Drupal field.
   *
   * @param object $entity
   *   The prepared entity that will be inserted in our Drupal 7.
   * @param object $row
   *   The mapped CSV row.
   * @param string $fieldname
   *   The name of the field holding the date value.
   */
  public function extractDate($entity, $row, $fieldname) {
    // Fix start date.
    $date = $row->{$fieldname};

    if ($date == 'now') {
      $date = date('Y-m-d', time());
    }

    $entity->c4m_date[LANGUAGE_NONE][0] = array(
      'value' => $date,
      'date_type' => 'datetime',
    );
  }

  /**
   * Prepare the date from a CSV file to the Drupal field.
   *
   * @param object $entity
   *   The prepared entity that will be inserted in our Drupal 7.
   * @param object $row
   *   The mapped CSV row.
   * @param string $fieldname
   *   The name of the field holding the date value.
   */
  public function extractDateTimeEnd($entity, $row, $fieldname) {
    // Fix start/end dates.
    $date = explode(';', $row->{$fieldname});

    if ($date[0] == 'now') {
      $date[0] = date('Y-m-d H:i', time());
    }

    $entity->c4m_datetime_end[LANGUAGE_NONE][0] = array(
      'value' => $date[0],
      'date_type' => 'datetime',
    );

    // Adding the end date of the event.
    if (isset($date[1])) {
      if ($date[1] == 'now') {
        $date[1] = date('Y-m-d H:i', time());
      }

      $entity->c4m_datetime_end[LANGUAGE_NONE][0]['value2'] = $date[1];
    }
  }

  /**
   * Prepare the date from a CSV file to the Drupal field.
   *
   * @param object $entity
   *   The prepared entity that will be inserted in our Drupal 7.
   * @param object $row
   *   The mapped CSV row.
   * @param string $fieldname
   *   The name of the field holding the date value.
   */
  public function extractDateEnd($entity, $row, $fieldname) {
    // Fix start/end dates.
    $date = explode(';', $row->{$fieldname});

    if ($date[0] == 'now') {
      $date[0] = date('Y-m-d', time());
    }

    $entity->c4m_date_end[LANGUAGE_NONE][0] = array(
      'value' => $date[0],
      'date_type' => 'datetime',
    );

    // Adding the end date of the event.
    if (isset($date[1])) {
      if ($date[1] == 'now') {
        $date[1] = date('Y-m-d', time());
      }

      $entity->c4m_date_end[LANGUAGE_NONE][0]['value2'] = $date[1];
    }
  }

  /**
   * Helper method to combine an amount and currency for a "money" field.
   *
   * @param object $entity
   *   The entity object AFTER it has been saved (nid available).
   * @param object $row
   *   The source row we are processing.
   * @param string $amountfield
   *   Name of the field holding the amount.
   * @param string $currencyfield
   *   Name of the field holding the currency (abbreviation).
   */
  public function extractBudget($entity, $row, $amountfield, $currencyfield) {
    $amount = $row->{$amountfield};
    $currency = $row->{$currencyfield};

    $entity->c4m_money[LANGUAGE_NONE][0] = array(
      'amount' => $amount,
      'currency' => $currency,
    );
  }

  /**
   * Helper method to turn a CSV address into a getlocation field.
   *
   * Will explode the CSV semi-colon separated address field and fill
   * all properties of the getlocation field. It is important that all 11
   * indices are present in the source file (even if empty).
   *
   * @param object $row
   *   The source row we are processing.
   *
   * @return array
   *   Parts of the address.
   */
  public function explodeAddress($row) {
    $location = explode(';', $row->location);
    if (count($location) <= 1) {
      return FALSE;
    }

    $location_array = array(
      'name' => $location[0] ? $location[0] : '',
      'street' => $location[1] ? $location[1] : '',
      'additional' => $location[2] ? $location[2] : '',
      'city' => $location[3] ? $location[3] : '',
      'province' => $location[4] ? $location[4] : '',
      'postal_code' => $location[5] ? $location[5] : '',
      'country' => $location[6] ? $location[6] : '',
    );

    return $location_array;
  }

  /**
   * Helper method for the organisation domain field.
   *
   * Combine a domain icon state and domain values for a "domain" field.
   *
   * @param object $entity
   *   The entity object AFTER it has been saved (nid available).
   * @param object $row
   *   The source row we are processing.
   * @param string $domainfield
   *   Name of the field holding the domain data.
   */
  public function extractDomain($entity, $row, $domainfield) {
    $domains = explode(',', $row->$domainfield);
    if (count($domains) < 1) {
      return FALSE;
    }

    foreach ($domains as $domain) {
      $domain_data = explode('|', $domain);
      if (count($domain_data) > 1) {
        $entity->c4m_domain[LANGUAGE_NONE][] = array(
          'icon' => $domain_data[0],
          'domain' => $domain_data[1],
        );
      }
    }
  }

  /**
   * Map terms to the existing terms in the database for a specified taxonomy.
   *
   * @param string $sourcefield
   *   The source field name.
   * @param string $vocabname
   *   The name of the vocabulary.
   *
   * @return array
   *   The mapping.
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
   * Get an array of all the terms and their parents based on the given terms.
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
      $parent_tids = array_map(
        create_function('$term', 'return $term->tid;'),
        $parents
      );
      // $tid is included in $parent_tids array.
      $all_tids = array_merge($all_tids, $parent_tids);
    }

    $unique = array_unique($all_tids);
    sort($unique);

    return $unique;
  }

}
