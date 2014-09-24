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
          "value" : "\\u003Ca href=\\u0022user\\/@{message:user:uid}\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E deleted @{message:c4m-activity-node:type} : @{message:c4m-activity-node:title}",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022user\\/@{message:user:uid}\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E deleted @{message:c4m-activity-node:type} : @{message:c4m-activity-node:title}\\u003C\\/p\\u003E\\n"
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
      "token options" : { "clear" : 1 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Ca href=\\u0022user\\/[message:user:uid]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E created @{message:c4m-activity-node:type}: \\u003Ca href=\\u0022node\\/[message:c4m-activity-node:nid]\\u0022\\u003E[message:c4m-activity-node:title]\\u003C\\/a\\u003E.",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022user\\/[message:user:uid]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E created @{message:c4m-activity-node:type}: \\u003Ca href=\\u0022node\\/[message:c4m-activity-node:nid]\\u0022\\u003E[message:c4m-activity-node:title]\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\n"
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
      "token options" : { "clear" : 1 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Ca href=\\u0022user\\/[message:user:uid]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E updated @{message:c4m-activity-node:type}: \\u003Ca href=\\u0022node\\/[message:c4m-activity-node:nid]\\u0022\\u003E[message:c4m-activity-node:title]\\u003C\\/a\\u003E.",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022user\\/[message:user:uid]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E updated @{message:c4m-activity-node:type}: \\u003Ca href=\\u0022node\\/[message:c4m-activity-node:nid]\\u0022\\u003E[message:c4m-activity-node:title]\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
