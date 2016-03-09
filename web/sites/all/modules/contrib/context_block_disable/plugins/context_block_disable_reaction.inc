<?php
/**
 * @file
 * Context reaction plugin for disabling blocks.
 *
 * This provides a reaction for the Context module that will hide the selected
 * blocks whenever the Context condition is met.
 */

/**
 * Context reaction plugin for disabling blocks.
 */
class Context_Block_Disable_Reaction extends context_reaction_block {

  // The block this plugin needs to consider.
  protected $reaction_block = NULL;

  /**
   * Implements options_form() callback.
   *
   * Overrides the parent function in order to pull out only the part of the
   * form we care about, and adjust the selected values due to that change.
   */
  public function options_form($context) {

    // Rebuild the block info cache if necessary.
    $this->get_blocks(NULL, NULL, $this->rebuild_needed());
    $this->rebuild_needed(FALSE);

    $settings = $this->fetch_from_context($context);

    $form = array('#tree' => TRUE);

    $modules = module_list();
    $form['selector'] = array(
      '#type' => 'item',
      '#tree' => TRUE,
    );
    foreach ($this->get_blocks() as $block) {
      $group = isset($block->context_group) ? $block->context_group : $block->module;
      if (!isset($form['selector'][$group])) {
        $form['selector'][$group] = array(
          '#type' => 'checkboxes',
          '#title' => isset($block->context_group) ? $block->context_group : $modules[$block->module],
          '#options' => array(),
        );
      }
      $form['selector'][$group]['#options'][$block->bid] = check_plain($block->info);

      // Set up the selected blocks.
      if (!empty($settings['blocks'][$block->bid])) {

        $form['selector'][$group]['#default_value'][] = $block->bid;
      }
    }
    ksort($form['selector']);

    return $form;
  }

  /**
   * Implements options_form_submit() callback.
   *
   * Overrides the parent function in order to handle the lack of regions in
   * this plugin.
   */
  public function options_form_submit($values) {

    $blocks = array();
    $block_info = $this->get_blocks();

    foreach ($values['selector'] as $module => $selections) {

      foreach ($selections as $selected) {

        if (!empty($selected)) {

          $blocks[$selected] = array(
            'module' => $block_info[$selected]->module,
            'delta' => $block_info[$selected]->delta,
            'region' => $block_info[$selected]->region,
            'weight' => $block_info[$selected]->weight,
          );
        }
      }
    }

    return array('blocks' => $blocks);
  }

  /**
   * Disables selected modules if a condition implements this plugin.
   *
   * @param array &$data
   *   The block data array (subject, content).
   *
   * @see hook_block_view_alter()
   */
  public function execute(&$data) {

    // Exit early if no reaction block was set or data has no content.
    if (empty($this->reaction_block) || empty($data['content'])) {

      return;
    }
    $block = $this->reaction_block;

    // Construct a bid that matches what we use on the settings form and what
    // context_reaction_block also uses.
    $bid = $block->module . '-' . $block->delta;

    $contexts = $this->get_contexts();
    foreach ($contexts as $context) {

      if (!empty($context->reactions[$this->plugin])) {

        $blocks = $context->reactions[$this->plugin]['blocks'];
        if (!empty($blocks[$bid])) {

          // Swap non-render arrays into render arrays when configured as such.
          if (variable_get('context_block_disable_force_array', FALSE)) {

            if (!is_array($data['content'])) {

              $data['content'] = array('#markup' => $data['content']);
            }
          }

          if (is_array($data['content'])) {

            // Leave the actual block contents alone, just stop users from being
            // able to access it.
            $data['content']['#access'] = FALSE;
          }
          else {

            $data['content'] = NULL;
          }
        }
      }
    }
  }

  /**
   * Sets the block this plugin should use for comparison operations.
   *
   * @param object $block
   *   A block object that at minimum contains the module and delta properties.
   */
  public function set_reaction_block($block) {

    $this->reaction_block = $block;
  }
}
