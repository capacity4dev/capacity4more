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
          "value" : "\\u003Cdiv class=\\u0022row-header\\u0022\\u003E[message:user:url-with-name] commented on a @node_type \\u003Cspan class=\\u0022separator\\u0022\\u003E|\\u003C\\/span\\u003E@date\\u003C\\/div\\u003E\\u003Cdiv class=\\u0022row message-group\\u0022\\u003E!group_info\\u003C\\/div\\u003E\\u003Cdiv class=\\u0022row message-title\\u0022\\u003E\\u003Ca href=\\u0022[message:field-comment:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\u003C\\/div\\u003E\\u003Cdiv class=\\u0022row message-content\\u0022\\u003E!content\\u003C\\/div\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cdiv class=\\u0022row-header\\u0022\\u003E[message:user:url-with-name] commented on a @node_type \\u003Cspan class=\\u0022separator\\u0022\\u003E|\\u003C\\/span\\u003E@date\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022row message-group\\u0022\\u003E!group_info\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022row message-title\\u0022\\u003E\\u003Ca href=\\u0022[message:field-comment:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022row message-content\\u0022\\u003E!content\\u003C\\/div\\u003E\\n"
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
          "value" : "\\u003Cdiv class=\\u0022row-header\\u0022\\u003E[message:user:url-with-name] @operation Article \\u003Cspan class=\\u0022separator\\u0022\\u003E|\\u003C\\/span\\u003E @date\\u003C\\/div\\u003E\\r\\n\\u003Cdiv class=\\u0022row message-content\\u0022\\u003E!content\\u003C\\/div\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cdiv class=\\u0022row-header\\u0022\\u003E[message:user:url-with-name] @operation Article \\u003Cspan class=\\u0022separator\\u0022\\u003E|\\u003C\\/span\\u003E @date\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022row message-content\\u0022\\u003E!content\\u003C\\/div\\u003E\\n"
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
          "value" : "\\u003Cdiv class=\\u0022row-header\\u0022\\u003E[message:user:url-with-name] @type \\u003Cspan class=\\u0022separator\\u0022\\u003E|\\u003C\\/span\\u003E @date\\u003C\\/div\\u003E\\u003Cdiv class=\\u0022row message-group\\u0022\\u003E!group_info\\u003C\\/div\\u003E\\r\\n\\u003Cdiv class=\\u0022row message-content\\u0022\\u003E!content\\u003C\\/div\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cdiv class=\\u0022row-header\\u0022\\u003E[message:user:url-with-name] @type \\u003Cspan class=\\u0022separator\\u0022\\u003E|\\u003C\\/span\\u003E @date\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022row message-group\\u0022\\u003E!group_info\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022row message-content\\u0022\\u003E!content\\u003C\\/div\\u003E\\n"
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
          "value" : "\\u003Cdiv class=\\u0022row-header\\u0022\\u003E[message:user:url-with-name] @operation Document \\u003Cspan class=\\u0022separator\\u0022\\u003E|\\u003C\\/span\\u003E @date\\u003C\\/div\\u003E\\u003Cdiv class=\\u0022row message-group\\u0022\\u003E!group_info\\u003C\\/div\\u003E\\r\\n\\u003Cdiv class=\\u0022row message-content\\u0022\\u003E!content\\u003C\\/div\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cdiv class=\\u0022row-header\\u0022\\u003E[message:user:url-with-name] @operation Document \\u003Cspan class=\\u0022separator\\u0022\\u003E|\\u003C\\/span\\u003E @date\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022row message-group\\u0022\\u003E!group_info\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022row message-content\\u0022\\u003E!content\\u003C\\/div\\u003E\\n"
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
          "value" : "\\u003Cdiv class=\\u0022row-header\\u0022\\u003E[message:user:url-with-name] @operation Event \\u003Cspan class=\\u0022separator\\u0022\\u003E|\\u003C\\/span\\u003E @date\\u003C\\/div\\u003E\\u003Cdiv class=\\u0022row message-group\\u0022\\u003E!group_info\\u003C\\/div\\u003E\\r\\n\\u003Cdiv class=\\u0022row message-content\\u0022\\u003E!content\\u003C\\/div\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cdiv class=\\u0022row-header\\u0022\\u003E[message:user:url-with-name] @operation Event \\u003Cspan class=\\u0022separator\\u0022\\u003E|\\u003C\\/span\\u003E @date\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022row message-group\\u0022\\u003E!group_info\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022row message-content\\u0022\\u003E!content\\u003C\\/div\\u003E\\n"
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
          "value" : "\\u003Cdiv class=\\u0022row-header\\u0022\\u003E[message:user:url-with-name] @operation Photo \\u003Cspan class=\\u0022separator\\u0022\\u003E|\\u003C\\/span\\u003E @date\\u003C\\/div\\u003E\\u003Cdiv class=\\u0022row message-group\\u0022\\u003E!group_info\\u003C\\/div\\u003E\\r\\n\\u003Cdiv class=\\u0022row message-content\\u0022\\u003E!content\\u003C\\/div\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cdiv class=\\u0022row-header\\u0022\\u003E[message:user:url-with-name] @operation Photo \\u003Cspan class=\\u0022separator\\u0022\\u003E|\\u003C\\/span\\u003E @date\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022row message-group\\u0022\\u003E!group_info\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022row message-content\\u0022\\u003E!content\\u003C\\/div\\u003E\\n"
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
          "value" : "\\u003Cdiv class=\\u0022row-header\\u0022\\u003E[message:user:url-with-name] @operation Photo album \\u003Cspan class=\\u0022separator\\u0022\\u003E|\\u003C\\/span\\u003E @date\\u003C\\/div\\u003E\\u003Cdiv class=\\u0022row message-group\\u0022\\u003E!group_info\\u003C\\/div\\u003E\\r\\n\\u003Cdiv class=\\u0022row message-content\\u0022\\u003E!content\\u003C\\/div\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cdiv class=\\u0022row-header\\u0022\\u003E[message:user:url-with-name] @operation Photo album \\u003Cspan class=\\u0022separator\\u0022\\u003E|\\u003C\\/span\\u003E @date\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022row message-group\\u0022\\u003E!group_info\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022row message-content\\u0022\\u003E!content\\u003C\\/div\\u003E\\n"
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
          "value" : "\\u003Cdiv class=\\u0022row-header\\u0022\\u003E[message:user:url-with-name] @operation Wiki page \\u003Cspan class=\\u0022separator\\u0022\\u003E|\\u003C\\/span\\u003E @date\\u003C\\/div\\u003E\\u003Cdiv class=\\u0022row message-group\\u0022\\u003E!group_info\\u003C\\/div\\u003E\\r\\n\\u003Cdiv class=\\u0022row message-content\\u0022\\u003E!content\\u003C\\/div\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cdiv class=\\u0022row-header\\u0022\\u003E[message:user:url-with-name] @operation Wiki page \\u003Cspan class=\\u0022separator\\u0022\\u003E|\\u003C\\/span\\u003E @date\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022row message-group\\u0022\\u003E!group_info\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022row message-content\\u0022\\u003E!content\\u003C\\/div\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
