<?php

/**
 * DS function field.
 *
 * Render location city and country.
 *
 * @param $field
 *
 * @return string
 */
function theme_c4m_field_location_city_country($field) {
  $output = '';

  if (empty($field['entity']->c4m_location)) {
    return $output;
  }
  $entity = $field['entity'];
  $wrapper = entity_metadata_wrapper('node', $entity);

  $location = $wrapper->c4m_location->value();
  $city = !empty($location['city']) ? $location['city'] : '';
  $country = !empty($location['country_name']) ? $location['country_name'] : '';

  $tag['element'] = array(
    '#tag'   => 'span',
    '#attributes' => array(
      'class' => 'location-city-country',
    ),
    '#value' => t($field['formatter'],
      array(
        '@city' => $city,
        '@country' => $country)
    ),
  );

  return theme_html_tag($tag);
}
