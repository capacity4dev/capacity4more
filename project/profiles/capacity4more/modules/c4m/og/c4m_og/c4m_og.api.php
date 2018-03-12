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
  return [
    'c4m_og' => [
      'name' => t('Organic Groups'),
      'description' => t('Organic Group features.'),
      'machine_name' => 'c4m_og',
      'weight' => 0,
      'default' => TRUE,
      'group_types' => ['group', 'project'],
      'content_types' => ['group', 'project'],
    ],
  ];
}

/**
 * Custom actions before deleting the merged group.
 *
 * @param int $group_id
 *   Merged group.
 * @param int $target_group_id
 *   Target group.
 */
function hook_c4m_group_merge($group_id, $target_group_id) {
}
