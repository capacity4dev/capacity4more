<?php
/**
 * Index of all the messages.
 */

$messages = array(
  // Account Settings (/admin/config/people/accounts).
  array(
    '#title' => 'Welcome (new user created by administrator)',
    '#subject' => 'user_mail_register_admin_created_subject.txt',
    '#body' => 'user_mail_register_admin_created_body.html',
  ),
  array(
    '#title' => 'Welcome (awaiting approval)',
    '#subject' => 'user_mail_register_pending_approval_subject.txt',
    '#body' => 'user_mail_register_pending_approval_body.html',
  ),
  array(
    '#title' => 'Welcome (no approval required)',
    '#subject' => 'user_mail_register_no_approval_required_subject.txt',
    '#body' => 'user_mail_register_no_approval_required_body.html',
  ),
  array(
    '#title' => 'Account activation',
    '#subject' => 'user_mail_status_activated_subject.txt',
    '#body' => 'user_mail_status_activated_body.html',
  ),
  array(
    '#title' => 'Account blocked',
    '#subject' => 'user_mail_status_blocked_subject.txt',
    '#body' => 'user_mail_status_blocked_body.html',
  ),
  array(
    '#title' => 'Account cancellation confirmation',
    '#subject' => 'user_mail_cancel_confirm_subject.txt',
    '#body' => 'user_mail_cancel_confirm_body.html',
  ),
  array(
    '#title' => 'Account canceled',
    '#subject' => 'user_mail_status_canceled_subject.txt',
    '#body' => 'user_mail_status_canceled_body.html',
  ),
  array(
    '#title' => 'Password recovery',
    '#subject' => 'user_mail_password_reset_subject.txt',
    '#body' => 'user_mail_password_reset_body.html',
  ),
);
