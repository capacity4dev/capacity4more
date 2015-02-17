<?php

/**
 * @file
 * Contains C4mRestfulActivityStreamResource.
 */

class C4mRestfulActivityStreamResource extends \RestfulEntityBaseMultipleBundles {

  protected $range = 10;

  /**
   * Overrides \RestfulEntityBaseNode::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();
    $public_fields['timestamp'] = array(
      'property' => 'timestamp',
      'data' => array(
        'type' => 'string',
      ),
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

  /**
   * Overrides \RestfulEntityBaseMultipleBundles::getQueryForList().
   *
   * Display only published entities in the activity stream,
   * Custom group filter.
   */
  public function getQueryForList() {
    $request = $this->getRequest();
    $query = parent::getQueryForList();

    $query->fieldCondition('field_entity_published', 'value', 1);

    // Add group filter to the activity stream.
    if (!empty($request['group'])) {
      $query->fieldCondition('field_group_node', 'target_id', $request['group'], is_array($request['group']) ? 'IN' : '=');
    }

    // In homepage, an alteration to the query is required.
    // See: c4m_message_query_activity_stream_homepage_alter().
    if (!empty($request['homepage']) && !empty($request['group'])) {
      if (empty($request['hide_articles'])) {
        $query->addTag('activity_stream_homepage');
      }
    }
    return $query;
  }
}
