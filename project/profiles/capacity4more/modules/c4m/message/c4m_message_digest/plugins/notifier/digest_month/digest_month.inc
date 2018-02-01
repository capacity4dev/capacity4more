<?php

/**
 * @file
 * Ctools plugin definition for monthly interval.
 */

$plugin = array(
  'title' => t('Monthly Message Digest'),
  'description' => t('Send Message via monthly digest.'),
  'class' => 'MessageDigestMonth',
  'view_modes' => array(
    'message_notify_monthly_digest' => array('label' => t('Notify - Monthly digest')),
  ),
);
