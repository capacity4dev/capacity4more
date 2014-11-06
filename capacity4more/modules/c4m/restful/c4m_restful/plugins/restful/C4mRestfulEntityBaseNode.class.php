<?php

/**
 * @file
 * Contains C4mRestfulEntityBaseNode.
 */

class C4mRestfulEntityBaseNode extends RestfulEntityBaseNode {

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
      // Add group ID to the field "og_vocabulary" (tags).
      if ($field_info['field_name'] == 'og_vocabulary' && is_array($value_item)) {
        $value_item['group'] = $request['group'][0];
      }
      $return[] = $this->createOrUpdateSubResourceItem($value_item, $handler);
    }

    return $return;
  }
}
