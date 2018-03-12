<?php

/**
 * @file
 * Ctools plugin definition for daily interval.
 */

$plugin = array(
  'title' => t('Daily'),
  'description' => t('Send Message via daily digest.'),
  'class' => 'MessageDigestDay',
  'view_modes' => array(
    'message_notify_daily_digest' => array('label' => t('Notify - Daily digest')),
  ),
);
