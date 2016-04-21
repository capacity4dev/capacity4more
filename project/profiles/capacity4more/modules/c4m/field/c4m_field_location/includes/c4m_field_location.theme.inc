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

  if (empty($field['entity']->c4m_location_address)) {
    return $output;
  }
  $entity = $field['entity'];
  $wrapper = entity_metadata_wrapper('node', $entity);

  $location = $wrapper->c4m_location_address->value();
  $name = !empty($location['name_line']) ? $location['name_line'] : '';
  $city = !empty($location['locality']) ? $location['locality'] : '';
  $country = !empty($location['country']) ? $location['country'] : '';

  if (module_exists('countries')) {
    $countries = countries_get_countries(
      'name',
      array('enabled' => COUNTRIES_ENABLED)
    );
  }
  else {
    require_once DRUPAL_ROOT . '/includes/locale.inc';
    $countries = country_get_list();
  }

  $country = array_key_exists(
    $country,
    $countries
  ) ? $countries[$country] : $country;

  if (empty($name) && empty($city) && empty($country)) {
    return;
  }

  $element_value = format_string(
    $field['formatter'],
    array(
      '@name' => $name,
      '@city' => $city,
      '@country' => $country,
    )
  );

  $tag['element'] = array(
    '#tag' => 'div',
    '#attributes' => array(
      'class' => 'event-location',
    ),
    '#value' => $element_value,
  );

  return theme_html_tag($tag);
}
