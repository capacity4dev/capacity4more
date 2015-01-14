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
class c4m_views_handler_area_custom_link extends views_handler_area {

  function option_definition() {
    $options = parent::option_definition();

    $options['link_path'] = array(
      'default' => '',
    );
    $options['link_text'] = array(
      'default' => 'Go to',
      'translatable' => TRUE,
    );
    $options['link_class'] = array(
      'default' => '',
    );

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['link_path'] = array(
      '#type' => 'textfield',
      '#required' => TRUE,
      '#title' => t('Link path'),
      '#description' => t('Set the path for the link.'),
      '#default_value' => $this->options['link_path'],
    );

    $form['link_text'] = array(
      '#type' => 'textfield',
      '#required' => TRUE,
      '#title' => t('Link text'),
      '#description' => t('Set the label for the link.'),
      '#default_value' => $this->options['link_text'],
    );

    $form['link_class'] = array(
      '#type' => 'textfield',
      '#required' => TRUE,
      '#title' => t('Link classes'),
      '#description' => t('Optionally set additional classes for the link,
        separated by comma.'),
      '#default_value' => $this->options['link_class'],
    );
  }

  /**
   * Find out the information to render.
   *
   * We do not retain query parameters as we are going elsewhere altogether.
   */
  function render($empty = FALSE) {
    $link_path = filter_xss_admin($this->options['link_path']);
    $link_text = filter_xss_admin($this->options['link_text']);
    $link_class = filter_xss_admin($this->options['link_class']);
    if (!$link_path || !$link_text) {
      return;
    }

    $options = array();
    //
    if (!empty($link_class)) {
      $options['attributes']['class'] = explode(', ', $link_class);
    }

    return l($link_text, $link_path, $options);
  }
}

