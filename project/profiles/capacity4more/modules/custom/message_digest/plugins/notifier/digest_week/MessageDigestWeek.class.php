<?php

/**
 * Email notifier.
 */
class MessageDigestWeek extends MessageDigest {

  /**
   * {@inheritdoc}
   */
  public function getInterval() {
    return '1 week';
  }

}
