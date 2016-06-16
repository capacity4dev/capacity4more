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
