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
    // Look for the key to find the right extension, using the mimetype.
    $key = array_search($document['filemime'], $mapping['mimetypes']);
    // Use the key of the extension to get the extension.
    $extension = array_search($key, $mapping['extensions']);
    // Use the extension to create a class.
    $document_type = 'as-document-' . $extension;
  }

  $tag['element'] = array(
    '#tag'       => 'span',
    '#attributes' => array(
      'class' => array('node-icon', 'as-document ' . $document_type),
    ),
    '#value'     => '',
  );

  return theme_html_tag($tag);
}
