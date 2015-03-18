<?php
/**
 * @file
 * Theme functions for the c4m_content_document module.
 */

/**
 * DS function field.
 *
 * Render a document icon.
 *
 * @param array $field
 *   The field info.
 *
 * @return string
 *   The rendered version of the field.
 */
function theme_c4m_content_document_icon(array $field) {
  if (empty($field['entity']->c4m_document)) {
    return NULL;
  }

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
