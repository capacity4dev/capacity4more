<?php

/**
 * @file
 * c4m_user_profile.pages.inc
 */

/**
 * Form constructor for the resend email change confirmation email form.
 *
 * @see c4m_user_profile_resend_email_change_confirmation_email_form_submit()
 *
 * @ingroup forms
 */
function c4m_user_profile_resend_email_change_confirmation_email_form($form, &$form_state) {
  $question = t('Resend email change confirmation');
  return confirm_form($form,
    $question,
    'user',
    t('<p>Are you sure you want to resend the email change confirmation?</p>'),
    t('Send'), t('Cancel'));
}

/**
 * Form validation handler for the resend email change confirmation email form.
 *
 * @see c4m_user_profile_resend_email_change_confirmation_email_form()
 */
function c4m_user_profile_resend_email_change_confirmation_email_form_validate($form, &$form_state) {
  global $user;

  if (!isset($user->data['email_confirm']) || !isset($user->data['email_confirm']['pending_email']) || $user->data['email_confirm']['expiration_time'] <= REQUEST_TIME) {
    form_set_error(NULL, t('You no longer require to validate your new email address.'));
  }
}

/**
 * Form submission handler for the resend email change confirmation email form.
 *
 * @see c4m_user_profile_resend_email_change_confirmation_email_form()
 */
function c4m_user_profile_resend_email_change_confirmation_email_form_submit($form, &$form_state) {
  global $user;
  $account = user_load($user->uid);
  email_confirm_build_mail(['mail' => $account->data['email_confirm']['pending_email']], $account);
  $form_state['redirect'] = 'user';
}

/**
 * Form constructor for the remove account confirmation form.
 *
 * @see c4m_user_profile_remove_account_form_submit()
 *
 * @ingroup forms
 */
function c4m_user_profile_remove_account_form($form, $form_state, $account) {
  if ($groups = c4m_og_get_user_owned_groups($account->uid, [
    'group',
    'project',
  ])) {
    $items = [];

    foreach ($groups as $nid => $title) {
      $items[] = l($title, 'node/' . $nid);
    }

    $form['warning'] = [
      '#markup' => '<p>' . t("You can't leave the platform meanwhile you still own groups and projects. Please, transfer the ownership first.") . '</p>' . theme('item_list', ['items' => $items]),
    ];

    return $form;
  }

  // We emulate the default user deletion form values to use
  // the default process.
  $form['_account'] = [
    '#type' => 'value',
    '#value' => $account,
  ];

  $form['uid'] = [
    '#type' => 'value',
    '#value' => $account->uid,
  ];

  $form['user_cancel_confirm'] = [
    '#type' => 'value',
    '#value' => FALSE,
  ];

  $form['user_cancel_notify'] = [
    '#type' => 'value',
    '#value' => FALSE,
  ];

  $form['user_cancel_method'] = [
    '#type' => 'value',
    // This method will block the user but leave the content
    // assigned to the user.
    '#value' => 'user_cancel_block',
  ];

  $form['anonymize'] = [
    '#type' => 'checkbox',
    '#title' => t('I no longer want my name to appear on contents I have contributed - please make all my content anonymous.'),
  ];

  $form['feedback'] = [
    '#type' => 'textarea',
    '#title' => t('Provide a reason (optional)'),
  ];

  $question = t('Are you sure you want to leave the platform? This action is irreversible');

  return confirm_form($form, $question, 'user');
}

/**
 * Form submission handler for the remove account confirmation form.
 *
 * @see c4m_user_profile_remove_account_form()
 */
function c4m_user_profile_remove_account_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $account = $values['_account'];

  if ($values['anonymize']) {
    // This cancel method will reassign all the content of the user
    // to the anonymous user.
    $values['user_cancel_method'] = 'c4m_user_admin_block_anonymous';
  }

  $gids = c4m_og_get_user_group_ids_by_bundle(NULL, $account);

  if (!empty($gids)) {
    // Remove all memberships of the user.
    foreach ($gids as $gid) {
      og_ungroup('node', $gid, 'user', $account->uid);
    }
  }

  // This calls the default Drupal workflow for cancelling an account.
  user_cancel($values, $values['uid'], $values['user_cancel_method']);

  drupal_set_message(t('Your account has been successfully removed from the platform.'));

  // As the user no longer exists, it doesn't have access to the
  // current page (user profile). So we redirect it to the homepage.
  $form_state['redirect'] = '<front>';
}

/**
 * User settings form where message digest intervals are set.
 *
 * @param array $form
 *   Form build array.
 * @param array $form_state
 *   Form state array.
 * @param object $account
 *   Drupal user entity object.
 */
function c4m_user_profile_settings_form(array $form, array &$form_state, $account) {
  drupal_set_title(t('Edit settings'));

  $digest_options = [
    C4M_MESSAGE_DIGEST_FREQUENCY_NEVER => t('Never'),
    C4M_MESSAGE_DIGEST_FREQUENCY_IMMEDIATELY => t('Immediate'),
  ];

  $digest_options += message_notify_get_notifiers_as_options();

  $original_values = [];

  _c4m_user_profile_settings_form_interests($form, $digest_options, $original_values, $account);
  _c4m_user_profile_settings_form_groups($form, $digest_options, $original_values, $account);
  _c4m_user_profile_settings_form_nodes($form, $digest_options, $original_values, $account);
  _c4m_user_profile_settings_form_comments($form, $digest_options, $original_values, $account);
  _c4m_user_profile_settings_form_extra_settings($form, $form_state, $account);

  $form['original_preferences'] = [
    '#type' => 'value',
    '#value' => $original_values,
  ];

  $form['user'] = ['#type' => 'value', '#value' => $account->uid];

  $form['actions']['submit'] = [
    '#type' => 'submit',
    '#value' => t('Save'),
  ];

  $form['actions']['cancel'] = [
    '#markup' => l(
      t('Cancel'),
      '<front>',
      ['attributes' => ['class' => ['btn', 'btn-default']]]
    ),
  ];

  return $form;
}

/**
 * Submit handler for the user settings form.
 *
 * @param array $form
 *   Form build array.
 * @param array $form_state
 *   Form state array.
 */
function c4m_user_profile_settings_form_submit(array $form, array &$form_state) {
  $originals = $form_state['values']['original_preferences'];
  $new_values = array_intersect_key($form_state['values'], $originals);
  $updates = array_diff_assoc($new_values, $originals);

  if (!empty($updates)) {
    foreach ($updates as $flagging_id => $update) {
      $flagging = flagging_load($flagging_id);
      $flagging->preference = $update;
      c4m_message_digest_set_preference($flagging);
    }
  }

  _c4m_user_profile_settings_form_submit_extra_settings($form, $form_state);

  drupal_set_message(t('Successfully saved preferences'));
}

/**
 * Saves extra settings in the user settings form.
 *
 * @param array $form
 *   Form build array.
 * @param array $form_state
 *   Form state array.
 */
function _c4m_user_profile_settings_form_submit_extra_settings(array $form, array &$form_state) {
  global $user;

  $edit = [
    'overlay' => !empty($form_state['values']['overlay']),
    'mimemail_textonly' => !empty($form_state['values']['mimemail_textonly']),
    'timezone' => $form_state['values']['timezone'],
    'contact' => $form_state['values']['contact'],
  ];

  user_save($user, $edit);
}

/**
 * Build the form for the topics/regions of interests.
 *
 * @param array $form
 *   Reference to the settings form.
 * @param array $digest_options
 *   Digest options.
 * @param object $account
 *   Drupal user object.
 */
function _c4m_user_profile_settings_form_interests(array &$form, array $digest_options, &$original_values, $account) {
  $vocabularies = [];

  $form['subscribe_c4m_follow_term'] = [
    '#type' => 'fieldset',
    '#title' => t('Your interest notifications'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  ];

  $form['subscribe_c4m_follow_term']['summary'] = [
    '#markup' => t('By indicating thematic of geographic interests, you are automatically subscribed to a weekly notification bringing together the latest highlighted items.'),
  ];

  $button_interest = l('<i class="fa fa-plus"></i> ' . t('Subscribe to topics'), 'user/' . $account->uid . '/edit', [
    'html' => TRUE,
    'absolute' => TRUE,
    'attributes' => [
      'class' => [
        'btn',
        'btn-primary',
      ],
    ],
    'fragment' => 'edit-c4m-vocab-topic',
  ]);
  $button_geography = l('<i class="fa fa-plus"></i> ' . t('Subscribe to regions & countries'), 'user/' . $account->uid . '/edit', [
    'html' => TRUE,
    'absolute' => TRUE,
    'attributes' => [
      'class' => [
        'btn',
        'btn-primary',
      ],
    ],
    'fragment' => 'edit-c4m-vocab-geo',
  ]);

  $form['subscribe_c4m_follow_term']['edit_buttons'] = [
    '#type' => 'container',
    '#children' => $button_interest . ' ' . $button_geography,
    '#prefix' => '<div>',
    '#suffix' => '</div>',
  ];

  $form['subscribe_c4m_follow_term']['frequency'] = [
    '#markup' => '<h3>' . t('Preferences') . '</h3>',
  ];

  $flag = flag_get_flag('subscribe_c4m_follow_term');
  $flaggings = c4m_user_profile_get_flag_flaggings($flag, $account);

  // @TODO: Sort by tid, hierarchy, vocabulary...?

  foreach ($flaggings as $flagging_id) {
    $flagging = flagging_load($flagging_id);

    $default_option = $flagging->preference;

    $taxonomy_term = entity_load_single($flagging->entity_type, $flagging->entity_id);
    $parents = taxonomy_get_parents_all($taxonomy_term->tid);
    $term_name = [];

    if (!empty($parents)) {
      foreach (array_reverse($parents) as $parent) {
        $term_name[] = l($parent->name, 'taxonomy/term/' . $parent->tid);
      }
    }

    if (empty($vocabularies[$taxonomy_term->vid])) {
      $vocabularies[$taxonomy_term->vid] = taxonomy_vocabulary_load($taxonomy_term->vid);
    }

    $vocabulary_label = [
      '#type' => 'html_tag',
      '#tag' => 'span',
      '#value' => $vocabularies[$taxonomy_term->vid]->name,
      '#attributes' => ['class' => ['badge']],
    ];

    $form['subscribe_c4m_follow_term']['flags'][$flagging_id] = [
      '#type' => 'select',
      '#options' => $digest_options,
      '#default_value' => $default_option,
      '#prefix' => '<div class="user_settings_row">',
      '#suffix' => drupal_render($vocabulary_label) . ' ' . '<span>' . implode(' » ', $term_name) . '</span></div>',
    ];
    $original_values[$flagging_id] = $default_option;
  }
}

/**
 * Build the form for the group/project follows.
 *
 * @param array $form
 *   Reference to the settings form.
 * @param array $digest_options
 *   Digest options.
 * @param object $account
 *   Drupal user object.
 */
function _c4m_user_profile_settings_form_groups(array &$form, array $digest_options, &$original_values, $account) {
  $form['subscribe_c4m_follow_group'] = [
    '#type' => 'fieldset',
    '#title' => t('Your group/project notifications'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  ];

  $form['subscribe_c4m_follow_group']['summary'] = [
    '#markup' => t('Group members are automatically subscribed to a weekly notification bringing together the latest group updates.'),
  ];

  $form['subscribe_c4m_follow_group']['frequency'] = [
    '#markup' => '<h3>' . t('Preferences') . '</h3>',
  ];

  $flag = flag_get_flag('subscribe_c4m_follow_group');
  $flaggings = c4m_user_profile_get_flag_flaggings($flag, $account);

  foreach ($flaggings as $flagging_id) {
    $flagging = flagging_load($flagging_id);

    $default_option = $flagging->preference;

    $group = entity_load_single($flagging->entity_type, $flagging->entity_id);

    if ($group->type == 'group') {
      $group_type = c4m_og_get_access_type($group);

      $icon_tag = [
        '#type' => 'html_tag',
        '#tag' => 'i',
        '#value' => '',
        '#attributes' => [
          'class' => [
            'node-icon',
            'as-group-' . $group_type['type'],
          ],
        ],
      ];
    }
    else {
      $entity_wrapper = entity_metadata_wrapper('node', $group);
      $project_type = $entity_wrapper->c4m_project_type->value();

      $icon_tag = [
        '#type' => 'html_tag',
        '#tag' => 'i',
        '#value' => '',
        '#attributes' => [
          'class' => [
            'node-icon',
            'fa',
            ($project_type === 'programme') ? 'fa-puzzle-piece' : 'fa-flag-checkered',
            'group-type-icon',
          ],
        ],
      ];
    }

    $bell_icon = [
      '#type' => 'html_tag',
      '#tag' => 'i',
      '#value' => '',
      '#attributes' => [
        'class' => [
          'fa',
          'fa-bell-o',
        ],
      ],
    ];

    $disable_link = [
      '#type' => 'html_tag',
      '#tag' => 'span',
      '#value' => drupal_render($bell_icon) . ' ' . flag_create_link('subscribe_c4m_follow_group', $group->nid),
      '#attributes' => [
        'class' => [
          'disable-notifications',
        ],
      ],
    ];

    $form['subscribe_c4m_follow_group']['flags'][$flagging_id] = [
      '#type' => 'select',
      '#options' => $digest_options,
      '#default_value' => $default_option,
      '#prefix' => '<div class="user_settings_row">',
      '#suffix' => drupal_render($icon_tag) . ' ' . '<span>' . l($group->title, 'node/' . $group->nid) . '</span>' . drupal_render($disable_link) . '</div>',
    ];
    $original_values[$flagging_id] = $default_option;
  }
}

/**
 * Build the form for the node follows.
 *
 * @param array $form
 *   Reference to the settings form.
 * @param array $digest_options
 *   Digest options.
 * @param object $account
 *   Drupal user object.
 */
function _c4m_user_profile_settings_form_nodes(array &$form, array $digest_options, &$original_values, $account) {
  $form['subscribe_c4m_follow_node'] = [
    '#type' => 'fieldset',
    '#title' => t('Your follow notifications'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  ];

  $form['subscribe_c4m_follow_node']['summary'] = [
    '#markup' => t('You can also subscribe to individual items across the platforn - to follow new items, subscribe directly from the content page.'),
  ];

  $form['subscribe_c4m_follow_node']['frequency'] = [
    '#markup' => '<h3>' . t('Preferences') . '</h3>',
  ];

  $flag = flag_get_flag('subscribe_c4m_follow_node');
  $flaggings = c4m_user_profile_get_flag_flaggings($flag, $account);

  foreach ($flaggings as $flagging_id) {
    $flagging = flagging_load($flagging_id);

    $default_option = $flagging->preference;

    $node = entity_load_single($flagging->entity_type, $flagging->entity_id);

    $info = c4m_helper_entity_label_info($node);

    $icon_tag = [
      '#type' => 'html_tag',
      '#tag' => 'i',
      '#value' => '',
      '#attributes' => ['class' => ['fa', $info['icon']]],
    ];

    $node_link = l($node->title, 'node/' . $node->nid);

    $form['subscribe_c4m_follow_node']['flags'][$flagging_id] = [
      '#type' => 'select',
      '#options' => $digest_options,
      '#default_value' => $default_option,
      '#prefix' => '<div class="user_settings_row">',
      '#suffix' => '<span>' . drupal_render($icon_tag) . ' ' . $node_link . '</span></div>',
    ];
    $original_values[$flagging_id] = $default_option;
  }
}

/**
 * Build the form for the comment follows.
 *
 * @param array $form
 *   Reference to the settings form.
 * @param array $digest_options
 *   Digest options.
 * @param object $account
 *   Drupal user object.
 */
function _c4m_user_profile_settings_form_comments(array &$form, array $digest_options, &$original_values, $account) {
  $form['subscribe_c4m_follow_comment'] = [
    '#type' => 'fieldset',
    '#title' => t('Your comment notifications'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  ];

  $form['subscribe_c4m_follow_comment']['frequency'] = [
    '#markup' => '<h3>' . t('Preferences') . '</h3>',
  ];

  // Comments are also treated as node follows.
  $flag = flag_get_flag('subscribe_c4m_follow_comment');
  $flaggings = c4m_user_profile_get_flag_flaggings($flag, $account);

  foreach ($flaggings as $flagging_id) {
    $flagging = flagging_load($flagging_id);

    $default_option = $flagging->preference;

    $node = entity_load_single($flagging->entity_type, $flagging->entity_id);

    $info = c4m_helper_entity_label_info($node);

    $icon_tag = [
      '#type' => 'html_tag',
      '#tag' => 'i',
      '#value' => '',
      '#attributes' => ['class' => ['fa', $info['icon']]],
    ];

    $node_link = l($node->title, 'node/' . $node->nid);

    $form['subscribe_c4m_follow_comment']['flags'][$flagging_id] = [
      '#type' => 'select',
      '#options' => $digest_options,
      '#default_value' => $default_option,
      '#prefix' => '<div class="user_settings_row">',
      '#suffix' => '<span>' . drupal_render($icon_tag) . ' ' . $node_link . '</span></div>',
    ];
    $original_values[$flagging_id] = $default_option;
  }
}

/**
 * Extra settings form items in the Settings form.
 *
 * @param array $form
 *   Form build array.
 * @param array $form_state
 *   Form state array.
 * @param object $account
 *   Drupal user entity object.
 */
function _c4m_user_profile_settings_form_extra_settings(array &$form, array &$form_state, $account) {
  // Add Overlay settings.
  // @see overlay_form_user_profile_form_alter()
  if (user_access('access overlay', $account)) {
    $form['overlay_control'] = [
      '#type' => 'fieldset',
      '#title' => t('Administrative overlay'),
    ];

    $form['overlay_control']['overlay'] = [
      '#type' => 'checkbox',
      '#title' => t('Use the overlay for administrative pages.'),
      '#description' => t('Show administrative pages on top of the page you started from.'),
      '#default_value' => isset($account->data['overlay']) ? $account->data['overlay'] : 1,
    ];
  }

  // Add Email settings.
  // @see mimemail_form_user_profile_form_alter()
  $form['mimemail'] = [
    '#type' => 'fieldset',
    '#title' => t('Email settings'),
    '#access' => user_access('edit mimemail user settings'),
  ];
  $form['mimemail']['mimemail_textonly'] = [
    '#type' => 'checkbox',
    '#title' => t('Plaintext email only'),
    '#default_value' => !empty($account->data['mimemail_textonly']) ? $account->data['mimemail_textonly'] : FALSE,
    '#description' => t('Check this option if you do not wish to receive email messages with graphics and styles.'),
  ];

  // Add checkbox for contact options.
  // @see contact_form_user_profile_form_alter().
  $form['mimemail']['contact'] = [
    '#type' => 'checkbox',
    '#title' => t('Members are allowed to contact you through your personal contact form'),
    '#default_value' => !empty($account->data['contact']) ? $account->data['contact'] : FALSE,
    '#group' => 'group_public_profile',
  ];

  // Add Locale settings.
  // @see system_user_timezone()
  $form['timezone'] = [
    '#type' => 'fieldset',
    '#title' => t('Locale settings'),
  ];
  $form['timezone']['timezone'] = [
    '#type' => 'select',
    '#title' => t('Time zone'),
    '#default_value' => isset($account->timezone) ? $account->timezone : variable_get('date_default_timezone', ''),
    '#options' => system_time_zones(FALSE),
    '#description' => t('Select the desired local time and time zone. Dates and times throughout this site will be displayed using this time zone.'),
  ];
  if (!isset($account->timezone) && empty($form_state['input']['timezone'])) {
    $form['timezone']['timezone']['#attributes'] = ['class' => ['timezone-detect']];
    drupal_add_js('misc/timezone.js');
  }
}

/**
 * Retrieve all the flaggings for one user in one specific flag.
 *
 * @param object $flag
 *   Drupal flag entity object.
 * @param object $user
 *   Drupal user entity object.
 *
 * @return array
 *   Flagging ID's for the user/flag.
 */
function c4m_user_profile_get_flag_flaggings($flag, $user) {
  $flags = &drupal_static(__FUNCTION__);

  // We check to see if the flag count is already in the cache,
  // if it's not, run the query.
  if (!isset($flags[$flag->name][$user->uid])) {
    $flags[$flag->name][$user->uid] = [];
    $query = db_select('flagging', 'f');

    $query->fields('f', ['flagging_id'])
      ->orderBy('fid')
      ->orderBy('entity_id')
      ->condition('fid', $flag->fid)
      ->condition('uid', $user->uid);

    $result = $query->execute()
      ->fetchCol();

    $flags[$flag->name][$user->uid] = $result;
  }

  return $flags[$flag->name][$user->uid];
}

/**
 * Callback for the user-organisations page.
 */
function _c4m_user_profile_organisations($text) {
  $results = [];

  if (strlen($text) >= 3) {
    $query = db_select('field_data_c4m_organisation', 'o')
      ->distinct()
      ->condition('c4m_organisation_value', db_like($text) . '%', 'LIKE')
      ->fields('o', ['c4m_organisation_value'])
      ->orderBy('c4m_organisation_value', 'ASC')
      ->range(0, 10);
    $results = $query->execute()->fetchCol();
  }

  drupal_json_output($results);
}
