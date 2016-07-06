<?php
/**
 * @file
 * OG Selection handler.
 */

/**
 * OG selection handler.
 */
class C4MOgSelectionHandler extends OgSelectionHandler {

  /**
   * {@inheritdoc}
   */
  public static function getInstance(
    $field,
    $instance = NULL,
    $entity_type = NULL,
    $entity = NULL
  ) {
    return new C4MOgSelectionHandler($field, $instance, $entity_type, $entity);
  }

  /**
   * {@inheritdoc}
   */
  public function validateReferencableEntities(array $ids) {
    // Remove empty ids.
    foreach ($ids as $key => $value) {
      if ($value === NULL) {
        unset($ids[$key]);
      }
    }
    return parent::validateReferencableEntities($ids);
  }

  /**
   * {@inheritdoc}
   */
  public function buildEntityFieldQuery(
    $match = NULL,
    $match_operator = 'CONTAINS'
  ) {
    parent::buildEntityFieldQuery();

    global $user;

    $handler = EntityReference_SelectionHandler_Generic::getInstance(
      $this->field,
      $this->instance,
      $this->entity_type,
      $this->entity
    );
    $query = $handler->buildEntityFieldQuery($match, $match_operator);

    // FIXME: http://drupal.org/node/1325628.
    unset($query->tags['node_access']);

    // FIXME: drupal.org/node/1413108.
    unset($query->tags['entityreference']);

    $query->addTag('entity_field_access');
    $query->addTag('og');

    $group_type = $this->field['settings']['target_type'];
    $entity_info = entity_get_info($group_type);

    if (!field_info_field(OG_GROUP_FIELD)) {
      // There are no groups, so falsify query.
      $query->propertyCondition($entity_info['entity keys']['id'], -1, '=');
      return $query;
    }

    // Show only the entities that are active groups.
    $query->fieldCondition(OG_GROUP_FIELD, 'value', 1, '=');

    $account = user_load($user->uid);
    if (user_access('administer site configuration', $account)) {
      // Site administrator can choose also groups he is not member of.
      $query->fieldCondition(
        'c4m_og_status',
        'value',
        array('deleted'),
        'NOT IN'
      );
      return $query;
    }

    $user_groups = og_get_groups_by_user(NULL, $group_type);
    $user_groups = $user_groups ?: array();

    $current_gid = og_context();
    $node_type = $this->instance['bundle'];
    if (!og_user_access($group_type, $current_gid['gid'], "create $node_type content")) {
      $query->propertyCondition($entity_info['entity keys']['id'], -1, '=');
    }
    if ($user_groups) {
      $query->propertyCondition(
        $entity_info['entity keys']['id'],
        $user_groups,
        'IN'
      );
    }
    else {
      // User doesn't have permission to select any group so falsify this
      // query.
      $query->propertyCondition($entity_info['entity keys']['id'], -1, '=');
    }

    $unallowed_values = array(
      'requested',
      'archived',
      'rejected',
      'deleted',
    );
    $query->fieldCondition(
      'c4m_og_status',
      'value',
      $unallowed_values,
      'NOT IN'
    );

    return $query;
  }

}
