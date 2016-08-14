<?php
/**
 * @file
 * c4m_og_invite.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function c4m_og_invite_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_organic-groups-invite-settings:admin/config/group/og_invite.
  $menu_links['management_organic-groups-invite-settings:admin/config/group/og_invite'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/group/og_invite',
    'router_path' => 'admin/config/group/og_invite',
    'link_title' => 'Organic groups Invite settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure Organic groups Invite settings.',
      ),
      'identifier' => 'management_organic-groups-invite-settings:admin/config/group/og_invite',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_organic-groups:admin/config/group',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Organic groups Invite settings');

  return $menu_links;
}
