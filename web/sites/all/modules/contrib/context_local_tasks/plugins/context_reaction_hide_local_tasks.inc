<?php

/**
 * Expose primary links as context reactions.
 */
class context_reaction_hide_local_tasks extends context_reaction {
  function options_form($context) {
    return array('hide_local_tasks' => array('#type' => 'value', '#value' => TRUE));
  }

  function options_form_submit($values) {
    return array('hide_local_tasks' => 1);
  }

  /**
   * Hide the local tasks tabs
   */
  function execute(&$vars) {
    $contexts = context_active_contexts();
    foreach ($contexts as $context) {
      if (!empty($context->reactions['hide_local_tasks'])) {
        $vars['tabs'] = '';
      }
    }
  }
}
