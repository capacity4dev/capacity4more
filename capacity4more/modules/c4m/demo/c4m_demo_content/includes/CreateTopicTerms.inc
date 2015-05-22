<?php
/**
 * @file
 * Class to create the Category vocabulary terms.
 */

/**
 * Class C4mDemoContentCreateTopicTerms.
 */
class C4mDemoContentCreateTopicTerms
  extends C4mDemoContentCreateEntity {
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
   * @param object $row
   */
  public function complete($term, $row) {
    if ($term->tid && $row->mapping) {
      c4m_vocab_topic_add_mapping(
        array(
          'tid'         => $term->tid,
          'source'      => $row->mapping,
          'destination' => $row->title,
        )
      );
    }
  }

}
