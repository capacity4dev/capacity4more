<?php
// @codingStandardsIgnoreFile

/**
 * @file
 * Definition of c4m_views_handler_area_result.
 */

/**
 * Views area handler to display some configurable result summary.
 *
 * @ingroup views_area_handlers
 */
class c4m_views_handler_area_result extends views_handler_area_result {
  /**
   * {@inheritdoc}
   */
  public function option_definition() {
    $options = parent::option_definition();

    $options['classes'] = array(
      'default' => '',
    );

    return $options;
  }

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['classes'] = array(
      '#type' => 'textfield',
      '#required' => TRUE,
      '#title' => t('Optional classes'),
      '#description' => t('Optionally set additional classes on the result,
        separated by comma.'),
      '#default_value' => $this->options['classes'],
    );
  }

  /**
   * {@inheritdoc}
   */
  public function render($empty = FALSE) {
    $content = parent::render($empty);
    if (!empty($content)) {
      $tag['element'] = array(
        '#tag'       => 'span',
        '#value'     => $content,
      );
      $classes = filter_xss_admin($this->options['classes']);
      if (!empty($classes)) {
        $tag['element']['#attributes']['class'] = explode(', ', $classes);
      }

      return theme_html_tag($tag);
    }
  }

}
