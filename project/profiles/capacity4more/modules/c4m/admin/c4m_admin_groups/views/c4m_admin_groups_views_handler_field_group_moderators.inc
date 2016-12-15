<?php
// @codingStandardsIgnoreFile

/**
 * @file
 * Group Moderators views field handler.
 */

class c4m_admin_groups_views_handler_field_group_moderators extends c4m_admin_groups_views_handler_field {

  /**
   * @inheritdoc
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['c4m_admin_groups_group_type'] = array('default' => '');

    return $options;
  }

  /**
   * @inheritdoc
   */
  function options_form(array &$form, array &$form_state) {
    parent::options_form($form, $form_state);

    $list = array();

    $group_bundles = og_get_all_group_bundle();
    if (isset($group_bundles['node']) && count($group_bundles['node'])) {
      $list = $group_bundles['node'];
    }

    if (count($list)) {
      $options = array('' => t('- None -'));

      foreach ($list as $key => $label) {
        $options[$key] = $label;
      }

      $form['c4m_admin_groups_group_type'] = array(
        '#type' => 'select',
        '#title' => t('Group type'),
        '#description' => t('The node type of the group.'),
        '#options' => $options,
        '#default_value' => $this->options['c4m_admin_groups_group_type'],
        '#weight' => -200,
      );
    }
  }

  /**
   * @inheritdoc
   */
  function render($values) {
    if ($group = $this->get_og_group_from_context($values)) {
      $group_type = $this->options['c4m_admin_groups_group_type'];
      $admins = c4m_og_get_group_admins($group->nid, FALSE, $group_type);

      if (count($admins)) {
        foreach ($admins as $uid => $user) {
          $output[] = c4m_user_name($user) . ' (' . $user->mail . ')';
        }
        return implode(', ', $output);
      }

      return t('none');
    }
  }

}
