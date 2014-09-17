<?php
/**
 * @file
 * c4m_activity_og.features.inc
 */

/**
 * Implements hook_default_message_type().
 */
function c4m_activity_og_default_message_type() {
  $items = array();
  $items['c4m_activity_og_request'] = entity_import('message_type', '{
    "name" : "c4m_activity_og_request",
    "description" : "Organic Groups : Requested membership",
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
          "value" : "New membership request for [message:c4m-activity-group:content-type:name]",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003ENew membership request for [message:c4m-activity-group:content-type:name]\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_activity_og_join'] = entity_import('message_type', '{
    "name" : "c4m_activity_og_join",
    "description" : "Organic Groups : Joined group",
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
          "value" : "Joined group [message:c4m-activity-group:content-type:name]",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EJoined group [message:c4m-activity-group:content-type:name]\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_activity_og_leave'] = entity_import('message_type', '{
    "name" : "c4m_activity_og_leave",
    "description" : "Organic Groups : Left group",
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
          "value" : "Left group [message:c4m-activity-group:content-type:name]",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003ELeft group [message:c4m-activity-group:content-type:name]\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');


  return $items;
}
