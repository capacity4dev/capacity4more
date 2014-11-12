<?php

/**
 * @file
 * Contains C4mRestfulEventsResource.
 */

class C4mRestfulEventsResource extends C4mRestfulEntityBaseNode {

  /**
   * Overrides \RestfulEntityBaseNode::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['event_type'] = array(
      'property' => 'c4m_event_type',
    );

    $public_fields['body'] = array(
      'property' => 'c4m_body',
      'sub_property' => 'value',
    );

    $public_fields['organiser'] = array(
      'property' => 'c4m_organised_by',
    );

    $public_fields['datetime'] = array(
      'property' => 'c4m_datetime_end',
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

    $public_fields['tags'] = array(
      'property' => 'og_vocabulary',
      'resource' => array(
        'tags' => array(
          'name' => 'tags',
          'full_view' => FALSE,
        ),
      ),
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
   * Location process callback.
   *
   * @param $value
   *
   * @return array
   */
  protected function processLocation($value) {
    return array(
      'lat' => $value['latitude'],
      'lng' => $value['longitude'],
    );
  }
}
