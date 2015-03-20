<?php
/**
 * @file
 * Contains C4mRestfulGroupsResource.
 */

/**
 * Class C4mRestfulGroupsResource.
 */
class C4mRestfulGroupsResource extends RestfulEntityBaseNode {
  /**
   * Overrides \RestfulEntityBaseNode::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['body'] = array(
      'property' => 'c4m_body',
      'sub_property' => 'value',
    );

    return $public_fields;
  }

}
