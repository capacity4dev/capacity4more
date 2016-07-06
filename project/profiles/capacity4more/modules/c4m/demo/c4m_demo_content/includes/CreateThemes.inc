<?php

/**
 * @file
 * Class to create the Theme vocabulary terms.
 */

/**
 * Class C4mDemoContentCreateThemes.
 */
class C4mDemoContentCreateThemes extends C4mDemoContentCreateEntity {
  public $bundle = 'c4m_vocab_theme';

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
          array('name', 'Name'),
          array('description', 'Description'),
        );
        $this->addFieldMapping('name', 'name');
        $this->addFieldMapping('description', 'description');

        $this->csvColumns = $csv_columns;
        break;
    }

    $this->postConstruct($class_name);
  }

}
