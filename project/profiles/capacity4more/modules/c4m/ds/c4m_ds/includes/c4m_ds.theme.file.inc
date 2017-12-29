<?php

/**
 * @file
 * Custom theme function to theme the file field.
 */

/**
 * Shows download URL, preview link for PDFs and size.
 *
 * Copy of theme_file_entity_download_link().
 *
 * @see theme_file_entity_download_link()
 */
function theme_c4m_link_and_size($variables) {
  $output = '';
  $uri = array();

  if (!array_key_exists('file', $variables)) {
    return $output;
  }
  $file = $variables['file'];

  if (!module_exists('file_entity')) {
    $uri['path'] = file_create_url($file->uri);
  }
  else {
    $uri = file_entity_download_uri($file);
  }

  // Set options as per anchor format described at
  // http://microformats.org/wiki/file-format-examples
  $uri['options']['attributes']['type'] = $file->filemime . '; length=' .
    $file->filesize;

  $inner = '';

  // Download link.
  $tag['element'] = [
    '#tag' => 'span',
    '#attributes' => [
      'class' => "download-link",
    ],
    '#value' => '<i class="fa fa-download"></i> ' . l(t('Download'), $uri['path'], $uri['options']),
  ];
  $inner .= theme_html_tag($tag);

  // Preview link.
  if ($variables['pdf_preview_uri'] && $file->filemime === 'application/pdf') {
    $tag['element'] = [
      '#tag' => 'span',
      '#attributes' => [
        'class' => ['preview-link'],
      ],
      '#value' => '<i class="fa fa-eye"></i> ' . l(t('Preview'), $variables['pdf_preview_uri']['path'], $variables['pdf_preview_uri']['options']),
    ];
    $inner .= theme_html_tag($tag);
  }

  // Filesize.
  $tag['element'] = array(
    '#tag' => 'span',
    '#attributes' => array(
      'class' => array('file-size', 'text-small', 'text-muted'),
    ),
    '#value' => t('Size') . ': ' . format_size($file->filesize),
  );
  $inner .= '<br/>' . theme_html_tag($tag);

  $tag['element'] = array(
    '#tag' => 'div',
    '#attributes' => array(
      'class' => "download-link-icon",
    ),
    '#value' => $inner,
  );
  $output .= theme_html_tag($tag);

  return $output;
}
