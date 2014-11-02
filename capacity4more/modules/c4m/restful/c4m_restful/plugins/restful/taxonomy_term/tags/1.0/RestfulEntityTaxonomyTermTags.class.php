<?php

/**
 * @file
 * Contains \RestfulEntityTaxonomyTermTags.
 */

class RestfulEntityTaxonomyTermTags extends \RestfulEntityBaseTaxonomyTerm {

  /**
   * Constructs a RestfulDataProviderEFQ object.
   *
   * @param array $plugin
   *   Plugin definition.
   * @param RestfulAuthenticationManager $auth_manager
   *   (optional) Injected authentication manager.
   * @param DrupalCacheInterface $cache_controller
   *   (optional) Injected cache backend.
   */
  public function __construct(array $plugin, \RestfulAuthenticationManager $auth_manager = NULL, \DrupalCacheInterface $cache_controller = NULL) {
    parent::__construct($plugin, $auth_manager, $cache_controller);
  }


  /**
   * {@inheritdoc}
   */
  public function process($path = '', array $request = array(), $method = \RestfulInterface::GET, $check_rate_limit = TRUE) {
    if (empty($request['group']) || !intval($request['group'])) {
      throw new \RestfulBadRequestException('The "group" parameter is missing for the request, thus the vocabulary cannot be set for the group.');
    }

    $node = node_load($request['group']);
    if (!$node) {
      throw new \RestfulBadRequestException('The "group" parameter is not a node.');
    }
    elseif($node->type != 'group') {
      throw new \RestfulBadRequestException('The "group" parameter is not a of type "group".');
    }

    $og_vocab = c4m_restful_get_og_vocab_by_name('node', $node->nid, 'Tags');

    if(!$og_vocab[0]) {
      throw new \RestfulBadRequestException('The "group" parameter does not contain "Tags" vocabulary.');
    }

    $this->bundle = $og_vocab[0]->machine_name;

    return parent::process($path, $request, $method, $check_rate_limit);
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
