<?php
/**
 * @file
 * Custom manage page callbacks for the taxonomy module.
 */

/**
 * Form builder for the category management overview.
 *
 * Display a tree of all the terms in a vocabulary, with options to edit
 * each one. The form is made drag and drop by the theme function.
 *
 * @ingroup forms
 */
function c4m_features_og_manage_categories_overview_form($form, &$form_state) {
  $form = c4m_feature_og_manage_get_form_info($form);

  $parameters = drupal_get_query_parameters();
  // Check for confirmation forms.
  if (isset($parameters['delete'])) {
    // Delete confirmation form.
    return array_merge($form, c4m_features_og_manage_taxonomy_term_confirm_delete($form, $form_state, $parameters['delete']));
  }
  if (isset($parameters['reset_alphabetical'])) {
    // Reset alphabetically confirmation form.
    return c4m_features_og_manage_categories_overview_confirm_reset_alphabetical($form, $form_state, $form['#vocabulary']->vid, $parameters['reset_alphabetical']);
  }

  $tree = taxonomy_get_tree($form['#vocabulary']->vid);

  $form = c4m_features_og_manage_build_form($form, $tree, 'terms');

  return $form;
}

/**
 * Form builder for the category types management overview.
 *
 * Display a list of all the 1st level terms in a vocabulary, with options to edit
 * each one. The form is made drag and drop by the theme function.
 *
 * @ingroup forms
 */
function c4m_features_og_manage_categories_types_overview_form($form, &$form_state) {
  $form = c4m_feature_og_manage_get_form_info($form);

  $parameters = drupal_get_query_parameters();
  // Check for confirmation forms.
  if (isset($parameters['delete'])) {
    // Delete confirmation form.
    return array_merge($form, c4m_features_og_manage_taxonomy_term_confirm_delete($form, $form_state, $parameters['delete']));
  }
  if (isset($parameters['reset_alphabetical'])) {
    // Reset alphabetically confirmation form.
    return c4m_features_og_manage_categories_overview_confirm_reset_alphabetical($form, $form_state, $form['#vocabulary']->vid, $parameters['reset_alphabetical']);
  }

  $tree = taxonomy_get_tree($form['#vocabulary']->vid, 0, 1);

  $form = c4m_features_og_manage_build_form($form, $tree, 'types');

  return $form;
}

/**
 * Submit handler for the category terms management page.
 * Handles Reordering - Delete - Reset alphabetical - Instant create new term.
 */
function c4m_features_og_manage_categories_overview_form_submit($form, &$form_state) {
  if ($form_state['triggering_element']['#value'] == t('Delete')) {
    // Execute the term deletion.
    if ($form_state['values']['delete'] === TRUE) {
      c4m_features_og_manage_taxonomy_term_confirm_delete_submit($form, $form_state);
      return;
    }
  }

  if ($form_state['triggering_element']['#value'] == t('Reset to alphabetical')) {
    // Execute the term reset alphabetical.
    if ($form_state['values']['reset_alphabetical'] === TRUE) {
      c4m_features_og_manage_categories_overview_confirm_reset_alphabetical_submit($form, $form_state);
      return;
    }
  }

  if ($form_state['triggering_element']['#value'] == t('Add Term')) {
    // Execute adding a term.
    c4m_features_og_manage_categories_overview_add_term_submit($form, $form_state);
    return;
  }

  $vocabulary = $form['#vocabulary'];
  $hierarchy = 0; // Update the current hierarchy type as we go.

  $changed_terms = array();

  $menu_item = menu_get_item(current_path());
  $tree = $menu_item['path'] == 'manage/categories/types' ? taxonomy_get_tree($vocabulary->vid, 0, 1) : taxonomy_get_tree($vocabulary->vid);

  if (empty($tree)) {
    return;
  }

  // Build a list of all terms that need to be updated on previous pages.
  $weight = 0;
  $term = (array) $tree[0];
  while ($term['tid'] != $form['#first_tid']) {
    if ($term['parents'][0] == 0 && $term['weight'] != $weight) {
      $term['parent'] = $term['parents'][0];
      $term['weight'] = $weight;
      $changed_terms[$term['tid']] = $term;
    }
    $weight++;
    $hierarchy = $term['parents'][0] != 0 ? 1 : $hierarchy;
    $term = (array) $tree[$weight];
  }

  // Renumber the current page weights and assign any new parents.
  $level_weights = array();
  foreach ($form_state['values'] as $tid => $values) {
    if (isset($form[$tid]['#term'])) {
      $term = $form[$tid]['#term'];
      // Give terms at the root level a weight in sequence with terms on previous pages.
      if ($values['parent'] == 0 && $term['weight'] != $weight) {
        $term['weight'] = $weight;
        $changed_terms[$term['tid']] = $term;
      }
      // Terms not at the root level can safely start from 0 because they're all on this page.
      elseif ($values['parent'] > 0) {
        $level_weights[$values['parent']] = isset($level_weights[$values['parent']]) ? $level_weights[$values['parent']] + 1 : 0;
        if ($level_weights[$values['parent']] != $term['weight']) {
          $term['weight'] = $level_weights[$values['parent']];
          $changed_terms[$term['tid']] = $term;
        }
      }
      $hierarchy = $term['parent'] != 0 ? 1 : $hierarchy;
      $weight++;
    }
  }

  // Build a list of all terms that need to be updated on following pages.
  for ($weight; $weight < count($tree); $weight++) {
    $term = (array) $tree[$weight];
    if ($term['parents'][0] == 0 && $term['weight'] != $weight) {
      $term['parent'] = $term['parents'][0];
      $term['weight'] = $weight;
      $changed_terms[$term['tid']] = $term;
    }
    $hierarchy = $term['parents'][0] != 0 ? 1 : $hierarchy;
  }
  // Save all updated terms.
  foreach ($changed_terms as $changed) {
    $term = (object) $changed;
    // Update term_hierarchy and term_data directly since we don't have a
    // fully populated term object to save.
    db_update('taxonomy_term_hierarchy')
      ->fields(array('parent' => $term->parent))
      ->condition('tid', $term->tid, '=')
      ->execute();

    db_update('taxonomy_term_data')
      ->fields(array('weight' => $term->weight))
      ->condition('tid', $term->tid, '=')
      ->execute();
  }

  // Update the vocabulary hierarchy to flat or single hierarchy.
  if ($vocabulary->hierarchy != $hierarchy) {
    $vocabulary->hierarchy = $hierarchy;
    taxonomy_vocabulary_save($vocabulary);
  }
  drupal_set_message(t('The configuration options have been saved.'));
}

/**
 * Submit handler to instantly create a new term.
 */
function c4m_features_og_manage_categories_overview_add_term_submit($form, &$form_state) {
  $parent_id = $form_state['triggering_element']['#attributes']['id'];
  $term_name = $form_state['input']['name-' . $parent_id];
  if (!$term_name) {
    drupal_set_message(t('Term name is a required field.'), 'error');
    return FALSE;
  }
  $form['#term'] = array(
    'name' => $term_name,
    'vid' => $form['#vocabulary']->vid,
    'vocabulary_machine_name' => $form['#vocabulary']->machine_name,
    'parent' => array($parent_id),
  );
  $form_state['term'] = (object) $form['#term'];
  $form_state['values'] = $form['#term'];

  entity_form_field_validate('taxonomy_term', $form, $form_state);

  // Save term.
  $term = c4m_features_og_manage_taxonomy_form_term_submit_build_taxonomy_term($form, $form_state);
  taxonomy_term_save($term);

  drupal_set_message(t('Created new term %term.', array('%term' => $term->name)));
  watchdog('taxonomy', 'Created new term %term.', array('%term' => $term->name), WATCHDOG_NOTICE, l(t('categories management'), 'manage/categories'));
}

/**
 * Form builder for the term delete form.
 *
 * @ingroup forms
 */
function c4m_features_og_manage_taxonomy_term_confirm_delete($form, &$form_state, $tid) {
  $term = taxonomy_term_load($tid);
  // Always provide entity id in the same form key as in the entity edit form.
  $form['tid'] = array('#type' => 'value', '#value' => $tid);

  $form['#term'] = $term;
  $form['type'] = array('#type' => 'value', '#value' => 'term');
  $form['name'] = array('#type' => 'value', '#value' => $term->name);
  $form['vocabulary_machine_name'] = array('#type' => 'value', '#value' => $term->vocabulary_machine_name);
  $form['delete'] = array('#type' => 'value', '#value' => TRUE);
  $menu_item = menu_get_item(current_path());
  $path = $menu_item['path'] == 'manage/categories/types' ? 'types' : '';
  return confirm_form($form,
    t('Are you sure you want to delete the term %title?',
      array('%title' => $term->name)),
    'manage/categories/' . $path,
    t('Deleting a term will delete all its children if there are any. This action cannot be undone.'),
    t('Delete'),
    t('Cancel'));
}

/**
 * Submit handler to delete a term after confirmation.
 *
 * @see taxonomy_term_confirm_delete_submit()
 */
function c4m_features_og_manage_taxonomy_term_confirm_delete_submit($form, &$form_state) {
  taxonomy_term_delete($form_state['values']['tid']);
  taxonomy_check_vocabulary_hierarchy($form['#vocabulary'], $form_state['values']);
  drupal_set_message(t('Deleted term %name.', array('%name' => $form_state['values']['name'])));
  watchdog('taxonomy', 'Deleted term %name.', array('%name' => $form_state['values']['name']), WATCHDOG_NOTICE);
  $menu_item = menu_get_item(current_path());
  $path = $menu_item['path'] == 'manage/categories/types' ? 'types' : '';
  $form_state['redirect'] = 'manage/categories/' . $path;
  cache_clear_all();
  return;
}

/**
 * Form builder to confirm resetting a terms under a specific category to alphabetical order.
 *
 * @ingroup forms
 * @see taxonomy_vocabulary_confirm_reset_alphabetical()
 */
function c4m_features_og_manage_categories_overview_confirm_reset_alphabetical($form, &$form_state, $vid, $tid) {
  $vocabulary = taxonomy_vocabulary_load($vid);
  $form['type'] = array('#type' => 'value', '#value' => 'vocabulary');
  $form['vid'] = array('#type' => 'value', '#value' => $vid);
  $form['machine_name'] = array('#type' => 'value', '#value' => $vocabulary->machine_name);
  $form['reset_alphabetical'] = array('#type' => 'value', '#value' => TRUE);
  $path = $tid ? $vocabulary->machine_name : 'types';

  if ($tid) {
    $term = taxonomy_term_load($tid);
    $form['parent_tid'] = array('#type' => 'value', '#value' => $tid);
    $form['name'] = array('#type' => 'value', '#value' => $term->name);

    return confirm_form($form,
      t('Are you sure you want to reset the children of the term %title to alphabetical order?',
        array('%title' => $term->name)),
      'manage/categories/' . $path,
      '<div class="question">'
      . t('Are you sure you want to reset the children of the term %title to alphabetical order?',
        array('%title' => $term->name))
      . '</div>'
      . t('Resetting the children of the term %title will discard all custom ordering and sort items alphabetically.',
        array('%title' => $term->name)),
      t('Reset to alphabetical'),
      t('Cancel'));
  }
  else {
    return confirm_form($form,
      t('Are you sure you want to reset the Categories to alphabetical order?'),
      'manage/categories/' . $path,
      '<div class="question">'
      . t('Are you sure you want to reset the Categories to alphabetical order?')
      . '</div>'
      . t('Resetting the the Categories will discard all custom ordering and sort items alphabetically.'),
      t('Reset to alphabetical'),
      t('Cancel'));
  }
}

/**
 * Submit handler to reset a specific category's children to alphabetical order after confirmation.
 *
 * @see c4m_features_og_manage_categories_overview_confirm_reset_alphabetical()
 */
function c4m_features_og_manage_categories_overview_confirm_reset_alphabetical_submit($form, &$form_state) {
  $params = array(
    ':weight' => 0,
    ':vid' => $form_state['values']['vid'],
  );
  $condition = '';
  if (isset($form_state['values']['parent_tid'])) {
    $params[':parent_tid'] = $form_state['values']['parent_tid'];
    $condition = ' AND h.parent = :parent_tid';
  }

  db_query(
    'UPDATE {taxonomy_term_data} AS d ' .
    'JOIN {taxonomy_term_hierarchy} AS h ' .
    'ON d.tid = h.tid ' .
    'SET d.weight = :weight ' .
    'WHERE d.vid = :vid' .
    $condition,
    $params
  );
  $menu_item = menu_get_item(current_path());
  $path = $menu_item['path'] == 'manage/categories/types' ? 'types' : '';

  if (isset($form_state['values']['name'])) {
    drupal_set_message(t('Reset category %name children to alphabetical order.', array('%name' => $form_state['values']['name'])));
    watchdog('taxonomy', 'Reset category %name children to alphabetical order.', array('%name' => $form_state['values']['name']), WATCHDOG_NOTICE);
  }
  else {
    drupal_set_message(t('Reset Categories to alphabetical order.'));
    watchdog('taxonomy', 'Reset Categories to alphabetical order.', WATCHDOG_NOTICE);
  }
  $form_state['redirect'] = 'manage/categories/' . $path;
}

/**
 * Form function for the category type edit form.
 *
 * To avoid duplicated code, using the term edit form to build this form,
 * as it's almost the same form, Just unset the parent fields and change the title and description.
 *
 * @ingroup forms
 * @see taxonomy_form_term()
 */
function c4m_features_og_manage_categories_type_form($form, &$form_state, $tid) {
  $form = c4m_features_og_manage_categories_term_form($form, $form_state, $tid);
  unset($form['title']);
  unset($form['description']);
  unset($form['parent']);

  $title['element'] = array(
    '#tag' => 'h2',
    '#attributes' => array(
      'class' => array('type-edit-title-text'),
    ),
    '#value' => t('Manage types of category'),
  );

  $description['element'] = array(
    '#tag' => 'h4',
    '#attributes' => array(
      'class' => array('type-edit-description-text'),
    ),
    '#value' => t('Change the types of category of this Group.'),
  );

  $form['title'] = array(
    '#markup' => theme_html_tag($title),
    '#weight' => -10,
  );

  $form['description'] = array(
    '#markup' => theme_html_tag($description),
    '#weight' => -5,
  );
  return $form;
}

/**
 * Validation handler for the custom type form.
 *
 * @see c4m_features_og_manage_categories_type_form()
 */
function c4m_features_og_manage_categories_type_form_validate($form, &$form_state) {
  entity_form_field_validate('taxonomy_term', $form, $form_state);
}

/**
 * Submit handler to update a type.
 *
 * @see c4m_features_og_manage_categories_type_form()
 */
function c4m_features_og_manage_categories_type_form_submit($form, &$form_state) {
  if ($form_state['triggering_element']['#value'] == t('Delete')) {
    // Execute the term deletion.
    if ($form_state['values']['delete'] === TRUE) {
      c4m_features_og_manage_taxonomy_term_confirm_delete_submit($form, $form_state);
      return;
    }
    // Rebuild the form to confirm term deletion.
    $form_state['rebuild'] = TRUE;
    $form_state['confirm_delete'] = TRUE;
    return;
  }
  if ($form_state['triggering_element']['#value'] == t('Cancel')) {
    return;
  }

  $term = c4m_features_og_manage_taxonomy_form_term_submit_build_taxonomy_term($form, $form_state);

  taxonomy_term_save($term);
  drupal_set_message(t('Updated category type %term.', array('%term' => $term->name)));
  watchdog('taxonomy', 'Updated category type %term.', array('%term' => $term->name), WATCHDOG_NOTICE, l(t('edit'), 'manage/categories/type/' . $term->tid . '/edit'));
  // Clear the page and block caches to avoid stale data.
  cache_clear_all();
}

/**
 * Form function for the term edit form.
 *
 * @ingroup forms
 * @see taxonomy_form_term()
 */
function c4m_features_og_manage_categories_term_form($form, &$form_state, $tid) {
  // Validate if the given term is valid.
  if(!$term = taxonomy_term_load($tid)) {
    drupal_set_message(t('term/type ID is not valid.'), 'error');
    $form_state['redirect'] = 'manage/categories';
    drupal_redirect_form($form_state);
  }

  $group = c4m_og_current_group();
  $vocabulary = c4m_og_vocab_load_group_vocabulary($group, 'c4m_vocab_category');

  // Validate if the given term belongs to the current group (The group vocab).
  if(!_og_vocab_term_exists_in_vocab($term->name, $vocabulary->vid)) {
    drupal_set_message(t('The term "%name" does not belong to the current group.', array('%name' => $term->name)), 'error');
    $form_state['redirect'] = 'manage/categories';
    drupal_redirect_form($form_state);
  }

  // Check for confirmation forms.
  if (isset($form_state['confirm_delete'])) {
    return array_merge($form, c4m_features_og_manage_taxonomy_term_confirm_delete($form, $form_state, $term->tid));
  }

  $parent = array_keys(taxonomy_get_parents($term->tid));
  $form['#term'] = (array) $term;
  $form['#term']['parent'] = $parent;
  $form['#vocabulary'] = $vocabulary;
  $form_state['term'] = $term;

  $tree = taxonomy_get_tree($vocabulary->vid, 0, 1);
  $options = array();
  if (empty($parent)) {
    $parent = array(0);
  }

  foreach ($tree as $item) {
    $options[$item->tid] = str_repeat('-', $item->depth) . $item->name;
  }

  $title['element'] = array(
    '#tag' => 'h2',
    '#attributes' => array(
      'class' => array('term-edit-title-text'),
    ),
    '#value' => t('Manage Group categories'),
  );

  $description['element'] = array(
    '#tag' => 'h4',
    '#attributes' => array(
      'class' => array('term-edit-description-text'),
    ),
    '#value' => t('Change the category term of this Group.'),
  );

  $form['title'] = array(
    '#markup' => theme_html_tag($title),
    '#weight' => -10,
  );

  $form['description'] = array(
    '#markup' => theme_html_tag($description),
    '#weight' => -5,
  );

  $form['parent'] = array(
    '#type' => 'radios',
    '#title' => t('Type of category'),
    '#options' => $options,
    '#default_value' => reset($parent),
    '#required' => TRUE,
    '#weight' => 0,
  );

  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Term name'),
    '#default_value' => $term->name,
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => 5,
  );

  $form['vocabulary_machine_name'] = array(
    '#type' => 'value',
    '#value' => isset($term->vocabulary_machine_name) ? $term->vocabulary_machine_name : $vocabulary->name,
  );

  $form['vid'] = array(
    '#type' => 'value',
    '#value' => $vocabulary->vid,
  );
  $form['tid'] = array(
    '#type' => 'value',
    '#value' => $term->tid,
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 10,
  );

  $form['actions']['cancel'] = array(
    '#type' => 'submit',
    '#value' => t('Cancel'),
    '#weight' => 15,
  );

  $form['actions']['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete'),
    '#weight' => 20,
  );

  return $form;
}

/**
 * Validation handler for the custom term form.
 *
 * @see c4m_features_og_manage_categories_term_form()
 */
function c4m_features_og_manage_categories_term_form_validate($form, &$form_state) {
  entity_form_field_validate('taxonomy_term', $form, $form_state);
}

/**
 * Submit handler to update a term.
 *
 * @see c4m_features_og_manage_categories_term_form()
 */
function c4m_features_og_manage_categories_term_form_submit($form, &$form_state) {
  if ($form_state['triggering_element']['#value'] == t('Delete')) {
    // Execute the term deletion.
    if ($form_state['values']['delete'] === TRUE) {
      $group = c4m_og_current_group();
      $form['#vocabulary'] = c4m_og_vocab_load_group_vocabulary($group, 'c4m_vocab_category');
      c4m_features_og_manage_taxonomy_term_confirm_delete_submit($form, $form_state);
      return;
    }
    // Rebuild the form to confirm term deletion.
    $form_state['rebuild'] = TRUE;
    $form_state['confirm_delete'] = TRUE;
    return;
  }
  if ($form_state['triggering_element']['#value'] == t('Cancel')) {
    return;
  }

  $term = c4m_features_og_manage_taxonomy_form_term_submit_build_taxonomy_term($form, $form_state);

  taxonomy_term_save($term);
  drupal_set_message(t('Updated term %term.', array('%term' => $term->name)));
  watchdog('taxonomy', 'Updated term %term.', array('%term' => $term->name), WATCHDOG_NOTICE, l(t('edit'), 'manage/categories/term/' . $term->tid . '/edit'));
  // Clear the page and block caches to avoid stale data.
  cache_clear_all();
}

/**
 * Updates the form state's term entity by processing this submission's values.
 */
function c4m_features_og_manage_taxonomy_form_term_submit_build_taxonomy_term($form, &$form_state) {
  $term = $form_state['term'];
  entity_form_submit_build_entity('taxonomy_term', $term, $form, $form_state);

  return $term;
}

/**
 * Returns HTML for a category types overview form as a sortable list of terms.
 */
function theme_c4m_features_og_manage_categories_types_overview_form($variables) {
  return theme_c4m_features_og_manage_categories_overview_form($variables);
}

/**
 * Returns HTML for a terms overview form as a sortable list of terms.
 *
 * @param $variables
 *   An associative array containing:
 *   - form: A render element representing the form.
 *
 * @see taxonomy_overview_terms()
 * @ingroup themeable
 */
function theme_c4m_features_og_manage_categories_overview_form($variables) {
  $form = $variables['form'];

  $vocabulary = $form['#vocabulary'];

  $errors = form_get_errors() != FALSE ? form_get_errors() : array();
  $rows = array();
  $menu_item = menu_get_item(current_path());

  $parents = $menu_item['path'] != 'manage/categories/types' ? array() : array(array('tid' => array('#value' => 0)));
  $overview_path = $menu_item['path'] == 'manage/categories/types' ? '/categories' : '';
  foreach (element_children($form) as $key) {
    if (isset($form[$key]['#term'])) {
      $term = &$form[$key];

      $row = array();
      if (isset($term['#term']['depth']) && $term['#term']['depth'] == 0) {
        if ($menu_item['path'] != 'manage/categories/types') {
          $parents[$key] = $term;
          continue;
        }
      }
      $row[] = drupal_render($term['view']);
      if ($form['#parent_fields']) {
        $term['tid']['#attributes']['class'] = array('term-id');
        $term['parent']['#attributes']['class'] = array('term-parent');
        $term['depth']['#attributes']['class'] = array('term-depth');
        $row[0] .= drupal_render($term['parent']) . drupal_render($term['tid']) . drupal_render($term['depth']);
      }
      $row[] = drupal_render($term['edit']) . ' | ' . drupal_render($term['delete']);
      $row = array('data' => $row);
      $rows[$term['#term']['parent']][$key] = $row;
    }
  }

  // Link to go back to manage page.
  $title['element'] = array(
    '#tag' => 'h2',
    '#attributes' => array(
      'class' => array('category-edit-title-text'),
    ),
    '#value' => t('Edit Group @title', array('@title' => $vocabulary->name)),
  );
  $output = '<div class="category-edit-title">' . theme_html_tag($title) . l(t('Return to overview'), url('manage' . $overview_path, array('absolute' => TRUE))) . '</div>';
  // Static page description.
  $output .= '<div class="category-edit-description">';
  $output .= t('
      Here you can define the category terms that will be used to classify documents and other contents submitted to the group.
      You can add, edit and delete the category terms. The category Group will not show up if there are no terms added to it.
      Manual order terms by dragging them. You can move terms from one category Group to another:
    ');
  $output .= '<strong>' . t('Do not forget to save after reordering and/or moving terms.') . '</strong>';
  $output .= '</div>';

  $menu_item = menu_get_item(current_path());
  $path = $menu_item['path'] == 'manage/categories/types' ? 'types' : '';

  foreach ($parents as $parent_key => $parent) {
    $parent_id = $parent['tid']['#value'];
    // Set header for the table.
    $reset_link_options = array(
      'absolute' => TRUE,
      'query' => array(
        'reset_alphabetical' => $parent_id
      ),
    );
    $header = array(
      array(
        'data' => t('Name') . l(t('Order items alphabetically'), url('manage/categories/' . $path, $reset_link_options)),
        'class' => array('category-name-column')
      ),
      t('Operations')
    );
    // Add necessary classes to rows.
    $row_position = 0;
    if(!empty($rows[$parent_id])) {
      foreach ($rows[$parent_id] as $key => $row) {
        $rows[$parent_id][$key]['class'] = array();
        if (isset($form['#parent_fields'])) {
          $rows[$parent_id][$key]['class'][] = 'draggable';
        }

        // Add an error class if this row contains a form error.
        foreach ($errors as $error_key => $error) {
          if (strpos($error_key, $key) === 0) {
            $rows[$parent_id][$key]['class'][] = 'error';
          }
        }
        $row_position++;
      }
    }

    if (empty($rows[$parent_id])) {
      $rows[$parent_id][] = array(array('data' => $form['#empty_text'], 'colspan' => '3'));
    }
    if ($menu_item['path'] != 'manage/categories/types') {
      $parent_element['element'] = array(
        '#tag' => 'h3',
        '#attributes' => array(
          'class' => array('category-title'),
        ),
        '#value' => $parent['#term']['name'],
      );

      $options = array(
        'absolute' => TRUE,
        'query' => drupal_get_destination(),
      );
      $category_title = theme_html_tag($parent_element) . l(t('Edit'), url('manage/categories/type/' . $parent_id . '/edit', $options));
      unset($options['query']);
      $category_title .= '|' . l(t('Change order'), url('manage/categories/types', $options));
      $options['query']['delete'] = $parent_id;
      $category_title .= '|' . l(t('Delete'), url('manage/categories', $options));

      $category_title_element['element'] = array(
        '#tag' => 'div',
        '#attributes' => array(
          'class' => array('category-title-wrapper'),
        ),
        '#value' => $category_title,
      );
      $output .= theme_html_tag($category_title_element);
    }
    $output .= theme('table', array('header' => $header, 'rows' => $rows[$parent_id], 'attributes' => array('id' => 'taxonomy-' . $parent_id)));

    $output .= $form['#page_type'] == 'terms' ? drupal_render_children($form[$parent_key]['add_term_form']) : '';

    // Add drag and drop if parent fields are present in the form.
    if ($form['#parent_fields']) {
      drupal_add_tabledrag('taxonomy-' . $parent_id, 'match', 'parent', 'term-parent', 'term-parent', 'term-id', FALSE);
      drupal_add_tabledrag('taxonomy-' . $parent_id, 'depth', 'group', 'term-depth', NULL, NULL, FALSE);
      drupal_add_tabledrag('taxonomy-' . $parent_id, 'order', 'sibling', 'term-weight');
    }
  }

  if ($form['#parent_fields']) {
    drupal_add_js(drupal_get_path('module', 'c4m_features_og_manage') . '/js/taxonomy.js');
    drupal_add_css(drupal_get_path('module', 'taxonomy') . '/taxonomy.css');
  }
  $output .= theme('pager');
  $output .= '<div class="actions">';
  $output .= drupal_render_children($form);
  $output .= '</div>';

  return $output;
}
