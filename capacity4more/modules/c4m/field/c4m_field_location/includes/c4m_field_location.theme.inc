<?php
/**
 * @file
 * Theme functionality for locations fields.
 */

/**
 * DS function field.
 *
 * Render location city and country.
 *
 * @param array $field
 *   The field info.
 *
 * @return string
 *   The rendered field.
 */
function theme_c4m_field_location_city_country(array $field) {
  $output = '';

  if (empty($field['entity']->c4m_location)) {
    return $output;
  }
  $entity = $field['entity'];
  $wrapper = entity_metadata_wrapper('node', $entity);

  $location = $wrapper->c4m_location->value();
  $name = !empty($location['name']) ? $location['name'] : '';
  $city = !empty($location['city']) ? $location['city'] : '';
  $country = !empty($location['country_name']) ? $location['country_name'] : '';

  // @codingStandardsIgnoreStart
  $tag['element'] = array(
    '#tag'   => 'span',
    '#attributes' => array(
      'class' => 'c4m-location',
    ),
    '#value' => t($field['formatter'],
      array(
        '@name' => $name,
        '@city' => $city,
        '@country' => $country)
    ),
  );
  // @codingStandardsIgnoreEnd

  return theme_html_tag($tag);
}
