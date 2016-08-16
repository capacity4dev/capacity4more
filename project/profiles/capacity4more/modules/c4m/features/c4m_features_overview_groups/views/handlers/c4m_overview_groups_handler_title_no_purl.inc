<?php

/**
 * @file
 * Contains the handler for node's title field.
 */

/**
 * When a node title's is linked inside a group context, the URL is modified
 * by the PURL API. This handler adds the option field to Disable PURL,
 * and adds the direct link to the node.
 *
 * @ingroup views_field_handlers
 */
class c4m_overview_groups_handler_title_no_purl extends views_handler_field_node {

  /**
   * {@inheritdoc}
   */
  function option_definition() {
    $options = parent::option_definition();

    // Checks if the option has been already selected.
    $default = $this->definition['disable_purl default'];
    $is_selected = isset($default) ? $default : FALSE;

    // Sets the option value.
    $options['disable_purl'] = array('default' => $is_selected, 'bool' => TRUE);

    return $options;
  }

  /**
   * {@inheritdoc}
   */
  function options_form(&$form, &$form_state) {
    $form['disable_purl'] = array(
      '#title' => t('Disable PURL'),
      '#description' => t("Disable persistent URL from links."),
      '#type' => 'checkbox',
      '#default_value' => $this->options['disable_purl'],
    );

    parent::options_form($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  function render_link($data, $values) {

    if ($this->options['disable_purl']) {
      return l($values->node_title, 'node/' . $this->get_value($values, 'nid'), ['purl' => array('disabled' => TRUE)]);
    }

    return parent::render_link($data, $values);
  }
}
