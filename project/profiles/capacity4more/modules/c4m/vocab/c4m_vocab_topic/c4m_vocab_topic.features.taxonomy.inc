<?php
/**
 * @file
 * c4m_vocab_topic.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function c4m_vocab_topic_taxonomy_default_vocabularies() {
  return array(
    'c4m_vocab_topic' => array(
      'name' => 'Topic',
      'machine_name' => 'c4m_vocab_topic',
      'description' => 'Topics and Sub-Topics',
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
