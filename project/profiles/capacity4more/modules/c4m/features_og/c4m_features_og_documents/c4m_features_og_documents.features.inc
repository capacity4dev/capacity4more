<?php
/**
 * @file
 * c4m_features_og_documents.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_features_og_documents_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function c4m_features_og_documents_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_autocomplete_search().
 */
function c4m_features_og_documents_default_search_api_autocomplete_search() {
  $items = array();
  $items['search_api_views_c4m_overview_og_documents'] = entity_import('search_api_autocomplete_search', '{
    "machine_name" : "search_api_views_c4m_overview_og_documents",
    "name" : "Overview - OG - Documents",
    "index_id" : "c4m_search_nodes",
    "suggester_id" : "",
    "type" : "search_api_views",
    "enabled" : "1",
    "options" : { "result count" : true, "fields" : [] },
    "rdf_mapping" : []
  }');
  return $items;
}
