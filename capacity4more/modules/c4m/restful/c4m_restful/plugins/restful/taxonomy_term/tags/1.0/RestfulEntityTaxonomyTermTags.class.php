<?php

/**
 * @file
 * Contains \RestfulEntityTaxonomyTermTags.
 */

class RestfulEntityTaxonomyTermTags extends \C4mRestfulEntityBaseTaxonomyTerm {

  /**
   * {@inheritdoc}
   *
   * Change the bundle on the fly, based on a parameter send in the request.
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

    if(!$og_vocab = c4m_restful_get_og_vocab_by_name('node', $node->nid, 'Tags')) {
      throw new \RestfulBadRequestException('The "group" does not have a "Tags" vocabulary.');
    }

    $this->bundle = $og_vocab[0]->machine_name;

    unset($request['group']);

    return parent::process($path, $request, $method, $check_rate_limit);
  }
}
