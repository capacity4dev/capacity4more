<?php

/**
 * @file
 * Contains C4mRestfulActivityStreamResource.
 */

class C4mRestfulActivityStreamResource extends \RestfulEntityBaseMultipleBundles {

  protected $range = 20;

  /**
   * Overrides \RestfulEntityBaseNode::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['group'] = array(
      'property' => 'field_group_node',
      'sub_property' => 'title',
    );

    return $public_fields;
  }

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
}
