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
          "value" : "\\u003Ch2\\u003E\\u003Ca href=\\u0022[message:field-comment:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\u003C\\/h2\\u003E\\r\\n\\u003Cdiv class=\\u0022activity-stream--operator\\u0022\\u003E!icon [message:user:url-with-name] commented on @node_type | !date\\u003C\\/div\\u003E\\r\\n\\u003Cdiv class=\\u0022activity-stream--content\\u0022\\u003E!content\\u003C\\/div\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Ch2\\u003E\\u003Ca href=\\u0022[message:field-comment:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\u003C\\/h2\\u003E\\n\\u003Cdiv class=\\u0022activity-stream--operator\\u0022\\u003E!icon [message:user:url-with-name] commented on @node_type | !date\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022activity-stream--content\\u0022\\u003E!content\\u003C\\/div\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_insert__node__article'] = entity_import('message_type', '{
    "name" : "c4m_insert__node__article",
    "description" : "c4m Insert Node Article",
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
          "value" : "\\u003Ch2\\u003E\\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\u003C\\/h2\\u003E\\r\\n\\u003Cdiv class=\\u0022activity-stream--operator\\u0022\\u003E!icon [message:user:url-with-name] @operation | !date\\u003C\\/div\\u003E\\r\\n\\u003Cdiv class=\\u0022activity-stream--content\\u0022\\u003E!content\\u003C\\/div\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Ch2\\u003E\\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\u003C\\/h2\\u003E\\n\\u003Cdiv class=\\u0022activity-stream--operator\\u0022\\u003E!icon [message:user:url-with-name] @operation | !date\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022activity-stream--content\\u0022\\u003E!content\\u003C\\/div\\u003E\\n"
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
          "value" : "\\u003Ch2\\u003E\\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\u003C\\/h2\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022activity-stream--operator\\u0022\\u003E!icon [message:user:url-with-name] @operation | !date\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022activity-stream--content\\u0022\\u003E!content\\u003C\\/div\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Ch2\\u003E\\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\u003C\\/h2\\u003E\\n\\u003Cdiv class=\\u0022activity-stream--operator\\u0022\\u003E!icon [message:user:url-with-name] @operation | !date\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022activity-stream--content\\u0022\\u003E!content\\u003C\\/div\\u003E\\n"
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
          "value" : "\\u003Ch2\\u003E\\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\u003C\\/h2\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022activity-stream--operator\\u0022\\u003E!icon [message:user:url-with-name] @operation | !date\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022activity-stream--content\\u0022\\u003E!content\\u003C\\/div\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Ch2\\u003E\\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\u003C\\/h2\\u003E\\n\\u003Cdiv class=\\u0022activity-stream--operator\\u0022\\u003E!icon [message:user:url-with-name] @operation | !date\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022activity-stream--content\\u0022\\u003E!content\\u003C\\/div\\u003E\\n"
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
          "value" : "\\u003Ch2\\u003E\\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\u003C\\/h2\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022activity-stream--operator\\u0022\\u003E!icon [message:user:url-with-name] @operation | !date\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022activity-stream--content\\u0022\\u003E!content\\u003C\\/div\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Ch2\\u003E\\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\u003C\\/h2\\u003E\\n\\u003Cdiv class=\\u0022activity-stream--operator\\u0022\\u003E!icon [message:user:url-with-name] @operation | !date\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022activity-stream--content\\u0022\\u003E!content\\u003C\\/div\\u003E\\n"
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
          "value" : "\\u003Ch2\\u003E\\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\u003C\\/h2\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022activity-stream--operator\\u0022\\u003E!icon [message:user:url-with-name] @operation @photoalbum | !date\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022activity-stream--content\\u0022\\u003E!content\\u003C\\/div\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Ch2\\u003E\\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\u003C\\/h2\\u003E\\n\\u003Cdiv class=\\u0022activity-stream--operator\\u0022\\u003E!icon [message:user:url-with-name] @operation @photoalbum | !date\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022activity-stream--content\\u0022\\u003E!content\\u003C\\/div\\u003E\\n"
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
          "value" : "\\u003Ch2\\u003E\\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\u003C\\/h2\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022activity-stream--operator\\u0022\\u003E!icon [message:user:url-with-name] @operation | !date\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022activity-stream--content\\u0022\\u003E!content\\u003C\\/div\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Ch2\\u003E\\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\u003C\\/h2\\u003E\\n\\u003Cdiv class=\\u0022activity-stream--operator\\u0022\\u003E!icon [message:user:url-with-name] @operation | !date\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022activity-stream--content\\u0022\\u003E!content\\u003C\\/div\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_insert__node__share'] = entity_import('message_type', '{
    "name" : "c4m_insert__node__share",
    "description" : "c4m Insert Node Share",
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
          "value" : "\\u003Ch2\\u003E\\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\u003C\\/h2\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022activity-stream--operator\\u0022\\u003E!icon [message:user:url-with-name] @operation to the !group | !date\\r\\nOriginal group: !group_original\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022activity-stream--content\\u0022\\u003E!content\\u003C\\/div\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Ch2\\u003E\\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\u003C\\/h2\\u003E\\n\\u003Cdiv class=\\u0022activity-stream--operator\\u0022\\u003E!icon [message:user:url-with-name] @operation to the !group | !date\\u003Cbr \\/\\u003E\\nOriginal group: !group_original\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022activity-stream--content\\u0022\\u003E!content\\u003C\\/div\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_insert__node__wiki_page'] = entity_import('message_type', '{
    "name" : "c4m_insert__node__wiki_page",
    "description" : "c4m Insert Node Wiki Page",
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
          "value" : "\\u003Ch2\\u003E\\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\u003C\\/h2\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022activity-stream--operator\\u0022\\u003E!icon [message:user:url-with-name] @operation | !date\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022activity-stream--content\\u0022\\u003E!content\\u003C\\/div\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Ch2\\u003E\\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\u003C\\/h2\\u003E\\n\\u003Cdiv class=\\u0022activity-stream--operator\\u0022\\u003E!icon [message:user:url-with-name] @operation | !date\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022activity-stream--content\\u0022\\u003E!content\\u003C\\/div\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_unpublish_group'] = entity_import('message_type', '{
    "name" : "c4m_unpublish_group",
    "description" : "c4m unpublish group",
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
          "value" : "Your @group_node_type @group_node_title is no longer published",
          "format" : "mail",
          "safe_value" : "Your @group_node_type @group_node_title is no longer published"
        },
        {
          "value" : "\\u003Cp\\u003E\\r\\nDear @member_full_name,\\r\\n\\u003C\\/p\\u003E\\r\\n \\r\\n\\u003Cp\\u003E\\u003Cbr\\u003E\\r\\n\\u003Ca href=\\u0022!group_dashboard_url\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E reverted back to Draft status.\\r\\n\\u003C\\/p\\u003E\\r\\n \\r\\n\\u003Cp\\u003E\\r\\n[current-user:c4m_first_name] [current-user:c4m_last_name] updated the status of this @group_node_type from Unpublished to Draft.\\r\\n\\u003C\\/p\\u003E\\r\\n \\r\\n\\u003Cp\\u003E\\r\\nYou can consult \\u003Ca href=\\u0022[site:url]help-guidance\\/\\u0022\\u003Ethis help section\\u003C\\/a\\u003E to find out more about Group statuses and what they imply.\\r\\n\\u003C\\/p\\u003E\\r\\n \\r\\n\\u003Cp\\u003E\\u003Cbr\\u003E\\r\\nThe capacity4dev team\\r\\n\\u003C\\/p\\u003E",
          "format" : "mail",
          "safe_value" : "\\u003Cp\\u003E\\nDear @member_full_name,\\n\\u003C\\/p\\u003E\\n \\n\\u003Cp\\u003E\\u003Cbr\\u003E\\n\\u003Ca href=\\u0022!group_dashboard_url\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E reverted back to Draft status.\\n\\u003C\\/p\\u003E\\n \\n\\u003Cp\\u003E\\n[current-user:c4m_first_name] [current-user:c4m_last_name] updated the status of this @group_node_type from Unpublished to Draft.\\n\\u003C\\/p\\u003E\\n \\n\\u003Cp\\u003E\\nYou can consult \\u003Ca href=\\u0022[site:url]help-guidance\\/\\u0022\\u003Ethis help section\\u003C\\/a\\u003E to find out more about Group statuses and what they imply.\\n\\u003C\\/p\\u003E\\n \\n\\u003Cp\\u003E\\u003Cbr\\u003E\\nThe capacity4dev team\\n\\u003C\\/p\\u003E"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_welcome_to_group'] = entity_import('message_type', '{
    "name" : "c4m_welcome_to_group",
    "description" : "c4m Welcome to Group",
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
          "value" : "\\u003Cp\\u003EWelcome to @group_node_title\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n",
          "format" : "default_html",
          "safe_value" : "\\u003Cp\\u003EWelcome to @group_node_title\\u00a0\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EDear @member_full_name,\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cbr \\/\\u003E\\r\\nThank you for joining \\u003Cstrong\\u003E\\u003Ca href=\\u0022!group_dashboard_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E\\u003C\\/strong\\u003E at [site:name].\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E@group_welcome_message\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cbr \\/\\u003E\\r\\n\\u003Ca href=\\u0022!go_public_profile_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@go_full_name\\u003C\\/a\\u003E,\\u003Cbr \\/\\u003E\\r\\n@group_node_type Administrator - @group_node_title\\u003C\\/p\\u003E\\r\\n",
          "format" : "default_html",
          "safe_value" : "\\u003Cp\\u003EDear @member_full_name,\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\nThank you for joining \\u003Cstrong\\u003E\\u003Ca href=\\u0022!group_dashboard_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E\\u003C\\/strong\\u003E at [site:name].\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u00a0\\u003C\\/p\\u003E\\n\\u003Cp\\u003E@group_welcome_message\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\n\\u003Ca href=\\u0022!go_public_profile_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@go_full_name\\u003C\\/a\\u003E,\\u003Cbr \\/\\u003E\\n@group_node_type Administrator - @group_node_title\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
