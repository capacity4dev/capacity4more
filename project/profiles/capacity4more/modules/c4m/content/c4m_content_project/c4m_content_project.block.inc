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

  $markup = '';
  if ($user->uid) {
    if (user_access('create project content')) {
      $create_project = l(
        t('Create a project'),
        'node/add/project',
        array('attributes' => array('class' => array('btn', 'btn-primary')))
      );
      $create_programme = l(
        t('Create a programme'),
        'node/add/programme',
        array('attributes' => array('class' => array('btn', 'btn-primary')))
      );
      $markup = $create_project . $create_programme;
    }
  }
  else {
    $markup = t(
      '!register or !login to create or join projects',
      array(
        '!register' => l(t('Register'), 'user/register'),
        '!login' => l(
          t('log in'),
          'user/login',
          array(
            'query' => array('destination' => request_path()),
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

/**
 * Project Dashboard title redesign.
 *
 * The function handles header title redesign project page.
 */
function _c4m_content_project_block_header_name_banner_project() {
  // First establish the current project.
  $project = c4m_og_current_group();
  $wrapper = entity_metadata_wrapper('node', $project);
  $markup = '';

  $title = $wrapper->title->value();

  $tagline = $wrapper->c4m_project_tag_line->value();

  $status = isset($wrapper->c4m_og_status) ? $wrapper->c4m_og_status->value(
  ) : 'published';

  $project_stage = $wrapper->c4m_project_stage->value();

  switch ($project_stage) {
    case 'notstarted':
      $flag_icon = 'fa-flag-o';
      $stage_label = 'not started';
      break;

    case 'completed':
      $flag_icon = 'fa-flag-checkered';
      $stage_label = 'completed';
      break;

    default:
      $flag_icon = 'fa-flag';
      $stage_label = 'ongoing';
  }

  $variables = [
    'title' => check_plain($title),
    'tagline' => check_plain($tagline),
    'stage_label' => $stage_label,
    'project_stage' => $project_stage,
    'type' => $wrapper->c4m_project_type->value(),
    'status' => $status,
    'flag_icon' => $flag_icon,
  ];
  $markup .= theme('c4m_content_project_header_title', $variables);

  // Adding AJAX for notification toggle, which is part of this block.
  drupal_add_library('system', 'drupal.ajax');

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
    $block['content'] = field_view_field(
      'node',
      $node,
      'c4m_partners',
      array('label' => 'hidden')
    );
  }

  return $block;
}

/**
 * Callback for the c4m_block_project_projects block.
 */
function _c4m_content_project_block_c4m_block_project_projects() {
  $block = array();

  if ($node = c4m_og_current_group()) {
    $block['subject'] = '';
    $block['content'] = field_view_field(
      'node',
      $node,
      'c4m_related_projects_unlimited',
      array(
        'label' => 'hidden',
        'type' => 'entityreference_entity_view',
        'settings' => array('view_mode' => 'block_list'),
      )
    );
  }

  return $block;
}

/**
 * Callback for the c4m_block_project_groups block.
 */
function _c4m_content_project_block_c4m_block_project_groups() {
  $block = array();

  if ($node = c4m_og_current_group()) {
    $block['subject'] = '';
    $block['content'] = field_view_field(
      'node',
      $node,
      'c4m_related_group',
      array(
        'label' => 'hidden',
        'type' => 'entityreference_entity_view',
        'settings' => array('view_mode' => 'block_list'),
      )
    );
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
