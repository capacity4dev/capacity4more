<?php

/**
 * @file
 * Create an overview of the featured messages to import them in an update hook.
 */

/**
 * Get a list of all the notification message entities as objects.
 *
 * @return array
 *   Array of message objects ready to be imported/saved.
 */
function _c4m_message_get_messages_notifies() {
  $messages = [];

  // NOTIFY :: MT10 :: Group Request Submitted.
  $messages[] = _c4m_message_get_messages_mt10();

  // NOTIFY :: MT12 :: Group Request Approved.
  $messages[] = _c4m_message_get_messages_mt12();

  // NOTIFY :: MT13 :: Welcome User to Group.
  $messages[] = _c4m_message_get_messages_mt13();

  // NOTIFY :: MT14 :: New Member Joined.
  $messages[] = _c4m_message_get_messages_mt14();

  // NOTIFY :: MT15 :: New Membership request.
  $messages[] = _c4m_message_get_messages_mt15();

  // NOTIFY :: MT17 :: Membership Request Rejected.
  $messages[] = _c4m_message_get_messages_mt17();

  // NOTIFY :: MT28 :: Group Published.
  $messages[] = _c4m_message_get_messages_mt28();

  // NOTIFY :: MT29 :: Group Unpublished.
  $messages[] = _c4m_message_get_messages_mt29();

  // NOTIFY :: MT30 :: Group Archived.
  $messages[] = _c4m_message_get_messages_mt30();

  // NOTIFY :: MT31 :: Group Re-Published.
  $messages[] = _c4m_message_get_messages_mt31();

  // NOTIFY :: MT32 :: Group Soft-Deleted.
  $messages[] = _c4m_message_get_messages_mt32();

  // NOTIFY :: MT34 :: Group Access Changed.
  $messages[] = _c4m_message_get_messages_mt34();

  // NOTIFY :: MT35 :: Group Admin Promoted.
  $messages[] = _c4m_message_get_messages_mt35();

  // NOTIFY :: MT36 :: Group Admin Demoted.
  $messages[] = _c4m_message_get_messages_mt36();

  // NOTIFY :: MT40 :: Group Membership Approved (to group admins).
  $messages[] = _c4m_message_get_messages_mt40();

  // NOTIFY :: MT48 :: Group Membership Requested (to requester).
  $messages[] = _c4m_message_get_messages_mt48();

  // NOTIFY :: MT49 :: Group Requested.
  $messages[] = _c4m_message_get_messages_mt49();

  return $messages;
}

/**
 * Get a list of all the subscribe_notify message entities as objects.
 *
 * @return array
 *   Array of message objects ready to be imported/saved.
 */
function _c4m_message_get_messages_subscribe_notifies() {
  $messages = [];

  // SUBSCRIPTION :: MT22 :: New Comment on your Comment.
  $messages[] = _c4m_message_get_messages_mt22();

  // SUBSCRIPTION :: MT23 :: New Recommendation on Content.
  $messages[] = _c4m_message_get_messages_mt23();

  // SUBSCRIPTION :: MT25 :: Group Content Published.
  $messages[] = _c4m_message_get_messages_mt25();

  // SUBSCRIPTION :: MT26 :: New Comment on Content.
  $messages[] = _c4m_message_get_messages_mt26();

  // SUBSCRIPTION :: MT46 :: Group Content Updated.
  $messages[] = _c4m_message_get_messages_mt46();

  // SUBSCRIPTION :: MT53 :: Group Content Shared.
  $messages[] = _c4m_message_get_messages_mt53();

  // SUBSCRIPTION :: MT51 :: Your Content Edited by Admin (to original
  // content author/editors).
  $messages[] = _c4m_message_get_messages_mt51();

  // SUBSCRIPTION :: MT54 :: Content Published about Term of Interest.
  $messages[] = _c4m_message_get_messages_mt54();

  return $messages;
}

/**
 * Get a list of all the activity stream message entities as objects.
 *
 * @return array
 *   Array of message objects ready to be imported/saved.
 */
function _c4m_message_get_messages_activity_streams() {
  $messages = [];

  // STREAM :: Comment Insert/Update.
  $messages[] = _c4m_message_get_messages_as1();

  // STREAM :: Article Insert/Update.
  $messages[] = _c4m_message_get_messages_as2();

  // STREAM :: Discussion Insert/Update.
  $messages[] = _c4m_message_get_messages_as3();

  // STREAM :: Document Insert/Update.
  $messages[] = _c4m_message_get_messages_as4();

  // STREAM :: Event Insert/Update.
  $messages[] = _c4m_message_get_messages_as5();

  // STREAM :: News Insert/Update.
  $messages[] = _c4m_message_get_messages_as6();

  // STREAM :: Photo Insert/Update.
  $messages[] = _c4m_message_get_messages_as7();

  // STREAM :: Photo Album Insert/Update.
  $messages[] = _c4m_message_get_messages_as8();

  // STREAM :: Share Insert/Update.
  $messages[] = _c4m_message_get_messages_as9();

  // STREAM :: Wiki Page Insert/Update.
  $messages[] = _c4m_message_get_messages_as10();

  return $messages;
}

/**
 * Get a list of all the log message entities as objects.
 *
 * @return array
 *   Array of message objects ready to be imported/saved.
 */
function _c4m_message_get_messages_logs() {
  $messages = [];

  // LOG :: Group State Change.
  $messages[] = _c4m_message_get_messages_log1();

  return $messages;
}

/**
 * Retrieve object for MT10.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_mt10() {
  return '
  {
  "name" : "c4m_group_request_submitted",
  "description" : "NOTIFY :: MT10 :: Group Request Submitted",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Cp\u003ENew @group_node_type\u0026nbsp;request\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u0026nbsp;\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u0026nbsp;\u003C\/p\u003E\r\n",
        "format" : "mail"
      },
      {
        "value" : "\u003Cp\u003EDear Administrator,\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cbr \/\u003E\r\n\u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E requested a new @group_node_type: \u003Ca href=\u0022!group_dashboard_url\u0022\u003E@group_node_title\u003C\/a\u003E.\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cbr \/\u003E\r\n\u003Cstrong\u003EReason\u003C\/strong\u003E: \u003Cem\u003E@message_to_site_admins\u003C\/em\u003E\u003C\/p\u003E\r\n\r\n\u003Cp\u003ETo edit the status of this @group_node_type: \u003Ca href=\u0022!pending_groups_overview\u0022\u003Emanage pending @group_node_type\u003C\/a\u003E.\u003C\/p\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear Administrator,\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cbr \/\u003E\n\u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E requested a new @group_node_type: \u003Ca href=\u0022!group_dashboard_url\u0022\u003E@group_node_title\u003C\/a\u003E.\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cbr \/\u003E\n\u003Cstrong\u003EReason\u003C\/strong\u003E: \u003Cem\u003E@message_to_site_admins\u003C\/em\u003E\u003C\/p\u003E\n\n\u003Cp\u003ETo edit the status of this @group_node_type: \u003Ca href=\u0022!pending_groups_overview\u0022\u003Emanage pending @group_node_type\u003C\/a\u003E.\u003C\/p\u003E\n"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for MT12.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_mt12() {
  return '
  {
  "name" : "c4m_group_request_approved",
  "description" : "NOTIFY :: MT12 :: Group Request Approved",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Cp\u003EYour @group_node_type\u0026nbsp;request for @group_node_title\u0026nbsp;was approved.\u003C\/p\u003E\r\n",
        "format" : "full_html"
      },
      {
        "value" : "\u003Cp\u003EDear @member_full_name,\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cbr \/\u003E\r\nWe\u0027re pleased to let you know your @group_node_type: \u003Cstrong\u003E@group_node_title\u003C\/strong\u003E was approved and is currently saved in draft status.\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cbr \/\u003E\r\n\u003Cem\u003E@admin_comment \u003C\/em\u003E\u003C\/p\u003E\r\n\r\n\u003Cp\u003EYou can access your new \u003Ca href=\u0022!group_dashboard_url\u0022 rel=\u0022nofollow\u0022\u003E@group_node_type here\u003C\/a\u003E.\u003C\/p\u003E\r\n\r\n\u003Cp\u003EAs the owner, we encourage you to read \u003Ca href=\u0022!help_section_url\u0022 rel=\u0022nofollow\u0022\u003Ethis short guide\u003C\/a\u003E. Here you\u2019ll find tips and advice to make the most of your @group_node_type. Once you\u0027re ready to go live, don\u0027t forget to update the status of your @group_node_type to share it with the rest of the community.\u003C\/p\u003E\r\n\r\n\u003Cp\u003EWe hope you\u2019ll enjoy using [site:name] and we\u2019d like to remind you that we are available to provide \u003Ca href=\u0022@site_contact_link\u0022 rel=\u0022nofollow\u0022\u003Ehelp and support\u003C\/a\u003E.\u003C\/p\u003E\r\n\r\n\u003Cp\u003EThe [site:name] team\u003C\/p\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @member_full_name,\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cbr \/\u003E\nWe\u0027re pleased to let you know your @group_node_type: \u003Cstrong\u003E@group_node_title\u003C\/strong\u003E was approved and is currently saved in draft status.\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cbr \/\u003E\n\u003Cem\u003E@admin_comment \u003C\/em\u003E\u003C\/p\u003E\n\n\u003Cp\u003EYou can access your new \u003Ca href=\u0022!group_dashboard_url\u0022 rel=\u0022nofollow\u0022\u003E@group_node_type here\u003C\/a\u003E.\u003C\/p\u003E\n\n\u003Cp\u003EAs the owner, we encourage you to read \u003Ca href=\u0022!help_section_url\u0022 rel=\u0022nofollow\u0022\u003Ethis short guide\u003C\/a\u003E. Here you\u2019ll find tips and advice to make the most of your @group_node_type. Once you\u0027re ready to go live, don\u0027t forget to update the status of your @group_node_type to share it with the rest of the community.\u003C\/p\u003E\n\n\u003Cp\u003EWe hope you\u2019ll enjoy using [site:name] and we\u2019d like to remind you that we are available to provide \u003Ca href=\u0022@site_contact_link\u0022 rel=\u0022nofollow\u0022\u003Ehelp and support\u003C\/a\u003E.\u003C\/p\u003E\n\n\u003Cp\u003EThe [site:name] team\u003C\/p\u003E\n"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for MT13.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_mt13() {
  return '
  {
  "name" : "c4m_welcome_to_group",
  "description" : "NOTIFY :: MT13 :: Welcome User to Group",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Cp\u003EWelcome to @group_node_title\u0026nbsp;\u003C\/p\u003E\r\n",
        "format" : "mail"
      },
      {
        "value" : "\u003Cp\u003EDear @member_full_name,\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cbr \/\u003E\r\nThank you for joining \u003Cstrong\u003E\u003Ca href=\u0022!group_dashboard_url\u0022 rel=\u0022nofollow\u0022\u003E@group_node_title\u003C\/a\u003E\u003C\/strong\u003E at [site:name].\u003C\/p\u003E\r\n\r\n\u003Cp\u003E@group_welcome_message\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cbr \/\u003E\r\n\u003Ca href=\u0022!go_public_profile_url\u0022 rel=\u0022nofollow\u0022\u003E@go_full_name\u003C\/a\u003E,\u003Cbr \/\u003E\r\n@group_node_type Administrator - @group_node_title\u003C\/p\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @member_full_name,\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cbr \/\u003E\nThank you for joining \u003Cstrong\u003E\u003Ca href=\u0022!group_dashboard_url\u0022 rel=\u0022nofollow\u0022\u003E@group_node_title\u003C\/a\u003E\u003C\/strong\u003E at [site:name].\u003C\/p\u003E\n\n\u003Cp\u003E@group_welcome_message\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cbr \/\u003E\n\u003Ca href=\u0022!go_public_profile_url\u0022 rel=\u0022nofollow\u0022\u003E@go_full_name\u003C\/a\u003E,\u003Cbr \/\u003E\n@group_node_type Administrator - @group_node_title\u003C\/p\u003E\n"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for MT14.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_mt14() {
  return '
  {
  "name" : "c4m_new_member_joined",
  "description" : "NOTIFY :: MT14 :: New Member Joined",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "module" : "c4m_message",
  "arguments" : null,
  "message_text" : { "und" : [
      {
        "value" : "\u003Cp\u003EA new member joined @group_node_title \u003C\/p\u003E\r\n",
        "format" : "mail"
      },
      {
        "value" : "\u003Cp\u003EDear @group_admin_full_name,\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cbr \/\u003E\r\nA new member joined \u003Ca href=\u0022!group_dashboard_url\u0022 rel=\u0022nofollow\u0022\u003E@group_node_title\u003C\/a\u003E at [site:name].\u003Cbr \/\u003E\r\nPlease find their details below:\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cstrong\u003E@new_member_full_name\u003C\/strong\u003E\u003C\/p\u003E\r\n\r\n\u003Cp\u003E@new_member_organisation, @new_member_organisation_type\u003C\/p\u003E\r\n\r\n\u003Cp\u003EBased in @new_member_country\u003C\/p\u003E\r\n\r\n\u003Cp\u003EExpertise: @new_member_expertise\u003C\/p\u003E\r\n\r\n\u003Cp\u003EAbout: @new_member_about_me\u003C\/p\u003E\r\n\r\n\u003Cp\u003EView this member\u0027s \u003Ca href=\u0022!new_member_public_profile_url\u0022 rel=\u0022nofollow\u0022\u003Eprofile\u003C\/a\u003E at [site:name].\u003C\/p\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @group_admin_full_name,\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cbr \/\u003E\nA new member joined \u003Ca href=\u0022!group_dashboard_url\u0022 rel=\u0022nofollow\u0022\u003E@group_node_title\u003C\/a\u003E at [site:name].\u003Cbr \/\u003E\nPlease find their details below:\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cstrong\u003E@new_member_full_name\u003C\/strong\u003E\u003C\/p\u003E\n\n\u003Cp\u003E@new_member_organisation, @new_member_organisation_type\u003C\/p\u003E\n\n\u003Cp\u003EBased in @new_member_country\u003C\/p\u003E\n\n\u003Cp\u003EExpertise: @new_member_expertise\u003C\/p\u003E\n\n\u003Cp\u003EAbout: @new_member_about_me\u003C\/p\u003E\n\n\u003Cp\u003EView this member\u0027s \u003Ca href=\u0022!new_member_public_profile_url\u0022 rel=\u0022nofollow\u0022\u003Eprofile\u003C\/a\u003E at [site:name].\u003C\/p\u003E\n"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for MT15.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_mt15() {
  return '
  {
  "name" : "c4m_new_membership_request",
  "description" : "NOTIFY :: MT15 :: New Membership request",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Cp\u003EA new member requested to join @group_node_title\u0026nbsp;\u003C\/p\u003E\r\n",
        "format" : "mail"
      },
      {
        "value" : "\u003Cp\u003EDear @group_admin_full_name,\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cbr \/\u003E\r\nA new member requested to join \u003Ca href=\u0022!group_dashboard_url\u0022 rel=\u0022nofollow\u0022\u003E@group_node_title\u003C\/a\u003E at [site:name].\u003Cbr \/\u003E\r\n\u003Ca href=\u0022!group_pending_member_url\u0022 rel=\u0022nofollow\u0022\u003EManage this request\u003C\/a\u003E\u003Cbr \/\u003E\r\nPlease find their details below:\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cstrong\u003E@new_member_full_name\u003C\/strong\u003E\u003C\/p\u003E\r\n\r\n\u003Cp\u003E@new_member_organisation, @new_member_organisation_type\u003C\/p\u003E\r\n\r\n\u003Cp\u003EBased in @new_member_country\u003C\/p\u003E\r\n\r\n\u003Cp\u003EExpertise: @new_member_expertise\u003C\/p\u003E\r\n\r\n\u003Cp\u003EAbout: @new_member_about_me\u003C\/p\u003E\r\n\r\n\u003Cp\u003EMessage from this member:\u003Cbr \/\u003E\r\n\u003Cem\u003E@new_member_request_message\u003C\/em\u003E\u003C\/p\u003E\r\n\r\n\u003Cp\u003EView this member\u0027s \u003Ca href=\u0022!new_member_public_profile_url\u0022 rel=\u0022nofollow\u0022\u003Eprofile\u003C\/a\u003E at [site:name].\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Ca href=\u0022!membership_approve_url\u0022\u003EApprove\u003C\/a\u003E - \u003Ca href=\u0022!membership_reject_url\u0022\u003EReject\u003C\/a\u003E\u003C\/p\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @group_admin_full_name,\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cbr \/\u003E\nA new member requested to join \u003Ca href=\u0022!group_dashboard_url\u0022 rel=\u0022nofollow\u0022\u003E@group_node_title\u003C\/a\u003E at [site:name].\u003Cbr \/\u003E\n\u003Ca href=\u0022!group_pending_member_url\u0022 rel=\u0022nofollow\u0022\u003EManage this request\u003C\/a\u003E\u003Cbr \/\u003E\nPlease find their details below:\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cstrong\u003E@new_member_full_name\u003C\/strong\u003E\u003C\/p\u003E\n\n\u003Cp\u003E@new_member_organisation, @new_member_organisation_type\u003C\/p\u003E\n\n\u003Cp\u003EBased in @new_member_country\u003C\/p\u003E\n\n\u003Cp\u003EExpertise: @new_member_expertise\u003C\/p\u003E\n\n\u003Cp\u003EAbout: @new_member_about_me\u003C\/p\u003E\n\n\u003Cp\u003EMessage from this member:\u003Cbr \/\u003E\n\u003Cem\u003E@new_member_request_message\u003C\/em\u003E\u003C\/p\u003E\n\n\u003Cp\u003EView this member\u0027s \u003Ca href=\u0022!new_member_public_profile_url\u0022 rel=\u0022nofollow\u0022\u003Eprofile\u003C\/a\u003E at [site:name].\u003C\/p\u003E\n\n\u003Cp\u003E\u003Ca href=\u0022!membership_approve_url\u0022\u003EApprove\u003C\/a\u003E - \u003Ca href=\u0022!membership_reject_url\u0022\u003EReject\u003C\/a\u003E\u003C\/p\u003E\n"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for MT17.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_mt17() {
  return '
  {
  "name" : "c4m_membership_request_rejected",
  "description" : "NOTIFY :: MT17 :: Membership Request Rejected",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Cp\u003EYour membership request to join @group_node_title\u0026nbsp; was rejected\u003C\/p\u003E\r\n",
        "format" : "mail"
      },
      {
        "value" : "\u003Cp\u003EDear colleague,\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cbr \/\u003E\r\nThank you for your interest in the group \u003Cstrong\u003E\u003Ca href=\u0022!group_dashboard_url\u0022 rel=\u0022nofollow\u0022\u003E@group_node_title\u003C\/a\u003E\u003C\/strong\u003E.\u003C\/p\u003E\r\n\r\n\u003Cp\u003EUnfortunately we cannot accept your membership request because @membership_reject_reason.\u003C\/p\u003E\r\n\r\n\u003Cp\u003EThank you for your understanding.\u003C\/p\u003E\r\n\r\n\u003Cp\u003EDon\u0027t hesitate to contact me if your have further questions.\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cbr \/\u003E\r\n\u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E,\u003Cbr \/\u003E\r\n@group_node_type Administrator - @group_node_title\u003C\/p\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear colleague,\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cbr \/\u003E\nThank you for your interest in the group \u003Cstrong\u003E\u003Ca href=\u0022!group_dashboard_url\u0022 rel=\u0022nofollow\u0022\u003E@group_node_title\u003C\/a\u003E\u003C\/strong\u003E.\u003C\/p\u003E\n\n\u003Cp\u003EUnfortunately we cannot accept your membership request because @membership_reject_reason.\u003C\/p\u003E\n\n\u003Cp\u003EThank you for your understanding.\u003C\/p\u003E\n\n\u003Cp\u003EDon\u0027t hesitate to contact me if your have further questions.\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cbr \/\u003E\n\u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E,\u003Cbr \/\u003E\n@group_node_type Administrator - @group_node_title\u003C\/p\u003E\n"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for MT22.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_mt22() {
  return '
  {
  "name" : "c4m_notify_subscribers_new_comment",
  "description" : "SUBSCRIPTION :: MT22 :: New Comment (reply) after Comment",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Cp\u003EYou received a reply to your comment\u003C\/p\u003E\r\n",
        "format" : "mail"
      },
      {
        "value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E added a new comment on the following @comment_content_type: \u003Cstrong\u003E\u003Ca href=\u0022!comment_content_url\u0022\u003E@comment_content_title\u003C\/a\u003E\u003C\/strong\u003E\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cem\u003E@comment_teaser_body \u003C\/em\u003E\u003Cbr \/\u003E\r\n\u003Ca href=\u0022!comment_url\u0022\u003ERead more...\u003C\/a\u003E or directly \u003Ca href=\u0022!comment_reply_url\u0022\u003Ereply to this comment\u003C\/a\u003E.\u003C\/p\u003E\r\n\r\n\u003Cp\u003EYou\u0027re receiving this e-mail because a new comment was made - if you no longer wish to receive notifications of comments on this content, please \u003Ca href=\u0022!unsubscribe_content_comments_url\u0022\u003Eunsubscribe\u003C\/a\u003E.\u003C\/p\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\n\n\u003Cp\u003E\u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E added a new comment on the following @comment_content_type: \u003Cstrong\u003E\u003Ca href=\u0022!comment_content_url\u0022\u003E@comment_content_title\u003C\/a\u003E\u003C\/strong\u003E\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cem\u003E@comment_teaser_body \u003C\/em\u003E\u003Cbr \/\u003E\n\u003Ca href=\u0022!comment_url\u0022\u003ERead more...\u003C\/a\u003E or directly \u003Ca href=\u0022!comment_reply_url\u0022\u003Ereply to this comment\u003C\/a\u003E.\u003C\/p\u003E\n\n\u003Cp\u003EYou\u0027re receiving this e-mail because a new comment was made - if you no longer wish to receive notifications of comments on this content, please \u003Ca href=\u0022!unsubscribe_content_comments_url\u0022\u003Eunsubscribe\u003C\/a\u003E.\u003C\/p\u003E\n"
      },
      {
        "value" : " \u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E replied to your comment on the following @comment_content_type: \u003Cstrong\u003E\u003Ca href=\u0022!comment_content_url\u0022\u003E@comment_content_title\u003C\/a\u003E\u003C\/strong\u003E",
        "format" : "mail",
        "safe_value" : " \u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E replied to your comment on the following @comment_content_type: \u003Cstrong\u003E\u003Ca href=\u0022!comment_content_url\u0022\u003E@comment_content_title\u003C\/a\u003E\u003C\/strong\u003E"
      }
    ]
  },
  "message_header" : { "und" : [
      {
        "value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\r\n  \r\n\u003Cp\u003EDiscover the latest updates you\u0027re subscribed to!\u003C\/p\u003E",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\n  \n\u003Cp\u003EDiscover the latest updates you\u0027re subscribed to!\u003C\/p\u003E"
      }
    ]
  },
  "message_footer" : { "und" : [
      {
        "value" : "\u003Cp\u003EYou are receiving these updates because you are subscribed to capacity4dev notification message(s) - to manage these, update your \u003Ca href=\u0022!user_settings_url\u0022\u003Enotification settings\u003C\/a\u003E.\u003C\/p\u003E",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EYou are receiving these updates because you are subscribed to capacity4dev notification message(s) - to manage these, update your \u003Ca href=\u0022!user_settings_url\u0022\u003Enotification settings\u003C\/a\u003E.\u003C\/p\u003E"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for MT23.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_mt23() {
  return '
  {
  "name" : "c4m_notify_content_recommendation",
  "description" : "SUBSCRIPTION :: MT23 :: New Recommendation on Content",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Cp\u003EYour @content_type_name\u0026nbsp;was recommended\u003C\/p\u003E\r\n",
        "format" : "mail"
      },
      {
        "value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E recommended your @content_type_name: \u003Cstrong\u003E\u003Ca href=\u0022!content_node_url\u0022\u003E@content_node_title\u003C\/a\u003E\u003C\/strong\u003E\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cem\u003E@node_teaser_body \u003C\/em\u003E\u003Cbr \/\u003E\r\n\u003Ca href=\u0022!content_node_url\u0022\u003ERead more...\u003C\/a\u003E\u003C\/p\u003E\r\n\r\n\u003Cp\u003ETotal recommendations: @content_recommend_count\u003C\/p\u003E\r\n\r\n\u003Cp\u003EYou\u0027re receiving this e-mail because another member recommended your post - if you no longer wish to receive notifications when your content is recommended, please \u003Ca href=\u0022!user_unsubscribe_recommend_url\u0022\u003Eunsubscribe.\u003C\/a\u003E\u003C\/p\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\n\n\u003Cp\u003E\u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E recommended your @content_type_name: \u003Cstrong\u003E\u003Ca href=\u0022!content_node_url\u0022\u003E@content_node_title\u003C\/a\u003E\u003C\/strong\u003E\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cem\u003E@node_teaser_body \u003C\/em\u003E\u003Cbr \/\u003E\n\u003Ca href=\u0022!content_node_url\u0022\u003ERead more...\u003C\/a\u003E\u003C\/p\u003E\n\n\u003Cp\u003ETotal recommendations: @content_recommend_count\u003C\/p\u003E\n\n\u003Cp\u003EYou\u0027re receiving this e-mail because another member recommended your post - if you no longer wish to receive notifications when your content is recommended, please \u003Ca href=\u0022!user_unsubscribe_recommend_url\u0022\u003Eunsubscribe.\u003C\/a\u003E\u003C\/p\u003E\n"
      },
      {
        "value" : "\u003Ca href=\u0022!content_node_url\u0022\u003E@content_node_title\u003C\/a\u003E, @content_type_name recommended by \u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E",
        "format" : "mail",
        "safe_value" : "\u003Ca href=\u0022!content_node_url\u0022\u003E@content_node_title\u003C\/a\u003E, @content_type_name recommended by \u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E"
      }
    ]
  },
  "message_header" : { "und" : [
      {
        "value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\r\n  \r\n\u003Cp\u003EDiscover the latest updates you\u0027re subscribed to!\u003C\/p\u003E",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\n  \n\u003Cp\u003EDiscover the latest updates you\u0027re subscribed to!\u003C\/p\u003E"
      }
    ]
  },
  "message_footer" : { "und" : [
      {
        "value" : "\u003Cp\u003EYou are receiving these updates because you are subscribed to capacity4dev notification message(s) - to manage these, update your \u003Ca href=\u0022!user_settings_url\u0022\u003Enotification settings\u003C\/a\u003E.\u003C\/p\u003E",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EYou are receiving these updates because you are subscribed to capacity4dev notification message(s) - to manage these, update your \u003Ca href=\u0022!user_settings_url\u0022\u003Enotification settings\u003C\/a\u003E.\u003C\/p\u003E"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for MT25.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_mt25() {
  return '
  {
  "name" : "c4m_new_content_published",
  "description" : "SUBSCRIPTION :: MT25 :: New Group Content Published",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Cp\u003ENew @content_type_name from @group_node_title\u003C\/p\u003E\r\n",
        "format" : "mail"
      },
      {
        "value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E @event_action\u0026nbsp;the following @content_type_name: \u003Cstrong\u003E\u003Ca href=\u0022!content_node_url\u0022\u003E@content_node_title\u003C\/a\u003E\u003C\/strong\u003E\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cem\u003E@node_teaser_body \u003C\/em\u003E\u003Cbr \/\u003E\r\n\u003Ca href=\u0022!content_node_url\u0022\u003ERead more...\u003C\/a\u003E\u003C\/p\u003E\r\n\r\n\u003Cp\u003EYou\u0027re receiving this e-mail because you\u0027re subscribed to \u003Ca href=\u0022!group_dashboard_url\u0022\u003E@group_node_title\u003C\/a\u003E\u0026nbsp;- if you no longer wish to receive notifications from this @group_node_type, please \u003Ca href=\u0022!unsubscribe_group_url\u0022\u003Eunsubscribe.\u003C\/a\u003E\u003C\/p\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\n\n\u003Cp\u003E\u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E @event_action\u0026nbsp;the following @content_type_name: \u003Cstrong\u003E\u003Ca href=\u0022!content_node_url\u0022\u003E@content_node_title\u003C\/a\u003E\u003C\/strong\u003E\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cem\u003E@node_teaser_body \u003C\/em\u003E\u003Cbr \/\u003E\n\u003Ca href=\u0022!content_node_url\u0022\u003ERead more...\u003C\/a\u003E\u003C\/p\u003E\n\n\u003Cp\u003EYou\u0027re receiving this e-mail because you\u0027re subscribed to \u003Ca href=\u0022!group_dashboard_url\u0022\u003E@group_node_title\u003C\/a\u003E\u0026nbsp;- if you no longer wish to receive notifications from this @group_node_type, please \u003Ca href=\u0022!unsubscribe_group_url\u0022\u003Eunsubscribe.\u003C\/a\u003E\u003C\/p\u003E\n"
      },
      {
        "value" : "\u003Ca href=\u0022!content_node_url\u0022\u003E@content_node_title\u003C\/a\u003E, @content_type_name @event_action by \u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E",
        "format" : "mail",
        "safe_value" : "\u003Ca href=\u0022!content_node_url\u0022\u003E@content_node_title\u003C\/a\u003E, @content_type_name @event_action by \u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E"
      }
    ]
  },
  "message_header" : { "und" : [
      {
        "value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\r\n  \r\n\u003Cp\u003EDiscover the latest updates you\u0027re subscribed to!\u003C\/p\u003E",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\n  \n\u003Cp\u003EDiscover the latest updates you\u0027re subscribed to!\u003C\/p\u003E"
      }
    ]
  },
  "message_footer" : { "und" : [
      {
        "value" : "\u003Cp\u003EYou are receiving these updates because you are subscribed to capacity4dev notification message(s) - to manage these, update your \u003Ca href=\u0022!user_settings_url\u0022\u003Enotification settings\u003C\/a\u003E.\u003C\/p\u003E",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EYou are receiving these updates because you are subscribed to capacity4dev notification message(s) - to manage these, update your \u003Ca href=\u0022!user_settings_url\u0022\u003Enotification settings\u003C\/a\u003E.\u003C\/p\u003E"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for MT26.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_mt26() {
  return '
  {
  "name" : "c4m_notify_content_followers_new_comment",
  "description" : "SUBSCRIPTION :: MT26 :: New Comment on Content",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Cp\u003EYou\u0027ve received a new comment\u003C\/p\u003E\r\n",
        "format" : "mail"
      },
      {
        "value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E posted a\u0026nbsp; comment on your @comment_content_type: \u003Cstrong\u003E\u003Ca href=\u0022!comment_content_url\u0022\u003E@comment_content_title\u003C\/a\u003E\u003C\/strong\u003E\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cem\u003E@comment_teaser_body \u003C\/em\u003E\u003Cbr \/\u003E\r\n\u003Ca href=\u0022!comment_url\u0022\u003ERead more...\u003C\/a\u003E or directly \u003Ca href=\u0022!comment_reply_url\u0022\u003Ereply to this comment\u003C\/a\u003E.\u003C\/p\u003E\r\n\r\n\u003Cp\u003EYou\u0027re receiving this e-mail because another member commented on your post - if you no longer wish to receive notifications, please \u003Ca href=\u0022!unsubscribe_content_comments_url\u0022\u003Eunsubscribe\u003C\/a\u003E.\u003C\/p\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\n\n\u003Cp\u003E\u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E posted a\u0026nbsp; comment on your @comment_content_type: \u003Cstrong\u003E\u003Ca href=\u0022!comment_content_url\u0022\u003E@comment_content_title\u003C\/a\u003E\u003C\/strong\u003E\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cem\u003E@comment_teaser_body \u003C\/em\u003E\u003Cbr \/\u003E\n\u003Ca href=\u0022!comment_url\u0022\u003ERead more...\u003C\/a\u003E or directly \u003Ca href=\u0022!comment_reply_url\u0022\u003Ereply to this comment\u003C\/a\u003E.\u003C\/p\u003E\n\n\u003Cp\u003EYou\u0027re receiving this e-mail because another member commented on your post - if you no longer wish to receive notifications, please \u003Ca href=\u0022!unsubscribe_content_comments_url\u0022\u003Eunsubscribe\u003C\/a\u003E.\u003C\/p\u003E\n"
      },
      {
        "value" : "\u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E commented on the following @comment_content_type: \u003Cstrong\u003E\u003Ca href=\u0022!comment_content_url\u0022\u003E@comment_content_title\u003C\/a\u003E\u003C\/strong\u003E",
        "format" : "mail",
        "safe_value" : "\u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E commented on the following @comment_content_type: \u003Cstrong\u003E\u003Ca href=\u0022!comment_content_url\u0022\u003E@comment_content_title\u003C\/a\u003E\u003C\/strong\u003E"
      }
    ]
  },
  "message_header" : { "und" : [
      {
        "value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\r\n  \r\n\u003Cp\u003EDiscover the latest updates you\u0027re subscribed to!\u003C\/p\u003E",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\n  \n\u003Cp\u003EDiscover the latest updates you\u0027re subscribed to!\u003C\/p\u003E"
      }
    ]
  },
  "message_footer" : { "und" : [
      {
        "value" : "\u003Cp\u003EYou are receiving these updates because you are subscribed to capacity4dev notification message(s) - to manage these, update your \u003Ca href=\u0022!user_settings_url\u0022\u003Enotification settings\u003C\/a\u003E.\u003C\/p\u003E",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EYou are receiving these updates because you are subscribed to capacity4dev notification message(s) - to manage these, update your \u003Ca href=\u0022!user_settings_url\u0022\u003Enotification settings\u003C\/a\u003E.\u003C\/p\u003E"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for MT28.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_mt28() {
  return '
  {
  "name" : "c4m_group_published",
  "description" : "NOTIFY :: MT28 :: Group Published",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Cp\u003EYour @group_node_type\u0026nbsp;@group_node_title\u0026nbsp;is published\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u0026nbsp;\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u0026nbsp;\u003C\/p\u003E\r\n",
        "format" : "mail"
      },
      {
        "value" : "\u003Cp\u003EDear @group_admin_full_name,\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cbr \/\u003E\r\nCongratulations!\u0026nbsp;\u003Ca href=\u0022!group_dashboard_url\u0022 rel=\u0022nofollow\u0022\u003E@group_node_title\u003C\/a\u003E is now published.\u003C\/p\u003E\r\n\r\n\u003Cp\u003E@event_user_full_name updated the status of this @group_node_type from Draft to Published.\u003C\/p\u003E\r\n\r\n\u003Cp\u003EYou can consult \u003Ca href=\u0022!help_section_url\u0022 rel=\u0022nofollow\u0022\u003Ethis help section\u003C\/a\u003E to find out more about @group_node_type statuses and what they imply.\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cbr \/\u003E\r\nThe capacity4dev team\u003C\/p\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @group_admin_full_name,\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cbr \/\u003E\nCongratulations!\u0026nbsp;\u003Ca href=\u0022!group_dashboard_url\u0022 rel=\u0022nofollow\u0022\u003E@group_node_title\u003C\/a\u003E is now published.\u003C\/p\u003E\n\n\u003Cp\u003E@event_user_full_name updated the status of this @group_node_type from Draft to Published.\u003C\/p\u003E\n\n\u003Cp\u003EYou can consult \u003Ca href=\u0022!help_section_url\u0022 rel=\u0022nofollow\u0022\u003Ethis help section\u003C\/a\u003E to find out more about @group_node_type statuses and what they imply.\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cbr \/\u003E\nThe capacity4dev team\u003C\/p\u003E\n"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for MT29.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_mt29() {
  return '
  {
  "name" : "c4m_group_unpublished",
  "description" : "NOTIFY :: MT29 :: Group Unpublished",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Cp\u003EYour @group_node_type\u0026nbsp;@group_node_title\u0026nbsp;is no longer published\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u0026nbsp;\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u0026nbsp;\u003C\/p\u003E\r\n",
        "format" : "mail"
      },
      {
        "value" : "\u003Cp\u003EDear @group_admin_full_name,\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cbr \/\u003E\r\n\u003Ca href=\u0022!group_dashboard_url\u0022 rel=\u0022nofollow\u0022\u003E@group_node_title\u003C\/a\u003E\u0026nbsp;reverted back to Draft status.\u003C\/p\u003E\r\n\r\n\u003Cp\u003E@event_user_full_name\u0026nbsp;updated the status of this @group_node_type from @group_former_status to Draft.\u003C\/p\u003E\r\n\r\n\u003Cp\u003EYou can consult \u003Ca href=\u0022!help_section_url\u0022 rel=\u0022nofollow\u0022\u003Ethis help section\u003C\/a\u003E to find out more about @group_node_type statuses and what they imply.\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cbr \/\u003E\r\nThe capacity4dev team\u003C\/p\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @group_admin_full_name,\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cbr \/\u003E\n\u003Ca href=\u0022!group_dashboard_url\u0022 rel=\u0022nofollow\u0022\u003E@group_node_title\u003C\/a\u003E\u0026nbsp;reverted back to Draft status.\u003C\/p\u003E\n\n\u003Cp\u003E@event_user_full_name\u0026nbsp;updated the status of this @group_node_type from @group_former_status to Draft.\u003C\/p\u003E\n\n\u003Cp\u003EYou can consult \u003Ca href=\u0022!help_section_url\u0022 rel=\u0022nofollow\u0022\u003Ethis help section\u003C\/a\u003E to find out more about @group_node_type statuses and what they imply.\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cbr \/\u003E\nThe capacity4dev team\u003C\/p\u003E\n"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for MT30.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_mt30() {
  return '
  {
  "name" : "c4m_group_archived",
  "description" : "NOTIFY :: MT30 :: Group Archived",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Cp\u003EYour @group_node_type @group_node_title is archived\u003C\/p\u003E\r\n\r\n\u003Cp\u003E \u003C\/p\u003E\r\n\r\n\u003Cp\u003E \u003C\/p\u003E\r\n",
        "format" : "mail"
      },
      {
        "value" : "\u003Cp\u003EDear @group_admin_full_name,\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cbr \/\u003E\r\n\u003Ca href=\u0022!group_dashboard_url\u0022 rel=\u0022nofollow\u0022\u003E@group_node_title\u003C\/a\u003E is now archived.\u003C\/p\u003E\r\n\r\n\u003Cp\u003E@event_user_full_name updated the status of this @group_node_type from @group_former_status to Archived.\u003C\/p\u003E\r\n\r\n\u003Cp\u003EYou can consult \u003Ca href=\u0022!help_section_url\u0022 rel=\u0022nofollow\u0022\u003Ethis help section\u003C\/a\u003E to find out more about @group_node_type statuses and what they imply.\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cbr \/\u003E\r\nThe capacity4dev team\u003C\/p\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @group_admin_full_name,\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cbr \/\u003E\n\u003Ca href=\u0022!group_dashboard_url\u0022 rel=\u0022nofollow\u0022\u003E@group_node_title\u003C\/a\u003E is now archived.\u003C\/p\u003E\n\n\u003Cp\u003E@event_user_full_name updated the status of this @group_node_type from @group_former_status to Archived.\u003C\/p\u003E\n\n\u003Cp\u003EYou can consult \u003Ca href=\u0022!help_section_url\u0022 rel=\u0022nofollow\u0022\u003Ethis help section\u003C\/a\u003E to find out more about @group_node_type statuses and what they imply.\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cbr \/\u003E\nThe capacity4dev team\u003C\/p\u003E\n"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for MT31.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_mt31() {
  return '
  {
  "name" : "c4m_group_republished",
  "description" : "NOTIFY :: MT31 :: Group Re-published",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "module" : "c4m_message",
  "arguments" : null,
  "message_text" : { "und" : [
      {
        "value" : "\u003Cp\u003EYour @group_node_type\u0026nbsp;@group_node_title\u0026nbsp;is published once again\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u0026nbsp;\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u0026nbsp;\u003C\/p\u003E\r\n",
        "format" : "mail"
      },
      {
        "value" : "\u003Cp\u003EDear @group_admin_full_name,\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cbr \/\u003E\r\n\u003Ca href=\u0022!group_dashboard_url\u0022 rel=\u0022nofollow\u0022\u003E@group_node_title\u003C\/a\u003E was published once again.\u003C\/p\u003E\r\n\r\n\u003Cp\u003E@event_user_full_name\u0026nbsp;updated the status of this @group_node_type from @group_former_status to Published.\u003C\/p\u003E\r\n\r\n\u003Cp\u003EYou can consult \u003Ca href=\u0022!help_section_url\u0022 rel=\u0022nofollow\u0022\u003Ethis help section\u003C\/a\u003E to find out more about @group_node_type statuses and what they imply.\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cbr \/\u003E\r\nThe capacity4dev team\u003C\/p\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @group_admin_full_name,\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cbr \/\u003E\n\u003Ca href=\u0022!group_dashboard_url\u0022 rel=\u0022nofollow\u0022\u003E@group_node_title\u003C\/a\u003E was published once again.\u003C\/p\u003E\n\n\u003Cp\u003E@event_user_full_name\u0026nbsp;updated the status of this @group_node_type from @group_former_status to Published.\u003C\/p\u003E\n\n\u003Cp\u003EYou can consult \u003Ca href=\u0022!help_section_url\u0022 rel=\u0022nofollow\u0022\u003Ethis help section\u003C\/a\u003E to find out more about @group_node_type statuses and what they imply.\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cbr \/\u003E\nThe capacity4dev team\u003C\/p\u003E\n"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for MT32.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_mt32() {
  return '
  {
  "name" : "c4m_group_soft_deleted",
  "description" : "NOTIFY :: MT32 :: Group Soft-Deleted",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Cp\u003EThe @group_node_type\u0026nbsp;@group_node_title was\u0026nbsp;deleted\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u0026nbsp;\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u0026nbsp;\u003C\/p\u003E\r\n",
        "format" : "mail"
      },
      {
        "value" : "\u003Cp\u003EDear administrator,\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cbr \/\u003E\r\n\u003Ca href=\u0022!group_dashboard_url\u0022 rel=\u0022nofollow\u0022\u003E@group_node_title\u003C\/a\u003E has been deleted.\u003C\/p\u003E\r\n\r\n\u003Cp\u003E@event_user_full_name updated the status of this @group_node_type from @group_former_status to Deleted.\u003C\/p\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear administrator,\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cbr \/\u003E\n\u003Ca href=\u0022!group_dashboard_url\u0022 rel=\u0022nofollow\u0022\u003E@group_node_title\u003C\/a\u003E has been deleted.\u003C\/p\u003E\n\n\u003Cp\u003E@event_user_full_name updated the status of this @group_node_type from @group_former_status to Deleted.\u003C\/p\u003E\n"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for MT34.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_mt34() {
  return '
  {
  "name" : "c4m_group_access_change",
  "description" : "NOTIFY :: MT34 :: Group Access Change",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Cp\u003EYour @group_node_type @group_node_title has new permissions!\u003C\/p\u003E\r\n\r\n\u003Cp\u003E \u003C\/p\u003E\r\n",
        "format" : "mail"
      },
      {
        "value" : "\u003Cp\u003EDear @group_admin_full_name,\u003C\/p\u003E\r\n\r\n\u003Cp\u003E@event_user_full_name updated the permissions of this @group_node_type to @group_permissions.\u003C\/p\u003E\r\n\r\n\u003Cp\u003EYou can consult \u003Ca href=\u0022!help_section_url\u0022 rel=\u0022nofollow\u0022\u003Ethis help section\u003C\/a\u003E to find out more about Group permissions and what they imply.\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cbr \/\u003E\r\nThe capacity4dev team\u003C\/p\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @group_admin_full_name,\u003C\/p\u003E\n\n\u003Cp\u003E@event_user_full_name updated the permissions of this @group_node_type to @group_permissions.\u003C\/p\u003E\n\n\u003Cp\u003EYou can consult \u003Ca href=\u0022!help_section_url\u0022 rel=\u0022nofollow\u0022\u003Ethis help section\u003C\/a\u003E to find out more about Group permissions and what they imply.\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cbr \/\u003E\nThe capacity4dev team\u003C\/p\u003E\n"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
';
}

/**
 * Retrieve object for MT35.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_mt35() {
  return '
  {
  "name" : "c4m_notify_promoted_member",
  "description" : "NOTIFY :: MT35 :: Group Admin Promoted",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Cp\u003EYou are now administrator for\u0026nbsp;@group_node_type: @group_node_title\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u0026nbsp;\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u0026nbsp;\u003C\/p\u003E\r\n",
        "format" : "mail"
      },
      {
        "value" : "\u003Cp\u003EDear @member_full_name,\u003C\/p\u003E\r\n\r\n\u003Cp\u003EYou are now an administrator for the @group_node_type \u003Ca href=\u0022!group_dashboard_url\u0022\u003E@group_node_title\u003C\/a\u003E\u003C\/p\u003E\r\n\r\n\u003Cp\u003EDiscover new functionalities and find out how you can administer this @group_node_type by consulting the following \u003Ca href=\u0022!help_section_url\u0022 rel=\u0022nofollow\u0022\u003Ehelp section\u003C\/a\u003E.\u003C\/p\u003E\r\n\r\n\u003Cp\u003Eif you have any questions about your role as administrator, please feel free to \u003Ca href=\u0022!event_user_message_url\u0022\u003Econtact me\u003C\/a\u003E.\u003C\/p\u003E\r\n\r\n\u003Cp\u003E@event_user_full_name\u003Cbr \/\u003E\r\n@group_node_type Administrator, @group_node_title\u003C\/p\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @member_full_name,\u003C\/p\u003E\n\n\u003Cp\u003EYou are now an administrator for the @group_node_type \u003Ca href=\u0022!group_dashboard_url\u0022\u003E@group_node_title\u003C\/a\u003E\u003C\/p\u003E\n\n\u003Cp\u003EDiscover new functionalities and find out how you can administer this @group_node_type by consulting the following \u003Ca href=\u0022!help_section_url\u0022 rel=\u0022nofollow\u0022\u003Ehelp section\u003C\/a\u003E.\u003C\/p\u003E\n\n\u003Cp\u003Eif you have any questions about your role as administrator, please feel free to \u003Ca href=\u0022!event_user_message_url\u0022\u003Econtact me\u003C\/a\u003E.\u003C\/p\u003E\n\n\u003Cp\u003E@event_user_full_name\u003Cbr \/\u003E\n@group_node_type Administrator, @group_node_title\u003C\/p\u003E\n"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for MT36.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_mt36() {
  return '
  {
  "name" : "c4m_group_admin_demoted",
  "description" : "NOTIFY :: MT36 :: Group Admin Demoted",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Cp\u003EYou are no longer administrator for @group_node_type: @group_node_title\u003C\/p\u003E\r\n\r\n\u003Cp\u003E \u003C\/p\u003E\r\n\r\n\u003Cp\u003E \u003C\/p\u003E\r\n",
        "format" : "mail"
      },
      {
        "value" : "\u003Cp\u003EDear @member_full_name,\u003C\/p\u003E\r\n\r\n\u003Cp\u003EYour administration rights for the @group_node_type \u003Ca href=\u0022!group_dashboard_url\u0022 rel=\u0022nofollow\u0022\u003E@group_node_title\u003C\/a\u003E have been removed.\u003C\/p\u003E\r\n\r\n\u003Cp\u003EIf you have any questions about your new role within this @group_node_type, please feel free to \u003Ca href=\u0022!event_user_message_url\u0022 rel=\u0022nofollow\u0022\u003Econtact me\u003C\/a\u003E.\u003C\/p\u003E\r\n\r\n\u003Cp\u003E@event_user_full_name\u003Cbr \/\u003E\r\n@group_node_type Administrator, @group_node_title\u003C\/p\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @member_full_name,\u003C\/p\u003E\n\n\u003Cp\u003EYour administration rights for the @group_node_type \u003Ca href=\u0022!group_dashboard_url\u0022 rel=\u0022nofollow\u0022\u003E@group_node_title\u003C\/a\u003E have been removed.\u003C\/p\u003E\n\n\u003Cp\u003EIf you have any questions about your new role within this @group_node_type, please feel free to \u003Ca href=\u0022!event_user_message_url\u0022 rel=\u0022nofollow\u0022\u003Econtact me\u003C\/a\u003E.\u003C\/p\u003E\n\n\u003Cp\u003E@event_user_full_name\u003Cbr \/\u003E\n@group_node_type Administrator, @group_node_title\u003C\/p\u003E\n"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for MT40.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_mt40() {
  return '
  {
  "name" : "c4m_notify_admins_membership_approved",
  "description" : "NOTIFY :: MT40 :: Group Membership Approved (to group admins)",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Cp\u003E@group_node_title:\u0026nbsp;a new member was accepted\u003C\/p\u003E\r\n",
        "format" : "mail"
      },
      {
        "value" : "\u003Cp\u003EDear @group_admin_full_name,\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E just approved the following user\u0027s membership request to join our @group_node_type \u003Cstrong\u003E\u003Ca href=\u0022!group_dashboard_url\u0022 rel=\u0022nofollow\u0022\u003E@group_node_title\u003C\/a\u003E\u003C\/strong\u003E at [site:name]:\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cstrong\u003E@related_user_full_name\u003C\/strong\u003E\u003C\/p\u003E\r\n\r\n\u003Cp\u003E@related_user_organisation, (@related_user_organisation_type)\u003C\/p\u003E\r\n\r\n\u003Cp\u003EBased in @related_user_country\u003C\/p\u003E\r\n\r\n\u003Cp\u003EExpertise: @related_user_expertise\u003C\/p\u003E\r\n\r\n\u003Cp\u003EView this member\u0027s \u003Ca href=\u0022!related_user_public_profile_url\u0022 rel=\u0022nofollow\u0022\u003Eprofile\u003C\/a\u003E at [site:name].\u003C\/p\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @group_admin_full_name,\u003C\/p\u003E\n\n\u003Cp\u003E\u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E just approved the following user\u0027s membership request to join our @group_node_type \u003Cstrong\u003E\u003Ca href=\u0022!group_dashboard_url\u0022 rel=\u0022nofollow\u0022\u003E@group_node_title\u003C\/a\u003E\u003C\/strong\u003E at [site:name]:\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cstrong\u003E@related_user_full_name\u003C\/strong\u003E\u003C\/p\u003E\n\n\u003Cp\u003E@related_user_organisation, (@related_user_organisation_type)\u003C\/p\u003E\n\n\u003Cp\u003EBased in @related_user_country\u003C\/p\u003E\n\n\u003Cp\u003EExpertise: @related_user_expertise\u003C\/p\u003E\n\n\u003Cp\u003EView this member\u0027s \u003Ca href=\u0022!related_user_public_profile_url\u0022 rel=\u0022nofollow\u0022\u003Eprofile\u003C\/a\u003E at [site:name].\u003C\/p\u003E\n"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for MT46.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_mt46() {
  return '
  {
  "name" : "c4m_group_content_updated",
  "description" : "SUBSCRIPTION :: MT46 :: Group Content Updated",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "module" : "c4m_message",
  "arguments" : null,
  "message_text" : { "und" : [
      {
        "value" : "\u003Cp\u003E@content_type_name @content_node_title from @group_node_title got updated\u003C\/p\u003E\r\n",
        "format" : "mail"
      },
      {
        "value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E updated the following @content_type_name: \u003Cstrong\u003E\u003Ca href=\u0022!content_node_url\u0022\u003E@content_node_title\u003C\/a\u003E\u003C\/strong\u003E\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cem\u003E@node_teaser_body \u003C\/em\u003E\u003Cbr \/\u003E\r\n\u003Ca href=\u0022!content_node_url\u0022\u003ERead more...\u003C\/a\u003E\u003C\/p\u003E\r\n\r\n\u003Cp\u003EYou\u0027re receiving this e-mail because you\u0027re subscribed to \u003Ca href=\u0022!group_dashboard_url\u0022\u003E@group_node_title\u003C\/a\u003E - if you no longer wish to receive notifications from this @group_node_type, please \u003Ca href=\u0022!unsubscribe_group_url\u0022\u003Eunsubscribe.\u003C\/a\u003E\u003C\/p\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\n\n\u003Cp\u003E\u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E updated the following @content_type_name: \u003Cstrong\u003E\u003Ca href=\u0022!content_node_url\u0022\u003E@content_node_title\u003C\/a\u003E\u003C\/strong\u003E\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cem\u003E@node_teaser_body \u003C\/em\u003E\u003Cbr \/\u003E\n\u003Ca href=\u0022!content_node_url\u0022\u003ERead more...\u003C\/a\u003E\u003C\/p\u003E\n\n\u003Cp\u003EYou\u0027re receiving this e-mail because you\u0027re subscribed to \u003Ca href=\u0022!group_dashboard_url\u0022\u003E@group_node_title\u003C\/a\u003E - if you no longer wish to receive notifications from this @group_node_type, please \u003Ca href=\u0022!unsubscribe_group_url\u0022\u003Eunsubscribe.\u003C\/a\u003E\u003C\/p\u003E\n"
      },
      {
        "value" : "\u003Ca href=\u0022!content_node_url\u0022\u003E@content_node_title\u003C\/a\u003E, @content_type_name updated by \u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E",
        "format" : "mail",
        "safe_value" : "\u003Ca href=\u0022!content_node_url\u0022\u003E@content_node_title\u003C\/a\u003E, @content_type_name updated by \u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E"
      }
    ]
  },
  "message_header" : { "und" : [
      {
        "value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\r\n  \r\n\u003Cp\u003EDiscover the latest updates you\u0027re subscribed to!\u003C\/p\u003E",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\n  \n\u003Cp\u003EDiscover the latest updates you\u0027re subscribed to!\u003C\/p\u003E"
      }
    ]
  },
  "message_footer" : { "und" : [
      {
        "value" : "\u003Cp\u003EYou are receiving these updates because you are subscribed to capacity4dev notification message(s) - to manage these, update your \u003Ca href=\u0022!user_settings_url\u0022\u003Enotification settings\u003C\/a\u003E.\u003C\/p\u003E",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EYou are receiving these updates because you are subscribed to capacity4dev notification message(s) - to manage these, update your \u003Ca href=\u0022!user_settings_url\u0022\u003Enotification settings\u003C\/a\u003E.\u003C\/p\u003E"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for MT48.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_mt48() {
  return '
  {
  "name" : "c4m_notify_user_membership_pending",
  "description" : "NOTIFY :: MT48 :: Group Membership Requested (to requester)",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Cp\u003EYour request to join\u0026nbsp;@group_node_title\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u0026nbsp;\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u0026nbsp;\u003C\/p\u003E\r\n",
        "format" : "mail"
      },
      {
        "value" : "\u003Cp\u003EDear @member_full_name,\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cbr \/\u003E\r\nThank you for requesting membership to @group_node_title at [site:name].\u003C\/p\u003E\r\n\r\n\u003Cp\u003EYour membership is currently waiting to be approved by one of the @group_node_type\u2019s administrators, and should be processed shortly.\u003C\/p\u003E\r\n\r\n\u003Cp\u003EIf you have any questions, please feel free to \u003Ca href=\u0022mailto:capacity4dev@ec.europa.eu\u0022\u003Econtact us\u003C\/a\u003E; we will be happy to help.\u003C\/p\u003E\r\n\r\n\u003Cp\u003EThe [site:name] team\u003C\/p\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @member_full_name,\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cbr \/\u003E\nThank you for requesting membership to @group_node_title at [site:name].\u003C\/p\u003E\n\n\u003Cp\u003EYour membership is currently waiting to be approved by one of the @group_node_type\u2019s administrators, and should be processed shortly.\u003C\/p\u003E\n\n\u003Cp\u003EIf you have any questions, please feel free to \u003Ca href=\u0022mailto:capacity4dev@ec.europa.eu\u0022\u003Econtact us\u003C\/a\u003E; we will be happy to help.\u003C\/p\u003E\n\n\u003Cp\u003EThe [site:name] team\u003C\/p\u003E\n"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for MT49.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_mt49() {
  return '
  {
  "name" : "c4m_group_requested",
  "description" : "NOTIFY :: MT49 :: Group Requested (to requester)",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Cp\u003EYour @group_node_type\u0026nbsp;request on [site:name]\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u0026nbsp;\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u0026nbsp;\u003C\/p\u003E\r\n",
        "format" : "mail"
      },
      {
        "value" : "\u003Cp\u003EDear @group_owner_full_name,\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cbr \/\u003E\r\nThank you for requesting the creation of the following @group_node_type: @group_node_title at [site:name].\u003C\/p\u003E\r\n\r\n\u003Cp\u003EYour request is currently pending review by one of the site\u0027s administrators and should be treated shortly.\u003C\/p\u003E\r\n\r\n\u003Cp\u003EIf you have any questions, please feel free to \u003Ca href=\u0022mailto:capacity4dev@ec.europa.eu\u0022 rel=\u0022nofollow\u0022\u003Econtact us\u003C\/a\u003E.\u003C\/p\u003E\r\n\r\n\u003Cp\u003EThe [site:name] team\u003C\/p\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @group_owner_full_name,\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cbr \/\u003E\nThank you for requesting the creation of the following @group_node_type: @group_node_title at [site:name].\u003C\/p\u003E\n\n\u003Cp\u003EYour request is currently pending review by one of the site\u0027s administrators and should be treated shortly.\u003C\/p\u003E\n\n\u003Cp\u003EIf you have any questions, please feel free to \u003Ca href=\u0022mailto:capacity4dev@ec.europa.eu\u0022 rel=\u0022nofollow\u0022\u003Econtact us\u003C\/a\u003E.\u003C\/p\u003E\n\n\u003Cp\u003EThe [site:name] team\u003C\/p\u003E\n"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for MT51.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_mt51() {
  return '
  {
  "name" : "c4m_notify_editors_group_content_updated",
  "description" : "SUBSCRIPTION :: MT51 :: Your Content Edited by Admin (to original author/editors)",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Cp\u003EYour @content_type_name @content_node_title was updated\u003C\/p\u003E\r\n",
        "format" : "mail"
      },
      {
        "value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E edited the following @content_type_name: \u003Cstrong\u003E\u003Ca href=\u0022!content_node_url\u0022\u003E@content_node_title\u003C\/a\u003E\u003C\/strong\u003E\u003C\/p\u003E\r\n\r\n\u003Cp\u003ETake a look at the latest changes by accessing this @content_type_name\u003Cbr \/\u003E\r\n\u003Ca href=\u0022!content_node_url\u0022\u003ERead more...\u003C\/a\u003E\u003C\/p\u003E\r\n\r\n\u003Cp\u003EYou\u0027re receiving this e-mail because you\u0027re subscribed to the @content_type_name \u003Ca href=\u0022!content_node_url\u0022\u003E@content_node_title\u003C\/a\u003E\u0026nbsp;- if you no longer wish to receive notifications from this @content_type_name, please \u003Ca href=\u0022!unsubscribe_content_url\u0022\u003Eunsubscribe.\u003C\/a\u003E\u003C\/p\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\n\n\u003Cp\u003E\u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E edited the following @content_type_name: \u003Cstrong\u003E\u003Ca href=\u0022!content_node_url\u0022\u003E@content_node_title\u003C\/a\u003E\u003C\/strong\u003E\u003C\/p\u003E\n\n\u003Cp\u003ETake a look at the latest changes by accessing this @content_type_name\u003Cbr \/\u003E\n\u003Ca href=\u0022!content_node_url\u0022\u003ERead more...\u003C\/a\u003E\u003C\/p\u003E\n\n\u003Cp\u003EYou\u0027re receiving this e-mail because you\u0027re subscribed to the @content_type_name \u003Ca href=\u0022!content_node_url\u0022\u003E@content_node_title\u003C\/a\u003E\u0026nbsp;- if you no longer wish to receive notifications from this @content_type_name, please \u003Ca href=\u0022!unsubscribe_content_url\u0022\u003Eunsubscribe.\u003C\/a\u003E\u003C\/p\u003E\n"
      },
      {
        "value" : "\u003Ca href=\u0022!content_node_url\u0022\u003E@content_node_title\u003C\/a\u003E, @content_type_name was updated by \u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E",
        "format" : "mail",
        "safe_value" : "\u003Ca href=\u0022!content_node_url\u0022\u003E@content_node_title\u003C\/a\u003E, @content_type_name was updated by \u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E"
      }
    ]
  },
  "message_header" : { "und" : [
      {
        "value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\r\n  \r\n\u003Cp\u003EDiscover the latest updates you\u0027re subscribed to!\u003C\/p\u003E",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\n  \n\u003Cp\u003EDiscover the latest updates you\u0027re subscribed to!\u003C\/p\u003E"
      }
    ]
  },
  "message_footer" : { "und" : [
      {
        "value" : "\u003Cp\u003EYou are receiving these updates because you are subscribed to capacity4dev notification message(s) - to manage these, update your \u003Ca href=\u0022!user_settings_url\u0022\u003Enotification settings\u003C\/a\u003E.\u003C\/p\u003E",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EYou are receiving these updates because you are subscribed to capacity4dev notification message(s) - to manage these, update your \u003Ca href=\u0022!user_settings_url\u0022\u003Enotification settings\u003C\/a\u003E.\u003C\/p\u003E"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for MT53.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_mt53() {
  return '
  {
  "name" : "c4m_new_content_share_published",
  "description" : "SUBSCRIPTION :: MT53 :: Group Content Shared",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Cp\u003ENew @content_type_name was shared to @group_node_title\u003C\/p\u003E\r\n",
        "format" : "mail"
      },
      {
        "value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E @event_action the following @content_type_name from \u003Ca href=\u0022!original_group_dashboard_url\u0022\u003E@original_group_node_title\u003C\/a\u003E: \u003Cstrong\u003E\u003Ca href=\u0022!content_node_url\u0022\u003E@content_node_title\u003C\/a\u003E\u003C\/strong\u003E.\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cem\u003E@node_teaser_body\u003C\/em\u003E\u003Cbr \/\u003E\r\n\u003Ca href=\u0022!content_node_url\u0022\u003ERead more...\u003C\/a\u003E\u003C\/p\u003E\r\n\r\n\u003Cp\u003EYou\u0027re receiving this e-mail because you\u0027re subscribed to \u003Ca href=\u0022!group_dashboard_url\u0022\u003E@group_node_title\u003C\/a\u003E - if you no longer wish to receive notifications from this @group_node_type, please \u003Ca href=\u0022!unsubscribe_group_url\u0022\u003Eunsubscribe.\u003C\/a\u003E\u003C\/p\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\n\n\u003Cp\u003E\u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E @event_action the following @content_type_name from \u003Ca href=\u0022!original_group_dashboard_url\u0022\u003E@original_group_node_title\u003C\/a\u003E: \u003Cstrong\u003E\u003Ca href=\u0022!content_node_url\u0022\u003E@content_node_title\u003C\/a\u003E\u003C\/strong\u003E.\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cem\u003E@node_teaser_body\u003C\/em\u003E\u003Cbr \/\u003E\n\u003Ca href=\u0022!content_node_url\u0022\u003ERead more...\u003C\/a\u003E\u003C\/p\u003E\n\n\u003Cp\u003EYou\u0027re receiving this e-mail because you\u0027re subscribed to \u003Ca href=\u0022!group_dashboard_url\u0022\u003E@group_node_title\u003C\/a\u003E - if you no longer wish to receive notifications from this @group_node_type, please \u003Ca href=\u0022!unsubscribe_group_url\u0022\u003Eunsubscribe.\u003C\/a\u003E\u003C\/p\u003E\n"
      },
      {
        "value" : "\u003Ca href=\u0022!content_node_url\u0022\u003E@content_node_title\u003C\/a\u003E, @content_type_name was shared to \u003Ca href=\u0022!group_dashboard_url\u0022\u003E@group_node_title\u003C\/a\u003E by \u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E",
        "format" : "mail",
        "safe_value" : "\u003Ca href=\u0022!content_node_url\u0022\u003E@content_node_title\u003C\/a\u003E, @content_type_name was shared to \u003Ca href=\u0022!group_dashboard_url\u0022\u003E@group_node_title\u003C\/a\u003E by \u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E"
      }
    ]
  },
  "message_header" : { "und" : [
      {
        "value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\r\n  \r\n\u003Cp\u003EDiscover the latest updates you\u0027re subscribed to!\u003C\/p\u003E",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\n  \n\u003Cp\u003EDiscover the latest updates you\u0027re subscribed to!\u003C\/p\u003E"
      }
    ]
  },
  "message_footer" : { "und" : [
      {
        "value" : "\u003Cp\u003EYou are receiving these updates because you are subscribed to capacity4dev notification message(s) - to manage these, update your \u003Ca href=\u0022!user_settings_url\u0022\u003Enotification settings\u003C\/a\u003E.\u003C\/p\u003E",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EYou are receiving these updates because you are subscribed to capacity4dev notification message(s) - to manage these, update your \u003Ca href=\u0022!user_settings_url\u0022\u003Enotification settings\u003C\/a\u003E.\u003C\/p\u003E"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for MT54.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_mt54() {
  return '
  {
  "name" : "c4m_notify_subscribe_content_of_interest",
  "description" : "SUBSCRIPTION :: MT54 :: Content Published about Term of Interest",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Cp\u003ENew @content_type_name about @term_name\u003C\/p\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003ENew @content_type_name about @term_name\u003C\/p\u003E\n"
      },
      {
        "value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E @event_action the following @content_type_name: \u003Cstrong\u003E\u003Ca href=\u0022!content_node_url\u0022\u003E@content_node_title\u003C\/a\u003E\u003C\/strong\u003E\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cem\u003E@node_teaser_body \u003C\/em\u003E\u003Cbr \/\u003E\r\n\u003Ca href=\u0022!content_node_url\u0022\u003ERead more...\u003C\/a\u003E\u003C\/p\u003E\r\n\r\n\u003Cp\u003EYou\u0027re receiving this e-mail because you\u0027re subscribed to \u003Cstrong\u003E@term_name\u003C\/strong\u003E - if you no longer wish to receive notifications related to this topic, please \u003Ca href=\u0022!unsubscribe_term_url\u0022\u003Eunsubscribe.\u003C\/a\u003E\u003C\/p\u003E",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\n\n\u003Cp\u003E\u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E @event_action the following @content_type_name: \u003Cstrong\u003E\u003Ca href=\u0022!content_node_url\u0022\u003E@content_node_title\u003C\/a\u003E\u003C\/strong\u003E\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cem\u003E@node_teaser_body \u003C\/em\u003E\u003Cbr \/\u003E\n\u003Ca href=\u0022!content_node_url\u0022\u003ERead more...\u003C\/a\u003E\u003C\/p\u003E\n\n\u003Cp\u003EYou\u0027re receiving this e-mail because you\u0027re subscribed to \u003Cstrong\u003E@term_name\u003C\/strong\u003E - if you no longer wish to receive notifications related to this topic, please \u003Ca href=\u0022!unsubscribe_term_url\u0022\u003Eunsubscribe.\u003C\/a\u003E\u003C\/p\u003E"
      },
      {
        "value" : "\u003Ca href=\u0022!content_node_url\u0022\u003E@content_node_title\u003C\/a\u003E, @content_type_name @event_action by \u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E",
        "format" : "mail",
        "safe_value" : "\u003Ca href=\u0022!content_node_url\u0022\u003E@content_node_title\u003C\/a\u003E, @content_type_name @event_action by \u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E"
      }
    ]
  },
  "message_header" : { "und" : [
      {
        "value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\r\n  \r\n\u003Cp\u003EDiscover the latest updates you\u0027re subscribed to!\u003C\/p\u003E",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\n  \n\u003Cp\u003EDiscover the latest updates you\u0027re subscribed to!\u003C\/p\u003E"
      }
    ]
  },
  "message_footer" : { "und" : [
      {
        "value" : "\u003Cp\u003EYou are receiving these updates because you are subscribed to capacity4dev notification message(s) - to manage these, update your \u003Ca href=\u0022!user_settings_url\u0022\u003Enotification settings\u003C\/a\u003E.\u003C\/p\u003E",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EYou are receiving these updates because you are subscribed to capacity4dev notification message(s) - to manage these, update your \u003Ca href=\u0022!user_settings_url\u0022\u003Enotification settings\u003C\/a\u003E.\u003C\/p\u003E"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for MT55.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_mt55() {
  return '
  {
  "name" : "c4m_content_updated",
  "description" : "SUBSCRIPTION :: MT55 :: Content Updated",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "module" : "c4m_message",
  "arguments" : null,
  "message_text" : { "und" : [
      {
        "value" : "\u003Cp\u003E@content_type_name @content_node_title got updated\u003C\/p\u003E\r\n",
        "format" : "filtered_html"
      },
      {
        "value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E updated the following @content_type_name: \u003Cstrong\u003E\u003Ca href=\u0022!content_node_url\u0022\u003E@content_node_title\u003C\/a\u003E\u003C\/strong\u003E\u003C\/p\u003E\r\n\r\n\u003Cp\u003E\u003Cem\u003E@node_teaser_body \u003C\/em\u003E\u003Cbr \/\u003E\r\n\u003Ca href=\u0022!content_node_url\u0022\u003ERead more...\u003C\/a\u003E\u003C\/p\u003E\r\n\r\n\u003Cp\u003EYou\u0027re receiving this e-mail because you\u0027re subscribed to \u003Ca href=\u0022!content_node_url\u0022\u003E@content_node_title\u003C\/a\u003E - if you no longer wish to receive notifications from this @content_type_name, please \u003Ca href=\u0022!unsubscribe_url\u0022\u003Eunsubscribe.\u003C\/a\u003E\u003C\/p\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Cp\u003EDear @user_full_name,\u003C\/p\u003E\n\n\u003Cp\u003E\u003Ca href=\u0022!event_user_url\u0022 rel=\u0022nofollow\u0022\u003E@event_user_full_name\u003C\/a\u003E updated the following @content_type_name: \u003Cstrong\u003E\u003Ca href=\u0022!content_node_url\u0022\u003E@content_node_title\u003C\/a\u003E\u003C\/strong\u003E\u003C\/p\u003E\n\n\u003Cp\u003E\u003Cem\u003E@node_teaser_body \u003C\/em\u003E\u003Cbr \/\u003E\n\u003Ca href=\u0022!content_node_url\u0022\u003ERead more...\u003C\/a\u003E\u003C\/p\u003E\n\n\u003Cp\u003EYou\u0027re receiving this e-mail because you\u0027re subscribed to \u003Ca href=\u0022!content_node_url\u0022\u003E@content_node_title\u003C\/a\u003E - if you no longer wish to receive notifications from this @content_type_name, please \u003Ca href=\u0022!unsubscribe_url\u0022\u003Eunsubscribe.\u003C\/a\u003E\u003C\/p\u003E\n"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for Log message 1.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_log1() {
  return '
  {
  "name" : "c4m_log_group_state_change",
  "description" : "LOG :: Group State Change",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "@event_user_full_name changed state of @group_node_type @group_node_title from @from_state to @to_state.\r\nComment: @admin_comment",
        "format" : "mail",
        "safe_value" : "@event_user_full_name changed state of @group_node_type @group_node_title from @from_state to @to_state.\nComment: @admin_comment"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for Activity Stream item 1.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_as1() {
  return '
  {
  "name" : "c4m_insert__comment",
  "description" : "STREAM :: Comment Insert/Update",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Cdiv class=\u0022activity-stream--operator\u0022\u003E!icon [message:user:url-with-name] commented on @node_type | !date\u003C\/div\u003E\r\n\r\n\u003Ch2\u003E\u003Ca href=\u0022[message:field-comment:url]\u0022\u003E[message:field-node:title]\u003C\/a\u003E\u003C\/h2\u003E\r\n\r\n\u003Cdiv class=\u0022activity-stream--content\u0022\u003E!content\u003C\/div\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Cdiv class=\u0022activity-stream--operator\u0022\u003E!icon [message:user:url-with-name] commented on @node_type | !date\u003C\/div\u003E\n\n\u003Ch2\u003E\u003Ca href=\u0022[message:field-comment:url]\u0022\u003E[message:field-node:title]\u003C\/a\u003E\u003C\/h2\u003E\n\n\u003Cdiv class=\u0022activity-stream--content\u0022\u003E!content\u003C\/div\u003E\n"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for Activity Stream item 2.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_as2() {
  return '
  {
  "name" : "c4m_insert__node__article",
  "description" : "STREAM :: Article Insert/Update",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Ch2\u003E\u003Ca href=\u0022[message:field-node:url]\u0022\u003E[message:field-node:title]\u003C\/a\u003E\u003C\/h2\u003E\r\n\r\n\u003Cdiv class=\u0022activity-stream--operator\u0022\u003E!icon [message:user:url-with-name] @operation | !date\u003C\/div\u003E\r\n\r\n\u003Cdiv class=\u0022activity-stream--content\u0022\u003E!content\u003C\/div\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Ch2\u003E\u003Ca href=\u0022[message:field-node:url]\u0022\u003E[message:field-node:title]\u003C\/a\u003E\u003C\/h2\u003E\n\n\u003Cdiv class=\u0022activity-stream--operator\u0022\u003E!icon [message:user:url-with-name] @operation | !date\u003C\/div\u003E\n\n\u003Cdiv class=\u0022activity-stream--content\u0022\u003E!content\u003C\/div\u003E\n"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for Activity Stream item 3.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_as3() {
  return '
  {
  "name" : "c4m_insert__node__discussion",
  "description" : "STREAM :: Discussion Insert/Update",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Ch2\u003E\u003Ca href=\u0022[message:field-node:url]\u0022\u003E[message:field-node:title]\u003C\/a\u003E\u003C\/h2\u003E\r\n\r\n\u003Cdiv class=\u0022activity-stream--operator\u0022\u003E!icon [message:user:url-with-name] @operation | !date\u003C\/div\u003E\r\n\r\n\u003Cdiv class=\u0022activity-stream--content\u0022\u003E!content\u003C\/div\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Ch2\u003E\u003Ca href=\u0022[message:field-node:url]\u0022\u003E[message:field-node:title]\u003C\/a\u003E\u003C\/h2\u003E\n\n\u003Cdiv class=\u0022activity-stream--operator\u0022\u003E!icon [message:user:url-with-name] @operation | !date\u003C\/div\u003E\n\n\u003Cdiv class=\u0022activity-stream--content\u0022\u003E!content\u003C\/div\u003E\n"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for Activity Stream item 4.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_as4() {
  return '
  {
  "name" : "c4m_insert__node__document",
  "description" : "STREAM :: Document Insert/Update",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "module" : "c4m_message",
  "arguments" : null,
  "message_text" : { "und" : [
      {
        "value" : "\u003Ch2\u003E\u003Ca href=\u0022[message:field-node:url]\u0022\u003E[message:field-node:title]\u003C\/a\u003E\u003C\/h2\u003E\r\n\r\n\u003Cdiv class=\u0022activity-stream--operator\u0022\u003E!icon [message:user:url-with-name] @operation | !date\u003C\/div\u003E\r\n\r\n\u003Cdiv class=\u0022activity-stream--content\u0022\u003E!content\u003C\/div\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Ch2\u003E\u003Ca href=\u0022[message:field-node:url]\u0022\u003E[message:field-node:title]\u003C\/a\u003E\u003C\/h2\u003E\n\n\u003Cdiv class=\u0022activity-stream--operator\u0022\u003E!icon [message:user:url-with-name] @operation | !date\u003C\/div\u003E\n\n\u003Cdiv class=\u0022activity-stream--content\u0022\u003E!content\u003C\/div\u003E\n"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for Activity Stream item 5.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_as5() {
  return '
  {
  "name" : "c4m_insert__node__event",
  "description" : "STREAM :: Event Insert/Update",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Ch2\u003E\u003Ca href=\u0022[message:field-node:url]\u0022\u003E[message:field-node:title]\u003C\/a\u003E\u003C\/h2\u003E\r\n\r\n\u003Cdiv class=\u0022activity-stream--operator\u0022\u003E!icon [message:user:url-with-name] @operation | !date\u003C\/div\u003E\r\n\r\n\u003Cdiv class=\u0022activity-stream--content\u0022\u003E!content\u003C\/div\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Ch2\u003E\u003Ca href=\u0022[message:field-node:url]\u0022\u003E[message:field-node:title]\u003C\/a\u003E\u003C\/h2\u003E\n\n\u003Cdiv class=\u0022activity-stream--operator\u0022\u003E!icon [message:user:url-with-name] @operation | !date\u003C\/div\u003E\n\n\u003Cdiv class=\u0022activity-stream--content\u0022\u003E!content\u003C\/div\u003E\n"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for Activity Stream item 6.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_as6() {
  return '
  {
  "name" : "c4m_insert__node__news",
  "description" : "STREAM :: News Insert/Update",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Ch2\u003E\u003Ca href=\u0022[message:field-node:url]\u0022\u003E[message:field-node:title]\u003C\/a\u003E\u003C\/h2\u003E\r\n\r\n\u003Cdiv class=\u0022activity-stream--operator\u0022\u003E!icon [message:user:url-with-name] @operation | !date\u003C\/div\u003E\r\n\r\n\u003Cdiv class=\u0022activity-stream--content\u0022\u003E!content\u003C\/div\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Ch2\u003E\u003Ca href=\u0022[message:field-node:url]\u0022\u003E[message:field-node:title]\u003C\/a\u003E\u003C\/h2\u003E\n\n\u003Cdiv class=\u0022activity-stream--operator\u0022\u003E!icon [message:user:url-with-name] @operation | !date\u003C\/div\u003E\n\n\u003Cdiv class=\u0022activity-stream--content\u0022\u003E!content\u003C\/div\u003E\n"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for Activity Stream item 7.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_as7() {
  return '
  {
  "name" : "c4m_insert__node__photo",
  "description" : "STREAM :: Photo Insert/Update",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Ch2\u003E\u003Ca href=\u0022[message:field-node:url]\u0022\u003E[message:field-node:title]\u003C\/a\u003E\u003C\/h2\u003E\r\n\r\n\u003Cdiv class=\u0022activity-stream--operator\u0022\u003E!icon [message:user:url-with-name] @operation @photoalbum | !date\u003C\/div\u003E\r\n\r\n\u003Cdiv class=\u0022activity-stream--content\u0022\u003E!content\u003C\/div\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Ch2\u003E\u003Ca href=\u0022[message:field-node:url]\u0022\u003E[message:field-node:title]\u003C\/a\u003E\u003C\/h2\u003E\n\n\u003Cdiv class=\u0022activity-stream--operator\u0022\u003E!icon [message:user:url-with-name] @operation @photoalbum | !date\u003C\/div\u003E\n\n\u003Cdiv class=\u0022activity-stream--content\u0022\u003E!content\u003C\/div\u003E\n"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for Activity Stream item 8.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_as8() {
  return '
  {
  "name" : "c4m_insert__node__photoalbum",
  "description" : "STREAM :: Photo Album Insert/Update",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Ch2\u003E\u003Ca href=\u0022[message:field-node:url]\u0022\u003E[message:field-node:title]\u003C\/a\u003E\u003C\/h2\u003E\r\n\r\n\u003Cdiv class=\u0022activity-stream--operator\u0022\u003E!icon [message:user:url-with-name] @operation | !date\u003C\/div\u003E\r\n\r\n\u003Cdiv class=\u0022activity-stream--content\u0022\u003E!content\u003C\/div\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Ch2\u003E\u003Ca href=\u0022[message:field-node:url]\u0022\u003E[message:field-node:title]\u003C\/a\u003E\u003C\/h2\u003E\n\n\u003Cdiv class=\u0022activity-stream--operator\u0022\u003E!icon [message:user:url-with-name] @operation | !date\u003C\/div\u003E\n\n\u003Cdiv class=\u0022activity-stream--content\u0022\u003E!content\u003C\/div\u003E\n"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for Activity Stream item 9.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_as9() {
  return '
  {
  "name" : "c4m_insert__node__share",
  "description" : "STREAM :: Share Insert/Update",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Cdiv class=\u0022activity-stream--operator\u0022\u003E!icon [message:user:url-with-name] @operation \u003Cspan class=\u0022share__group-info\u0022\u003Eto the !group\u003C\/span\u003E\u003C\/div\u003E\r\n\r\n\u003Cdiv class=\u0022activity-stream--content\u0022\u003E!content\u003C\/div\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Cdiv class=\u0022activity-stream--operator\u0022\u003E!icon [message:user:url-with-name] @operation \u003Cspan class=\u0022share__group-info\u0022\u003Eto the !group\u003C\/span\u003E\u003C\/div\u003E\n\n\u003Cdiv class=\u0022activity-stream--content\u0022\u003E!content\u003C\/div\u003E\n"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}

/**
 * Retrieve object for Activity Stream item 10.
 *
 * @return string
 *   Serialized message entity object.
 */
function _c4m_message_get_messages_as10() {
  return '
  {
  "name" : "c4m_insert__node__wiki_page",
  "description" : "STREAM :: Wiki Page Insert/Update",
  "argument_keys" : [],
  "argument" : [],
  "category" : "message_type",
  "data" : {
    "token options" : { "clear" : 0 },
    "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
  },
  "language" : "",
  "arguments" : null,
  "module" : "c4m_message",
  "message_text" : { "und" : [
      {
        "value" : "\u003Ch2\u003E\u003Ca href=\u0022[message:field-node:url]\u0022\u003E[message:field-node:title]\u003C\/a\u003E\u003C\/h2\u003E\r\n\r\n\u003Cdiv class=\u0022activity-stream--operator\u0022\u003E!icon [message:user:url-with-name] @operation | !date\u003C\/div\u003E\r\n\r\n\u003Cdiv class=\u0022activity-stream--content\u0022\u003E!content\u003C\/div\u003E\r\n",
        "format" : "mail",
        "safe_value" : "\u003Ch2\u003E\u003Ca href=\u0022[message:field-node:url]\u0022\u003E[message:field-node:title]\u003C\/a\u003E\u003C\/h2\u003E\n\n\u003Cdiv class=\u0022activity-stream--operator\u0022\u003E!icon [message:user:url-with-name] @operation | !date\u003C\/div\u003E\n\n\u003Cdiv class=\u0022activity-stream--content\u0022\u003E!content\u003C\/div\u003E\n"
      }
    ]
  },
  "entity_type" : "message_type",
  "rdf_mapping" : []
}
  ';
}
