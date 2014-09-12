<?php
/**
 * @file
 * c4m_activity_node.features.inc
 */

/**
 * Implements hook_default_message_type().
 */
function c4m_activity_node_default_message_type() {
  $items = array();
  $items['c4m_activity_node_delete'] = entity_import('message_type', '{
    "name" : "c4m_activity_node_delete",
    "description" : "Node : Delete",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "Deleted a [message:field-node:content-type:name]",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EDeleted a [message:field-node:content-type:name]\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_activity_node_insert'] = entity_import('message_type', '{
    "name" : "c4m_activity_node_insert",
    "description" : "Node : Create",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "Added a [message:field-node:content-type:name]",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EAdded a [message:field-node:content-type:name]\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_activity_node_update'] = entity_import('message_type', '{
    "name" : "c4m_activity_node_update",
    "description" : "Node : Update",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "Edited a [message:field-node:content-type:name]",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EEdited a [message:field-node:content-type:name]\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
