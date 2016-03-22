<?php
/**
 * @file
 * DS override to create the proper PURL aware links.
 */

/**
 * Overwrite of the normal field renderer so we can link to the proper PURL URL.
 *
 * @param array $field
 *   The field info.
 *
 * @return mixed
 *   The rendered field (if not empty).
 *
 * @see ds_render_field()
 */
function c4m_og_purl_ds_render_field(array $field) {
  $title_field = FALSE;

  $output = '';
  $settings = isset($field['formatter_settings'])
    ? $field['formatter_settings']
    : array();
  $settings += $field['properties']['default'];

  // Basic string.
  if (isset($settings['link text'])) {
    // @codingStandardsIgnoreStart
    $output = t($settings['link text']);
    // @codingStandardsIgnoreEnd
  }
  elseif (isset($field['properties']['entity_render_key']) && isset($field['entity']->{$field['properties']['entity_render_key']})) {
    if ($field['entity_type'] == 'user' && $field['properties']['entity_render_key'] == 'name') {
      $output = format_username($field['entity']);
    }
    else {
      $title_field = $field['properties']['entity_render_key'] == 'title' && $field['entity_type'] == 'node';
      $output = $field['entity']->{$field['properties']['entity_render_key']};
    }
  }

  if (empty($output)) {
    return;
  }

  // Link.
  if ($settings['link']) {
    if (isset($field['entity']->uri)) {
      $uri_info = $field['entity']->uri;
    }
    else {
      $uri_info = entity_uri($field['entity_type'], $field['entity']);
    }

    c4m_og_purl_alter_uri_info($settings['link'], $uri_info);

    $output = l($output, $uri_info['path'], $uri_info['options']);
    if ($title_field) {
      $output = ds_edit_support('title', $output, $field);
    }
  }
  else {
    $output = check_plain($output);
    if ($title_field) {
      $output = ds_edit_support('title', $output, $field);
    }
  }

  // Wrapper and class.
  if (!empty($settings['wrapper'])) {
    $wrapper = check_plain($settings['wrapper']);
    $class = (!empty($settings['class'])) ? ' class="' . check_plain($settings['class']) . '"' : '';
    $output = '<' . $wrapper . $class . '>' . $output . '</' . $wrapper . '>';
  }

  return $output;
}
