<?php

/**
 * @file
 * Contains \PluggableNodeAccessEmailDomain.
 */

class PluggableNodeAccessOrganisation extends PluggableNodeAccessBase {

  /**
   * {@inheritdoc}
   */
  public static function getNodeGrants($account = NULL, $op = 'view') {
    if (empty($account)) {
      global $user;
      $account = user_load($user->uid);
    }

    if (!$account->uid) {
      // Anonymous user.
      return array();
    }

    if ($op != 'view') {
      // Not a view operation.
      return array();
    }
    $organisations = array();
    $realms = array();

//    $email_domain = explode('@', $account->mail);
//    // Get organisations ids whose mail list includes user's mail domain.
//    $query = new EntityFieldQuery();
//    $query
//      ->entityCondition('entity_type', 'node')
//      ->propertyCondition('type', 'organisation')
//      ->propertyCondition('status', NODE_PUBLISHED)
//      ->fieldCondition('c4m_domain', 'value', $email_domain[1]);
//
//    $result = $query
//      ->execute();
//
//    if (empty($result['node'])) {
//      return array();
//    }
//
//    $organisations = array_keys($result['node']);

    foreach ($organisations as $organisation) {
      // The "realm" name is the plugin name.
      // The "gid" is always 1, as it just indicates the user has the email
      // domain.
      $realm = 'organisation::' . $organisation;
      $realms[$realm] = array(1);
    }

    return $realms;
  }

  /**
   * {@inheritdoc}
   */
  public function getNodeAccessRecords() {
    $node = $this->getNode();

    if (empty($node->status)) {
      // Node is unpublished, so we don't allow every group member to see
      // it.
      return array();
    }

    $grants = array();
    $entities = $this->getAccessEntities('node', $node, 'organisation');
    $entities = array_unique($entities);
    foreach ($entities as $entity) {
      foreach ($entity->data as $organisation) {
        $realm = 'organisation::' . $organisation;
        $grants[] = array (
          'realm' => $realm,
          'gid' => 1,
          'grant_view' => 1,
          'grant_update' => 0,
          'grant_delete' => 0,
          'priority' => 0,
        );
      }
    }

    return $grants;
  }

  /**
   * {@inheritdoc}
   */
  public function checkForNodeAccessChange() {
    foreach ($this->getAccessEntities() as $access_entity) {
      // Restricted access was changed to other kind of the restricted access.
      if ($access_entity->timestamp == REQUEST_TIME) {
        return TRUE;
      }
    }
    // Get editing node.
    $node = $this->getNode();
    $fields = $this->getReferenceFields($node);
    foreach($fields as $field) {
      // Removed or added number of restricted access entities.
      if ($node->original->{$field} != $node->{$field}) {
        return TRUE;
      }
    }
    return FALSE;
  }
}
