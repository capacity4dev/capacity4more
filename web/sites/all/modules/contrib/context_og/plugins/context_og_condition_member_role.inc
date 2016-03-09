<?php

/**
 * Expose organic groups member status as a context condition..
 */
class context_og_condition_member_role extends context_condition {
  function condition_values() {
    // we want to expose all roles so og_roles doesn't quite suffice.
    $query = db_select('og_role', 'ogr')
      ->fields('ogr', array('rid', 'name', 'group_type', 'group_bundle'))
      ->condition('gid', 0, '=')
      ->orderBy('group_type, group_bundle, name', 'ASC');
    $rids = $query
      ->execute()
      ->fetchAll();

    $roles = array();
    foreach ($rids as $rid => $fields) {
      $roles[$rid] = $fields->group_type . '-' . $fields->group_bundle . ': ' . $fields->name;
    }
    return $roles;
  }

  function condition_form($context) {
    $form = parent::condition_form($context);
    $form['#type'] = 'select';
    $form['#multiple'] = TRUE;
    return $form;
  }

  function options_form($context) {
    $defaults = $this->fetch_from_context($context, 'options');
    return array(
      'node_form' => array(
        '#title' => t('Set on node form'),
        '#type' => 'checkbox',
        '#description' => t('Set this context on node forms'),
        '#default_value' => isset($defaults['node_form']) ? $defaults['node_form'] : TRUE,
      ),
    );
  }

  function execute($group) {
    global $user;
    $node_form = ((arg(0) == 'node') && ((is_numeric(arg(1)) && (arg(2) == 'edit')) || (arg(1) == 'add')));
    // load the current roles for the user.
    $roles = og_get_user_roles($group['group_type'], $group['gid'], $user->uid);
    if (!empty($roles)) {
      // Load all contexts that trigger on this context.
      foreach ($roles as $rid => $name) {
        $contexts = $this->get_contexts($rid);

        foreach($contexts as $context) {
          $options = $this->fetch_from_context($context, 'options');
          // Check node_Form status and trigger context accordingly.
          if (!$node_form || !empty($options['node_form'])) {
            $this->condition_met($context, $rid);
          }
        }
      }
    }
  }
}
