<?php

/**
 * @file
 * Form alters that trigger or add notifications.
 */

/**
 * Triggers email notification when membership request is rejected.
 *
 * Triggers email notification when group administrator rejects membership
 * request.
 *
 * @param array $form
 *   Drupal form array.
 * @param array $form_state
 *   Drupal form_state array.
 */
function _c4m_user_notifications_form_c4m_og_reject_membership_request_alter(array &$form, array &$form_state) {
  module_load_include('inc', 'c4m_user_notifications', 'includes/c4m_user_notifications.notify');

  $form['#submit'][] = '_c4m_user_notifications_notify_user_og_group_membership_rejected';
  $form['#submit'][] = 'c4m_og_route_to_group_people';
}

/**
 * Triggers email notification when user is invited to group by admin.
 *
 * @param array $form
 *   Drupal form array.
 * @param array $form_state
 *   Drupal form_state array.
 */
function _c4m_user_notifications_form_og_ui_add_users_alter(array &$form, array &$form_state) {
  module_load_include('inc', 'c4m_user_notifications', 'includes/c4m_user_notifications.notify');

  // Apply only to SAs.
  $site_admin_role = user_role_load_by_name('administrator');
  if (!user_has_role($site_admin_role->rid)) {
    return;
  }

  // Remove request message and invitation option when adding a user to a group.
  $form['membership_fields'] = FALSE;

  // Add a checkbox for sending a welcome message.
  $form['og_user']['notification'] = [
    '#type' => 'checkbox',
    '#title' => 'Send a welcome email to the new user.',
    '#default_value' => 1,
    '#disabled' => 0,
    '#description' => NULL,
  ];

  // Add custom submit handler to process the notification.
  $form['#submit'][] = '_c4m_user_notifications_notify_user_og_group_membership_added_by_admin';
}
