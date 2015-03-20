<?php
/**
 * @file
 *
 * Custom Display Suite function fields.
 */

/**
 * DS function field.
 *
 * Renders a link to the group the current group node belongs to.
 *
 * @param $field
 *
 * @return string
 */
function theme_c4m_field_og_group($field) {
  if (empty($field['entity'])) {
    return;
  }

  // Don't show this field in a group context.
  $context = og_context();
  if ($context) {
    return;
  }

  // Only show this field for group nodes.
  $entity = $field['entity'];
  if (!og_is_group_content_type('node', $entity->type)) {
    dsm($entity->type);
    return;
  }

  // Get group node.
  $groups = og_get_entity_groups('node', $entity);
  $group_nid = array_pop($groups['node']);

  // Return a link to the group.
  return l($entity->title, 'node/' . $group_nid);
}
