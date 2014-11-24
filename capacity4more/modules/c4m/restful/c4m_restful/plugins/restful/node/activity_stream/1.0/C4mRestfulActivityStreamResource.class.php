<?php

/**
 * @file
 * Contains C4mRestfulActivityStreamResource.
 */

class C4mRestfulActivityStreamResource extends \RestfulEntityBaseMultipleBundles {

  /**
   * Overrides \RestfulEntityBaseNode::viewEntity().
   *
   * Adds the message HTML to the resource.
   */
  public function viewEntity($entity_id) {
    $request = $this->getRequest();

    $return = parent::viewEntity($entity_id);
    if (!empty($request['html'])) {
      $message = message_load($entity_id);
      $output = $message->view('activity_stream');
      $return['id'] = $entity_id;
      $return['html'] = drupal_render($output);
    }

    return $return;
  }

  /**
   * Overrides \RestfulEntityBaseMultipleBundles::getQueryForList().
   *
   * Adds group filter to the list.
   */
  public function getQueryForList() {
    $request = $this->getRequest();

    $query = parent::getQueryForList();

    if (!empty($request['group']) && intval($request['group'])) {
      $query->fieldCondition('field_group_node', 'target_id', $request['group']);
    }

    if (!empty($request['range']) && intval($request['range'])) {
      $query->range(0, $request['range']);
    }

    return $query;
  }
}
