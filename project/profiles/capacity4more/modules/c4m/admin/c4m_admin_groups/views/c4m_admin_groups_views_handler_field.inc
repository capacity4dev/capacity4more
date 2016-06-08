<?php

/**
 * @file
 * Helper class for C4M Admin Groups views field handler.
 */

class c4m_admin_groups_views_handler_field extends views_handler_field {

  /**
   * @inheritdoc
   *
   * Disable advanced rendering.
   */
  function allow_advanced_render() {
    return FALSE;
  }

  /**
   * @inheritdoc
   *
   * Disable query.
   */
  function query() {}

  /**
   * Helper function to return the Organic Group from the context.
   *
   * @param $render_values
   *   The values retrieved from the render function.
   *
   * @return object | bool
   *   Returns the Organic Group object or FALSE if it's not a group.
   */
  function get_og_group_from_context($render_values) {
    // If it's not about a node.
    if (!is_object($render_values) || !isset($render_values->nid)) {
      return FALSE;
    }

    // Load the node.
    $group = node_load($render_values->nid);

    // If the node is not valid.
    if (!is_object($group)) {
      return FALSE;
    }

    // If the node is not a group.
    if (og_is_group('node', $group)) {
      return $group;
    }

    return FALSE;
  }

}
