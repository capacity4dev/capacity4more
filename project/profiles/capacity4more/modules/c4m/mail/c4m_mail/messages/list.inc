<?php

/**
 * @file
 * Index of all the messages.
 */

$messages = array(
  // Account Settings (/admin/config/people/accounts).
  array(
    'module' => 'email_confirm',
    'title' => 'Email address change request email body',
    'subject' => 'email_confirm_confirmation_email_subject',
    'body' => 'email_confirm_confirmation_email_body',
  ),
  array(
    'module' => 'email_confirm',
    'title' => 'Email address change request email body (Original)',
    'subject' => 'email_confirm_confirmation_original_email_subject',
    'body' => 'email_confirm_confirmation_original_email_body',
  ),
  array(
    'module' => 'user',
    'title' => 'Welcome (new user created by administrator)',
    'subject' => 'user_mail_register_admin_created_subject',
    'body' => 'user_mail_register_admin_created_body',
  ),
  array(
    'module' => 'user',
    'title' => 'Welcome (awaiting approval)',
    'subject' => 'user_mail_register_pending_approval_subject',
    'body' => 'user_mail_register_pending_approval_body',
  ),
  array(
    'module' => 'user',
    'title' => 'Welcome (no approval required)',
    'subject' => 'user_mail_register_no_approval_required_subject',
    'body' => 'user_mail_register_no_approval_required_body',
  ),
  array(
    'module' => 'user',
    'title' => 'Account activation',
    'subject' => 'user_mail_status_activated_subject',
    'body' => 'user_mail_status_activated_body',
  ),
  array(
    'module' => 'user',
    'title' => 'Account blocked',
    'subject' => 'user_mail_status_blocked_subject',
    'body' => 'user_mail_status_blocked_body',
  ),
  array(
    'module' => 'user',
    'title' => 'Account cancellation confirmation',
    'subject' => 'user_mail_cancel_confirm_subject',
    'body' => 'user_mail_cancel_confirm_body',
  ),
  array(
    'module' => 'user',
    'title' => 'Account canceled',
    'subject' => 'user_mail_status_canceled_subject',
    'body' => 'user_mail_status_canceled_body',
  ),
  array(
    'module' => 'user',
    'title' => 'Password recovery',
    'subject' => 'user_mail_password_reset_subject',
    'body' => 'user_mail_password_reset_body',
  ),
  array(
    'module' => 'user',
    'title' => 'Admin alert about new user registration',
    'subject' => 'user_mail_register_pending_approval_admin_subject',
    'body' => 'user_mail_register_pending_approval_admin_body',
  ),
  array(
    'module' => 'user',
    'title' => 'Welcome (awaiting approval)',
    'subject' => 'user_registrationpassword_register_subject',
    'body' => 'user_registrationpassword_register_body',
  ),
  array(
    'module' => 'user',
    'title' => 'Welcome',
    'subject' => 'user_registrationpassword_status_activated_subject',
    'body' => 'user_registrationpassword_status_activated_body',
  ),

  // Group status request & approvals.
  array(
    'module' => 'c4m_content_group',
    'title' => 'Admin alert when a new group has been requested.',
    'subject' => 'group_pending_approval_admin_subject',
    'body' => 'group_pending_approval_admin_body',
  ),
  array(
    'module' => 'c4m_content_group',
    'title' => 'User alert when a new group request has been rejected.',
    'subject' => 'group_rejected_user_subject',
    'body' => 'group_rejected_user_body',
  ),
  array(
    'module' => 'c4m_content_group',
    'title' => 'User alert when a new group request has been approved.',
    'subject' => 'group_approved_user_subject',
    'body' => 'group_approved_user_body',
  ),

  // Invitations to join a group.
  array(
    'module' => 'c4m_og_invite_users',
    'title' => 'Visitor alert when he has been invited to a group.',
    'subject' => 'invite_group_member_subject',
    'body' => 'invite_group_member_body',
  ),
  array(
    'module' => 'c4m_og_invite_users',
    'title' => 'User alert when he has been invited to a group.',
    'subject' => 'group_invite_user_subject',
    'body' => 'group_invite_user_body',
  ),
);
