<?php

/**
 * @file
 * Contains \C4mRestfulEntityBaseTaxonomyTerm.
 */

/**
 * Class C4mRestfulEntityBaseTaxonomyTerm.
 */
class C4mRestfulEntityBaseTaxonomyTerm extends \RestfulEntityBaseTaxonomyTerm {

  /**
   * Overrides \RestfulEntityBaseTaxonomyTerm::checkEntityAccess().
   *
   * Allow access to create "Tags" resource for privileged users, as
   * we can't use entity_access() since entity_metadata_taxonomy_access()
   * denies it for a non-admin user.
   */
  protected function checkEntityAccess($op, $entity_type, $entity) {
    $account = $this->getAccount();
    $resource_name = $this->getResourceName();
    if ($resource_name == 'tags') {
      $group = c4m_restful_get_group_by_og_vocab_name($entity->vocabulary_machine_name);
      $gid = $group[0]->gid;
      return og_user_access('node', $gid, 'edit terms', $account);
    }
    elseif ($resource_name == 'categories') {
      $group = c4m_restful_get_group_by_og_vocab_name($entity->vocabulary_machine_name);
      $gid = $group[0]->gid;
      return og_user_access('node', $gid, 'administer group', $account);
    }
    return user_access('create content', $account);
  }

  /**
   * Overrides \RestfulEntityBaseTaxonomyTerm::checkPropertyAccess().
   *
   * Allow user to set the parent term for the unsaved term, even if the user
   * doesn't have access to update existing terms, as required by the entity
   * metadata wrapper's access check.
   */
  protected function checkPropertyAccess($op, $public_field_name, EntityMetadataWrapper $property, EntityMetadataWrapper $wrapper) {
    $info = $property->info();
    $term = $wrapper->value();
    if (!empty($info['name']) && $info['name'] == 'parent' && empty($term->tid) && $op == 'edit') {
      return TRUE;
    }
    return parent::checkPropertyAccess($op, $public_field_name, $property, $wrapper);
  }

  /**
   * {@inheritdoc}
   *
   * Change the bundle on the fly, based on a parameter send in the request.
   * This applies only for the "tags" and "categories" resources.
   */
  public function process($path = '', array $request = array(), $method = \RestfulInterface::GET, $check_rate_limit = TRUE) {
    $resource_name = $this->getResourceName();

    if ($resource_name == 'tags' || $resource_name == 'categories') {
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

      $vocab_name = $resource_name == 'tags' ? 'Tags' : 'Categories';
      if (!$og_vocab = c4m_restful_get_og_vocab_by_name('node', $node->nid, $vocab_name)) {
        throw new \RestfulBadRequestException('The "group" does not have a "' . $vocab_name . '" vocabulary.');
      }

      $this->bundle = $og_vocab[0]->machine_name;

      // Group ID removed from the request because it's not a field in the
      // taxonomy.
      unset($request['group']);
    }

    return parent::process($path, $request, $method, $check_rate_limit);
  }

}
