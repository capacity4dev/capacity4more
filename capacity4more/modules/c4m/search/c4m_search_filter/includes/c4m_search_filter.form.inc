<?php
/**
 * @file
 * All forms for the c4m_search_filter module.
 */

/**
 * Form to filter search views.
 *
 * @return array
 *   An array containing the search filter form.
 */
function c4m_search_filter_search_filter_form($form, &$form_state, $filter_type = 'all') {
  // Don't show form for anonymous users.
  if (user_is_anonymous()) {
    return array();
  }

  // Create filter options.
  $options = array();

  // Add groups filter.
  if ($filter_type == 'all' || $filter_type == 'groups') {
    $groups = og_get_groups_by_user();
    if (!empty($groups)) {
      $options += array('groups' => t('My groups'));
    }
  }

  // Add interests filter.
  if ($filter_type == 'all' || $filter_type == 'interests') {
    $options += array(
      'interests' => t('My interests'),
    );
  }

  // Add default filter.
  $options += array(
    'showAll' => t('Show all'),
  );

  // Create links for each option.
  $params = drupal_get_query_parameters();
  foreach ($options as $key => $option) {
    $query = array_merge($params, array('filter' => $key));
    $options[$key] = l($option, current_path(), array('query' => $query));
  }

  $default_value = !empty($_GET['filter']) ? $_GET['filter'] : 'showAll';

  if (!array_key_exists($default_value, $options)) {
    $default_value = 'showAll';
  }

  // Create the form.
  $form = array();
  $form['filter'] = array(
    '#type' => 'radios',
    '#title' => t('Filter by'),
    '#options' => $options,
    '#default_value' => $default_value,
    '#attributes' => array('onchange' => 'this.form.submit();'),
  );

  // Remove unique form token so request can be cached. This is accompanied by
  // code in a hook_form_alter to ignore the token and remove the build_id.
  $form['#token'] = FALSE;
  $form['#method'] = 'get';
  $form['#action'] = request_uri();

  return $form;
}
