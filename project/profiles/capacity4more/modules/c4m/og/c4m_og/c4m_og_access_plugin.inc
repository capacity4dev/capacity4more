<?php
// @codingStandardsIgnoreFile

/**
 * @file
 * OG access plugin.
 */

/**
 * Access plugin that provides property based access control.
 */
class c4m_og_access_plugin extends views_plugin_access {

  /**
   * Plugin summary title.
   *
   * @return string
   *   The summary text.
   */
  function summary_title() {
    return $this->options['feature'];
  }

  /**
   * Determine if the current user has access or not.
   *
   * @param object $account
   *    The user object.
   *
   * @return bool
   *    TRUE if user has access to the view.
   */
  function access($account) {
    return c4m_og_access($this->options['feature'], $account);
  }

  function get_access_callback() {
    return array('c4m_og_access', array($this->options['feature']));
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['feature'] = array('default' => 'all');

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Get list of features.
    $features = c4m_og_feature_info();
    foreach ($features as $feature) {
      $features[$feature['machine_name']] = strip_tags($feature['name']);
    }

    $form['feature'] = array(
      '#type' => 'select',
      '#options' => $features,
      '#title' => t('Feature'),
      '#default_value' => $this->options['feature'],
      '#description' => t('Only groups with the selected feature enabled will be able to access this display.'),
    );
  }

}
