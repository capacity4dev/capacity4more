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
function theme_c4m_content_event_link_to_gmap(array $field) {
  if (empty($field['entity'])) {
    return NULL;
  }

  $entity = $field['entity'];
  $wrapper = entity_metadata_wrapper('node', $entity);
  $location = $wrapper->c4m_location->value();

  // In any case we need latitude and longitude.
  if (empty($location['latitude']) ||
      empty($location['longitude'])) {
    return;
  }

  $url = 'https://www.google.com/maps';
  $zoom = !empty($location['mapzoom']) ? $location['mapzoom'] : 12;

  // Do a location search if we have an address.
  if (!empty($location['street']) &&
      !empty($location['city']) &&
      !empty($location['country_name'])) {
    $url .= '/place/' . $location['street'] . ',' . $location['city'] . ',' .
            $location['country_name'];
  }

  $url .= '/@' . $location['latitude'] . ',' . $location['longitude'] . ',' .
        $zoom . 'z';

  $options = array(
    'html' => TRUE,
    'attributes' => array('target' => '_blank'),
  );
  $text = t('View on Google Maps');
  return l($text, $url, $options);
}
