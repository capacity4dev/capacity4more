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

  $title = $wrapper->title->value();
  $status = isset($wrapper->c4m_og_status) ? $wrapper->c4m_og_status->value() : 'published';
  $tag['title']['element'] = array(
    '#tag' => 'h1',
    '#attributes' => array(
      'class' => array('group-title'),
    ),
    '#value' => $title,
  );

  $markup = theme_html_tag($tag['title']);

  if ($status != 'published') {
    $tag['status']['element'] = array(
      '#tag' => 'span',
      '#attributes' => array(
        'class' => array('group-status'),
      ),
      '#value' => $status,
    );
    $markup .= theme_html_tag($tag['status']);
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
