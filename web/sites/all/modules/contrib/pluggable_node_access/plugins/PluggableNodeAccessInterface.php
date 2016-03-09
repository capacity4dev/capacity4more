<?php

/**
 * @file
 * Contains \PluggableNodeAccess.
 */

interface PluggableNodeAccessInterface {

  /**
   * @return mixed
   *
   * @see hook_node_grants()
   */
  public static function getNodeGrants($account = NULL, $op = 'view');

  /**
   * @return mixed
   *
   * @see hook_node_access_records()
   */
  public function getNodeAccessRecords();

  /**
   * Determine if the passed entity has access to the handler.
   *
   * @todo: Improve the above one-liner.
   *
   * @param $entity_type
   *   The entity type.
   * @param $entity
   *   The entity object.
   * @param $op
   *   The operation to perform: 'view', 'edit' or 'delete'.
   * @return mixed
   */
  public static function access($entity_type, $entity, $op);

  /**
   * Determine if the changed node require node access change.
   *
   * @return boolean
   *   TRUE in case the plugin made a change which requires node access change.
   *   FALSE otherwise.
   */
  public function checkForNodeAccessChange();
}
