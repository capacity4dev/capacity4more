<?php

/**
 * @file
 * Value object that stores Message Digest preferences.
 */

/**
 * Value object that stores Message Digest preferences.
 */
final class C4mMessagePreference {

  /**
   * Flag ID.
   *
   * @var int
   */
  private $fid;

  /**
   * Entity type.
   *
   * @var string
   */
  private $entityType;

  /**
   * Entity ID.
   *
   * @var int
   */
  private $entityId;

  /**
   * User ID.
   *
   * @var int
   */
  private $uid;

  /**
   * Machine name of the digest preference.
   *
   * @var string
   */
  private $preference;

  /**
   * C4mMessagePreference constructor.
   *
   * @param int $fid
   *   Flag ID.
   * @param string $entity_type
   *   Entity type.
   * @param int $entity_id
   *   Entity ID.
   * @param int $uid
   *   User ID.
   * @param string $preference
   *   Machine name of the digest preference.
   */
  public function __construct($fid, $entity_type, $entity_id, $uid, $preference) {
    if ($fid <= 0 || $entity_id <= 0 || $uid <= 0) {
      throw new InvalidArgumentException("ID's cannot be less then 0");
    }

    $this->fid = $fid;
    $this->entityType = $entity_type;
    $this->entityId = $entity_id;
    $this->uid = $uid;
    $this->preference = $preference;
  }

  /**
   * Get the flag ID.
   *
   * @return int
   *   Flag ID.
   */
  public function getFid() {
    return $this->fid;
  }

  /**
   * Get the Entity type.
   *
   * @return string
   *   Entity type.
   */
  public function getEntityType() {
    return $this->entityType;
  }

  /**
   * Get the Entity ID.
   *
   * @return int
   *   Entity ID.
   */
  public function getEntityId() {
    return $this->entityId;
  }

  /**
   * Get the user ID.
   *
   * @return int
   *   User ID.
   */
  public function getUid() {
    return $this->uid;
  }

  /**
   * Get the machine name of the digest preference.
   *
   * @return string
   *   Digest interval preference.
   */
  public function getPreference() {
    return $this->preference;
  }

  /**
   * Update the preference and return a new value object.
   *
   * @param string $preference
   *   The machine name of the (new) digest preference.
   *
   * @return \C4mMessagePreference
   *   New instance of the value object.
   */
  public function updatePreference($preference) {
    return new C4mMessagePreference($this->fid, $this->entityType, $this->entityId, $this->uid, $preference);
  }

}
