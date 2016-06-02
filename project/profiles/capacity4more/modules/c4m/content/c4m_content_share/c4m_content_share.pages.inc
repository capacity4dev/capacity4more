<?php

/**
 * @file
 * Forms and pages from the share module.
 */

/**
 * Render the form that lists the groups a user can share the content to.
 *
 * @param array $form
 *   Form render array.
 * @param array $form_state
 *   Form state array.
 *
 * @return array
 *   Form render array.
 *
 * @see c4m_content_share_form_validate
 *
 * @ingroup forms
 */
function c4m_content_share_form($form, &$form_state) {
  $groups = og_get_groups_by_user();

  if (empty($groups['node'])) {
    $form['info'] = array(
      '#markup' => t(
        'You are not a member of any groups to share to.'
      ),
    );

    return $form;
  }

  $node = menu_get_object();
  $node_form = new stdClass();
  $node_form->type = 'share';
  $node_form->language = LANGUAGE_NONE;
  module_load_include('inc', 'node', 'node.pages');
  $orig_form = drupal_get_form('share_node_form', $node_form);
  $types = node_type_get_types();
  $human_name = $types[$node->type]->name;

  $form['info'] = array(
    '#markup' => t(
      'You will share %node_type with title %node_title',
      array('%node_type' => $human_name, '%node_title' => $node->title)
    ),
    '#prefix' => '<h2>',
    '#suffix' => '</h2>',
    '#weight' => -5,
  );

  $form['og_group_ref'] = $orig_form['og_group_ref'];
  $form['og_group_ref'][LANGUAGE_NONE]['#title'] = t('Share to');
  $form['og_group_ref']['#weight'] = 3;

  $form['c4m_body'] = $orig_form['c4m_body'];
  $form['c4m_body']['#weight'] = 4;

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Share'),
    '#weight' => 10,
  );

  $form['#validate'][] = 'og_validate_widgets';
  $form['#validate'][] = 'c4m_content_share_form_validate';
  $form['#submit'][] = 'c4m_content_share_form_submit';

  return $form;
}

/**
 * Share form validator.
 *
 * @param array $form
 *   Form render array.
 * @param array $form_state
 *   Form state array.
 *
 * @see c4m_content_share_form
 *
 * @ingroup forms
 */
function c4m_content_share_form_validate($form, &$form_state) {
  $node = menu_get_object();
  $group = og_context();

  $group_ref = $form_state['input']['og_group_ref'][LANGUAGE_NONE][0];

  $default = $group_ref['default'];
  $admin = $group_ref['admin'];

  if ((empty($default) || $default === '_none') && (empty($admin) || empty($admin[0]['target_id']))) {
    form_set_error('og_group_ref', t('You need a group reference'));
    return;
  }

  if ((!empty($default) && $default !== '_none') && (!empty($admin) && !empty($admin[0]['target_id']))) {
    form_set_error(
      'og_group_ref',
      t('Please only select either of both group selections.')
    );
    return;
  }

  $form_state['values']['nid'] = $node->nid;
  $form_state['values']['gid'] = $group['gid'];
  $form_state['values']['title'] = $node->title;
  $form_state['values']['c4m_source_entity'] = $node->nid;
  $form_state['values']['og_group_ref'] = !empty($default) ? $default : $admin;
}

/**
 * Share form validator.
 *
 * @param array $form
 *   Form render array.
 * @param array $form_state
 *   Form state array.
 *
 * @see c4m_content_share_form
 *
 * @ingroup forms
 */
function c4m_content_share_form_submit($form, &$form_state) {
  $values = $form_state['values'];

  $node = new stdClass();
  $node->title = $values['title'];
  $node->type = 'share';

  node_object_prepare($node);

  // If this is a book page, we need an extra step.
  $original_node = entity_metadata_wrapper(
    'node',
    $values['c4m_source_entity']
  );

  if ($original_node->getBundle() === 'wiki_page') {
    $bid = c4m_content_wiki_page_get_bid_by_nid($values['og_group_ref']);
    $book = $node->book;
    $book['bid'] = $bid;
    $book['original_bid'] = $bid;
    $node->book = $book;
  }

  $node_wrapper = entity_metadata_wrapper('node', $node);

  $node_wrapper->og_group_ref = $values['og_group_ref'];
  $node_wrapper->c4m_source_entity = $values['c4m_source_entity'];

  $node_wrapper->save();

  $group = node_load($values['og_group_ref']);
  drupal_set_message(
    t(
      'Successfully shared %node_title to <a href="@group_url">%group_title</a>.',
      array(
        '%node_title' => $values['title'],
        '%group_title' => $group->title,
        '@group_url' => url(
          '<front>',
          array(
            'absolute' => TRUE,
            'purl' => array(
              'provider' => 'og_purl|node',
              'id' => $group->nid,
            ),
          )
        ),
      )
    )
  );

  $form_state['redirect'] = url(
    'node/' . $values['nid'],
    array(
      'absolute' => TRUE,
      'purl' => array(
        'provider' => 'og_purl|node',
        'id' => $values['gid'],
      ),
    )
  );
}
