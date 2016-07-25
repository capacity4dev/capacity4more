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
  $items['c4m_log_group_admin_demoted'] = entity_import('message_type', '{
    "name" : "c4m_log_group_admin_demoted",
    "description" : "c4m Log Group Admin Demoted",
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
          "value" : "\\u003Cpre\\u003E\\r\\n@group_node_type @group_node_title (id: @group_node_id): Administrator @user_full_name (id: @user_id) was demoted to regular member status by @event_user_full_name] (id: event_user_id).\\u003C\\/pre\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cpre\\u003E\\n@group_node_type @group_node_title (id: @group_node_id): Administrator @user_full_name (id: @user_id) was demoted to regular member status by @event_user_full_name] (id: event_user_id).\\u003C\\/pre\\u003E"
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
