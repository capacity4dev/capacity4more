<?php

/**
 * @file
 * Views argument plugin.
 */

// @codingStandardsIgnoreFile

/**
 * The global activity stream argument default handler.
 *
 * To allow filtering the content of the global activity stream by the user's
 * groups / projects / interests, we need to pass the relevant IDs.
 */
class c4m_message_plugin_argument_default extends views_plugin_argument_default {

  /**
   * Return the node IDs of the user's groups or project.
   *
   * @return string
   *   A `+` separated list of node IDs of the user's groups or projects.
   */
  public function get_argument() {
    $filterBy = filter_input(INPUT_GET, 'filter', FILTER_SANITIZE_STRING);

    $groups_by_user = og_get_groups_by_user();

    switch ($filterBy) {
      case 'groups':
        $groups_by_user = c4m_message_filter_groups_by_bundle($groups_by_user['node']);
        $groups_by_user = implode('+', $groups_by_user);
        break;
      case 'projects':
        $groups_by_user = c4m_message_filter_groups_by_bundle($groups_by_user['node'], 'project');
        $groups_by_user = implode('+', $groups_by_user);
        break;
      case 'interests':
        $groups_by_user = 'any';
        break;
      default:
        $groups_by_user = 'all';
    }

    return $groups_by_user;
  }
}
