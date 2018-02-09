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

/**
 * DS function field.
 *
 * Render a document type and size.
 *
 * @param array $field
 *   The field info.
 *
 * @return string
 *   The rendered version of the field.
 */
function theme_c4m_content_document_type_size(array $field) {
  if (empty($field['entity']->c4m_document)) {
    return NULL;
  }

  $object = $field['entity'];
  $object_wrapper = entity_metadata_wrapper('node', $object);
  $document = $object_wrapper->c4m_document->value();

  $tags = array(
    'type' => array(
      'element' => array(
        '#tag' => 'span',
        '#attributes' => array(
          'class' => array('document-type'),
        ),
        '#value' => t('File type: @type', array('@type' => $document['type'])),
      ),
    ),
    'size' => array(
      'element' => array(
        '#tag' => 'span',
        '#attributes' => array(
          'class' => array('document-size'),
        ),
        '#value' => t('Size: @size', array('@size' => format_size($document['filesize']))),
      ),
    ),
  );

  return theme_html_tag($tags['type']) . ' | ' . theme_html_tag($tags['size']);
}

/**
 * PDF preview DS field.
 *
 * @param array $field
 *   The field info.
 *
 * @return string|null
 *   The rendered version of the field.
 */
function c4m_content_document_ds_field_pdf_preview(array $field) {
  if (empty($field['entity']->c4m_document)) {
    return;
  }

  $object = $field['entity'];
  $object_wrapper = entity_metadata_wrapper('node', $object);

  $document = $object_wrapper->c4m_document->value();
  if (empty($document['filemime']) || $document['filemime'] !== 'application/pdf') {
    return;
  }

  $file_uri = file_entity_download_uri((object) $document);
  $file_uri['options']['query']['skip_file_download_count'] = TRUE;
  $file_url = url($file_uri['path'], $file_uri['options']);
  $output = [
    '#theme' => 'html_tag',
    '#tag' => 'iframe',
    '#attributes' => [
      'id' => 'file-preview',
      'src' => base_path() . 'profiles/capacity4more/libraries/pdf.js/web/viewer.html?file=' . drupal_encode_path($file_url),
      'width' => '100%',
      'height' => '600',
    ],
    '#value' => '',
  ];

  return drupal_render($output);
}
