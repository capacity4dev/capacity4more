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
  $items['c4m_group_access_change'] = entity_import('message_type', '{
    "name" : "c4m_group_access_change",
    "description" : "c4m Group Access Change",
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
          "value" : "\\u003Cp\\u003EYour @group_node_type\\u0026nbsp;@group_node_title\\u0026nbsp;has new permissions!\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n",
          "format" : "default_html",
          "safe_value" : "\\u003Cp\\u003EYour @group_node_type\\u00a0@group_node_title\\u00a0has new permissions!\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u00a0\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EDear @group_admin_full_name,\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E@event_user_full_name\\u0026nbsp;updated the permissions of this @group_node_type to @group_permissions.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EYou can consult \\u003Ca href=\\u0022url]help-guidance\\u0022 rel=\\u0022nofollow\\u0022\\u003Ethis help section\\u003C\\/a\\u003E to find out more about Group permissions and what they imply.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cbr \\/\\u003E\\r\\nThe capacity4dev team\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EDear @group_admin_full_name,\\u003C\\/p\\u003E\\n\\u003Cp\\u003E@event_user_full_name\\u0026nbsp;updated the permissions of this @group_node_type to @group_permissions.\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou can consult \\u003Ca href=\\u0022url]help-guidance\\u0022 rel=\\u0022nofollow\\u0022\\u003Ethis help section\\u003C\\/a\\u003E to find out more about Group permissions and what they imply.\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\nThe capacity4dev team\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_group_admin_demoted'] = entity_import('message_type', '{
    "name" : "c4m_group_admin_demoted",
    "description" : "c4m Group Admin Demoted",
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
          "value" : "\\u003Cp\\u003EYou are no longer administrator for @group_node_type @group_node_title\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n",
          "format" : "default_html",
          "safe_value" : "\\u003Cp\\u003EYou are no longer administrator for @group_node_type @group_node_title\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u00a0\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u00a0\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EDear @member_full_name,\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\r\\nYou are no longer administrator for the @group_node_type \\u003Ca href=\\u0022!group_dashboard_url\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E\\r\\n\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003E\\r\\n[current-user:c4m_first_name] [current-user:c4m_last_name]\\r\\n\\u003Cbr\\u003E\\r\\n@group_node_type Administrator, @group_node_title\\r\\n\\u003C\\/p\\u003E",
          "format" : "default_html",
          "safe_value" : "\\u003Cp\\u003EDear @member_full_name,\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\nYou are no longer administrator for the @group_node_type \\u003Ca href=\\u0022!group_dashboard_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E\\n\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\n[current-user:c4m_first_name] [current-user:c4m_last_name]\\u003Cbr \\/\\u003E\\u003Cbr \\/\\u003E\\u003Cbr \\/\\u003E\\n@group_node_type Administrator, @group_node_title\\n\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_group_archived'] = entity_import('message_type', '{
    "name" : "c4m_group_archived",
    "description" : "c4m Group Archived",
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
          "value" : "\\u003Cp\\u003EYour @group_node_type\\u0026nbsp;@group_node_title\\u0026nbsp;is archived\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n",
          "format" : "default_html",
          "safe_value" : "\\u003Cp\\u003EYour @group_node_type\\u00a0@group_node_title\\u00a0is archived\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u00a0\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u00a0\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EDear @group_admin_full_name,\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cbr \\/\\u003E\\r\\n\\u003Ca href=\\u0022!group_dashboard_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E is now archived.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E@event_user_full_name updated the status of this @group_node_type from @group_former_status to Archived.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EYou can consult \\u003Ca href=\\u0022!help_section_url\\u0022 rel=\\u0022nofollow\\u0022\\u003Ethis help section\\u003C\\/a\\u003E to find out more about @group_node_type statuses and what they imply.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cbr \\/\\u003E\\r\\nThe capacity4dev team\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EDear @group_admin_full_name,\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\n\\u003Ca href=\\u0022!group_dashboard_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E is now archived.\\u003C\\/p\\u003E\\n\\u003Cp\\u003E@event_user_full_name updated the status of this @group_node_type from @group_former_status to Archived.\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou can consult \\u003Ca href=\\u0022!help_section_url\\u0022 rel=\\u0022nofollow\\u0022\\u003Ethis help section\\u003C\\/a\\u003E to find out more about @group_node_type statuses and what they imply.\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\nThe capacity4dev team\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_group_hard_deleted'] = entity_import('message_type', '{
    "name" : "c4m_group_hard_deleted",
    "description" : "c4m Group Hard Deleted",
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
          "value" : "\\u003Cp\\u003EYour @group_node_type\\u0026nbsp;@group_node_title is\\u0026nbsp;permanently deleted\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n",
          "format" : "default_html",
          "safe_value" : "\\u003Cp\\u003EYour @group_node_type\\u00a0@group_node_title is\\u00a0permanently deleted\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u00a0\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u00a0\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EDear @group_admin_full_name,\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cbr \\/\\u003E\\r\\n\\u003Ca href=\\u0022!group_dashboard_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E has been permanently deleted.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E@event_user_full_name updated the status of this @group_node_type from @group_former_status to permanently Deleted.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EYou can consult \\u003Ca href=\\u0022url]help-guidance\\u0022 rel=\\u0022nofollow\\u0022\\u003Ethis help section\\u003C\\/a\\u003E to find out more about Group statuses and what they imply.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cbr \\/\\u003E\\r\\nThe capacity4dev team\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EDear @group_admin_full_name,\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\n\\u003Ca href=\\u0022!group_dashboard_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E has been permanently deleted.\\u003C\\/p\\u003E\\n\\u003Cp\\u003E@event_user_full_name updated the status of this @group_node_type from @group_former_status to permanently Deleted.\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou can consult \\u003Ca href=\\u0022url]help-guidance\\u0022 rel=\\u0022nofollow\\u0022\\u003Ethis help section\\u003C\\/a\\u003E to find out more about Group statuses and what they imply.\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\nThe capacity4dev team\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_group_published'] = entity_import('message_type', '{
    "name" : "c4m_group_published",
    "description" : "c4m Group Published",
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
          "value" : "\\u003Cp\\u003EYour @group_node_type\\u0026nbsp;@group_node_title\\u0026nbsp;is published\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n",
          "format" : "default_html",
          "safe_value" : "\\u003Cp\\u003EYour @group_node_type\\u00a0@group_node_title\\u00a0is published\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u00a0\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u00a0\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EDear @group_admin_full_name,\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cbr \\/\\u003E\\r\\nCongratulations!\\u0026nbsp;\\u003Ca href=\\u0022!group_dashboard_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E is now published.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E@event_user_full_name updated the status of this @group_node_type from Draft to Published.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EYou can consult \\u003Ca href=\\u0022!help_section_url\\u0022 rel=\\u0022nofollow\\u0022\\u003Ethis help section\\u003C\\/a\\u003E to find out more about @group_node_type statuses and what they imply.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cbr \\/\\u003E\\r\\nThe capacity4dev team\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EDear @group_admin_full_name,\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\nCongratulations!\\u0026nbsp;\\u003Ca href=\\u0022!group_dashboard_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E is now published.\\u003C\\/p\\u003E\\n\\u003Cp\\u003E@event_user_full_name updated the status of this @group_node_type from Draft to Published.\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou can consult \\u003Ca href=\\u0022!help_section_url\\u0022 rel=\\u0022nofollow\\u0022\\u003Ethis help section\\u003C\\/a\\u003E to find out more about @group_node_type statuses and what they imply.\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\nThe capacity4dev team\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_group_republished'] = entity_import('message_type', '{
    "name" : "c4m_group_republished",
    "description" : "c4m Group Republished",
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
          "value" : "\\u003Cp\\u003EYour @group_node_type\\u0026nbsp;@group_node_title\\u0026nbsp;is published once again\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n",
          "format" : "default_html",
          "safe_value" : "\\u003Cp\\u003EYour @group_node_type\\u00a0@group_node_title\\u00a0is published once again\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u00a0\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u00a0\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EDear @group_admin_full_name,\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cbr \\/\\u003E\\r\\n\\u003Ca href=\\u0022!group_dashboard_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E was published once again.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E@event_user_full_name\\u0026nbsp;updated the status of this @group_node_type from @group_former_status to Published.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EYou can consult \\u003Ca href=\\u0022!help_section_url\\u0022 rel=\\u0022nofollow\\u0022\\u003Ethis help section\\u003C\\/a\\u003E to find out more about @group_node_type statuses and what they imply.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cbr \\/\\u003E\\r\\nThe capacity4dev team\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EDear @group_admin_full_name,\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\n\\u003Ca href=\\u0022!group_dashboard_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E was published once again.\\u003C\\/p\\u003E\\n\\u003Cp\\u003E@event_user_full_name\\u0026nbsp;updated the status of this @group_node_type from @group_former_status to Published.\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou can consult \\u003Ca href=\\u0022!help_section_url\\u0022 rel=\\u0022nofollow\\u0022\\u003Ethis help section\\u003C\\/a\\u003E to find out more about @group_node_type statuses and what they imply.\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\nThe capacity4dev team\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_group_request_submitted'] = entity_import('message_type', '{
    "name" : "c4m_group_request_submitted",
    "description" : "c4m Group Request Submitted",
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
          "value" : "\\u003Cp\\u003ENew @group_node_type\\u0026nbsp;request\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n",
          "format" : "default_html",
          "safe_value" : "\\u003Cp\\u003ENew @group_node_type\\u00a0request\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u00a0\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u00a0\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EDear Administrator,\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cbr \\/\\u003E\\r\\n\\u003Ca href=\\u0022!event_user_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@event_user_full_name\\u003C\\/a\\u003E requested a new @group_node_type: \\u003Ca href=\\u0022!group_dashboard_url\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cbr \\/\\u003E\\r\\n\\u003Cstrong\\u003EReason\\u003C\\/strong\\u003E: \\u003Cem\\u003E@message_to_site_admins\\u003C\\/em\\u003E\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003ETo edit the status of this @group_node_type and add a rework message: \\u003Ca href=\\u0022!group_edit_status_url\\u0022\\u003Emanage this @group_node_type\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EDear Administrator,\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\n\\u003Ca href=\\u0022!event_user_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@event_user_full_name\\u003C\\/a\\u003E requested a new @group_node_type: \\u003Ca href=\\u0022!group_dashboard_url\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\n\\u003Cstrong\\u003EReason\\u003C\\/strong\\u003E: \\u003Cem\\u003E@message_to_site_admins\\u003C\\/em\\u003E\\u003C\\/p\\u003E\\n\\u003Cp\\u003ETo edit the status of this @group_node_type and add a rework message: \\u003Ca href=\\u0022!group_edit_status_url\\u0022\\u003Emanage this @group_node_type\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_group_requested'] = entity_import('message_type', '{
    "name" : "c4m_group_requested",
    "description" : "c4m Group Requested",
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
          "value" : "\\u003Cp\\u003EYour @group_node_type\\u0026nbsp;request on [site:name]\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n",
          "format" : "default_html",
          "safe_value" : "\\u003Cp\\u003EYour @group_node_type\\u00a0request on [site:name]\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u00a0\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u00a0\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EDear @group_owner_full_name,\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cbr \\/\\u003E\\r\\nThank you for requesting the creation of the following @group_node_type: @group_node_title at [site:name].\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EYour request is currently pending review by one of the site\\u0027s administrators and should be treated shortly.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EIf you have any questions, please feel free to \\u003Ca href=\\u0022mailto:capacity4dev@ec.europa.eu\\u0022\\u003Econtact us\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EThe [site:name] team\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EDear @group_owner_full_name,\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\nThank you for requesting the creation of the following @group_node_type: @group_node_title at [site:name].\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYour request is currently pending review by one of the site\\u0027s administrators and should be treated shortly.\\u003C\\/p\\u003E\\n\\u003Cp\\u003EIf you have any questions, please feel free to \\u003Ca href=\\u0022mailto:capacity4dev@ec.europa.eu\\u0022\\u003Econtact us\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\n\\u003Cp\\u003EThe [site:name] team\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_group_soft_deleted'] = entity_import('message_type', '{
    "name" : "c4m_group_soft_deleted",
    "description" : "c4m Group Soft Deleted",
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
          "value" : "\\u003Cp\\u003E@group_node_type\\u0026nbsp;@group_node_title was\\u0026nbsp;deleted\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n",
          "format" : "default_html",
          "safe_value" : "\\u003Cp\\u003E@group_node_type\\u00a0@group_node_title was\\u00a0deleted\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u00a0\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u00a0\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EDear administrator,\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cbr \\/\\u003E\\r\\n\\u003Ca href=\\u0022!group_dashboard_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E has been deleted.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E@event_user_full_name updated the status of this @group_node_type from @group_former_status to Deleted.\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EDear administrator,\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\n\\u003Ca href=\\u0022!group_dashboard_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E has been deleted.\\u003C\\/p\\u003E\\n\\u003Cp\\u003E@event_user_full_name updated the status of this @group_node_type from @group_former_status to Deleted.\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_group_unpublished'] = entity_import('message_type', '{
    "name" : "c4m_group_unpublished",
    "description" : "c4m Group Unpublished",
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
          "value" : "\\u003Cp\\u003EYour @group_node_type\\u0026nbsp;@group_node_title\\u0026nbsp;\\u0026nbsp;is no longer published\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n",
          "format" : "default_html",
          "safe_value" : "\\u003Cp\\u003EYour @group_node_type\\u00a0@group_node_title\\u00a0\\u00a0is no longer published\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u00a0\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u00a0\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EDear @group_admin_full_name,\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cbr \\/\\u003E\\r\\n\\u003Ca href=\\u0022!group_dashboard_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E\\u0026nbsp;reverted back to Draft status.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E@event_user_full_name\\u0026nbsp;updated the status of this @group_node_type from @group_former_status to Draft.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EYou can consult \\u003Ca href=\\u0022!help_section_url\\u0022 rel=\\u0022nofollow\\u0022\\u003Ethis help section\\u003C\\/a\\u003E to find out more about @group_node_type statuses and what they imply.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cbr \\/\\u003E\\r\\nThe capacity4dev team\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EDear @group_admin_full_name,\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\n\\u003Ca href=\\u0022!group_dashboard_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E\\u0026nbsp;reverted back to Draft status.\\u003C\\/p\\u003E\\n\\u003Cp\\u003E@event_user_full_name\\u0026nbsp;updated the status of this @group_node_type from @group_former_status to Draft.\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou can consult \\u003Ca href=\\u0022!help_section_url\\u0022 rel=\\u0022nofollow\\u0022\\u003Ethis help section\\u003C\\/a\\u003E to find out more about @group_node_type statuses and what they imply.\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\nThe capacity4dev team\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
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
  $items['c4m_insert__node__news'] = entity_import('message_type', '{
    "name" : "c4m_insert__node__news",
    "description" : "c4m Insert Node News",
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
          "value" : "\\u003Ch2\\u003E\\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\u003C\\/h2\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022activity-stream--operator\\u0022\\u003E!icon [message:user:url-with-name] @operation from the group: !group_original\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022activity-stream--content\\u0022\\u003E!content\\u003C\\/div\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Ch2\\u003E\\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\u003C\\/h2\\u003E\\n\\u003Cdiv class=\\u0022activity-stream--operator\\u0022\\u003E!icon [message:user:url-with-name] @operation from the group: !group_original\\u003C\\/div\\u003E\\n\\u003Cdiv class=\\u0022activity-stream--content\\u0022\\u003E!content\\u003C\\/div\\u003E\\n"
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
  $items['c4m_new_content_published'] = entity_import('message_type', '{
    "name" : "c4m_new_content_published",
    "description" : "c4m New Content Published",
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
          "value" : "\\u003Cp\\u003ENew @content_type_name from @group_node_title\\u003C\\/p\\u003E\\r\\n",
          "format" : "default_html",
          "safe_value" : "\\u003Cp\\u003ENew @content_type_name from @group_node_title\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EDear @user_full_name,\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Ca href=\\u0022!event_user_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@event_user_full_name\\u003C\\/a\\u003E added the following @content_type_name: \\u003Cstrong\\u003E\\u003Ca href=\\u0022!content_node_url\\u0022\\u003E@content_node_title\\u003C\\/a\\u003E\\u003C\\/strong\\u003E\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cem\\u003E@node_teaser_body \\u003C\\/em\\u003E\\u003Cbr \\/\\u003E\\r\\n\\u003Ca href=\\u0022!content_node_url\\u0022\\u003ERead more...\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EYou\\u0027re receiving this e-mail because you\\u0027re subscribed to \\u003Ca href=\\u0022!group_dashboard_url\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E\\u0026nbsp;- if you no longer wish to receive notifications from this @group_node_type, please \\u003Ca href=\\u0022!unsubscribe_group_url\\u0022\\u003Eunsubscribe.\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EDear @user_full_name,\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u003Ca href=\\u0022!event_user_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@event_user_full_name\\u003C\\/a\\u003E added the following @content_type_name: \\u003Cstrong\\u003E\\u003Ca href=\\u0022!content_node_url\\u0022\\u003E@content_node_title\\u003C\\/a\\u003E\\u003C\\/strong\\u003E\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u003Cem\\u003E@node_teaser_body \\u003C\\/em\\u003E\\u003Cbr \\/\\u003E\\n\\u003Ca href=\\u0022!content_node_url\\u0022\\u003ERead more...\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou\\u0027re receiving this e-mail because you\\u0027re subscribed to \\u003Ca href=\\u0022!group_dashboard_url\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E\\u0026nbsp;- if you no longer wish to receive notifications from this @group_node_type, please \\u003Ca href=\\u0022!unsubscribe_group_url\\u0022\\u003Eunsubscribe.\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_new_member_joined'] = entity_import('message_type', '{
    "name" : "c4m_new_member_joined",
    "description" : "c4m New Member Joined",
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
          "value" : "\\u003Cp\\u003EA new member joined\\u0026nbsp;@group_node_title\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n",
          "format" : "default_html",
          "safe_value" : "\\u003Cp\\u003EA new member joined\\u00a0@group_node_title\\u00a0\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EDear @group_admin_full_name,\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cbr \\/\\u003E\\r\\nA new member\\u0026nbsp;joined\\u0026nbsp;\\u003Ca href=\\u0022!group_dashboard_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E at [site:name].\\u003Cbr \\/\\u003E\\r\\nPlease find their details below:\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cstrong\\u003E@new_member_full_name\\u003C\\/strong\\u003E\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E@new_member_organisation, @new_member_organisation_type\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EBased in @new_member_country\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EExpertise: @new_member_expertise\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EAbout: @new_member_about_me\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EView this member\\u0027s \\u003Ca href=\\u0022!new_member_public_profile_url\\u0022 rel=\\u0022nofollow\\u0022\\u003Eprofile\\u003C\\/a\\u003E at [site:name].\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EDear @group_admin_full_name,\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\nA new member\\u0026nbsp;joined\\u0026nbsp;\\u003Ca href=\\u0022!group_dashboard_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E at [site:name].\\u003Cbr \\/\\u003E\\nPlease find their details below:\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u003Cstrong\\u003E@new_member_full_name\\u003C\\/strong\\u003E\\u003C\\/p\\u003E\\n\\u003Cp\\u003E@new_member_organisation, @new_member_organisation_type\\u003C\\/p\\u003E\\n\\u003Cp\\u003EBased in @new_member_country\\u003C\\/p\\u003E\\n\\u003Cp\\u003EExpertise: @new_member_expertise\\u003C\\/p\\u003E\\n\\u003Cp\\u003EAbout: @new_member_about_me\\u003C\\/p\\u003E\\n\\u003Cp\\u003EView this member\\u0027s \\u003Ca href=\\u0022!new_member_public_profile_url\\u0022 rel=\\u0022nofollow\\u0022\\u003Eprofile\\u003C\\/a\\u003E at [site:name].\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_new_membership_request'] = entity_import('message_type', '{
    "name" : "c4m_new_membership_request",
    "description" : "c4m New Membership Request",
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
          "value" : "\\u003Cp\\u003EA new member requested to join @group_node_title\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n",
          "format" : "default_html",
          "safe_value" : "\\u003Cp\\u003EA new member requested to join @group_node_title\\u00a0\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EDear @group_admin_full_name,\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cbr \\/\\u003E\\r\\nA new member requested to join \\u003Ca href=\\u0022!group_dashboard_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E at [site:name].\\u003Cbr \\/\\u003E\\r\\n\\u003Ca href=\\u0022!group_pending_member_url\\u0022 rel=\\u0022nofollow\\u0022\\u003EManage this request\\u003C\\/a\\u003E\\u003Cbr \\/\\u003E\\r\\nPlease find their details below:\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cstrong\\u003E@new_member_full_name\\u003C\\/strong\\u003E\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E@new_member_organisation, @new_member_organisation_type\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EBased in @new_member_country\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EExpertise: @new_member_expertise\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EAbout: @new_member_about_me\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EMessage from this member:\\u003Cbr \\/\\u003E\\r\\n\\u003Cem\\u003E@new_member_request_message\\u003C\\/em\\u003E\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EView this member\\u0027s \\u003Ca href=\\u0022!new_member_public_profile_url\\u0022 rel=\\u0022nofollow\\u0022\\u003Eprofile\\u003C\\/a\\u003E at [site:name].\\u003C\\/p\\u003E\\r\\n",
          "format" : "default_html",
          "safe_value" : "\\u003Cp\\u003EDear @group_admin_full_name,\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\nA new member requested to join \\u003Ca href=\\u0022!group_dashboard_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E at [site:name].\\u003Cbr \\/\\u003E\\u003Ca href=\\u0022!group_pending_member_url\\u0022 rel=\\u0022nofollow\\u0022\\u003EManage this request\\u003C\\/a\\u003E\\u003Cbr \\/\\u003E\\nPlease find their details below:\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u00a0\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u003Cstrong\\u003E@new_member_full_name\\u003C\\/strong\\u003E\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u00a0\\u003C\\/p\\u003E\\n\\u003Cp\\u003E@new_member_organisation, @new_member_organisation_type\\u003C\\/p\\u003E\\n\\u003Cp\\u003EBased in @new_member_country\\u003C\\/p\\u003E\\n\\u003Cp\\u003EExpertise: @new_member_expertise\\u003C\\/p\\u003E\\n\\u003Cp\\u003EAbout: @new_member_about_me\\u003C\\/p\\u003E\\n\\u003Cp\\u003EMessage from this member:\\u003Cbr \\/\\u003E\\u003Cem\\u003E@new_member_request_message\\u003C\\/em\\u003E\\u003C\\/p\\u003E\\n\\u003Cp\\u003EView this member\\u0027s \\u003Ca href=\\u0022!new_member_public_profile_url\\u0022 rel=\\u0022nofollow\\u0022\\u003Eprofile\\u003C\\/a\\u003E at [site:name].\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_notify_admins_membership_approved'] = entity_import('message_type', '{
    "name" : "c4m_notify_admins_membership_approved",
    "description" : "c4m Notify Admins Membership Approved",
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
          "value" : "\\u003Cp\\u003E@group_node_title:\\u0026nbsp;a new member was accepted\\u003C\\/p\\u003E\\r\\n",
          "format" : "default_html",
          "safe_value" : "\\u003Cp\\u003E@group_node_title:\\u00a0a new member was accepted\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EDear @group_admin_full_name,\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Ca href=\\u0022!event_user_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@event_user_full_name\\u003C\\/a\\u003E just approved the following user\\u0027s membership request to join our @group_node_type \\u003Cstrong\\u003E\\u003Ca href=\\u0022!group_dashboard_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E\\u003C\\/strong\\u003E at [site:name]:\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cstrong\\u003E@related_user_full_name\\u003C\\/strong\\u003E\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E@related_user_organisation, (@related_user_organisation_type)\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EBased in @related_user_country\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EExpertise: @related_user_expertise\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EView this member\\u0027s \\u003Ca href=\\u0022!related_user_public_profile_url\\u0022 rel=\\u0022nofollow\\u0022\\u003Eprofile\\u003C\\/a\\u003E at [site:name].\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EDear @group_admin_full_name,\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u003Ca href=\\u0022!event_user_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@event_user_full_name\\u003C\\/a\\u003E just approved the following user\\u0027s membership request to join our @group_node_type \\u003Cstrong\\u003E\\u003Ca href=\\u0022!group_dashboard_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E\\u003C\\/strong\\u003E at [site:name]:\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u003Cstrong\\u003E@related_user_full_name\\u003C\\/strong\\u003E\\u003C\\/p\\u003E\\n\\u003Cp\\u003E@related_user_organisation, (@related_user_organisation_type)\\u003C\\/p\\u003E\\n\\u003Cp\\u003EBased in @related_user_country\\u003C\\/p\\u003E\\n\\u003Cp\\u003EExpertise: @related_user_expertise\\u003C\\/p\\u003E\\n\\u003Cp\\u003EView this member\\u0027s \\u003Ca href=\\u0022!related_user_public_profile_url\\u0022 rel=\\u0022nofollow\\u0022\\u003Eprofile\\u003C\\/a\\u003E at [site:name].\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_notify_content_followers_new_comment'] = entity_import('message_type', '{
    "name" : "c4m_notify_content_followers_new_comment",
    "description" : "c4m Notify Content Followers New Comment",
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
          "value" : "\\u003Cp\\u003EYou\\u0027ve received a new comment\\u003C\\/p\\u003E\\r\\n",
          "format" : "default_html",
          "safe_value" : "\\u003Cp\\u003EYou\\u0027ve received a new comment\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EDear @user_full_name,\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Ca href=\\u0022!event_user_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@event_user_full_name\\u003C\\/a\\u003E posted a\\u0026nbsp; comment on your @comment_content_type: \\u003Cstrong\\u003E\\u003Ca href=\\u0022!comment_content_url\\u0022\\u003E@comment_content_title\\u003C\\/a\\u003E\\u003C\\/strong\\u003E\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cem\\u003E@comment_teaser_body \\u003C\\/em\\u003E\\u003Cbr \\/\\u003E\\r\\n\\u003Ca href=\\u0022!comment_content_url\\u0022\\u003ERead more... \\u003C\\/a\\u003Eor directly \\u003Ca href=\\u0022!comment_content_url\\u0022\\u003Ereply to this comment\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EYou\\u0027re receiving this e-mail because another member commented on your post - if you no longer wish to receive notifications, please \\u003Ca href=\\u0022!unsubscribe_content_comments_url\\u0022\\u003Eunsubscribe\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EDear @user_full_name,\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u003Ca href=\\u0022!event_user_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@event_user_full_name\\u003C\\/a\\u003E posted a\\u0026nbsp; comment on your @comment_content_type: \\u003Cstrong\\u003E\\u003Ca href=\\u0022!comment_content_url\\u0022\\u003E@comment_content_title\\u003C\\/a\\u003E\\u003C\\/strong\\u003E\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u003Cem\\u003E@comment_teaser_body \\u003C\\/em\\u003E\\u003Cbr \\/\\u003E\\n\\u003Ca href=\\u0022!comment_content_url\\u0022\\u003ERead more... \\u003C\\/a\\u003Eor directly \\u003Ca href=\\u0022!comment_content_url\\u0022\\u003Ereply to this comment\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou\\u0027re receiving this e-mail because another member commented on your post - if you no longer wish to receive notifications, please \\u003Ca href=\\u0022!unsubscribe_content_comments_url\\u0022\\u003Eunsubscribe\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_notify_content_recommendation'] = entity_import('message_type', '{
    "name" : "c4m_notify_content_recommendation",
    "description" : "c4m Notify Content Recommendation",
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
          "value" : "\\u003Cp\\u003EYour @content_type_name\\u0026nbsp;was recommended\\u003C\\/p\\u003E\\r\\n",
          "format" : "default_html",
          "safe_value" : "\\u003Cp\\u003EYour @content_type_name\\u00a0was recommended\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EDear @user_full_name,\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Ca href=\\u0022!event_user_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@event_user_full_name\\u003C\\/a\\u003E recommended your @content_type_name: \\u003Cstrong\\u003E\\u003Ca href=\\u0022!content_node_url\\u0022\\u003E@content_node_title\\u003C\\/a\\u003E\\u003C\\/strong\\u003E\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cem\\u003E@node_teaser_body \\u003C\\/em\\u003E\\u003Cbr \\/\\u003E\\r\\n\\u003Ca href=\\u0022!content_node_url\\u0022\\u003ERead more...\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003ETotal recommendations: @content_recommend_count\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EYou\\u0027re receiving this e-mail because another member recommended your post - if you no longer wish to receive notifications when your content is recommended, please \\u003Ca href=\\u0022!user_unsubscribe_recommend_url\\u0022\\u003Eunsubscribe.\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EDear @user_full_name,\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u003Ca href=\\u0022!event_user_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@event_user_full_name\\u003C\\/a\\u003E recommended your @content_type_name: \\u003Cstrong\\u003E\\u003Ca href=\\u0022!content_node_url\\u0022\\u003E@content_node_title\\u003C\\/a\\u003E\\u003C\\/strong\\u003E\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u003Cem\\u003E@node_teaser_body \\u003C\\/em\\u003E\\u003Cbr \\/\\u003E\\n\\u003Ca href=\\u0022!content_node_url\\u0022\\u003ERead more...\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n\\u003Cp\\u003ETotal recommendations: @content_recommend_count\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou\\u0027re receiving this e-mail because another member recommended your post - if you no longer wish to receive notifications when your content is recommended, please \\u003Ca href=\\u0022!user_unsubscribe_recommend_url\\u0022\\u003Eunsubscribe.\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_notify_promoted_member'] = entity_import('message_type', '{
    "name" : "c4m_notify_promoted_member",
    "description" : "c4m Notify Promoted Member",
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
          "value" : "\\u003Cp\\u003EYour are now administrator for\\u0026nbsp;@group_node_type: @group_node_title\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n",
          "format" : "default_html",
          "safe_value" : "\\u003Cp\\u003EYour are now administrator for\\u00a0@group_node_type: @group_node_title\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u00a0\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u00a0\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EDear @member_full_name,\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EYou are now an administrator for the @group_node_type \\u003Ca href=\\u0022!group_dashboard_url\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EDiscover new functionalities and find out how you can administer this @group_node_type by consulting the following \\u003Ca href=\\u0022url]help-guidance\\u0022 rel=\\u0022nofollow\\u0022\\u003Ehelp section\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003Eif you have any questions about your role as administrator, please feel free to \\u003Ca href=\\u0022!event_user_message_url\\u0022\\u003Econtact me\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E@event_user_full_name\\u003Cbr \\/\\u003E\\r\\n@group_node_type Administrator, @group_node_title\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EDear @member_full_name,\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou are now an administrator for the @group_node_type \\u003Ca href=\\u0022!group_dashboard_url\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n\\u003Cp\\u003EDiscover new functionalities and find out how you can administer this @group_node_type by consulting the following \\u003Ca href=\\u0022url]help-guidance\\u0022 rel=\\u0022nofollow\\u0022\\u003Ehelp section\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\n\\u003Cp\\u003Eif you have any questions about your role as administrator, please feel free to \\u003Ca href=\\u0022!event_user_message_url\\u0022\\u003Econtact me\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\n\\u003Cp\\u003E@event_user_full_name\\u003Cbr \\/\\u003E\\n@group_node_type Administrator, @group_node_title\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['c4m_notify_subscribers_new_comment'] = entity_import('message_type', '{
    "name" : "c4m_notify_subscribers_new_comment",
    "description" : "c4m Notify Subscribers New Comment",
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
          "value" : "\\u003Cp\\u003EYou received a reply to your comment\\u003C\\/p\\u003E\\r\\n",
          "format" : "default_html",
          "safe_value" : "\\u003Cp\\u003EYou received a reply to your comment\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EDear @user_full_name,\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Ca href=\\u0022!event_user_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@event_user_full_name\\u003C\\/a\\u003E added a new comment on the following @comment_content_type: \\u003Cstrong\\u003E\\u003Ca href=\\u0022!comment_content_url\\u0022\\u003E@comment_content_title\\u003C\\/a\\u003E\\u003C\\/strong\\u003E\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cem\\u003E@comment_teaser_body \\u003C\\/em\\u003E\\u003Cbr \\/\\u003E\\r\\n\\u003Ca href=\\u0022!comment_content_url\\u0022\\u003ERead more... \\u003C\\/a\\u003Eor directly \\u003Ca href=\\u0022!comment_content_url\\u0022\\u003Ereply to this comment\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EYou\\u0027re receiving this e-mail because a new comment was made - if you no longer wish to receive notifications of comments on this content, please \\u003Ca href=\\u0022!unsubscribe_content_comments_url\\u0022\\u003Eunsubscribe\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EDear @user_full_name,\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u003Ca href=\\u0022!event_user_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@event_user_full_name\\u003C\\/a\\u003E added a new comment on the following @comment_content_type: \\u003Cstrong\\u003E\\u003Ca href=\\u0022!comment_content_url\\u0022\\u003E@comment_content_title\\u003C\\/a\\u003E\\u003C\\/strong\\u003E\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u003Cem\\u003E@comment_teaser_body \\u003C\\/em\\u003E\\u003Cbr \\/\\u003E\\n\\u003Ca href=\\u0022!comment_content_url\\u0022\\u003ERead more... \\u003C\\/a\\u003Eor directly \\u003Ca href=\\u0022!comment_content_url\\u0022\\u003Ereply to this comment\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou\\u0027re receiving this e-mail because a new comment was made - if you no longer wish to receive notifications of comments on this content, please \\u003Ca href=\\u0022!unsubscribe_content_comments_url\\u0022\\u003Eunsubscribe\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\n"
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
          "value" : "\\u003Cp\\u003EDear @member_full_name,\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cbr \\/\\u003E\\r\\nThank you for joining \\u003Cstrong\\u003E\\u003Ca href=\\u0022!group_dashboard_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E\\u003C\\/strong\\u003E at [site:name].\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E@group_welcome_message\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cbr \\/\\u003E\\r\\n\\u003Ca href=\\u0022!go_public_profile_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@go_full_name\\u003C\\/a\\u003E,\\u003Cbr \\/\\u003E\\r\\n@group_node_type Administrator - @group_node_title\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EDear @member_full_name,\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\nThank you for joining \\u003Cstrong\\u003E\\u003Ca href=\\u0022!group_dashboard_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@group_node_title\\u003C\\/a\\u003E\\u003C\\/strong\\u003E at [site:name].\\u003C\\/p\\u003E\\n\\u003Cp\\u003E@group_welcome_message\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\n\\u003Ca href=\\u0022!go_public_profile_url\\u0022 rel=\\u0022nofollow\\u0022\\u003E@go_full_name\\u003C\\/a\\u003E,\\u003Cbr \\/\\u003E\\n@group_node_type Administrator - @group_node_title\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
