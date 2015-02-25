<?php
/**
 * @file
 * Field formatter info and callbacks.
 */

/**
 * Implements hook_field_formatter_info().
 */
function c4m_ds_field_formatter_info() {
  $formatters = array(
    // Formatter to present download link of a file in particular format.
    'c4m_ds_formatter_link_and_size' => array(
      'label'       => t('C4M Download link with filesize'),
      'description' => t('Displays a link that will force the browser to
        download the file.'),
      'field types' => array('file', 'image'),
      'settings'    => array(
        'text' => t('Download [file:name]'),
      ),
    ),
  );

  return $formatters;
}

/**
 * Implements hook_field_formatter_view().
 *
 * @see media_field_formatter_info()
 */
function c4m_ds_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();

  if ($display['type'] == 'c4m_ds_formatter_link_and_size') {
    $settings = $display['settings'];
    $element  = array();
    foreach ($items as $delta => $item) {
      $file = (object) $item;
      if (file_entity_access('download', $file)) {
        $element[$delta] = array(
          '#theme' => 'c4m_ds_formatter_link_and_size',
          '#file'  => $file,
          '#text'  => $settings['text'],
        );
      }
    }
  }

  return $element;
}
