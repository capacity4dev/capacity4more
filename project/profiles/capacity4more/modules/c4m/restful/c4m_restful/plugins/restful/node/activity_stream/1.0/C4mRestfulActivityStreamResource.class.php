<?php

/**
 * @file
 * Contains C4mRestfulActivityStreamResource.
 */

/**
 * Class C4mRestfulActivityStreamResource.
 */
class C4mRestfulActivityStreamResource extends \RestfulDataProviderDbQuery implements \RestfulDataProviderDbQueryInterface {

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
      $output = $message->view((!empty($request['group_context'])) ? 'activity_group' : 'activity_global');
      $return['id'] = $row->mid;
      $return['html'] = drupal_render($output);
    }

    return $return;
  }

  /**
   * {@inheritdoc}
   */
  public function getQuery() {
    $query = parent::getQuery();

    // Add a query for meter_category.
    $field = field_info_field('field_group_node');
    $table_name = _field_sql_storage_tablename($field);

    $request = $this->getRequest();

    $query->leftJoin($table_name, 'gn', "message.mid = gn.entity_id AND gn.entity_type='message'");
    $query->innerJoin('field_data_field_node', 'fn', "message.mid = fn.entity_id AND fn.entity_type='message'");
    $query->innerJoin('node', 'node', "fn.field_node_target_id = node.nid");

    // Show only publish content in active stream.
    $query->condition('node.status', 1);

    $query->condition('message.type', db_like('c4m_insert__') . '%', 'LIKE');

    if (!empty($request['topics'])) {
      // Join related to Articles tables to get V&V activities with user's
      // topics of interest.
      $query->innerJoin('field_data_c4m_vocab_topic', 'crt', "node.nid = crt.entity_id AND crt.entity_type='node'");

      // Filter only entities with related topics.
      $query->condition('crt.c4m_vocab_topic_tid', $request['topics'], is_array($request['topics']) ? 'IN' : '=');
    }

    $query->addField('gn', 'field_group_node_target_id', 'group_node');

    if (!empty($request['group'])) {
      if (empty($request['hide_articles'])) {
        $or = db_or();
        $or->condition('gn.field_group_node_target_id', $request['group'], is_array($request['group']) ? 'IN' : '=');
        if (!empty($request['topics'])) {
          $and = db_and();
          $and->isNull('gn.field_group_node_target_id');
          $and->condition('node.type', 'article');
          $and->condition('crt.c4m_vocab_topic_tid', $request['topics'], is_array($request['topics']) ? 'IN' : '=');
          $or->condition($and);
        }
        else {
          $or->isNull('gn.field_group_node_target_id');
        }
        $query->condition($or);
      }
      else {
        $query->condition('gn.field_group_node_target_id', $request['group'], is_array($request['group']) ? 'IN' : '=');
      }
    }

    $query->addTag('activity_stream_entity_field_access');

    return $query;
  }

}
