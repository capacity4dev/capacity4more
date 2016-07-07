<?php

/**
 * @file
 * Code for the project blocks.
 */

/**
 * Callback for the c4m_block_create_project block.
 */
function _c4m_content_project_block_c4m_block_create_project() {
  global $user;

  if ($user->uid) {
    if (user_access('create project content')) {
      $markup = l(t('Create a project'), 'node/add/project', array('attributes' => array('class' => array('btn', 'btn-default'))));
    }
  }
  else {
    $markup = t('!register or !login to create or join projects', array(
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

/**
 * Callback for the c4m_block_project_partners block.
 */
function _c4m_content_project_block_c4m_block_project_partners() {
  $block = array();

  if ($node = c4m_og_current_group()) {
    $block['subject'] = '';
    if ($nodes = node_get_recent(variable_get('node_recent_block_count', 10))) {
      $block['content'] = field_view_field('node', $node, 'c4m_partners', array('label' => 'hidden'));
    }
  }

  return $block;
}

/**
 * Callback for the c4m_block_project_about block.
 */
function _c4m_content_project_block_c4m_block_project_about() {
  $block = array();
  $block['subject'] = '';

  if ($node = c4m_og_current_group()) {
    // Render it with our custom group_dashboard view mode.
    $node_view = node_view($node, 'group_dashboard');
    $block['content'] = drupal_render($node_view);
  }

  return $block;
}