<?php
/**
 * @file
 * Hooks provided by the C4M Helper Entity module.
 */

/**
 * Define the available group metrics.
 *
 * You need to implement the hook_c4m_helper_entity_metrics_info() hook to
 * define what metrics should be made available.
 *
 * @return array
 *   An array of metric lists and their settings.
 *
 *   Each list has the following data:
 *   - type:
 *       The identifier of the metrics list.
 *   - context:
 *       The context of the metrics.
 *       Can be either "global" or "group", defaults to "global".
 *   - callback:
 *       The callback to retrieve the metrics.
 *   - arguments:
 *       The arguments to be passed to the callback function.
 *   - weight:
 *       The weight used to sort the lists.
 */
function hook_c4m_helper_entity_metrics_info() {
  return array(
    'c4m_helper_entity' => array(
      'type'      => 'c4m_helper_entity_my_metric',
      'context'   => 'global',
      'callback'  => 'c4m_helper_entity_my_callback_function',
      'arguments' => array('my_first_argument', 'my_second_argument'),
      'weight'    => 0,
    ),
  );
}

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
function hook_c4m_helper_entity_label_info() {
  return array(
    'discussion' => array(
      'article' => t('a'),
      'singular' => t('discussion'),
      'plural' => t('discussions'),
      'insert action' => t('started a new discussion'),
      'update action' => t('updated the discussion'),
      'icon' => 'fa-comments',
    ),
    'event-learning' => array(
      'article' => t('a'),
      'singular' => t('learning event'),
      'plural' => t('learning events'),
      'insert action' => t('posted a new learning event'),
      'update action' => t('updated the learning event'),
      'icon' => 'fa-university',
    ),
  );
}
