<?php

/**
 * DS function field.
 *
 * Render a document icon.
 *
 * @param $field
 *
 * @return string
 */
function theme_c4m_content_document_icon($field) {
  if (empty($field['entity']->c4m_document)) {
    return;
  }
  //include_once DRUPAL_ROOT . '/includes/file.mimetypes.inc';

  $object = $field['entity'];

  $object_wrapper = entity_metadata_wrapper('node', $object);

  $document = $object_wrapper->c4m_document->value();
  $document_type = '';
  if (!empty($document['filemime'])) {
    include_once DRUPAL_ROOT . '/includes/file.mimetypes.inc';
    $mapping = file_mimetype_mapping();
    $key = array_search($document['filemime'], $mapping['mimetypes']);
    $extension = array_search($key, $mapping['extensions']);
    $document_type = 'as-document-' . $extension;
  }


  return '<span class="node-icon as-document ' . $document_type . '"> </span>';
}
