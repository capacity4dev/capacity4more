<?php

/**
 * @file
 * Views argument plugin.
 */

/**
 * The group members argument default handler.
 */
class c4m_features_og_members_plugin_argument_default extends views_plugin_argument_default {

  /**
   * Return the members of current group.
   *
   * @return mixed
   *   String of membership id's.
   */
  function get_argument() {
    $group = c4m_og_current_group();
    // By default, show active memberships.
    $state = array(1);
    // If current user is group owner, 'administrator member' or has the
    // site wide role administrator, also allow pending memberships to be shown.
    if (_c4m_features_og_members_is_power_user($group)) {
      $state[] = 2;
    }

    $query = new EntityFieldQuery();
    $result = $query
      ->entityCondition('entity_type', 'og_membership')
      ->propertyCondition('group_type', 'node', '=')
      ->propertyCondition('entity_type', 'user', '=')
      ->propertyCondition('state', $state, 'IN')
      ->propertyCondition('gid', $group->nid, '=')
      ->execute();

    foreach (entity_load('og_membership', array_keys($result['og_membership'])) as $og_membership) {
      $user_ids[] = $og_membership->etid;
    }

    if (!empty($user_ids)) {
      return implode('+', $user_ids);
    }
    else {
      // If no user ids meet our conditions, show no members.
      return '';
    }
  }

}
