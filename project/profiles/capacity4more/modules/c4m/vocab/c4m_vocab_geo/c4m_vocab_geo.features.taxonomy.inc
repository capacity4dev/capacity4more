<?php
/**
 * @file
 * c4m_vocab_geo.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function c4m_vocab_geo_taxonomy_default_vocabularies() {
  return array(
    'c4m_vocab_geo' => array(
      'name' => 'Regions & Countries',
      'machine_name' => 'c4m_vocab_geo',
      'description' => 'Geographical vocabulary: countries are grouped by their regions as defined by the EC.',
      'hierarchy' => 1,
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
