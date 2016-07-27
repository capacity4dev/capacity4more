<?php

/**
 * @file
 * Base class to create OG Vocabularies.
 */

/**
 * Class C4mDemoContentCreateVocabulary.
 */
abstract class C4mDemoContentCreateVocabularyTerms extends C4mDemoContentCreateEntity {
  public $entityType = 'taxonomy_term';

  /**
   * Class constructor.
   */
  public function __construct() {
    parent::__construct();

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
          $csv_columns[] = array(OG_AUDIENCE_FIELD, 'Group');
          $csv_columns[] = array('group_type', 'Group Type');
        }
        $this->csvColumns = $csv_columns;
        break;

      case 'og_vocab':
        $class_name = 'MigrateDestinationEntityAPI';
        break;
    }

    $this->postConstruct($class_name);
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
    if ($this->entityType == 'taxonomy_term' && $this->ogVocab) {
      $this->prepareRowTaxonomyTerm($row);
    }

    return TRUE;
  }

  /**
   * Prepare a taxonomy term for storage within groups.
   *
   * Add the group identifier to the vocabulary name, and set OG-vocab
   * relation to the newly created vocabulary.
   *
   * @param object $row
   *   The term data that will be stored.
   *
   * @return bool
   *   Success.
   */
  protected function prepareRowTaxonomyTerm(&$row) {
    switch ($row->group_type) {
      case 'group':
        $mapped_id = $this->getMappedIds('C4mDemoContentCreateGroups', $row->{OG_AUDIENCE_FIELD});
        break;

      case 'project':
        $mapped_id = $this->getMappedIds('C4mDemoContentCreateProjects', $row->{OG_AUDIENCE_FIELD});
        break;
    }

    if (empty($mapped_id['destid1'])) {
      return FALSE;
    }

    $name = $this->bundle . '_' . $mapped_id['destid1'];

    $row->vocabulary_machine_name = $name;

    return TRUE;
  }

  /**
   * Helper method to retrieve mapped ids.
   *
   * @param string $source
   *   Migration Source (used to map source to destination).
   * @param string $row_field
   *   The field in our row to extract.
   *
   * @return array
   *   An array with destid1 and/or destid2.
   */
  protected function getMappedIds($source, $row_field) {
    return $this->handleSourceMigration(
      $source,
      $row_field,
      NULL,
      $this
    );
  }

}
