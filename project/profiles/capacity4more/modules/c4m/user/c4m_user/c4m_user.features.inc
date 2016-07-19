<?php
/**
 * @file
 * c4m_user.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_user_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "elysia_cron" && $api == "default_elysia_cron_rules") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_sort().
 */
function c4m_user_default_search_api_sort() {
  $items = array();
  $items['c4m_search_nodes__changed'] = entity_import('search_api_sort', '{
    "index_id" : "c4m_search_nodes",
    "field" : "changed",
    "name" : "Recently updated",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "c4m_search_nodes__changed",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "asc",
    "options" : { "field_name" : "Date changed" },
    "rdf_mapping" : []
  }');
  return $items;
}
