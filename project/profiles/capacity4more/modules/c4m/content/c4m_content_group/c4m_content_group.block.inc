<?php

/**
 * @file
 * Code for group blocks.
 */

/**
 * Function to preprocess a block.
 *
 * We set classes here to avoid another wrapper div within the block.
 *
 * @param array $variables
 *   Block variables.
 */
function _c4m_content_group_preprocess_header_name_banner(array &$variables) {
  // First establish the current group.
  $group = c4m_og_current_group();

  $group_access = c4m_og_get_access_type($group);
  if (!empty($group_access['type'])) {
    $variables['classes_array'][] = 'group-' .
      drupal_html_class($group_access['type']);
  }
}

/**
 * The group name.
 */
function _c4m_content_group_block_header_name_banner() {
  // First establish the current group.
  $group = c4m_og_current_group();
  $wrapper = entity_metadata_wrapper('node', $group);
  $markup = '';

  $menu_item = menu_get_item();
  if (drupal_is_front_page(
    ) || ($menu_item['path'] == 'manage' && og_user_access(
        'node',
        $group->nid,
        'administer group'
      ))
  ) {
    // Add group image.
    $file = $wrapper->c4m_banner->value();
    if (!empty($file)) {
      $file['style_name'] = 'banner';
      $file['path'] = $file['uri'];
      $file['attributes'] = array('class' => 'group-banner');
      // If current page is the Group Management page,
      // Add an edit link to the banner.
      if ($menu_item['path'] == 'manage') {
        $edit_link['element'] = array(
          '#tag' => 'span',
          '#attributes' => array(
            'class' => array('edit-link'),
          ),
          '#value' => t('Edit'),
        );
        $options = array(
          'html' => TRUE,
          'attributes' => array(
            'class' => array(
              'edit-banner',
            ),
          ),
        );
        $markup .= l(
          theme_html_tag($edit_link) . theme_image_style($file),
          url(
            'node/' . $group->nid . '/edit',
            array('absolute' => TRUE, 'fragment' => 'edit-image-banner')
          ),
          $options
        );
      }
      else {
        $markup .= theme_image_style($file);
      }
    }
  }

  $variables = array();

  $title = $wrapper->title->value();

  $variables['title'] = $title;

  $variables['group_type'] = c4m_og_get_group_type_name($group);

  $status = isset($wrapper->c4m_og_status) ? $wrapper->c4m_og_status->value(
  ) : 'published';

  $variables['group_status'] = ($status !== 'published') ? $status : '';

  $variables['organisations'] = array();
  $variables['organisation_icons'] = array();
  $variables['organisation_ellipsis'] = FALSE;
  $variables['emails'] = array();
  $variables['group_access'] = c4m_og_get_access_type($group)['type'];

  if ($variables['group_access'] == 'restricted') {

    $emails = array();

    if ($organisation_info = c4m_og_get_organisations($group)) {
      $organisations = node_load_multiple(
        array_values($organisation_info)
      );

      // Load icon + title for all organisations.
      $organisation_list = array();

      // Load icon for the first three.
      $organisation_icons = array();
      $count = 0;

      foreach ($organisations as $nid => $org) {
        $icon = c4m_content_organisation_get_icon($org);
        $icon['#item']["attributes"]["class"] = array('group-title-organisation-icon');
        $icon['#item']["attributes"]["title"] = $org->title;

        $icon_render = drupal_render($icon);

        $organisation_list[] = $icon_render . $org->title;

        if ($count++ < 3) {
          $organisation_icons[] = $icon_render;
        }
      }

      $variables['organisations'] = $organisation_list;
      $variables['organisation_icons'] = $organisation_icons;

      if (count($organisations) > 3) {
        $variables['organisation_ellipsis'] = TRUE;
      }
    }

    if ($domain_info = c4m_og_get_email_domains($group)) {
      $emails = array_values($domain_info);
      array_walk(
        $emails,
        function (&$value, $key) {
          $value = trim($value, ', ');
          $value = '@' . $value;
        }
      );
    }

    $variables['emails'] = $emails;
  }

  $title = theme('c4m_content_group_header_title', $variables);

  return array(
    'subject' => '',
    'content' => $markup . $title,
  );
}

/**
 * Callback for the c4m_block_create_group block.
 */
function _c4m_content_group_block_c4m_block_create_group() {
  global $user;

  if ($user->uid) {
    if (user_access('create group content')) {
      $markup = l(
        t('Create a group'),
        'node/add/group',
        array('attributes' => array('class' => array('btn', 'btn-default')))
      );
    }
  }
  else {
    $markup = t(
      '!register or !login to create or join groups',
      array(
        '!register' => l(t('Register'), 'user/register'),
        '!login' => l(
          t('log in'),
          'user/login',
          array(
            'query' => drupal_get_destination(),
          )
        ),
      )
    );
  }

  return array(
    'subject' => '',
    'content' => $markup,
  );
}
