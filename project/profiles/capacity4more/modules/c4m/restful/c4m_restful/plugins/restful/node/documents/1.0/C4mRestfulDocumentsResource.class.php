<?php
/**
 * @file
 * Contains C4mRestfulDocumentsResource.
 */

/**
 * Class C4mRestfulDocumentsResource.
 */
class C4mRestfulDocumentsResource extends C4mRestfulEntityBaseNode {

  /**
   * Overrides \RestfulEntityBaseNode::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['document'] = array(
      'property' => 'c4m_document',
      'process_callbacks' => array(
        array($this, 'processDocument'),
      ),
    );

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

    $public_fields['document_type'] = array(
      'property' => 'c4m_vocab_document_type',
      'resource' => array(
        'c4m_vocab_document_type' => array(
          'name' => 'document_types',
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

    $public_fields['topic'] = array(
      'property' => 'c4m_vocab_topic',
      'resource' => array(
        'c4m_vocab_topic' => array(
          'name' => 'topics',
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

    $public_fields['add_to_library'] = array(
      'property' => 'c4m_document_add_to_library',
    );

    return $public_fields;
  }

  /**
   * Process a property value.
   *
   * @param array $value
   *   The property value.
   *
   * @return array
   *   The new value.
   */
  protected function processDocument(array $value) {
    return array(
      'id' => $value['fid'],
      'filename' => $value['filename'],
      'filesize' => $value['filesize'],
      'filemime' => $value['filemime'],
      'url' => file_create_url($value['uri']),
    );
  }

}
