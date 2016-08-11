<?php
/**
 * @file
 * Contains the members count field handler.
 */

/**
 * Handler for the group's members count custom field.
 *
 * @ingroup views_field_handlers
 */
class c4m_overview_groups_handler_members_count extends views_handler_field_entity {

  /**
   * @param $node
   * @return mixed|null
   *
   */
  function render($node) {
    if (empty($node->nid)) {
      return NULL;
    }

    $query = new EntityFieldQuery();

    return $query
      ->entityCondition('entity_type', 'og_membership')
      ->propertyCondition('group_type', 'node')
      ->propertyCondition('gid', $node->nid)
      ->propertyCondition('entity_type', 'user')
      ->count()
      ->execute();
  }
}
