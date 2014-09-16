<?php
/**
 * @file
 * c4m_activity_comment.features.inc
 */

/**
 * Implements hook_default_message_type().
 */
function c4m_activity_comment_default_message_type() {
  $items = array();
  $items['c4m_activity_comment_delete'] = entity_import('message_type', '{
    "name" : "c4m_activity_comment_delete",
    "description" : "Comment : Delete",
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
          "value" : "Deleted a comment",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EDeleted a comment\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_activity_comment_insert'] = entity_import('message_type', '{
    "name" : "c4m_activity_comment_insert",
    "description" : "Comment : Create",
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
          "value" : "Added a comment",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EAdded a comment\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_activity_comment_update'] = entity_import('message_type', '{
    "name" : "c4m_activity_comment_update",
    "description" : "Comment : Update",
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
          "value" : "Edited a comment",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EEdited a comment\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
