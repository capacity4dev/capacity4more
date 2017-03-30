<?php

/**
 * @file
 * OG Selection handler.
 */

/**
 * OG selection handler, used for selecting related groups and projects.
 */
class C4MSelectionHandler extends C4MOgSelectionHandler {

  /**
   * {@inheritdoc}
   */
  public static function getInstance(
    $field,
    $instance = NULL,
    $entity_type = NULL,
    $entity = NULL
  ) {
    return new C4MSelectionHandler($field, $instance, $entity_type, $entity);
  }

  /**
   * {@inheritdoc}
   */
  public function validateReferencableEntities(array $ids) {
    return parent::validateReferencableEntities($ids);
  }

  /**
   * {@inheritdoc}
   *
   * Extends C4MOgSelectionHandler::buildEntityFieldQuery().
   */
  public function buildEntityFieldQuery(
    $match = NULL,
    $match_operator = 'CONTAINS'
  ) {
    // Code similar from parent::buildEntityFieldQuery().
    global $user;

    $query = $this->createEntityFieldQuery($match, $match_operator);

    $this->setQueryTags($query);

    $group_type = $this->field['settings']['target_type'];
    $entity_info = entity_get_info($group_type);

    if (!field_info_field(OG_GROUP_FIELD)) {
      // There are no groups, so falsify query.
      $query->propertyCondition(
        $entity_info['entity keys']['id'],
        static::FALSE_ID,
        '='
      );
      return $query;
    }

    $this->setGroupFieldConditions($query, $group_type);

    $account = user_load($user->uid);
    if (user_access('administer site configuration', $account)) {
      // Site administrator can choose also groups he is not member of.
      $query->fieldCondition(
        'c4m_og_status',
        'value',
        array('published'),
        'IN'
      );
      return $query;
    }

    $ids = $this->getUserGroupIds($group_type, $user);

    if ($ids) {
      $query->propertyCondition($entity_info['entity keys']['id'], $ids, 'IN');
    }
    else {
      // User doesn't have permission to select any group so falsify this
      // query.
      $query->propertyCondition(
        $entity_info['entity keys']['id'],
        static::FALSE_ID,
        '='
      );
    }

    // If group id present at POST data, we got here from document widget,
    // that creates group content (AJAX POST).
    // If not, try to resolve group id from context.
    if (!$group['gid'] = filter_input(
      INPUT_POST,
      'group',
      FILTER_VALIDATE_INT
    )
    ) {
      $group = og_context();
    }

    // If group id was resolved, check that user got permissions to add content
    // to resolved group.
    if ($group['gid']) {
      $node_type = $this->instance['bundle'];

      $target_access = og_user_access(
        $group_type,
        $group['gid'],
        "create $node_type content"
      );
      // Any member can edit a wiki page unless a power user has changed it
      // specifically for a specific node.
      if (!empty($this->entity->nid) && $node_type == 'wiki_page') {
        $target_access = og_user_access(
          $group_type,
          $group['gid'],
          "update any wiki_page content"
        );
      }

      if (!_c4m_features_og_members_is_power_user() && !$target_access) {
        // User is not group member and can't add content. Falsify the query.
        $query->propertyCondition(
          $entity_info['entity keys']['id'],
          static::FALSE_ID,
          '='
        );
        return $query;
      }
    }

    // Adding condition that verifying that group state allows adding content
    // member can add content to groups at draft or published state.
    $allowed_states = array('published');
    $query->fieldCondition(
      'c4m_og_status',
      'value',
      $allowed_states,
      'IN'
    );

    // No additional modifications to query. If creating content from a form,
    // permissions will be rechecked at form access.
    return $query;
  }

  /**
   * Implements EntityReferenceHandler::getReferencableEntities().
   */
  public function getReferencableEntities(
    $match = NULL,
    $match_operator = 'CONTAINS',
    $limit = 0
  ) {
    $options = array();
    $entity_type = $this->field['settings']['target_type'];

    $query = $this->buildEntityFieldQuery($match, $match_operator);
    if ($limit > 0) {
      $query->range(0, $limit);
    }

    $results = $query->execute();

    if (!empty($results[$entity_type])) {
      $entities = entity_load($entity_type, array_keys($results[$entity_type]));
      foreach ($entities as $entity_id => $entity) {
        $this->createElementTagFromEntity(
          $entity_type,
          $entity,
          $options,
          $entity_id
        );
      }
    }

    return $options;
  }

  /**
   * @param $match
   * @param $match_operator
   * @return \EntityFieldQuery
   */
  private function createEntityFieldQuery($match, $match_operator) {
    $handler = EntityReference_SelectionHandler_Generic::getInstance(
      $this->field,
      $this->instance,
      $this->entity_type,
      $this->entity
    );
    $query = $handler->buildEntityFieldQuery($match, $match_operator);
    return $query;
  }

  /**
   * @param $query
   */
  private function setQueryTags($query) {
    // FIXME: http://drupal.org/node/1325628.
    unset($query->tags['node_access']);

    // FIXME: drupal.org/node/1413108.
    unset($query->tags['entityreference']);

    $query->addTag('entity_field_access');
    $query->addTag('og');
  }

  /**
   * @param $query
   * @param $group_type
   */
  private function setGroupFieldConditions($query, $group_type) {
// Show only the entities that are active groups.
    $query->fieldCondition(OG_GROUP_FIELD, 'value', 1, '=');

    // If project, don't include templates.
    if ($group_type === 'project') {
      $query->fieldCondition('c4m_is_template', 'value', 1, '<>');
    }
  }

  /**
   * @param $group_type
   * @param $user
   * @return array
   */
  private function getUserGroupIds($group_type, $user) {
    $user_groups = og_get_groups_by_user(NULL, $group_type);
    $user_groups = $user_groups ? $user_groups : array();

    if ($user_groups && !empty($this->instance) && $this->instance['entity_type'] == 'node') {
      // Determine which groups should be selectable.
      $node = $this->entity;
      $node_type = $this->instance['bundle'];
      $ids = array();
      foreach ($user_groups as $gid) {
        // Check if user has "create" permissions on those groups.
        // If the user doesn't have create permission, check if perhaps the
        // content already exists and the user has edit permission.
        if (og_user_access($group_type, $gid, "create $node_type content")) {
          $ids[] = $gid;
        }
        elseif (!empty($node->nid) &&
          ($this->isUserAllowedToUpdateAnyContent($group_type, $gid, $node_type)
            || $this->isUserOwnerAndAllowedToUpdateOwnContent(
              $group_type,
              $user,
              $node,
              $gid,
              $node_type
            ))
        ) {
          $node_groups = isset($node_groups) ? $node_groups : og_get_entity_groups(
            $node->nid
          );
          if (in_array($gid, $node_groups['node'])) {
            $ids[] = $gid;
          }
        }
      }
    }
    else {
      $ids = $user_groups;
    }
    return array($node_type, $ids);
  }

  /**
   * @param $group_type
   * @param $user
   * @param $node
   * @param $gid
   * @param $node_type
   * @return bool
   */
  private function isUserOwnerAndAllowedToUpdateOwnContent(
    $group_type,
    $user,
    $node,
    $gid,
    $node_type
  ) {
    return $user->uid === $node->uid
      && og_user_access($group_type, $gid, "update own $node_type content");
  }

  /**
   * @param $group_type
   * @param $gid
   * @param $node_type
   * @return bool
   */
  private function isUserAllowedToUpdateAnyContent(
    $group_type,
    $gid,
    $node_type
  ) {
    return og_user_access($group_type, $gid, "update any $node_type content");
  }

  /**
   * @param $entity_type
   * @param $entity
   * @param $options
   * @param $entity_id
   */
  private function createElementTagFromEntity(
    $entity_type,
    $entity,
    &$options,
    $entity_id
  ) {
    $tag = array();

    list(, , $bundle) = entity_extract_ids($entity_type, $entity);

    switch ($entity->type) {
      case 'project':
        // Add project/programme indicator.
        $entity_wrapper = entity_metadata_wrapper('node', $entity);
        $project_type = $entity_wrapper->c4m_project_type->value();

        $tag['element'] = array(
          '#tag' => 'i',
          '#attributes' => array(
            'class' => array(
              'fa',
              ($project_type == 'programme') ? 'fa-puzzle-piece' : 'fa-flag-checkered',
              'project-type-' . $project_type,
            ),
          ),
          '#value' => '',
        );

        $options[$bundle][$entity_id] = theme_html_tag(
            $tag
          ) . ' ' . check_plain($this->getLabel($entity));

        break;

      case 'group':
        // Add private level indicator.
        $group_type = c4m_og_get_access_type($entity);

        $tag['element'] = array(
          '#tag' => 'span',
          '#attributes' => array(
            'class' => array(
              'group-icon',
              'group-' . $group_type['type'],
              'node-icon',
              'as-group-' . $group_type['type'],
            ),
          ),
          '#value' => '',
        );
        $options[$bundle][$entity_id] = theme_html_tag(
            $tag
          ) . ' ' . check_plain($this->getLabel($entity));

        break;

      default:
        $options[$bundle][$entity_id] = check_plain(
          $this->getLabel($entity)
        );
        break;
    }
  }

}
