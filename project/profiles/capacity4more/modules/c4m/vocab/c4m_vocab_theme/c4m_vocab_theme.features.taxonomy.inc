<?php
/**
 * @file
 * c4m_vocab_theme.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function c4m_vocab_theme_taxonomy_default_vocabularies() {
  return array(
    'c4m_vocab_theme' => array(
      'name' => 'Theme',
      'machine_name' => 'c4m_vocab_theme',
      'description' => 'Categorize topics in themes',
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
