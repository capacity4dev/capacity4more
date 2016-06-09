<?php

/**
 * @file
 *
 */

class c4m_admin_groups_views_handler_field_group_metrics extends c4m_admin_groups_views_handler_field {

  /**
   * @inheritdoc
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['c4m_admin_groups_group_statistic'] = array('default' => '');

    return $options;
  }

  /**
   * @inheritdoc
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $list = c4m_content_statistics_info('group');
    if (count($list)) {
      $options = array('' => t('- None -'));

      foreach ($list as $key => $info) {
        $options[$info['type']] = $info['plural'];
      }

      $form['c4m_admin_groups_group_statistic'] = array(
        '#type' => 'select',
        '#title' => t('Group statistic'),
        '#description' => t('The statistic of the group to be rendered.'),
        '#options' => $options,
        '#default_value' => $this->options['c4m_admin_groups_group_statistic'],
        '#weight' => -200,
      );
    }
  }

  /**
   * @inheritdoc
   */
  function render($values) {
    $statistic = $this->options['c4m_admin_groups_group_statistic'];
    if (!empty($statistic) && $group = $this->get_og_group_from_context($values)) {
      $og_context = og_context('node', $group);
      $statistics = c4m_content_get_group_statistics($og_context);
      if (isset($statistics[$statistic])) {
        return $statistics[$statistic]['count'];
      }
      return 0;
    }
  }

}
