<?php
// @codingStandardsIgnoreFile

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
  /**
   * {@inheritdoc}
   */
  public function option_definition() {
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
    $options['link_icon'] = array(
      'default' => '',
    );

    return $options;
  }

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
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

    $form['link_icon'] = array(
      '#type' => 'textfield',
      '#required' => TRUE,
      '#title' => t('Link icon'),
      '#description' => t('Optionally icon to use for this link (fontawesome).'),
      '#default_value' => $this->options['link_icon'],
    );
  }

  /**
   * Find out the information to render.
   *
   * We do not retain query parameters as we are going elsewhere altogether.
   *
   * @param bool $empty
   *   Is the field empty.
   *
   * @return string
   *   The rendered content.
   */
  public function render($empty = FALSE) {
    $link_path = filter_xss_admin($this->options['link_path']);
    $link_text = filter_xss_admin($this->options['link_text']);
    $link_class = filter_xss_admin($this->options['link_class']);
    $link_icon = filter_xss_admin($this->options['link_icon']);

    if (!$link_path || !$link_text) {
      return NULL;
    }

    $options = array(
      'html' => TRUE,
      'attributes' => array(
        'class' => array('custom-link'),
      ),
    );

    if (!empty($link_class)) {
      $classes = explode(', ', $link_class);
      $options['attributes']['class'] = array_merge(
        $options['attributes']['class'],
        $classes
      );
    }

    $icon = NULL;
    if ($link_icon) {
      $icon = '<i class="fa ' . $icon . '"></li>"';
      $options['attributes']['title'] = $link_text;
    }

    return l(
      $icon . '<span class="label">' . $link_text . '</span>',
      $link_path,
      $options
    );
  }

}
