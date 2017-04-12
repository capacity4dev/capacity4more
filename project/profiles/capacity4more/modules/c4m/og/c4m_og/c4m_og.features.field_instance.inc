<?php
/**
 * @file
 * c4m_og.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function c4m_og_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'og_membership-og_membership_type_default-c4m_og_total_comments'.
  $field_instances['og_membership-og_membership_type_default-c4m_og_total_comments'] = array(
    'bundle' => 'og_membership_type_default',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'og_membership',
    'field_name' => 'c4m_og_total_comments',
    'label' => 'Total comments',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'og_membership-og_membership_type_default-c4m_og_total_posts'.
  $field_instances['og_membership-og_membership_type_default-c4m_og_total_posts'] = array(
    'bundle' => 'og_membership_type_default',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'og_membership',
    'field_name' => 'c4m_og_total_posts',
    'label' => 'Total posts',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Total comments');
  t('Total posts');

  return $field_instances;
}
