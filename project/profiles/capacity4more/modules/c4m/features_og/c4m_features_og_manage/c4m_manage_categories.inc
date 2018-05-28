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
  $form_info = c4m_feature_og_manage_get_category_management_form_info($form);

  $tree = taxonomy_get_tree($form_info['#vocabulary']->vid);

  $form = c4m_features_og_manage_build_category_management_form($form_info, $tree, 'terms');

  return $form;
}

/**
 * Form builder for the category types management overview.
 *
 * Display a list of all the 1st level terms in a vocabulary, with options to
 * edit each one.
 * The form is made drag and drop by the theme function.
 *
 * @ingroup forms
 */
function c4m_features_og_manage_categories_types_overview_form($form, &$form_state) {
  $form_info = c4m_feature_og_manage_get_category_management_form_info($form);

  $tree = taxonomy_get_tree($form_info['#vocabulary']->vid, 0, 1);

  $form = c4m_features_og_manage_build_category_management_form($form_info, $tree, 'types');

  return $form;
}

/**
 * Submit handler for the category types management page.
 *
 * Handles:
 * - Reordering.
 * - Delete.
 * - Reset alphabetical.
 * - Instant create new category type.
 */
function c4m_features_og_manage_categories_types_overview_form_submit($form, &$form_state) {

  if ($form_state['triggering_element']['#value'] == t('Add Term')) {
    // Execute adding a term.
    c4m_features_og_manage_categories_overview_add_term_submit($form, $form_state);
    return;
  }

  $vocabulary = $form['#vocabulary'];
  $tree = taxonomy_get_tree($vocabulary->vid, 0, 1);
  // Update the terms weight.
  c4m_features_og_manage_categories_overview_update_vocabulary($form, $form_state, $tree);
}

/**
 * Submit handler for the category terms management page.
 *
 * Handles:
 * - Reordering.
 * - Delete.
 * - Reset alphabetical.
 * - Instant create new term.
 */
function c4m_features_og_manage_categories_overview_form_submit($form, &$form_state) {

  if ($form_state['triggering_element']['#value'] == t('Add Term')) {
    // Execute adding a term.
    c4m_features_og_manage_categories_overview_add_term_submit($form, $form_state);
    return;
  }

  $vocabulary = $form['#vocabulary'];
  $tree = taxonomy_get_tree($vocabulary->vid);
  // Update the terms weight.
  c4m_features_og_manage_categories_overview_update_vocabulary($form, $form_state, $tree);
}

/**
 * Submit handler to instantly create a new term.
 */
function c4m_features_og_manage_categories_overview_add_term_submit($form, &$form_state) {
  $parent_id = isset($form_state['triggering_element']['#attributes']['id']) ? $form_state['triggering_element']['#attributes']['id'] : 0;
  $term_name = $parent_id ? $form_state['input']['name-' . $parent_id] : $form_state['input']['name'];
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
function c4m_features_og_manage_categories_term_delete_confirm_form($form, &$form_state, $tid) {
  $form = c4m_features_og_manage_categories_delete_helper($form, $tid);
  $form_state['redirect'] = $form['#destination'];
  // Validate if the given id belongs to a Taxonomy-term.
  if (!$form) {
    drupal_redirect_form($form_state);
  }
  return confirm_form($form,
    t('Are you sure you want to delete the term %name?',
      array('%name' => $form['#term']->name)),
    $form['#destination'],
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel'));
}

/**
 * Submit handler to delete a term after confirmation.
 *
 * @see taxonomy_term_confirm_delete_submit()
 */
function c4m_features_og_manage_categories_term_delete_confirm_form_submit($form, &$form_state) {
  taxonomy_term_delete($form_state['values']['tid']);
  taxonomy_check_vocabulary_hierarchy($form['#vocabulary'], $form_state['values']);
  drupal_set_message(t('Deleted term %name.', array('%name' => $form_state['values']['name'])));
  watchdog('taxonomy', 'Deleted term %name.', array('%name' => $form_state['values']['name']), WATCHDOG_NOTICE);
  $form_state['redirect'] = $form['#destination'];
  cache_clear_all();
}

/**
 * Form builder for the category type delete form.
 *
 * @ingroup forms
 */
function c4m_features_og_manage_categories_type_delete_confirm_form($form, &$form_state, $tid) {
  $form = c4m_features_og_manage_categories_delete_helper($form, $tid);
  $form_state['redirect'] = $form['#destination'];
  // Validate if the given id belongs to a Taxonomy-term.
  if (!$form) {
    drupal_redirect_form($form_state);
  }
  return confirm_form($form,
    t('Are you sure you want to delete the category type %title?',
      array('%title' => $form['#term']->name)),
    $form['#destination'],
    t('Deleting a category type will delete all its children if there are any. This action cannot be undone.'),
    t('Delete'),
    t('Cancel'));
}

/**
 * Submit handler to delete a category type after confirmation.
 *
 * @see taxonomy_term_confirm_delete_submit()
 */
function c4m_features_og_manage_categories_type_delete_confirm_form_submit($form, &$form_state) {
  taxonomy_term_delete($form_state['values']['tid']);
  taxonomy_check_vocabulary_hierarchy($form['#vocabulary'], $form_state['values']);
  drupal_set_message(t('Deleted category type %name.', array('%name' => $form_state['values']['name'])));
  watchdog('taxonomy', 'Deleted category type %name.', array('%name' => $form_state['values']['name']), WATCHDOG_NOTICE);
  $form_state['redirect'] = $form['#destination'];
  cache_clear_all();
}

/**
 * Form builder to confirm resetting a terms (2nd level).
 *
 * Under a specific category type to alphabetical order.
 *
 * @ingroup forms
 */
function c4m_features_og_manage_categories_term_order_confirm_form($form, &$form_state, $tid) {
  $term = taxonomy_term_load($tid);
  $vocabulary = taxonomy_vocabulary_load($term->vid);
  $form['type'] = array('#type' => 'value', '#value' => 'vocabulary');
  $form['vid'] = array('#type' => 'value', '#value' => $vocabulary->vid);
  $form['machine_name'] = array('#type' => 'value', '#value' => $vocabulary->machine_name);
  $form['reset_alphabetical'] = array('#type' => 'value', '#value' => TRUE);

  $form['parent_tid'] = array('#type' => 'value', '#value' => $tid);
  $form['name'] = array('#type' => 'value', '#value' => $vocabulary->name);

  return confirm_form($form,
    t('Are you sure you want to reset the children of the term %title to alphabetical order?',
      array('%title' => $term->name)),
    'manage/categories/',
    t('Resetting the children of the term %title will discard all custom ordering and sort items alphabetically.',
      array('%title' => $term->name)),
    t('Reset to alphabetical'),
    t('Cancel'));
}

/**
 * Submit handler to reset a specific category's children to alphabetical order.
 *
 * Change after confirmation.
 *
 * @see c4m_features_og_manage_categories_term_order_confirm_form()
 */
function c4m_features_og_manage_categories_term_order_confirm_form_submit($form, &$form_state) {
  $params = array(
    ':weight' => 0,
    ':vid' => $form_state['values']['vid'],
    ':parent_tid' => $form_state['values']['parent_tid'],
  );

  $query = <<<EOT
    UPDATE {taxonomy_term_data} AS d
    JOIN {taxonomy_term_hierarchy} AS h
    ON d.tid = h.tid
    SET d.weight = :weight
    WHERE d.vid = :vid
    AND h.parent = :parent_tid
EOT;

  db_query($query, $params);

  drupal_set_message(t('Reset category %name children to alphabetical order.', array('%name' => $form_state['values']['name'])));
  watchdog('taxonomy', 'Reset category %name children to alphabetical order.', array('%name' => $form_state['values']['name']), WATCHDOG_NOTICE);
  $form_state['redirect'] = 'manage/categories';
}

/**
 * Form builder to confirm resetting category types to alphabetical order.
 *
 * This is only for the first (1) level.
 *
 * @ingroup forms
 */
function c4m_features_og_manage_categories_type_order_confirm_form($form, &$form_state, $vid) {
  $vocabulary = taxonomy_vocabulary_load($vid);
  $form['type'] = array('#type' => 'value', '#value' => 'vocabulary');
  $form['vid'] = array('#type' => 'value', '#value' => $vid);
  $form['machine_name'] = array('#type' => 'value', '#value' => $vocabulary->machine_name);
  $form['reset_alphabetical'] = array('#type' => 'value', '#value' => TRUE);

  return confirm_form($form,
    t('Are you sure you want to reset the Categories to alphabetical order?'),
    'manage/categories/types',
    t('Resetting the the Categories will discard all custom ordering and sort items alphabetically.'),
    t('Reset to alphabetical'),
    t('Cancel'));
}

/**
 * Submit handler to reset the vocabulary's category types.
 *
 * Changes the sort to alphabetical order after confirmation.
 *
 * @see c4m_features_og_manage_categories_type_order_confirm_form()
 */
function c4m_features_og_manage_categories_type_order_confirm_form_submit($form, &$form_state) {
  $params = array(
    ':weight' => 0,
    ':vid' => $form_state['values']['vid'],
  );

  $query = <<<EOT
    UPDATE {taxonomy_term_data} AS d
    JOIN {taxonomy_term_hierarchy} AS h
    ON d.tid = h.tid
    SET d.weight = :weight
    WHERE d.vid = :vid
EOT;

  db_query($query, $params);

  drupal_set_message(t('Reset Categories to alphabetical order.'));
  watchdog('taxonomy', 'Reset Categories to alphabetical order.', WATCHDOG_NOTICE);
  $form_state['redirect'] = 'manage/categories/types';
}

/**
 * Form builder function for the category type add form.
 *
 * To avoid duplicated code, using the term edit form to build this form,
 * then adding some changes to suit the add form.
 *
 * @ingroup forms
 */
function c4m_features_og_manage_categories_type_add_form($form, &$form_state, $edit = array()) {
  // Return destination.
  $params = drupal_get_query_parameters();
  $form['#destination'] = isset($params['destination']) ? $params['destination'] : '';

  // Add vocabulary and group info to form.
  $form = c4m_feature_og_manage_get_category_management_form_info($form);
  $vocabulary = $form['#vocabulary'];

  $term = is_object($edit) ? $edit : (object) $edit;
  $defaults = array(
    'name' => '',
    'description' => '',
    'format' => NULL,
    'vocabulary_machine_name' => isset($vocabulary) ? $vocabulary->machine_name : NULL,
    'tid' => NULL,
    'weight' => 0,
  );
  foreach ($defaults as $key => $value) {
    if (!isset($term->$key)) {
      $term->$key = $value;
    }
  }
  $form_state['term'] = $term;

  $form = c4m_features_og_manage_categories_edit_form_build($form, $form_state, $term, $vocabulary);
  // No need for parents field, This is a parent.
  unset($form['parent']);
  // No need for a delete button, this is a new type.
  unset($form['actions']['delete']);
  // Change name field label.
  $form['name']['#title'] = t('Type name');

  $page_title['element'] = array(
    '#tag' => 'h2',
    '#attributes' => array(
      'class' => array('type-edit-title-text'),
    ),
    '#value' => t('Add a new type of category'),
  );

  $page_description['element'] = array(
    '#tag' => 'h4',
    '#attributes' => array(
      'class' => array('type-edit-description-text'),
    ),
    '#value' => t('Change the types of category of this Group.'),
  );

  $form['page_title'] = array(
    '#markup' => theme_html_tag($page_title),
    '#weight' => -10,
  );

  $form['page_description'] = array(
    '#markup' => theme_html_tag($page_description),
    '#weight' => -5,
  );

  return $form;
}

/**
 * Validation handler for the custom type adding form.
 *
 * @see c4m_features_og_manage_categories_type_add_form()
 */
function c4m_features_og_manage_categories_type_add_form_validate($form, &$form_state) {
  entity_form_field_validate('taxonomy_term', $form, $form_state);
}

/**
 * Submit handler to create a new type.
 *
 * @see c4m_features_og_manage_categories_type_add_form()
 */
function c4m_features_og_manage_categories_type_add_form_submit($form, &$form_state) {
  if ($form_state['triggering_element']['#value'] == t('Cancel')) {
    return;
  }

  $term = c4m_features_og_manage_taxonomy_form_term_submit_build_taxonomy_term($form, $form_state);

  taxonomy_term_save($term);
  drupal_set_message(t('Created new category type %term.', array('%term' => $term->name)));
  watchdog('taxonomy', 'Created new category type %term.', array('%term' => $term->name), WATCHDOG_NOTICE, l(t('edit'), 'taxonomy/term/' . $term->tid . '/edit'));
  // Clear the page and block caches to avoid stale data.
  cache_clear_all();
}

/**
 * Form builder function for the category type edit form.
 *
 * To avoid duplicated code, using the term edit form to build this form,
 * as it's almost the same form, Just unset the parent fields and change the
 * title and description.
 *
 * @ingroup forms
 *
 * @see taxonomy_form_term()
 */
function c4m_features_og_manage_categories_type_form($form, &$form_state, $tid) {
  // Return destination.
  $params = drupal_get_query_parameters();
  $form['#destination'] = $params['destination'];
  $term = taxonomy_term_load($tid);
  $group = c4m_og_current_group();
  $vocabulary = c4m_og_vocab_load_group_vocabulary($group, 'c4m_vocab_category');

  // Check for confirmation forms.
  if (isset($form_state['confirm_delete'])) {
    return array_merge($form, c4m_features_og_manage_categories_type_delete_confirm_form($form, $form_state, $tid));
  }

  $form = c4m_features_og_manage_categories_edit_form_build($form, $form_state, $term, $vocabulary);
  // There's no parent in the "category type" (1st level terms).
  unset($form['parent']);

  $page_title['element'] = array(
    '#tag' => 'h2',
    '#attributes' => array(
      'class' => array('type-edit-title-text'),
    ),
    '#value' => t('Manage types of category'),
  );

  $page_description['element'] = array(
    '#tag' => 'h4',
    '#attributes' => array(
      'class' => array('type-edit-description-text'),
    ),
    '#value' => t('Change the types of category of this Group.'),
  );

  $form['page_title'] = array(
    '#markup' => theme_html_tag($page_title),
    '#weight' => -10,
  );

  $form['page_description'] = array(
    '#markup' => theme_html_tag($page_description),
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
    // Execute the category type deletion.
    if ($form_state['values']['delete'] === TRUE) {
      c4m_features_og_manage_categories_type_delete_confirm_form_submit($form, $form_state);
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
  watchdog('taxonomy', 'Updated category type %term.', array('%term' => $term->name), WATCHDOG_NOTICE, l(t('edit'), 'taxonomy/term/' . $term->tid . '/edit'));
  // Clear the page and block caches to avoid stale data.
  cache_clear_all();
}

/**
 * Form function for the term edit form.
 *
 * @ingroup forms
 *
 * @see taxonomy_form_term()
 */
function c4m_features_og_manage_categories_term_form($form, &$form_state, $tid) {
  $params = drupal_get_query_parameters();
  $form['#destination'] = $params['destination'];
  $term = taxonomy_term_load($tid);
  $group = c4m_og_current_group();
  $vocabulary = c4m_og_vocab_load_group_vocabulary($group, 'c4m_vocab_category');

  // Check for confirmation forms.
  if (isset($form_state['confirm_delete'])) {
    return array_merge($form, c4m_features_og_manage_categories_term_delete_confirm_form($form, $form_state, $tid));
  }

  $form = c4m_features_og_manage_categories_edit_form_build($form, $form_state, $term, $vocabulary);

  $page_title['element'] = array(
    '#tag' => 'h2',
    '#attributes' => array(
      'class' => array('term-edit-title-text'),
    ),
    '#value' => t('Manage Group categories'),
  );

  $page_description['element'] = array(
    '#tag' => 'h4',
    '#attributes' => array(
      'class' => array('term-edit-description-text'),
    ),
    '#value' => t('Change the category term of this Group.'),
  );

  $form['page_title'] = array(
    '#markup' => theme_html_tag($page_title),
    '#weight' => -10,
  );

  $form['page_description'] = array(
    '#markup' => theme_html_tag($page_description),
    '#weight' => -5,
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
      c4m_features_og_manage_categories_term_delete_confirm_form_submit($form, $form_state);
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
  watchdog('taxonomy', 'Updated term %term.', array('%term' => $term->name), WATCHDOG_NOTICE, l(t('edit'), 'taxonomy/term/' . $term->tid . '/edit'));
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
 *
 * @see theme_c4m_features_og_manage_categories_overview_form()
 *
 * @ingroup themeable
 */
function theme_c4m_features_og_manage_categories_types_overview_form($variables) {
  return theme_c4m_features_og_manage_categories_overview_form($variables);
}

/**
 * Returns HTML for a terms overview form as a sortable list of terms.
 *
 * @param array $variables
 *   An associative array containing:
 *   - form: A render element representing the form.
 *
 * @return string
 *   HTML of the terms/types overview form with add terms inputs.
 *
 * @ingroup themeable
 */
function theme_c4m_features_og_manage_categories_overview_form(array $variables) {
  $form = $variables['form'];
  $type = $form['#group']->type;

  $vocabulary = $form['#vocabulary'];

  $errors = form_get_errors() != FALSE ? form_get_errors() : array();
  $rows = array();

  $parents = $form['#page_type'] != 'types' ? array() : array(array('tid' => array('#value' => 0)));
  $overview_path = $form['#page_type'] == 'types' ? '/categories' : '';
  foreach (element_children($form) as $key) {
    if (isset($form[$key]['#term'])) {
      $term = &$form[$key];

      $row = array();
      if (isset($term['#term']['depth']) && $term['#term']['depth'] == 0) {
        if ($form['#page_type'] != 'types') {
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
    '#value' => t('Edit @type @title', array('@type' => ucfirst($type), '@title' => $vocabulary->name)),
  );
  $output = '<div class="category-edit-title">' . theme_html_tag($title) . l(t('Return to overview'), 'manage' . $overview_path, ['absolute' => TRUE]) . '</div>';
  // Static page description.
  $output .= '<div class="category-edit-description">';
  $output .= t('
      Here you can define the category terms that will be used to classify documents and other contents submitted to the @type.
      You can add, edit and delete the category terms. The category @type_uc will not show up if there are no terms added to it.
      Manual order terms by dragging them. You can move terms from one category @type_uc to another:
    ', array('@type' => $type, '@type_uc' => ucfirst($type)));
  $output .= '<strong>' . t('Do not forget to save after reordering and/or moving terms.') . '</strong>';
  $output .= '</div>';

  foreach ($parents as $parent_key => $parent) {
    $parent_id = isset($parent['#term']['tid']) ? $parent['#term']['tid'] : 0;
    $reset_path = $form['#page_type'] == 'types' ? 'type/' . $vocabulary->vid : 'term/' . $parent_id;
    // Set header for the table.
    $header = array(
      array(
        'data' => t('Name') . l(t('Order items alphabetically'), 'manage/categories/' . $reset_path . '/term-order', ['absolute' => TRUE]),
        'class' => array('category-name-column'),
      ),
      t('Operations'),
    );
    // Add necessary classes to rows.
    $row_position = 0;
    if (!empty($rows[$parent_id])) {
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
    if ($form['#page_type'] != 'types') {
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
      $category_title = theme_html_tag($parent_element) . l(t('Edit'), 'manage/categories/type/' . $parent_id . '/edit', $options);
      $category_title .= '|' . l(t('Change order'), 'manage/categories/types', ['absolute' => TRUE]);
      $category_title .= '|' . l(t('Delete'), 'manage/categories/type/' . $parent_id . '/delete', $options);

      $category_title_element['element'] = array(
        '#tag' => 'div',
        '#attributes' => array(
          'class' => array('category-title-wrapper'),
        ),
        '#value' => $category_title,
      );
      $output .= theme_html_tag($category_title_element);
    }
    $output .= theme(
      'table',
      array(
        'header' => $header,
        'rows' => $rows[$parent_id],
        'attributes' => array('id' => 'taxonomy-' . $parent_id),
      )
    );

    $output .= $form['#page_type'] == 'terms' ? drupal_render_children($form[$parent_key]['add_term_form']) : drupal_render_children($form['add_term_form']);

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

/**
 * Helper callback.
 *
 * Saves the order of the terms (Terms and category types) in the vocabulary.
 */
function c4m_features_og_manage_categories_overview_update_vocabulary($form, &$form_state, $tree) {
  $changed_terms = array();

  if (empty($tree)) {
    return;
  }

  // Renumber the current page weights and assign any new parents.
  $weight = 0;
  foreach ($form_state['input'] as $tid => $values) {
    if (isset($form[$tid]['#term'])) {
      $term = $form[$tid]['#term'];
      if ($term['weight'] != $weight) {
        $term['weight'] = $weight;
        $changed_terms[$term['tid']] = $term;
      }
      $weight++;
    }
  }

  // Save all updated terms.
  foreach ($changed_terms as $changed) {
    $term = (object) $changed;
    // Update term_weight directly since we don't have a
    // fully populated term object to save.
    db_update('taxonomy_term_data')
      ->fields(array('weight' => $term->weight))
      ->condition('tid', $term->tid, '=')
      ->execute();
  }

  drupal_set_message(t('The configuration options have been saved.'));
}

/**
 * Helper callback; inserts the vocabulary info & group into the form.
 *
 * @return array
 *   The form group/ vocab info.
 */
function c4m_feature_og_manage_get_category_management_form_info($form) {
  $group = c4m_og_current_group();
  $vocabulary = c4m_og_vocab_load_group_vocabulary($group, 'c4m_vocab_category');

  $form['#vocabulary'] = $vocabulary;
  $form['#group'] = $group;
  $form['#tree'] = TRUE;
  $form['#parent_fields'] = FALSE;

  return $form;
}

/**
 * Helper callback; Builds the actual form for category types/ terms overview.
 *
 * @return array
 *   The overview form.
 */
function c4m_features_og_manage_build_category_management_form($form, $tree, $items_type) {
  $form['#page_type'] = $items_type;
  $delta = 0;
  $term_deltas = array();
  $current_page = array();
  $term = current($tree);
  do {
    // In case this tree is completely empty.
    if (empty($term)) {
      break;
    }
    $delta++;

    // Finally, if we've gotten down this far,
    // we're rendering a term on this page.
    $term_deltas[$term->tid] = isset($term_deltas[$term->tid]) ? $term_deltas[$term->tid] + 1 : 0;
    $key = 'tid:' . $term->tid . ':' . $term_deltas[$term->tid];

    $form['#first_tid'] = $term->tid;
    $current_page[$key] = $term;
  } while ($term = next($tree));

  // If this form was already submitted once, it's probably hit a validation
  // error. Ensure the form is rebuilt in the same order as the user submitted.
  if (!empty($form_state['input'])) {
    // Get the $_POST order.
    $order = array_flip(array_keys($form_state['input']));

    // Update our form with the new order.
    $current_page = array_merge($order, $current_page);
    foreach ($current_page as $key => $term) {
      // Verify this is a term for the current page and set at the current
      // depth.
      if (is_array($form_state['input'][$key]) && is_numeric($form_state['input'][$key]['tid'])) {
        $current_page[$key]->depth = $form_state['input'][$key]['depth'];
      }
      else {
        unset($current_page[$key]);
      }
    }
  }

  // Build the actual form.
  foreach ($current_page as $key => $term) {
    // Save the term for the current page so we don't have to load it a
    // second time.
    $form[$key]['#term'] = (array) $term;
    if (isset($term->parents)) {
      $form[$key]['#term']['parent'] = $term->parent = $term->parents[0];
      unset($form[$key]['#term']['parents'], $term->parents);
    }

    $form[$key]['view'] = array(
      '#type' => 'link',
      '#title' => $term->name,
      '#href' => 'taxonomy/term/' . $term->tid,
    );
    if ($form['#vocabulary']->hierarchy < 2 && count($tree) > 1) {
      $form['#parent_fields'] = TRUE;
      $form[$key]['tid'] = array(
        '#type' => 'hidden',
        '#value' => $term->tid,
      );
      $form[$key]['parent'] = array(
        '#type' => 'hidden',
        // Yes, default_value on a hidden.
        // It needs to be changeable by the javascript.
        '#default_value' => $term->parent,
      );
      $form[$key]['depth'] = array(
        '#type' => 'hidden',
        // Same as above, the depth is modified by javascript,
        // so it's a default_value.
        '#default_value' => $term->depth,
      );
    }
    $edit_path = $items_type == 'types' ? 'type' : 'term';
    $form[$key]['edit'] = array(
      '#type' => 'link',
      '#title' => t('Edit'),
      '#href' => 'manage/categories/' . $edit_path . '/' . $term->tid . '/edit',
      '#options' => array(
        'query' => drupal_get_destination(),
      ),
    );
    $form[$key]['delete'] = array(
      '#type' => 'link',
      '#title' => t('Delete'),
      '#href' => 'manage/categories/' . $edit_path . '/' . $term->tid . '/delete',
      '#options' => array(
        'query' => drupal_get_destination(),
      ),
    );
    // Adding "Add a term" form under each category type (For terms page).
    if ($term->parent == 0 && $items_type == 'terms') {
      $form[$key]['add_term_form']['name'] = array(
        '#title' => t('Term name'),
        '#title_display' => 'invisible',
        '#type' => 'textfield',
        '#name' => 'name-' . $term->tid,
        '#attributes' => array(
          'class' => array('label-input'),
        ),
      );

      $form[$key]['add_term_form']['actions']['add_term'] = array(
        '#type' => 'submit',
        '#value' => t('Add Term'),
        '#name' => 'add-term-' . $term->tid,
        '#attributes' => array(
          'id' => $term->tid,
        ),
      );
    }
  }

  // Adding "Add a type" form (For category types page).
  if ($items_type == 'types') {
    $form['add_term_form']['name'] = array(
      '#title' => t('Term name'),
      '#title_display' => 'invisible',
      '#type' => 'textfield',
      '#name' => 'name',
      '#attributes' => array(
        'class' => array('label-input'),
      ),
    );

    $form['add_term_form']['actions']['add_term'] = array(
      '#type' => 'submit',
      '#value' => t('Add Term'),
      '#name' => 'add-term',
    );
  }

  $form['#empty_text'] = t('No terms available.');

  if ($form['#vocabulary']->hierarchy < 2 && count($tree) > 1) {
    $form['actions'] = array('#type' => 'actions', '#tree' => FALSE);
    $form['actions']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save'),
    );

    $redirect_query = array();
    $get_query = drupal_get_query_parameters();
    if (isset($get_query['page'])) {
      $redirect_query = array(
        'query' => array('page' => $get_query['page']),
      );
    }

    $form_state['redirect'] = array(
      current_path(),
      $redirect_query,
    );
  }

  // Adding "Add new type of category" button.
  // If there's no terms in current group,
  // The button won't be displayed if it's in the actions array.
  if ($items_type == 'terms') {
    $new_category = array(
      '#type' => 'link',
      '#title' => t('Add new type of category'),
      '#href' => 'manage/categories/type/add',
      '#options' => array(
        'query' => drupal_get_destination(),
      ),
      '#attributes' => array(
        'class' => array(
          'btn btn-default',
        ),
      ),
    );
    if (empty($current_page)) {
      $form['new_category'] = $new_category;
    }
    else {
      $form['actions']['new_category'] = $new_category;
    }
  }

  return $form;
}

/**
 * Helper callback; Gets necessary info for the delete form.
 *
 * Used by term delete and types delete callbacks.
 *
 * @return array
 *   The delete form info.
 */
function c4m_features_og_manage_categories_delete_helper($form, $tid) {
  $form = c4m_feature_og_manage_get_category_management_form_info($form);
  // Set the form redirect destination.
  // Default destination is "Categories management overview.
  $form['#destination'] = 'manage/categories';
  $params = drupal_get_query_parameters();
  if (isset($params['destination'])) {
    $form['#destination'] = $params['destination'];
  }
  if (!$term = taxonomy_term_load($tid)) {
    drupal_set_message(t('Term/Type ID is not valid.'), 'error');
    return FALSE;
  }
  // Always provide entity id in the same form key as in the entity edit form.
  $form['tid'] = array('#type' => 'value', '#value' => $tid);

  $form['#term'] = $term;
  $form['type'] = array('#type' => 'value', '#value' => 'term');
  $form['name'] = array('#type' => 'value', '#value' => $term->name);
  $form['vocabulary_machine_name'] = array(
    '#type' => 'value',
    '#value' => $term->vocabulary_machine_name,
  );
  $form['delete'] = array('#type' => 'value', '#value' => TRUE);

  return $form;
}

/**
 * Helper callback; Builds the edit term/type form.
 *
 * @return array
 *   The prepared edit form.
 */
function c4m_features_og_manage_categories_edit_form_build($form, &$form_state, $term, $vocabulary) {
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

  $vocab_name = isset($term->vocabulary_machine_name)
    ? $term->vocabulary_machine_name
    : $vocabulary->name;
  $form['vocabulary_machine_name'] = array(
    '#type' => 'value',
    '#value' => $vocab_name,
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
