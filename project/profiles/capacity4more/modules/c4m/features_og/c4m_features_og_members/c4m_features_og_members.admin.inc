<?php

/**
 * @file
 * Administrator forms/functionality for OG members.
 */

/**
 * Form callback to promote a user.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state.
 * @param object $account
 *   The user account.
 *
 * @return array
 *   The confirmation form.
 */
function c4m_features_og_members_promote(array $form, array &$form_state, $account) {
  $group = c4m_og_current_group();
  $membership = og_get_membership('node', $group->nid, 'user', $account->uid);
  $error = NULL;
  $warning = NULL;

  if ($group->uid == $account->uid) {
    $warning = t('User is already the group manager.');
  }

  if (!$membership) {
    $error = t('User is not a member of the group.');
  }
  else {
    switch ($membership->state) {
      case OG_STATE_PENDING:
        $error = t('User is not approved as group member yet.');
        break;

      case OG_STATE_BLOCKED:
        $error = t('User is rejected from this group.');
        break;
    }
  }

  $roles = og_roles('node', $group->type, $group->nid);

  $admin_role = array_search(C4M_FEATURES_OG_MEMBERS_ADMINISTRATOR_ROLE_NAME, $roles);
  if (!$admin_role) {
    $error = t('Could not find administrator role to give.');
  }

  $user_roles = og_get_user_roles('node', $group->nid, $account->uid);

  if (array_search(C4M_FEATURES_OG_MEMBERS_ADMINISTRATOR_ROLE_NAME, $user_roles)) {
    $warning = t('User already has administrator role for this group.');
  }

  $return_link_text = '&laquo; ' . t('Return to the members overview');
  $return_link = array(
    '#markup' => l(
      $return_link_text,
      'members',
      array('html' => TRUE)
    ),
  );

  if ($error) {
    _c4m_features_og_members_create_form_alert($form, $error, 'error', 'danger');

    $form['return'] = $return_link;

    return $form;
  }
  elseif ($warning) {
    _c4m_features_og_members_create_form_alert($form, $warning);

    $form['return'] = $return_link;

    return $form;
  }
  else {
    // Add group membership form. We still don't have the user or state.
    $form_state['og_membership'] = $membership;

    return confirm_form(
      $form,
      t('Are you sure you want to promote user?'),
      'members',
      t('Are you sure you want to promote user %user to group administrator?',
        array('%user' => c4m_user_name($account))
      ),
      t('Promote'),
      t('Return to the members overview')
    );
  }
}

/**
 * Submit handler; Edit membership in group.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 */
function c4m_features_og_members_promote_submit(array $form, array &$form_state) {
  $og_membership = $form_state['og_membership'];
  $group = node_load($og_membership->gid);

  if (!$group) {
    form_set_error(NULL, t('Error promoting user'));
  }

  $roles = og_roles('node', $group->type, $group->nid);

  $rid = array_search(C4M_FEATURES_OG_MEMBERS_ADMINISTRATOR_ROLE_NAME, $roles);

  if (!$rid) {
    form_set_error(NULL, t('Error promoting user'));
  }

  og_role_grant('node', $group->nid, $og_membership->etid, $rid);

  $og_membership->save();

  drupal_set_message(t('User successfully promoted.'));

  $form_state['redirect'] = 'members';
}

/**
 * Form callback to demote a user.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 * @param object $account
 *   The user account.
 *
 * @return array
 *   The confirmation form.
 */
function c4m_features_og_members_demote(array $form, array &$form_state, $account) {
  $group = c4m_og_current_group();
  $membership = og_get_membership('node', $group->nid, 'user', $account->uid);
  $error = NULL;
  $warning = NULL;

  if (!$membership) {
    $error = t('User is not a member of the group.');
  }

  $roles = og_roles('node', $group->type, $group->nid);

  $admin_role = array_search(C4M_FEATURES_OG_MEMBERS_ADMINISTRATOR_ROLE_NAME, $roles);
  if (!$admin_role) {
    $error = t('Could not find administrator role to give.');
  }

  $user_roles = og_get_user_roles('node', $group->nid, $account->uid);
  if (!array_search(C4M_FEATURES_OG_MEMBERS_ADMINISTRATOR_ROLE_NAME, $user_roles)) {
    $warning = t('User is not an administrator of this group.');
  }

  if ($group->uid == $account->uid) {
    $warning = t('Can not take away administrator role from the group manager.');
  }

  $return_text = '&laquo; ' . t('Return to the members overview');
  $return_link = array(
    '#markup' => l(
      $return_text,
      'members',
      array('html' => TRUE)
    ),
  );

  if ($error) {
    _c4m_features_og_members_create_form_alert($form, $error, 'error', 'danger');

    $form['return'] = $return_link;

    return $form;
  }
  elseif ($warning) {
    _c4m_features_og_members_create_form_alert($form, $warning);

    $form['return'] = $return_link;

    return $form;
  }
  else {
    // Add group membership form. We still don't have the user or state.
    $form_state['og_membership'] = $membership;

    return confirm_form(
      $form,
      t('Are you sure you want to demote user?'),
      'members',
      t('Are you sure you want to take away the group administrator role from user %user?',
        array('%user' => c4m_user_name($account))
      ),
      t('Demote'),
      t('Return to the members overview')
    );
  }
}

/**
 * Submit handler; Edit membership in group.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 */
function c4m_features_og_members_demote_submit(array $form, array &$form_state) {
  $og_membership = $form_state['og_membership'];
  $group = node_load($og_membership->gid);

  if (!$group) {
    form_set_error(NULL, t('Error demoting user'));
  }

  $roles = og_roles('node', $group->type, $group->nid);

  $rid = array_search(C4M_FEATURES_OG_MEMBERS_ADMINISTRATOR_ROLE_NAME, $roles);

  if (!$rid) {
    form_set_error(NULL, t('Error demoting user'));
  }

  og_role_revoke('node', $group->nid, $og_membership->etid, $rid);

  $og_membership->save();

  drupal_set_message(t('User successfully demoted.'));

  $form_state['redirect'] = 'members';
}

/**
 * Form callback to remove a user.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 * @param object $account
 *   The user account.
 *
 * @return array
 *   The confirmation form.
 */
function c4m_features_og_members_remove(array $form, array &$form_state, $account) {
  $group = c4m_og_current_group();
  $membership = og_get_membership('node', $group->nid, 'user', $account->uid);
  $error = NULL;
  $warning = NULL;

  if (!$membership) {
    $error = t('User is not a member of the group.');
  }

  if ($group->uid == $account->uid) {
    $warning = t('Can not remove the group manager.');
  }

  $return_text = '&laquo; ' . t('Return to the members overview');
  $return_link = array(
    '#markup' => l(
      $return_text,
      'members',
      array('html' => TRUE)
    ),
  );

  if ($error) {
    _c4m_features_og_members_create_form_alert($form, $error, 'error', 'danger');

    $form['return'] = $return_link;

    return $form;
  }
  elseif ($warning) {
    _c4m_features_og_members_create_form_alert($form, $warning);

    $form['return'] = $return_link;

    return $form;
  }
  else {
    // Add group membership form. We still don't have the user or state.
    $form_state['og_membership'] = $membership;

    return confirm_form(
      $form,
      t('Are you sure you want to remove user?'),
      'members',
      t('Are you sure you want to remove user %user from this group?',
        array('%user' => c4m_user_name($account))
      ),
      t('Remove'),
      t('Return to the members overview')
    );
  }
}

/**
 * Submit handler; Remove membership in group.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 */
function c4m_features_og_members_remove_submit(array $form, array &$form_state) {
  $og_membership = $form_state['og_membership'];
  $group = node_load($og_membership->gid);

  if (!$group) {
    form_set_error(NULL, t('Error removing user'));
  }

  og_ungroup($og_membership->group_type, $og_membership->gid, $og_membership->entity_type, $og_membership->etid);

  drupal_set_message(t('User successfully removed.'));

  $form_state['redirect'] = 'members';
}

/**
 * Form callback to approve a user.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 * @param object $account
 *   The user account.
 *
 * @return array
 *   Approve form.
 */
function c4m_features_og_members_approve(array $form, array &$form_state, $account) {
  $group = c4m_og_current_group();
  $membership = og_get_membership('node', $group->nid, 'user', $account->uid);
  $error = NULL;
  $warning = NULL;

  if (!$membership) {
    $error = t('User is not a member of the group.');
  }
  else {
    switch ($membership->state) {
      case OG_STATE_ACTIVE:
        $error = t('User is already approved as a group member yet.');
        break;

      case OG_STATE_BLOCKED:
        $error = t('User is rejected from this group.');
        break;
    }
  }

  $return_text = '&laquo; ' . t('Return to the members overview');
  $return_link = array(
    '#markup' => l(
      $return_text, 'members',
      array('html' => TRUE)
    ),
  );

  if ($error) {
    _c4m_features_og_members_create_form_alert($form, $error, 'error', 'danger');

    $form['return'] = $return_link;

    return $form;
  }
  elseif ($warning) {
    _c4m_features_og_members_create_form_alert($form, $warning);

    $form['return'] = $return_link;

    return $form;
  }
  else {
    // Add group membership form. We still don't have the user or state.
    $form_state['og_membership'] = $membership;

    return confirm_form(
      $form,
      t('Are you sure you want to approve user?'),
      'members',
      t('Are you sure you want to approve user %user as a member of this group?',
        array('%user' => c4m_user_name($account))
      ),
      t('Approve'),
      t('Return to the members overview')
    );
  }
}

/**
 * Submit handler; Remove membership in group.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 */
function c4m_features_og_members_approve_submit(array $form, array &$form_state) {
  $og_membership = $form_state['og_membership'];
  $group = node_load($og_membership->gid);

  if (!$group) {
    form_set_error(NULL, t('Error approving user'));
  }

  $og_membership->state = OG_STATE_ACTIVE;
  og_membership_save($og_membership);
  drupal_set_message(t('User successfully approved to the group.'));

  $form_state['redirect'] = 'members';
}

/**
 * Form callback to approve a user.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 * @param object $account
 *   The user account.
 *
 * @return array
 *   The form.
 */
function c4m_features_og_members_reject(array $form, array &$form_state, $account) {
  $group = c4m_og_current_group();
  $membership = og_get_membership('node', $group->nid, 'user', $account->uid);
  $error = NULL;
  $warning = NULL;

  if (!$membership) {
    $error = t('User is not a member of the group.');
  }
  else {
    switch ($membership->state) {
      case OG_STATE_ACTIVE:
        $error = t('User is already approved as a group member yet.');
        break;

      case OG_STATE_BLOCKED:
        $error = t('User is rejected from this group.');
        break;
    }
  }

  $return_text = '&laquo; ' . t('Return to the members overview');
  $return_link = array(
    '#markup' => l(
      $return_text,
      'members',
      array('html' => TRUE)
    ),
  );

  if ($error) {
    _c4m_features_og_members_create_form_alert($form, $error, 'error', 'danger');

    $form['return'] = $return_link;

    return $form;
  }
  elseif ($warning) {
    _c4m_features_og_members_create_form_alert($form, $warning);

    $form['return'] = $return_link;

    return $form;
  }
  else {
    // Add group membership form. We still don't have the user or state.
    $form_state['og_membership'] = $membership;

    return confirm_form(
      $form,
      t('Are you sure you want to reject user?'),
      'members',
      t('Are you sure you want to reject user %user as a member of this group?',
        array('%user' => c4m_user_name($account))
      ),
      t('Reject'),
      t('Return to the members overview')
    );
  }
}

/**
 * Submit handler; Remove membership in group.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 */
function c4m_features_og_members_reject_submit(array $form, array &$form_state) {
  $og_membership = $form_state['og_membership'];
  $group = node_load($og_membership->gid);

  if (!$group) {
    form_set_error(NULL, t('Error rejecting user'));
  }

  $og_membership->state = OG_STATE_BLOCKED;
  og_membership_save($og_membership);
  drupal_set_message(t('User successfully rejected from the group.'));

  $form_state['redirect'] = 'members';
}

/**
 * Create an alert form item.
 *
 * @param array $form
 *   The form array.
 * @param string $message
 *   The message string.
 * @param string $severity
 *   The message severity level.
 * @param string $class
 *   The css class name.
 */
function _c4m_features_og_members_create_form_alert(array &$form, $message, $severity = 'warning', $class = 'warning') {
  $prefix = array(
    '<div class="alert alert-' . $class . '" role="alert">',
    '<span class="fa fa-exclamation-circle" aria-hidden="true"></span>',
    '<span class="sr-only">' . ucfirst($severity) . ':</span>',
  );

  $form[$severity . '_message'] = array(
    '#markup' => $message,
    '#prefix' => implode(PHP_EOL, $prefix),
    '#suffix' => '</div>',
  );
}
