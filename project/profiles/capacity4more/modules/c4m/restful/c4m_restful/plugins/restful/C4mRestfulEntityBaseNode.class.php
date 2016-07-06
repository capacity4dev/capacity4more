<?php
/**
 * @file
 * Contains C4mRestfulEntityBaseNode.
 */

/**
 * Class C4mRestfulEntityBaseNode.
 */
class C4mRestfulEntityBaseNode extends RestfulEntityBaseNode {

  /**
   * Overrides \RestfulEntityBase::checkEntityAccess().
   *
   * Set permissions to create group content based on user's OG permissions and
   * group status value.
   */
  protected function checkEntityAccess($op, $entity_type, $entity) {
    $account = $this->getAccount();
    $resource_name = $this->getResourceName();
    $group_id = $this->request['group'];
    $wrapper = entity_metadata_wrapper('node', $group_id);

    if (empty($wrapper->c4m_og_status)) {
      return FALSE;
    }

    $group_status = $wrapper->c4m_og_status->value();
    // Only platform admins can create group content if group status
    // is NOT within the allowed groups array.
    $allowed_groups = array(
      'draft',
      'published',
    );
    if (!in_array($group_status, $allowed_groups) && !user_access('administer site configuration', $account)) {
      return FALSE;
    }
    return og_user_access('node', $group_id, "create $resource_name content", $account);
  }

  /**
   * Overrides ResfulEntityBase::createOrUpdateSubResourceItems().
   *
   * When creating a new tag, Send the group ID to the "tags" resource.
   */
  protected function createOrUpdateSubResourceItems(\RestfulInterface $handler, $value, $field_info) {
    $request = $this->getRequest();

    // Return the entity ID that was created.
    if ($field_info['cardinality'] == 1) {
      // Single value.
      return $this->createOrUpdateSubResourceItem($value, $handler);
    }

    // Multiple values.
    $return = array();
    foreach ($value as $value_item) {
      // Add group ID to the field "og_vocabulary" (categories, tags).
      if ($field_info['field_name'] == 'og_vocabulary' && is_array($value_item)) {
        $handler = restful_get_restful_handler('tags');
        $value_item['group'] = $request['group'];
      }
      $return[] = $this->createOrUpdateSubResourceItem($value_item, $handler);
    }

    return $return;
  }

  /**
   * Overrides RestfulEntityBase::getFormSchemaAllowedValues().
   *
   * For OG vocab fields we get only the ones of the group passed context.
   */
  protected function getFormSchemaAllowedValues($field) {
    if ($field['field_name'] == 'c4m_related_document') {
      // We don't need allowed values for related documents, because we are
      // getting them from library.
      return array();
    }
    if ($field['field_name'] != OG_VOCAB_FIELD) {
      return parent::getFormSchemaAllowedValues($field);
    }

    $request = $this->getRequest();
    if (empty($request['group']) || !intval($request['group'])) {
      throw new \RestfulBadRequestException('The "group" parameter is missing for the request, thus the vocabulary cannot be set for the group.');
    }

    $node = node_load($request['group']);
    if (!$node) {
      throw new \RestfulBadRequestException('The "group" parameter is not a node.');
    }
    elseif ($node->type != 'group') {
      throw new \RestfulBadRequestException('The "group" parameter is not a of type "group".');
    }

    $return = array();

    foreach (array('tags', 'categories') as $vocab_name) {
      $allowed_values = array();
      $og_vocab = c4m_restful_get_og_vocab_by_name('node', $node->nid, $vocab_name);
      $vocab = taxonomy_vocabulary_load($og_vocab[0]->vid);

      $allowed_values[] = array(
        'vocabulary' => $vocab->machine_name,
        'parent' => 0,
      );

      $field['settings']['allowed_values'] = $allowed_values;
      $return[$vocab_name] = taxonomy_allowed_values($field);
    }

    return $return;
  }

}
