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
   * Helper to check if node was deleted after group merge.
   *
   * @param int $nid
   *   The group title.
   *
   * @return bool
   *   Returns TRUE if node was deleted.
   */
  private function checkIfNodeIsDeleteAfterMerge($nid) {
    $query = new \entityFieldQuery();
    $result = $query
      ->entityCondition('entity_type', 'node')
      ->propertyCondition('nid', $nid)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->range(0, 1)
      ->execute();

    if (!empty($result['node'])) {
      return FALSE;
    }

    return TRUE;
  }

  /**
   * Checks if the user has the given role into the given group.
   *
   * @param int $uid
   *   User id of the user that needs to be checked.
   * @param int $gid
   *   Group id of the group that needs to be checked.
   * @param array $rids
   *   Role ids which the user should have.
   *
   * @return bool
   *   Returns true if user has the given role inside the group.
   */
  public function checkIfUserHasRoleInGroup($uid, $gid, array $rids) {

    $query = db_select('og_users_roles', 'og_users_roles');

    $query->fields('og_users_roles', array('rid'))
      ->condition('uid', $uid)
      ->condition('gid', $gid);
    $results = $query->execute()->fetchCol();

    if (empty($results)) {
      return FALSE;
    }
    foreach ($rids as $rid) {
      if (in_array($rid, $results)) {
        return TRUE;
      }
    }
    return FALSE;
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
   * @Then /^User "([^"]*)" is an admin of Group "([^"]*)"$/
   */
  public function checkIfUserIsAdminOfGroup($username, $group_title) {
    $gid = $this->getNodeIdByTitle($group_title);
    $user = user_load_by_name($username);
    // Admin role ids.
    $rids = [3, 6];
    if (!$this->checkIfUserHasRoleInGroup($user->uid, $gid, $rids)) {
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
    $deleted = $this->checkIfNodeIsDeleteAfterMerge($nid);
    if (!$deleted) {
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
