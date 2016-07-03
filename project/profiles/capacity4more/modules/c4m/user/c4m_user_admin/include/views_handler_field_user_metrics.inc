<?php
/**
 * @file
 * Definition of views_handler_field_user_metrics.
 */

// @codingStandardsIgnoreFile

class views_handler_field_user_metrics extends views_handler_field_c4m_user_admin {

  /**
   * @inheritdoc
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['c4m_user_admin_user_metric'] = array('default' => '');

    return $options;
  }

  /**
   * @inheritdoc
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $list = c4m_helper_entity_metrics_info();
    if (count($list)) {
      $options = array('' => t('- None -'));

      foreach ($list as $key => $info) {
        if ($info['context'] != 'user') {
          continue;
        }
        $option_key = $info['context'] . '::' . $info['type'];
        $option_label = $info['type'];
        $options[$option_key] = $option_label;
      }

      $form['c4m_user_admin_user_metric'] = array(
        '#type' => 'select',
        '#title' => t('User metric'),
        '#description' => t('The metric of the user to be rendered.'),
        '#options' => $options,
        '#default_value' => $this->options['c4m_user_admin_user_metric'],
        '#weight' => -200,
      );
    }
  }

  /**
   * @inheritdoc
   */
  function render($values) {
    $metric_key = $this->options['c4m_user_admin_user_metric'];
    if (!empty($metric_key) && $account = user_load($values->uid)) {
      return c4m_helper_entity_get_metrics($metric_key, $account->uid, 'user');
    }
    return '';
  }

}
