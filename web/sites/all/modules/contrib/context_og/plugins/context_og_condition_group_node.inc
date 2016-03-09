<?php

/**
 * Expose organic groups group nodes as a context condition.
 */
class context_og_condition_group_node extends context_condition {
  function condition_values() {
    $result = og_get_all_group();

    $values = array();

    foreach ($result as $gid) {
      $group = node_load($gid);
      $type = node_type_get_name($group->type);

      $values[$group->nid] = $type . ': ' . $group->title;
    }

    return $values;
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
    if (isset($group) && $group['group_type'] == 'node') {
      $node = entity_load_single($group['group_type'], $group['gid']);
      $node_form = ((arg(0) == 'node') && ((is_numeric(arg(1)) && (arg(2) == 'edit')) || (arg(1) == 'add')));
      if (!empty($node->nid)) {
        $contexts = $this->get_contexts($node->nid);
        $this->values[$node->nid] = array();

        foreach ($contexts as $context) {
          $options = $this->fetch_from_context($context, 'options');
          // The condition is met unless we are looking at a node form
          // and the "Set on node form" option is unchecked.
          if (!$node_form || !empty($options['node_form'])) {
            $this->condition_met($context, $group['gid']);
          }
        }
      }
    }
  }
}
