<?php

/**
 * @file
 * Provides an MEFIBS exposed form plugin for View 3.x.
 */

/**
 * Display Extender Plugin class.
 */
class mefibs_display_extender_plugin_blocks extends views_plugin_display_extender {

  /**
   * Retrieve enabled blocks.
   *
   * @return array
   *   An array with all additional blocks, keys are the machine_names and the
   * values the block titles.
   */
  public function get_enabled_blocks() {
    $blocks = array();
    $settings = $this->display->get_option('mefibs');
    if (!isset($settings['blocks'])) {
      return array();
    }
    foreach ($settings['blocks'] as $block) {
      $blocks[$block['machine_name']] = $block['name'];
    }
    return $blocks;
  }

  function get_block_options($machine_name) {
    $settings = $this->display->get_option('mefibs');
    if (!isset($settings['blocks'])) {
      return array();
    }
    foreach ($settings['blocks'] as $block) {
      if ($block['machine_name'] == $machine_name) {
        $block_settings = $block + array(
          'submit_button' => t('Submit'),
          'reset_button' => FALSE,
          'reset_button_label' => t('Reset'),
          'autosubmit' => FALSE,
          'autosubmit_hide' => FALSE,
        );
        return $block_settings;
      }
    }
  }

  /**
   * Define options used by this module.
   *
   * options_definition_alter() is used instead of option_definition() to allow
   * the options to be exportable.
   * @see https://drupal.org/node/2128119
   */
  public function options_definition_alter(&$options) {
    $options['mefibs'] = array(
      'default' => array(
        'blocks' => array(),
      ),
    );
  }

  /**
   * Provide a title for the options summary.
   */
  function summary_title() {
    return t('MEFIBS Settings');
  }

  /**
   * Provide an option summary.
   */
  function options_summary(&$categories, &$options) {
    if ($this->display->get_option('exposed_block')) {
      $value = t('Default');
      $blocks = $this->get_enabled_blocks();
      if (count($blocks)) {
        $value = t('Default + !count', array('!count' => count($blocks)));
      }
      $options['mefibs'] = array(
        'category' => 'exposed',
        'title' => t('Exposed form blocks'),
        'value' => $value,
        'desc' => t('Control which blocks can be used for exposed forms.'),
      );
    }
  }

  /**
   * Provide a form to edit options for this plugin.
   */
  function options_form(&$form, &$form_state) {
    if ($form_state['section'] == 'mefibs') {

      // Add javascript needed for ajax form behaviors.
      drupal_add_js(drupal_get_path('module', 'mefibs') . '/js/mefibs_admin.js');
      drupal_add_css(drupal_get_path('module', 'mefibs') . '/css/mefibs_admin.css');

      $ajax_callback_base_path = 'admin/structure/views/view/' . $form_state['view']->name . '/edit/' . $form_state['view']->current_display . '/ajax/mefibs';
      
      $exposed_settings = $this->display->get_option('exposed_form');
      $default_options = $exposed_settings['options'];
      $default_block = array(
        'name' => t('Default'),
        'machine_name' => 'default',
        'reset_button' => $default_options['reset_button'],
        'reset_button_label' => $default_options['reset_button_label'],
        'autosubmit' => $default_options['autosubmit'],
        'autosubmit_hide' => $default_options['autosubmit_hide'],
      );

      // Get the settings.
      $settings = $this->display->get_option('mefibs');
      $blocks = $settings['blocks'];

      // Find out if we are in an edit context here.
      $edit = FALSE;
      if (isset($form_state['storage']['action']) && $form_state['storage']['action'] == 'edit') {
        $edit = $form_state['storage']['id'];
      }

      $form['#mefibs_block_edit'] = $edit !== FALSE;

      if (isset($form_state['view']->form_cache['blocks'])) {
        $blocks = $form_state['view']->form_cache['blocks'];
        if ($edit === FALSE && $blocks != $settings['blocks']) {
          drupal_set_message('* ' . t('All changes are stored temporarily. Click Apply to make your changes permanent. Click Cancel to discard your changes.'), 'warning', FALSE);
        }
      }

      $form['mefibs'] = array(
        '#blocks' => $blocks,
        '#tree' => TRUE,
      );
      $form['#title'] .= t('Enable additional blocks for exposed elements');
      
      $form['mefibs']['description'] = array(
        '#type' => 'markup',
        '#markup' => t('Choose which blocks are available for exposed input fields for this display.'),
        '#prefix' => '<div class="description">',
        '#suffix' => '</div>',
      );
      $form['mefibs']['blocks'] = array(
        '#prefix' => '<div id="mefibs-display-extender-blocks-wrapper">',
        '#suffix' => '</div>',
        '#theme' => 'mefibs_views_ui_block_list',
      );

      $default_items_per_page = -1;
      if (!isset($settings['extras']['items_per_page']) || $settings['extras']['items_per_page'] === -1) {
        $default_items_per_page = -1;
      }
      else {
        $machine_name = $settings['extras']['items_per_page'];
        foreach ($blocks as $id => $block) {
          if ($block['machine_name'] == $machine_name) {
            $default_items_per_page = $id;
            break;
          }
        }
      }
      
      $default_sort = -1;
      if (!isset($settings['extras']['sort']) || $settings['extras']['sort'] === -1) {
        $default_sort = -1;
      }
      else {
        $machine_name = $settings['extras']['sort'];
        foreach ($blocks as $id => $block) {
          if ($block['machine_name'] == $machine_name) {
            $default_sort = $id;
            break;
          }
        }
      }

      if (!is_array($blocks)) {
        $blocks = array($default_block);
      }
      if (!in_array($default_block, $blocks, TRUE)) {
        $blocks = array_merge($blocks, array($default_block));
      }

      for ($id = 0; $id < count($blocks); $id++) {
        $block_settings = $blocks[$id];
        if ($edit === $id) {
          $form['mefibs']['blocks'][$id]['name'] = array(
            '#type' => 'textfield',
            '#default_value' => $blocks[$id]['name'],
            '#size' => 12,
          );
          $form['mefibs']['blocks'][$id]['machine_name'] = array(
            '#type' => 'machine_name',
            '#machine_name' => array(
              'label' => t('Machine name'),
              'source' => array('options', 'mefibs', 'blocks', $id, 'name'),
              'exists' => 'mefibs_block_machine_name_exists',
            ),
            '#required' => FALSE,
            '#default_value' => $blocks[$id]['machine_name'],
            '#size' => 12,
          );
          $form['mefibs']['blocks'][$id]['submit_button'] = array(
            '#type' => 'textfield',
            '#title' => t('Submit button text'),
            '#description' => t('Text to display in the submit button of the exposed form.'),
            '#default_value' => $block_settings['submit_button'],
            '#required' => TRUE,
          );
          $form['mefibs']['blocks'][$id]['reset_button'] = array(
            '#type' => 'checkbox',
            '#title' => t('Include reset button'),
            '#description' => t('If checked the exposed form will provide a button to reset all the applied exposed filters'),
            '#default_value' => $block_settings['reset_button'],
            '#attributes' => $block_settings['reset_button'] ? array('checked' => 'checked') : array(),
          );
          $form['mefibs']['blocks'][$id]['reset_button_label'] = array(
            '#type' => 'textfield',
            '#title' => t('Reset button label'),
            '#description' => t('Text to display in the reset button of the exposed form.'),
            '#default_value' => $block_settings['reset_button_label'],
            '#size' => 10,
            '#dependency' => array(
              'edit-mefibs-blocks-' . $id . '-reset-button' => array(1),
            ),
          );
          $form['mefibs']['blocks'][$id]['autosubmit'] = array(
            '#type' => 'checkbox',
            '#title' => t('Autosubmit'),
            '#description' => t('Automatically submit the form once an element is changed.'),
            '#default_value' => $block_settings['autosubmit'],
            '#attributes' => $block_settings['autosubmit'] ? array('checked' => 'checked') : array(),
          );
          $form['mefibs']['blocks'][$id]['autosubmit_hide'] = array(
            '#type' => 'checkbox',
            '#title' => t('Hide submit button'),
            '#description' => t('Hide submit button if autosubmit is enabled.'),
            '#default_value' => $block_settings['autosubmit_hide'],
            '#dependency' => array(
              'edit-mefibs-blocks-' . $id . '-autosubmit' => array(1),
            ),
          );
        }
        else {
          $form['mefibs']['blocks'][$id]['name'] = array(
            '#type' => 'markup',
            '#markup' => $blocks[$id]['name'],
          );
          $form['mefibs']['blocks'][$id]['machine_name'] = array(
            '#type' => 'markup',
            '#markup' => $blocks[$id]['machine_name'],
          );
          $form['mefibs']['blocks'][$id]['reset_button'] = array(
            '#type' => 'checkbox',
            '#default_value' => $block_settings['reset_button'],
            '#attributes' => array('disabled' => 'disabled'),
          );
          // Somehow this is necessary to keep the checkbox check during form
          // interaction.
          if ($block_settings['reset_button']) {
            $form['mefibs']['blocks'][$id]['reset_button']['#attributes']['checked'] = 'checked';
          }
          $form['mefibs']['blocks'][$id]['autosubmit'] = array(
            '#type' => 'checkbox',
            '#default_value' => $block_settings['autosubmit'],
            '#attributes' => array('disabled' => 'disabled'),
          );
          // Somehow this is necessary to keep the checkbox check during form
          // interaction.
          if ($block_settings['autosubmit']) {
            $form['mefibs']['blocks'][$id]['autosubmit']['#attributes']['checked'] = 'checked';
          }
        }

        $items = mefibs_get_expected_items_for_exposed_form_block($this->view, $blocks[$id]['machine_name']);

        $form['mefibs']['blocks'][$id]['filters'] = array(
          '#type' => 'markup',
          '#markup' => count($items['filter']),
          '#access' => $edit !== $id,
        );
        $form['mefibs']['blocks'][$id]['sorts'] = array(
          '#type' => 'markup',
          '#markup' => count($items['sort']),
          '#access' => $edit !== $id,
        );

        if ($blocks[$id]['machine_name'] != 'default') {
          $actions = array(
            'edit' => t('Edit'),
            'save' => t('Save'),
            'cancel' => t('Cancel'),
            'remove' => t('Remove'),
          );
          foreach ($actions as $type => $label) {
            $form['mefibs']['blocks'][$id]['actions'][$type] = array(
              '#type' => 'submit',
              '#default_value' => $label,
              '#name' => 'edit-mefibs-block-action-' . $type . '-' . $id,
              '#group' => $id,
              '#access' => $edit === FALSE || $edit === $id,
            );
          }
          if ($edit !== FALSE && $edit === $id) {
            $form['mefibs']['blocks'][$id]['actions']['edit']['#prefix'] = '<div style="display: none;">';
            $form['mefibs']['blocks'][$id]['actions']['edit']['#suffix'] = '</div>';
            $form['mefibs']['blocks'][$id]['actions']['edit']['#weight'] = 100;
            $form['mefibs']['blocks'][$id]['actions']['remove']['#prefix'] = '<div style="display: none;">';
            $form['mefibs']['blocks'][$id]['actions']['remove']['#suffix'] = '</div>';
            $form['mefibs']['blocks'][$id]['actions']['remove']['#weight'] = 100;
          }
          else {
            $form['mefibs']['blocks'][$id]['actions']['save']['#prefix'] = '<div style="display: none;">';
            $form['mefibs']['blocks'][$id]['actions']['save']['#suffix'] = '</div>';
            $form['mefibs']['blocks'][$id]['actions']['save']['#weight'] = 100;
            $form['mefibs']['blocks'][$id]['actions']['cancel']['#prefix'] = '<div style="display: none;">';
            $form['mefibs']['blocks'][$id]['actions']['cancel']['#suffix'] = '</div>';
            $form['mefibs']['blocks'][$id]['actions']['cancel']['#weight'] = 100;
          }
        }
      }

      // The "add new block". This won't show when an indivdual block is
      // edited.
      $form['mefibs']['add_block'] = array(
        '#type' => 'fieldset',
        '#title' => t('Add new block'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
        '#access' => $edit === FALSE,
      );
      $form['mefibs']['add_block']['name'] = array(
        '#type' => 'textfield',
        '#title' => t('Block name'),
        '#default_value' => '',
        '#access' => $edit === FALSE,
      );
      $form['mefibs']['add_block']['machine_name'] = array(
        '#type' => 'machine_name',
        '#machine_name' => array(
          'label' => t('Machine name'),
          'source' => array('options', 'mefibs', 'add_block', 'name'),
          'exists' => 'mefibs_block_machine_name_exists',
        ),
        '#required' => FALSE,
        '#default_value' => '',
        '#access' => $edit === FALSE,
      );
      $form['mefibs']['add_block']['submit'] = array(
        '#type' => 'submit',
        '#default_value' => t('Add block'),
        '#attributes' => array(
          'class' => array('mefibs-add-block'),
        ),
        // This is convenient to decide on the triggered action in
        // options_submit().
        '#parents' => array('mefibs', 'blocks', NULL, 'add'),
        '#group' => 'add',
        '#access' => $edit === FALSE,
      );
    }
    $form['#validate'] = array('views_ui_edit_display_form_validate');
    $form['#submit'] = array('views_ui_edit_display_form_submit');
  }

  /**
   * Handle any special handling on the form submission.
   */
  function options_validate(&$form, &$form_state) {
    if ($form_state['section'] == 'mefibs') {
      $values = $form_state['values'];
      $add_block = $values['mefibs']['add_block'];
      $button = $form_state['triggering_element'];
      if (isset($button['#group']) && $button['#group'] === 'add') {
        // New block should be added, check for submitted values
        if (empty($add_block['name'])) {
          form_set_error('mefibs][add_block][name', t('Please enter a name for the block.'));
        }
      }
    }
  }

  /**
   * Handle any special handling on the form submission.
   */
  function options_submit(&$form, &$form_state) {
    if ($form_state['section'] == 'mefibs') {
      $values = $form_state['values'];

      $blocks = $form['options']['mefibs']['#blocks'];
      if (isset($form_state['view']->form_cache['blocks'])) {
        $blocks = $form_state['view']->form_cache['blocks'];
      }
      foreach ($blocks as $id => $block) {
        if ($block['machine_name'] == 'default') {
          unset($blocks[$id]);
        }
      }

      // If the #group property is set on the clicked button, that means we are
      // modifying a block, not actually updating the settings.
      $button = $form_state['triggering_element'];
      if (isset($button['#group'])) {
        $action = array_pop($button['#parents']);
        array_pop($button['#parents']);
        $id = array_pop($button['#parents']);
        
        // Store the action arguments to have them accessible in
        // options_form().
        $form_state['storage']['action'] = $action;
        $form_state['storage']['id'] = $id;

        switch ($action) {
          case 'add':
            // New block to be added.
            $blocks[] = array(
              'name' => $values['mefibs']['add_block']['name'],
              'machine_name' => $values['mefibs']['add_block']['machine_name'],
              'submit_button' => t('Submit'),
              'reset_button' => FALSE,
              'reset_button_label' => t('Reset'),
              'autosubmit' => FALSE,
              'autosubmit_hide' => FALSE,
            );
            // This is the only working way I have found to clear the input
            // values.
            $form_state['input']['mefibs']['add_block']['name'] = '';
            $form_state['input']['mefibs']['add_block']['machine_name'] = '';
            break;

          case 'remove':
            // Block to be removed.
            unset($blocks[$id]);
            break;
            
          case 'edit':
            // Block to be edited.
            break;
          
          case 'save':
            // Block to be saved.
            $blocks[$id] = array(
              'name' => $form_state['input']['mefibs']['blocks'][$id]['name'],
              'machine_name' => $form_state['input']['mefibs']['blocks'][$id]['machine_name'],
              'submit_button' => $form_state['input']['mefibs']['blocks'][$id]['submit_button'],
              'reset_button' => $form_state['input']['mefibs']['blocks'][$id]['reset_button'],
              'reset_button_label' => $form_state['input']['mefibs']['blocks'][$id]['reset_button_label'],
              'autosubmit' => $form_state['input']['mefibs']['blocks'][$id]['autosubmit'],
              'autosubmit_hide' => $form_state['input']['mefibs']['blocks'][$id]['autosubmit_hide'],
            );
            break;
        }
        
        $form_state['rerender'] = TRUE;
        $form_state['rebuild'] = TRUE;
        $form_state['view']->form_cache = array(
          'key' => 'display',
          'blocks' => array_values($blocks),
        );
        
      }
      else {
        // Save settings.
        if (isset($values['mefibs']['extras'])) {
          $extras = $values['mefibs']['extras'];
        }
        else {
          $extras = array(
            'sort' => -1,
            'items_per_page' => -1,
          );
        }
        $settings = array(
          'blocks' => array_values($blocks),
          'extras' => array(
            'sort' => $extras['sort'] != -1 ? $blocks[$extras['sort']]['machine_name'] : -1,
            'items_per_page' => $extras['items_per_page'] != -1 ? $blocks[$extras['items_per_page']]['machine_name'] : -1,
          ),
        );
        
        $mefibs = $this->display->get_option('mefibs');
        if ($mefibs) {
          $settings = $settings + $mefibs;
        }

        // Remove filter associations for deleted blocks.
        $block_ids = array();
        foreach ($blocks as $block) {
          $block_ids[] = $block['machine_name'];
        }
        mefibs_remove_block_association_recursive($settings[$this->view->current_display], $block_ids);

        // Finally, update the mefibs settings for this display.
        $this->display->set_option('mefibs', $settings);
        views_ui_cache_set($this->view);
      }
      
    }
    
  }

}
