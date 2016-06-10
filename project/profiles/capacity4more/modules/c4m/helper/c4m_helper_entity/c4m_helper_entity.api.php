<?php
/**
 * @file
 * Hooks provided by the capacity4more Entity helper module.
 */

/**
 * Define the label info for a content type (and its subtypes).
 *
 * You need to implement the hook_c4m_helper_entity_label_info() hook to define
 * all label info provided.
 *
 * @return array
 *   An array of content types (machine name of the bundle or the subtype)
 *   defined in an array. Each defined type can provide:
 *   - article ("a", "an"...)
 *   - singular ("learning event", "info", "document"...)
 *   - plural ("learning events", "info's", "documents"...)
 *   - insert action ("posted", "started", "commented on"...)
 *   - update action ("updated"...)
 *   - icon ("fa-info-circle", "fa-lightbulb"...)
 */
function hook_c4m_content_share_fields_info() {
  return array(
    'discussion' => array(
      'article' => 'a',
      'singular' => 'discussion',
      'plural' => 'discussions',
      'insert action' => 'started',
      'update action' => 'updated',
      'icon' => 'fa-comments',
    ),
    'event-learning' => array(
      'article' => 'a',
      'singular' => 'learning event',
      'plural' => 'learning events',
      'insert action' => 'posted',
      'update action' => 'updated',
      'icon' => 'fa-university',
    ),
  );
}
