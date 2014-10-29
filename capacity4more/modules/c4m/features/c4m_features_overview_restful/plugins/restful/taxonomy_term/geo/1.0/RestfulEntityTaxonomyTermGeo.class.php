<?php

/**
 * @file
 * Contains \RestfulEntityTaxonomyTermGeo.
 */

class RestfulEntityTaxonomyTermGeo extends \RestfulEntityBaseTaxonomyTerm {

  public function getQueryForList() {
    $query = parent::getQueryForList();
    $query->propertyOrderBy('name');
    // Make sure the custom ordering is the first.
    $query->order = array_reverse($query->order);
    return $query;
  }

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

  /**
   * Overrides \RestfulEntityBaseTaxonomyTerm::checkEntityAccess().
   *
   * Allow access to create "Tags" resource for privileged users, as
   * we can't use entity_access() since entity_metadata_taxonomy_access()
   * denies it for a non-admin user.
   */
  protected function checkEntityAccess($op, $entity_type, $entity) {
    $account = $this->getAccount();
    return user_access('create content', $account);
  }
}
