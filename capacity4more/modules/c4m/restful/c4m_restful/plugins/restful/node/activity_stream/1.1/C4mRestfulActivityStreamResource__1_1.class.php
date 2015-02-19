<?php

/**
 * @file
 * Contains C4mRestfulActivityStreamResource.
 */

class C4mRestfulActivityStreamResource__1_1 extends \RestfulDataProviderDbQuery implements \RestfulDataProviderDbQueryInterface {

  protected $range = 10;

  /**
   * Overrides \RestfulEntityBaseNode::publicFieldsInfo().
   */
  public function publicFieldsInfo() {

    $public_fields['timestamp'] = array(
      'property' => 'timestamp',
    );

    $public_fields['group_node'] = array(
      'property' => 'group_node',
      'column_for_query' => 'gn.field_group_node_target_id',
    );
    return $public_fields;
  }

  /**
   * Overrides \RestfulDataProviderDbQuery::view().
   *
   * Adds the message HTML to the resource.
   */
  public function mapDbRowToPublicFields($row) {
    $request = $this->getRequest();

    $return = parent::mapDbRowToPublicFields($row);

    if (!empty($request['html'])) {
      $message = message_load($row->mid);
      $output = $message->view('activity_stream');
      $return['id'] = $row->mid;
      $return['html'] = drupal_render($output);
    }

    return $return;
  }

  public function getQuery() {
    $query = parent::getQuery();

    // Add a query for meter_category.
    $field = field_info_field('field_group_node');
    $table_name = _field_sql_storage_tablename($field);

    $request = $this->getRequest();

    if (!empty($request['homepage']) && empty($request['hide_articles'])) {
      $query->leftJoin($table_name, 'gn', "message.mid = gn.entity_id AND gn.entity_type='message'");
    }
    else {
      $query->innerJoin($table_name, 'gn', 'message.mid = gn.entity_id');
    }

    $query->addField('gn', 'field_group_node_target_id', 'group_node');

    if (!empty($request['group'])) {
      $query->condition('gn.field_group_node_target_id', $request['group'], is_array($request['group']) ? 'IN' : '=');
    }

    $query->addTag('activity_stream_entity_field_access');

    return $query;
  }
}
