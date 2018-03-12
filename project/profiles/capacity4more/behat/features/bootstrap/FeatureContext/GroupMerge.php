<?php

namespace FeatureContext;

/**
 * @file
 * Context methods about Groups merge.
 */

/**
 * Definitions of tests for group merge.
 *
 * @package FeatureContext
 */
trait GroupMerge {

  /**
   * Helper to get the node based on the title.
   *
   * @param string $title
   *   The group title.
   *
   * @return int
   *   The node id or NULL.
   *
   * @throws Exception
   *   Throws exception if group title not found.
   */
  private function getNodeIdByTitle($title) {
    $query = new \entityFieldQuery();
    $result = $query
      ->entityCondition('entity_type', 'node')
      ->propertyCondition('title', $title)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->range(0, 1)
      ->execute();

    if (empty($result['node'])) {
      $params = array(
        '@title' => $title,
      );
      throw new \Exception(format_string("Group @title not found.", $params));
    }

    $nid = (int) key($result['node']);
    return $nid;
  }

  /**
   * Checks if the user has the given role into the given group.
   *
   * @param int $uid
   *   User id of the user that needs to be checked.
   * @param int $gid
   *   Group id of the group that needs to be checked.
   * @param string $role
   *   Role name the user should have.
   *
   * @return bool
   *   Returns true if user has the given role inside the group.
   */
  public function checkIfUserHasRoleInGroup($uid, $gid, $role) {

    if (empty($uid) || empty($gid) || empty($role)) {
      return FALSE;
    }
    $user_roles = og_get_user_roles('node', $gid, $uid);
    return (in_array($role, $user_roles));
  }

  /**
   * Checks if user is member of a group.
   *
   * @Then /^User "([^"]*)" is a member of Group "([^"]*)"$/
   */
  public function checkIfUserIsMemberOfGroup($username, $group_title) {
    $gid = $this->getNodeIdByTitle($group_title);
    $user = user_load_by_name($username);
    if (!og_is_member('node', $gid, 'user', $user)) {
      $params = [
        '@username' => $username,
        '@groupTitle' => $group_title,
      ];
      throw new \Exception(format_string("User @username is not a member of group @groupTitle.", $params));
    }
    return TRUE;
  }

  /**
   * Checks if user has admin role in group.
   *
   * @Then /^User "([^"]*)" has "([^"]*)" role in Group "([^"]*)"$/
   */
  public function checkIfUserIsAdminOfGroup($username, $role, $group_title) {
    $gid = $this->getNodeIdByTitle($group_title);
    $user = user_load_by_name($username);
    if (!$this->checkIfUserHasRoleInGroup($user->uid, $gid, $role)) {
      $params = [
        '@username' => $username,
        '@groupTitle' => $group_title,
      ];
      throw new \Exception(format_string("User @username is not an admin of group @groupTitle.", $params));
    }
  }

  /**
   * Checks if node is a content of a group.
   *
   * @Then /^Node with id "([^"]*)" is content of Group "([^"]*)"$/
   */
  public function checkIfNodeIsInGroup($id, $group_title) {
    $gid = $this->getNodeIdByTitle($group_title);
    $node = node_load($id);
    if (!og_is_member('node', $gid, 'node', $node)) {
      $params = [
        '@wikiPageId' => $id,
        '@groupTitle' => $group_title,
      ];
      throw new \Exception(format_string("Node with id @wikiPageId is not a member of group @groupTitle.", $params));
    }
    return TRUE;
  }

  /**
   * Checks if orphan node has been deleted.
   *
   * @Then /^Orphan node "([^"]*)" should be deleted$/
   */
  public function nodeIsDeletedAfterMerge($nid) {
    $node = node_load($nid);
    if (!empty($node)) {
      $params = [
        '@nid' => $nid,
      ];
      throw new \Exception(format_string("Orphan node with node id @nid was not deleted.", $params));
    }
  }

  /**
   * Checks if user has view permission for a node.
   *
   * @Then /^Content with id "([^"]*)" is available for user "([^"]*)"$/
   */
  public function contentIsAvailableForUsers($id, $username) {
    $user = user_load_by_name($username);
    $node = node_load($id);
    if (!node_access('view', $node, $user)) {
      $params = [
        '@nodeTitle' => $node->title,
        '@username' => $username,
      ];
      throw new \Exception(format_string("User @username doesn't have access to @nodeTitle.", $params));
    }
  }

}
