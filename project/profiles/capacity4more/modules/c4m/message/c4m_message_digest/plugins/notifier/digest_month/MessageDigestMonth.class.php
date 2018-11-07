<?php

/**
 * @file
 * Message digest plugin for monthly interval.
 */

/**
 * Monthly email notifier.
 */
class MessageDigestMonth extends MessageDigest {

  /**
   * {@inheritdoc}
   */
  public function getInterval() {
    return '1 month';
  }

}
