<?php
/**
 * @file
 * Class to create the Category vocabulary terms.
 */

/**
 * Class C4mDemoContentCreateTopicTerms.
 */
class C4mDemoContentCreateTopicTerms extends C4mDemoContentCreateEntity {
  public $bundle = 'c4m_vocab_topic';

  /**
   * Content creations need to be run before this one.
   *
   * @var array
   */
  public $dependencies
    = array(
      'C4mDemoContentCreateUsers',
    );

  public $entityType = 'taxonomy_term';

  /**
   * Class constructor.
   */
  public function __construct() {
    parent::__construct();

    // Settings based on the entity type.
    switch ($this->entityType) {
      case 'taxonomy_term':
        $class_name = 'MigrateDestinationTerm';

        $csv_columns = array(
          array('id', 'ID'),
          array('parent', 'Parent'),
          array('name', 'Name'),
          array('description', 'Description'),
          array('mapping', 'Mapping'),
        );
        $this->addFieldMapping('parent_name', 'parent');
        $this->addFieldMapping('name', 'name');
        $this->addFieldMapping('description', 'description');

        $this->csvColumns = $csv_columns;
        break;
    }

    $this->postConstruct($class_name);
  }

  /**
   * Complete callback.
   *
   * @param object $term
   *   Drupal Term object.
   * @param object $row
   *   Source row object.
   */
  public function complete($term, $row) {
    if ($term->tid && $row->mapping) {
      c4m_vocab_topic_add_mapping(
        array(
          'tid'         => $term->tid,
          'source'      => $row->mapping,
          'destination' => $row->name,
        )
      );
    }
  }


  /**
   * Create stub terms (when creating users), who will be replaced afterwards.
   *
   * @param Migration $migration
   *   The migration that is being done to create this stub.
   * @param array $source_id
   *   Array of strings with the source id(s).
   *
   * @return array|bool
   *   Array with topic node id if term created, else FALSE.
   */
  public function createStub(Migration $migration, array $source_id) {
    $term = new stdClass();
    $term->name = t('Stub for @id', array('@id' => $source_id[0]));
    $term->vocabulary_machine_name = 'c4m_vocab_topic';

    $voc = taxonomy_vocabulary_machine_name_load('c4m_vocab_topic');
    $term->vid = $voc->vid;

    taxonomy_term_save($term);

    if (isset($term->tid)) {
      return array($term->tid);
    }
    else {
      return FALSE;
    }
  }

}
