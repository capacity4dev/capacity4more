<?php
// @codingStandardsIgnoreFile

/**
 * @file
 * Handler to add a node add button to a view area.
 */

/**
 * Views area handler to display a button to add new content.
 *
 * The handler will validate if the user has the proper rights to add the new
 * content.
 *
 * @ingroup views_area_handlers
 */
class c4m_views_handler_area_node_add extends views_handler_area {
  /**
   * {@inheritdoc}
   */
  public function option_definition() {
    $options = parent::option_definition();

    $options['node_type'] = array(
      'default' => NULL,
    );
    $options['link_text'] = array(
      'default' => 'Add content',
      'translatable' => TRUE,
    );
    $options['icon'] = array(
      'default' => NULL,
    );

    return $options;
  }

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['node_type'] = array(
      '#type' => 'select',
      '#required' => TRUE,
      '#title' => t('Node type'),
      '#description' => t('Select to what kind of Node type creation form the link will point.'),
      '#default_value' => $this->options['node_type'],
      '#options' => node_type_get_names(),
    );
    $form['link_text'] = array(
      '#type' => 'textfield',
      '#required' => TRUE,
      '#title' => t('Link text'),
      '#description' => t('Set the label for the link.'),
      '#default_value' => $this->options['link_text'],
    );
    $form['icon'] = array(
      '#type' => 'textfield',
      '#required' => FALSE,
      '#title' => t('Icon'),
      '#description' => t('Set the Font Awesome icon class for the link.'),
      '#default_value' => $this->options['icon'],
    );
  }

  /**
   * {@inheritdoc}
   */
  public function render($empty = FALSE) {
    $node_type = filter_xss_admin($this->options['node_type']);
    $link_text = filter_xss_admin($this->options['link_text']);
    $icon = filter_xss_admin($this->options['icon']);
    if (!$node_type || !$link_text) {
      return;
    }

    // Check if user has access to the node creation form.
    if (!node_access('create', $node_type)) {
      return;
    }
    
    if ($context = og_context()) {
      if (!og_user_access($context['group_type'], $context['gid'], "create {$node_type} content")) {
        return;
      }
    }

    $options = array(
      'attributes' => array(
        'class' => array('node-create', 'node-create-' . $node_type),
      ),
    );


    if ($icon) {
      $link_text = '<i class="fa ' . $icon . '" aria-hidden="true"></i> ' . $link_text;
    }

    return $link_text = l($link_text, 'node/add/' . $node_type, $options);
  }

}
