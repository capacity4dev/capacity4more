<?php
/**
 * @file
 * Functionality to change uri_info based on the entity type and PURL settings.
 */

/**
 * Alter uri info based on the given type and the entity in the uri_info.
 *
 * @param string $type
 *   PURL link type.
 * @param array $uri_info
 *   The uri info that needs to be changed.
 *   Contains:
 *   - path : the path for the link.
 *   - options : the options for the link.
 *               the options should contain the entity for who we want the
 *               uri_info.
 */
function c4m_og_purl_alter_uri_info($type, array &$uri_info) {
  switch ($type) {
    case C4M_OG_PURL_LINK_AUTO:
      c4m_og_purl_alter_uri_info_purl_auto($uri_info);
      break;

    case C4M_OG_PURL_LINK_DISABLED:
      c4m_og_purl_alter_uri_info_purl_disabled($uri_info);
      break;

    case C4M_OG_PURL_LINK_DASHBOARD:
      c4m_og_purl_alter_uri_info_purl_dashboard($uri_info);
      break;
  }
}

/**
 * Alter the uri_info for a rendered field so it uses PURL if appropriate.
 *
 * @param array $uri_info
 *   The link info array.
 */
function c4m_og_purl_alter_uri_info_purl_auto(array &$uri_info) {
  $entity = $uri_info['options']['entity'];
  $gid = c4m_og_get_gid_from_entity($entity);

  // Enable PURL if it is a group or group content.
  if ($gid) {
    $uri_info['options']['purl'] = array(
      'provider' => 'og_purl|node',
      'id' => $gid,
    );
  }
  // Disable PURL if it is not a group or group content.
  else {
    $uri_info['options']['purl'] = array(
      'disabled' => TRUE,
    );
  }
}

/**
 * Alter the uri_info for a rendered field so it always disable PURL.
 *
 * @param array $uri_info
 *   The link info array.
 */
function c4m_og_purl_alter_uri_info_purl_disabled(array &$uri_info) {
  $uri_info['options']['purl'] = array(
    'disabled' => TRUE,
  );
}

/**
 * Alter the uri_info for a rendered field so it points to the group dashboard.
 *
 * @param array $uri_info
 *   The link info array.
 */
function c4m_og_purl_alter_uri_info_purl_dashboard(array &$uri_info) {
  $entity = $uri_info['options']['entity'];
  $gid = c4m_og_get_gid_from_entity($entity);

  // No change if not group related.
  if (!$gid) {
    return;
  }

  // Point the link to the group dashboard.
  $uri_info['path'] = '<front>';
  $uri_info['options']['purl'] = array(
    'provider' => 'og_purl|node',
    'id' => $gid,
  );
}
