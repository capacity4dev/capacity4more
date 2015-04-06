<?php
/**
 * @file
 * Contains \RestfulEntityTaxonomyTermTags.
 */

/**
 * Class RestfulEntityTaxonomyTermCategories.
 */
class RestfulEntityTaxonomyTermCategories extends \C4mRestfulEntityBaseTaxonomyTerm {

  /**
   * Overrides \RestfulEntityBaseNode::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['parent'] = array(
      'property' => 'parent',
    );

    return $public_fields;
  }
}
