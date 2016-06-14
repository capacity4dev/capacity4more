<?php
/**
 * @file
 * Hooks provided by the capacity4more Organic Group Functionality module.
 */

/**
 * Define the features available for groups.
 *
 * You need to implement the hook_c4m_og_feature() hook to define
 * what features should be made available.
 *
 * @return array
 *   An array of features and their settings. The keys are used to identify
 *   the available features.
 *   Each feature has the following data:
 *   - name : The name of the feature.
 *   - description : The description of the feature.
 *   - machine_name : The machine name of the feature.
 *   - weight : The weight used to sort the feature in listings.
 *   - default : The default state of the feature.
 *   - group_types : An array of group types the feature is available for.
 *   - content_types : An array of enabled content types.
 */
function hook_c4m_og_feature_info() {
  return array(
    'c4m_og' => array(
      'name' => t('Organic Groups'),
      'description' => t('Organic Group features.'),
      'machine_name' => 'c4m_og',
      'weight' => 0,
      'default' => TRUE,
      'group_types' => array('group', 'project'),
      'content_types' => array('group', 'project'),
    ),
  );
}

/**
 * Define the available group metrics.
 *
 * You need to implement the hook_c4m_og_metrics_info() hook to define
 * what metrics should be made available.
 *
 * @return array
 *   An array of metric lists and their settings.
 *
 *   Each list has the following data:
 *   - type:
 *       The identifier of the metrics list.
 *   - callback:
 *       The callback to retrieve the metrics.
 *   - arguments:
 *       The arguments to be passed to the callback function.
 *   - weight:
 *       The weight used to sort the lists.
 */
function hook_c4m_og_metrics_info() {
  return array(
    'c4m_og' => array(
      'type'      => 'c4m_og_my_metric',
      'callback'  => 'c4m_og_my_callback_function',
      'arguments' => array('my_first_argument', 'my_second_argument'),
      'weight'    => 0,
    ),
  );
}
