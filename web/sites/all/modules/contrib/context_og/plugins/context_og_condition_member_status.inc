<?php

/**
 * Expose organic groups member status as a context condition..
 */
class context_og_condition_member_status extends context_condition {
  function condition_values() {
    return og_group_content_states();
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
    // load the og_membership corresponding to the current user and group
    $og_membership = og_get_membership($group['group_type'], $group['gid'], 'user', $user->uid);

    if (!empty($og_membership)) {
      // Load all contexts that trigger on this context.
      $contexts = $this->get_contexts($og_membership->state);

      // iterate over all the states and trigger contexts for
      foreach($contexts as $context) {
        $options = $this->fetch_from_context($context, 'options');
        // Check node_Form status and trigger context accordingly.
        if (!$node_form || !empty($options['node_form'])) {
          $this->condition_met($context, $og_membership->state);
        }
      }
    }
  }
}
