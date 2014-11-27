<?php
/**
 * @file
 * Handler to optionally add links to page displays of a view.
 */

/**
 * Views area handler to display a link to a view page.
 *
 * This allows the user to switch the layout in which to consult a view if a
 * view has several pages offering content in a different format.
 * f.i.
 * - Format - Show rendered entity - Settings - View mode - Teaser
 * - Format - Show rendered entity - Settings - View mode - Table teaser
 * - ...
 *
 * @ingroup views_area_handlers
 */
class c4m_views_handler_area_switch_page extends views_handler_area {

  function option_definition() {
    $options = parent::option_definition();

    $options['link_path'] = array(
      'default' => '',
    );
    $options['link_text'] = array(
      'default' => 'Add content',
      'translatable' => TRUE,
    );
    $options['link_class'] = array(
      'default' => '',
    );

    return $options;
  }

  /**
   * Retrieve the paths to page displays of this view.
   */
  function allowed_paths() {
    $options = array();
    foreach($this->view->display as $display) {
      if ('page' == $display->display_plugin &&
        !empty($display->display_options['path'])) {
        $options[$display->display_options['path']] =
          $display->display_options['path'];
      }
    }
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Retrieve the paths to page displays of current View.
    $options = $this->allowed_paths();

    $form['link_path'] = array(
      '#type' => 'select',
      '#required' => TRUE,
      '#title' => t('Link path'),
      '#options' => $options,
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
      '#title' => t('Link class'),
      '#description' => t('Optionally set an additional class for the link.'),
      '#default_value' => $this->options['link_class'],
    );
  }


  /**
   * Find out the information to render.
   */
  function render($empty = FALSE) {
    $link_path = filter_xss_admin($this->options['link_path']);
    $link_text = filter_xss_admin($this->options['link_text']);
    $link_class = filter_xss_admin($this->options['link_class']);
    if (!$link_path || !$link_text) {
      return;
    }

    // This handler is not to add custom paths.
    // Check if path is page of current View.
    if (!in_array($link_path, $this->allowed_paths())) {
      return;
    }

    $options = array();
    if (!empty($link_class)) {
      $options = array(
        'attributes' => array(
          'class' => array($link_class),
        )
      );
    }

    return l($link_text, $link_path, $options);
  }
}

