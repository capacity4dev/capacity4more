<?php

/**
 * @file
 * Contains \PluggableNodeAccessEmailDomain.
 */

class PluggableNodeAccessEmailDomain extends PluggableNodeAccessBase {

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

    $email_domain = explode('@', $account->mail);
    // The "realm" name is the plugin name, along with the email domain.
    // The "gid" is always 1, as it just indicates the user has the email
    // domain.
    $realm = 'email_domain::' . $email_domain[1];
    return array($realm => array(1));
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

    foreach ($this->getAccessEntities() as $entity) {
      foreach ($entity->data as $email_domain) {
        $realm = 'email_domain::' . $email_domain;
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
