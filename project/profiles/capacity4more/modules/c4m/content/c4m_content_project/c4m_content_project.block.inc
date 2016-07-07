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
 * Project Dashboard title redesign.
 *
 * The function handles header title redesign project page.
 */
function _c4m_content_project_block_header_name_banner() {
  // First establish the current group.
  $group = c4m_og_current_group();
  $wrapper = entity_metadata_wrapper('node', $group);

  $title = $wrapper->title->value();
  $status = isset($wrapper->c4m_og_status) ? $wrapper->c4m_og_status->value() : 'published';

  $project_stage = $wrapper->c4m_project_stage->value();

  switch ($project_stage) {
    case 'notstarted':
      $flag_icon = 'fa-flag-o';
      $stage_label = 'not started';
      break;

    case 'completed':
      $flag_icon= 'fa-flag-checkered';
      $stage_label = 'completed';
      break;

    default:
      $flag_icon = 'fa-flag';
      $stage_label = 'ongoing';
  }

  $variables = [
    'title' => check_plain($title),
    'stage_label' => $stage_label,
    'project_stage' => $project_stage,
    'type' => $wrapper->c4m_project_type->value(),
    'status' => $status,
    'flag_icon' => $flag_icon,
  ];
  $title = theme('c4m_content_project_header_title', $variables);

  $tag['title']['element'] = array(
    '#tag' => 'div',
    '#attributes' => array(
      'class' => array('project-title'),
    ),
    '#value' => $title,
  );

  $markup = theme_html_tag($tag['title']);

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

  return array(
    'subject' => '',
    'content' => $markup,
  );
}
