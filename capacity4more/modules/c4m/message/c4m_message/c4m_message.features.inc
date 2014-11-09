<?php
/**
 * @file
 * c4m_message.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_message_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function c4m_message_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_message_type().
 */
function c4m_message_default_message_type() {
  $items = array();
  $items['c4m_insert__comment'] = entity_import('message_type', '{
    "name" : "c4m_insert__comment",
    "description" : "c4m Insert Comment",
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
          "value" : "\\u003Cdiv class=\\u0022row message-header\\u0022\\u003E\\r\\n  \\u003Ca href=\\u0022@{message:user:url}\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E commented on the @node_type | @date\\r\\n\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022row message-title\\u0022\\u003E\\r\\n  \\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022row message-content\\u0022\\u003E\\r\\n  !content\\r\\n\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022row message-footer\\u0022\\u003E\\r\\n  !footer\\r\\n\\u003C\\/div\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cdiv class=\\u0022row message-header\\u0022\\u003E\\n  \\u003Ca href=\\u0022@{message:user:url}\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E commented on the @node_type | @date\\n\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022row message-title\\u0022\\u003E\\n  \\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\n\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022row message-content\\u0022\\u003E\\n  !content\\n\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022row message-footer\\u0022\\u003E\\n  !footer\\n\\u003C\\/div\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_insert__node__discussion'] = entity_import('message_type', '{
    "name" : "c4m_insert__node__discussion",
    "description" : "c4m Insert Node Discussion",
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
          "value" : "\\u003Cdiv class=\\u0022row message-header\\u0022\\u003E\\r\\n  \\u003Ca href=\\u0022@{message:user:url}\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E @type | @date\\r\\n\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022row message-title\\u0022\\u003E\\r\\n  \\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022row message-content\\u0022\\u003E\\r\\n  !content\\r\\n\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022row message-footer\\u0022\\u003E\\r\\n  !footer\\r\\n\\u003C\\/div\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cdiv class=\\u0022row message-header\\u0022\\u003E\\n  \\u003Ca href=\\u0022@{message:user:url}\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E @type | @date\\n\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022row message-title\\u0022\\u003E\\n  \\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\n\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022row message-content\\u0022\\u003E\\n  !content\\n\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022row message-footer\\u0022\\u003E\\n  !footer\\n\\u003C\\/div\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_insert__node__document'] = entity_import('message_type', '{
    "name" : "c4m_insert__node__document",
    "description" : "c4m Insert Node Document",
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
          "value" : "\\u003Cdiv class=\\u0022row message-header\\u0022\\u003E\\r\\n  \\u003Ca href=\\u0022@{message:user:url}\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E uploaded a new Document | @date\\r\\n\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022row message-title\\u0022\\u003E\\r\\n  \\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022row message-content\\u0022\\u003E\\r\\n  !content\\r\\n\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022row message-footer\\u0022\\u003E\\r\\n  !footer\\r\\n\\u003C\\/div\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cdiv class=\\u0022row message-header\\u0022\\u003E\\n  \\u003Ca href=\\u0022@{message:user:url}\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E uploaded a new Document | @date\\n\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022row message-title\\u0022\\u003E\\n  \\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\n\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022row message-content\\u0022\\u003E\\n  !content\\n\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022row message-footer\\u0022\\u003E\\n  !footer\\n\\u003C\\/div\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_insert__node__event'] = entity_import('message_type', '{
    "name" : "c4m_insert__node__event",
    "description" : "c4m Insert Node Event",
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
          "value" : "\\u003Cdiv class=\\u0022row message-header\\u0022\\u003E\\r\\n  \\u003Ca href=\\u0022@{message:user:url}\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E added a new Event | @date\\r\\n\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022row message-title\\u0022\\u003E\\r\\n  \\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022row message-content\\u0022\\u003E\\r\\n  !content\\r\\n\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022row message-footer\\u0022\\u003E\\r\\n  !footer\\r\\n\\u003C\\/div\\u003E",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022url}\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E added a new Event | @date\\u003C\\/p\\u003E\\n\\u003Cp\\u003E  \\u003Ca href=\\u0022url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n\\u003Cp\\u003E  !content\\u003C\\/p\\u003E\\n\\u003Cp\\u003E  !footer\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_insert__node__photo'] = entity_import('message_type', '{
    "name" : "c4m_insert__node__photo",
    "description" : "c4m Insert Node Photo",
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
          "value" : "\\u003Cdiv class=\\u0022row message-header\\u0022\\u003E\\r\\n  \\u003Ca href=\\u0022@{message:user:url}\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E added a new Photo | @date\\r\\n\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022row message-title\\u0022\\u003E\\r\\n  \\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022row message-content\\u0022\\u003E\\r\\n  !content\\r\\n\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022row message-footer\\u0022\\u003E\\r\\n  !footer\\r\\n\\u003C\\/div\\u003E",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022url}\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E added a new Photo | @date\\u003C\\/p\\u003E\\n\\u003Cp\\u003E  \\u003Ca href=\\u0022url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n\\u003Cp\\u003E  !content\\u003C\\/p\\u003E\\n\\u003Cp\\u003E  !footer\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_insert__node__photoalbum'] = entity_import('message_type', '{
    "name" : "c4m_insert__node__photoalbum",
    "description" : "c4m Insert Node Photo Album",
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
          "value" : "\\u003Cdiv class=\\u0022row message-header\\u0022\\u003E\\r\\n  \\u003Ca href=\\u0022@{message:user:url}\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E added a new Photo album | @date\\r\\n\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022row message-title\\u0022\\u003E\\r\\n  \\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022row message-content\\u0022\\u003E\\r\\n  !content\\r\\n\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022row message-footer\\u0022\\u003E\\r\\n  !footer\\r\\n\\u003C\\/div\\u003E",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022url}\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E added a new Photo album | @date\\u003C\\/p\\u003E\\n\\u003Cp\\u003E  \\u003Ca href=\\u0022url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n\\u003Cp\\u003E  !content\\u003C\\/p\\u003E\\n\\u003Cp\\u003E  !footer\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
