<?php
/**
 * @file
 * Custom Display Suite function fields.
 */

/**
 * Theme function for gmap link.
 *
 * @param array $field
 *   The field info.
 *
 * @return string
 *   The rendered version of the field.
 */
function theme_c4m_content_event_link_to_osm(array $field) {
  if (empty($field['entity'])) {
    return NULL;
  }

  $entity = $field['entity'];
  $wrapper = entity_metadata_wrapper('node', $entity);
  $location = $wrapper->c4m_location_address->value();

  $address = geocoder_widget_parse_addressfield($location);
  $api_url = 'http://nominatim.openstreetmap.org/';

  $params = array(
    'query' => array('q' => $address),
    'html' => TRUE,
    'attributes' => array('target' => '_blank'),
  );
  $text = t('View on OpenStreetMap.org');
  return l($text, $api_url, $params);
}
