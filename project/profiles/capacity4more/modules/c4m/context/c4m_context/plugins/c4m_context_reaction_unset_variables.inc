<?php
// @codingStandardsIgnoreFile

/**
 * @file
 * Context plugin.
 */

/**
 * Expose organic groups as context reactions.
 */
class c4m_context_reaction_unset_variables extends context_reaction {

  /**
   * Provide a form element that allow the admin to chose a menu item.
   */
  function options_form($context) {
    $default_value = $this->fetch_from_context($context);

    return array(
      '#title'         => t('Unset variables'),
      '#type'          => 'textarea',
      '#description'   => t('Enter variables (one per line) to unset on page load.') . ' ' . t('For example: "main_menu" and "secondary_menu" to prevent the navigation menus to appear in the header.'),
      '#default_value' => is_string($default_value) ? $default_value : '',
    );
  }

  function execute(&$variables) {
    // Get the list of contexts associated with this reaction.
    $contexts = $this->get_contexts();

    // Iterate through each, and process those with something set.
    foreach ($contexts as $context) {
      if (isset($context->reactions) && (!empty($context->reactions[$this->plugin]))) {
        $vars_unset = $this->fetch_from_context($context, 'values');
        if (!empty($vars_unset)) {
          $vars_unset = explode("\n", $vars_unset);
          foreach ($vars_unset as $var) {
            $var = trim($var);
            if (!empty($variables[$var])) {
              $variables[$var] = NULL;
            }
          }
        }
      }
    }

  }
}
