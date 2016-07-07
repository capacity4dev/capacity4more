<?php

/**
 * @file
 * Cron related code.
 */

/**
 * Callback for the c4m_user cron job.
 */
function _c4m_user_cron() {
  $last_uid = variable_get('c4m_user_cron_last_uid', 0);
  $date = variable_get('c4m_user_cron_date', new DateTime('2000-01-01'));
  $current_date = new DateTime();
  $days = $date->diff($current_date)->days;

  // $last_uid is 0 at the beginning of a new day.
  if (!$days && !$last_uid) {
    return;
  }

  $limit = variable_get('c4m_user_cron_limit', 50);
  $accounts = db_query_range('SELECT uid FROM {users} WHERE uid > :uid', 0, $limit, array(
    ':uid' => $last_uid,
  ))->fetchCol();

  $queue = DrupalQueue::get('c4m_user');
  foreach ($accounts as $account) {
    $last_uid = $account;
    $queue->createItem($account);
  }

  variable_set('c4m_user_cron_last_uid', $last_uid);
}
