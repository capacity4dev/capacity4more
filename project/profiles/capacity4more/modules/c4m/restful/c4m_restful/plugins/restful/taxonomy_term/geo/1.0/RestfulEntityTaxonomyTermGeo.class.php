<?php
/**
 * @file
 * Contains \RestfulEntityTaxonomyTermGeo.
 */

/**
 * Class RestfulEntityTaxonomyTermGeo.
 */
class RestfulEntityTaxonomyTermGeo extends \C4mRestfulEntityBaseTaxonomyTerm {
  /**
   * Overrides \RestfulEntityBaseNode::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['parent'] = array(
      'property' => 'parent',
      'sub_property' => 'tid',
    );

    return $public_fields;
  }

}
