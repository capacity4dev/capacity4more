<?php

/**
 * Monthly email notifier.
 */
class MessageDigestMonth extends MessageDigest {
  public function getInterval() {
    return '1 month';
  }
}
