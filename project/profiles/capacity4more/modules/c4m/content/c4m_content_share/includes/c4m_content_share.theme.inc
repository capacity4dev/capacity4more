<?php

/**
 * @file
 * Theme functions for the c4m_content_share module.
 */

/**
 * DS function field.
 *
 * Render the original group of a shared content item.
 *
 * @param array $field
 *   The field info.
 *
 * @return string
 *   The rendered version of the field.
 */
function theme_c4m_content_share_original_group(array $field) {
  $object = $field['entity'];
  $object_wrapper = entity_metadata_wrapper('node', $object);

  $original_entity = entity_metadata_wrapper(
    'node',
    $object_wrapper->c4m_source_entity->value()
  );
  $group_wrapper = entity_metadata_wrapper(
    'node',
    $original_entity->og_group_ref->value()
  );

  $group_link = l(
    $group_wrapper->title->value(),
    url('node/' . $group_wrapper->get('nid')->value(), array('purl' => array('disabled' => FALSE)))
  );

  return t('Original group: !group_link', array('!group_link' => $group_link));
}
