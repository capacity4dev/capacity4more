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
  if (!empty($wrapper->pluggable_node_access->value())) {
    // If pluggable_node_access is set, then access is restricted.
    $group_access = 'restricted';
  }
  else {
    // Determine access per group_access parameter.
    $group_access = $wrapper->group_access->value() == FALSE ? 'public' : 'private';
  }

  $title = $wrapper->title->value();
  $status = isset($wrapper->c4m_og_status) ? $wrapper->c4m_og_status->value() : 'published';
  $variables = array(
    'title' => $title,
    'group_access' => $group_access,
    'group_status' => $status,
  );
  $title = theme('c4m_content_group_header_title', $variables);

  $tag['title']['element'] = array(
    '#tag' => 'h1',
    '#attributes' => array(
      'class' => array('group-title'),
    ),
    '#value' => $title,
  );

  $markup = theme_html_tag($tag['title']);

  $menu_item = menu_get_item();
  if (drupal_is_front_page() || ($menu_item['path'] == 'manage' && og_user_access('node', $group->nid, 'administer group'))) {
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
        $markup .= l(theme_html_tag($edit_link) . theme_image_style($file), url('node/' . $group->nid . '/edit', array('absolute' => TRUE, 'fragment' => 'edit-image-banner')), $options);
      }
      else {
        $markup .= theme_image_style($file);
      }
    }
  }

  return array(
    'subject' => '',
    'content' => $markup,
  );
}

/**
 * Callback for the c4m_block_create_group block.
 */
function _c4m_content_group_block_c4m_block_create_group() {
  global $user;

  if ($user->uid) {
    if (user_access('create group content')) {
      $markup = l(t('Create a group'), 'node/add/group', array('attributes' => array('class' => array('btn', 'btn-default'))));
    }
  }
  else {
    $markup = t('!register or !login to create or join groups', array(
      '!register' => l(t('Register'), 'user/register'),
      '!login' => l(t('log in'), 'user/login', array(
        'query' => drupal_get_destination(),
      )),
    ));
  }

  return array(
    'subject' => '',
    'content' => $markup,
  );
}
