<?php
/**
 * @file
 * Class to create the Region vocabulary terms.
 */

/**
 * Class C4mDemoContentCreateRegionTerms
 */
class C4mDemoContentCreateRegionTerms extends C4mDemoContentCreateVocabularyTerms {
  public $bundle = 'c4m_vocab_geo';

  /**
   * Content creations need to be run before this one.
   *
   * @var array
   */
  public $dependencies = array(
    'C4mDemoContentCreateUsers',
  );

  /**
   * Create stub Topics (when creating users), who will be replaced afterwards.
   *
   * @param Migration $migration
   *   The migration that is being done to create this stub.
   * @param array $source_id
   *   Array of strings with the source id(s).
   *
   * @return array|bool
   *   Array with region term id if term created, else FALSE.
   */
  public function createStub(Migration $migration, array $source_id) {
    $vocab = taxonomy_vocabulary_machine_name_load('c4m_vocab_geo');
    $term = new stdClass();
    $term->name = t('Stub geo term for @id', array('@id' => $source_id[0]));
    $term->vid = $vocab->vid;
    $term->uid = 1;

    taxonomy_term_save($term);
    if (isset($term->tid)) {
      return array($term->tid);
    }
    else {
      return FALSE;
    }
  }
}
