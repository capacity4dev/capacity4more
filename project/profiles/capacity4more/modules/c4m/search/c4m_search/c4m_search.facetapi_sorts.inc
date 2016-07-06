<?php

/**
 * @file
 * Add the option to sort facet terms based on the taxonomy weight.
 *
 * Improved version of the facetapi_taxonomy_sort module.
 *
 * @see https://drupal.org/project/facetapi_taxonomy_sort
 */

/**
 * Tests whether a field is a term reference field.
 *
 * @param array $facet
 *   The facet definition as returned by facetapi_facet_load().
 *
 * @return bool
 *   TRUE if the field is a term reference field.
 */
function c4m_search_is_term_reference_field(array $facet) {
  // Check by field type.
  $field_types = array(
    'taxonomy_term',
  );
  if (isset($facet['field type']) && in_array($facet['field type'], $field_types)) {
    return TRUE;
  }

  // Check by field info field type.
  $field_info_types = array(
    'taxonomy_term_reference',
  );
  if ($facet['field api name']) {
    $field_info = field_info_field($facet['field api name']);
    if ($field_info && in_array($field_info['type'], $field_info_types)) {
      return TRUE;
    }
  }

  return FALSE;
}

/**
 * Implements hook_facetapi_facet_info_alter().
 *
 * Adds the sort by taxonomy weights to the alter callbacks.
 */
function c4m_search_facetapi_facet_info_alter(array &$facet_info, array $searcher_info) {
  foreach ($facet_info as $name => $facet) {
    // Only act on taxonomy term reference fields.
    if (c4m_search_is_term_reference_field($facet)) {
      $facet_info[$name]['alter callbacks'][] = 'c4m_search_add_taxonomy_weights';
    }
  }
}

/**
 * Alter callback that adds taxonomy weights to render array.
 */
function c4m_search_add_taxonomy_weights(array &$build, FacetapiAdapter $adapter) {
  foreach (taxonomy_term_load_multiple(array_keys($build)) as $tid => $term) {
    $build[$tid]['#taxonomy_weight'] = $term->weight;
  }
}

/**
 * Implements hook_facetapi_sort_info().
 *
 * Adds the sort by term weight option.
 */
function c4m_search_facetapi_sort_info() {
  $sorts = array();

  $sorts['taxonomy_weight'] = array(
    'label' => t('Taxonomy weight'),
    'callback' => 'c4m_search_sort_taxonomy',
    'description' => t('Sort by the taxonomy term weight.'),
    'requirements' => array('c4m_search_is_taxonomy_facet' => TRUE),
    'weight' => -40,
  );

  return $sorts;
}

/**
 * Checks whether the facet indexes taxonomy terms.
 *
 * @param string $realm
 *   The realm definition as returned by facetapi_realm_load().
 * @param array $facet
 *   The facet definition as returned by facetapi_facet_load().
 * @param bool $option
 *   If TRUE, the the requirements will pass if the facet indexes taxonomy
 *   terms. If FALSE, the facet must NOT index taxonomy terms in order to pass
 *   the requirements.
 *
 * @return bool
 *   TRUE if the hierarchical status matches $option, FALSE otherwise.
 */
function c4m_search_is_taxonomy_facet($realm, array $facet, $option) {
  $is_taxonomy_facet = c4m_search_is_term_reference_field($facet);
  return ($option) ? $is_taxonomy_facet : !$is_taxonomy_facet;
}

/**
 * Sorts by taxonomy weight.
 */
function c4m_search_sort_taxonomy(array $a, array $b) {
  $a_count = (isset($a['#taxonomy_weight'])) ? $a['#taxonomy_weight'] : 0;
  $b_count = (isset($b['#taxonomy_weight'])) ? $b['#taxonomy_weight'] : 0;
  if ($a_count == $b_count) {
    return 0;
  }
  return ($a_count < $b_count) ? -1 : 1;
}
