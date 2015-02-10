<?php
/**
 * @file Administrator forms/functionality for OG members.
 */

define('C4M_ADMINISTRATOR_ROLE_NAME', 'administrator member');

/**
 * Form callback to promote a user.
 *
 * @param $form
 * @param $form_state
 * @param $account
 */
function c4m_features_og_members_promote($form, &$form_state, $account) {
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
        $error = t('User is blocked from this group.');
        break;
    }
  }

  $roles = og_roles('node', $group->type, $group->nid);

  $admin_role = array_search(C4M_ADMINISTRATOR_ROLE_NAME, $roles);
  if (!$admin_role) {
    $error = t('Could not find administrator role to give.');
  }

  $user_roles = og_get_user_roles('node', $group->nid, $account->uid);

  if (array_search(C4M_ADMINISTRATOR_ROLE_NAME, $user_roles)) {
    $warning = t('User already has administrator role for this group.');
  }

  $return_link = array(
    '#markup' => l(
      '&laquo; ' . t('Return to the members overview'), 'members',
      array('html' => TRUE)
    ),
  );

  if ($error) {
    $form['error_message'] = array(
      '#markup' => $error,
      '#prefix' => '<div class="alert alert-danger" role="alert">
  <span class="glyphicon glyphicon-exclamation-sign" aria-hidden="true"></span>
  <span class="sr-only">Error:</span>',
      '#suffix' => '</div>'
    );

    $form['return'] = $return_link;

    return $form;
  }
  elseif ($warning) {
    $form['warning_message'] = array(
      '#markup' => $warning,
      '#prefix' => '<div class="alert alert-warning" role="alert">
  <span class="glyphicon glyphicon-exclamation-sign" aria-hidden="true"></span>
  <span class="sr-only">Warning:</span>',
      '#suffix' => '</div>'
    );

    $form['return'] = $return_link;

    return $form;
  }
  else {
    // Add group membership form. We still don't have the user or state.
    $form_state['og_membership'] = $membership;

    return confirm_form(
      $form,
      t('Are you sure you want to promote user?'),
      url('members'),
      t('Are you sure you want to promote user %user to group administrator?',
        array('%user' => c4m_user_profile_name($account))
      ),
      t('Promote'),
      t('Return to the members overview')
    );
  }
}

/**
 * Submit handler; Edit membership in group.
 *
 * @param $form
 * @param $form_state
 */
function c4m_features_og_members_promote_submit($form, &$form_state) {
  $og_membership = $form_state['og_membership'];
  $group = node_load($og_membership->gid);

  if (!$group) {
    form_set_error(NULL, t('Error promoting user'));
  }

  $roles = og_roles('node', $group->type, $group->nid);

  $rid = array_search(C4M_ADMINISTRATOR_ROLE_NAME, $roles);

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
 * @param $form
 * @param $form_state
 * @param $account
 */
function c4m_features_og_members_demote($form, &$form_state, $account) {
  $group = c4m_og_current_group();
  $membership = og_get_membership('node', $group->nid, 'user', $account->uid);
  $error = NULL;
  $warning = NULL;

  if (!$membership) {
    $error = t('User is not a member of the group.');
  }

  $roles = og_roles('node', $group->type, $group->nid);

  $admin_role = array_search(C4M_ADMINISTRATOR_ROLE_NAME, $roles);
  if (!$admin_role) {
    $error = t('Could not find administrator role to give.');
  }

  $user_roles = og_get_user_roles('node', $group->nid, $account->uid);
  if (!array_search(C4M_ADMINISTRATOR_ROLE_NAME, $user_roles)) {
    $warning = t('User is not an administrator of this group.');
  }

  if ($group->uid == $account->uid) {
    $warning = t('Can not take away administrator role from the group manager.');
  }

  $return_link = array(
    '#markup' => l(
      '&laquo; ' . t('Return to the members overview'), 'members',
      array('html' => TRUE)
    ),
  );

  if ($error) {
    $form['error_message'] = array(
      '#markup' => $error,
      '#prefix' => '<div class="alert alert-danger" role="alert">
  <span class="glyphicon glyphicon-exclamation-sign" aria-hidden="true"></span>
  <span class="sr-only">Error:</span>',
      '#suffix' => '</div>'
    );

    $form['return'] = $return_link;

    return $form;
  }
  elseif ($warning) {
    $form['warning_message'] = array(
      '#markup' => $warning,
      '#prefix' => '<div class="alert alert-warning" role="alert">
  <span class="glyphicon glyphicon-exclamation-sign" aria-hidden="true"></span>
  <span class="sr-only">Warning:</span>',
      '#suffix' => '</div>'
    );

    $form['return'] = $return_link;

    return $form;
  }
  else {
    // Add group membership form. We still don't have the user or state.
    $form_state['og_membership'] = $membership;

    return confirm_form(
      $form,
      t('Are you sure you want to demote user?'),
      url('members'),
      t('Are you sure you want to take away the group administrator role from user %user?',
        array('%user' => c4m_user_profile_name($account))
      ),
      t('Demote'),
      t('Return to the members overview')
    );
  }
}

/**
 * Submit handler; Edit membership in group.
 *
 * @param $form
 * @param $form_state
 */
function c4m_features_og_members_demote_submit($form, &$form_state) {
  $og_membership = $form_state['og_membership'];
  $group = node_load($og_membership->gid);

  if (!$group) {
    form_set_error(NULL, t('Error demoting user'));
  }

  $roles = og_roles('node', $group->type, $group->nid);

  $rid = array_search(C4M_ADMINISTRATOR_ROLE_NAME, $roles);

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
 * @param $form
 * @param $form_state
 * @param $account
 */
function c4m_features_og_members_remove($form, &$form_state, $account) {
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

  $return_link = array(
    '#markup' => l(
      '&laquo; ' . t('Return to the members overview'), 'members',
      array('html' => TRUE)
    ),
  );

  if ($error) {
    $form['error_message'] = array(
      '#markup' => $error,
      '#prefix' => '<div class="alert alert-danger" role="alert">
  <span class="glyphicon glyphicon-exclamation-sign" aria-hidden="true"></span>
  <span class="sr-only">Error:</span>',
      '#suffix' => '</div>'
    );

    $form['return'] = $return_link;

    return $form;
  }
  elseif ($warning) {
    $form['warning_message'] = array(
      '#markup' => $warning,
      '#prefix' => '<div class="alert alert-warning" role="alert">
  <span class="glyphicon glyphicon-exclamation-sign" aria-hidden="true"></span>
  <span class="sr-only">Warning:</span>',
      '#suffix' => '</div>'
    );

    $form['return'] = $return_link;

    return $form;
  }
  else {
    // Add group membership form. We still don't have the user or state.
    $form_state['og_membership'] = $membership;

    return confirm_form(
      $form,
      t('Are you sure you want to remove user?'),
      url('members'),
      t('Are you sure you want to remove user %user from this group?',
        array('%user' => c4m_user_profile_name($account))
      ),
      t('Remove'),
      t('Return to the members overview')
    );
  }
}

/**
 * Submit handler; Remove membership in group.
 *
 * @param $form
 * @param $form_state
 */
function c4m_features_og_members_remove_submit($form, &$form_state) {
  $og_membership = $form_state['og_membership'];
  $group = node_load($og_membership->gid);

  if (!$group) {
    form_set_error(NULL, t('Error removing user'));
  }

  og_membership_delete($og_membership->id);

  $og_membership->save();

  drupal_set_message(t('User successfully removed.'));

  $form_state['redirect'] = 'members';
}