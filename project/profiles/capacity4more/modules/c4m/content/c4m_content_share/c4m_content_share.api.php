<?php

/**
 * @file
 * Hooks provided by the capacity4more Organic Group Functionality module.
 */

/**
 * Define the fields a shared content item should inherit.
 *
 * You need to implement the hook_c4m_share_content_fields_info() hook to define
 * what features should be made available.
 *
 * @return array
 *   An array of content types (machine name of the bundle) with all fields
 *   defined in an array. Each defined field will be mapped one-on-one.
 */
function hook_c4m_content_share_fields_info() {
  return array(
    'discussion' => array(
      'type',
      'c4m_discussion_type',
    ),
  );
}
