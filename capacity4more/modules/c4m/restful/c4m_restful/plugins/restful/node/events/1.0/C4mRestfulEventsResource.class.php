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

    $public_fields['location'] = array(
      'property' => 'c4m_location',
      'process_callbacks' => array(
        array($this, 'processLocation'),
      ),
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
      'street' => $value['street'],
      'city' => $value['city'],
      'postal_code' => $value['postal_code'],
      'country_name' => $value['country_name'],
      'lat' => $value['latitude'],
      'lng' => $value['longitude'],
    );
  }

  /**
   * Overrides /ResfulEntityBase::createEntity().
   *
   * Add a new location when saving an event entity.
   */
  public function createEntity() {
    $entity = parent::createEntity();
    $request = $this->getRequest();

    $entity = node_load($entity[0]['id']);

    $locations = array(
      0 => array(
        'address' => $request['location']['street'] . ' ' . $request['location']['postal_code'] . ', ' . $request['location']['city'] . ', ' . $request['location']['country_name'],
        'street' => $request['location']['street'],
        'postal_code' => $request['location']['postal_code'],
        'city' => $request['location']['city'],
        'country_name' => $request['location']['country_name'],
        'country' => $request['location']['country'],
        'latitude' => $request['location']['lat'],
        'longitude' => $request['location']['lng'],
      ),
    );

    $criteria = array(
      'field_name' => 'c4m_location',
      'nid' => $entity->nid,
      'vid' => $entity->vid,
    );

    $locations = getlocations_fields_save_locations($locations, $criteria, array(), 'insert');
    entity_metadata_wrapper('node', $entity)->c4m_location->set($locations[0]);
    node_save($entity);
  }
}
