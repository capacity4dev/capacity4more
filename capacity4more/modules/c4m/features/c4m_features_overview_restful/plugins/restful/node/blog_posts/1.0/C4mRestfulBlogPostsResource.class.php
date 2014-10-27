<?php

/**
 * @file
 * Contains C4mRestfulBlogPostsResource.
 */

class C4mRestfulBlogPostsResource extends RestfulEntityBaseNode {

  /**
   * Overrides \RestfulEntityBaseNode::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['body'] = array(
      'property' => 'c4m_body',
      'sub_property' => 'value',
    );

    $public_fields['og_group_ref'] = array(
      'property' => 'og_group_ref',
      'sub_property' => 'title',
    );

    return $public_fields;
  }
}
