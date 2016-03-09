<?php

/**
 * @file
 * Contains page callbacks and related functions for the admin UI.
 */

/**
 * Form displaying an overview over all searches available for autocompletion.
 *
 * @param SearchApiIndex $index
 *   The index for which autocompletion searches should be configured.
 *
 * @see search_api_autocomplete_admin_overview_submit()
 * @see search_api_autocomplete_admin_overview_submit_delete()
 * @ingroup forms
 */
function search_api_autocomplete_admin_overview(array $form, array &$form_state, SearchApiIndex $index) {
  $form = array();
  $form_state['index'] = $index;
  $index_id = $index->machine_name;

  $server = $index->server();
  if (!$server || !$server->supportsFeature('search_api_autocomplete')) {
    drupal_set_message(t("The server this index currently lies on doesn't support autocompletion. " .
        'To use autocompletion, you will have to move this index to a server supporting this feature.'), 'error');
    if (search_api_autocomplete_search_load_multiple(FALSE, array('index_id' => $index_id))) {
      $form['description'] = array(
        '#type' => 'item',
        '#title' => t('Delete autocompletion settings'),
        '#description' => t("If you won't use autocompletion with this index anymore, you can delete all autocompletion settings associated with it. " .
            "This will delete all autocompletion settings on this index. Settings on other indexes won't be influenced."),
      );
      $form['button'] = array(
        '#type' => 'submit',
        '#value' => t('Delete autocompletion settings'),
        '#submit' => array('search_api_autocomplete_admin_overview_submit_delete'),
      );
    }
    return $form;
  }

  $form['#tree'] = TRUE;
  $types = search_api_autocomplete_get_types();
  $searches = search_api_autocomplete_search_load_multiple(FALSE, array('index_id' => $index_id));
  $show_status = FALSE;
  foreach ($types as $type => $info) {
    if (empty($info['list searches'])) {
      continue;
    }
    $t_searches = $info['list searches']($index);
    if (empty($t_searches)) {
      $t_searches = array();
    }
    foreach ($t_searches as $id => $search) {
      if (isset($searches[$id])) {
        $types[$type]['searches'][$id] = $searches[$id];
        $show_status |= $searches[$id]->hasStatus(ENTITY_IN_CODE);
        unset($searches[$id]);
      }
      else {
        $search += array(
          'machine_name' => $id,
          'index_id' => $index_id,
          'type' => $type,
          'enabled' => 0,
          'options' => array(),
        );
        $search['options'] += array(
          'result count' => TRUE,
          'fields' => array(),
        );
        $types[$type]['searches'][$id] = entity_create('search_api_autocomplete_search', $search);
      }
    }
  }
  foreach ($searches as $id => $search) {
    $type = isset($types[$search->type]) ? $search->type : '';
    $types[$type]['searches'][$id] = $search;
    $types[$type]['unavailable'][$id] = TRUE;
    $show_status |= $search->hasStatus(ENTITY_IN_CODE);
  }
  $base_path = 'admin/config/search/search_api/index/' . $index_id . '/autocomplete/';
  foreach ($types as $type => $info) {
    if (empty($info['searches'])) {
      continue;
    }
    if (!$type) {
      $info += array(
        'name' => t('Unavailable search types'),
        'description' => t("The modules providing these searches were disabled or uninstalled. If you won't use them anymore, you can delete their settings."),
      );
    }
    elseif (!empty($info['unavailable'])) {
      $info['description'] .= '</p><p>' . t("The searches marked with an asterisk (*) are currently not available, possibly because they were deleted. If you won't use them anymore, you can delete their settings.");
    }
    $form[$type] = array(
      '#type' => 'fieldset',
      '#title' => $info['name'],
    );
    if (!empty($info['description'])) {
      $form[$type]['#description'] = '<p>' . $info['description'] . '</p>';
    }
    $form[$type]['searches']['#theme'] = 'tableselect';
    $form[$type]['searches']['#header'] = array();
    if ($show_status) {
      $form[$type]['searches']['#header']['status'] = t('Status');
    }
    $form[$type]['searches']['#header'] += array(
      'name' => t('Name'),
      'operations' => t('Operations'),
    );
    $form[$type]['searches']['#empty'] = '';
    $form[$type]['searches']['#js_select'] = TRUE;
    foreach ($info['searches'] as $id => $search) {
      $form[$type]['searches'][$id] = array(
        '#type' => 'checkbox',
        '#default_value' => $search->enabled,
        '#parents' => array('searches', $id),
      );
      $unavailable = !empty($info['unavailable'][$id]);
      if ($unavailable) {
        $form[$type]['searches'][$id]['#default_value'] = FALSE;
        $form[$type]['searches'][$id]['#disabled'] = TRUE;
      }
      $form_state['searches'][$id] = $search;
      $options = &$form[$type]['searches']['#options'][$id];
      if ($show_status) {
        $options['status'] = isset($search->status) ? theme('entity_status', array('status' => $search->status)) : '';;
      }
      $options['name'] = $search->name;
      if ($unavailable) {
        $options['name'] = '* ' . $options['name'];
      }
      $items = array();
      if (!$unavailable && !empty($search->id)) {
        $items[] = l(t('edit'), $base_path . $id . '/edit');
      }
      if (!empty($search->status) && ($search->hasStatus(ENTITY_CUSTOM))) {
        $title = $search->hasStatus(ENTITY_IN_CODE) ? t('revert') : t('delete');
        $items[] = l($title, $base_path . $id . '/delete');
      }
      if ($items) {
        $variables = array(
          'items' => $items,
          'attributes' => array('class' => array('inline')),
        );
        $options['operations'] = theme('item_list', $variables);
      }
      else {
        $options['operations'] = '';
      }
      unset($options);
    }
  }

  if (!element_children($form)) {
    $form['message']['#markup'] = '<p>' . t('There are currently no searches known for this index.') . '</p>';
  }
  else {
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save'),
    );
  }

  return $form;
}

/**
 * Submit callback for search_api_autocomplete_admin_overview().
 *
 * @see search_api_autocomplete_admin_overview()
 */
function search_api_autocomplete_admin_overview_submit(array $form, array &$form_state) {
  $msg = t('The settings have been saved.');
  foreach ($form_state['values']['searches'] as $id => $enabled) {
    $search = $form_state['searches'][$id];
    if ($search->enabled != $enabled) {
      $change = TRUE;
      if (!empty($search->is_new)) {
        $options['query']['destination'] = $_GET['q'];
        $options['fragment'] = 'module-search_api_autocomplete';
        $vars['@perm_url'] = url('admin/people/permissions', $options);
        $msg = t('The settings have been saved. Please remember to set the <a href="@perm_url">permissions</a> for the newly enabled searches.', $vars);
      }
      $search->enabled = $enabled;
      $search->save();
    }
  }
  drupal_set_message(empty($change) ? t('No values were changed.') : $msg);
}

/**
 * Submit callback for search_api_autocomplete_admin_overview(), when all
 * settings for the index should be deleted.
 *
 * @see search_api_autocomplete_admin_overview()
 */
function search_api_autocomplete_admin_overview_submit_delete(array $form, array &$form_state) {
  $index = $form_state['index'];
  $ids = array_keys(search_api_autocomplete_search_load_multiple(FALSE, array('index_id' => $index->machine_name)));
  if ($ids) {
    entity_delete_multiple('search_api_autocomplete_search', $ids);
    drupal_set_message(t('All autocompletion settings stored for this index were deleted.'));
  }
  else {
    drupal_set_message(t('There were no settings to delete.'), 'warning');
  }
  $form_state['redirect'] = 'admin/config/search/search_api/index/' . $index->machine_name;
}

/**
 * Form for editing the autocompletion settings for a search.
 *
 * @param SearchApiAutocompleteSearch $search
 *   The search whose settings should be edited.
 *
 * @ingroup forms
 *
 * @see search_api_autocomplete_admin_search_edit_validate()
 * @see search_api_autocomplete_admin_search_edit_submit()
 */
function search_api_autocomplete_admin_search_edit(array $form, array &$form_state, SearchApiAutocompleteSearch $search) {
  drupal_set_title(t('Edit %search', array('%search' => $search->name)), PASS_THROUGH);

  $form_state['search'] = $search;
  $form_state['type'] = $type = search_api_autocomplete_get_types($search->type);
  if (!$type) {
    drupal_set_message(t('No information about the type of this search was found.'), 'error');
    return array();
  }
  $form['#tree'] = TRUE;
  $form['enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enabled'),
    '#default_value' => $search->enabled,
  );
  $form['options']['min_length'] = array(
    '#type' => 'textfield',
    '#title' => t('Minimum length of keywords for autocompletion'),
    '#description' => t('If the entered keywords are shorter than this, no autocomplete suggestions will be displayed.'),
    '#default_value' => isset($search->options['min_length']) ? $search->options['min_length'] : 1,
    '#validate' => array('element_validate_integer_positive'),
  );
  $form['options']['results'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display result count estimates'),
    '#description' => t('Display the estimated number of result for each suggestion. ' .
        'This option might not have an effect for some servers or types of suggestion.'),
    '#default_value' => !empty($search->options['results']),
  );

  // Add a list of fields to include for autocomplete searches.
  $fields = $search->index()->getFields();
  $fulltext_fields = $search->index()->getFulltextFields();
  $options = array();
  foreach ($fulltext_fields as $field) {
    $options[$field] = $fields[$field]['name'];
  }
  $form['options']['fields'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Fields to use'),
    '#description' => t('Select the fields which should be searched for matches when looking for autocompletion suggestions. Leave blank to use the same fields as the underlying search.'),
    '#options' => $options,
    '#default_value' => empty($search->options['fields']) ? array() : drupal_map_assoc($search->options['fields']),
    '#attributes' => array('class' => array('search-api-checkboxes-list')),
  );

  $custom_form = empty($form['options']['custom']) ? array() : $form['options']['custom'];
  if (!empty($type['config form']) && function_exists($type['config form']) && is_array($custom_form = $type['config form']($custom_form, $form_state, $search))) {
    $form['options']['custom'] = $custom_form;
  }

  $form['advanced'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['advanced']['submit_button_selector'] = array(
    '#type' => 'textfield',
    '#title' => t('Search button selector'),
    '#description' => t('<a href="@jquery_url">jQuery selector</a> to identify the search button in the search form. Use the ID attribute of the "Search" submit button to prevent issues when another button is present (e.g., "Reset"). The selector is evaluated relative to the form. The default value is ":submit".', array('@jquery_url' => 'https://api.jquery.com/category/selectors/')),
    '#default_value' => isset($search->options['submit_button_selector']) ? $search->options['submit_button_selector'] : ':submit',
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

/**
 * Validate callback for search_api_autocomplete_admin_search_edit().
 *
 * @see search_api_autocomplete_admin_search_edit()
 * @see search_api_autocomplete_admin_search_edit_submit()
 */
function search_api_autocomplete_admin_search_edit_validate(array $form, array &$form_state) {
  if (empty($form_state['type']['config form'])) {
    return;
  }
  $f = $form_state['type']['config form'] . '_validate';
  if (function_exists($f)) {
    $custom_form = empty($form['options']['custom']) ? array() : $form['options']['custom'];
    $f($custom_form, $form_state, $form_state['values']['options']['custom']);
  }
}

/**
 * Submit callback for search_api_autocomplete_admin_search_edit().
 *
 * @see search_api_autocomplete_admin_search_edit()
 * @see search_api_autocomplete_admin_search_edit_validate()
 */
function search_api_autocomplete_admin_search_edit_submit(array $form, array &$form_state) {
  $values = &$form_state['values'];
  if (!empty($form_state['type']['config form'])) {
    $f = $form_state['type']['config form'] . '_submit';
    if (function_exists($f)) {
      $custom_form = empty($form['options']['custom']) ? array() : $form['options']['custom'];
      $f($custom_form, $form_state, $values['options']['custom']);
    }
  }

  $search = $form_state['search'];
  $search->enabled = $values['enabled'];
  $search->options['results'] = $values['options']['results'];
  $search->options['min_length'] = $values['options']['min_length'];
  $search->options['fields'] = array_keys(array_filter($values['options']['fields']));
  $search->options['submit_button_selector'] = $form_state['values']['advanced']['submit_button_selector'];
  if (isset($values['options']['custom'])) {
    // Take care of custom options that aren't changed in the config form.
    $old = empty($search->options['custom']) ? array() : $search->options['custom'];
    $search->options['custom'] = $values['options']['custom'] + $old;
  }

  $search->save();
  drupal_set_message(t('The autocompletion settings for the search have been saved.'));
  $form_state['redirect'] = 'admin/config/search/search_api/index/' . $search->index_id . '/autocomplete';
}

/**
 * Form for deleting the autocompletion settings of a search.
 *
 * @param SearchApiAutocompleteSearch $search
 *   The search whose settings should be deleted.
 *
 * @see search_api_autocomplete_admin_search_delete_submit()
 * @ingroup forms
 */
function search_api_autocomplete_admin_search_delete(array $form, array &$form_state, SearchApiAutocompleteSearch $search) {
  $form_state['search'] = $search;
  return confirm_form(
    $form,
    t('Do you really want to delete the autocompletion settings for search %search?', array('%search' => $search->name)),
    'admin/config/search/search_api/index/' . $search->index_id . '/autocomplete'
  );
}

/**
 * Submit callback for search_api_autocomplete_admin_search_delete().
 *
 * @see search_api_autocomplete_admin_search_delete()
 */
function search_api_autocomplete_admin_search_delete_submit(array $form, array &$form_state) {
  $form_state['search']->delete();
  drupal_set_message(t('The autocompletion settings for the search have been deleted.'));
  $form_state['redirect'] = 'admin/config/search/search_api/index/' . $form_state['search']->index_id . '/autocomplete';
}
