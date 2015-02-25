<?php
/**
 * @file
 * Custom field renderer & helpers.
 */

/**
 * Render a field.
 *
 * @see ds_render_field().
 *
 * @param array $field
 *
 * @return string
 */
function c4m_ds_ds_render_field($field) {
  $title_field = FALSE;

  $output = '';
  $settings = isset($field['formatter_settings'])
    ? $field['formatter_settings']
    : array();
  $settings += $field['properties']['default'];


  // Basic string.
  if (isset($settings['link text'])) {
    $output = t($settings['link text']);
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

    $uri_info = _c4m_ds_ds_render_field_uri_info($settings, $uri_info);

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

/**
 * Helper to define the URI options based on the settings and entity.
 *
 * @param array $settings
 *   Settings for the field.
 * @param array $uri_info
 *   The uri info that needs to be changed.
 *
 * @return array
 */
function _c4m_ds_ds_render_field_uri_info($settings, $uri_info) {
  switch($settings['link']) {
    case C4M_DS_LINK_TYPE_PURL_AUTO:
      return _c4m_ds_ds_render_field_uri_info_purl_auto($uri_info);
      break;

    case C4M_DS_LINK_TYPE_PURL_DISABLED:
      return _c4m_ds_ds_render_field_uri_info_purl_disabled($uri_info);
      break;

    case C4M_DS_LINK_TYPE_PURL_OG_DASHBOARD:
      return _c4m_ds_ds_render_field_uri_info_purl_og_dashboard($uri_info);
      break;
  }

  return $uri_info;
}

/**
 * Alter the uri_info for a rendered field so it uses PURL if appropriate.
 *
 * @param array $uri_info
 *   The link info array.
 *
 * @return array
 */
function _c4m_ds_ds_render_field_uri_info_purl_auto($uri_info) {
  $entity = $uri_info['options']['entity'];
  $gid = c4m_og_get_gid_from_entity($entity);

  // Enable PURL if it is a group or group content.
  if ($gid) {
    $uri_info['options']['purl'] = array(
      'provider' => 'og_purl|node',
      'id' => $gid,
    );
  }
  // Disable PURL if it is not a group or group content.
  else {
    $uri_info['options']['purl'] = array(
      'disabled' => TRUE,
    );
  }

  return $uri_info;
}

/**
 * Alter the uri_info for a rendered field so it always disable PURL.
 *
 * @param array $uri_info
 *   The link info array.
 *
 * @return array
 */
function _c4m_ds_ds_render_field_uri_info_purl_disabled($uri_info) {
  $uri_info['options']['purl'] = array(
    'disabled' => TRUE,
  );
  return $uri_info;
}

/**
 * Alter the uri_info for a rendered field so it points to the group dashboard.
 *
 * @param array $uri_info
 *   The link info array.
 *
 * @return array
 */
function _c4m_ds_ds_render_field_uri_info_purl_og_dashboard($uri_info) {
  $entity = $uri_info['options']['entity'];
  $gid = c4m_og_get_gid_from_entity($entity);

  // No change if not group related.
  if (!$gid) {
    return $uri_info;
  }

  // Point the link to the group dashboard.
  $uri_info['path'] = '<front>';
  $uri_info['options']['purl'] = array(
    'provider' => 'og_purl|node',
    'id' => $gid,
  );
  return $uri_info;
}
