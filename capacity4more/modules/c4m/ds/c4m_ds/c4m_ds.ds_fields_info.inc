<?php
/**
 * @file
 * Custom fields & field alters for the DS module.
 */

/**
 * Define fields.
 *
 * These fields are not overridden through the interface.
 * If you want those, look at hook_ds_custom_fields_info().
 *
 * @param string $entity_type
 *   The name of the entity which we are requesting fields for, e.g. 'node'.
 *
 * @return array
 *   A collection of fields which keys are the entity type name and values
 *   a collection fields.
 *
 * @see ds_get_fields()
 */
function c4m_ds_ds_fields_info($entity_type) {
  $fields = array();

  $path = drupal_get_path('module', 'c4m_ds');

  // Fields for entity type node.

  // Creation time.
  $format_types    = system_get_date_types();
  $date_formatters = array();
  foreach (system_get_date_formats() as $type => $format) {
    // Only use date format types from C4M.
    if (FALSE === strpos($type, 'c4m', 0)) {
      continue;
    }
    foreach($format as $format_instance) {
      $date_formatters[$format_instance['format']] = t("Time ago or date format '!date'",
        array('!date' => $format_types[$type]['title'] . ' (' . $format_instance['format'] . ')'));
    }
  }

  $fields['node']['c4m_ds_submitted_by_and_on'] = array(
    'title'      => t('User name + creation date'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'ui_limit'   => array('*|*'),
    'file'       => $path . '/includes/c4m_ds.theme.node.inc',
    'function'   => 'theme_c4m_ds_submitted_by_and_on',
    'properties' => array(
      'formatters' => $date_formatters,
    ),
  );

  $fields['node']['c4m_ds_creation_date'] = array(
    'title'      => t('C4M creation date'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'ui_limit'   => array('*|*'),
    'file'       => $path . '/includes/c4m_ds.theme.node.inc',
    'function'   => 'theme_c4m_ds_creation_date',
    'properties' => array(
      'formatters' => $date_formatters,
    ),
  );

  $fields['node']['c4m_ds_type_posted_by'] = array(
    'title'      => t('Node type posted by - on (meta)'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'ui_limit'   => array('*|*'),
    'file'       => $path . '/includes/c4m_ds.theme.node.inc',
    'function'   => 'theme_c4m_ds_type_posted_by',
    'properties' => array(
      'default' => 'Default',
    ),
  );

  $fields['node']['c4m_ds_content_type_icon'] = array(
    'title'      => t('Content type icon'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'ui_limit'   => array('*|*'),
    'file'       => $path . '/includes/c4m_ds.theme.node.inc',
    'function'   => 'theme_c4m_ds_content_type_icon',
    'properties' => array(
      'formatters' => array(
        'default' => t('Default'),
      ),
    ),
  );

  $fields['node']['c4m_ds_content_footer_stats'] = array(
    'title'      => t('Footer stats'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'ui_limit'   => array('*|*'),
    'file'       => $path . '/includes/c4m_ds.theme.node.inc',
    'function'   => 'theme_c4m_ds_content_footer_stats',
    'properties' => array(
      'formatters' => array(
        'default' => t('Default'),
      ),
    ),
  );

  // Fields for Group nodes

  // A field to give list of all members of a group node with a particular role.
  foreach (c4m_og_get_group_bundles() as $group_bundle => $og_roles) {
    $fields['node']['c4m_ds_group_role_members'] = array(
      'title'      => t('Group role members'),
      'field_type' => DS_FIELD_TYPE_FUNCTION,
      'ui_limit'   => array($group_bundle . '|*'),
      'file'       => $path . '/includes/c4m_ds.theme.node.inc',
      'function'   => 'theme_c4m_ds_group_role_members',
      'properties' => array('formatters' => $og_roles),
    );
  }

  $fields['node']['c4m_ds_group_access_info'] = array(
    'title'      => t('Group access info'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'ui_limit'   => array('group|*'),
    'file'       => $path . '/includes/c4m_ds.theme.node.inc',
    'function'   => 'theme_c4m_ds_group_access_info',
    'properties' => array(
      'formatters' => array(
        'default' => t('Default'),
      ),
    ),
  );

  $fields['node']['c4m_ds_group_members_count'] = array(
    'title'      => t('Group members count'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'ui_limit'   => array('group|*'),
    'file'       => $path . '/includes/c4m_ds.theme.node.inc',
    'function'   => 'theme_c4m_ds_group_members_count',
    'properties' => array(
      'formatters' => array(
        'default' => t('Default'),
      ),
    ),
  );

  // Fields for entity type file.
  $fields['file']['c4m_ds_download_link'] = array(
    'title'      => t('C4M file download link'),
    'field_type' => DS_FIELD_TYPE_THEME,
    // Currently for all file bundles.
    'ui_limit'   => array('*|*'),
    'properties' => array(
      'formatters' => array(
        'c4m_ds_formatter_link_and_size' => t('C4M download link with filesize'),
      ),
    ),
  );

  $fields['file']['c4m_ds_document_preview'] = array(
    'title'      => t('C4M document preview'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    // Currently for document only.
    'ui_limit'   => array('document|*'),
    'file'       => $path . '/includes/c4m_ds.theme.file.inc',
    'function'   => 'theme_c4m_ds_document_preview',
  );

  return $fields;
}

/**
 * Implements hook_ds_fields_info_alter().
 */
function c4m_ds_ds_fields_info_alter(&$fields, $entity_type) {
  if (isset($fields['node']['title']['properties']['settings']['link'])) {
    $fields['node']['title']['properties']['settings']['link'][] = 'PURL auto';
    $fields['node']['title']['properties']['settings']['link'][] = 'PURL disabled';
  }

  var_dump($fields['node']['title']);
}
