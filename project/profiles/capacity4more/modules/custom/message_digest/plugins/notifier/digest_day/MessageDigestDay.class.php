<?php

/**
 * @file
 * Message digest plugin for daily interval.
 */

/**
 * Daily email notifier.
 */
class MessageDigestDay extends MessageDigest {

  /**
   * {@inheritdoc}
   */
  public function getInterval() {
    return '1 day';
  }

}
