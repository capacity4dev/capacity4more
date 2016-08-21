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
  $markup = '';

  if ($user->uid) {
    if (user_access('create project content')) {
      $create_project = '<div class="c4m-wide-green-btn">' . l(t('Create a project'), 'node/add/project', array('attributes' => array('class' => array('btn', 'btn-default')))) . '</div>';
      $create_programme = '<div class="c4m-wide-green-btn">'  . l(t('Create a programme'), 'node/add/programme', array('attributes' => array('class' => array('btn', 'btn-default')))) . '</div>';
      $markup = $create_project . $create_programme;
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
