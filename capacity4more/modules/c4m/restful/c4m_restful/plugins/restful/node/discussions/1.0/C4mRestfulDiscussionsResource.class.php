<?php

/**
 * @file
 * Contains C4mRestfulDiscussionsResource.
 */

class C4mRestfulDiscussionsResource extends C4mRestfulEntityBaseNode {

  /**
   * Overrides \RestfulEntityBaseNode::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['body'] = array(
      'property' => 'c4m_body',
      'sub_property' => 'value',
    );

    $public_fields['group'] = array(
      'property' => OG_AUDIENCE_FIELD,
      'resource' => array(
        'group' => array(
          'name' => 'groups',
          'full_view' => FALSE,
        ),
      ),
    );

    $public_fields['discussion_type'] = array(
      'property' => 'c4m_discussion_type',
    );

    $public_fields['topic'] = array(
      'property' => 'c4m_related_topic',
      'resource' => array(
        'topic' => array(
          'name' => 'topics',
          'full_view' => FALSE,
        ),
      ),
    );

    $public_fields['tags'] = array(
      'property' => 'og_vocabulary',
      'resource' => array(
        'tags' => array(
          'name' => 'tags',
          'full_view' => FALSE,
        ),
      ),
    );

    $public_fields['date'] = array(
      'property' => 'c4m_vocab_date',
      'resource' => array(
        'c4m_vocab_date' => array(
          'name' => 'dates',
          'full_view' => FALSE,
        ),
      ),
    );

    $public_fields['language'] = array(
      'property' => 'c4m_vocab_language',
      'resource' => array(
        'c4m_vocab_language' => array(
          'name' => 'languages',
          'full_view' => FALSE,
        ),
      ),
    );

    $public_fields['geo'] = array(
      'property' => 'c4m_vocab_geo',
      'resource' => array(
        'c4m_vocab_geo' => array(
          'name' => 'geo',
          'full_view' => FALSE,
        ),
      ),
    );

    $public_fields['status'] = array(
      'property' => 'status',
    );

    return $public_fields;
  }

  /**
   * Overrides RestfulEntityBase::getFormSchemaAllowedValues().
   *
   * For OG vocab fields we get only the ones of the group passed context.
   */
  protected function getFormSchemaAllowedValues($field) {
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
    elseif($node->type != 'group') {
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
