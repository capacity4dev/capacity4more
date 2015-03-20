<?php
// @codingStandardsIgnoreFile

/**
 * @file
 * Context to react to form ID's.
 */

/**
 * Expose form id's as a context condition.
 */
class c4m_context_condition_no_form extends context_condition {
  /**
   * Omit condition values. We will provide a custom input form for our conditions.
   */
  function condition_values() {
    return array();
  }

  /**
   * Condition form.
   */
  function condition_form($context) {
    $form = parent::condition_form($context);
    unset($form['#options']);

    $form['#type'] = 'textarea';
    $form['#default_value'] = implode("\n", $this->fetch_from_context($context, 'values'));
    return $form;
  }

  /**
   * Condition form submit handler.
   */
  function condition_form_submit($values) {
    $parsed = array();
    $items = explode("\n", $values);
    if (!empty($items)) {
      foreach ($items as $v) {
        $v = trim($v);
        if (!empty($v)) {
          $parsed[$v] = $v;
        }
      }
    }
    return $parsed;
  }

  /**
   * Execute.
   */
  function execute() {
    if ($this->condition_used()) {
      $current_op = !empty($_POST['op']) ? $_POST['op'] : NULL;
      $current_form_id = !empty($_POST['form_id']) ? $_POST['form_id'] : NULL;
      foreach ($this->get_contexts() as $context) {
        $combinations = $this->fetch_from_context($context, 'values');
        $condition_met = TRUE;
        // The moment we find a combination of a form and an operation which
        // we disallow, we stop checking the combinations because condition is
        // not met.
        foreach ($combinations as $combination) {
          list($form_id, $op) = explode('|', $combination);
          if (!empty($current_op) &&
              !empty($current_form_id) &&
              $current_op === $op &&
              $current_form_id === $form_id) {
            $condition_met = FALSE;
          }
          if (!$condition_met) {
            break;
          }
        }
        if ($condition_met) {
          $this->condition_met($context);
        }
      }
    }
  }
}
