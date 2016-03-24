<?php
/**
 * @file
 * c4m_vocab_language.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function c4m_vocab_language_taxonomy_default_vocabularies() {
  return array(
    'c4m_vocab_language' => array(
      'name' => 'Languages',
      'machine_name' => 'c4m_vocab_language',
      'description' => 'Language indication for content',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
