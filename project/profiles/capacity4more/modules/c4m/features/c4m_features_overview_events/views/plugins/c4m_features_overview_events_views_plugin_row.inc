<?php

/**
 * @file
 * Handler to optionally add links to page displays of a view.
 */

/**
 * Views area handler to display a custom link to anywhere.
 *
 * This allows the user to switch to add a custom link to header or footer of a
 * view.
 *
 * @ingroup views_area_handlers
 */
// @codingStandardsIgnoreLine
class c4m_features_overview_events_views_plugin_row extends calendar_plugin_row {

  // @codingStandardsIgnoreLine
  function option_definition() {
    $options = parent::option_definition();
    $options['colors']['contains']['c4m_event_type'] = ['default' => []];
    return $options;
  }

  // @codingStandardsIgnoreLine
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['colors']['legend']['#options']['c4m_event_type'] = t('Based on Event Type');

    $colors = $this->options['colors']['c4m_event_type'];

    $type_names = array(
      'event' => t('Event'),
      'learning' => t('Learning'),
      'meeting' => t('Meeting'),
    );
    foreach ($type_names as $key => $name) {
      $form['colors']['c4m_event_type'][$key] = array(
        '#title' => check_plain($name),
        '#default_value' => isset($colors[$key]) ? $colors[$key] : CALENDAR_EMPTY_STRIPE,
        '#dependency' => array('edit-row-options-colors-legend' => array('c4m_event_type')),
        '#type' => 'textfield',
        '#size' => 7,
        '#maxlength' => 7,
        '#element_validate' => array('calendar_validate_hex_color'),
        '#prefix' => '<div class="calendar-colorpicker-wrapper">',
        '#suffix' => '<div class="calendar-colorpicker"></div></div>',
        '#attributes' => array('class' => array('edit-calendar-colorpicker')),
        '#attached' => array(
          'library' => array(
            array('system', 'farbtastic'),
          ),
          'js' => array(drupal_get_path('module', 'calendar') . '/js/calendar_colorpicker.js'),
        ),
      );
    }
  }

  // @codingStandardsIgnoreLine
  function render($row) {
    $rows = parent::render($row);
    if ($this->options['colors']['legend'] == 'c4m_event_type') {
      if (!empty($rows)) {
        foreach ($rows as &$one_row) {
          $stripe_options = $this->calendar_event_type_stripe($one_row->entity);
          if (!empty($stripe_options)) {
            $one_row->stripe = $stripe_options['stripe'];
            $one_row->stripe_label = $stripe_options['stripe_label'];
          }
        }
      }
    }
    return $rows;
  }

  /**
   * Create a stripe base on node type.
   */
  // @codingStandardsIgnoreLine
  function calendar_event_type_stripe($entity) {
    $output = [
      'stripe' => [],
      'stripe_label' => [],
    ];
    $colors = isset($this->options['colors']['c4m_event_type']) ? $this->options['colors']['c4m_event_type'] : array();
    if (empty($colors)) {
      return $output;
    }

    if (empty($entity->type)) {
      return $output;
    }
    $entity_wrapper = entity_metadata_wrapper('node', $entity);

    if (!isset($entity_wrapper->c4m_event_type)) {
      return $output;
    }
    $field_c4m_event_type = field_info_field('c4m_event_type');

    $event_types = $field_c4m_event_type['settings']['allowed_values'];
    $type = $entity_wrapper->c4m_event_type->value();

    if (array_key_exists($type, $event_types) || $colors[$type] == CALENDAR_EMPTY_STRIPE) {
      $output['stripe_label'][] = $event_types[$type];
    }
    if (array_key_exists($type, $colors)) {
      $output['stripe'][] = $colors[$type];
    }

    return $output;
  }

}
