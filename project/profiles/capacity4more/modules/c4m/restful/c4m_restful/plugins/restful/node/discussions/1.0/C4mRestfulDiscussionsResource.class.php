<?php

/**
 * @file
 * Contains C4mRestfulDiscussionsResource.
 */

/**
 * Class C4mRestfulDiscussionsResource.
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

    $public_fields['related_document'] = array(
      'property' => 'c4m_related_document',
      'resource' => array(
        'document' => array(
          'name' => 'documents',
          'full_view' => FALSE,
        ),
      ),
    );

    $public_fields['topic'] = array(
      'property' => 'c4m_vocab_topic',
      'resource' => array(
        'c4m_vocab_topic' => array(
          'name' => 'topics',
          'full_view' => FALSE,
        ),
      ),
    );

    $public_fields['categories'] = array(
      'property' => 'og_vocabulary',
      'resource' => array(
        'categories' => array(
          'name' => 'categories',
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
   * Overrides \RestfulEntityBase::setPropertyValues().
   *
   * Determine if we should send a notification.
   */
  protected function setPropertyValues(EntityMetadataWrapper $wrapper, $null_missing_fields = FALSE) {
    $request = $this->getRequest();
    static::cleanRequest($request);

    if (isset($request['notification'])) {
      $node = $wrapper->value();

      // The app will send 'true' as string if the user checked the checkbox.
      $node->c4m_send_notification = $request['notification'] == 'true';

      // Remove the custom field from the request to prevent errors since this
      // one is not under the public fields info.
      unset($request['notification']);
      $this->setRequest($request);
    }

    parent::setPropertyValues($wrapper, $null_missing_fields);
  }

  /**
   * Overrides \RestfulEntityBase::propertyValuesPreprocessText().
   *
   * Make sure that the body field format is always set as 'filtered_html'.
   */
  protected function propertyValuesPreprocessText($property_name, $value, $field_info) {
    if ($property_name == 'c4m_body') {
      return array(
        'value' => $value,
        'format' => 'filtered_html',
      );
    }

    return parent::propertyValuesPreprocessText($property_name, $value, $field_info);
  }

}
