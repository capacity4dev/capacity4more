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
   * Uses the current group ID to fetch & return it's member's count.
   * 
   * @param $node
   *  The group to check it's member's count.
   *
   * @return int|null
   *  The group's members count, if the node provided is valid.
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
