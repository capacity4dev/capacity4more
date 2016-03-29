<?php
/**
 * @file
 * c4m_search_nodes.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_search_nodes_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function c4m_search_nodes_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_autocomplete_search().
 */
function c4m_search_nodes_default_search_api_autocomplete_search() {
  $items = array();
  $items['search_api_views_c4m_search_nodes'] = entity_import('search_api_autocomplete_search', '{
    "machine_name" : "search_api_views_c4m_search_nodes",
    "name" : "Search Content",
    "index_id" : "c4m_search_nodes",
    "suggester_id" : "server",
    "type" : "search_api_views",
    "enabled" : "1",
    "options" : {
      "min_length" : "1",
      "results" : 1,
      "custom" : { "display" : "page" },
      "submit_button_selector" : ":submit",
      "autosubmit" : 1,
      "suggester_configuration" : []
    },
    "rdf_mapping" : []
  }');
  return $items;
}
