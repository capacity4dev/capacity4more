<?php

/**
 * @file
 * API Example of the hooks in the c4m_message_digeset module.
 */

/**
 * Implementation of the c4m_message_digest_grouping_info hook.
 *
 * @return array
 *   Callbacks grouped by message_type (array key).
 */
function hook_c4m_message_digest_grouping_info() {
  return [
    'c4m_new_content_share_published' => [
      'title_callback' => 'c4m_message_digest_group_title',
      'title_callback_argument_field' => 'field_group_node',
    ],
  ];
}
